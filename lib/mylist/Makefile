##
## EPITECH PROJECT, 2023
## Libmylist
## File description:
## The Makefile of the libmylist
##

NAME    	=	libmylist.a

CC		=	gcc

BUILDDIR 	=	../../build

SRCS		=	my_concat_list.c
SRCS		+=	my_delete_circled_list.c
SRCS		+=	my_delete_list.c
SRCS		+=	my_delete_nodes.c
SRCS		+=	my_find_node.c
SRCS		+=	my_list_size.c
SRCS		+=	my_list_size_circled.c
SRCS		+=	my_list_to_array.c
SRCS		+=	my_list_to_array_circled.c
SRCS		+=	my_merge_list.c
SRCS		+=	my_params_to_list.c
SRCS		+=	my_pop_back.c
SRCS		+=	my_pop_front.c
SRCS		+=	my_pop_node.c
SRCS		+=	my_previous_to_next.c
SRCS		+=	my_push_back.c
SRCS		+=	my_push_back_circled.c
SRCS		+=	my_push_front.c
SRCS		+=	my_rev_list.c
SRCS		+=	my_show_list.c
SRCS		+=	my_sort_list.c

OBJS		=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

HEADER		=	mylist.h

CFLAGS		=	-Werror -Wextra -Wpedantic -g3 -L./ -lmy -I../../include
DEBUGFLAGS	=	-g3
OPTIMIZEFLAGS	=	-O3

.PHONY: all my debug clean fclean re copy

all:	my $(BUILDDIR) $(NAME) copy
	@echo -e "\033[1;33mLibmylist compiled.\033[0m"

my:
	@cp ../my/libmy.a libmy.a
	@cp ../my/my.h my.h

debug: CFLAGS += $(DEBUGFLAGS)
debug: OPTIMIZEFLAGS =
debug: all

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(BUILDDIR)
	@$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)
	@echo -e "\033[1;31mLibmylist .o deleted.\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@echo -e "\033[1;31mLibmylist cleaned.\033[0m"

re: 	fclean all

copy:
	@cp $(NAME) ../$(NAME)
	@cp $(HEADER) ../../include/$(HEADER)
