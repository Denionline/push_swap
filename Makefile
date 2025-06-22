# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 23:46:38 by dximenes          #+#    #+#              #
#    Updated: 2025/06/22 12:36:04 by dximenes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #

C_STD = \033[0;39m
C_GRAY = \033[0;90m
C_RED = \033[0;91m
C_GREEN = \033[0;92m
C_YELLOW = \033[0;93m
C_BLUE = \033[0;94m
C_MAGENTA = \033[0;95m
C_CYAN = \033[0;96m
C_WHITE = \033[0;97m

# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

PUSH_SWAP		= push_swap
CHECKER			= checker
ARQUIVE			= binary.a

# **************************************************************************** #
#                                    Path's                                    #
# **************************************************************************** #

PUSH_SWAP_FILE	= push_swap.c
CHECKER_FILE	= checker_bonus.c

BF				= .bonus

FILES			+= sort
FILES			+= sn
FILES			+= ss
FILES			+= pn
FILES			+= rn
FILES			+= rr
FILES			+= rrn
FILES			+= rrr
FILES			+= parse
FILES			+= verify
FILES			+= rotates
FILES			+= calc_moves
FILES			+= get_number
FILES			+= find_lis_sequence

LIBFT_FILES		+= ft_isdigit
LIBFT_FILES		+= ft_atoi
LIBFT_FILES		+= ft_strlen
LIBFT_FILES		+= ft_strlcpy
LIBFT_FILES		+= ft_substr
LIBFT_FILES		+= ft_strchr
LIBFT_FILES		+= ft_strdup
LIBFT_FILES		+= ft_split
LIBFT_FILES		+= ft_calloc
LIBFT_FILES		+= ft_memcpy
LIBFT_FILES		+= ft_bzero
LIBFT_FILES		+= ft_putchar_fd
LIBFT_FILES		+= ft_putstr_fd
LIBFT_FILES		+= ft_putendl_fd
LIBFT_FILES		+= ft_memset

GNL_FILES		+= get_next_line
GNL_FILES		+= get_next_line_utils

# FILES			+= $(LIBFT_FILES)
FILES			+= $(GNL_FILES)

SRCS_LIBFT		= $(addprefix ./, $(addsuffix .c, $(LIBFT_FILES)))
OBJS_LIBFT		= $(addprefix ./, $(addsuffix .o, $(LIBFT_FILES)))

SRCS			= $(addprefix ./, $(addsuffix .c, $(FILES)))
OBJS			= $(addprefix ./, $(addsuffix .o, $(FILES)))

# **************************************************************************** #
#                                  Compiler                                    #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
MAKE		= make --no-print-directory
RM			= rm -rf

# **************************************************************************** #
#                                    Comands                                   #
# **************************************************************************** #

all: $(ARQUIVE)
	@printf "$(C_MAGENTA)Program is ready :D$(C_STD)\n"

$(ARQUIVE): $(OBJS) $(OBJS_LIBFT)
	@$(AR) $(ARQUIVE) $(OBJS) $(OBJS_LIBFT)
	@$(CC) $(CFLAGS) $(PUSH_SWAP_FILE) $(ARQUIVE) -o $(PUSH_SWAP)
	@printf "$(C_GREEN)Success to created $(C_STD)$(PUSH_SWAP)\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "Compiling $(C_YELLOW)$<$(C_STD)...\n"

bonus: $(BF) all
	@$(CC) $(CFLAGS) $(CHECKER_FILE) $(ARQUIVE) -o $(CHECKER)

$(BF):
	@touch $(BF)
	@printf "$(C_GREEN)Success to created $(C_STD)$(CHECKER)\n"

clean:
	@$(RM) $(OBJS) $(OBJS_LIBFT)

fclean: clean
	@$(RM) $(ARQUIVE) $(PUSH_SWAP) $(CHECKER) $(BF)

re: fclean all
