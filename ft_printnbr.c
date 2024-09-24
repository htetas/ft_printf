#include "ft_printf.h"

void    ft_putnbr_prec(int n, int precision)
{
    int i;

    i = ft_strlen(base);

    if (n >= i)
        ft_putunbr_base(n / i, base);
    ft_putchar_fd(base[n % i], fd);
}

int ft_printnbr(va_list args, t_flag flag)
{
    int n;
    int neg;
    int count;

    n = va_arg(args, int);
    count = 0;
    if (n < 0)
        neg = 1;

}