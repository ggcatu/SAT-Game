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

void GenerarCero(int n, int m){
    int aux,aux2;
    vector<int> auxV;
    vector<int> auxV2;

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n; j++){
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

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
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
            cout << aux << endl;
            for(int j = 0; j < m; j++){
                Celdas[i].push_back(Celda(clausula,clausula+1,clausula+2,clausula+3,clausula+4,clausula+5,aux[j]));
                clausula += 6;
            }
        }
        cout << Celdas[0][1].n << endl;
        GenerarCero(n,m);
        for(int i = 0; i < ClausulasCero.size(); i++){
            cout << "{" << ClausulasCero[i][0] << "v" << ClausulasCero[i][1] << "}" << " and ";
        }
	}
}