/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_dllist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:46:26 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:48:32 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DS_DLLIST_H
# define DS_DLLIST_H

# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

typedef struct s_dllist
{
	int				val;
	struct s_dllist	*next;
	struct s_dllist	*prev;
}				t_dllist;

t_dllist		*ft_dllist_new_node(int value);
void			ft_dllist_push_front(t_dllist **head, int value);
void			ft_dllist_push_back(t_dllist **head, int value);
void			ft_dllist_del_node(t_dllist **head, t_dllist *to_del);
void			ft_dllist_print(t_dllist *it, int reverse);

#endif
