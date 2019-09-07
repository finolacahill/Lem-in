/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:02:47 by amamy             #+#    #+#             */
/*   Updated: 2019/09/07 21:13:05 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

/*
** new_room :
** Creates a new room and link it to the chained list.
** If START or END flag is raised, store it.
*/

t_room	*new_room(t_room *r)
{
	t_room *new;
	t_room *tmp;

	tmp = r;
	if (r->name != NULL)
	{
		if (!(new = ft_memalloc(sizeof(t_room))))
			return (NULL);
		r->next = new;
		r = new;
		r->prev = tmp;
	}
	return (r);
}
