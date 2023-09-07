# .SUFFIXES	:
NAME = so_long
NAMEB = so_long_bonus
PRINTF = Printf/libftprintf.a
LIBFT = Libft/libft.a
MLX = mlx_linux/libmlx_Linux.a
LINKS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC_FILES = so_long.c \
		so_long_utils.c \
		map_certify.c \
		check_map.c \
		window_handler.c \
		fill_window.c \
		key_hook.c

SRC_FILESB = so_long_bonus.c \
		so_long_utils_bonus.c \
		map_certify_bonus.c \
		check_map_bonus.c \
		window_handler_bonus.c \
		fill_window_bonus.c \
		key_hook_bonus.c \
		enemy_handler_bonus.c \
		animations_bonus.c
		
SRC = ${addprefix Src/, ${SRC_FILES}}
SRCB = ${addprefix Srcb/, ${SRC_FILESB}}
OBJ = ${SRC:.c=.o}
OBJB = ${SRCB:.c=.o}
CC = cc 
FLAGS = -Wall -Werror -Wextra -g3
RM = rm -f 

${NAME}: ${OBJ}
	make -C Printf 
	make -C Libft
	make -C mlx_linux
	${CC} ${FLAGS} ${OBJ} -I Inc ${PRINTF} ${LIBFT} ${MLX} ${LINKS} -o ${NAME}


all: ${NAME}

bonus: ${NAMEB}

${NAMEB}: ${OBJB}
	make -C Printf 
	make -C Libft 
	make -C mlx_linux
	${CC} ${FLAGS} ${OBJB} -I Inc ${PRINTF} ${LIBFT} ${MLX} ${LINKS} -o ${NAMEB}

clean:
	make clean -C Printf
	make clean -C Libft
	make clean -C mlx_linux
	${RM} ${OBJ} ${OBJB}

fclean: clean
	make fclean -C Printf
	make fclean -C Libft
	${RM} ${NAME} ${NAMEB}
	${RM} ${PRINTF} ${LIBFT}

re: fclean
	make all

.PHONY: all clean fclean re bonus