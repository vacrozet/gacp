NAME = gacp
CFLAGS = -Wall -Wextra -Werror
SRC = ./srcs/main.c \
	./srcs/ft_itoa.c \
	./srcs/expand_str.c \
	
OBJ = $(SRC:.c=.o)

.PHONY : clean fclean re

$(NAME) : $(OBJ)
	@gcc $(CFLAGS) -o $(NAME) $^
	@echo "\033[31m|||------- ✔ Creating $(NAME) executable ----------|||\033[0m"
	@echo " \033[31m                       _  __ ____      _ \033[0m"
	@echo " \033[31m                      | |/ _|___ \    | |\033[0m"
	@echo " \033[31m        __      _____ | | |_  __) | __| | \033[0m"
	@echo " \033[31m        \ \ /\ / / _ \| |  _||__ < / _  | \033[0m"
	@echo " \033[31m         \ V  V / (_) | | |  ___) | (_| |\033[0m"
	@echo " \033[31m          \_/\_/ \___/|_|_| |____/ \__,_| \033[0m"	
	@echo " \033[31m        --------------------------------- \033[0m"
	@echo " \033[31m       |18/01/17 |@vacrozet @42| 28/02/17|\033[0m"
	@echo " \033[31m        --------------------------------- \033[0m"
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