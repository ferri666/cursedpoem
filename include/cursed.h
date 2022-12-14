/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursed.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:42:08 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/11/28 19:24:12 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSED_H
# define CURSED_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef struct s_word
{
	char		gender;
	char		type;
	char		*text;
}	t_word;

t_word	*load_words(void);
#endif