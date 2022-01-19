MAIN=main.c
DEPENDENCE=./MatrizEsparsa.c
PROGRAMNAME=MatrizEsparsa
IN=.in
OUT=.out

all:
	gcc -O3 -march=native -Wall -Werror -Wextra ${DEPENDENCE} $(MAIN) -o $(PROGRAMNAME) -lm

run:
	./$(PROGRAMNAME)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(PROGRAMNAME)< $(IN) && ./$(PROGRAMNAME) < $(IN) > $(OUT)

clean:
	@rm *.o

zip:
	@zip -r $(PROGRAMNAME).zip * 

dev:
	clear && gcc -O3 -march=native ${DEPENDENCE} $(MAIN) -o $(PROGRAMNAME) -lm && ./$(PROGRAMNAME) < $(IN) && ./$(PROGRAMNAME) < $(IN) > $(OUT)

perfect:
	clear && gcc -O3 -march=native -Wall -Werror -Wextra ${DEPENDENCE} $(MAIN) -o $(PROGRAMNAME) -lm && valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(PROGRAMNAME)< $(IN) && ./$(PROGRAMNAME) < $(IN) > $(OUT)