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

EXEC		= push_swap
ARQUIVE		= binary.a
LIBFT		= $(LIBFT_PATH)libft.a

# **************************************************************************** #
#                                    Path's                                    #
# **************************************************************************** #

INC			= include
LIBFT_PATH	= $(INC)/libft/

FILES		+= main
FILES		+= push_swap
FILES		+= ft_sa
FILES		+= ft_sb
FILES		+= ft_pa
FILES		+= ft_pb
FILES		+= ft_ra
FILES		+= ft_rb
FILES		+= ft_rra
FILES		+= ft_rrb

SRC_FILES	= $(addprefix ./, $(FILES))
SRCS		= $(addprefix ./, $(addsuffix .c, $(SRC_FILES)))
OBJS		= $(addprefix ./, $(addsuffix .o, $(SRC_FILES)))

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

all: verify $(LIBFT) $(ARQUIVE)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(ARQUIVE): $(OBJS) $(LIBFT)
	@$(AR) $(ARQUIVE) $(OBJS)
	@$(CC) $(CFLAGS) $(ARQUIVE) $(LIBFT) -o $(EXEC)
	@printf "\n$(C_GREEN)Success to created the executable $(C_STD)$(EXEC)\n\n"

%.o: %.c
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@printf ""

verify:
	@if test ! -d "$(LIBFT_PATH)"; then $(MAKE) get_libft; \
		else printf "\n$(C_GREEN)Libft folder exist!$(C_STD)\n\n"; fi
	@$(MAKE) update_modules

update_modules:
	@printf "$(C_BLUE)Updating repository...$(C_STD)\n"
	@git submodule init
	@git submodule update --recursive --remote
	@printf "$(C_BLUE)Repository updated!$(C_STD)\n\n"

get_libft:
	@echo "Cloning Libft"
	@git clone https://github.com/Denionline/Libft.git $(LIBFT_PATH)
	@echo "Libft clone successfully downloaded"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(ARQUIVE) $(EXEC)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all
