##
## EPITECH PROJECT, 2023
## B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
## File description:
## Makefile
##

NAME		=	asm

SRCS		=	./src/main.c										\
				./src/utils/split.c									\
				./src/utils/count.c									\
				./src/utils/len_tab.c								\
				./src/error/ceo.c									\
				./src/parser/ceo.c									\
				./src/parser/format.c								\
				./src/parser/open.c									\
				./src/parser/read.c									\
				./src/parser/output.c								\
				./src/parser/tab.c									\
				./src/parser/line/line.c							\
				./src/parser/line/subfuncs.c						\
				./src/parser/line/header/ceo.c						\
				./src/parser/line/header/utils.c					\
				./src/write/header/write.c							\
				./src/write/instruction/write.c						\
				./src/write/args/write.c							\
				./src/write/args/index.c							\
				./src/write/args/labels.c							\
				./src/write/ceo.c									\
				./src/write/utils/reverse.c							\
				./src/write/utils/big_endian.c						\
				./src/write/utils/get_byte.c						\
				./src/write/utils/valid_byte.c						\
				./src/parser/line/body/instructions/instruction.c	\
				./src/parser/line/body/instructions/args.c			\
				./src/parser/line/body/is_minemonic.c				\
				./src/parser/line/body/error/utils/array.c			\
				./src/parser/line/body/error/utils/args_validity.c	\
				./src/parser/line/body/error/line_validity.c		\
				./src/parser/line/body/error/label.c				\
				./src/parser/line/body/error/type/get.c				\
				./src/parser/line/body/error/type/check.c			\
				./src/parser/line/body/error/labels_list/add.c		\
				./src/parser/line/body/error/labels_list/init.c		\
				./src/parser/line/body/error/labels_list/remove.c	\
				./src/parser/line/body/error/labels_list/browse.c	\
				./src/parser/line/body/error/labels_list/check.c	\
				./src/parser/line/body/error/separator.c			\

SRCTEST	=		./src/utils/split.c									\
				./src/utils/count.c									\
				./src/error/ceo.c									\
				./src/parser/ceo.c									\
				./src/parser/format.c								\
				./src/parser/open.c									\
				./src/parser/read.c									\
				./src/parser/output.c								\
				./src/parser/tab.c									\
				./src/parser/line/line.c							\
				./src/parser/line/subfuncs.c						\
				./src/parser/line/header/ceo.c						\
				./src/parser/line/header/utils.c					\
				./src/write/header/write.c							\
				./src/write/instruction/write.c						\
				./src/write/args/write.c							\
				./src/write/ceo.c									\
				./src/write/utils/reverse.c							\
				./src/write/utils/big_endian.c						\
				./src/write/utils/get_byte.c						\
				./src/write/utils/valid_byte.c						\
				./src/parser/line/body/instructions/instruction.c	\
				./src/parser/line/body/instructions/args.c			\
				./src/parser/line/body/is_minemonic.c				\
				./src/parser/line/body/error/utils/array.c			\
				./src/parser/line/body/error/utils/args_validity.c	\
				./src/parser/line/body/error/line_validity.c		\
				./src/parser/line/body/error/label.c				\
				./src/parser/line/body/error/type/get.c				\
				./src/parser/line/body/error/type/check.c			\
				./src/parser/line/body/error/labels_list/add.c		\
				./src/parser/line/body/error/labels_list/init.c		\
				./src/parser/line/body/error/labels_list/remove.c	\
				./src/parser/line/body/error/labels_list/browse.c	\
				./src/parser/line/body/error/labels_list/check.c	\
				./src/parser/line/body/error/separator.c		\

TEST = 	../tests/asm_tests/is_minemoric.c	\
		../tests/asm_tests/is_label.c	\
		../tests/asm_tests/my_str_isnum.c	\
		../tests/asm_tests/is_register.c	\
		../tests/asm_tests/is_direct.c	\
		../tests/asm_tests/is_indirect.c	\
		../tests/asm_tests/get_instruction.c	\
		../tests/asm_tests/find_quotes.c	\
		../tests/asm_tests/count_element.c	\

CC			=	gcc -g

OBJS		=	$(SRCS:.c=.o)

OBJTEST		=	$(SRCTEST:.c=.o)

CFLAGS 		= 	-I../include/ -L../lib/my/ -lmy

WFLAGS 		= 	-W -Wall -Wextra -Wshadow

RM			=	rm -f

NAMETEST	= 	unit_tests

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(WFLAGS)
		@printf "\033[34m [Compilation]\033[39m %s\n" $(<:.c=.o)

all:    $(OBJS)
		@$(CC) -g -o $(NAME) $(OBJS) $(CFLAGS)
		@echo -e "\033[1;32m [Compilation of $(NAME) done !]\033[0m"
clean:
		@$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

tests_run:
	@$(CC) $(OBJTEST) $(CFLAGS) $(TEST) -o $(NAMETEST) --coverage -lcriterion

re:		fclean all
