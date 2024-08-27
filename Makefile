# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 16:47:27 by ojacobs           #+#    #+#              #
#    Updated: 2024/08/27 14:24:27 by ojacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		so_long

SRCS =  $(SRC_DIR)so_long.c\
		$(SRC_DIR)error_check_utils.c\
		$(SRC_DIR)map_error_check.c\
		$(SRC_DIR)pre_load_map.c\
		$(SRC_DIR)validate_map.c\
		$(SRC_DIR)game_init.c\
		$(SRC_DIR)hooks.c\
		$(SRC_DIR)render_map.c\
		$(SRC_DIR)so_long_utils.c\
		#$(SRC_DIR)main.c\
		

RM = rm -rf

CC = gcc -g #-fsanitize=address

CFLAGS =  -Werror -Wall -Wextra -I$(INC_DIR) -Imlx

SRC_DIR = src/

OBJ_DIR = obj

INC_DIR = inc

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFTDIR = ./$(INC_DIR)/libft

LIBFTA = $(LIBFTDIR)/libft.a

MLX_DIR = minilibx-linux/
MLX = $(MLX_DIR)/libmlx_Linux.a
LINK = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz -lGL

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
WARNING='\033[33m'
DANGER='\033[31m'


all: $(NAME)


$(NAME): $(LIBFTA) $(OBJS)  #$(SRC) $(MLX) 
	@$(CC) $(OBJS) $(LIBFTA) $(LINK) -o $@
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ_DIR)/%.o: %.c $(LIBFTA)
	@echo $(CURSIVE) "     - Building $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# $(MLX):
# 	@echo $(CURSIVE)$(WARNING) "     - (Wait a sec...) Building $@" $(NONE)
# 	@make -C $(MLX_DIR) > /dev/null || true

$(LIBFTA):
	@echo $(CURSIVE)$(WARNING) "     - (Wait a sec...) Building $@" $(NONE)
	@make all -C $(LIBFTDIR) > /dev/null || true

clean:
	@$(RM) $(OBJS) $(OBJ_DIR)
	@make -C $(LIBFTDIR) clean > /dev/null || true
	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

fclean: clean
	@rm -f $(NAME) > /dev/null || true
	@make -C $(LIBFTDIR) fclean > /dev/null || true
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

re: fclean all

.PHONY: all clean fclean re