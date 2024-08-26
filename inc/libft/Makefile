# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 20:49:10 by ojacobs           #+#    #+#              #
#    Updated: 2024/08/26 20:38:29 by ojacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
WARNING='\033[33m'
DANGER='\033[31m'



SRCS =	        ft_atoi.c\
    ft_atol.c\
    ft_bzero.c\
    ft_calloc.c\
    ft_isalnum.c\
    ft_isalpha.c\
    ft_isascii.c\
    ft_isdigit.c\
    ft_isprint.c\
    ft_isspace.c\
    ft_itoa.c\
    ft_memchr.c\
    ft_memcmp.c\
    ft_memcpy.c\
    ft_memmove.c\
    ft_memset.c\
    ft_putchar_fd.c\
    ft_putendl_fd.c\
    ft_putnbr_fd.c\
    ft_putstr_fd.c\
    ft_split.c\
    ft_strchr.c\
    ft_strdup.c\
    ft_striteri.c\
    ft_strjoin.c\
    ft_strlcat.c\
    ft_strlcpy.c\
    ft_strlen.c\
    ft_strmapi.c\
    ft_strncmp.c\
    ft_strncpy.c\
    ft_strnstr.c\
    ft_strrchr.c\
    ft_strtrim.c\
    ft_substr.c\
    ft_tolower.c\
    ft_toupper.c\
    gnl/get_next_line.c\
    gnl/get_next_line_utils.c\
    printf/ft_print_char.c\
    printf/ft_printf.c\
    printf/ft_print_hex.c\
    printf/ft_print_num.c\
    printf/ft_print_percent.c\
    printf/ft_print_str.c\
    printf/ft_print_unint.c\
    printf/ft_putaddress.c\
    printf/ft_putchar.c\
    printf/ft_putstr.c
 

OBJ_DIR = obj

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)


CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -I. -g #-fsanitize=address 

all:			$(NAME)

$(NAME):		$(OBJS) 
	@ar rcs $(NAME) $(OBJS)> /dev/null 2>&1 || true
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ_DIR)/%.o: %.c
	@echo $(CURSIVE) "     - Building $<" $(NONE)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJ_DIR) > /dev/null 2>&1 || true
	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

fclean:			clean
	@$(RM) $(NAME) > /dev/null 2>&1 || true
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

re:				fclean all

.PHONY:			all clean fclean re