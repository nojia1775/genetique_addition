CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = obj

SRCS =	src/main.c \
	src/aff.c \
	src/gen.c \
	src/utils.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

NAME = lapin

$(NAME): $(OBJS)
	@make -C LIBFT
	$(CC) $(CFLAGS) $^ -o $@ LIBFT/libft.a
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@make clean -C LIBFT
	rm -f $(OBJS)

fclean: clean
	@make fclean -C LIBFT
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re