# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hucoulon <hucoulon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 05:19:02 by lunovill          #+#    #+#              #
#    Updated: 2023/02/06 16:04:15 by hucoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 #=============================================================================#
#								SOURCES											#
 #=============================================================================#

SRCS_DIR = sources
BNS_DIR = bonus
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
									fill_struct_utils\
									fill_struct_utils_2\
									fill_struct_utils_3)\
			$(addprefix $(MTH_DIR)/, equal\
									mt_calculate\
									mt_rotate\
									rayon\
									vt_calculate)\
			$(addprefix $(RTC_DIR)/, cm_init\
									cm_move\
									miniRT\
									raytracer\
									rt_free\
									rt_intersection\
									rt_light\
									rt_plane\
									rt_shadow\
									rt_sphere\
									rt_cylinder)\
			$(addprefix $(UTL_DIR)/, trgb_color)\
				

SRCS = $(addsuffix .c, $(SRC_FILES))

 #=============================================================================#
#									OBJETS										#
 #=============================================================================#

OBJS_DIR = objets
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_BNS = $(SRCS:%.c=$(OBJS_DIR)/%_bonus.o)
DEPS = $(SRCS:%.c=$(OBJS_DIR)/%.d)
DEPS_BNS = $(SRCS:%.c=$(OBJS_DIR)/%_bonus.d)

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
CFLAGS = -Wall -Wextra -Werror -O3
CDFLAGS = -MMD -MP
CIFLAGS = -Iincludes -I$(LFT_LIB)/includes -I$(MLX_LIB)
CLFLAGS =  $(LFT_FLAGS) $(MLX_FLAGS)

 #=============================================================================#
#									MAKEFILE									#
 #=============================================================================#

NAME = miniRT
BONUS = miniRT_bonus

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

bonus : $(BONUS)

$(BONUS) : $(OBJS_DIR) $(OBJS_BNS)
	$(CC) $(CFLAGS) $(CIFLAGS) $(OBJS_BNS) $(CLFLAGS) -o $(BONUS)

$(OBJS_BNS) : $(OBJS_DIR)/%_bonus.o : $(BNS_DIR)/%.c
	$(CC) $(CFLAGS) $(CDFLAGS) $(CIFLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C $(LFT_LIB)
	$(MAKE) clean -C $(MLX_LIB)
	rm -rf $(OBJS_DIR)

fclean : clean
	$(MAKE) fclean -C $(LFT_LIB)
	rm -rf $(NAME)
	rm -rf $(BONUS)

re : fclean all

-include $(DEPS) $(DEPS_BNS)

.PHONY: all clean fclean re

#.SILENT:
