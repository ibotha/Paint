/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 07:15:39 by ibotha            #+#    #+#             */
/*   Updated: 2018/06/14 11:23:09 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*makesplit(const char *s, char c, int *j)
{
	char	*ret;
	int		i;

	i = *j;
	while (s[*j] != '\0' && s[*j] != c)
		++*j;
	if (!(ret = ft_strsub(s, i, *j - i)))
		return (NULL);
	return (ret);
}

static char	**clear(char **ret, int i)
{
	int j;

	j = 0;
	while (j < i - 1)
		ft_strdel(&ret[j]);
	return (NULL);
}

static int	get_needed(const char *s, char c)
{
	int ret;
	int i;

	ret = 1;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		while (s[i] != c && s[i] != '\0')
			++i;
		++ret;
	}
	if (s[i - 1] == c)
		--ret;
	return (ret);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!(ret = (char**)ft_memalloc(sizeof(char**) * get_needed(s, c))))
		return (NULL);
	i = 0;
	j = 0;
	while (1)
	{
		while (s[j] == c)
			++j;
		if (!s[j])
		{
			ret[i] = NULL;
			return (ret);
		}
		if (!(ret[i++] = makesplit(s, c, &j)))
			return (clear(ret, i));
	}
	return (NULL);
}
