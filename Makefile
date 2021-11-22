NAME_PS    =    push_swap

NAME_CK	   =    checker

CC         =    gcc

CFLAGS     =    -Wall -Wextra -Werror

RM         =    rm -f

HEADERS	   =    ./includes

HEADERS_L  =    push_swap.h \
				ds_dllist.h \
				ft_mlx.h \
				libft.h

HEADERS_S  =    $(addprefix $(HEADERS)/, $(HEADERS_L))

LIBFT_DIR  =    ./libft

LIBFT      =    ./libft/libft.a

SRCS_DIR   =    ./srcs

OBJS_DIR   =    ./objs

SRCS_GEN_D =    /general

SRCS_PS_D  =    /push_swap

SRCS_CK_D  =    /checker

SRCS_ALG_D =    /algorithm

SRCS_GEN_L = 	ps_operations.c \
				ps_operations1.c \
				ps_operations2.c \
             	ps_print_stacks.c \
             	ps_parse_args.c \
             	ps_utils.c \
             	ds_dllist.c

SRCS_ALG_L =    ps_alg_bubble_sort.c \
				ps_alg_insertion_sort.c \
				ps_alg_selection_sort.c \
				ps_alg_quick_sort.c \
				ps_alg_qsort_utils.c \
				ps_alg_utils.c \
				ps_alg_utils1.c

SRCS_PS_L  =    push_swap.c

SRCS_PS_LB =    push_swap_bonus.c \
				push_swap_parse_bonus.c \
                mlx_main.c \
                mlx_draw_main.c \
                mlx_utils.c \
                mlx_utils_col_etc.c \
                mlx_hooks.c

SRCS_CK_L  =    push_swap_checker.c

SRCS_CK_LB =    push_swap_checker_bonus.c \
				ps_checker_read_bonus.c \
				ps_checker_parse_bonus.c

SRCS_GEN   =    $(addprefix $(SRCS_DIR), $(addprefix $(SRCS_GEN_D)/, $(SRCS_GEN_L)))

SRCS_ALG   =    $(addprefix $(SRCS_DIR), $(addprefix $(SRCS_ALG_D)/, $(SRCS_ALG_L)))

SRCS_PS    =    $(addprefix $(SRCS_DIR), $(addprefix $(SRCS_PS_D)/, $(SRCS_PS_L)))

SRCS_CK    =    $(addprefix $(SRCS_DIR), $(addprefix $(SRCS_CK_D)/, $(SRCS_CK_L)))

SRCS_PS_B  =    $(addprefix $(SRCS_DIR), $(addprefix $(SRCS_PS_D)/, $(SRCS_PS_LB)))

SRCS_CK_B  =    $(addprefix $(SRCS_DIR), $(addprefix $(SRCS_CK_D)/, $(SRCS_CK_LB)))

OBJS_GEN   =    $(SRCS_GEN:%.c=$(OBJS_DIR)/%.o)

OBJS_ALG   =    $(SRCS_ALG:%.c=$(OBJS_DIR)/%.o)

OBJS_PS    =    $(SRCS_PS:%.c=$(OBJS_DIR)/%.o)

OBJS_CK    =    $(SRCS_CK:%.c=$(OBJS_DIR)/%.o)

OBJS_PS_B  =    $(SRCS_PS_B:%.c=$(OBJS_DIR)/%.o)

OBJS_CK_B  =    $(SRCS_CK_B:%.c=$(OBJS_DIR)/%.o)

ifeq ($(MAKECMDGOALS), bonus)
OBJS_PS := $(OBJS_PS_B)
OBJS_CK := $(OBJS_CK_B)
endif

$(OBJS_DIR)/%.o: %.c $(HEADERS_S)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@ -I$(HEADERS)

all: push_swap checker

push_swap: $(OBJS_PS) $(OBJS_GEN) $(OBJS_ALG) $(HEADERS_S)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS_PS) $(OBJS_GEN) $(OBJS_ALG) -o $(NAME_PS) -L $(LIBFT_DIR) -lft -I$(HEADERS) -I /usr/local/include/mlx.h -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
#-g -fsanitize=address

checker: $(OBJS_CK) $(OBJS_GEN) $(OBJS_ALG) $(HEADERS_S)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS_CK) $(OBJS_GEN) $(OBJS_ALG) -o $(NAME_CK) -L $(LIBFT_DIR) -lft -I$(HEADERS)

bonus: all

clean:
	$(RM) $(OBJS_GEN) $(OBJS_PS) $(OBJS_CK)
	$(RM) -r $(OBJS_DIR)
	@make clean -C $(LIBFT_DIR)

fclean:     clean
	$(RM) $(NAME_PS) $(NAME_CK)
	@make fclean -C $(LIBFT_DIR)

re:          fclean all

.PHONY:      all bonus clean fclean re

