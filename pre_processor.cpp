#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

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
      string n;
      string e;
      string s;
      string w;
      Celda(string N, string E, string S, string W):s(S),n(N),e(E),w(W){}; 
      Celda(int g){
      	n = to_string(g);
      	e = to_string(g+1);
      	s = to_string(g+2);
      	w = to_string(g+3);
      }; 
};


int main(int argc, char * argv[]){
	int n, m, index;
	string line;
	ifstream infile("example_input.txt");
	while (getline(infile, line)) {
	    istringstream iss(line);
	    if (!(iss >> n >> m)) { break; } // error
	    cout << n << " " << m << endl;
	   // Celda *array[][] = new Celda[n][m];
	}
	Celda e(0);
	cout << e.n << " " << e.w;
}