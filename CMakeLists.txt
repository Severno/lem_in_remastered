cmake_minimum_required(VERSION 3.15)
project(lem_in_remastered C)

set(CMAKE_C_STANDARD 99)

add_executable(lem_in_remastered
        libft/src/ft_str/ft_check_end_spaces.c
        libft/src/ft_str/ft_check_start_spaces.c
        libft/src/ft_str/ft_convert_dec_base_to_str.c
        libft/src/ft_str/ft_convert_undec_base_to_str.c
        libft/src/ft_str/ft_find_and_remove_char.c
        libft/src/ft_str/ft_isalnum.c
        libft/src/ft_str/ft_isalpha.c
        libft/src/ft_str/ft_isascii.c
        libft/src/ft_str/ft_isdigit.c
        libft/src/ft_str/ft_isprint.c
        libft/src/ft_str/ft_isspace.c
        libft/src/ft_str/ft_itoa.c
        libft/src/ft_str/ft_str_is_lowercase.c
        libft/src/ft_str/ft_str_is_numeric_no_spaces.c
        libft/src/ft_str/ft_str_is_numeric_with_spaces.c
        libft/src/ft_str/ft_str_is_printable.c
        libft/src/ft_str/ft_str_is_uppercase.c
        libft/src/ft_str/ft_strcat.c
        libft/src/ft_str/ft_strchr.c
        libft/src/ft_str/ft_strclr.c
        libft/src/ft_str/ft_strcmp.c
        libft/src/ft_str/ft_strcpy.c
        libft/src/ft_str/ft_strdel.c
        libft/src/ft_str/ft_strdup.c
        libft/src/ft_str/ft_strequ.c
        libft/src/ft_str/ft_striter.c
        libft/src/ft_str/ft_striteri.c
        libft/src/ft_str/ft_strjoin.c
        libft/src/ft_str/ft_strlcat.c
        libft/src/ft_str/ft_strlen.c
        libft/src/ft_str/ft_strmap.c
        libft/src/ft_str/ft_strmapi.c
        libft/src/ft_str/ft_strncat.c
        libft/src/ft_str/ft_strncmp.c
        libft/src/ft_str/ft_strncpy.c
        libft/src/ft_str/ft_strnequ.c
        libft/src/ft_str/ft_strnew.c
        libft/src/ft_str/ft_strnlen.c
        libft/src/ft_str/ft_strnstr.c
        libft/src/ft_str/ft_strrchr.c
        libft/src/ft_str/ft_strsplit.c
        libft/src/ft_str/ft_strstr.c
        libft/src/ft_str/ft_strsub.c
        libft/src/ft_str/ft_strtrim.c
        libft/src/ft_str/ft_tolower.c
        libft/src/ft_str/ft_toupper.c
        src/copy_lines.c
        src/free_data.c
        src/free_data2.c
        src/hashmap.c
        src/init_structs.c
        src/lem_in.c
        src/parse.c
        src/queue.c
        src/validation.c
        src/printing.c
        src/bfs.c
        src/get_real_links_connections.c
        src/form_path.c
        src/launch_ants.c
        libft/src/get_next_line.c
        src/delete_dead_links.c
        src/delete_input_links.c
        src/delete_output_links.c
        src/delete_input_links.c src/delete_dead_links.c src/delete_output_links.c src/check_path.c src/get_links_position.c src/create_in_out_links.c)

target_link_libraries(lem_in_remastered ${CMAKE_SOURCE_DIR}/libft/libft.a)