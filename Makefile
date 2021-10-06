# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 20:34:48 by cado-car          #+#    #+#              #
#    Updated: 2021/10/05 22:32:11 by cado-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf
MLX 		= libmlx_Linux.a
LIBFT 		= libft.a

LFT_PATH 	= ./libft/
MLX_PATH 	= ./mlx_linux/
INCLUDES 	= ./include
SRCDIR 		= ./srcs/

SRC 		= $(SRCDIR)main.c \
				$(SRCDIR)close.c \
				$(SRCDIR)color.c \
				$(SRCDIR)draw.c \
				$(SRCDIR)error.c \
				$(SRCDIR)init_utils.c \
				$(SRCDIR)init.c \
				$(SRCDIR)key_handle.c \
				$(SRCDIR)menu.c \
				$(SRCDIR)project.c \
				$(SRCDIR)read.c \
				$(SRCDIR)render.c \
				$(SRCDIR)rotate.c \
				$(SRCDIR)transform.c \
				$(SRCDIR)utils.c

OBJ=$(notdir $(SRC:.c=.o))
#OBJ= fdf.o

#compilation
CF 			= -Wall -Wextra -Werror
CC 			= clang
MLX_CF 		= -lm -lbsd -lmlx -lXext -lX11
CFI 		= -I$(INCLUDES)
LEAKS 		= valgrind
LEAKS_FILE	= valgrind-out.txt
LF 			= --leak-check=full \
        		--show-leak-kinds=all \
        		--track-origins=yes \
        		--verbose \
        		--log-file=$(LEAKS_FILE) \
        		./fdf maps/42.fdf

#common commands
RM =rm -f

#rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@printf "\n$(CY)Generating FdF executable...$(RC)\n"
	$(CC) $(CF) -o $(NAME) $(OBJ) -L $(LFT_PATH) -L $(MLX_PATH) -lft $(MLX_CF)
	mkdir objs
	mv $(OBJ) objs/
	@printf "$(GR)Done!$(RC)\n\n"

$(OBJ): $(SRC)
	@printf "\n$(CY)Compiling source files...$(RC)\n"
	$(CC) $(CF) -g -c -I ./includes/ $(SRC)
	@printf "$(GR)Objects ready!$(RC)\n\n"

$(MLX):
	@printf "\n$(CY)Generating MiniLibX...$(RC)\n"
	@make -C $(MLX_PATH)
	@printf "$(GR)MiniLibX created!$(RC)\n\n"

$(LIBFT):
	@printf "\n$(GR)Generating Libft...$(RC)\n"
	@make -C $(LFT_PATH)
	@printf "$(GR)Libft created!$(RC)\n\n"

bonus: all

clean:
	@printf "\n$(YE)Cleaning all object files from libft...$(RC)\n"
	@make clean -C $(LFT_PATH)
	@printf "$(GR)Libft objects removed!$(RC)\n\n"
	$(RM) -rf $(OBJ) $(BONUS_OBJ) objs/

fclean: clean
	@printf "\n$(YE)Cleaning all additional objects and libraries...$(RC)\n"
	$(RM) -rf $(NAME) $(BONUS_OBJ) objs/
	@make fclean -C $(LFT_PATH)
	@make clean -C $(MLX_PATH)
	@printf "$(GR)All libraries removed!$(RC)\n\n"

re: fclean all

rebonus: fclean bonus

leaks: 
	$(LEAKS) $(LF)

cleanleaks: 
	$(RM) $(LEAKS_FILE)

.PHONY: clean fclean re rebonus all bonus

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m