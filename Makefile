##### VARIABLES #####

NAME = fdf

LIST_SRC += main.c

LIST_OBJ = $(LIST_SRC:.c=.o)
LIST_HEADER = fdf.h
# variable notee en bleu 
DIR_BUILD = .build/
DIR_SRC = src/
DIR_HEADER = includes/
DIR_MLX = minilibx_macos/
#$(addprefix $(DIR_LIB), libft/)

# Shortcuts
SRC = $(addprefix $(DIR_SRC), $(LIST_SRC))
OBJ = $(addprefix $(DIR_BUILD), $(LIST_OBJ))
HEADER = $(addprefix $(DIR_HEADER), $(LIST_HEADER))
MLX = $(addprefix $(DIR_MLX), libmlx.a)

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

all: $(MLX) $(NAME)

$(NAME): $(DIR_BUILD) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(DIR_MLX) -lmlx -framework OpenGL -framework AppKit
# -l enleve le lib (prefix) et le .a (suffix)

$(DIR_BUILD)%.o: $(DIR_SRC)%.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -I $(DIR_HEADER) -I $(DIR_MLX) -o $@

$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)

$(MLX):
	$(MAKE) -C $(DIR_MLX)
	
clean:
	$(RM) -r $(DIR_BUILD)
	$(MAKE) -C $(DIR_MLX) clean 

fclean:	clean
	$(RM) $(NAME)

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
# -l (compilateur)precise le nom de la lib a inclure ex: ft pour libft
# $(RM) == rm -f (option du shell): $(RM) -r == remove recursif force pour plusieurs fichiers ou dossiers inside
# Target -> Date         Dependance -> Date
#stack_instructions.o: src/stack_instructions.c
#	$(CC) $(CFLAGS) src/stack_instructions.c -c -I include/
#addprefix  ajouter un prefix pour avoir le chemin du dossier
#La commande make -C, permet d’expliquer à make, d’aller exécuter un autre Makefile situé dans un autre dossier. 