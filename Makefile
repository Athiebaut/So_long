NAME = so_long
PRINTF = libftprintf.a
LIBFT = libft.a

SRC_FILES = so_long.c so_long_utils.c valider_carte.c check_carte.c
		
SRC = ${addprefix Src/, ${SRC_FILES}}
OBJ = ${SRC:.c=.o}
CC = cc 
FLAGS = -Wall -Werror -Wextra -g3
RM = rm -f 

${NAME}: ${OBJ}
	@make -C Printf 
	@cp Printf/libftprintf.a .
	@make -C Libft 
	@cp Libft/libft.a .
	${CC} ${FLAGS} ${OBJ} -I Inc ${PRINTF} ${LIBFT} -o ${NAME}


all: ${NAME}
	${CC} ${FLAGS} ${OBJ} -I Inc ${PRINTF} ${LIBFT} -o ${NAME}


clean:
	@make clean -C Printf
	@make clean -C Libft
	${RM} ${OBJ}

fclean: clean
	@make fclean -C Printf
	@make fclean -C Libft
	${RM} ${NAME}
	${RM} ${PRINTF} ${LIBFT}

re: fclean
	make all

.PHONY: all clean fclean re bonus