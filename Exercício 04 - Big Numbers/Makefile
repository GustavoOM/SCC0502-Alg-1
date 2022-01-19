MAIN=main.c
DEPENDENCE=TADs/numberPart/numberPart.c TADs/totalNumber/totalNumber.c TADs/operation/operation.c
UTIL=TADs/util/util.c
PROGRAMNAME=big_number
IN=.in

all:
	gcc -O3 -march=native -Wall -Werror -Wextra $(UTIL) ${DEPENDENCE} $(MAIN) -o $(PROGRAMNAME) -lm

run:
	./$(PROGRAMNAME)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(PROGRAMNAME)

clean:
	@rm *.o

zip:
	@zip -r $(PROGRAMNAME).zip * 

dev:
	gcc -O3 -march=native $(UTIL) ${DEPENDENCE} $(MAIN) -o $(PROGRAMNAME) -lm && ./$(PROGRAMNAME) < $(IN)