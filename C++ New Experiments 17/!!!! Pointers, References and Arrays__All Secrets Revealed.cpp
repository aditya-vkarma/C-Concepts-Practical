

#include "stdafx.h"
#include<iostream>

using namespace std;

int main()
{
	int arr[2][3] = { { 1,2,3 },{ 4,5,6 } };

	//____________________________________________________
	/*#1*/	int &ref_to_int = arr[0][0];	// Or **arr;	// But actually, it DOESN'T RESOLVE TO AN int* (i.e. arr[0]) BUT TO AN int (i.e. arr[0][0]) and would permenently refer there only i.e., you can't
											// index it (since references are constant) with a for loop like ref_to_int[i] to traverse values
											// through the array arr[0] like what u can do with a pointer to an integer as below:

	int *ptr_to_int = arr[0];				// Or *arr
	for (int i = 0; i < 3; i++)				// Gives 123
		cout << ptr_to_int[i];
	//_____________________________________________________


	//____________________________________________________
	/*2*/int(&ref_to_1dArray_of_int)[3] = arr[0];	//Or *arr;		// Similarly, IT RESOLVES TO AN int* AND NOT TO AN int(*)[3] like the pointer as below does.
													// So can't traverse the array arr like the pointer to a 1d array can do below:
	int(*ptr_to_1dArray_of_int)[3] = arr;
	for (int i = 0; i < 2; i++)				// Gives 123
	{										//		 456
		for (int j = 0; j < 3; j++)
			cout << ptr_to_1dArray_of_int[i][j];
		cout << endl;
	}
	//____________________________________________________


	//____________________________________________________
	/*3*/int(&ref_to_2dArray_of_int)[2][3] = arr;					// Similarly, IT RESOLVES TO AN int(*)[3] AND NOT TO AN int(*)[2][3] like the pointer as below does.
	int(*ptr_to_2dArray_of_int)[2][3] = &arr;
	//____________________________________________________
}