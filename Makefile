NAME = libftprintf.a

AR	= ar crs

CC	= cc
CCFLAGS = -Wall -Wextra -Werror
RM	= rm -rf

SRC	= ft_printf.c \
	  ft_printf_strlen.c \
	  ft_printf_putchar.c \
	  ft_printf_putstr.c \
	  ft_print_int.c \
	  ft_print_int_u.c \
	  ft_print_hex.c \
	  ft_printf_strchr.c \
	  ft_print_ptr.c

OBJ	= $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
