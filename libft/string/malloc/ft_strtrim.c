/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 02:55:41 by abarriel          #+#    #+#             */
/*   Updated: 2017/07/11 23:45:15 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtri(char const *s)
{
	char	*result;
	int		i[2];
	int		j;
	int		n;

	if (s == NULL)
		return (NULL);
	i[0] = 0;
	j = ft_strlen(s) - 1;
	n = 0;
	while (s[i[0] + n] == ' ' || s[i[0] + n] == '\n' || s[i[0] + n] == '\t')
		n++;
	while (s[j - i[0]] == ' ' || s[j - i[0]] == '\n' || s[j - i[0]] == '\t')
		i[0]++;
	if (j + 1 == n)
		i[0] = 0;
	result = malloc(sizeof(char) * (j - n - i[0] + 2));
	if (result == NULL)
		return (NULL);
	i[1] = 0;
	while (i[1] <= j - n - i[0] && j != n)
		result[i[1]++] = s[n + i[1]];
	result[i[1]] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1)
{
	return (ft_strtri(s1));
}
