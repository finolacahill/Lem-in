/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:31:28 by fcahill           #+#    #+#             */
/*   Updated: 2019/10/29 01:51:03 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem-in.h"
#include "libft.h"

static int		find_neighbours(t_queue *q, t_room *r)
{
	int j;

	j = 0;
	while (j < r->links_nb)
	{
//		printf("\ttrying %d, visited = %d flow = %d\n", r->links[j], q->visited[r->links[j]], q->flow[r->id][r->links[j]]);
		if (q->visited[r->links[j]] == 0  //if there is a link and we have not visited the link
			&& q->flow[r->id][r->links[j]] == 1) //We repect the flow chart by only followig flows of one.
		{
			q->queue[q->position] = r->links[j]; // add to end of queue
			q->prev[r->links[j]] = r->id; //note from which node we linked this node
			q->visited[r->links[j]] = 1; //mark it as visited
			++q->position; //move up the end of queue marker
		}
		++j;
	}
	return (0);
}

int				bfs(t_farm *f, t_queue *q)
{
	int		i;
	int		node;

	i = -1;
	set_to_n(&q->queue, q->length, -1);
	reset_queue(q, f->start->id, f->end->id);
	while (++i < q->length && q->visited[f->end->id] != 1 && q->queue[i] >= 0)
	{
		node = q->queue[i]; //sets node to the next node in the queue
		find_neighbours(q, f->id_table[node]);
	}
	if (q->visited[f->end->id] != 1)//if while path finding we did not reach the end, we failed
		return (-1);
	return (0);
}
