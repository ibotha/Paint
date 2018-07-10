/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:35:35 by ibotha            #+#    #+#             */
/*   Updated: 2018/05/17 12:19:36 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *ret, const char *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
	{
		ret[length] = str[length];
		length++;
	}
	ret[length] = str[length];
	return (ret);
}
