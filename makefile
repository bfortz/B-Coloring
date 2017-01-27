#cplex addresses!!!!
#folder include
INCCPLEX= -I/opt/ibm/ILOG/CPLEX_Studio1251/cplex/include/
#folder lib
LIBCPLEX= -L/opt/ibm/ILOG/CPLEX_Studio1251/cplex/lib/x86-64_sles10_4.1/static_pic/ -m64 -lcplex -lm -lpthread
#folder concert
CONCPLEX= -I/opt/ibm/ILOG/CPLEX_Studio1251/concert/include/ 
TDIR=src/tools
SDIR=src/solver
MDIR=src/main

all: tools solver main

tools: $(TDIR)/Set.h $(TDIR)/Set.cpp $(TDIR)/Graph.h $(TDIR)/Graph.cpp $(TDIR)/Timer.h  $(TDIR)/Timer.cpp
	g++ -c -Wextra -ansi -O3 -funroll-all-loops $(TDIR)/Set.cpp -o lib/set.o
	g++ -c -Wextra -ansi -O3 -funroll-all-loops $(TDIR)/Graph.cpp -o lib/graph.o
	g++ -c -Wextra -ansi -O3 -funroll-all-loops $(TDIR)/Timer.cpp -o lib/time.o
		
solver: $(SDIR)/Solver.h $(SDIR)/Solver.cpp $(SDIR)/StdRepresentative.h $(SDIR)/StdRepresentative.cpp $(SDIR)/Heuristic.h $(SDIR)/Heuristic.cpp $(SDIR)/BasicHeuristic.h $(SDIR)/BasicHeuristic.cpp
	g++ -c -Wextra -ansi -O3 -funroll-all-loops $(SDIR)/Solver.cpp -o lib/solver.o
	g++ -c -Wextra -ansi -O3 -funroll-all-loops $(SDIR)/Heuristic.cpp -o lib/heur.o
	g++ -c -Wextra -ansi -O3 -funroll-all-loops $(SDIR)/BasicHeuristic.cpp -o lib/bheur.o
	g++ -c -Wextra -ansi -O3 -funroll-all-loops -DIL_STD $(INCCPLEX) $(CONCPLEX) $(SDIR)/StdRepresentative.cpp -o lib/stdrepr.o
	
main: $(MDIR)/Main.cpp $(MDIR)/Marcio_SandBox.cpp $(MDIR)/Fabio_SandBox.cpp tools solver
	g++ -c -Wextra -ansi -O3 -funroll-all-loops $(MDIR)/Reader.cpp -o lib/reader.o
	g++ -Wextra -ansi -O3 -funroll-all-loops -DIL_STD $(INCCPLEX) $(CONCPLEX) lib/time.o lib/set.o lib/graph.o lib/reader.o lib/heur.o lib/bheur.o lib/solver.o lib/stdrepr.o $(MDIR)/Main.cpp -o bin/main $(LIBCPLEX)	
	g++ -Wextra -ansi -O3 -funroll-all-loops -DIL_STD $(INCCPLEX) $(CONCPLEX) lib/time.o lib/set.o lib/graph.o lib/reader.o lib/heur.o lib/bheur.o lib/solver.o lib/stdrepr.o $(MDIR)/Marcio_SandBox.cpp -o bin/marcio $(LIBCPLEX)
	g++ -Wextra -ansi -O3 -funroll-all-loops -DIL_STD $(INCCPLEX) $(CONCPLEX) lib/time.o lib/set.o lib/graph.o lib/reader.o lib/heur.o lib/bheur.o lib/solver.o lib/stdrepr.o $(MDIR)/Fabio_SandBox.cpp -o bin/fabio $(LIBCPLEX)