#include <iostream>

using namespace std;

struct B1{
	virtual void vf() const {cout << "B1::vf";}
	void f() const {cout << "B1::f";}
	virtual void pvf() = 0;
};

struct D1 : B1{
	void vf() const override {cout << "D1::vf";}
	void f() const {cout << "D1::f";}
};

struct D2 : D1{
	void pvf() override {cout << "D2::pvf";}
};

struct B2{
	virtual void pvf() = 0;
};

struct D21 : B2 {
	string mem = " Data Member ";
	void pvf() override {cout << mem;}
};

struct D22 : B2 {
	int num = 21;
	void pvf() override {cout << num;}
};

void call(const B1& b){
	b.vf();
	b.f();
}

void f(B2& b2){
	
	b2.pvf();
}

int main(){
	/*
	B1 b1;    
	D1 d1;
	call(b1);
	call(d1);

	b1.vf();
	b1.f();

	d1.vf();
	d1.f();
	*/

	D2 d1;
	call(d1);
	d1.vf();
	d1.f();
	d1.pvf();
	
	D21 d21;
	D22 d22;
	
	f(d21);
	f(d22);
}