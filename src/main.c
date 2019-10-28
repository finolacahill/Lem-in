/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:19:28 by amamy             #+#    #+#             */
/*   Updated: 2019/10/28 18:21:58 by amamy            ###   ########.fr       */
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
	putchar('\n');
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
		ft_free_lemin(f, r);
		return (-1);
	}
	write_input(f);
	solve(f, f->room_nb, f->start->id);
	ft_free_lemin(f, r);
	return (0);
}
