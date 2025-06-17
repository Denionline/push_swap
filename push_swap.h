/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:38:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 23:25:27 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>

#define TRUE 1
#define FALSE 0

typedef struct s_moves
{
	int		 a;
	int		 b;
	int		 reverse_a;
	int		 reverse_b;
	long * sequence;
	long	 sequence_len;
	int		 total;
} t_moves;

typedef struct s_stack
{
	char	*name;
	long	*array;
	long	len;
} t_stack;

// push_swap.c
int main(int argc, char * argv[]);

// rotates.c
void rotate_one(t_stack * a, t_stack * b, t_moves * moves);
void rotate_two(t_stack * a, t_stack * b, t_moves * moves);

// operations
void pn(t_stack * from, t_stack * to, int toprint);
void sn(t_stack * n, int toprint);
void rn(t_stack * n, int toprint);
void rrn(t_stack * n, int toprint);
void ss(t_stack * a, t_stack * b, int toprint);
void rr(t_stack * a, t_stack * b, int toprint);
void rrr(t_stack * a, t_stack * b, int toprint);

// sort.c
void sort(t_stack * a, t_stack * b);

// parse.c
void parse(t_stack ** a, t_stack ** b, char ** args, int length);

// calc_moves.c
t_moves calc_moves(t_stack * a, t_stack * b, long number);

// find_lis_sequence.c
void ft_find_lis_sequence(long * array, long len, t_moves * moves);

// verify.c
void check_args(t_stack * a, t_stack * b, char ** args);
void error(t_stack * a, t_stack * b, char ** to_clean);
void is_there_duplicate(t_stack * a, t_stack * b, long * array, int length);
void is_exceding_limits(t_stack * a, t_stack * b, long * array, int len);

// get_number.c
long get_bigger(t_stack * n);
long get_smaller(t_stack * n);
long get_pos(t_stack * n, long number);

//libft functions
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nbr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strrchr(const char *s, int c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t n_items, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *buff, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

//get_next_line functions
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	*ft_linejoin(char *old, char *buffer);
int		ft_changebuffer(char *buffer);
char	*ft_clear(char *buff);


#endif