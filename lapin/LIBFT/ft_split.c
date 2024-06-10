/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:35:30 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/26 18:08:38 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	fto_cunt_words(const char *s, char c);
static	void	ft_free(char **noms);
static	void	ft_wordlen(const char *s, char c, int *d, int *f);
static	char	*ft_fill(const char *s, int *d, int *f);

char	**ft_split(char const *s, char c)
{
	char	**noms;
	int		nbr_words;
	int		i;
	int		d;
	int		f;

	d = 0;
	f = 0;
	i = 0;
	nbr_words = fto_cunt_words(s, c);
	noms = malloc(sizeof(char *) * (nbr_words + 1));
	if (noms == NULL)
		return (NULL);
	noms[nbr_words] = NULL;
	while (i < nbr_words)
	{
		ft_wordlen(s, c, &d, &f);
		noms[i] = ft_fill(s, &d, &f);
		if (noms[i] == NULL)
			ft_free(noms);
		i++;
	}
	return (noms);
}

static	int	fto_cunt_words(const char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			words++;
		if (s[i] != c && s[i - 1] == c)
			words++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words / 2);
}

static	void	ft_free(char **noms)
{
	int	i;

	i = 0;
	while (noms[i])
	{
		if (noms[i] != NULL)
			free(noms[i]);
		i++;
	}
	free(noms);
}

static	void	ft_wordlen(const char *s, char c, int *d, int *f)
{
	int	i;

	i = *d;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			*d = i;
		if (s[i] != c && s[i - 1] == c)
			*d = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			*f = i + 1;
			break ;
		}
		i++;
	}
	return ;
}

static	char	*ft_fill(const char *s, int *d, int *f)
{
	int		i;
	char	*nom;

	nom = malloc(sizeof(char) * (*f - *d + 1));
	if (nom == NULL)
		return (NULL);
	nom[*f - *d] = '\0';
	i = 0;
	while (*d < *f)
	{
		nom[i] = s[*d];
		i++;
		*d += 1;
	}
	*d = *f;
	return (nom);
}
