##
## EPITECH PROJECT, 2023
## read_html_file
## File description:
## Makefile
##

SRCS		=		./funcs/my_getnbr.c		\
					./funcs/my_putchar.c	\
					./funcs/my_put_nbr.c	\
					./funcs/my_putstr.c		\
					./funcs/my_strcpy.c		\
					./funcs/my_strlen.c		\
					./funcs/my_isdigit.c	\
					./funcs/my_strcmp.c		\
					./funcs/my_strncmp.c	\
					./funcs/my_calloc.c		\
					./funcs/my_memset.c		\
					./funcs/my_show_array.c	\
					./funcs/my_strchr.c		\
					./funcs/my_strdup.c		\
					./funcs/my_realloc.c	\
					./funcs/my_memcpy.c		\
					./funcs/my_strtok.c		\
					./funcs/my_putsterr.c	\
					./funcs/my_strcat.c		\
					./funcs/my_strstr.c		\

CC 		 	=		gcc

RM		 	=		rm -f

OBJS     	=		$(SRCS:.c=.o)

CLEAN_LIB 	= 		rm -f libmy.a

NAME     	=		libmy.a

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
		@printf "\033[34m [Compilation]\033[39m %s\n" $(<:.c=.o)

all:    $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@echo -e "\033[1;32m [Compilation of $(NAME) done !]\033[0m\n"

clean:
		@$(RM) $(OBJS)
		@printf "\033[31m [Delete] \033[39m%s\n" $(OBJS)
		@echo -e "\033[1;32m [Clean of $(NAME) done !]\n\033[0m"

fclean: clean
		@$(RM) $(NAME)

re:     fclean all
