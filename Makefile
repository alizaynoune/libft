NAME = libprintf.a
N_PRINTF = printf.a
N_LIB = libft.a
N_NEXT_LINE = next_line.a
GCC = gcc -Wall -Werror -Wextra -c
OBJS = objs/

#
#src dire
#

D_L_CONV = ./libft/convert/
D_L_COUNT = ./libft/count/
D_L_EDIT = ./libft/edit/
D_L_IS = ./libft/is/
D_L_LST = ./libft/lst/
D_L_MEM = ./libft/mem/
D_L_PUT = ./libft/put/
D_L_STR = ./libft/str/
D_PRINT = ./printf/
D_N_LINE = gnl/
D_INC = ./includes/

#
#src file
#

L_CONV = ft_atoi_all.c		\
       ft_atoi.c		\
       ft_itoa.c		\
       ft_tolower.c		\
       ft_toupper.c

L_COUNT = count_words.c		\
	ft_count_char.c

L_EDIT = ft_bzero.c		\
       remove_last_space.c

L_IS = ft_all_digit.c		\
     ft_isalnum.c		\
     ft_isalpha.c		\
     ft_isascii.c		\
     ft_isdigit.c		\
     ft_isprint.c

L_LST = ft_lstadd.c		\
      ft_lstdel.c		\
      ft_lstdelone.c		\
      ft_lstiter.c		\
      ft_lstmap.c		\
      ft_lstnew.c

L_MEM = ft_memalloc.c		\
      ft_memccpy.c		\
      ft_memchr.c		\
      ft_memcmp.c		\
      ft_memcpy.c		\
      ft_memdel.c		\
      ft_memmove.c		\
      ft_memset.c

L_PUT = ft_putchar.c		\
      ft_putchar_fd.c		\
      ft_putendl.c		\
      ft_putendl_fd.c		\
      ft_putnbr.c		\
      ft_putnbr_fd.c		\
      ft_putstr.c		\
      ft_putstr_fd.c

L_STR = ft_strcat.c		\
      ft_strchr.c		\
      ft_strclr.c		\
      ft_strcmp.c		\
      ft_strcpy.c		\
      ft_strdel.c		\
      ft_strdup.c		\
      ft_strequ.c		\
      ft_striter.c		\
      ft_striteri.c		\
      ft_strjoin.c		\
      ft_strlcat.c		\
      ft_strlen.c		\
      ft_strmap.c		\
      ft_strmapi.c		\
      ft_strncat.c		\
      ft_strncmp.c		\
      ft_strncpy.c		\
      ft_strndup.c		\
      ft_strnequ.c		\
      ft_strnew.c		\
      ft_strnstr.c		\
      ft_strrchr.c		\
      ft_strsplit.c		\
      ft_strstr.c		\
      ft_strsub.c		\
      ft_strtrim.c

PRINTF = check2.c		\
	check.c			\
	convert2.c		\
	convert3.c		\
	convert4.c		\
	convert.c		\
	float2.c		\
	float.c			\
	ft_precision2.c		\
	ft_precision.c		\
	ft_printf.c		\
	ft_printf2.c		\
	ft_printf3.c		\
	printall.c		\
	printall2.c

N_LINE = get_next_line.c

LIB_INC = ./includes/libft.h
PRINT_INC = ./includes/ft_printf.h
LINE_INC = ./includes/get_next_line.h

LIB_OBJ := $(addprefix $(OBJS), $(L_CONV:.c=.o))	\
	$(addprefix $(OBJS), $(L_COUNT:.c=.o))		\
	$(addprefix $(OBJS), $(L_EDIT:.c=.o))		\
	$(addprefix $(OBJS), $(L_IS:.c=.o))		\
	$(addprefix $(OBJS), $(L_LST:.c=.o))		\
	$(addprefix $(OBJS), $(L_MEM:.c=.o))		\
	$(addprefix $(OBJS), $(L_PUT:.c=.o))		\
	$(addprefix $(OBJS), $(L_STR:.c=.o))
PRINT_OBJ := $(LIB_OBJ) $(addprefix $(OBJS), $(PRINTF:.c=.o))
N_LINE_OBJ := $(LIB_OBJ) $(addprefix $(OBJS), $(N_LINE:.c=.o))
OBJ_ALL := $(PRINT_OBJ) $(addprefix $(OBJS), $(N_LINE:.c=.o))
ALL_SRC = $(OBJ_ALL:.o=.c)


#
# colors
#

DEF = \e[0m
RED = \e[1;31m
MOVE = \e[1;34m
BLUE = \e[1;96m
GREEN = \e[1;32m
GREY = \e[1;90m

#
# functions
#
define compile
	@mkdir -p $(OBJS)
	@$(GCC) $1 -o $2 -I $(D_INC)
	@echo "$(GREY)[$(MOVE)Object file$(BLUE) $(notdir $2)$(GREY)] $(GREEN)Created.$(DEF)"
endef

define to_lib
	@ar rc $1 $2
	@ranlib $1
	@echo "$(GREY)[$(MOVE)Library file$(BLUE) $(notdir $1)$(GREY)] $(GREEN)Created.$(DEF)"

endef

#
# rules
#

all: $(NAME)
	

$(NAME): $(OBJ_ALL)
	@$(call to_lib, $(NAME), $(OBJ_ALL))

obj_lib: $(LIB_OBJ)
$(OBJS)%.o: $(D_L_CONV)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(D_L_COUNT)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(D_L_EDIT)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(D_L_IS)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(D_L_LST)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(D_L_MEM)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(D_L_PUT)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(D_L_STR)%.c $(LIB_INC)
	$(call compile,$<, $@)

obj_line: $(N_LINE_OBJ)
$(OBJS)%.o: $(D_N_LINE)%.c
	@$(call compile,$<, $@)

obj_print: $(PRINT_OBJ)
$(OBJS)%.o: $(D_PRINT)%.c $(PRINT_INC)
	$(call compile,$<, $@)

print: $(N_PRINTF) obj_print
$(N_PRINTF): $(PRINT_OBJ)
	@$(call to_lib, $(N_PRINTF), $(PRINT_OBJ))

lib: $(N_LIB) obj_lib
$(N_LIB): $(LIB_OBJ)
	@$(call to_lib, $(N_LIB), $(LIB_OBJ))

next_line: $(N_NEXT_LINE) obj_line
$(N_NEXT_LINE): $(N_LINE_OBJ)
	@$(call to_lib, $(N_NEXT_LINE), $(N_LINE_OBJ))

clean:
	@rm -rf $(OBJS)
	@echo "$(GREY)[$(MOVE)Path objects$(BLUE) $(OBJS)$(GREY)] $(RED)Deleted.$(DEF)"

fclean: clean
	@rm -f $(NAME) $(N_PRINTF) $(N_LIB) $(N_NEXT_LINE)
	@echo "$(GREY)[$(MOVE)Library files$(BLUE) $(NAME) $(N_PRINTF) $(N_LIB) $(N_NEXT_LINE)$(GREY)] $(RED)Deleted.$(DEF)"

re: fclean all

.PHONY: re clean fclean all next_line lib print
