/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:19:28 by amamy             #+#    #+#             */
/*   Updated: 2019/10/05 04:28:10 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"
#include <stdio.h>

static void	write_input(t_farm *f)
{
	f->input = f->input_start;
	while (f->input->line)
	{
		ft_putstr(f->input->line);
		ft_putstr("\n");
		f->input = f->input->next;
	}
}

int	main(void)
{
	t_farm	*f;
	t_room	*r;

	if (!(f = ft_memalloc(sizeof(t_farm))))
		return (-1);
	if (!(r = ft_memalloc(sizeof(t_room))))
	{
		ft_free_lemin(f, r);
		return (-1);
	}

	if (get_input(f, r) == -1)
	{
		ft_printf("INPUT ERROR\n");
		ft_free_lemin(f, r);
		return (-1);
	}
	write_input(f);
	ft_putchar('\n');
	int i = 0;
	while (i < f->room_nb)
	{
		printf("id %d = %s\n",i, f->id_table[i]->name);
		++i;
	}
	solve(f, f->room_nb, f->start->id, f->end->id);
	ft_free_lemin(f, r);
//	ft_putstr("No errors!\n");
	return (0);
}
