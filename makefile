#cplex addresses!!!!
#folder include
INCCPLEX= -I/opt/ibm/ILOG/CPLEX_Studio1251/cplex/include/
#folder lib
LIBCPLEX= -L/opt/ibm/ILOG/CPLEX_Studio1251/cplex/lib/x86-64_sles10_4.1/static_pic/ -m64 -lcplex -lm -lpthread
#folder concert
CONCPLEX= -I/opt/ibm/ILOG/CPLEX_Studio1251/concert/include/ 


all: tools solver main

tools: src/tools/Set.h src/tools/Set.cpp src/tools/Graph.h src/tools/Graph.cpp src/tools/Timer.h  src/tools/Timer.cpp
	g++ -c -Wextra -ansi -O3 -funroll-all-loops src/tools/Set.cpp -o lib/set.o
	g++ -c -Wextra -ansi -O3 -funroll-all-loops src/tools/Graph.cpp -o lib/graph.o
	g++ -c -Wextra -ansi -O3 -funroll-all-loops src/tools/Timer.cpp -o lib/time.o
		
solver: src/solver/Solver.h src/solver/Solver.cpp src/solver/StdRepresentative.h src/solver/StdRepresentative.cpp src/solver/Heuristic.h src/solver/Heuristic.cpp
	g++ -c -Wextra -ansi -O3 -funroll-all-loops src/solver/Solver.cpp -o lib/solver.o
	g++ -c -Wextra -ansi -O3 -funroll-all-loops src/solver/Heuristic.cpp -o lib/heur.o
	g++ -c -Wextra -ansi -O3 -funroll-all-loops -DIL_STD $(INCCPLEX) $(CONCPLEX) src/solver/StdRepresentative.cpp -o lib/stdrepr.o
	
main: src/main/Main.cpp src/main/Marcio_SandBox.cpp src/main/Fabio_SandBox.cpp tools solver
	g++ -c -Wextra -ansi -O3 -funroll-all-loops src/main/Reader.cpp -o lib/reader.o
	g++ -Wextra -ansi -O3 -funroll-all-loops -DIL_STD $(INCCPLEX) $(CONCPLEX) lib/time.o lib/set.o lib/graph.o lib/reader.o lib/heur.o lib/solver.o lib/stdrepr.o src/main/Main.cpp -o bin/main $(LIBCPLEX)	
	g++ -Wextra -ansi -O3 -funroll-all-loops -DIL_STD $(INCCPLEX) $(CONCPLEX) lib/time.o lib/set.o lib/graph.o lib/reader.o lib/heur.o lib/solver.o lib/stdrepr.o src/main/Marcio_SandBox.cpp -o bin/marcio $(LIBCPLEX)
	g++ -Wextra -ansi -O3 -funroll-all-loops -DIL_STD $(INCCPLEX) $(CONCPLEX) lib/time.o lib/set.o lib/graph.o lib/reader.o lib/heur.o lib/solver.o lib/stdrepr.o src/main/Fabio_SandBox.cpp -o bin/fabio $(LIBCPLEX)