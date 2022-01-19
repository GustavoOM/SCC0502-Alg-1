MAIN=main.c
DEPENDENCIES=./TADs/Util/Util.c ./TADs/Jogo/Jogo.c ./TADs/Lista/Lista.c ./TADs/Operacao/Lista/Lista.c ./TADs/Operacao/Operacao.c
PROGRAMNAME=ListaDeJogos

all:
	gcc -O3 -march=native -Wall -Werror -Wextra -g $(DEPENDENCIES) $(MAIN) -o $(PROGRAMNAME) -lm

run:
	./$(PROGRAMNAME)


