#include "malloc.h"

int		main(void)
{
	int		i;
	int		page_size;
	char	*str;

	page_size = getpagesize();
	str = (char*)ft_malloc(page_size + 1);
	i = 0;
	while (i < page_size)
	{
		str[i] = '*';
		i++;
	}
	str[i] = '\0';
	ft_printf("%s", str);

	return (0);
}
