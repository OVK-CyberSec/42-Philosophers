/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:46:30 by mohifdi           #+#    #+#             */
/*   Updated: 2025/04/11 17:46:36 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t dstsize)
{
	unsigned int	desl;
	unsigned int	srl;
	unsigned int	i;

	i = 0;
	srl = 0;
	desl = 0;
	while (d[desl] != '\0')
		desl++;
	while (s[srl] != '\0')
		srl++;
	if (desl >= dstsize)
		return (srl + dstsize);
	while (s[i] != '\0' && desl + i < dstsize - 1)
	{
		d[desl + i] = s[i];
		i++;
	}
	d[desl + i] = '\0';
	return (desl + srl);
}
/*
#include <stdio.h>
int main()
{
    // Initialisation des chaînes
    char d[50] = "Hello";  d est assez grand
    char *s = " World!";
    unsigned int dstsize = 5;

    // Affichage avant la concaténation
    printf("Avant la concaténation:\n");
    printf("d : '%s'\n", d);  // Affiche "Hello"
    printf("s : '%s'\n", s);    // Affiche " World!"
    printf("Taille maximale : %u\n", dstsize);  // Affiche "20"

    // Appel de ft_strlcat
    unsigned int result = ft_strlcat(d, s, dstsize);

    // Affichage après la concaténation
    printf("\nAprès la concaténation:\n");
    printf("d : '%s'\n", d);  // Affiche "Hello World!"
    printf("Longueur totale de la chaîne résultante : %u\n", result);

    return 0;
}
*/
