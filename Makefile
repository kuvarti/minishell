#
#	BAHO AND KUVARTI
#

NAME		= minishell

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
LIBFT		= src/libft/libft.a
INCLUDE		= -Iincludes/. -Isrc/libft

#RDLINE_SRC	= src/utils/lineinput.c
#RDLINE_OBJ	= $(RDLINE_SRC:.c=.o)
#$(RDLINE_OBJ)%.o:$(RDLINE_SRC)%.c
#	$(CC) -lreadline $(CFLAGS) $(INCLUDE) -c $< -o $@

SRC			= $(shell find src -name "*.c" | grep -v "libft") #$(wildcard src/*.c)
OBJ			= $(SRC:.c=.o)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(LIBFT) $(NAME)

$(NAME): $(RDLINE_OBJ) $(OBJ)
ifeq ($(shell uname), Linux)
	@$(CC) -lreadline $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)
endif
ifeq ($(shell uname), Darwin)
	@$(CC) -lreadline $(CFLAGS) $(INCLUDE) $(LIBFT) $(OBJ) -o $(NAME)
endif
	@echo "Compile complated"

run: all
	./$(NAME)

clean:
	@make -C src/libft clean
	@rm -f $(OBJ)
	@echo "Project Objects removed"

fclean: clean
	@rm -f $(NAME) $(LIBFT)
	@rm -rf .history
	@echo "Programs Deleted"

re: fclean all

$(LIBFT):
	@make -C src/libft
