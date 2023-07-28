NAME = so_long
PRINTF = Printf/libftprintf.a
LIBFT = Libft/libft.a
MLX = mlx_linux/libmlx_Linux.a

SRC_FILES = so_long.c so_long_utils.c valider_carte.c check_carte.c gestion_fenetre.c remplir_fenetre.c
		
SRC = ${addprefix Src/, ${SRC_FILES}}
OBJ = ${SRC:.c=.o}
CC = cc 
FLAGS = -Wall -Werror -Wextra -g3
RM = rm -f 

${NAME}: ${OBJ}
	@make -C Printf 
	@make -C Libft
	@make -C mlx_linux
	${CC} ${FLAGS} ${OBJ} -I Inc ${PRINTF} ${LIBFT} ${MLX} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}


all: ${NAME}
#${CC} ${FLAGS} ${OBJ} -I Inc ${PRINTF} ${LIBFT} -o ${NAME}


clean:
	@make clean -C Printf
	@make clean -C Libft
	@make clean -C mlx_linux
	${RM} ${OBJ}

fclean: clean
	@make fclean -C Printf
	@make fclean -C Libft
	${RM} ${NAME}

re: fclean
	make all

.PHONY: all clean fclean re bonus