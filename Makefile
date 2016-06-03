NAME	= fillit
CC		= gcc
S_DIR	= 
O_DIR	= 
I_DIR	= -Wall -Werror -Wextra
FLAGS	= $(I_DIR) $(LIBS_DIR)
FILES	= ft_error.c ft_clean_tab.c ft_resolve.c ft_check_piece.c ft_place_piece.c ft_aff_tab.c main.c 
LIBS_F	= libft.a
SRC		= $(addprefix $(S_DIR),$(FILES))
OBJS	= $(addprefix $(O_DIR),$(FILES:.c=.o))
LIBS	= $(addprefix -L. ,$(LIBS_F))
RM		= rm -f

all: $(NAME)

$(NAME): 	$(OBJS) 
	make -C libft all
	@$(CC) $(FLAGS) ./libft/$(LIBS_F) $^ -o $@
	@echo "./[0;34m$(NAME)[0;1m created."
	@echo "[0;1mDone."

$(O_DIR)%.o:		$(S_DIR)%.c
	@echo "[0;33m$<[0;37m"
	@echo "↪︎- [0;32m$@[0;1m"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	make -C libft clean
	@$(RM) $(OBJS)

fclean: 	clean
	make -C libft fclean
	@$(RM) $(NAME)
	@echo "[0;1mClear."

re:			fclean all

.PHONY : all clean fclean re
