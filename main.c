#include <stdio.h>
#include "ft_printf.h"
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	int	i;
	void	*ptr;
	char	*s;

	s = "Hello";
	ptr = s;
	i = ft_printf("%40.20i\n", INT_MIN);
	ft_printf("This is length %i\n", i);
	i = printf("%40.20i\n", INT_MIN);
	printf("This is length %i\n", i);
}