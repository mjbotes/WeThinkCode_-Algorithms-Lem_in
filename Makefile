NAME = lem_in
DIR = ./srcs/
LIBRARY_NAME = libft.a
LIBRARY_DIR = ./incl/libft/
LIBRARY = $(addprefix $(LIBRARY_DIR), $(LIBRARY_NAME))
FLAGS = -Wall -Werror -Wextra
HEAD =	./incl/lem_in.h
FUNC =	ants.c\
		env.c\
		errors.c\
		init.c\
		links.c\
		main.c\
		print.c\
		rooms.c\
		route.c\
		route_helpers.c\
		utils.c\
		error_checks.c
FILES = $(addprefix $(DIR), $(FUNC))
OBJ = $(patsubst %.c, %.o, $(CHECK_FILES))
OBJECTS = $(CHECK_FILES:.c=.o)
all: $(NAME)
$(NAME): $(LIBRARY_NAME) $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(FILES) $(LIBRARY) -I $(HEAD)
	@echo "LEM_IN BUILT"
$(LIBRARY_NAME):
	@make -C $(LIBRARY_DIR)
	@echo "Libft Built!"
%.o: %.c
	gcc -c -o $@ $<
clean:
	@echo "Removing Objects..."
	@/bin/rm -f $(OBJ)
	@make clean -C $(LIBRARY_DIR)
	@echo "Clean complete!"
fclean:
	@echo "Removing Objects..."
	@/bin/rm -f $(NAME) $(PUSH)
	@/bin/rm -f $(CHECK_OBJ) $(PUSH_OBJ)
	@make fclean -C $(LIBRARY_DIR)
	@echo "Fclean complete!"
re: fclean all
