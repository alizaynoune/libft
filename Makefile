NAME = 			libn_dprintf.a
NAME_DPRINTF =		libdprintf.a
NAME_LIB = 		libft.a
NAME_NEXT_LINE =	libnext_line.a
GCC = 			gcc -Wall -Werror -Wextra -c
OBJS = 			objs/

#*
#*** src dire
#*

PATH_LIBFT_CONV = 	./libft/convert/
PATH_LIBFT_COUNT =	./libft/count/
PATH_LIBFT_EDIT = 	./libft/edit/
PATH_LIBFT_IS = 	./libft/is/
PATH_LIBFT_LST =	./libft/lst/
PATH_LIBFT_MEM =	./libft/mem/
PATH_LIBFT_PUT =	./libft/put/
PATH_LIBFT_SRCH = 	./libft/srch/
PATH_LIBFT_STR = 	./libft/str/
PATH_LIBFT_FREE = 	./libft/free/
PATH_DPRINTF =		./dprintf/
PATH_NEXT_LINE =	./gnl/
PATH_INC =		./includes/

#*
#*** src file
#*

LIBFT_CONV = 		ft_atoi_all.c				\
			ft_atoi.c				\
			ft_atol.c				\
			ft_atol_all.c				\
			ft_atoll.c				\
			ft_atoll_all.c				\
			ft_itoa.c				\
			ft_ltoa.c				\
			ft_lltoa.c				\
			ft_tolower.c				\
			ft_toupper.c				\
			ft_atoi_base.c				\
			ft_power.c				\
			ft_itoa_base.c

LIBFT_COUNT = 		count_words.c				\
			ft_count_char.c				\
			ft_strnlen.c				\
			ft_strlen.c				\
			start_end_words.c			\
			ft_intlen.c

LIBFT_EDIT = 		ft_bzero.c				\
			remove_last_space.c			\
			ft_strclr.c				\
			ft_skip_char.c

LIBFT_IS = 		ft_all_digit.c				\
			ft_isalnum.c				\
			ft_isalpha.c				\
			ft_isascii.c				\
			ft_isdigit.c				\
			ft_isprint.c

LIBFT_LST =		ft_lstadd.c				\
	    		ft_lstdel.c				\
	    		ft_lstdelone.c				\
	    		ft_lstiter.c				\
	    		ft_lstmap.c				\
	    		ft_lstnew.c

LIBFT_MEM = 		ft_memalloc.c				\
	    		ft_memccpy.c				\
	    		ft_memchr.c				\
	    		ft_memcmp.c				\
	    		ft_memcpy.c				\
	    		ft_memdel.c				\
	    		ft_memmove.c				\
	    		ft_memset.c

LIBFT_PUT = 		ft_putchar.c				\
	    		ft_putchar_fd.c				\
	    		ft_putendl.c				\
	    		ft_putendl_fd.c				\
	    		ft_putnbr.c				\
	    		ft_putnbr_fd.c				\
	    		ft_putstr.c				\
	    		ft_putstr_fd.c

LIBFT_SRCH = 		ft_strchr.c				\
	     		ft_strrchr.c				\
	     		ft_strstr.c				\
	     		ft_strnstr.c				\
	     		ft_strchrstr.c

LIBFT_STR = 		ft_strcat.c				\
	    		ft_strcmp.c				\
	    		ft_strcpy.c				\
	    		ft_strdup.c				\
	    		ft_strequ.c				\
	    		ft_striter.c				\
	    		ft_striteri.c				\
	    		ft_strjoin.c				\
	    		ft_strlcat.c				\
	    		ft_strmap.c				\
	    		ft_strmapi.c				\
	    		ft_strncat.c				\
	    		ft_strncmp.c				\
	    		ft_strncpy.c				\
	    		ft_strndup.c				\
	    		ft_strnequ.c				\
	    		ft_strnew.c				\
	    		ft_strsplit.c				\
	    		ft_strsub.c				\
	    		ft_strtrim.c				\
	    		split_by_str.c

LIBFT_FREE = 		free_rev.c				\
	     		free_tab_char.c				\
	     		ft_strdel.c

DPRINTF = 		convert_args.c				\
	  		dprintf.c				\
	  		get_args.c				\
	  		helper_args.c				\
	  		helper_put.c				\
	  		specifier.c				\
	  		tools.c

NAME_LINE = 		get_next_line.c

LIB_INC = 		./includes/libft.h
DPRINTF_INC = 		./includes/ft_dprintf.h
LINE_INC = 		./includes/get_next_line.h

LIB_OBJ := $(addprefix $(OBJS), $(LIBFT_CONV:.c=.o))		\
	$(addprefix $(OBJS), $(LIBFT_COUNT:.c=.o))		\
	$(addprefix $(OBJS), $(LIBFT_EDIT:.c=.o))		\
	$(addprefix $(OBJS), $(LIBFT_IS:.c=.o))			\
	$(addprefix $(OBJS), $(LIBFT_LST:.c=.o))		\
	$(addprefix $(OBJS), $(LIBFT_MEM:.c=.o))		\
	$(addprefix $(OBJS), $(LIBFT_PUT:.c=.o))		\
	$(addprefix $(OBJS), $(LIBFT_STR:.c=.o))		\
	$(addprefix $(OBJS), $(LIBFT_FREE:.c=.o))		\
	$(addprefix $(OBJS), $(LIBFT_SRCH:.c=.o))
DPRINTF_OBJ := $(LIB_OBJ) $(addprefix $(OBJS), $(DPRINTF:.c=.o))
NAME_LINE_OBJ := $(LIB_OBJ) $(addprefix $(OBJS), $(NAME_LINE:.c=.o))
OBJ_ALL := $(DPRINTF_OBJ) $(addprefix $(OBJS), $(NAME_LINE:.c=.o))


#*
#*** colors
#*

DEF =		\e[1;0m
RED =		\e[1;31m
PURPLE =	\e[1;34m
BLUE =		\e[1;96m
GREEN =		\e[1;32m
SILVER =	\e[1;90m
YELLOW =	\e[1;33m

#*
#*** functions
#*
define compile
@mkdir -p $(OBJS)
@$(GCC) $1 -o $2 -I $(PATH_INC)
@echo "$(SILVER)[$(PURPLE)Object file$(BLUE) $(notdir $2)$(SILVER)] $(GREEN)Created.$(DEF)"
endef

define to_lib
@ar rc $1 $2
@ranlib $1
@echo "$(SILVER)[$(PURPLE)Library file$(YELLOW) $(notdir $1)$(SILVER)] $(GREEN)Created.$(DEF)"

endef

define remove_lib
@rm -f $1
@echo "$(SILVER)[$(PURPLE)library file$(YELLOW)$1$(SILVER)] $(RED)deleted.$(DEF)"
endef

#*
#*** rules
#*

all:		$(NAME)

dprintf:	$(NAME_DPRINTF)

libft:		$(NAME_LIB)

next_line:	$(NAME_NEXT_LINE)

$(NAME): $(OBJ_ALL)
	@$(call to_lib, $(NAME), $(OBJ_ALL))

$(OBJS)%.o: $(PATH_LIBFT_CONV)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_COUNT)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_EDIT)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_IS)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_LST)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_MEM)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_PUT)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_STR)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_FREE)%.c $(LIB_INC)
	@$(call compile, $<, $@)

$(OBJS)%.o: $(PATH_LIBFT_SRCH)%.c $(LIB_INC)
	@$(call compile, $<, $@)

$(OBJS)%.o: $(PATH_NEXT_LINE)%.c
	@$(call compile,$<, $@)


$(OBJS)%.o: $(PATH_DPRINTF)%.c $(DPRINTF_INC)
	@$(call compile,$<, $@)

$(NAME_DPRINTF): $(DPRINTF_OBJ)
	@$(call to_lib, $(NAME_DPRINTF), $(DPRINTF_OBJ))

$(NAME_LIB): $(LIB_OBJ)
	@$(call to_lib, $(NAME_LIB), $(LIB_OBJ))

$(NAME_NEXT_LINE): $(NAME_LINE_OBJ)
	@$(call to_lib, $(NAME_NEXT_LINE), $(NAME_LINE_OBJ))

clean:
	@rm -rf $(OBJS)
	@echo "$(SILVER)[$(PURPLE)Path objects$(DEF) $(OBJS)$(SILVER)] $(RED)Deleted.$(DEF)"

fclean: clean
	@$(call remove_lib, $(NAME))
	@$(call remove_lib, $(NAME_DPRINTF))
	@$(call remove_lib, $(NAME_NEXT_LINE))
	@$(call remove_lib, $(NAME_LIB))

fclean_dprintf:	clean
	@$(call remove_lib, $(NAME_DPRINTF))

fclean_next:	clean
	@$(call remove_lib, $(NAME_NEXT_LINE))

fclean_libft:	clean
	@$(call remove_lib, $(NAME_LIB))

re_dprintf:	fclean_dprintf dprintf

re_next:	fclean_next next_line

re_libft:	fclean_libft libft

re:		fclean all

.PHONY: re clean fclean all next_line libft dprintf fclean_dprintf fclean_next fclean_libft re_dprintf re_next re_libft
