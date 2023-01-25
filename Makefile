# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhali <skhali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 05:19:02 by lunovill          #+#    #+#              #
#    Updated: 2022/11/07 19:03:27 by skhali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 #=============================================================================#
#								SOURCES											#
 #=============================================================================#

SRCS_DIR = sources
MLX_DIR = minilibx
PSG_DIR = parsing
MTH_DIR = math
RTC_DIR = raytracer
UTL_DIR = utils
SRCS_DIRS = $(MLX_DIR)\
				$(PSG_DIR)\
				$(MTH_DIR)\
				$(RTC_DIR)\
				$(UTL_DIR)\

SRC_FILES =	main\
			$(addprefix $(MLX_DIR)/, mlx_close\
									mlx_event\
									mlx_init_key\
									mlx_init_window\
									mlx_put_pixel)\
			$(addprefix $(PSG_DIR)/, init\
									error\
									parsing\
									fill_struct\
									get_next_line\
									fill_struct_utils\
									get_next_line_utils)\
			$(addprefix $(MTH_DIR)/, mt_calculate\
									mt_inverse\
									mt_rotate\
									mt_transform\
									vt_calculate)\
			$(addprefix $(RTC_DIR)/, cm_init\
									miniRT\
									raytracer\
									rt_free)\
			$(addprefix $(UTL_DIR)/, trgb_color)\
				

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

LFT_LIB = libft
LFT_FLAGS = -L$(LFT_LIB) -lft
MLX_LIB = minilibx
MLX_FLAGS = -L$(MLX_LIB) -lmlx -lXext -lX11 -lm -lz

 #=============================================================================#
#									COMPILATION									#
 #=============================================================================#

CC = clang
CFLAGS = -Wall -Wextra -Werror -g
CDFLAGS = -MMD -MP
CIFLAGS = -Iincludes -I$(LFT_LIB)/includes -I$(MLX_LIB)
CLFLAGS =  $(LFT_FLAGS) $(MLX_FLAGS)

 #=============================================================================#
#									MAKEFILE									#
 #=============================================================================#

NAME = miniRT

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(CIFLAGS) $(OBJS) $(CLFLAGS) -o $(NAME)

$(OBJS_DIR) :
	$(MAKE) -C $(LFT_LIB)
	$(MAKE) -C $(MLX_LIB)
	mkdir $(OBJS_DIR)
	mkdir $(addprefix $(OBJS_DIR)/, $(MLX_DIR)\
									$(PSG_DIR)\
									$(MTH_DIR)\
									$(RTC_DIR)\
									$(UTL_DIR))

$(OBJS) : $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(CDFLAGS) $(CIFLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C $(LFT_LIB)
	$(MAKE) clean -C $(MLX_LIB)
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LFT_LIB)
	rm -rf $(NAME)

re : fclean all

-include $(DEPS)

.PHONY: all clean fclean re

#.SILENT:
