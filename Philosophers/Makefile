NAME        = philo
CC          = gcc
CFLAGS      = -g -O0 -Wall -Wextra -Werror -Iinclude -pthread
RM          = rm -f

SRC_DIR     = src
UTILS_DIR   = utils

SRC         = $(SRC_DIR)/main.c \
              $(SRC_DIR)/dinner.c \
              $(SRC_DIR)/getters_setters.c \
              $(SRC_DIR)/init.c \
              $(SRC_DIR)/monitoring.c \
              $(SRC_DIR)/parsing.c \
              $(SRC_DIR)/safe_functions.c \
              $(SRC_DIR)/write.c \
              $(UTILS_DIR)/synchro_utils.c \
              $(UTILS_DIR)/utils.c

OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ Build complete!"

%.o: %.c
	@echo "🔨 Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "🧹 Cleaning object files..."
	@$(RM) $(OBJ)

fclean: clean
	@echo "🧨 Removing binary..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
