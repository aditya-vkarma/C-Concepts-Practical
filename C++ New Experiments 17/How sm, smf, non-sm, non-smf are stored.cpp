#include"stdafx.h"
#include<cstdio>
#include<conio.h>


class A
{
public:
	int a, b;
	static char arr[15];

	void mf(double d)
	{
		double pre_num = 1.4234325;	//Just some
		double num = d * pre_num;	// random code.
	}

	static char* sf(char *src)
	{
		return arr;
	}
};

char A::arr[15];

int main()
{
	A a;

	/* How non-static members, static members and static member functions are stored*/

	printf("non-sm = [%u %u] \t sm = [%u %u] \t smf = %u\n", &a.a, &a.b, A::arr, A::arr+1, A::sf);	//So far not able to derive any conclusion from these addresses about how differently they're stored!
	//____________________________________________________________


	/* How a non-static member function is stored (Note: This method to get the address of a non-smf is hell tricky
	   and very very unusual. SOURCE: https://stackoverflow.com/a/8122891 */
	void (__thiscall A::*ptr2mf)(double) = &A::mf;
	void* p2mf = (void*&) ptr2mf;
	printf("non-smf = %u\n", p2mf);		//Seems sm, smf and non-smf are relatively closely stored than a non-sm.

	_getch();
}
