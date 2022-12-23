 #=============================================================================#
#								SOURCES											#
 #=============================================================================#

SRCS_DIR = srcs_2
MLX_DIR = minilibx
RTC_DIR = raytracer
SRCS_DIRS = $(MLX_DIR)\
				$(RTC_DIR)\

SRC_FILES =		main\
			init\
				parsing\
				get_next_line\
				get_next_line_utils\

SRCS = $(addsuffix .c, $(SRC_FILES))

 #=============================================================================#
#									OBJETS										#
 #=============================================================================#

OBJS_DIR = objets
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
DEPS = $(SRCS:%.c=$(OBJS_DIR)/%.d)

 #=============================================================================#
#									LIBRARY										#
 #=============================================================================#

LIB_DIR = libft

 #=============================================================================#
#									COMPILATION									#
 #=============================================================================#

CC = clang
CFLAGS = -Wall -Wextra -Werror -g
CDFLAGS = -MMD -MP
CIFLAGS = -Iincludes -I$(LIB_DIR)/includes -I$(MLX_DIR)
CLFLAGS = -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

 #=============================================================================#
#									MAKEFILE									#
 #=============================================================================#

NAME = miniRT

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(CIFLAGS) $(OBJS) $(CLFLAGS) -o $(NAME)

$(OBJS_DIR) :
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(MLX_DIR)
	mkdir $(OBJS_DIR)
	mkdir $(OBJS_DIR)/$(MLX_DIR)
	mkdir $(OBJS_DIR)/$(RTC_DIR)

$(OBJS) : $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(CDFLAGS) $(CIFLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C $(LIB_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -rf $(NAME)

re : fclean all

-include $(DEPS)

.PHONY: all clean fclean re