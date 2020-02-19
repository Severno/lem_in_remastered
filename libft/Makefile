NAME:=libft.a

LIBFT_ARRAY_PATH=ft_array/
LIBFT_ARRAY_SRC= ft_print_int_arr ft_print_str_arr ft_print_pstr_arr \
				ft_get_number_of_substrings ft_print_ll_arr \
				ft_print_sizet_arr

LIBFT_LST_PATH:=	ft_lst/
LIBFT_LST_SRC:= ft_lstadd \
				ft_lstdel \
				ft_lstdelone \
				ft_lstiter \
				ft_lstmap \
				ft_lstnew

LIBFT_MATH_PATH:=	ft_math/
LIBFT_MATH_SRC= ft_abs \
				ft_max_of_three \
				ft_max_of_two \
				ft_middle_of_three \
				ft_min_of_two \
				ft_log2n

LIBFT_MEM_PATH:=	ft_mem/
LIBFT_MEM_SRC:=	ft_bzero \
				ft_memalloc \
				ft_memccpy \
				ft_memchr \
				ft_memcmp \
				ft_memcpy \
				ft_memdel \
				ft_memmove \
				ft_memset

LIBFT_NUM_PATH:=	ft_num/
LIBFT_NUM_SRC:= ft_atoi \
				ft_atol \
				ft_atoul \
				ft_num_of_digits \
				ft_num_of_fields \
				ft_unnum_of_fields \
				ft_copy_int_arr \

PRINTF_PATH:=	ft_printf/
PRINTF_SRC:=		alignment calc_signed_precision calc_signed_width \
			calc_unsigned_precision calc_unsigned_width flag_cs flag_di \
			flag_o precision flag_u flag_x ft_printf pf_strchr get_flags \
			print_d print_o check_conventions utils print_u print_x print_p flag_p \
			flag_percent print_percent print_f flag_f calc_float_width \
			pf_strchr_flags pf_strcat flag_f_handle removes_flags \
			handle_float_zeros pf_putnbr_base pf_putstr pf_putunbr parse_flags \
			ft_ftoa handle_float_conditions

LIBFT_PUT_PATH:=	ft_put/
LIBFT_PUT_SRC:= ft_putchar \
				ft_putchar_fd \
				ft_putendl \
				ft_putendl_fd \
				ft_putnbr \
				ft_putnbr_base \
				ft_putnbr_fd \
				ft_putstr \
				ft_putstr_fd \
				ft_putunbr

LIBFT_STR_PATH:=	ft_str/
LIBFT_STR_SRC:= ft_check_end_spaces \
				ft_check_start_spaces \
				ft_convert_dec_base_to_str \
				ft_convert_undec_base_to_str \
				ft_find_and_remove_char \
				ft_isalnum \
				ft_isalpha \
				ft_isascii \
				ft_isdigit \
				ft_isprint \
				ft_isspace \
				ft_itoa \
				ft_str_is_lowercase \
				ft_str_is_numeric_with_spaces \
				ft_str_is_printable \
				ft_str_is_uppercase \
				ft_strcat \
				ft_strchr \
				ft_strclr \
				ft_strcmp \
				ft_strcpy \
				ft_strdel \
				ft_strdup \
				ft_strequ \
				ft_striter \
				ft_striteri \
				ft_strjoin \
				ft_strlcat \
				ft_strlen \
				ft_strmap \
				ft_strmapi \
				ft_strncat \
				ft_strncmp \
				ft_strncpy \
				ft_strnequ \
				ft_strnew \
				ft_strnlen \
				ft_strnstr \
				ft_strrchr \
				ft_strsplit \
				ft_strstr \
				ft_strsub \
				ft_strtrim \
				ft_tolower \
				ft_toupper \
				ft_str_is_numeric_no_spaces

FT_SORTING_PATH:=	ft_sorting/
FT_SORTING_SRC:=	ft_merge_sort ft_merge_sort_sizet ft_bubble_sort ft_quick_sort

FT_SEARCHING_PATH:=	ft_searching/
FT_SEARCHING_SRC:=	ft_quick_select

FILES:= get_next_line

# ==================

# ==== Standard ====
COMPILE_PATH:=objects/
SRC_PATH:=src/
HEAD_PATH:=includes/
CC:=gcc
C_FLAGS:=-Wall -Wextra -Werror -I $(HEAD_PATH)
# ==================

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

# ====== Auto ======
FILES+=$(addprefix $(LIBFT_LST_PATH),$(LIBFT_LST_SRC))
FILES+=$(addprefix $(LIBFT_MATH_PATH),$(LIBFT_MATH_SRC))
FILES+=$(addprefix $(LIBFT_MEM_PATH),$(LIBFT_MEM_SRC))
FILES+=$(addprefix $(LIBFT_NUM_PATH),$(LIBFT_NUM_SRC))
FILES+=$(addprefix $(PRINTF_PATH),$(PRINTF_SRC))
FILES+=$(addprefix $(LIBFT_PUT_PATH),$(LIBFT_PUT_SRC))
FILES+=$(addprefix $(LIBFT_STR_PATH),$(LIBFT_STR_SRC))
FILES+=$(addprefix $(FT_SORTING_PATH),$(FT_SORTING_SRC))
FILES+=$(addprefix $(LIBFT_ARRAY_PATH),$(LIBFT_ARRAY_SRC))
FILES+=$(addprefix $(FT_SEARCHING_PATH),$(FT_SEARCHING_SRC))

SRC:=$(addprefix $( SRC_PATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(COMPILE_PATH),$(addsuffix .o,$(FILES)))
# ==================
CACHE:=.cache_exists

COUNTER= 1
LENGTH= $(words $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(END)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN) " - Done" $(END)

$(COMPILE_PATH)%.o: $(SRC_PATH)%.c $(HEAD_PATH) | $(CACHE)
	@printf '$(CYAN_IN)%-20s$(RED_IN)%-50s $(GREEN_IN)%-8s' "- Compile function:" "$<" "$(COUNTER)/$(LENGTH)"
	@echo "\r\c"
	@$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))
	@$(CC) $(C_FLAGS) -c $< -o $@

%.c:
	@echo $(RED) "Missing file : $@"

$(CACHE):
	@mkdir $(COMPILE_PATH)
	@mkdir $(COMPILE_PATH)$(LIBFT_LST_PATH)
	@mkdir $(COMPILE_PATH)$(LIBFT_MATH_PATH)
	@mkdir $(COMPILE_PATH)$(LIBFT_MEM_PATH)
	@mkdir $(COMPILE_PATH)$(LIBFT_NUM_PATH)
	@mkdir $(COMPILE_PATH)$(PRINTF_PATH)
	@mkdir $(COMPILE_PATH)$(LIBFT_PUT_PATH)
	@mkdir $(COMPILE_PATH)$(LIBFT_STR_PATH)
	@mkdir $(COMPILE_PATH)$(FT_SORTING_PATH)
	@mkdir $(COMPILE_PATH)$(LIBFT_ARRAY_PATH)
	@mkdir $(COMPILE_PATH)$(FT_SEARCHING_PATH)
	@touch $(CACHE)

clean:
	@rm -Rf $(COMPILE_PATH)
	@rm -f $(CACHE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@echo $(RED)
	@norminette src/ $(HEAD_PATH) | grep -v Norme -B1 || echo $(END)$(LIGHT_GREEN)"Norm - OK!"$(END)
	@echo $(END)

.PHONY: all clean fclean re test norme