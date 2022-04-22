#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include "Matrix.h"
#include "MatrixIO.h"
#include <cmath>
#include <iomanip>
#include <complex>

using namespace std;
using namespace Numeric_lib;

void fsqrt( ){
	int nn = 0;
	cin >> nn;
	if(nn < 0) cout << "Invalid number ";
	else
		cout << sqrt(nn) << endl;
}

int main(){

	cout << "size of typenames: " << endl
	<< "char" << sizeof(char) << endl
	<< "short" << sizeof(short) << endl
	<< "int" << sizeof(int) << endl
	<< "long" << sizeof(long) << endl
	<< "float" << sizeof(float*) << endl
	<< "double" << sizeof(double) << endl
	<< "int*" << sizeof(int*) << endl
	<< "double*" << sizeof(double*) << endl;

	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);

	cout << "Matrix elements: " << endl
	<< "Matrix<int> a(10):  " << sizeof(a) << endl
	<< "Matrix<int> b(100): " << sizeof(b) << endl
	<< "atrix<double> c(10): " << sizeof(c) << endl
	<< "Matrix<int,2> d(10,10): " << sizeof(d) << endl
	<< "Matrix<int,3> e(10,10,10): " << sizeof(e) << endl;

	cout << "enter some numbers for sqrt: " << endl;
	for(int i = 0; i < 10; ++i)
		fsqrt();
	
	cout << "enter some floating points: " << endl;

	Matrix<double> ma(10);
	for(int i = 0; i < 10; ++i)
		cin >> ma[i];

	cout << ma << endl;
	

	cout << "Multiplication Table: " << endl;
	int m, n;
	cin >> m >> n;

	Matrix<int,2> m_table(m,n);
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(m_table(i,j) == 0){
				m_table(i,j) = i+j;
			}else{
				m_table(i,j) == i*j;
			}
		}
	}

	for (int i = 0; i < m_table.dim1(); ++i) {
        for (int j = 0; j < m_table.dim2(); ++j)
            cout << setw(5) << m_table(i,j);
        cout << endl;
        
    }

  	cout << "Complex Numbers: " << endl;
  	Matrix<complex<double>> cx (10);
  	int sum = 0;
  	for(int i = 0; i < cx.size(); ++i){
  		cin >> cx[i];
  		sum += i;
  	}
  	cout << "Sum: " << sum << endl;
  	
    
  	cout << "Matix numbers: " << endl;
	Matrix<int,2> mat (2,3);
    for (int i = 0; i < mat.dim1(); ++i)
        for (int j = 0; j < mat.dim2(); ++j)
            cin >> mat[i][j];

    cout << mat << endl;
    

}
