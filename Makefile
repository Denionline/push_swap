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

BF				= .bonus
INC				= include
LIBFT_PATH		= $(INC)/libft/
GNL_PATH		= $(INC)/get_next_line/

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

SRCS			= $(addprefix ./, $(addsuffix .c, $(FILES)))
OBJS			= $(addprefix ./, $(addsuffix .o, $(FILES)))

PUSH_SWAP_FILE	= push_swap.c
CHECKER_FILE	= checker.c

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
	@printf "\n$(C_GREEN)Program is ready :D$(C_STD)\n"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(ARQUIVE): $(OBJS) $(LIBFT)
	@$(AR) $(ARQUIVE) $(OBJS)
	@$(CC) $(CFLAGS) $(PUSH_SWAP_FILE) $(ARQUIVE) $(LIBFT) -I $(INC) -o $(PUSH_SWAP)
	@printf "\n$(C_GREEN)Success to created $(C_STD)$(PUSH_SWAP)\n\n"

%.o: %.c
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@printf "Compiling $(C_YELLOW)$<$(C_STD)...\n"

bonus: verify_gnl $(GNL) $(BF) all
	@$(CC) $(CFLAGS) $(CHECKER_FILE) $(ARQUIVE) $(LIBFT) $(GNL) -I $(INC) -o $(CHECKER)

$(BF):
	@touch $(BF)

$(GNL):
	@$(MAKE) -C $(GNL_PATH)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(ARQUIVE) $(PUSH_SWAP) $(CHECKER)

re: fclean all

# libft processes
verify_libft:
	@if test ! -d "$(LIBFT_PATH)"; then $(MAKE) get_libft; \
		else printf "libft: $(C_GREEN)✅$(C_STD)\n"; fi
	@$(MAKE) update_modules

get_libft:
	@echo "Cloning Libft"
	@git clone $(LIBFT_URL) $(LIBFT_PATH)
	@echo "Libft clone successfully downloaded"

# get_next_line processes
verify_gnl:
	@if test ! -d "$(GNL_PATH)"; then $(MAKE) get_gnl; \
		else printf "get_next_line: $(C_GREEN)✅$(C_STD)\n"; fi
	@$(MAKE) update_modules

get_gnl:
	@printf "Cloning get_next_line\n"
	@git clone $(GNL_URL) $(GNL_PATH)
	@printf "\n$(C_GREEN)get_next_line$(C_STD) successfully downloaded\n"

#general processes
update_modules:
	@git submodule init
	@git submodule update --recursive --remote
# @printf "$(C_BLUE)Updating repository...$(C_STD)\n"
# @printf "$(C_BLUE)Repository updated!$(C_STD)\n\n"