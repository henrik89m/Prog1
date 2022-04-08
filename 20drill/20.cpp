#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <list>

using namespace std;

template<typename C>
void print3(const C& cont, const string& s){
	
	cout << s << '\t';
	for (auto& x : cont) cout << x << " ";
		cout << endl;
}

template<typename T>
void increase(T& c, int n) {
    for (auto& a : c)
        a+= n;
}

template<typename Iter1, typename Iter2>
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for (Iter1 p = f1; p != e1; ++p)
        *f2++ = *p;
    return f2;
}


int main(){

	constexpr int size = 10;

	int arr[size]; 
    for (int i = 0; i < size; ++i) arr[i] = i;
    print3(arr, "arr:");
	

    array<int, size> ar;
    std::copy(arr, arr + size, ar.begin());
    print3(ar, "ar:");

    vector<int> v(size);
    std::copy(arr, arr + size, v.begin());
    print3(v, "v:");

    list<int> l(size);
    std::copy(arr, arr + size, l.begin());
    print3(l, "l:");


    array<int, size> arr2 = ar;
    print3(arr2, "ar cp:");
    vector<int> v2 = v;
    print3(v2, "v cp:");
    list<int> l2 = l;
    print3(l2, "l cp:");

    increase(arr2, 2);
    print3(arr2, "arr2 inc:");
	increase(v2, 3);
	print3(v2, "v2 inc:");
	increase(l2, 5);
	print3(l2, "l2 inc:");
 
 	vector<int>::iterator vfind;
    vfind = find(v2.begin(), v2.end(), 3);
    if (vfind != v2.end())
        cout << "Found at: " << distance(v2.begin(), vfind) << endl;
    else
        cout << "Not found" << endl;

    list<int>::iterator lfind;
    lfind = find(l2.begin(), l2.end(), 27);
    if (lfind != l2.end())
        cout << "Found at: " << distance(l2.begin(), lfind) << endl;
    else
        cout << "Not found" << endl;
   
}
