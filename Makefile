CC = gcc
NAME=minirt
MAKEFLAGS += --no-print-directory

INCLUDE = -I include -I /usr/local/include -I $(LIBFT_DIR) -I $(GNL_DIR)
MLX_FLAGS=-lmlx -framework OpenGL -framework AppKit
CFLAGS = $(INCLUDE) -Imlx -O3
# CFLAGS = $(INCLUDE) -Imlx -Wall -Werror -Wextra -O3

OBJS_DIR = objs/

SRC_DIR = src/
SRC_FILES = main.c

MLX_DIR = $(SRC_DIR)mlx/
MLX_FILES = vue.c color.c image.c

COR_DIR = $(SRC_DIR)core/

RENDERER_DIR = $(SRC_DIR)renderer/
RENDERER_FILES = renderer.c

POINT_DIR = $(COR_DIR)point/
POINT_FILES = point.c

COLOR_DIR = $(COR_DIR)color/
COR_FILES = color.c mult.c

VEC_DIR = $(COR_DIR)vector/
VEC_FILES = vector.c

TUPLE_DIR = $(COR_DIR)tuple/
TUPLE_FILES = tuple.c add.c sub.c scale.c \
							normalize.c negate.c length.c \
							dot.c div.c cross.c

UTILS_DIR = $(SRC_DIR)utils/
UTILS_FILES = float_cmp.c

MATRIX_DIR = $(COR_DIR)matrix/
MATRIX_FILES = compair.c matrix.c mult.c \
							 transpos.c determinant.c sub-matrix.c \
							 minor.c delete.c cofactor.c is-invert.c \
							 invert.c translate.c scale.c rotate.c

RAY_DIR = $(COR_DIR)ray/
RAY_FILES = ray.c delete.c at.c transform.c \
						print.c ray-for-px.c

HIT_DIR = $(RENDERER_DIR)hit/
HIT_FILES = hit.c sphere.c delete.c cylinder.c plane.c

ENTITY_DIR = $(RENDERER_DIR)entity/
ENTITY_FILES = entity.c sphere.c

LIGHT_DIR = $(RENDERER_DIR)light/
LIGHT_FILES = lighting.c

NORMALS_DIR = $(COR_DIR)normals/
NORMALS_FILES = sphere.c

REFLECTION_DIR = $(COR_DIR)reflection/
REFLECTION_FILES = reflection.c

MATERIAL_DIR = $(COR_DIR)material/
MATERIAL_FILE = material.c

CAMERA_DIR = $(COR_DIR)camera/
CAMERA_FILES = camera.c transform.c

PARSE_DIR = $(SRC_DIR)parsing/
PARSER_FILES = parse_ambient.c parse_cam.c parse_cy.c \
							parse_file.c parse_light.c parse_pl.c parse_sp.c


CFILES = $(addprefix $(SRC_DIR), $(SRC_FILES))
CFILES += $(addprefix $(MLX_DIR), $(MLX_FILES))
CFILES += $(addprefix $(POINT_DIR), $(POINT_FILES))
CFILES += $(addprefix $(VEC_DIR), $(VEC_FILES))
CFILES += $(addprefix $(UTILS_DIR), $(UTILS_FILES))
CFILES += $(addprefix $(TUPLE_DIR), $(TUPLE_FILES))
CFILES += $(addprefix $(MATRIX_DIR), $(MATRIX_FILES))
CFILES += $(addprefix $(RAY_DIR), $(RAY_FILES))
CFILES += $(addprefix $(HIT_DIR), $(HIT_FILES))
CFILES += $(addprefix $(ENTITY_DIR), $(ENTITY_FILES))
CFILES += $(addprefix $(LIGHT_DIR), $(LIGHT_FILES))
CFILES += $(addprefix $(COLOR_DIR), $(COR_FILES))
CFILES += $(addprefix $(NORMALS_DIR), $(NORMALS_FILES))
CFILES += $(addprefix $(REFLECTION_DIR), $(REFLECTION_FILES))
CFILES += $(addprefix $(MATERIAL_DIR), $(MATERIAL_FILE))
CFILES += $(addprefix $(CAMERA_DIR), $(CAMERA_FILES))
CFILES += $(addprefix $(PARSE_DIR), $(PARSER_FILES))
CFILES += $(addprefix $(RENDERER_DIR), $(RENDERER_FILES))

OFILES_ = $(patsubst %.c, %.o, $(CFILES))
OFILES = $(addprefix $(OBJS_DIR), $(OFILES_))

LIBFT_DIR = ./libs/libft/
LIBFT = libft.a

GNL_DIR = ./libs/gnl/
GNL = get_next_line.o

LIBS = $(LIBFT_DIR)$(LIBFT) $(GNL_DIR)$(GNL)

INCLUDE += -I $(LIBFT_DIR) -I $(GNL_DIR)


all: $(NAME)

$(NAME): $(OFILES) $(GNL_DIR)$(GNL) 
	@echo "$(green)source files compiled successfully \n $(reset)"
	@echo "$(yellow)linking object files.. $(reset)"

	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBS) $(OFILES) -o $(NAME)

	@echo "$(green)All done, binary file path: ./$(NAME)$(reset)"

fsanitize: CFLAGS += -fsanitize=address -g
fsanitize: all
	@echo "$(red)fsanitize activated $(reset)"

debug: CFLAGS += -g
debug: all

error: CFLAGS += -Wall -Werror -Wextra
error: all

$(OBJS_DIR)%.o:%.c
	@echo "$(yellow)Compiling $(reset)$<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)$(LIBFT):
	@echo "$(yello)Compiling libft$(reset)"
	@$(MAKE) -C $(LIBFT_DIR) bonus

$(GNL_DIR)$(GNL): $(LIBFT_DIR)$(LIBFT)
	@echo "$(yellow)Compiling gnl$(reset)"
	$(MAKE) -C $(GNL_DIR) 

re: fclean all

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@rm -f $(NAME)

clean:
	@echo "$(yellow)Cleaning libft.. $(reset)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(yellow)Cleaning gnl.. $(reset)"
	@$(MAKE) -C $(GNL_DIR) clean
	@echo "$(yellow)Cleaning object files... $(reset)"
	@rm -f $(OFILES)
	@rm -rf $(OBJS_DIR)
	@echo "$(green)object files cleaned \n $(reset)"

.PHONY: clean fclean re

# colors
yellow=`tput setaf 3`
green=`tput setaf 2`
red=`tput setaf 1`
reset=`tput sgr0`
