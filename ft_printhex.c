#include "ft_printf.h"

char    *ft_sharp(t_flag flag)
{
    if (flag.specifier == 'X')
        return ("0X");
    return ("0x");
}

int ft_printhex(va_list args, t_flag flag)
{
    if (!args || flag.specifier == 'x')
        return (0);
    return (0);
}