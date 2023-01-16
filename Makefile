NAME = cub3D
HEADER = header3D.h
SOURCES = cub3d/main.c cub3d/draw.c cub3d/ft_itoa.c cub3d/mlx.c cub3d/player.c cub3d/rays2.c cub3d/actions.c cub3d/draw2d.c  cub3d/minimap.c cub3d/moves.c cub3d/rays.c cub3d/utils.c \
	prs/checking.c prs/functions.c prs/parser_map.c prs/split_by_lim.c prs/checking1.c prs/functions1.c prs/map_queue.c prs/parser1.c prs/parser_map1.c prs/split_by_space.c prs/errors.c prs/parser.c prs/parser2.c prs/split.c prs/valid.c \
	prs/gnl/get_next_line_utils.c prs/gnl/get_next_line.c
SRC_PATH = srcs
OBJ_PATH  = objs

CC = cc
CFLAGS = -Wall -Wextra -Werror 
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

.PHONY:	all clean fclean re bonus

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

all : $(OBJ_PATH) $(NAME)

$(NAME) : $(OBJS) 
	$(CC) $(MLX_FLAGS) $(OBJS) $(CFLAGS) -o  $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c incs/$(HEADER)
	@$(CC)  -c -o  $@ $<

$(OBJ_PATH):
	@mkdir objs
	@mkdir objs/cub3d
	@mkdir objs/prs
	@mkdir objs/prs/gnl

clean:
	rm -fr $(OBJS)
	rm -fr $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	rm -fr $(OBJ_PATH)
re : fclean all
