CC = clang
NAME=minirt
MAKEFLAGS += --no-print-directory

INCLUDE = -I include -I /usr/local/include -I $(LIBFT_DIR) -I $(GNL_DIR)
MLX_FLAGS=-lmlx -framework OpenGL -framework AppKit
# CFLAGS = $(INCLUDE) -Imlx
CFLAGS = $(INCLUDE) -Imlx -Wall -Werror -Wextra -O3

OBJS_DIR = objs/

SRC_DIR = src/
SRC_FILES = main.c

MLX_DIR = $(SRC_DIR)mlx/
MLX_FILES = vue.c color.c image.c

COR_DIR = $(SRC_DIR)core/

RAY_DIR = $(COR_DIR)ray/
RAY_FILES = ray.c

VEC_DIR = $(COR_DIR)vec/
VEC_FILES = vec.c vec-arithmetic.c vec-products.c

RENDERER_DIR = $(SRC_DIR)renderer/
RENDERER_FILES = renderer.c

INTERSECTION_DIR = $(RENDERER_DIR)intersect/
INTERSECTION_FILES = sphere.c plane.c cylinder.c

RENDERER_UTILS_DIR = $(RENDERER_DIR)utils/
RENDERER_UTILS_FILES = camera-to-plane.c top-left-corner.c

PLANE_DIR= ./src/plane/
PLANE_FILES = plane.c


CFILES = $(addprefix $(SRC_DIR), $(SRC_FILES))
CFILES += $(addprefix $(MLX_DIR), $(MLX_FILES))
CFILES += $(addprefix $(RAY_DIR), $(RAY_FILES))
CFILES += $(addprefix $(VEC_DIR), $(VEC_FILES))
CFILES += $(addprefix $(RENDERER_DIR), $(RENDERER_FILES))
CFILES += $(addprefix $(INTERSECTION_DIR), $(INTERSECTION_FILES))
CFILES += $(addprefix $(RENDERER_UTILS_DIR), $(RENDERER_UTILS_FILES))

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