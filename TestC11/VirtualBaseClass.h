#ifndef __VIRTUAL_BASE_CLASS__
#define __VIRTUAL_BASE_CLASS__

/*虚基类的初始化与一般多继承的初始化在语法上是一样的，但构造函数的调用次序不同。派生类构造函数的调用次序有三个原则:
(1)虚基类的构造函数在非虚基类之前调用;
(2)若同一层次中包含多个虚基类，这些虚基类的构造函数按它们说明的次序调用;
(3)若虚基类由非虚基类派生而来，则仍先调用基类构造函数，再调用派生类的构造函

虚基类主要解决在多重继承时，基类可能被多次继承，虚基类主要提供一个基类给派生类*/

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