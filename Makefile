# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/09/05 09:22:47 by faneyer      #+#   ##    ##    #+#        #
#    Updated: 2019/09/05 09:23:04 by faneyer     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

FILES = bresenham \
		close_event \
		ft_push_back_list \
		get_next_line \
		hud \
		key_event \
		main \
		map_cav \
		map_iso \
		parsing \
		scale \
		untils_free \
		untilscav \
		untilsiso

SRCS = $(addprefix $(PATH_SRCS), $(addsuffix .c, $(FILES)))

PATH_INC = ./includes/

PATH_SRCS = ./srcs/

PATH_OBJ = ./obj/

OBJ = $(addprefix $(PATH_OBJ), $(addsuffix .o, $(FILES)))

INC = $(addprefix $(PATH_INC), fdf.h)

FLAGS = -Wall -Wextra -Werror

FL_DEBUG = -g -fsanitize=address

LIGHT_PINK = \033[0;38;5;200m

PINK = \033[0;38;5;198m

DARK_BLUE = \033[0;38;5;110m

GREEN = \033[0;38;5;111m

LIGHT_GREEN = \033[0;38;5;121m

FLASH_GREEN = \033[33;32m

all: $(NAME)

$(NAME): lib $(PATH_OBJ) $(OBJ)
	@echo "$(DARK_BLUE)\nFichiers de "$(NAME)" compilés\n"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) ./libft/libft.a ./Ressource/minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
	@echo "$(FLASH_GREEN)Programme "$(NAME)" compilé et prêt à l'usage !\n"

$(PATH_OBJ):
	@mkdir obj
	@echo "$(DARK_BLUE) creating object directory"

$(PATH_OBJ)%.o: $(PATH_SRCS)%.c $(INC) libft/libft.a
	@echo "$(OBJ)"
	@gcc $(FLAGS) -g -o $@ -c $< -I $(INC)
	@echo "$(DARK_BLUE).\c"

lib:
	@(cd libft && make)

lib_clean:
	@(cd libft && make clean)

lib_fclean:
	@(cd libft && make fclean)

lib_re:
	@(cd libft && make re)

debug: lib $(PATH_OBJ) $(OBJ)
	@gcc $(FL_DEBUG) -o $(NAME) $(OBJ) libft/libft.a ./Ressource/minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

clexec: fclean
	@echo "deleting executable"
	@rm  -f fdf

clean: lib_clean
	@/bin/rm -f $(OBJ)
	@echo "$(LIGHT_PINK)Suppression des .o de "$(NAME)"\n"

fclean: clean lib_fclean
	@/bin/rm -f $(NAME)
	@echo "$(PINK)Suppression de" $(NAME)"\n"

re: lib_re fclean all

.PHONY: all clean fclean re clexec
