##
## EPITECH PROJECT, 2023
## read_html_file
## File description:
## Makefile
##

PARTS		= 		./asm ./corewar

MAKE_LIB 	=  		make -C ./lib/my

MAKE_CLEAN 	= 		make clean -C ./lib/my

MAKE_FCLEAN = 		make fclean -C ./lib/my

CP 			= 		cp ./lib/my/include/my.h ./include/

RM 			= 		rm -f

all:    $(MAKE)

$(MAKE):
		@$(CP)
		@$(MAKE_LIB)
		@for part_dir in $(PARTS); do 		\
			make -C $$part_dir; 			\
			echo -e "\033[1;32m[Compilation of $$part_dir done !]\033[0m"; \
		done

clean:
		@$(MAKE_CLEAN)
		@for part_dir in $(PARTS); do 			\
			make -C $$part_dir clean; 			\
			echo -e "\033[1;32m[Compilation of $$part_dir done !]\033[0m"; \
		done

fclean: clean
		@$(MAKE_FCLEAN)
		@for part_dir in $(PARTS); do 			\
			make -C $$part_dir fclean; 			\
			echo -e "\033[1;32m[Compilation of $$part_dir done !]\033[0m"; \
		done

re: fclean all

man-epiteh:
		@echo -e "\033[1;34mBonne lecture !\n\033[0m"
		@cat man-epiteh.420

run-tests: all
		@cp $(NAME) ./tests/
		@clear
		@echo -e "\033[1;36m[Run tests]\033[0m"
		@cd tests && ftest
		@echo -e "\033[1;36m[End of tests]\033[0m"
		@rm -f ./tests/$(NAME)

coding-style: fclean
		@clear
		@echo -e "\033[1;36m[Run coding style]\033[0m"
		@coding-style . . && cat coding-style-reports.log
		@echo -e "\033[1;36m[End of coding style]\033[0m"
		@rm -f coding-style-reports.log

backup: fclean
		@mkdir -p backup
		@mkdir -p backup/$(NAME)
		@tar zcvf backup/$(NAME)/archive_`date +"%Y-%m-%d-%H-%M-%S"`.tgz . \
			> /dev/null

tests_run: $(MAKE)
	@make tests_run -C ./asm
