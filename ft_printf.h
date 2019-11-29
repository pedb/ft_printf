/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 15:19:04 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/28 21:38:02 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_map
{
	int		pos;
	int		size;
	int		min;
	int		spac;
	int		zero;
	int		pad;
	int		ast;
	int		prec;
	int		l;
	int		ll;
	int		h;
	int		hh;
	int		apo;
	int		hash;
	int		plus;
}				t_map;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_putchar_fd(char c, int fd, t_map *map);
void			ft_putstr_fd(char *s, int fd, t_map *map);
void			ft_putendl_fd(char *s, int fd, t_map *map);
void			ft_putnbr_fd(int n, int fd, t_map *map);
void			*ft_memcpy(void *dst, const void *src, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_itoa_base(unsigned long nb, unsigned long base, char c);
int				ft_printf(const char *s, ...);

#endif
