#include "stdafx.h"
#include<cstdio>
#include<cstring>

using namespace std;

class A		//Class A.
{
public:
	int a;

	A()		//Default constructor sets values of all the members.
	{
		a = 999;

		int(*p)[5] = arr;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 5; j++)
				p[i][j] = (i + 1) * j;

		cptr = "John Doe";
		strcpy(str, "Chamaleon");
	}

	void show_data();		//Fucntion show_data() that displays all members's values.
	static void class_static_method();	//A class static method.

private:
	int arr[2][5];
	char *cptr;
	char str[10];
};

void A::show_data()		//A::show_data() implementation.
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 5; j++)
			printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
	putchar('\n');

	printf("%s\n", cptr);
	printf("%s\n\n", str);
}
void A::class_static_method()		//A::class_static_method() implementation.
{
	printf("----> Inside class A's static method.\n\n");
}







static void static_func()	//A static function definition.
{
	printf("----> Inside static function.\n");
}

int main()
{
	A a;

	/*  Declaring pointer to class member and pointer to class method  */
	int A::*ptr_to_class_member = &A::a;

	void (A::*ptr_to_class_method)() = &A::show_data;	// A::show_data; would be wrong! '&' must be preceded.

	/*  Accessing values  */
	printf("Now a.a through pointer to class member = %d\n\n", a.*ptr_to_class_member);
	printf("Now calling a.show_data() through pointer to class method...\n");
	(a.*ptr_to_class_method)();






	printf("____________________________________________________________\n\n");







	/*  Declaring pointer to an int and pointer to a function*/
	int *ptr_to_int = &a.a;

	//void(*ptr_to_func)() = a.show_data;	//Or &a.show_data;	//This is totally senseless!
											//A pointer to a function can't point to a non-static class method.
	void(*ptr_to_func_1)() = A::class_static_method;	//However, this is valid.
	void(*ptr_to_func_2)() = static_func;	//And so is this.

	/*  Accessing values  */
	printf("Now a.a through an int pointer = %d\n\n", *ptr_to_int);
	/*printf("Now calling a.show_data() through a pointer to function...\n\n");*/
	//ptr_to_func();	//Error!
	printf("Now calling A::class_static_method() through a pointer to function...\n");
	ptr_to_func_1();
	printf("Now calling static_func() through a pointer to function...\n");
	ptr_to_func_2();
}