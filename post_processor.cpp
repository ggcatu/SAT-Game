#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

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
            }
        }
        etiqueta = Et;
      }; 
};
void cVector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] ;
    }
    cout << " ";
}


int main(int argc, char * argv[]){
	int n, m, index;
    string line;
    string aux;
	ifstream infile("Satout.txt");
    int N = 5, M = 5;
    N = atoi(argv[1]);
    M = atoi(argv[2]);
    cout << N << " " << M << " ";
    int i = 0, k = 0, p = 0;
    int f;
    int ee;
    vector<int> horizontal;
    vector<int> vertical;
    vector<int> last_horizontal;
    horizontal.clear();
    vertical.clear();
	while (getline(infile, line)) {
        if (i++ == 0)
            continue;
        istringstream iss(line);
        while(iss >> n){
            if (p == N)
                break;
            if (i<6){
                f = n;
                if (i == 2){
                    horizontal.push_back(int(f)>0);
                }
                if (i == 5){
                    vertical.push_back(int(f)>0);
                }
                 if (k == M-1){
                     if (i == 3){
                        ee = int(f)>0;
                     }
                }
                if (p == N-1){
                    if (i == 4){
                        last_horizontal.push_back(int(f)>0);
                    }
                }
            } else{
                if (i == 6+(N*M)){
                    k++;
                    if (k == M){
                        vertical.push_back(ee);
                        cVector(horizontal);
                        cVector(vertical);
                        horizontal.clear();
                        vertical.clear();
                        k = 0;
                        p++;
                    }
                    i = 1;
                    
                }
            }
            i++;
        }
        cVector(last_horizontal);
	}
}