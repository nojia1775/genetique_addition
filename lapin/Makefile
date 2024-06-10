CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = obj

SRCS =	src/main.c \
	src/aff.c \
	src/gen.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

NAME = lapin

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re