/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raubert <raubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:22:17 by raubert           #+#    #+#             */
/*   Updated: 2019/12/04 19:22:30 by raubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char				*ft_strjoin(char **s1, char *s2)
{
	size_t			len;
	char			*ret;
	unsigned int	i;
	unsigned int	j;

	len = ft_strlen(*s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s1 && (*s1)[i] != '\0')
	{
		ret[i] = (*s1)[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free(*s1);
	*s1 = ret;
	return (ret);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	char			*casts;
	unsigned int	i;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	casts = (char *)s;
	i = 0;
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		ret[i] = casts[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char				*ft_strdup(const char *s1)
{
	char			*res;
	size_t			len;
	size_t			i;

	i = 0;
	len = ft_strlen(s1);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cast1;
	unsigned char	*cast2;

	i = 0;
	if (n <= 0)
		return (0);
	cast1 = (unsigned char *)s1;
	cast2 = (unsigned char *)s2;
	while ((i < n - 1) && (cast1[i] != '\0') && (cast2[i] != '\0'))
	{
		if (cast1[i] != cast2[i])
			return (cast1[i] - cast2[i]);
		i++;
	}
	return (cast1[i] - cast2[i]);
}
