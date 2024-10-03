NAME =		cub3d

SRC =		./src/move/handle_move.c \
			./src/move/handle_mouse.c \
			./src/parse/parse.c \
			./src/parse/parse_map.c \
			./src/render/render.c \
			./src/render/render_tools.c \
			./src/render/draw.c \
			./src/render/minimap.c \
			./src/tools/tools.c \
			./src/main.c

CFLAGS =	-Wall -Wextra -Werror -O3 -g #-fsanitize=address 

RED =		\033[0;31m
BLUE =		\033[0;34m
GREEN =		\033[0;32m
RESET =		\033[0m

LIBMLX	:= ./MLX42
HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

LIBFTPATH =	./libft/
LIBFT =		$(LIBFTPATH)libft.a

OBJ_DIR =	obj

OBJ =		$(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	cc $(CFLAGS) -c $< $(HEADERS) -o $@

$(NAME) :	$(OBJ_DIR) $(OBJ)
	@echo "$(BLUE)Building $(NAME)...$(RESET)"
	make -C $(LIBFTPATH) all -s
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	cc $(CFLAGS) $(OBJ) $(LIBS) $(LIBFT) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)$(NAME) built$(RESET)"

all :		$(NAME)

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX)/build
	make -C $(LIBFTPATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTPATH) fclean

re: fclean all

.PHONY:
	all clean fclean re