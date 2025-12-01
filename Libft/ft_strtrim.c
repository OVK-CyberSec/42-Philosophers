/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:32:40 by mohifdi           #+#    #+#             */
/*   Updated: 2025/04/14 15:17:48 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed_str;
	size_t	i;

	if (!s1)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	len = end - start;
	if (len == 0)
		return (ft_strdup(""));
	trimmed_str = (char *)malloc(len + 1);
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		trimmed_str[i] = s1[start + i];
		i++;
	}
	trimmed_str[len] = '\0';
	return (trimmed_str);
}

/*
int main()
{
    const char *s1 = "   Hello, World!   ";
    const char *set = " ";

    char *trimmed = ft_strtrim(s1, set);
    if (trimmed)
    {
        printf("Trimmed string: '%s'\n", trimmed);
        free(trimmed); // Ne pas oublier de libérer la mémoire allouée
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/
