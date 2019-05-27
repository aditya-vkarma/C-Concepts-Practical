// Pointers and Arrays__All Secrets Revealed.cpp : main project file.

#include "stdafx.h"
#include<iostream>

using namespace std;


int main()
{
	int arr[4][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12} };

	int *ptr_to_int = arr[0];

	int(*ptr_to_1dArray_of_int)[3] = arr;

	int(*ptr_to_2dArray_of_int)[4][3] = &arr;
}