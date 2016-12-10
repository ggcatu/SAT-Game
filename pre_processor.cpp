#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

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
      int r;
      char etiqueta;
      Celda(int N, int E, int S, int W, int Z, int R, char Et){
        n = N;
        e = E;
        s = S;
        w = W;
        z = Z;
        r = R;
        etiqueta = Et;
      }; 
};

int clausula = 1;
vector< vector<Celda> > Celdas;
vector< vector<int> > ClausulasCero;
vector< vector<int> > ClausulasUno;
vector< vector<int> > ClausulasDos;

void GenerarCero(int N, int M){
    int aux,aux2;
    vector<int> auxV;
    vector<int> auxV2;

    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < M; j++){
            auxV.clear();
            auxV2.clear();
            auxV.push_back(-Celdas[i][j].e);
            auxV.push_back(Celdas[i+1][j].w);
            auxV2.push_back(Celdas[i][j].e);
            auxV2.push_back(-Celdas[i+1][j].w);
            ClausulasCero.push_back(auxV);
            ClausulasCero.push_back(auxV2);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M-1; j++){
            auxV.clear();
            auxV2.clear();
            auxV.push_back(-Celdas[i][j].n);
            auxV.push_back(Celdas[i][j+1].s);
            auxV2.push_back(Celdas[i][j].n);
            auxV2.push_back(-Celdas[i][j+1].s);
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
            if(Celdas[i][j].etiqueta == '0'){
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
                auxV.push_back(-n);
                auxV.push_back(-s);
                auxV.push_back(e);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-n);
                auxV.push_back(-e);
                auxV.push_back(s);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-n);
                auxV.push_back(-w);
                auxV.push_back(s);
                auxV.push_back(e);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-s);
                auxV.push_back(-e);
                auxV.push_back(n);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-s);
                auxV.push_back(-w);
                auxV.push_back(n);
                auxV.push_back(e);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-e);
                auxV.push_back(-w);
                auxV.push_back(n);
                auxV.push_back(s);
                ClausulasUno.push_back(auxV);
                auxV.clear();
            }
            else if(Celdas[i][j].etiqueta == '3'){
                auxV.push_back(-n);
                auxV.push_back(-s);
                auxV.push_back(-e);
                auxV.push_back(w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-n);
                auxV.push_back(-s);
                auxV.push_back(-w);
                auxV.push_back(e);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-n);
                auxV.push_back(-e);
                auxV.push_back(-w);
                auxV.push_back(s);
                ClausulasUno.push_back(auxV);
                auxV.clear();
                auxV.push_back(-s);
                auxV.push_back(-e);
                auxV.push_back(-w);
                auxV.push_back(n);
                ClausulasUno.push_back(auxV);
                auxV.clear();
            }
            else{
                auxV.push_back(-n);
                auxV.push_back(-s);
                auxV.push_back(-e);
                auxV.push_back(-w);
                ClausulasUno.push_back(auxV);
                auxV.clear();
            }
        }
    }
}

void GenerarDos(int N, int M){
    vector<int> auxV;
    int n,s,e,w,z;
    for(int j = 0; j < M; j++){
        auxV.clear();
        n = Celdas[1][j].n;
        s = Celdas[1][j].s;
        e = Celdas[1][j].e;
        w = Celdas[1][j].w;
        z = Celdas[1][j].z;
        auxV.push_back(w);
        auxV.push_back(z);
        ClausulasDos.push_back(auxV);
        auxV.clear();
        auxV.push_back(-w);
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
        auxV.push_back(e);
        auxV.push_back(z);
        ClausulasDos.push_back(auxV);
        auxV.clear();
        auxV.push_back(-e);
        auxV.push_back(-z);
        ClausulasDos.push_back(auxV);
        auxV.clear();
    }
    for(int i = 0; i < N; i++){
        auxV.clear();
        n = Celdas[i][1].n;
        s = Celdas[i][1].s;
        e = Celdas[i][1].e;
        w = Celdas[i][1].w;
        z = Celdas[i][1].z;
        auxV.push_back(s);
        auxV.push_back(z);
        ClausulasDos.push_back(auxV);
        auxV.clear();
        auxV.push_back(-s);
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
        auxV.push_back(n);
        auxV.push_back(z);
        ClausulasDos.push_back(auxV);
        auxV.clear();
        auxV.push_back(-n);
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
            auxV.push_back(z);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(n);
            auxV.push_back(-Celdas[i][j+1].z);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(e);
            auxV.push_back(-Celdas[i+1][j].z);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(s);
            auxV.push_back(-Celdas[i][j-1].z);
            ClausulasDos.push_back(auxV);
            auxV.clear();
            auxV.push_back(w);
            auxV.push_back(-Celdas[i-1][j].z);
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
            auxV.push_back(w);
            auxV.push_back(-Celdas[i-1][j].z);
            auxV.push_back(z);
            ClausulasDos.push_back(auxV);
            auxV.clear();
        }
    }
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
                Celdas[i].push_back(Celda(clausula,clausula+1,clausula+2,clausula+3,clausula+4,clausula+5,aux[j]));
                clausula += 6;
            }
        }
        cout << clausula << endl;
        cout << Celdas[0][1].n << endl;
        cout << "Clausulas 0" << endl;
        GenerarCero(n,m);
        for(int i = 0; i < ClausulasCero.size(); i++){
            cout << "{" << ClausulasCero[i][0] << "v" << ClausulasCero[i][1] << "}" << " and " << endl;
        }
        cout << endl;
        cout << "Clausulas 1" << endl;
        GenerarUno(n,m);
        for(int i = 0; i < ClausulasUno.size(); i++){
            cout << "{";
            for(int j = 0; j < ClausulasUno[i].size(); j++){
                if (j < ClausulasUno[i].size() -1){
                    cout << ClausulasUno[i][j] << "v" ;
                }
                else{
                    cout << ClausulasUno[i][j] << "}" ;
                }
            }
            cout << "and" << endl;
        }
        cout << "Clausulas 2" << endl;
        GenerarDos(n,m);
        for(int i = 0; i < ClausulasUno.size(); i++){
            cout << "{";
            for(int j = 0; j < ClausulasUno[i].size(); j++){
                if (j < ClausulasUno[i].size() -1){
                    cout << ClausulasUno[i][j] << "v" ;
                }
                else{
                    cout << ClausulasUno[i][j] << "}" ;
                }
            }
            cout << "and" << endl;
        }
	}
}