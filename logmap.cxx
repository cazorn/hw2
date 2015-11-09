#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double x0 = 0.5;
	double x;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	ofstream out("data.dat"); //create a file with the name: data, which stores all the calculations
	int plenght = Nend-Nskip;
	double p[plenght];

	for(double r=1; r <= 4; r += 0.001){
	   x=x0;
	   for(int i=1; i <= Nskip; i++)
		   x = r*x*(1-x);
	   for(int i=Nskip+1; i <= Nend; i++){
	   		   x = r*x*(1-x);
			   p[i-Nskip-1]=x;
	    }
   	   for(int j=0;j <=Nend-Nskip-1;j++){   
	    out << p[j] << endl; //subsequent writing in file  
	    }
	}

	cout << "calculations done and sotred in file: data.dat" << endl;
	out.close();

	return 0;
}
