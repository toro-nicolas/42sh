##
## EPITECH PROJECT, 2023
## Libmymemory
## File description:
## The Makefile of the libmymemory
##

NAME    	=	libmymemory.a

CC		=	gcc

BUILDDIR 	=	../../build

SRCS		=	my_calloc.c
SRCS		+=	my_free.c
SRCS		+=	my_malloc.c
SRCS		+=	my_malloc_strdup.c
SRCS		+=	my_malloc_strdup_word_array.c
SRCS		+=	my_malloc_strndup.c
SRCS		+=	my_memchr.c
SRCS		+=	my_memcpy.c
SRCS		+=	my_memcmp.c
SRCS		+=	my_memmove.c
SRCS		+=	my_memset.c
SRCS		+=	my_realloc.c

OBJS		=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

HEADER		=	mymemory.h

CFLAGS		=	-Werror -Wextra -Wpedantic -g3
CFLAGS		+=	-L./ -lmylist -lmy -I../../include
DEBUGFLAGS	=	-g3
OPTIMIZEFLAGS	=	-O3

.PHONY: all my debug clean fclean re copy

all:	my $(BUILDDIR) $(NAME) copy
	@echo -e "\033[1;33mLibmymemory compiled.\033[0m"

my:
	@cp ../my/libmy.a libmy.a
	@cp ../my/my.h my.h
	@cp ../mylist/libmylist.a libmylist.a
	@cp ../mylist/mylist.h mylist.h

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(BUILDDIR)
	@$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUGFLAGS)
debug: OPTIMIZEFLAGS =
debug: all

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)
	@echo -e "\033[1;31mLibmymemory .o deleted.\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@echo -e "\033[1;31mLibmymemory cleaned.\033[0m"

re: 	fclean all

copy:
	@cp $(NAME) ../$(NAME)
	@cp $(HEADER) ../../include/$(HEADER)
