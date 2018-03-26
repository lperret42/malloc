#include "malloc.h"

void			**get_first_pages(void)
{
	int		i;

	i = 0;
	static void	**first_pages = NULL;

	if (first_pages == NULL)
	{
		first_pages = mmap(NULL, sizeof(void*) * NB_PAGE_TYPE, PROT_READ | PROT_WRITE,
						MAP_ANON | MAP_PRIVATE, -1, 0);
		while (i < NB_PAGE_TYPE)
			first_pages[i++] = NULL;
	}

	return first_pages;
}

void		*get_first_page(size_t size)
{
	t_page_type		page_type;

	page_type = get_page_type(size);
	return get_first_pages()[page_type];
}

void			*get_alloc_page(size_t size)
{
	size_t		mem_len;
	size_t		nb_block;
	size_t		is_free_space_size;
	size_t		alloc_size;
	void		*begin_is_free_space;;
	void		*alloc_page;
	t_page_type	page_type;

	page_type = get_page_type(size);
	mem_len = get_mem_len(size);
	nb_block = get_nb_block(size);
	is_free_space_size = get_is_free_space_size(nb_block);
	alloc_size = sizeof(void*) + is_free_space_size * sizeof(char) + mem_len;
	alloc_page = (void*)mmap(NULL, alloc_size, PROT_READ | PROT_WRITE,
						MAP_ANON | MAP_PRIVATE, -1, 0);

	begin_is_free_space = (void*)((char*)alloc_page + sizeof(void*));
	memset(begin_is_free_space, 255, is_free_space_size);
	return alloc_page;
}

void	add_page(size_t size)
{
	t_page_type		page_type;
	void			**first_pages;
	void			*tmp;
	void			*new_page;

	page_type = get_page_type(size);
	first_pages = get_first_pages();
	tmp = first_pages[page_type];
	new_page = get_alloc_page(size);
	if (tmp == NULL)
		memset(new_page, 0, sizeof(void*));
	else
		memcpy(new_page, tmp, sizeof(void*));
	first_pages[page_type] = new_page;
	printf("page++\n");
}
