#include "ft_printf.h"

void    *ft_putsharp(t_flag flag)
{
    if (flag.specifier == 'X')
        ft_putstr_fd("0X", 1);
    else
        ft_putstr_fd("0x", 1);
}

int ft_hexlen(unsigned int n, int precision)
{
    int len;

    len = 1;
    while (n >= 16)
    {
        n = n / 16;
        len++;
    }
    if (precision > len)
        return(precision);
    return (len);
}

void    ft_puthex_prec(unsigned int n, int precision, char *base)
{
    while (precision > ft_hexlen(n, 0))
    {
        ft_putchar_fd('0', 1);
        precision--;
    }
    ft_puthex((unsigned long)n, base);
}

int ft_printhex(va_list args, t_flag flag)
{
    int count;
    unsigned int n;
    char    *base;

    if (flag.specifier == 'X')
        base = HEXUP;
    else if (flag.specifier == 'x')
        base = HEXLOW;
    n = va_arg(args, unsigned int);
    count = 0;
    if (n == 0 && flag.dot && flag.precision == 0)
        return (ft_padchar(flag.width, ' '));
    else
        count += ft_hexlen(n, flag.precision);
    if (flag.sharp == 1 && n != 0)
    {
        ft_putsharp(flag);
        count += 2;
    }
    if (flag.zero && flag.dot == 0 && flag.minus == 0)
        count += ft_padchar(flag.width - count, '0');
    ft_puthex_prec(n, flag.precision, base);
    if (flag.minus && flag.width > count)
        count += ft_padchar(flag.width - count, ' ');
    return (count);
}