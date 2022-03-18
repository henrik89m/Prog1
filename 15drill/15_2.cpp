#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

void error(string error)
{
    throw runtime_error(error);
}

struct Person {
    Person() { }
    Person(string fname, string lname, int aa);

    string first_name() const { return fn; }
    string last_name() const { return ln; }
    int age() const { return a; }

private:
    string fn, ln;
    int a;
};

Person::Person(string fname, string lname, int aa)
    : fn{fname}, ln{lname}, a{aa}
{
    if (aa < 0 || 150 < aa) error("wrong age");
    
    string mix = fname + lname;
    string characters = ";:\"'[]*&^%$#@!";

    for(int i = 0; i < mix.size(); ++i){
        for(int j = 0; j < characters.size(); ++j){
            if(mix[i] == characters[j]) error("wrong character(s)");
        }
    }        
}

istream& operator>>(istream& is, Person& men){

    string firstname, lastname;
    int age1;

    is >> firstname >> lastname >> age1;

    men = Person(firstname, lastname, age1);
    return is;
}

ostream& operator<<(ostream& os, Person& men){


   return os << "Name: " << men.first_name() << " " << men.last_name() << " age: " << men.age();
}


int main()
try {

    cout << "Enter first name, second name, age: " << endl; 


    vector<Person> people;
    Person p;
    while(cin >> p){
        people.push_back(p);
    }
    for(int i = 0; i < people.size(); ++i) cout << people[i] << endl;

}
catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << endl;
    return 1;
}
