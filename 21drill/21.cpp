#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

struct Item{
    string name;
    int iid;
    double value;
};

ostream& operator<<(ostream& os, const Item& it){

    return os << it.name << " " << it.iid << " " << it.value;
}

istream& operator>>(istream& is, Item& it){

    string name;
    int iid;
    double value;
    is >> name >> iid >> value;
    Item itm {name, iid, value};
    it = itm;
    return is;
}

struct Cmp_by_value{
	bool operator()(const Item& a, const Item& b) const
		{return a.value > b.value;}
};

class Cmp_by_name{
	string name;
public:
	Cmp_by_name(const string& n) : name{n} { }
	bool operator()(const Item& a) const {return a.name == name; }
};

class Cmp_by_iid{
	int iid;
public:
	Cmp_by_iid(const int& n) : iid{n} { }
	bool operator()(const Item& a) const {return a.iid == iid; }
};

template<typename C>
void print(const C& c, char space = ' ')
{
    for (const auto& a : c)
        cout << a << space;
    cout << endl;
}

int main(){
    const string fname {"adatok.txt"};

    ifstream fil {fname};

    vector<Item> vi;
    for (Item ii; fil >> ii;)
        vi.push_back(ii);

    list<Item> li (vi.size());
    copy(vi.begin(), vi.end(), li.begin());

    sort(vi.begin(), vi.end(),
    	[](const Item& a, const Item& b) {return a.name < b.name;});

    sort(vi.begin(), vi.end(),
    	[](const Item& a, const Item& b) {return a.iid < b.iid;});

    sort(vi.begin(), vi.end(), Cmp_by_value());

    vi.push_back(Item{"Horse shoe", 99,12.34});
    vi.push_back(Item{"Canon S400", 9988,499.95});

    vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_name("Mali")));
  	vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_name("Kabul")));

  	vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_iid(26)));
    vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_iid(34)));

    print(vi);

    li.sort([](const Item& a, const Item& b) { return a.name < b.name;});
    li.sort([](const Item& a, const Item& b) { return a.iid < b.iid;});
    li.sort([](const Item& a, const Item& b) { return a.value > b.value;});

    li.push_back(Item{"Horse shoe", 99,12.34});
    li.push_back(Item{"Canon S400", 9988,499.95});

    li.erase(find_if(li.begin(), li.end(), Cmp_by_name("Cila")));
    li.erase(find_if(li.begin(), li.end(), Cmp_by_name("Liam")));
    
    li.erase(find_if(li.begin(), li.end(), Cmp_by_iid(99)));
    li.erase(find_if(li.begin(), li.end(), Cmp_by_iid(13)));

    print(li);
}