/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:03:29 by sstench           #+#    #+#             */
/*   Updated: 2019/11/03 19:36:46 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_near(char **shape_arr, int x, int y, int blocks)
{
	int pass;

	pass = 0;
	if (y < 3 && shape_arr[x][y + 1] == '#')
		return (check_right(shape_arr, x, y, blocks));
	else if (y > 0 && shape_arr[x][y - 1] == '#')
		return (check_left(shape_arr, x, y, blocks));
	else if (x < 3 && shape_arr[x + 1][y] == '#')
		return (check_up(shape_arr, x, y, blocks));
	else if (x > 0 && shape_arr[x - 1][y] == '#')
		return (check_down(shape_arr, x, y, blocks));
	else
		pass++;
	return (0);
}

int		checker(char **shape_arr, int x, int index)
{
	int len;
	int valid;
	int blocks;

	index = 0;
	len = 0;
	valid = 1;
	blocks = 0;
	while (index < x)
	{
		while (shape_arr[index][len] != '\0')
		{
			blocks += check_near(shape_arr, index, len, blocks);
			len++;
		}
		len = 0;
		index++;
	}
	if (blocks > 4 || blocks < 4)
		return (valid - 1);
	return (valid);
}

int		skip_checker(char **shape_arr)
{
	int index;
	int x;
	int y;
	int blocks;

	index = 0;
	blocks = 0;
	x = 0;
	y = 4;
	while (index < y)
	{
		while (shape_arr[index][x] != '\0')
		{
			if (shape_arr[index][x] == '#')
				blocks++;
			else if (shape_arr[index][x] != '.')
				return (0);
			x++;
		}
		x = 0;
		index++;
	}
	if (blocks == 4)
		return (1);
	return (0);
}

int		filler(char **shape_arr, int x, int y)
{
	int width;
	int height;

	width = 0;
	height = 0;
	while (width < 4)
	{
		while (height <= 4)
		{
			if (height == 4)
				shape_arr[width][height] = '\0';
			else
				shape_arr[width][height] = '.';
			height++;
		}
		height = 0;
		width++;
	}
	shape_arr[0][1] = '#';
	shape_arr[1][1] = '#';
	shape_arr[2][1] = '#';
	shape_arr[2][0] = '#';
	shape_arr[2][2] = '#';
	return (skip_checker(shape_arr));
}

void	printer(char **shape_arr)
{
	int index;
	int x;
	int y;

	index = 0;
	x = 0;
	y = 4;
	while (index < y)
	{
		while (shape_arr[index][x] != '\0')
		{
			printf("%c", shape_arr[index][x]);
			x++;
		}
		x = 0;
		printf("\n");
		index++;
	}
}
