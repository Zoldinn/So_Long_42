NAME = so_long

CFLAGS = -Wall -Wextra -Werror -g -Iincludes

DIR_SRC = src
DIR_OBJ = obj
DIR_INCLUDES = includes
DIR_PRINTF = $(DIR_INCLUDES)/ft_printf
DIR_LIBFT = $(DIR_INCLUDES)/libft
DIR_GNL = $(DIR_INCLUDES)/gnl
DIR_MLX = $(DIR_INCLUDES)/mlx

SRC = $(addprefix $(DIR_SRC)/, so_long.c load.c utils.c key_hooks.c render.c check_map.c)
OBJ = $(addprefix $(DIR_OBJ)/, $(notdir $(SRC:.c=.o)))

PRINTF = $(DIR_PRINTF)/libftprintf.a
LIBFT = $(DIR_LIBFT)/libft.a
GNL = $(DIR_GNL)/gnl.a
MLX = $(DIR_MLX)/libmlx_Linux.a
MLX_FLAGS = -I$(DIR_MLX) -L$(DIR_MLX) -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(LIBFT) $(GNL) $(MLX)
	@echo "🔨 Compilation de $(NAME)..."
	@cc $(OBJ) $(PRINTF) $(LIBFT) $(GNL) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Compilation réussie !"

$(DIR_OBJ)/%.o:$(DIR_SRC)/%.c | $(DIR_OBJ)
	@echo "🔧 Compilation de $<..."
	@cc $(CFLAGS) -c $< -o $@

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)

$(PRINTF):
	@echo "📦 Compilation de ft_printf..."
	@make -s -C $(DIR_PRINTF)

$(LIBFT):
	@echo "📦 Compilation de libft..."
	@make -s -C $(DIR_LIBFT)

$(GNL):
	@echo "📦 Compilation de GNL..."
	@make -s -C $(DIR_GNL)

$(MLX):
	@echo "📦 Compilation de la MiniLibX..."
	@make -s -C $(DIR_MLX) > /dev/null 2>&1
# "> /dev/null 2>&1" pour pas avoir les msg degueu de compil

clean:
	@echo "🧹 Nettoyage des fichiers .o ..."
	@rm -rf $(DIR_OBJ)
	@make -s -C $(DIR_PRINTF) clean
	@make -s -C $(DIR_LIBFT) clean
	@make -s -C $(DIR_GNL) clean
	@make -s -C $(DIR_MLX) clean > /dev/null 2>&1
	@echo "✅ Nettoyage terminé !"


fclean: clean
	@echo "🗑️ Suppression de $(NAME)..."
	@rm -f $(NAME)
	@make -s -C $(DIR_PRINTF) fclean
	@make -s -C $(DIR_LIBFT) fclean
	@make -s -C $(DIR_GNL) fclean
	@echo "✅ Tout a été supprimé !"

re: fclean all

.PHONY: all clean fclean re