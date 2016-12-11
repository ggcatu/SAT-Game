#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;
int last_number;

// Sacado de internet
string to_string(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

class Celda {
   public:
      int n;
      int s;
      int e;
      int w;
      int z;
      vector< vector<int> > r;
      char etiqueta;
      Celda(int N, int E, int S, int W, int Z, int I, int J, char Et){
        int p;
        n = N;
        e = E;
        s = S;
        w = W;
        z = Z;
        r.resize(I);
        p = Z+1;
        for(int i = 0; i < I; i++){
            for(int j = 0; j < J; j++){
                r[i].push_back(p++);
                last_number = p;
            }
        }
        etiqueta = Et;
      }; 
};

int clausula = 1;

vector< vector<Celda> > Celdas;
vector< vector<int> > ClausulasCero;
vector< vector<int> > ClausulasUno;
vector< vector<int> > ClausulasDos;
vector< vector<int> > ClausulasTres;
vector< vector<int> > ClausulasCuatro;
vector< vector<int> > ClausulasCinco;

void GenerarCero(int N, int M){
    int aux,aux2;
    vector<int> auxV;
    vector<int> auxV2;

    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < M; j++){
            auxV.clear();
            auxV2.clear();
            auxV.push_back(-Celdas[i][j].s);
            auxV.push_back(Celdas[i+1][j].n);
            auxV2.push_back(Celdas[i][j].s);
            auxV2.push_back(-Celdas[i+1][j].n);
            ClausulasCero.push_back(auxV);
            ClausulasCero.push_back(auxV2);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M-1; j++){
            auxV.clear();
            auxV2.clear();
            auxV.push_back(-Celdas[i][j].e);
            auxV.push_back(Celdas[i][j+1].w);
            auxV2.push_back(Celdas[i][j].e);
            auxV2.push_back(-Celdas[i][j+1].w);
            ClausulasCero.push_back(auxV);
            ClausulasCero.push_back(auxV2);
        }
    }
}

void GenerarUno(int N, int M){
    vector<int> auxV;
    int n,s,e,w;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            auxV.clear();
            n = Celdas[i][j].n;
            s = Celdas[i][j].s;
            e = Celdas[i][j].e;
            w = Celdas[i][j].w;
            if(Celdas[i][j].etiqueta == '.'){
                auxV.push_back(n);
                auxV.push_back(s);
                auxV.push_back(e);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
            }
            else if(Celdas[i][j].etiqueta == '0'){
                auxV.push_back(-n);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-s);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-e);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
            }
            else if(Celdas[i][j].etiqueta == '1'){
                auxV.push_back(n);
                auxV.push_back(s);
                auxV.push_back(e);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();

                auxV.push_back(-n);
                auxV.push_back(-e);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-n);
                auxV.push_back(-s);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-n);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-e);
                auxV.push_back(-s);
                ClausulasUno.push_back(auxV);
                auxV.clear();  
                auxV.push_back(-e);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-s);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
            }
            else if(Celdas[i][j].etiqueta == '2'){
                auxV.push_back(-e);
                auxV.push_back(-n);
                auxV.push_back(-s);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(e);
                auxV.push_back(n);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(e);
                auxV.push_back(s);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-n);
                auxV.push_back(-s);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();

                auxV.push_back(-e);
                auxV.push_back(-n);
                auxV.push_back(-s);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-e);
                auxV.push_back(-n);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(e);
                auxV.push_back(s);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(n);
                auxV.push_back(s);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();

                auxV.push_back(-e);
                auxV.push_back(-n);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(e);
                auxV.push_back(n);
                auxV.push_back(s);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(e);
                auxV.push_back(s);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-n);
                auxV.push_back(-s);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();

                auxV.push_back(-e);
                auxV.push_back(-n);
                auxV.push_back(-s);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-e);
                auxV.push_back(-s);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(e);
                auxV.push_back(n);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(n);
                auxV.push_back(s);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();

                auxV.push_back(-e);
                auxV.push_back(-s);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(e);
                auxV.push_back(n);
                auxV.push_back(s);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(e);
                auxV.push_back(n);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-n);
                auxV.push_back(-s);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();

                auxV.push_back(-e);
                auxV.push_back(-n);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-e);
                auxV.push_back(-s);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(e);
                auxV.push_back(n);
                auxV.push_back(s);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(n);
                auxV.push_back(s);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
            }
            else if(Celdas[i][j].etiqueta == '3'){
                auxV.push_back(-n);
                auxV.push_back(-s);
                auxV.push_back(-e);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(w);
                auxV.push_back(s);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(w);
                auxV.push_back(n);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(w);
                auxV.push_back(e);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(s);
                auxV.push_back(e);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(s);
                auxV.push_back(n);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(e);
                auxV.push_back(n);
                ClausulasUno.push_back(auxV);
                auxV.clear();
            }
            else{
                auxV.push_back(n);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(s);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(e);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
            }
        }
    }
}

void GenerarDos(int N, int M){
    vector<int> auxV;
    int n,s,e,w,z;
    for(int i = 0; i < N; i++){
        auxV.clear();
        n = Celdas[i][0].n;
        s = Celdas[i][0].s;
        e = Celdas[i][0].e;
        w = Celdas[i][0].w;
        z = Celdas[i][0].z;
        auxV.push_back(-w);
        auxV.push_back(z);
        ClausulasDos.push_back(auxV);
        auxV.clear();
        auxV.push_back(w);
        auxV.push_back(-z);
        ClausulasDos.push_back(auxV);
        auxV.clear();
    }
    for(int i = 0; i < N; i++){
        auxV.clear();
        n = Celdas[i][M-1].n;
        s = Celdas[i][M-1].s;
        e = Celdas[i][M-1].e;
        w = Celdas[i][M-1].w;
        z = Celdas[i][M-1].z;
        auxV.push_back(-e);
        auxV.push_back(z);
        ClausulasDos.push_back(auxV);
        auxV.clear();
        auxV.push_back(e);
        auxV.push_back(-z);
        ClausulasDos.push_back(auxV);
        auxV.clear();
    }
    for(int j = 0; j < M; j++){
        auxV.clear();
        n = Celdas[0][j].n;
        s = Celdas[0][j].s;
        e = Celdas[0][j].e;
        w = Celdas[0][j].w;
        z = Celdas[0][j].z;
        auxV.push_back(-s);
        auxV.push_back(z);
        ClausulasDos.push_back(auxV);
        auxV.clear();
        auxV.push_back(s);
        auxV.push_back(-z);
        ClausulasDos.push_back(auxV);
        auxV.clear();
    }
    for(int j = 0; j < M; j++){
        auxV.clear();
        n = Celdas[N-1][j].n;
        s = Celdas[N-1][j].s;
        e = Celdas[N-1][j].e;
        w = Celdas[N-1][j].w;
        z = Celdas[N-1][j].z;
        auxV.push_back(-n);
        auxV.push_back(z);
        ClausulasDos.push_back(auxV);
        auxV.clear();
        auxV.push_back(n);
        auxV.push_back(-z);
        ClausulasDos.push_back(auxV);
        auxV.clear();
    }
    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < M-1; j++){
            auxV.clear();
            n = Celdas[i][j].n;
            s = Celdas[i][j].s;
            e = Celdas[i][j].e;
            w = Celdas[i][j].w;
            z = Celdas[i][j].z;
            auxV.clear();
            auxV.push_back(Celdas[i-1][j].z);
            auxV.push_back(-z);
            auxV.push_back(-n);
            auxV.push_back(-e);
            auxV.push_back(-s);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(Celdas[i-1][j].z);
            auxV.push_back(-z);
            auxV.push_back(-n);
            auxV.push_back(-e);
            auxV.push_back(Celdas[i][j-1].z);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(Celdas[i-1][j].z);
            auxV.push_back(-z);
            auxV.push_back(-n);
            auxV.push_back(Celdas[i+1][j].z);
            auxV.push_back(-s);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(Celdas[i-1][j].z);
            auxV.push_back(-z);
            auxV.push_back(-n);
            auxV.push_back(Celdas[i+1][j].z);
            auxV.push_back(Celdas[i][j-1].z);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(Celdas[i-1][j].z);
            auxV.push_back(-z);
            auxV.push_back(Celdas[i][j+1].z);
            auxV.push_back(-e);
            auxV.push_back(-s);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(Celdas[i-1][j].z);
            auxV.push_back(-z);
            auxV.push_back(Celdas[i][j+1].z);
            auxV.push_back(-e);
            auxV.push_back(Celdas[i][j-1].z);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(Celdas[i-1][j].z);
            auxV.push_back(-z);
            auxV.push_back(Celdas[i][j+1].z);
            auxV.push_back(Celdas[i+1][j].z);
            auxV.push_back(-s);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(Celdas[i-1][j].z);
            auxV.push_back(-z);
            auxV.push_back(Celdas[i][j+1].z);
            auxV.push_back(Celdas[i+1][j].z);
            auxV.push_back(Celdas[i][j-1].z);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(-z);
            auxV.push_back(-n);
            auxV.push_back(-e);
            auxV.push_back(-s);
            auxV.push_back(-w);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(-z);
            auxV.push_back(-n);
            auxV.push_back(-e);
            auxV.push_back(Celdas[i][j-1].z);
            auxV.push_back(-w);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(-z);
            auxV.push_back(-n);
            auxV.push_back(Celdas[i+1][j].z);
            auxV.push_back(-s);
            auxV.push_back(-w);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(-z);
            auxV.push_back(-n);
            auxV.push_back(Celdas[i+1][j].z);
            auxV.push_back(Celdas[i][j-1].z);
            auxV.push_back(-w);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(-z);
            auxV.push_back(Celdas[i][j+1].z);
            auxV.push_back(-e);
            auxV.push_back(-s);
            auxV.push_back(-w);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(-z);
            auxV.push_back(Celdas[i][j+1].z);
            auxV.push_back(-e);
            auxV.push_back(Celdas[i][j-1].z);
            auxV.push_back(-w);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(-z);
            auxV.push_back(Celdas[i][j+1].z);
            auxV.push_back(Celdas[i+1][j].z);
            auxV.push_back(-s);
            auxV.push_back(-w);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(-z);
            auxV.push_back(Celdas[i][j+1].z);
            auxV.push_back(Celdas[i+1][j].z);
            auxV.push_back(Celdas[i][j-1].z);
            auxV.push_back(-w);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(w);
            auxV.push_back(-Celdas[i-1][j].z);
            auxV.push_back(z);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(n);
            auxV.push_back(-Celdas[i][j+1].z);
            auxV.push_back(z);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(e);
            auxV.push_back(-Celdas[i+1][j].z);
            auxV.push_back(z);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(s);
            auxV.push_back(-Celdas[i][j-1].z);
            auxV.push_back(z);
            ClausulasDos.push_back(auxV);
            auxV.clear();
        }
    }
}

void GenerarTres(int N, int M){
	vector<int> auxV;
	for(int i = 0; i < N; i++){
       for(int j = 0; j < M; j++){
       		auxV.push_back(Celdas[i][j].r[i][j]);
       		auxV.clear();
       		for(int p = 0; p < N; p++){
      			for(int q = 0; q < M; q++){
		    		if (p-1 >= 0){
		    			auxV.push_back(-Celdas[i][j].r[p][q]);
		    			auxV.push_back(Celdas[p][q].n);
		    			auxV.push_back(Celdas[i][j].r[p-1][q]);
		    			ClausulasTres.push_back(auxV);
		    			auxV.clear();
		    		}
		    		if (q+1 < M){
		    			auxV.push_back(-Celdas[i][j].r[p][q]);
		    			auxV.push_back(Celdas[p][q].e);
		    			auxV.push_back(Celdas[i][j].r[p][q+1]);
		    			ClausulasTres.push_back(auxV);
		    			auxV.clear();
		    		}
		    		if (q-1 >= 0){
		    			auxV.push_back(-Celdas[i][j].r[p][q]);
		    			auxV.push_back(Celdas[p][q].w);
		    			auxV.push_back(Celdas[i][j].r[p][q-1]);
		    			ClausulasTres.push_back(auxV);
		    			auxV.clear();
		    		}
		    		if (p+1 < N){
		    			auxV.push_back(-Celdas[i][j].r[p][q]);
		    			auxV.push_back(Celdas[p][q].s);
		    			auxV.push_back(Celdas[i][j].r[p+1][q]);
		    			ClausulasTres.push_back(auxV);
		    			auxV.clear();
		    		}
		    	}
		    }
    	}
	}
}

void GenerarCuatro(int N, int M){
	vector<int> auxV;
	for(int i = 0; i < N; i++){
       for(int j = 0; j < M; j++){
       		for(int p = 0; p < N; p++){
      			for(int q = 0; q < M; q++){
		    		auxV.push_back(-Celdas[i][j].z);
		    		auxV.push_back(-Celdas[p][q].z);
		    		auxV.push_back(Celdas[i][j].r[p][q]);
		    		ClausulasCuatro.push_back(auxV);
		    		auxV.clear();
		    	}
		    }
    	}
	}
}

void GenerarCinco(int N, int M){
    vector<int> auxV;
    int n,s,e,w;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            n = Celdas[i][j].n;
            s = Celdas[i][j].s;
            e = Celdas[i][j].e;
            w = Celdas[i][j].w;

            // NORTE
            // ###############
            // Normal
            auxV.push_back(-n);
            auxV.push_back(w);
            if(i-1 >= 0){
                auxV.push_back(Celdas[i-1][j].w);
            }
            if(j-1 >= 0){
                auxV.push_back(Celdas[i][j-1].n);
            }
            ClausulasCinco.push_back(auxV);
            auxV.clear();

            ////////////////////
            // auxV.push_back(-n);
            // auxV.push_back(w);
            // if(i-1 >= 0){
            //     auxV.push_back(-Celdas[i-1][j].w);
            // }
            // if(j-1 >= 0){
            //     auxV.push_back(-Celdas[i][j-1].n);
            // }
            // ClausulasCinco.push_back(auxV);
            // auxV.clear();

            // auxV.push_back(-n);
            // auxV.push_back(-w);
            // if(i-1 >= 0){
            //     auxV.push_back(-Celdas[i-1][j].w);
            // }
            // if(j-1 >= 0){
            //     auxV.push_back(Celdas[i][j-1].n);
            // }
            // ClausulasCinco.push_back(auxV);
            // auxV.clear();

            // auxV.push_back(-n);
            // auxV.push_back(-w);
            // if(i-1 >= 0){
            //     auxV.push_back(Celdas[i-1][j].w);
            // }
            // if(j-1 >= 0){
            //     auxV.push_back(-Celdas[i][j-1].n);
            // }
            // ClausulasCinco.push_back(auxV);
            // auxV.clear();

            ////////////////////

            // No 3
            // auxV.push_back(-n);
            // auxV.push_back(-w);
            // if(i-1 >= 0){
            //     auxV.push_back(-Celdas[i-1][j].w);
            // }
            // if(j-1 >= 0){
            //     auxV.push_back(-Celdas[i][j-1].n);
            // }
            // ClausulasCinco.push_back(auxV);
            // auxV.clear();


            // NORTE 
            auxV.push_back(-n);
            auxV.push_back(e);
            if(i-1 >= 0){
                auxV.push_back(Celdas[i-1][j].e);
            }
            if(j+1 < M){
                auxV.push_back(Celdas[i][j+1].n);
            }
            ClausulasCinco.push_back(auxV);
            auxV.clear();

            // No 3
            // auxV.push_back(-n);
            // auxV.push_back(-e);
            // if(i-1 >= 0){
            //     auxV.push_back(-Celdas[i-1][j].e);
            // }
            // if(j+1 < M){
            //     auxV.push_back(-Celdas[i][j+1].n);
            // }
            // ClausulasCinco.push_back(auxV);
            // auxV.clear();

            // WEST
            // ###############
            auxV.push_back(-w);
            auxV.push_back(n);
            if(i-1 >= 0){
                auxV.push_back(Celdas[i-1][j].w);
            }
            if(j-1 >= 0){
                auxV.push_back(Celdas[i][j-1].n);
            }
            ClausulasCinco.push_back(auxV);
            auxV.clear();

            // No 3
            // auxV.push_back(-w);
            // auxV.push_back(-n);
            // if(i-1 >= 0){
            //     auxV.push_back(-Celdas[i-1][j].w);
            // }
            // if(j-1 >= 0){
            //     auxV.push_back(-Celdas[i][j-1].n);
            // }
            // ClausulasCinco.push_back(auxV);
            // auxV.clear();

             // WEST
            // ###############
            auxV.push_back(-w);
            auxV.push_back(s);
            if(i+1 < N){
                auxV.push_back(Celdas[i+1][j].w);
            }
            if(j-1 >= 0){
                auxV.push_back(Celdas[i][j-1].s);
            }
            ClausulasCinco.push_back(auxV);
            auxV.clear();

            // No 3
            // auxV.push_back(-w);
            // auxV.push_back(-s);
            // if(i+1 < N){
            //     auxV.push_back(-Celdas[i+1][j].w);
            // }
            // if(j-1 >= 0){
            //     auxV.push_back(-Celdas[i][j-1].s);
            // }
            // ClausulasCinco.push_back(auxV);
            // auxV.clear();


            // EAST
            // ##############
            auxV.push_back(-e);
            auxV.push_back(n);
            if(i-1 >= 0){
                auxV.push_back(Celdas[i-1][j].e);
            }
            if(j+1 < M){
                auxV.push_back(Celdas[i][j+1].n);
            }
            ClausulasCinco.push_back(auxV);
            auxV.clear();

            // No 3
            // auxV.push_back(-e);
            // auxV.push_back(-n);
            // if(i-1 >= 0){
            //     auxV.push_back(-Celdas[i-1][j].e);
            // }
            // if(j+1 < M){
            //     auxV.push_back(-Celdas[i][j+1].n);
            // }
            // ClausulasCinco.push_back(auxV);
            // auxV.clear();


            auxV.push_back(-e);
            auxV.push_back(s);
            if(i+1 < N){
                auxV.push_back(Celdas[i+1][j].e);
            }
            if(j+1 < M){
                auxV.push_back(Celdas[i][j+1].s);
            }
            ClausulasCinco.push_back(auxV);
            auxV.clear();

            // auxV.push_back(-e);
            // auxV.push_back(-s);
            // if(i+1 < N){
            //     auxV.push_back(-Celdas[i+1][j].e);
            // }
            // if(j+1 < M){
            //     auxV.push_back(-Celdas[i][j+1].s);
            // }
            // ClausulasCinco.push_back(auxV);
            // auxV.clear();

            // SOUTH

            auxV.push_back(-s);
            auxV.push_back(w);
            if(i+1 < N){
                auxV.push_back(Celdas[i+1][j].w);
            }
            if(j-1 >= 0){
                auxV.push_back(Celdas[i][j-1].s);
            }
            ClausulasCinco.push_back(auxV);
            auxV.clear();

            // auxV.push_back(-s);
            // auxV.push_back(-w);
            // if(i+1 < N){
            //     auxV.push_back(-Celdas[i+1][j].w);
            // }
            // if(j-1 >= 0){
            //     auxV.push_back(-Celdas[i][j-1].s);
            // }
            // ClausulasCinco.push_back(auxV);
            // auxV.clear();



            auxV.push_back(-s);
            auxV.push_back(e);
            if(i+1 < N){
                auxV.push_back(Celdas[i+1][j].e);
            }
            if(j+1 < M){
                auxV.push_back(Celdas[i][j+1].s);
            }
            ClausulasCinco.push_back(auxV);
            auxV.clear();

            // auxV.push_back(-s);
            // auxV.push_back(-e);
            // if(i+1 < N){
            //     auxV.push_back(-Celdas[i+1][j].e);
            // }
            // if(j+1 < M){
            //     auxV.push_back(-Celdas[i][j+1].s);
            // }
            // ClausulasCinco.push_back(auxV);
            // auxV.clear();
        }
    }
}

void GenerarArchivo(){
    ofstream outfile;
    outfile.open("Sat.txt");
    vector< vector<int> > claus [6] = {ClausulasCero, ClausulasUno, ClausulasDos, ClausulasTres, ClausulasCuatro, ClausulasCinco};
    int clausulas = 0;
    for(int h = 0; h < 6; h++)
    	clausulas += claus[h].size();
    outfile << "p cnf " << last_number-1 << " " << clausulas << endl;
    for(int h = 0; h < 6; h++){
        for(int i = 0; i < claus[h].size(); i++){
            for(int j = 0; j < claus[h][i].size(); j++){
                if (j < claus[h][i].size() -1){
                    outfile << claus[h][i][j] << " " ;
                }
                else{
                    outfile << claus[h][i][j] << " 0" ;
                }
            }
            outfile << endl;
        }
    }
    outfile.close();
}

int main(int argc, char * argv[]){
	int n, m, index;
    string line;
    string aux;
	ifstream infile("example_input.txt");
	while (getline(infile, line)) {
	    istringstream iss(line);
        iss >> n >> m;
        Celdas.resize(n);
        for(int i = 0; i < n; i++){
            iss >> aux;
            cout << aux << endl;
            for(int j = 0; j < m; j++){
                Celdas[i].push_back(Celda(clausula,clausula+1,clausula+2,clausula+3,clausula+4,n,m,aux[j]));
                cout << clausula << endl;
                clausula += 5+(n*m);
            }
        }
        GenerarCero(n,m);
        GenerarUno(n,m);
        GenerarDos(n,m);
        GenerarTres(n,m);
        GenerarCuatro(n,m);
        GenerarCinco(n,m);
        GenerarArchivo();
        system("minisat Sat.txt ee.txt");
        system("post_processor");
	}
}