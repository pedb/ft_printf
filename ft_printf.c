/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 17:00:44 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/12/09 18:31:12 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_map	*ft_initmap(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->pos = 0;
	map->size = 0;
	map->typ = 'a';
	map->min = 0;
	map->spac = 0;
	map->zero = 0;
	map->width = 0;
	map->pad = 0;
	map->prec = -1;
	map->pfill = 0;
	map->bon = 0;
	map->apos = -1;
	map->hash = 0;
	map->plus = 0;
	map->nb = 0;
	map->sci = 0;
	return (map);
}

t_map	*ft_resetmap(t_map *map)
{
	map->typ = 'a';
	map->min = 0;
	map->spac = 0;
	map->zero = 0;
	map->width = 0;
	map->pad = 0;
	map->prec = -1;
	map->pfill = 0;
	map->bon = 0;
	map->hash = 0;
	map->apos = -1;
	map->plus = 0;
	map->nb = 0;
	map->sci = 0;
	return (map);
}

void	ft_writer(const char *s, t_map *map)
{
	while (s[map->pos])
	{
		if (s[map->pos] == '%')
		{
			map->pos++;
			return ;
		}
		ft_putchar_flags(s[map->pos], 1, map, 0);
		map->pos++;
	}
	return ;
}

int		ft_printf(const char *s, ...)
{
	va_list	args;
	t_map	*map;

	map = ft_initmap();
	va_start(args, s);
	while (s[map->pos])
	{
		ft_writer(s, map);
		ft_flagfinder(s, map, &args);
		if (ft_thebigshort(s, map, &args) == 0)
			ft_typefinder(s, map, &args);
		map = ft_resetmap(map);
	}
	va_end(args);
	free(map);
	return (map->size);
}
