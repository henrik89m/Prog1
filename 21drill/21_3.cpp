#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

template<typename T>
void print(const T& t, char space = ' '){
    for(const auto& a : t)
        cout << a << space;
    cout << endl;
}

int main(){

    const string fname {"data.txt"};

    ifstream fil {fname};

    vector<double> vd;
    for(double nn; fil >> nn;)
        vd.push_back(nn);

    print(vd);

    vector<int> vi (vd.size());
    copy(vd.begin(), vd.end(), vi.begin());

    for(int i = 0; i < vd.size(); ++i)
        cout << vd[i] << '\t' << vi[i] << endl;
      
    double vd_sum = 0;        
    for(int i = 0; i < vd.size(); ++i)
        vd_sum += vd[i];

    cout << "sum of elements in vd: " << vd_sum << endl;

    double diff = 0;
    for(int i = 0; i < vd.size(); ++i)
        diff += vd[i] - vi[i];

    cout << "difference between vd and vi: " << diff << endl;

    reverse(vd.begin(),vd.end());

    print(vd);
    
    double vd_mean = vd_sum / vd.size();

    cout << "mean value of elements in vd: " << vd_mean << endl;

    vector<double> vd2;
    for(int i = 0; i < vd.size(); ++i){
        if(vd[i] < vd_mean)
            vd2.push_back(vd[i]);
    }

    print(vd2);

    sort(vd.begin(), vd.end());

    print(vd);

}