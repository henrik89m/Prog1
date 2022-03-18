#include "Simple_window.h"
#include "Graph.h"

double one(double) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x)+slope(x);}

int main(){

	using namespace Graph_lib;

	constexpr int xmax = 600;
	constexpr int ymax = 600;

	Simple_window win {Point{100,100},xmax,ymax,"Function Graphs"};

	Axis xa{Axis::x, Point {100,300}, 400,20, "1 == 20 pixels"};
	Axis ya{Axis::y, Point {300,500}, 400,20, "1 == 20 pixels"};

	xa.set_color (Color::red);
	ya.set_color (Color::red);

	constexpr int x_orig = xmax/2;
	constexpr int y_orig = ymax/2;
	const Point orig {x_orig,y_orig};

	constexpr int r_min = -10;
	constexpr int r_max =  11;

	constexpr int n_points = 400;

	constexpr int x_scale = 20;
	constexpr int y_scale = 20;

	Function s {one,r_min, r_max,orig,n_points,x_scale,y_scale};
	Function s2 {slope,r_min, r_max,orig,n_points,x_scale,y_scale};
	Function s3 {square,r_min, r_max,orig,n_points,x_scale,y_scale};

	Text ts {Point{100,y_orig+y_orig/2-70}, "x/2"};

	Function s4 {cos,r_min, r_max,orig,n_points,x_scale,y_scale};
	s4.set_color(Color::blue);

	Function s5 {sloping_cos,r_min, r_max,orig,n_points,x_scale,y_scale};

	win.attach(xa);
	win.attach(ya);
	win.attach(s);
	win.attach(s2);
	win.attach(s3);
	win.attach(ts);
	win.attach(s4);
	win.attach(s5);
	

	win.wait_for_button();

}