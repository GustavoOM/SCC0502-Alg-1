MAIN=main.c
DEPENDENCIES=./TADs/Util/Util.c ./TADs/Jogo/Jogo.c ./TADs/ArvoreAVL/Arvore.c
PROGRAMNAME=JogosAVL
OUT=.out
IN=.in

all:
	gcc -O3 -march=native -Wall -Werror -Wextra -g $(DEPENDENCIES) $(MAIN) -o $(PROGRAMNAME) -lm

run:
	./$(PROGRAMNAME)

dev:
	clear && gcc -O3 -march=native -Wall -Werror -Wextra -g $(DEPENDENCIES) $(MAIN) -o $(PROGRAMNAME) -lm && ./$(PROGRAMNAME) < $(IN) > $(OUT) && ./$(PROGRAMNAME) < $(IN)

