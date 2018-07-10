/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:25:38 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/05 13:17:01 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "objects.h"
# include "vector.h"
# include <fcntl.h>

# define HEX "0123456789abcdef"

void	parse(t_scene *scene, char *file);

#endif
