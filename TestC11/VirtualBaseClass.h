#ifndef __VIRTUAL_BASE_CLASS__
#define __VIRTUAL_BASE_CLASS__

#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout << "A constructor!" << endl;
	}
};

class B
{
public:
	B()
	{
		cout << "B constructor!" << endl;
	}
};

class C
{
public:
	C()
	{
		cout << "C constructor!" << endl;
	}
};

class E : public C
{
public:
	E()
	{
		cout << "E constructor!" << endl;
	}
};

class D : public A, public B, virtual public E
{
public:
	D()
	{
		cout << "D constructor!" << endl;
	}
};

#endif