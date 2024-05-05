##
## EPITECH PROJECT, 2023
## 42sh
## File description:
## The main Makefile of our project
##

NAME		=	42sh

CC		=	gcc
DEBUG_MODE	=

BUILDDIR 	=	./build
SRCDIR		=	./src

SRCS		=	../src/main.c
SRCS		+=	../src/builtins/about.c
SRCS		+=	../src/builtins/alias.c
SRCS		+=	../src/builtins/cd.c
SRCS		+=	../src/builtins/echo.c
SRCS		+=	../src/builtins/else.c
SRCS		+=	../src/builtins/endif.c
SRCS		+=	../src/builtins/env.c
SRCS		+=	../src/builtins/exec.c
SRCS		+=	../src/builtins/exit.c
SRCS		+=	../src/builtins/foreach.c
SRCS		+=	../src/builtins/help.c
SRCS		+=	../src/builtins/history.c
SRCS		+=	../src/builtins/if.c
SRCS		+=	../src/builtins/repeat.c
SRCS		+=	../src/builtins/set.c
SRCS		+=	../src/builtins/setenv.c
SRCS		+=	../src/builtins/source.c
SRCS		+=	../src/builtins/unalias.c
SRCS		+=	../src/builtins/unset.c
SRCS		+=	../src/builtins/unsetenv.c
SRCS		+=	../src/builtins/where.c
SRCS		+=	../src/builtins/which.c
SRCS		+=	../src/globbing/globbing.c
SRCS		+=	../src/history/history_file.c
SRCS		+=	../src/history/event.c
SRCS		+=	../src/inhibitors/array_separators.c
SRCS		+=	../src/inhibitors/array_string.c
SRCS		+=	../src/inhibitors/inhibitors.c
SRCS		+=	../src/line-editing/ansi.c
SRCS		+=	../src/line-editing/my_getline.c
SRCS		+=	../src/line-editing/termios.c
SRCS		+=	../src/parsing/condition.c
SRCS		+=	../src/parsing/input_command.c
SRCS		+=	../src/parsing/parsing.c
SRCS		+=	../src/parsing/replace_alias.c
SRCS		+=	../src/parsing/replace_variable.c
SRCS		+=	../src/parsing/tilde.c
SRCS		+=	../src/prompt/prompt.c
SRCS		+=	../src/prompt/git_repository.c
SRCS		+=	../src/prompt/title.c
SRCS		+=	../src/separators/backticks.c
SRCS		+=	../src/separators/left_redirections.c
SRCS		+=	../src/separators/multiple_commands.c
SRCS		+=	../src/separators/operators.c
SRCS		+=	../src/separators/parantheses.c
SRCS		+=	../src/separators/pipes.c
SRCS		+=	../src/separators/redirections.c
SRCS		+=	../src/separators/right_redirections.c
SRCS		+=	../src/command.c
SRCS		+=	../src/config_file.c
SRCS		+=	../src/environnement.c
SRCS		+=	../src/scripting.c
SRCS		+=	../src/shell.c
SRCS		+=	../src/signals.c

OBJS     	=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

CFLAGS		=	-Werror -Wextra -I./include/
DEBUGFLAGS	=	-g3
OPTIMIZEFLAGS	=	-O3
VALGRINDFLAGS	=	--leak-check=full --show-leak-kinds=all --track-origins=yes
OUTPUT		=	valgrind.log

LDFLAGS 	=	-L./lib/ -lmymemory -lmylist -lmy

.PHONY: all libs create-build debug clean fclean re re_debug \
	tests unit_tests tests_run doc

all: create-build libs $(BUILDDIR) $(NAME)
	@echo -e "\033[1;33m42sh compiled.\033[0m"

libs:
	@make --no-print-directory -C ./lib/my/ $(DEBUG_MODE)
	@make --no-print-directory -C ./lib/mylist/ $(DEBUG_MODE)
	@make --no-print-directory -C ./lib/mymemory/ $(DEBUG_MODE)
	@echo -e "\033[1;33mLibs made.\033[0m"

create-build:
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/builtins/%.c
	$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/globbing/%.c
	$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/history/%.c
	$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/inhibitors/%.c
	$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/line-editing/%.c
	$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/parsing/%.c
	$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/prompt/%.c
	$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/separators/%.c
	$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -c $< -o $@


debug: CFLAGS += $(DEBUGFLAGS)
debug: OPTIMIZEFLAGS =
debug: DEBUG_MODE = debug
debug: all

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	@rm -rf $(BUILDDIR)
	@echo -e "\033[1;31mAll .o deleted.\033[0m"

fclean: clean
	@find -type f -name "*.a" -exec rm -f {} \;
	@rm -rf unit_tests*
	@rm -rf tests/unit_tests*
	@rm -rf vgcore*
	@rm -rf *.log
	@rm -rf $(NAME)
	@echo -e "\033[1;31mProject cleaned.\033[0m"

re:	fclean all

re_debug: fclean debug

valgrind: fclean debug
	@echo -e "\033[0;36mExecuting valgrind...\033[0m"
	@valgrind $(VALGRINDFLAGS) ./$(NAME) 2> $(OUTPUT)

tests: re
	@./tester.sh

# Unit tests Makefile
unit_tests:
	@make unit_tests --no-print-directory -C./tests/

tests_run:
	@make tests_run --no-print-directory -C./tests/
	@gcovr \
    --exclude lib/my/my_printf/round_flag_a.c \
    --exclude lib/mylist/my_list_to_array.c \
    --exclude lib/mylist/my_show_list.c

# Documentation
doc: tests_run
	@doxygen Doxyfile
	@gcovr \
    --exclude lib/my/my_printf/round_flag_a.c \
    --exclude lib/mylist/my_list_to_array.c \
    --exclude lib/mylist/my_show_list.c \
	--branch --html-details docs/tests/test.html
	@echo -e "\033[1;33mDocumentation generated.\033[0m"
	@google-chrome docs/html/index.html
	@google-chrome docs/tests/test.html
