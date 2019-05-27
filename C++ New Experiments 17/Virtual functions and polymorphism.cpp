#include "stdafx.h"
#include<iostream>

using namespace std;

class Base
{
public:
	virtual void showMsg()
	{
		cout << "Base's Message.\n";
	}
};

class Derived1 : public Base
{
public:
	void showMsg()
	{
		cout << "Derived1's Message.\n";
	}
};

class Derived2 : public Derived1
{
public:
	void showMsg()
	{
		cout << "Derived2's Message.\n";
	}
};

class Derived3 : public Derived2
{

};

//int main()
//{
//	Base *bp;
//	Derived2 d2;
//
//	//__________________
//
//	bp = &d2;
//	bp->showMsg();	//If u hover over showMsg() in this line, the tooltip shows "void Base::showMsg()" as the method signature coz polymorphism is
//					//achieved at runtime not compile time.
//
//	//bp->Derived1::showMsg();	//Error! Coz bp is a Base* and through a base* you can only access a base (Or the base part of the derived class).
//
//	Derived2 *d2p;
//	d2p = &d2;
//	d2p->Derived1::showMsg();	//This is valid.
//
//	//____________________
//
//	Derived3 d3;
//	bp = &d3;
//	bp->showMsg();	// Like inheritance, virtual functions are also hierarchical. When a derived class fails to override a virtual function, the first
//					// redefinition found in reverse order of derivation is used. In this case the one in Derived2 is used.
//}


//int main()
//{
//	Derived1 *d1p;
//	Derived2 d2;
//
//	d1p = &d2;
//	
//	d1p->showMsg();		//The Virtual Attribute is Inherited: When a derived class that has inherited a virtual function is itself used as a base class
//						//for another derived class, the virtual function can still be overridden, i.e, here, it won't call Derived1's overridden showMsg()
//						//but Derived2's overridden showMsg(), i.e, here also runtime polymorphism is exhibited. (Remove 'virtual' from Base::showMsg() then
//						//run this program and see it urself).
//}


//_____________________________________________________The virtual attribute is inherited_________________________________________________________________

//class Base
//{
//public:
//	virtual void Foo()
//	{
//		cout << "Base::Foo()" << endl;
//	}
//};
//
//class Base1 : public Base
//{
//public:
//	void Foo()
//	{
//		cout << "Base1::Foo()" << endl;
//	}
//};
//
//class Derived : public Base1
//{
//public:
//	/*void Foo()
//	{
//		cout << "Derived::Foo()" << endl;
//	}*/
//};
//
//
//
//int main()
//{
//	Base1 *b1p, b1o;
//
//	b1p = &b1o;
//	b1p->Foo();
//
//	Derived d_o;
//	
//	b1p = &d_o;
//	b1p->Foo();		//Try this with uncommented Derived::Foo() too.
//
//	b1p->Base::Foo();
//}