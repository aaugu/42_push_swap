NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror

INCLUDE = -I include -I libft
LIB = -Llibft -lft
LIBFT = libft/libft.a

RM = rm -f

SRCS_FILES = 	push_swap.c \

SRCS = $(addprefix ./src/, $(SRCS_FILES))
OBJS = $(SRCS:%.c=%.o)

%.o : %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			@echo " [ .. ] | Compiling push_swap.."
			$(CC) $(FLAGS) $(LIB) $(OBJS) -o $(NAME)
			@echo " [ OK ] | push_swap ready!"

$(LIBFT):	
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

clean:		
			@echo " [ .. ] | Cleaning objects.."
			@make -s -C libft clean
			@($(RM) $(OBJS))
			@echo " [ OK ] | Objects removed!"

fclean: 	clean
			@echo " [ .. ] | Cleaning libraries and executable.."
			@make -s -C libft fclean
			@($(RM) $(NAME))
			@echo " [ OK ] | Everything is clean!"

re: 		fclean all

.PHONY:		all clean fclean re