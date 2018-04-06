# include "malloc.h"

int main() 
{
char	*str;

str = malloc(1024); 
str =malloc(1024 * 32); 
str = malloc(1024 * 1024); 
str = malloc(1024 * 1024 * 16); 
str = malloc(1024 * 1024 * 128); 
show_alloc_mem(); 
return (0); 
}
