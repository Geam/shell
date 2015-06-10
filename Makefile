NAME    = sh1

CC      = /usr/bin/gcc
MAKE	= /usr/bin/make
MKDIR   = /bin/mkdir
RM      = /bin/rm

PATH_LIBFT  = libft
PATH_INCL   = includes
PATH_SRCS   = srcs
PATH_OBJ    = obj

CFLAGS  = -Wall -Wextra -Werror -I $(PATH_LIBFT)/$(PATH_INCL) -I $(PATH_INCL)
LDFLAGS = -L libft -lft

LIBFT	= $(PATH_LIBFT)/libft.a

SRCS    = sh.c
OBJ     = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRCS))

.PHONY: all clean fclean re libft dump_var

all: $(LIBFT) $(PATH_OBJ) $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

$(PATH_OBJ)/%.o: $(PATH_SRCS)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(PATH_OBJ):
	$(MKDIR) $@

$(LIBFT):
	$(MAKE) -C $(PATH_LIBFT)

libft:
	$(MAKE) -C $(PATH_LIBFT)

clean:
	$(RM) -rf $(PATH_OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

dump_var:
	echo $(OBJ)
