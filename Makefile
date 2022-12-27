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
RTC_DIR = raytracer
SRCS_DIRS = $(MLX_DIR)\
				$(RTC_DIR)\

SRC_FILES =	$(MLX_DIR)/mlx_close\
				$(MLX_DIR)/mlx_event\
				$(MLX_DIR)/mlx_init_key\
				$(MLX_DIR)/mlx_init_window\
				$(MLX_DIR)/mlx_put_pixel\
				$(RTC_DIR)/mt_init\
				$(RTC_DIR)/mt_cross\
				$(RTC_DIR)/rt_camcoor\
				$(RTC_DIR)/rt_draw_pixel\
				$(RTC_DIR)/rt_free\
				$(RTC_DIR)/rt_image\
				$(RTC_DIR)/mt_rotate\
				miniRT\
				rgb_color\
				

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
