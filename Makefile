LEM_IN=lem-in
LIBFT_NAME=libft/libft.a

# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
LIGHT_GREEN:="\033[1;92m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"

END_IN:=\033[0;0m
BLACK_IN:=\033[1;30m
RED_IN:=\033[1;31m
GREEN_IN:=\033[1;32m
PURPLE_IN:=\033[1;35m
CYAN_IN:=\033[1;36m
WHITE_IN:=\033[1;37m
# ==================

FILES = buffer \
        commands \
        copy_lines \
        debug \
        engine \
        engine_utils \
        errors \
        lem_in \
        moving \
        moving_utils \
        parse \
        parse_utils \
        utils \
        verify \
        verify_utils \

FILES_LEM_IN= $(filter-out checker, $(FILES))
OBJ_LEM_IN=$(addprefix $(OBJ_PATH), $(addsuffix .o, $(FILES_LEM_IN)))

OBJ_PATH=objects/
SRC_PATH=src/
HEAD_PATH= includes/

SRC=$(addprefix src/, $(addsuffix .c, $(FILES_LEM_IN)))


CC:=gcc
C_FLAGS:= -I $(HEAD_PATH)
CACHE=.cache_exists

COUNTER= 1
LENGTH= $(words $(FILES))

all: libft_make $(LEM_IN)

libft_make:
	@cd libft/; make; cp libft.a ..; cd ..;

$(LEM_IN): $(OBJ_LEM_IN) $(LIBFT_NAME)
	gcc $(OBJ_LEM_IN) $(LIBFT_NAME) -o $(LEM_IN)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEAD_PATH) | $(CACHE)
	@printf '$(CYAN_IN)%-20s$(RED_IN)%-50s $(GREEN_IN)%-8s' "- Compile function:" "$<" "$(COUNTER)/$(LENGTH)"
	@echo "\r\c"
	@$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))
	$(CC) $(C_FLAGS) -c $< -o $@

%.c:
	@echo $(RED) "Missing file : $@"

$(CACHE):
	@mkdir $(OBJ_PATH)
	@touch $(CACHE)

clean:
	rm -rf $(OBJ_PATH)
	@rm -f $(CACHE)

fclean: clean
	cd libft/; make fclean; cd ..;
	rm lem-in
	rm libft.a

re: fclean
	$(MAKE) all

norm:
	@echo $(RED)
	@norminette src/ $(HEAD_PATH) | grep -v Norme -B1 || echo $(END)$(LIGHT_GREEN)"Norm - OK!"$(END)
	@echo $(END)

.PHONY: all clean fclean re test norm libft_make