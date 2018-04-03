#include "malloc.h"

int		check_is_free_page(void *page, t_page_type page_type)
{
	size_t		block_size;
	size_t		num_char;
	size_t		nb_block_user;
	size_t		is_free_space_size;

	void		*begin_is_free_space;

	if (page_type == TINY)
		block_size = TINY_BLOCK_SIZE;
	else
		block_size = SMALL_BLOCK_SIZE;
	nb_block_user = get_nb_block_user(block_size);
	is_free_space_size = get_is_free_space_size(nb_block_user);
	begin_is_free_space = page + sizeof(void*);
	num_char = 0;
	while (num_char < is_free_space_size)
	{
		if (*(unsigned char *)(begin_is_free_space + num_char) != 255)
			return 0;
		num_char++;
	}
	return 1;
}

size_t		get_num_block_of_ptr_in_page(void *page, t_page_type page_type, void *ptr)
{
	size_t		block_size;
	void		*page_mem_begin;
	size_t		num_block;
	size_t		nb_block_user;

	if (page_type == TINY)
		block_size = TINY_BLOCK_SIZE;
	else
		block_size = SMALL_BLOCK_SIZE;
	num_block = 0;
	nb_block_user = get_nb_block_user(block_size);
	page_mem_begin = get_page_mem_begin(page, block_size);
	while (num_block < nb_block_user)
	{
		if (page_mem_begin + block_size * num_block == ptr)
			return num_block;
		num_block++;
	}
	return (-1);
}

int		search_and_free_ptr_in_larges(void *ptr, t_page_type page_type)
{
	void			*page;

	page = get_first_pages()[LARGE];
	while (page != NULL)
	{
		if (page + sizeof(void*) + sizeof(unsigned long) == ptr)
		{
			del_page(page, page_type);
			return (1);
		}
		page = read_void_star_in_memory(page);
	}
	return (0);
}

int		search_and_free_ptr_in_not_larges(void *ptr, t_page_type page_type)
{
	void			**first_pages;
	void			*page;
	long			num_block_of_ptr;

	first_pages = get_first_pages();
	num_block_of_ptr = -1;
	page = first_pages[page_type];
	while (page != NULL)
	{
		num_block_of_ptr = get_num_block_of_ptr_in_page(page, page_type, ptr);
		if (num_block_of_ptr != -1)
			break;
		page = read_void_star_in_memory(page);
	}
	if (num_block_of_ptr != -1)
	{
		if (!(get_is_free_block(page + sizeof(void*), num_block_of_ptr) == 0))
			return (0);
		set_is_free_block(page + sizeof(void*), num_block_of_ptr, 1);
		if (check_is_free_page(page, page_type) == 1)
			del_page(page, page_type);
		return (1);
	}
	return (0);
}

void	free(void *ptr)
{
	if (ptr == NULL)
		return ;

	printf("free\n");
	if (search_and_free_ptr_in_not_larges(ptr, TINY) == 0)
		if (search_and_free_ptr_in_not_larges(ptr, SMALL) == 0)
			if (search_and_free_ptr_in_larges(ptr, LARGE) == 0)
				printf("error: was not allocated\n");
}
