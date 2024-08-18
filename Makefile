# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 16:47:27 by ojacobs           #+#    #+#              #
#    Updated: 2024/08/18 16:53:51 by ojacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =  $(SRC_DIR)test_main.c\
		#$(SRC_DIR)game_init.c\
		$(SRC_DIR)hooks.c\
		$(SRC_DIR)render_map.c\
		$(SRC_DIR)main.c\
		

RM = rm -rf

CC = gcc -g #-fsanitize=address

CFLAGS =  -Wall -Wextra -I$(INC_DIR) -Imlx

SRC_DIR = src/

OBJ_DIR = obj/

INC_DIR = inc/

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFTDIR = ./$(INC_DIR)/libft

LIBFTA = $(LIBFTDIR)/libft.a

MLX_DIR = mlx/
MLX = $(MLX_DIR)/minilibx-linux/libmlx_Linux.a
LINK = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz -lGL

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
WARNING='\033[33m'
DANGER='\033[31m'


all: $(NAME)


$(NAME): $(LIBFTA) $(MLX) $(OBJS)  #$(SRC)
	@$(CC) $(OBJS) $(LIBFTA) $(LINK) -o $@
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ_DIR)/%.o: %.c $(LIBFTA)
	@echo $(CURSIVE) "     - Building $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	@make -C $(MLX_DIR)

$(LIBFTA):
	@echo $(CURSIVE)$(WARNING) "     - (Wait a sec...) Building $@" $(NONE)
	@make all -C $(LIBFTDIR) > /dev/null || true

clean:
	@$(RM) $(OBJS) $(OBJ_DIR)
	@make -C $(LIBFTDIR) clean > /dev/null || true
	@make -C $(MLX_DIR) clean > /dev/null || true
	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

fclean: clean
	@rm -f $(NAME) > /dev/null || true
	@make -C $(LIBFTDIR) fclean > /dev/null || true
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

re: fclean all

.PHONY: all clean fclean re