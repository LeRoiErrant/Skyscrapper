# **************************************************************************** #
#							PROJECT'S DIRECTORY								   #
# **************************************************************************** #

NAME = Skyscrapper

# **************************************************************************** #
#						COMPILATION AND LINK FLAGS							   #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_FLAGS =

# **************************************************************************** #
#								SOURCE FILES								   #
# **************************************************************************** #

SRC = main.c \
	check_args.c \
	parse_args.c \
	solver.c \
	print_tbl.c
SRC_BONUS = bonus/main.c \
	bonus/check_args.c \
	bonus/parse_args.c \
	bonus/solver.c \
	bonus/print_tbl.c
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

# **************************************************************************** #
#								COLORS										   #
# **************************************************************************** #

BOLD = \033[1m
ITAL = \033[3m
UNDL = \033[4m
BLNK = \033[5m
REVR = \033[7m
GR = \033[32;1m
RE = \033[31;1m
YE = \033[33;1m
CY = \033[36;1m
RC = \033[0m

# **************************************************************************** #
#							MAKEFILE RULES									   #
# **************************************************************************** #

export NOW := $(shell date '+%F_%H:%M:%S')

all: ${NAME}

${NAME}: compile ${OBJS} c_done
	@printf "$(YE) Linking...$(RC)\n"
	@${CC} ${CFLAGS} ${OBJS} ${LIB_FLAGS} -o ${NAME}
	@printf "$(GR) => Success !$(RC)\n\n" 

bonus: compile ${OBJS_BONUS} c_done
	@printf "$(YE) Linking...$(RC)\n"
	@${CC} ${CFLAGS} ${OBJS_BONUS} ${LIB_FLAGS} -o ${NAME}
	@printf "$(GR) => Success !$(RC)\n\n" 

.c.o:
	@${CC} ${CFLAGS} -o $@ -c $<
	@printf "$(GR)$(REVR) $(RC)"

compile:
	@echo "\n$(GR)[X] Compiling ${NAME}$(RC)\n"

c_done:
	@echo "$(GR) => 100%$(RC)\n"

clean:
	@printf "\n$(YE)Cleaning...\n"
	@rm -f ${OBJS}
	@rm -f ${OBJS_BONUS}
	@printf "\n$(GR)=> Cleaning complete!$(RC)\n\n"

fclean: clean
	@printf "$(YE)Delete ${NAME}...\n"
	@rm -f ${NAME}
	@printf "\n$(GR)=> ${NAME} deleted!$(RC)\n\n"

git:
	git add .
	git commit -m "Upload by $(LOGNAME) $(NOW)"
	git push

launch: all
	./$(NAME)

re: fclean all

vg: all
	@valgrind --leak-check=full --track-origins=yes ./${NAME}

.PHONY: all bonus clean fclean launch re