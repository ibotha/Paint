#include "libft.h"
#include <stdio.h>

static int	atoiprereq(const char **s)
{
	int isneg;

	isneg = 0;
	while (**s == ' ' || **s == '\t' || **s == '\f' || **s == '\v'
			|| **s == '\n' || **s == '\r')
		++*s;
	if (**s == '-')
	{
		isneg = 1;
		++*s;
	}
	else if (**s == '+')
		++*s;
	return (isneg);
}

int			ft_atoi_b(const char *str, const char *base)
{
	long long	ret;
	int			isneg;
	const char	*s;
	int			mult;

	ret = 0;
	mult = (int)ft_strlen(base);
	isneg = atoiprereq(&str);
	while ((s = ft_strchr((char*)base, *str)) && (s != (base + mult)))
	{
		ret *= mult;
			ret += s - base;
		if (ret < 0 && isneg == 1)
			return (0);
		if (ret < 0)
			return (-1);
		++str;
	}
	if (isneg)
		ret *= -1;
	return (ret);
}
