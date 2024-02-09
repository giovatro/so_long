/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:53:29 by tblaase           #+#    #+#             */
/*   Updated: 2024/02/09 15:06:52 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t n);
int		ft_count_c(char *s, char c);
int		ft_count_lines(int fd, int line_length, int img_w);
int		ft_isdigit(int c);
int		ft_line_length(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// get_next_line

void	ft_free_gnl(char **p);
int		ft_strlen_gnl(char *s);
int		ft_strchr_gnl(char *s, int c, int flag);
char	*ft_strnjoin_gnl(char *s1, char *s2, int n);
char	*ft_strndup_gnl(char *str, int n);
void	*ft_calloc_gnl(size_t nelem, size_t elsize);
char	*ft_update_nl_gnl(char **next_line, int position);
char	*ft_output_gnl(char **next_line, int position, int bytes);
char	*get_next_line(int fd);

// ft_printf

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putptr(void *p, int *len);
void	ft_putnbr(int n, int *len);
void	ft_puthex(unsigned long x, int *len, char s);
void	ft_putuint(unsigned int u, int *len);

#endif
