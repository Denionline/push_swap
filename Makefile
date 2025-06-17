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
LIBFT		= $(LIBFT_PATH)libft.a
GNL			= $(GNL_PATH)get_next_line.a

# **************************************************************************** #
#                                    Git                                       #
# **************************************************************************** #

LIBFT_URL	= https://github.com/Denionline/Libft.git
GNL_URL		= https://github.com/Denionline/get_next_line.git

# **************************************************************************** #
#                                    Path's                                    #
# **************************************************************************** #

INC			= include
LIBFT_PATH	= $(INC)/libft/
GNL_PATH	= $(INC)/get_next_line/

FILES		+= push_swap
FILES		+= sort
FILES		+= sn
FILES		+= ss
FILES		+= pn
FILES		+= rn
FILES		+= rr
FILES		+= rrn
FILES		+= rrr
FILES		+= parse
FILES		+= verify
FILES		+= rotates
FILES		+= calc_moves
FILES		+= get_number
FILES		+= find_lis_sequence

SRCS		= $(addprefix ./, $(addsuffix .c, $(FILES)))
OBJS		= $(addprefix ./, $(addsuffix .o, $(FILES)))

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

all: verify_libft $(LIBFT) $(ARQUIVE)
	@echo "✅ Tudo está atualizado!"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(ARQUIVE): $(OBJS) $(LIBFT)
	@$(AR) $(ARQUIVE) $(OBJS)
	@$(CC) $(CFLAGS) $(ARQUIVE) $(LIBFT) -o $(PUSH_SWAP)
	@printf "\n$(C_GREEN)Success to created the executable $(C_STD)$(PUSH_SWAP)\n\n"

%.o: %.c
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@printf "Compiling $(C_YELLOW)$<$(C_STD)...\n"

bonus: all verify_gnl $(GNL)
	@$(AR) $(ARQUIVE) $()

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(ARQUIVE) $(PUSH_SWAP)

re: fclean all


# libft processes
verify_libft:
	@if test1 ! -d "$(LIBFT_PATH)"; then $(MAKE) get_libft; \
		else printf "\n$(C_GREEN)Libft folder exist!$(C_STD)\n\n"; fi
	@$(MAKE) modules_libft

modules_libft:
	@printf "$(C_BLUE)Updating repository...$(C_STD)\n"
	@git submodule init
	@git submodule update --recursive --remote
	@printf "$(C_BLUE)Repository updated!$(C_STD)\n\n"

get_libft:
	@echo "Cloning Libft"
	@git clone $(LIBFT_URL) $(LIBFT_PATH)
	@echo "Libft clone successfully downloaded"

# get_next_line processes
verify_gnl:
	@if test2 ! -d "$(GNL_PATH)"; then $(MAKE) get_gnl; \
		else printf "\n$(C_GREEN)get_next_line folder exist!$(C_STD)\n\n"; fi
	@$(MAKE) modules_gnl

modules_gnl:
	@git submodule init
	@git submodule update --recursive --remote
# @printf "$(C_BLUE)Updating repository...$(C_STD)\n"
# @printf "$(C_BLUE)Repository updated!$(C_STD)\n\n"

get_gnl:
	@echo "Cloning get_next_line"
	@git clone $(GNL_URL) $(GNL_PATH)
	@echo "get_next_line clone successfully downloaded"