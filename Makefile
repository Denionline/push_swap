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

PUSH_SWAP	= push_swap
CHECKER		= checker
ARQUIVE		= binary.a

# **************************************************************************** #
#                                    Path's                                    #
# **************************************************************************** #

PUSH_SWAP_FILE	= push_swap.c
CHECKER_FILE	= checker.c

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

LIBFT_FILES		+= ft_isalnum
LIBFT_FILES		+= ft_isalpha
LIBFT_FILES		+= ft_isprint
LIBFT_FILES		+= ft_isdigit
LIBFT_FILES		+= ft_isascii
LIBFT_FILES		+= ft_toupper
LIBFT_FILES		+= ft_tolower
LIBFT_FILES		+= ft_atoi
LIBFT_FILES		+= ft_strncmp
LIBFT_FILES		+= ft_memcmp
LIBFT_FILES		+= ft_strlen
LIBFT_FILES		+= ft_strlcpy
LIBFT_FILES		+= ft_strlcat
LIBFT_FILES		+= ft_strlcpy
LIBFT_FILES		+= ft_substr
LIBFT_FILES		+= ft_strtrim
LIBFT_FILES		+= ft_strchr
LIBFT_FILES		+= ft_strnstr
LIBFT_FILES		+= ft_strmapi
LIBFT_FILES		+= ft_strjoin
LIBFT_FILES		+= ft_strdup
LIBFT_FILES		+= ft_strnstr
LIBFT_FILES		+= ft_itoa
LIBFT_FILES		+= ft_split
LIBFT_FILES		+= ft_strrchr
LIBFT_FILES		+= ft_striteri
LIBFT_FILES		+= ft_memcpy
LIBFT_FILES		+= ft_memmove
LIBFT_FILES		+= ft_calloc
LIBFT_FILES		+= ft_memcpy
LIBFT_FILES		+= ft_bzero
LIBFT_FILES		+= ft_putchar_fd
LIBFT_FILES		+= ft_putstr_fd
LIBFT_FILES		+= ft_putendl_fd
LIBFT_FILES		+= ft_putnbr_fd
LIBFT_FILES		+= ft_memset
LIBFT_FILES		+= ft_memchr

GNL_FILES		+= get_next_line
GNL_FILES		+= get_next_line_utils

FILES			+= $(LIBFT_FILES)
FILES			+= $(GNL_FILES)

SRCS			= $(addprefix ./, $(addsuffix .c, $(FILES)))
OBJS			= $(addprefix ./, $(addsuffix .o, $(FILES)))

# **************************************************************************** #
#                                  Compiler                                    #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
MAKE		= make --no-print-directory

# **************************************************************************** #
#                                    Comands                                   #
# **************************************************************************** #

all: $(ARQUIVE)
	@printf "$(C_MAGENTA)Program is ready :D$(C_STD)\n"

$(ARQUIVE): $(OBJS)
	@$(AR) $(ARQUIVE) $(OBJS) $(LIBFT_OBJS)
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
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(ARQUIVE) $(PUSH_SWAP) $(CHECKER) $(BF)

re: fclean all
