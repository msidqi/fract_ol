/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 02:51:38 by msidqi            #+#    #+#             */
/*   Updated: 2018/10/19 02:55:03 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wordcount(char *s, char c)
{
	unsigned int w;
	unsigned int i;

	if (!s)
		return (0);
	w = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0'))
			w++;
		i++;
	}
	if (s[0] != c)
		w++;
	return (w);
}
