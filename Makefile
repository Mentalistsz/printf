NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		ft_format.c \
		ft_handler.c \
		ft_type_id.c \
		ft_type_p.c \
		ft_substr.c \
		ft_strlen.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_itoa.c \
		ft_type_x.c \

OBJS = $(SRCS:.c=.o)

HEADERS =	ft_printf.h 

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@
clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
