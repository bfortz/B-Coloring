
#include "ImpRepresentative.h"

void ImpRepresentative::innerbuild(){
	int status;
	env = CPXopenCPLEX(&status);
	lp = CPXcreateprob(env, &status, "B-col with lower bounds");

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			x[i][j] = -1;
		}
	}
	//printf("INIT OK!\n");
	//getchar();

	char name[100];
	for(int i = 0; i < n; i++){
		if(g->degree(i) >= lb - 1){
			//printf("vertice %d passed \n", i);
			//getchar();
			x[i][i] = var++;
			sprintf(name, "x[%d][%d]", i+1, i+1);
			addBinVar(1.0, name);
			for(int j = 0; j< n; j++){
				if(j != i && !g->hasEdge(i, j)){
					x[i][j] = var++;
					sprintf(name, "x[%d][%d]", i+1, j+1);
					addBinVar(0.0, name);
				}
			}
		}
	}
	//printf("BUILD OK!\n");
	//getchar();

	Set* visited = new Set(n);
	long u, w;
	Set* mark = new Set(n);
	for(int v = 0; v < n; v++){
		addRepresentativeConst(v);
		//printf("Representative OK for %d\n", v);
		//getchar();
		visited->removeAll();
		visited->unio(g->getAntiNeig(v));
		u = 0;
		mark->removeAll();
		while(!visited->isEmpty()){
			u = visited->firstElemAfter(u);
			w = visited->firstElemAfter(u+1);
			while(w < n){
				if(g->hasEdge(w, u)){
					addEdgeConst(v, u, w);
					mark->add(u);
					mark->add(w);
				}
				w = visited->firstElemAfter(w+1);
			}

			if(!mark->isIn(u)) addSingleVConst(v, u);

			visited->remove(u);
		}
	}

	for(int v = 0; v < n; v++){
		for(int u = 0; u < n; u++){
			if(v!=u && x[v][v] >= 0 && x[u][u] >= 0 && !g->hasEdge(v, u)) addBcolConstraint(v, u);
		}
	}
}

void ImpRepresentative::innerSolver(){
	CPXchgprobtype(env, lp, 1);

	CPXchgobjsen(env, lp, CPX_MAX);

	int status = CPXsetdblparam(env, CPX_PARAM_TILIM/*1039*/, 1800.0);
	if(status != 0){
		printf("\n PROBLEMS TO ADD TIME LIMIT TO THE MODEL!!!! ERRO CODE = %d\n", status);
	}

	status = CPXwriteprob (env, lp, "bcolwithheuristic.lp", NULL);
	if(status != 0){
		printf("\nPROBLEMS TO WRITE THE MODEL!!!! ERRO CODE = %d\n", status);
	}

	status = CPXmipopt (env, lp);

	if(status != 0){
		printf("\n PROBLEMS TO SOLVE THE MODEL!!!! ERRO CODE = %d\n", status);
	}

	int lpstat = CPXgetstat (env, lp);
	if(lpstat != CPXMIP_OPTIMAL && lpstat != CPXMIP_OPTIMAL_TOL && lpstat != CPX_STAT_OPTIMAL  && lpstat != CPX_STAT_OPTIMAL_INFEAS){
		printf("\n No SOLUTION status = %d\n", lpstat);
	}

	double val;
	CPXgetobjval(env, lp, &val);
	if(status != 0){
		printf("\nPROBLEMS TO RETRIVE OPTIMAL SOLUTION!!!! ERRO CODE = %d\n", status);
	}

	solution = val;
}

void ImpRepresentative::addBinVar(double coef, char* name){
	double obj = coef;
	double lb = 0.0;
	double up = 1.0;
	char type = 'B';
	CPXnewcols(env, lp, 1, &obj, &lb, &up, &type, &name);
}

void ImpRepresentative::addEdgeConst(long v, long u, long w){
	double rhs = 0.0;// lado direito

	char sense = 'L';

	int rmatind[3] = {x[v][v], x[v][u], x[v][w]};
	double rmatval[3] = {-1.0, 1.0, 1.0};

	int rmatbeg[2] = {0, 2};

	if(x[v][v] >= 0)CPXaddrows(env, lp, 0, 1, 3, &rhs, &sense, rmatbeg,rmatind, rmatval, NULL, NULL);
}

void ImpRepresentative::addSingleVConst(long v, long u){
	double rhs = 0.0;// lado direito

	char sense = 'L';

	int rmatind[2] = {x[v][v], x[v][u]};
	double rmatval[2] = {-1.0, 1.0};

	int rmatbeg[2] = {0, 1};

	if(x[v][v] >= 0)CPXaddrows(env, lp, 0, 1, 2, &rhs, &sense, rmatbeg,rmatind, rmatval, NULL, NULL);
}

void ImpRepresentative::addRepresentativeConst(long v){
	int nzcnt = 0; //numero de coeficientes nao zero
	double rhs = 1.0;// lado direito

	char sense = 'L';

	int rmatind[n];
	double rmatval[n];

	if(x[v][v] >= 0){
		rmatind[nzcnt] = x[v][v];
		rmatval[nzcnt++] = 1.0;
	}
	for(int i = 0; i < n; i++){
		if(i != v && !g->hasEdge(v, i) && x[i][i] >= 0){
			rmatind[nzcnt] = x[i][v];
			rmatval[nzcnt++] = 1.0;
		}
	}

	int rmatbeg[2] = {0, nzcnt - 1};

	CPXaddrows(env, lp, 0, 1, nzcnt, &rhs, &sense, rmatbeg,rmatind, rmatval, NULL, NULL);
}

void ImpRepresentative::addBcolConstraint(long v, long u){
	int nzcnt = 0; //numero de coeficientes nao zero
	double rhs = -1.0;// lado direito

	char sense = 'G';

	int rmatind[n];
	double rmatval[n];

	rmatind[nzcnt] = x[v][v];
	rmatval[nzcnt++] = -1.0;
	rmatind[nzcnt] = x[u][u];
	rmatval[nzcnt++] = -1.0;

	for(int i = 0; i < n; i++){
		if(i != v && i != u && !g->hasEdge(u, i) && g->hasEdge(v, i)){
			rmatind[nzcnt] = x[u][i];
			rmatval[nzcnt++] = 1.0;
		}
	}

	int rmatbeg[2] = {0, nzcnt - 1};

	if(x[v][v] >= 0 && x[u][u] >= 0)CPXaddrows(env, lp, 0, 1, nzcnt, &rhs, &sense, rmatbeg,rmatind, rmatval, NULL, NULL);
}

ImpRepresentative::ImpRepresentative(Graph* h, long lnb): Solver(h){
	lb = lnb;
	g = h;
	n = g->sizeV();
	var = 0;
	x = new long*[n];
	for(int i = 0; i < n; i++){
		x[i] = new long[n];
	}
}

ImpRepresentative::~ImpRepresentative(){
	for(int i = 0; i < n; i++) delete x[i];

	delete x;
}

