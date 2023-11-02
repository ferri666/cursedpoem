NAME 		= cursed
LIBFT_DIR 	= libft
LIBFT 		= libft.a
INCLUDE 	= include
SRC_DIR		= src/
OBJ_DIR		= obj/
SRC_FILES	= main loadWords zalgo

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I$(INCLUDE)
AR				= ar rcs

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all:				$(LIBFT) $(NAME) 

$(NAME)			:	$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) -o $@ $^
					@echo "Program Created"

$(OBJ_DIR)%.o	: 	$(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -o $@ -c $^

$(LIBFT):				
					@make -C $(LIBFT_DIR)
					@cp $(LIBFT_DIR)/$(LIBFT) .

clean:				
					@$(RM) $(OBJ)
					@rm -rf $(OBJ_DIR)
					@make -C $(LIBFT_DIR) clean
					@echo "Clean boys Indeed!"

fclean:				clean
					@make -C $(LIBFT_DIR) fclean
					@$(RM) $(LIBFT)
					@$(RM) $(NAME)
					@echo "Super clean boys Forever!"

re:					fclean $(NAME)

norm:			
					@norminette $(SRC) $(INCLUDE) $(LIBFT_DIR) | grep -v Norme -B1 || true


.PHONY:				all clean libft_make fclean re norm