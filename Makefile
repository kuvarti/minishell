NAME = minishell

CFLAGS = $(INCLUDE)
INCLUDE = -IInclude/
CC = gcc

SRC = $(shell find Src -name "*.c")
SRCDIR = $(sort $(dir $(SRC)))
SRCFLS = $(notdir $(SRC))

OUTPREFIX = objects/
OBJ = $(addprefix $(OUTPREFIX), $(SRCFLS:.c=.o))

vpath %.c $(SRCDIR)
$(OUTPREFIX)%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: outfolder $(NAME)
	@echo "Done"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -lreadline -o $(NAME)

outfolder:
	@echo "Building Minishell"
	@if [ ! -d $(OUTPREFIX) ]; then echo "$(OUTPREFIX) folder created."; fi
	@mkdir -p $(OUTPREFIX);
	@echo "Compiling Files..."

clean:
	@echo "Cleaning Objects..."
	@if [ -d $(OUTPREFIX) ]; then rm -rf $(OUTPREFIX); fi

fclean: clean
	@echo "Cleaning Program..."
	@if [ ! -d $(NAME) ]; then rm -rf $(NAME); fi
	@echo "Done"

re: fclean seperate all

seperate:
	@echo "-----------------"

.PHONY:
	all clean fclean re seperate

check:
	@echo "SRC : "
	@echo $(SRC)
	@echo "\nSRCDIR : "
	@echo $(SRCDIR)
	@echo "\nSRCFLS : "
	@echo $(SRCFLS)
	@echo "\nOBJ : "
	@echo $(OBJ)
