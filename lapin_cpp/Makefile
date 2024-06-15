CC = cc

CXX = g++  # Utiliser le compilateur C++ pour compiler les fichiers C++
CXXFLAGS = -Wall -Wextra -Werror

OBJS_DIR = obj

SRCS =  src/Lapin.cpp \
        src/main.cpp \
        src/vie.cpp \
	src/utils.cpp \
	src/destin.cpp

OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

NAME = lapin

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


.PHONY: all clean fclean re