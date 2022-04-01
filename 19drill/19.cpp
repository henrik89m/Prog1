#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T> struct S{
	S(T v) : val{v} {}

	T& get();
	const T& get() const;
	T& operator = (const T&);

private:
	T val;
};


template<class T> T& S<T>::get(){return val;}

template<class T> const T& S<T>::get() const {return val;}


template<class T> void read_val(T& v){
	
	cin >> v;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){

	os << "{ ";
    for (int i = 0; i<v.size(); ++i) {
        os << v[i];
        if (i<v.size()-1) os << ',';
        os << ' ';
    }
    os << "}";
    return os;
	
}

template<typename T>
istream& operator>>(istream& is, vector<T>& t ){

	T v;
    cin >> v;
    if (!is) return is;
    t = v;

	return is;
}

int main(){

	S<int> s1{12};
	S<char> s2{'a'};
	S<double> s3{1.1};
	S<string> s4{"Hello"};
	vector<int> s5 {vector<int>{1,3,4,1}};

	cout << "s<int> " << s1.get() << endl;
    cout << "s<char> " << s2.get() << endl;
    cout << "s<double> "<< s3.get() << endl;
    cout << "s<string> "<< s4.get() << endl;
    cout << "s<vector> "<< s5 << endl;


	return 0;
}