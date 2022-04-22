#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <list>
#include <map>
#include <numeric>

using namespace std;

template<typename C, typename U>
void print(const map<C,U>& c)
{
    for (const auto& a : c)
        cout << a.first << " " << a.second << endl;
    cout << endl;
}

void out_put(map<string, int>& mp){

	string mapp;
	int nn = 0;
	for(int i = 0; i < mp.size(); ++i){
		cin >> mapp >> nn;
		mp.insert(make_pair(mapp,nn));
	}
}

int main(){

	map<string, int> msi;

	msi["Amber"] = 21;
	msi["Johnny"] = 69;
	msi["Liam"] = 66;
	msi["Mali"] = 33;
	msi["Ían"] = 23;
	msi["Magnus"] = 94;
	msi["Cleo"] = 89;
	msi["Aaron"] = 75;
	msi["Thomas"] = 67;
	msi["Floyd"] = 35;

	print(msi);

	//msi.erase(msi.begin(), msi.end());

	out_put(msi);

	print(msi);
    
	int sum_map = accumulate(msi.begin(), msi.end(), 0,
            [](int sum, const pair<string,int>& p) { return sum += p.second; });

	cout << "sum of map: " << sum_map << endl;

	map<int, string> mis;
	for (const auto& a : msi)
        mis[a.second] = a.first;

    print(mis);

}