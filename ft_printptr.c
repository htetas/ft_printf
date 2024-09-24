#include "ft_printf.h"

int ft_printptr(va_list args, t_flag flag)
{
    unsigned long   ptr;
    int count;

    ptr = (unsigned long)va_arg(args, void *);
    if (ptr == 0 && flag.dot && flag.precision == 0)
        return (ft_padchar(flag.width, ' '));
    count = 2;
    count += ft_hexlen(ptr, 0);
    if (flag.minus == 0)
    {
        if (flag.zero && flag.dot == 0)
            count += ft_padchar(flag.width - count, '0');
        else
            count += ft_padchar(flag.width - count, ' ');
    }
    ft_putstr_fd("0x", 1);
    ft_puthex(ptr, HEXLOW);
    if (flag.minus)
        count += ft_padchar(flag.width - count, ' ');
    return (count);
}