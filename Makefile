NAME = gacp
CFLAGS = -Wall -Wextra -Werror
SRC = ./srcs/main.c \
	./srcs/ft_itoa.c \
	./srcs/expand_str.c \
	./srcs/ft_strjoin_commit.c \
	./srcs/print.c \
	./srcs/utils.c \
	./srcs/ft_strjoin.c \

OBJ = $(SRC:.c=.o)

.PHONY : clean fclean re

$(NAME) : $(OBJ)
	@gcc $(CFLAGS) -o $(NAME) $^
	@echo "\033[31m|||------- ✔ Creating $(NAME) executable ----------|||\033[0m"
	@echo "\n"
	@echo "\033[31m            _____          _____ _____  \033[0m"
	@echo "\033[31m           / ____|   /\   / ____|  __ \ \033[0m"
	@echo "\033[31m          | |  __   /  \ | |    | |__) |\033[0m"
	@echo "\033[31m          | | |_ | / /\ \| |    |  ___/ \033[0m"
	@echo "\033[31m          | |__| |/ ____ \ |____| |     \033[0m"
	@echo "\033[31m           \_____/_/    \_\_____|_|     \033[0m"
	@echo " \033[31m       --------------------------------- \033[0m"
	@echo " \033[31m      | Perso |@vacrozet @42| 18/06/2017|\033[0m"
	@echo " \033[31m       --------------------------------- \033[0m"
	@echo "\n"

%.o: %.c
	@clang $^ $(CFLAGS) -c -o $@

clean :
	@echo "\033[31m|||------- ❌ Removing Object Files $(NAME) --------|||\033[0m"
	@rm -f $(OBJ)

fclean : clean
	@echo "\033[31m|||------- ❌ Removing $(NAME) ---------------------|||\033[0m"	
	@rm -f $(NAME)

re : fclean $(NAME)

run : norm $(NAME)

norm :
	@norminette srcs/* includes/* | grep -B 1 "Error" || true