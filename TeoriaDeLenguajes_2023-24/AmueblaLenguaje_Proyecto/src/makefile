# Ignacio Alcalde Torrescusa y Dario Alvarez Barrado

OBJ = expresiones.o lexico.o

ejecutar: expresiones
	./expresiones basica.amu basica.cpp

expresiones: $(OBJ) estructura.o estructuramuebles.o
	g++ -o expresiones $(OBJ) estructura.o estructuramuebles.o

estructura.o: estructura.cpp estructura.h
	g++ -c -o estructura.o estructura.cpp

estructuramuebles.o: estructuramuebles.cpp estructuramuebles.h
	g++ -c -o estructuramuebles.o estructuramuebles.cpp

expresiones.o: expresiones.c
	g++ -c -o expresiones.o expresiones.c

lexico.o: lex.yy.c
	g++ -c -o lexico.o lex.yy.c

expresiones.c: expresiones.y
	bison -d -v -o expresiones.c expresiones.y

lex.yy.c: lexico.l
	flex lexico.l

clean:
	rm -f *.o expresiones lex.yy.c expresiones.c

