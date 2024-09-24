int	ft_isspec(const int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' \
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int ft_padchar(int len, char c)
{
    int count;

    count = 0;
    while (len > 0)
    {
        ft_putchar_fd(c, 1);
        count++;
        len--;
    }
    return (count);
}

void    ft_puthex(unsigned long n, char *base)
{
    if (n >= 16)
        ft_puthex(n / 16, base);
    ft_putchar_fd(base[n % 16], 1);
}