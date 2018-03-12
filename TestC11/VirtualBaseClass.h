#ifndef __VIRTUAL_BASE_CLASS__
#define __VIRTUAL_BASE_CLASS__

/*�����ĳ�ʼ����һ���̳еĳ�ʼ�����﷨����һ���ģ������캯���ĵ��ô���ͬ�������๹�캯���ĵ��ô���������ԭ��:
(1)�����Ĺ��캯���ڷ������֮ǰ����;
(2)��ͬһ����а����������࣬��Щ�����Ĺ��캯��������˵���Ĵ������;
(3)��������ɷ���������������������ȵ��û��๹�캯�����ٵ���������Ĺ��캯

�������Ҫ����ڶ��ؼ̳�ʱ��������ܱ���μ̳У��������Ҫ�ṩһ�������������*/

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