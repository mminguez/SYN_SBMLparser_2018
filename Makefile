##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_DIR	=	$(realpath ./src)

TEST_SRC	=	$(realpath ./tests)

SRC	=	$(SRC_DIR)/sbml.c		\
		$(SRC_DIR)/parser.c		\
		$(SRC_DIR)/file.c		\
		requirement.c

TESTS	=	$(TEST_SRC)/test1.c	\

NAME	=	SBMLparser

INCLUDE	=	-I./include

LFLAGS =

OBJ	=	$(SRC:.c=.o)

DEFAULT	=	\033[0m
GREEN	=	\033[0;32m
RED	=	\033[1;31m

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(MAIN_SRC) $(OBJ) $(INCLUDE) $(LFLAGS) && \
	echo "[ $(GREEN)$(NAME) created !$(DEFAULT) ]" || \
	echo "[ $(RED)Error compiling $(NAME)$(DEFAULT) ]"

clean:
	@rm -f *.gc*
	@find . -name "*.o" -type f -delete

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

bonus:	$(OBJ)
	gcc -o $(NAME) $(MAIN_SRC) $(SRC) $(INCLUDE) -DBONUS

debug:	$(OBJ)
	gcc -o $(NAME) $(MAIN_SRC) $(SRC) $(INCLUDE) $(LFLAGS) -g3

tests_run:	re
	gcc -c $(SRC) $(INCLUDE) -DUNIT_TESTS --coverage
	gcc -c $(TESTS) $(INCLUDE)
	gcc -o unit_tests *.o -lcriterion -lgcov
	./unit_tests --always-succeed
	gcovr

%.o:	%.c
	@$(CC) -o $@ -c $< -W $(INCLUDE) && \
	echo "[ $(GREEN)$< Compiled !$(DEFAULT) ]" || \
	echo "[ $(RED)Fail compilation $<$(DEFAULT) ]"

.PHONY:	all clean fclean re tests_run bonus debug