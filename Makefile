SRCS	= check_file.c \
		check_file2.c \
		cleaning.c \
		colors.c \
		draw.c \
		exit.c \
		ft_atoi.c \
		ft_ncmp_dup.c \
		ft_split.c \
		get_map.c \
		get_next_line.c \
		get_next_line_utils.c \
		hooks.c \
		image.c \
		init_game.c \
		main.c \
		moves.c \
		parsing.c \
		parsing_utils.c \
		player.c \
		raycaster.c \
		raycaster2.c \
		texturing.c \
			
SRCSB	= check_file.c \
		check_file2.c \
		cleaning_bonus.c \
		colors.c \
		draw.c \
		exit_bonus.c \
		ft_atoi.c \
		ft_ncmp_dup.c \
		ft_split.c \
		get_map_bonus.c \
		get_next_line.c \
		get_next_line_utils.c \
		hooks_bonus.c \
		hooks2_bonus.c \
		hooks3_bonus.c \
		image.c \
		init_bonus.c \
		init_game_bonus.c \
		main.c \
		minimap.c \
		moves_bonus.c \
		parsing.c \
		parsing_utils.c \
		player.c \
		raycaster_bonus.c \
		raycaster2_bonus.c \
		texturing_bonus.c 

SRCDIR = srcs
SRCBDIR = srcs_bonus

OBJDIR = objs
OBJBDIR = objs_bonus

SOURCES := ${addprefix ${SRCDIR}/, ${SRCS}}
OBJS	:= ${SOURCES:${SRCDIR}/%.c=${OBJDIR}/%.o}

SOURCESB := ${addprefix ${SRCBDIR}/, ${SRCSB}}
OBJSB	:= ${SOURCESB:${SRCBDIR}/%.c=${OBJBDIR}/%.o}

NAME	= cub3D
NAMEB	= cub3Dbonus

LFT		= libft/libft.a

MLX		= mlx/libmlx.a

INC		= -I ./includes -I ./libft -I ./mlx

CC		= cc
RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g

LIBFLAGS	= -L./libft -lft 

${NAME}:	${MLX}  ${OBJS}
			@echo "Created object files."
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L./mlx -lmlx -lXext -lX11 -lm
			@echo "cub3D is ready!"

${NAMEB}:	${MLX} ${OBJSB}
			@echo "Created object files."
			@${CC} ${CFLAGS} ${OBJSB} -o ${NAMEB} -L./mlx -lmlx -lXext -lX11 -lm
			@echo "cub3D with bonus is ready!"

			
${OBJDIR}/%.o : ${SRCDIR}/%.c
		@[ ! -d ${OBJDIR} ] && mkdir -p  ${OBJDIR} || true
		@$(CC) $(CFLAGS) -c ${INC} $< -o $@

${OBJBDIR}/%.o : ${SRCBDIR}/%.c
		@[ ! -d ${OBJBDIR} ] && mkdir -p  ${OBJBDIR} || true
		@$(CC) $(CFLAGS) -c ${INC} $< -o $@

${LFT}:
		@echo " [..] | Compiling libft..."
		@make -s -C libft
		@echo " [OK] | Done."

${MLX}:
		@echo " [..] | Compiling minilibx..."
		@make -s -C mlx
		@echo " [OK] | Done."

all:		${NAME}

bonus:		${NAMEB}

sanitize:	${MLX}
		@${CC} ${CFLAGS} -fsanitize=address -g3 ${INC} ${SOURCES} -o ${NAME} -L./mlx -lmlx -lXext -lX11 -lm
		@echo " Compiled with address sanitizer."


clean:		
		@${RM} ${OBJS}
		@${RM} ${OBJSB}
		@${RM} ${OBJDIR}
		@${RM} ${OBJBDIR}
		@echo "Object files removed."

fclean:		clean
		@${RM} ${NAME}
		@${RM} ${NAMEB}
		@echo "Binary files removed."

re:		fclean all

rebonus: fclean bonus

.PHONY: all clean sanitize fclean re bonus
