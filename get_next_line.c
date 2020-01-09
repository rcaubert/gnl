/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raubert <raubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:21:18 by raubert           #+#    #+#             */
/*   Updated: 2020/01/09 15:19:21 by raubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_free(char **contain, int k)
{
	if (*contain)
	{
		free(*contain);
		*contain = NULL;
	}
	return (k);
}

static int		ft_is_bn(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		ft_modif(char **line, char **contain)
{
	char		*tmp;
	int			index;

	index = ft_is_bn(*contain);
	if (index == (-1))
	{
		*line = ft_strdup(*contain);
		return (ft_free(contain, 0));
	}
	*line = ft_substr(*contain, 0, index);
	tmp = ft_substr(*contain, index + 1, ft_strlen(*contain) - index - 1);
	free(*contain);
	*contain = tmp;
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*contain;
	char		*buff;
	ssize_t		read_ret;

	if ((!(line)) || (fd < 0) || (BUFFER_SIZE < 1) ||
			(!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (ft_free(&contain, -1));
	while ((read_ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_ret] = '\0';
		if (!(ft_strjoin(&contain, buff)))
			return (ft_free(&contain, 0));
		if (ft_is_bn(contain) != (-1))
			break ;
	}
	free(buff);
	if (read_ret < 0)
		return (ft_free(&contain, -1));
	if ((ft_strncmp(contain, "", ft_strlen(contain)) == 0) && read_ret == 0)
	{
		*line = ft_strdup("");
		return (ft_free(&contain, 0));
	}
	return (ft_modif(line, &contain));
}
