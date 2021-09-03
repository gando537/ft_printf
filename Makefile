LIBFT = ./srcs/libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  srcs/ft_printf.c \
		srcs/sources/ft_check_format.c \
		srcs/sources/ft_u_itoa.c \
		srcs/sources/ft_ull_base.c \
		srcs/sources/ft_putchar.c \
		srcs/sources/ft_str_tolower.c \
		srcs/sources/ft_putstrprec.c \
		srcs/sources/ft_print_str.c \
		srcs/sources/ft_print_char.c \
		srcs/sources/ft_print_pointer.c \
		srcs/sources/ft_print_width.c \
		srcs/sources/ft_print_int.c \
		srcs/sources/ft_print_uint.c \
		srcs/sources/ft_percent.c \
		srcs/sources/ft_print_hexa.c \
		srcs/sources/ft_check_flags.c 
		
SURPL_O = 	ft_check_format.o \
			ft_u_itoa.o \
			ft_ull_base.o \
			ft_putchar.o \
			ft_str_tolower.o \
			ft_putstrprec.o \
			ft_print_str.o \
			ft_print_char.o \
			ft_print_pointer.o \
			ft_print_width.o \
			ft_print_int.o \
			ft_print_uint.o \
			ft_percent.o \
			ft_print_hexa.o \
			ft_check_flags.o  

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./srcs/libft
	cp srcs/libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./srcs/libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./srcs/libft
	rm -rf $(NAME)

re : fclean all
