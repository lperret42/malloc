#include "malloc.h"

void		show_alloc_mem_between_two_addr(void *begin, void *end)
{
	size_t		nb_octets;

	nb_octets = end - begin;
	printf("%#lX - %#lX : %lu octets\n", (unsigned long)begin, (unsigned long)end, nb_octets);
}

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

void		show_alloc_mem()
{
	void		**first_pages;
	size_t		total;

	first_pages = get_first_pages();
	total = 0;
	total += show_and_get_total_tiny_mem(first_pages[TINY]);
	total += show_and_get_total_small_mem(first_pages[SMALL]);
	total += show_and_get_total_large_mem(first_pages[LARGE]);
	if (total > 0)
		printf("Total : %lu octets\n", total);
}
