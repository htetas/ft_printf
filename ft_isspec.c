int	ft_isspec(const int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' \
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}