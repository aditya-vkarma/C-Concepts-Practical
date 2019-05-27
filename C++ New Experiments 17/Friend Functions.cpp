// Roger.cpp : main project file.

#include"stdafx.h"
#include<cstdio>

const int IDLE = 1;
const int INUSE = 0;

class C2;	// Class C2 forward declaration.

class C1	// Class C1 definition.
{
public:
        C1();	// Constructor declaration.
        void set_status(int);	//Method declaration.
        bool idle(C2);			//Method declaration.
        friend void foo(C1&, C2&);	// Friend function declaration.

private:
        int status1;	//private field.
};

class C2	//Class C2 definition.
{
public:
        C2();	// Constructor declaration.
        void set_status(int); // Method declaration.
        friend bool C1::idle(C2);	// Friend function declaration.
        friend void foo(C1&, C2&);	// Friend function declaration.

private:
        int status2;	//Private field.
};



C1::C1() { status1 = INUSE; }	// C1::C1() implementation.

void C1::set_status(int status)	// C1::set_status(int) implementation.
{
        this->status1 = status;
}

bool C1::idle(C2 b)		// C1::idle(C2) implementation.
{
        return status1 && b.status2;
}



C2::C2() { status2 = IDLE; }	// C2::C2() implementation.

void C2::set_status(int status)		// C2::set_status(int) implementation.
{
        this->status2 = status;
}



void foo(C1 &a, C2 &b)		// foo(C1&, C2&) definition.
{
        a.status1 = IDLE;
        b.status2 = IDLE;
}





int main(int argc, char *argv[])
{
        C1 a;
        C2 b;

        /*a.set_status(IDLE);	//These two lines make system free.
        b.set_status(IDLE);*/

        //foo(a, b);	//This also makes system free.

        printf(a.idle(b) ? "System is free.\n" : "System is occupied!\n");
}
