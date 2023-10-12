############
### NAME ###
############

NAME = fdf

###############
### SOURCES ###
###############

DIR_SRC = src/

LIST_SRC += main.c
LIST_SRC += readnstore_elements.c
LIST_SRC += free_fcts.c
LIST_SRC += displays.c

vpath %.c $(DIR_SRC)

###############
### OBJECTS ###
###############

DIR_BUILD = .build/

LIST_OBJ = $(LIST_SRC:.c=.o)

OBJ = $(patsubst %.c, $(DIR_BUILD)/%.o, $(LIST_SRC))

###############
### HEADERS ###
###############

DIR_HEADER += includes/

LIST_HEADER += fdf.h
LIST_HEADER += libft.h
LIST_HEADER += ft_printf.h
LIST_HEADER += gnl.h
LIST_HEADER += mlh.h

# variable notee en bleu

vpath %.h $(DIR_HEADER)

###########
### LIB ###
###########

DIR_LIBFT = libft/
DIR_MLX = minilibx_macos/

INCLUDES_LIB += -I $(DIR_HEADER)
INCLUDES_LIB += -I $(DIR_LIBFT)/includes/
INCLUDES_LIB += -I $(DIR_MLX)

#$(addprefix $(DIR_LIB), libft/)

# Shortcuts
# SRC = $(addprefix $(DIR_SRC), $(LIST_SRC))
# OBJ = $(addprefix $(DIR_BUILD), $(LIST_OBJ))
# HEADER = $(addprefix $(DIR_HEADER), $(LIST_HEADER))

MLX = $(addprefix $(DIR_MLX), libmlx.a)

#LIBFT = $(addprefix $(DIR_LIBFT), libft.a)
LIBFT = $(DIR_LIBFT)/libft.a
# (LIBFT = $(DIR_LIBFT)/libft.a) == (LIBFT = $(addprefix $(DIR_LIBFT), libft.a))

###################
### COMPILATION ###
###################

CC = cc
CFLAGS = -Wall -Wextra

ifeq ($(debug), true)
	CFLAGS += -fsanitize=address,undefined -g3
endif

ifneq ($(no_error), true)
	CFLAGS += -Werror
endif
# option a rajouter au moment du make ex: make debug=true
#  //                                 ex: make no_error=true
# ifeq (si c'est egal) si debug egal true alors aux CFLAGS += on ajoute -fsanitize=adress, fait attention au comportement indefinis
# -g3 pouur afficher plus d'info sur le code et la localisation des erreurs.
# finir par endif

##### RULES #####

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(DIR_BUILD) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBFT) -framework OpenGL -framework AppKit
# -l enleve le lib (prefix) et le .a (suffix)

$(DIR_BUILD)%.o: $(DIR_SRC)%.c $(HEADER)
	$(CC) $(CFLAGS) $< -c $(INCLUDES_LIB) -o $@

$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)

$(MLX):
	$(MAKE) -C $(DIR_MLX)

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

clean:
	$(RM) -r $(DIR_BUILD)
	$(MAKE) -C $(DIR_MLX) clean
	$(MAKE) -C $(DIR_LIBFT) clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(DIR_LIBFT) fclean

re:	fclean
	$(MAKE) all

.PHONY: all clean fclean re
#DIR_BUILD = .nom du dossier/ (= dossier cache)
# $@ permet d'obtenir le nom de la cibe
# -o (compilateur)permet de donner un chemin et un nom au fichier qu'on compile
# $< permet de récupérer la première dépendance
# Compilateur GCC
# -I (compilateur)pour préciser le dossier d'include (path) seulement pour gcc
# -c (option du compilateur) pour créer des fichiers .o (sans le binaire final) seulement pour gcc
# -C (option de make) precise le chemin pour executer un autre makefile
# -L (option compilateur)precise le dossier vers lequel se trouve la lib
# -l (compilateur)precise le nom de la lib a inclure ex: ft pour libft. enleve le lib (prefix) et le .a (suffix)
# $(RM) == rm -f (option du shell): $(RM) -r == remove recursif force pour plusieurs fichiers ou dossiers inside
# Target -> Date         Dependance -> Date
#stack_instructions.o: src/stack_instructions.c
#	$(CC) $(CFLAGS) src/stack_instructions.c -c -I include/
#addprefix  ajouter un prefix pour avoir le chemin du dossier
#La commande make -C, permet d’expliquer à make, d’aller exécuter un autre Makefile situé dans un autre dossier.

# srcs/
# |
# | - main.c
# |
# | - map/
# |	|
# |	| -map.c
# |

# LIST_SRC	+= main.c
# LIST_SRC	+= map.c

# DIR_SRC		+= srcs/
# DIR_SRC		+= srcs/map/

# SRCS		= $(addprefix $(DIR_SRC), $(LIST_SRC))

# SRCS	-> srcs/ srcs/maps main.c
# 		-> srcs/ srcs/maps map.c

# vpath %.c $(DIR_SRC)

# %.c ->srcs/main.c srcs/map/map.c
