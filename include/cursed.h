/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursed.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:42:08 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/13 13:02:30 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSED_H
# define CURSED_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <time.h>
# define MAX_WORDS 103

typedef struct s_word
{
	char		gender;
	char		type;
	char		*text;
}	t_word;

t_word	**load_words(void);
void	show_word(t_word *word);
char	*zalgo(char *str);
size_t	z_strlen(const char *str);
#endif