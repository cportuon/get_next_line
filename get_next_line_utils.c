/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cportuon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:53:57 by cportuon          #+#    #+#             */
/*   Updated: 2023/02/01 17:53:59 by cportuon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*dest;
	int		len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *str1, char *str2)
{
	unsigned int	i;
	unsigned int	j;
	char			*dest;

	if (!str1 || !str2)
		return (0);
	i = 0;
	j = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!dest)
		return (0);
	while (str1[i])
	{
		dest[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		dest[i] = str2[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
		str ++;
	if (*str == (char)c)
		return ((char *)str);
	return (0);
}

char	*ft_substr(char *line, int start, int strlen2)
{
	int		i;
	char	*substr;

	if (!line)
		return (0);
	if (start > ft_strlen(line))
		return (ft_strdup(""));
	substr = (char *) malloc(sizeof(char) * strlen2 + 1);
	if (!substr)
		return (0);
	i = 0;
	while (strlen2 > 0)
	{
		substr[i] = line[start];
		i++;
		start++;
		strlen2--;
	}
	substr[i] = '\0';
	return (substr);
}
