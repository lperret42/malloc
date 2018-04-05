#include "malloc.h"

void		show_alloc_mem_between_two_addr(void *begin, void *end)
{
	size_t		nb_octets;

	nb_octets = end - begin;
	printf(
			"%#lX - %#lX : %lu octets\n",
			(unsigned long)begin,
			(unsigned long)end,
			nb_octets
		);
}
/*
size_t		show_and_get_total_large_mem(void *page)
{
	size_t		total;
	size_t		size;
	void		*begin;

	total = 0;
	while(page)
	{
		size = *((unsigned long *)(page + sizeof(void*)));
		size -= sizeof(void*) + sizeof(unsigned long);
		printf("LARGE : %#lX\n", (unsigned long)get_page_mem_begin(page, SMALL_BLOCK_SIZE + 1));
		begin = page + sizeof(void*) + sizeof(unsigned long);
		show_alloc_mem_between_two_addr(begin, begin + size);
		total += size;
		page = read_void_star_in_memory(page);
	}
	return (total);
}

size_t		show_and_get_total_small_mem(void *page)
{
	size_t		nb_allocated;
	size_t		num_block;
	size_t		tmp;
	size_t		nb_block_user;
	size_t		already_print;

	nb_block_user = get_nb_block_user(SMALL_BLOCK_SIZE);
	nb_allocated = 0;
	while(page)
	{
		already_print = 0;
		num_block = 0;
		while (num_block < nb_block_user)
		{
			if (get_is_free_block(page + sizeof(void*), num_block) == 0)
			{
				tmp = num_block;
				while (get_is_free_block(page + sizeof(void*), num_block) == 0 && num_block < nb_block_user)
					num_block++;
				if (already_print++ == 0)
					printf("SMALL : %#lX\n", (unsigned long)get_page_mem_begin(page, SMALL_BLOCK_SIZE));
				show_alloc_mem_between_two_addr(
					get_page_mem_begin(page, SMALL_BLOCK_SIZE) + tmp * SMALL_BLOCK_SIZE,
					get_page_mem_begin(page, SMALL_BLOCK_SIZE) + (num_block - tmp) * SMALL_BLOCK_SIZE);
				nb_allocated += num_block - tmp;
			}
			else
				num_block++;
		}
		page = read_void_star_in_memory(page);
	}
	return (nb_allocated * SMALL_BLOCK_SIZE);
}

size_t		show_and_get_total_tiny_mem(void *page)
{
	size_t		nb_allocated;
	size_t		num_block;
	size_t		tmp;
	size_t		nb_block_user;
	size_t		already_print;

	nb_block_user = get_nb_block_user(TINY_BLOCK_SIZE);
	nb_allocated = 0;
	while(page)
	{
		already_print = 0;
		num_block = 0;
		while (num_block < nb_block_user)
		{
			if (get_is_free_block(page + sizeof(void*), num_block) == 0)
			{
				tmp = num_block;
				while (get_is_free_block(page + sizeof(void*), num_block) == 0 && num_block < nb_block_user)
					num_block++;
				if (already_print++ == 0)
					printf("TINY : %#lX\n", (unsigned long)get_page_mem_begin(page, TINY_BLOCK_SIZE));
				show_alloc_mem_between_two_addr(
					get_page_mem_begin(page, TINY_BLOCK_SIZE) + tmp * TINY_BLOCK_SIZE,
					get_page_mem_begin(page, TINY_BLOCK_SIZE) + (num_block - tmp) * TINY_BLOCK_SIZE);
				nb_allocated += num_block - tmp;
			}
			else
				num_block++;
		}
		page = read_void_star_in_memory(page);
	}
	return (nb_allocated * TINY_BLOCK_SIZE);
}
*/
size_t		get_nb_page(void *page)
{
	size_t		nb_page;

	nb_page = 0;
	while (page)
	{
		nb_page++;
		page = read_void_star_in_memory(page);
	}
	return (nb_page);
}

size_t		show_and_get_alloc_mem_in_one_not_large_page(void *page, t_page_type page_type, size_t num_page)
{
	size_t		num_block;
	size_t		nb_block_user;
	void		*begin;
	size_t		total;
	size_t		block_size;

	block_size = page_type == TINY ? TINY_BLOCK_SIZE : SMALL_BLOCK_SIZE;
	if (page_type == TINY && num_page == 0)
		printf("TINY : %#lX\n", (unsigned long)get_page_mem_begin(page, TINY_BLOCK_SIZE));
	else if (num_page == 0)
		printf("SMALL : %#lX\n", (unsigned long)get_page_mem_begin(page, SMALL_BLOCK_SIZE));
		//printf("SMALL\n");
	nb_block_user = get_nb_block_user(block_size);
	total = 0;
	num_block = 0;
	while (num_block < nb_block_user)
	{
		if (get_is_free_block(page + sizeof(void*), num_block) == 0)
		{
			begin = get_page_mem_begin(page, block_size);
			begin += block_size * num_block;
			total += block_size;
			show_alloc_mem_between_two_addr(begin, begin + block_size);
		}
		num_block++;
	}
	return (total);
}

size_t		show_and_get_alloc_mem_in_one_large_page(void *page, size_t num_page)
{
	size_t		size;
	void	*begin;

	size = *((unsigned long *)(page + sizeof(void*)));
	size -= sizeof(void*) + sizeof(unsigned long);
	if (num_page == 0)
		printf("LARGE : %#lX\n", (unsigned long)get_page_mem_begin(page, SMALL_BLOCK_SIZE + 1));
	begin = page + sizeof(void*) + sizeof(unsigned long);
	show_alloc_mem_between_two_addr(begin, begin + size);
	return (size);
}

size_t		show_and_get_alloc_mem_in_one_page(void *page, t_page_type page_type, size_t num_page)
{
	if (page_type == LARGE)
		return show_and_get_alloc_mem_in_one_large_page(page, num_page);
	else
		return show_and_get_alloc_mem_in_one_not_large_page(page, page_type, num_page);
}

void		sort_pages(void ** pages, size_t nb_page)
{
	size_t		n;
	void		*tmp;

	if (nb_page < 2)
		return ;
	n = 0;
	while (n < nb_page - 1)
	{
		if (pages[n+1] < pages[n])
		{
			tmp = pages[n];
			pages[n] = pages[n+1];
			pages[n+1] = tmp;
			n = 0;
		}
		else
			n++;
	}
}

size_t		show_alloc_mem_by_type(void *page, t_page_type page_type)
{
	size_t		total;
	size_t		n;
	size_t		nb_page;
	void		**pages;

	nb_page = get_nb_page(page);
	if (!page || !(pages = (void**)mmap(NULL, sizeof(void*) * nb_page,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return 0;
	n = 0;
	while (page)
	{
		pages[n++] = page;
		page = read_void_star_in_memory(page);
	}
	sort_pages(pages, nb_page);
	total = 0;
	n = 0;
	while (n < nb_page)
	{
		total += show_and_get_alloc_mem_in_one_page(pages[n], page_type, n);
		n++;
	}
	munmap(pages, sizeof(void*) * nb_page);
	return (total);
}

void		show_alloc_mem()
{
	void		**first_pages;
	size_t		total;

	first_pages = get_first_pages();
	/*
	printf("Nb TINY page: %lu\n", get_nb_page(first_pages[TINY]));
	printf("Nb SMALL page: %lu\n", get_nb_page(first_pages[SMALL]));
	printf("Nb LARGE page: %lu\n", get_nb_page(first_pages[LARGE]));
	show_alloc_mem_by_type(first_pages[TINY], TINY);
	show_alloc_mem_by_type(first_pages[SMALL], SMALL);
	show_alloc_mem_by_type(first_pages[LARGE], LARGE);
	total = 0;
	total += show_and_get_total_tiny_mem(first_pages[TINY]);
	total += show_and_get_total_small_mem(first_pages[SMALL]);
	total += show_and_get_total_large_mem(first_pages[LARGE]);
	*/
	total = 0;
	total += show_alloc_mem_by_type(first_pages[TINY], TINY);
	total += show_alloc_mem_by_type(first_pages[SMALL], SMALL);
	total += show_alloc_mem_by_type(first_pages[LARGE], LARGE);
	if (total > 0)
		printf("Total : %lu octets\n", total);
}
