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
#                                    Git                                       #
# **************************************************************************** #

LIBFT_URL	= https://github.com/Denionline/Libft.git

# **************************************************************************** #
#                                    Path's                                    #
# **************************************************************************** #

INC			= include
LIBFT_PATH	= $(INC)/libft/

FILES		+= main
FILES		+= push_swap
FILES		+= ft_sn
FILES		+= ft_pn
FILES		+= ft_rn
FILES		+= ft_rrn

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
#                                    Tests                                     #
# **************************************************************************** #

TEST1		= 329 353 164 94 981 245 693 183 118 404 840 470 68 796 273 220 507 329 531 968 123 626 937 381 309 795 675 43 39 691 598 339 566 854 633 492 546 927 821 507 78 42 783 128 803 358 774 606 234 893 723 928 622 837 236 700 733 945 887 146 460 450 897 567 644 437 176 431 699 497 167 553 129 765 61 828 310 356 366 178 840 625 529 529 135 823 543 749 483 91 612 217 4 665 860 532 870 974 558 281

TEST2		= 306 255 38 429 601 561 67 43 729 978 725 933 584 52 779 501 59 635 175 295 220 838 988 418 145 322 981 921 993 464 226 527 647 906 866 306 386 207 787 161 747 742 404 485 661 498 694 214 25 294 674 645 325 120 217 561 37 138 542 197 866 371 640 78 601 150 161 939 550 589 667 988 896 253 55 864 901 63 959 757 865 978 688 624 243 182 721 197 397 798 155 375 992 718 183 59 269 172 501 30
TEST3		= 125 869 710 410 210 607 927 985 12 581 456 880 359 246 927 149 21 587 954 664 981 339 771 498 895 257 721 284 294 39 541 300 839 388 100 285 545 955 421 675 806 447 607 260 606 54 860 526 457 45 498 374 225 519 143 949 891 479 586 971 883 935 580 738 642 593 900 605 922 497 451 544 721 892 996 100 923 479 397 503 109 872 739 504 535 953 345 824 82 791 192 653 14 450 673 972 578 385 838 622
TEST4		= 945 719 347 537 188 804 987 571 751 127 807 478 504 799 676 499 472 369 852 236 832 702 576 27 829 87 490 771 487 265 75 198 267 424 472 262 105 348 793 154 354 955 357 2 696 647 671 448 532 56 390 988 820 928 705 318 779 551 346 589 100 780 975 607 732 743 875 950 243 566 525 318 604 518 19 873 681 91 863 33 470 603 76 505 414 843 671 691 77 342 65 184 882 797 236 510 396 172 673 233
TEST5		= 235 815 1 97 540 786 783 656 997 466 962 788 926 275 13 546 166 233 550 551 697 36 735 396 588 939 382 939 999 774 275 62 913 573 887 392 932 559 68 265 199 981 646 102 736 880 645 398 996 275 427 884 781 24 142 962 823 369 221 305 505 697 928 992 134 162 186 637 299 30 679 934 826 29 491 501 811 998 528 532 405 648 261 691 939 977 953 564 835 211 426 924 594 569 967 644 202 143 847 361

# **************************************************************************** #
#                                    Comands                                   #
# **************************************************************************** #

all: verify $(LIBFT) $(ARQUIVE)
	@echo "✅ Tudo está atualizado!"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(ARQUIVE): $(OBJS) $(LIBFT)
	@$(AR) $(ARQUIVE) $(OBJS)
	@$(CC) $(CFLAGS) $(ARQUIVE) $(LIBFT) -o $(EXEC)
	@printf "\n$(C_GREEN)Success to created the executable $(C_STD)$(EXEC)\n\n"

%.o: %.c
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@printf "Compiling $(C_YELLOW)$<$(C_STD)...\n"

pr:
	@clear
	@printf "Test 1:\n"
	@./$(EXEC) p $(TEST1)
	@printf "\nTest 2:\n"
	@./$(EXEC) p $(TEST2)
	@printf "\nTest 3:\n"
	@./$(EXEC) p $(TEST3)
	@printf "\nTest 4:\n"
	@./$(EXEC) p $(TEST4)
	@printf "\nTest 5:\n"
	@./$(EXEC) p $(TEST5)

cop:
	@clear
	@printf "Test 1:\n"
	@./$(EXEC) $(TEST1) | ./countop.sh
	@printf "\nTest 2:\n"
	@./$(EXEC) $(TEST2) | ./countop.sh
	@printf "\nTest 3:\n"
	@./$(EXEC) $(TEST3) | ./countop.sh
	@printf "\nTest 4:\n"
	@./$(EXEC) $(TEST4) | ./countop.sh
	@printf "\nTest 5:\n"
	@./$(EXEC) $(TEST5) | ./countop.sh

help:
	@printf "\n$(C_MAGENTA)MAKE TYPES$(C_STD)\n\n"
	@printf "[$(C_GREEN)pr$(C_STD)] = Print the sorted array;\n"
	@printf "[$(C_GREEN)cop$(C_STD)] = Show the amount of each operation.\n\n"

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
	@git clone $(LIBFT_URL) $(LIBFT_PATH)
	@echo "Libft clone successfully downloaded"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(ARQUIVE) $(EXEC)

re: fclean all
