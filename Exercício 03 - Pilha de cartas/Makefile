MAIN=main.c
DEPENDENCE=carta.c baralho.c 
UTIL=util.c
BINARY=executavel

all:
	gcc -Wall -Wextra -Werror -g $(UTIL) ${DEPENDENCE} $(MAIN) -o $(BINARY) -lm

run:
	./$(BINARY)
	
debug:
	gcc -DDEBUG -lm -Wall $(UTIL) ${DEPENDENCE} $(MAIN) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o

zip:
	@zip -r ex3.zip * 