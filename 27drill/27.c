#include <stdio.h>


void func(const char* p, const int x)
{
    printf("p is \"%s\" and x is %i\n", p, x);
}

int main(){


	printf("Hello World \n");


	char* first = "Hello";
	char* last = "World";
	printf("%s %s\n",first,last);

	func("foo", 7);
	func("joe", 5);
	func("Mar", 2);

}