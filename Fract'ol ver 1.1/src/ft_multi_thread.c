/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 03:06:15 by msidqi            #+#    #+#             */
/*   Updated: 2019/05/02 03:06:17 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

static void	ft_set_startend(t_data *datacopy, int step, int i_thread)
{
	datacopy->thread_range.start.x = 0;
	datacopy->thread_range.start.y = step * i_thread;
	datacopy->thread_range.end.x = datacopy->winwidth;
	datacopy->thread_range.end.y = step * (i_thread + 1);
}

static void	ft_handle_threads(t_data *multi, int n_threads, int step)
{
	pthread_t	thread_ids[n_threads];
	int			i;

	i = -1;
	while (++i < n_threads)
		ft_set_startend(&multi[i], step, i);
	i = -1;
	while (++i < n_threads)
		pthread_create(&thread_ids[i], NULL, draw_fractal, (void *)&multi[i]);
	i = -1;
	while (++i < n_threads)
		pthread_join(thread_ids[i], NULL);
}

void		ft_multi_thread(t_data *data, int n_threads)
{
	t_data	*multi;
	int		i;
	int		step;

	multi = (t_data *)malloc(sizeof(t_data) * n_threads);
	step = data->winheight / n_threads;
	i = -1;
	while (++i < n_threads)
		multi[i] = *data;
	ft_handle_threads(multi, n_threads, step);
	free(multi);
}
