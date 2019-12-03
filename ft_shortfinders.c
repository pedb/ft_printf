/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shortfinders.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 14:43:20 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/12/03 14:50:43 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_shortfinder3(const char *s, t_map *map, va_list *args)
{
	short int	*n;

	if (s[map->pos] == 'n')
	{
		n = va_arg(*args, short int*);
		*n = map->size;
		map->pos++;
		return (1);
	}
	return (0);
}

int	ft_shortfinder2(const char *s, t_map *map, va_list *args)
{
	char				*string;
	unsigned short int	u;

	if (s[map->pos] == 'o')
	{
		u = va_arg(*args, unsigned short int);
		string = ft_itoa_base(u, 8, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'x' || s[map->pos] == 'X')
	{
		u = va_arg(*args, unsigned short int);
		string = ft_itoa_base(u, 16, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_shortfinder3(s, map, args));
}

int	ft_shortfinder(const char *s, t_map *map, va_list *args)
{
	short int			i;
	unsigned short int	u;
	char				*string;

	if (s[map->pos] == 'd' || s[map->pos] == 'i')
	{
		i = va_arg(*args, short int);
		string = ft_itoa_base(i, 10, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'u')
	{
		u = va_arg(*args, unsigned short int);
		string = ft_itoa_base(u, 10, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_shortfinder2(s, map, args));
}
