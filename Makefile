NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

FILES = main \
		do_op \
		ops \
		sort \

INCLUDES_FOLDER = includes

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

LIB_FOLDER = liblp_c
LIB_NAME = liblp.a

$(NAME): makelib
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDES_FOLDER)/$(LIB_FOLDER)/$(LIB_NAME) -o $(NAME)

all: $(NAME)

clean: cleanlib
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

makelib:
	make -C $(INCLUDES_FOLDER)/${LIB_FOLDER}

cleanlib:
	make fclean -C $(INCLUDES_FOLDER)/${LIB_FOLDER}

.PHONY: all clean fclean re makelib cleanlib