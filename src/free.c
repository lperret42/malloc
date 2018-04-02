#include "malloc.h"

int		check_is_free_page(void *page, t_page_type page_type)
{
	size_t		block_size;   //just for call to get_nb_block_user
	size_t		num_block;
	size_t		nb_block_user;
	void		*begin_is_free_space;

	if (page_type == TINY)
		block_size = TINY_BLOCK_SIZE;
	else if (page_type == SMALL)
		block_size = SMALL_BLOCK_SIZE;
	nb_block_user = get_nb_block_user(block_size);
	begin_is_free_space = page + sizeof(void*);
	num_block = 0;
	while (num_block < nb_block_user)
	{
		if (*(unsigned char *)(begin_is_free_space + num_block) != 255)
			return 0;
		num_block++;
	}
	return 1;
}

size_t		get_num_block_of_ptr_in_page(void *page, t_page_type page_type, void *ptr)
{
	size_t		block_size;   //just for call to get_nb_block_user
	void		*page_mem_begin;
	size_t		num_block;
	size_t		nb_block_user;

	if (page_type == TINY)
		block_size = TINY_BLOCK_SIZE;
	else if (page_type == SMALL)
		block_size = SMALL_BLOCK_SIZE;
	num_block = 0;
	nb_block_user = get_nb_block_user(block_size);
	page_mem_begin = get_page_mem_begin(page, block_size);
	while (num_block < nb_block_user)
	{
		if (page_mem_begin + block_size * num_block == ptr)
			return num_block;
	}
	return (-1);
}

void	*search_and_free_ptr(ptr)
{
	void			**first_pages;
	t_page_type		page_type;

	first_pages = get_first_pages();
	page_type = 0;
	while (page_type < LARGE)
	{
		page = first_pages[page_type];
		while (page != NULL)
		{
			if (

void	free(void *ptr)
{
	if (ptr == NULL)
		return ;
	search_and_free_ptr(ptr);
}
