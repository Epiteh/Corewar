##
## EPITECH PROJECT, 2023
## B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
## File description:
## Makefile
##

NAME		=	corewar

SRCS		=	./src/main.c								\
				./src/tab.c									\
				./src/error/ceo.c							\
				./src/tab/free.c							\
				./src/tab/len.c								\
				./src/tab/show.c							\
				./src/parser/corewar.c						\
				./src/parser/utils/count.c					\
				./src/parser/utils/split.c					\
				./src/parser/init/structs.c 				\
				./src/parser/programs/get.c					\
				./src/parser/programs/add.c					\
				./src/parser/programs/list.c				\
				./src/parser/programs/subfuncs.c			\
				./src/parser/programs/set/ids.c				\
				./src/parser/programs/set/loads.c			\
				./src/parser/programs/set/memory.c			\
				./src/arena/loop.c							\
				./src/arena/win.c							\
				./src/arena/sort.c							\
				./src/arena/instruction/handle.c			\
				./src/arena/instruction/launch.c			\
				./src/arena/instruction/list/live.c			\
				./src/arena/instruction/list/ld.c			\
				./src/arena/instruction/list/st.c			\
				./src/arena/instruction/list/add.c			\
				./src/arena/instruction/list/sub.c			\
				./src/arena/instruction/list/and.c			\
				./src/arena/instruction/list/or.c			\
				./src/arena/instruction/list/xor.c			\
				./src/arena/instruction/list/zjmp.c			\
				./src/arena/instruction/list/ldi.c			\
				./src/arena/instruction/list/sti.c			\
				./src/arena/instruction/list/fork.c			\
				./src/arena/instruction/list/lld.c			\
				./src/arena/instruction/list/lldi.c			\
				./src/arena/instruction/list/lfork.c		\
				./src/arena/instruction/list/aff.c			\
				./src/arena/utils/pcounter.c				\
				./src/arena/utils/get/arg/ceo.c				\
				./src/arena/utils/get/arg/direct.c			\
				./src/arena/utils/get/arg/type.c			\
				./src/arena/utils/get/inst/len.c			\
				./src/arena/utils/get/inst/value.c			\
				./src/arena/utils/memory/add.c				\
				./src/arena/utils/memory/adress.c			\
				./src/arena/utils/memory/write.c			\
				./src/arena/utils/program/copy.c			\
				./src/arena/utils/register/correct_num.c	\
				./src/arena/utils/register/valid.c			\
				./src/parser/utils/get_correct_addr.c	\
				./src/parser/utils/display_dump_error.c	\

OBJS		=	$(SRCS:.c=.o)

CFLAGS 		= 		-I../include/ -L../lib/my/ -lmy

WFLAGS 		= 		-W -Wall -Wextra -Wshadow

RM			=	rm -f

.c.o:
		@$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)
		@printf "\033[34m [Compilation]\033[39m %s\n" $(<:.c=.o)

all:    $(OBJS)
		@$(CC) -g -o $(NAME) $(OBJS) $(CFLAGS)
		@echo -e "\033[1;32m [Compilation of $(NAME) done !]\033[0m"
clean:
		@$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
