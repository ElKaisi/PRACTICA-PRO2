OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11
# OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -std=c++11

program.exe: cjt_jugador.o torneo.o cjt_categoria.o program.o jugador.o cjt_torneo.o
	g++ $(OPCIONS) -o program.exe cjt_jugador.o torneo.o cjt_categoria.o program.o jugador.o cjt_torneo.o

program.o: program.cc
	g++ $(OPCIONS) -c program.cc

cjt_jugador.o: cjt_jugador.cc cjt_jugador.hh
	g++ $(OPCIONS) -c cjt_jugador.cc

torneo.o: torneo.cc torneo.hh
	g++ $(OPCIONS) -c torneo.cc

cjt_categoria.o: cjt_categoria.hh cjt_categoria.cc
	g++ $(OPCIONS) -c cjt_categoria.cc

jugador.o: jugador.hh jugador.cc
	g++ $(OPCIONS) -c jugador.cc
	
cjt_torneo.o: cjt_torneo.cc cjt_torneo.hh
	g++ $(OPCIONS) -c cjt_torneo.cc

tar: Makefile cjt_jugador.hh cjt_jugador.cc cjt_categoria.hh cjt_categoria.cc jugador.cc jugador.hh torneo.hh torneo.cc BinTree.hh program.cc html.zip
	tar -cvf practica.tar *.cc *.hh Makefile html.zip
	
clean: 
	rm -f *.o *.gch *.exe *.tar
