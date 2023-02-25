NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = main \
		do_op \
		ops \
		sort \

SRCS_DIR = src

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))

OBJS_DIR = obj

OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

INCLUDES_DIR = includes

INCLUDES_FILES = push_swap

INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(addsuffix .h, $(INCLUDES_FILES)))

LIBS_DIR = libs

LIBLP_DIR = $(LIBS_DIR)/liblp_c

LIBLP = $(LIBLP_DIR)/liblp.a

$(NAME): $(LIBLP) $(OBJS_DIR) $(OBJS)
	$(CC) $(OBJS) $(LIBLP) -o $(NAME)

$(LIBLP):
	make -C ${LIBLP_DIR}

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean: cleanlib
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: clean all

cleanlib:
	make fclean -C ${LIBLP_DIR}

.PHONY: all clean fclean re makelib cleanlib