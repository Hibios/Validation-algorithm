/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:31:36 by sstench           #+#    #+#             */
/*   Updated: 2019/11/03 19:32:06 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	char	**shape_arr;
	int		x;
	int		y;
	int		index;
	int		valid;

	x = 5;
	y = 5;
	index = 0;
	shape_arr = (char **)malloc(x * sizeof(char *));
	while (index < x)
	{
		shape_arr[index] = (char *)malloc(y * sizeof(char));
		index++;
	}
	shape_arr[4] = NULL;
	valid = filler(shape_arr, x, y);
	if (valid == 1)
		valid = checker(shape_arr, x - 1, y);
	printer(shape_arr);
	printf("Valid: %d", valid);
	return (0);
}
