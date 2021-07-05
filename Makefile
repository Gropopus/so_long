# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 21:46:59 by thsembel          #+#    #+#              #
#    Updated: 2021/07/05 15:37:07 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
RED = \033[0;91m
ORANGE = \033[93m
GREEN = \033[0;92m
PURPLE = \033[0;95m
BLUE = \033[0;34m
BOLD = \033[1m

SRCS		=	./srcs/main.c \
				./srcs/ft_parsing.c \
				./srcs/ft_parsing2.c \
				./srcs/key.c \
				./srcs/move.c \
				./srcs/exit.c \
				./srcs/display.c

SRCS_BONUS	=	./bonus/srcs/main.c \
				./bonus/srcs/ft_parsing.c \
				./bonus/srcs/ft_parsing2.c \
				./bonus/srcs/key.c \
				./bonus/srcs/move.c \
				./bonus/srcs/exit.c \
				./bonus/srcs/load_bonus.c \
				./bonus/srcs/display.c

INCLUDES	=	./libft/libft.h \
				./libft/ft_printf.h \
				./includes/so_long.h \
				./includes/mlx.h

INCLUDES_BONUS	=	./libft/libft.h \
					./libft/ft_printf.h \
					./bonus/includes/so_long.h \
					./bonus/includes/mlx.h

HEAD		= ./includes/

HEAD_BONUS	= ./bonus/includes/

LIBFT		= ./libft/libft.a

MLX		= ./mlx_lib/libmlx_Linux.a

#MLX			= ./mlx_lib/libmlx.a

MLX_DIR		= ./mlx_lib/

LIB_DIR		= ./libft/

NAME		= so_long

CC			= clang

OBJS		= ${SRCS:.c=.o}

OBJS_B		= ${SRCS_BONUS:.c=.o}

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g

#LFLAGS		= -framework OpenGL -framework AppKit

LFLAGS		= -lm -lX11 -lXext -lbsd

.c.o:
		@${CC} ${CFLAGS} -I${HEAD_BONUS} -c $< -o ${<:.c=.o}
		@echo "${GREEN}[ OK ]	${ORANGE}${<:.s=.o}${NC}"


all:		${NAME}

${NAME}:	${OBJS}
			@make -C ${LIB_DIR}
			@make -C ${LIB_DIR} bonus
			@echo "${GREEN}\nlibmlx.a		has been created${NC}"
			@echo "${GREEN}\nlibft.a		has been created"
			@${CC} ${CFLAGS} ${LFLAGS} -I${HEAD} -o ${NAME} $(OBJS) ${LIBFT} ${MLX}
			@echo "so_long		has been created\n${NC}"

bonus:		${OBJS_B}
			@make -C ${LIB_DIR}
			@make -C ${LIB_DIR} bonus
			@${CC} ${CFLAGS} ${LFLAGS} -I${HEAD_BONUS} -o ${NAME} $(OBJS_B) ${LIBFT} ${MLX}
			@echo "${GREEN}so_long	with bonus has been created${NC}"

clean:
			@make -C $(LIB_DIR) clean
			@make -C ${MLX_DIR} clean
			@${RM} ${OBJS}
			@${RM} ${OBJS_B}
			@echo "${GREEN}[ OK ]${RED}	*.o files	deleted${NC}"

fclean:		clean
			@make -C $(LIB_DIR) fclean
			@echo "${GREEN}[ OK ]${RED}	libft.a		deleted${NC}"
			@${RM} ${NAME} ${NAME2}
			@echo "${GREEN}[ OK ]${RED}	so_long 	deleted${NC}"

re :		fclean all

.PHONY:		all	clean	fclean re
