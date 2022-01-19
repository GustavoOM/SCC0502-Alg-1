MAIN=main.c
UTIL=filtro.c jogo.c catalogo.c
BINARY=executavel

all:
	gcc -Wall -Werror -g $(UTIL) $(MAIN) -o $(BINARY) -lm

run:
	./$(BINARY)
	
debug:
	gcc -DDEBUG -lm -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o

zip:
	@zip -r ex2.zip * 