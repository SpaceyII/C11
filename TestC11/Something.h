#ifndef _HEADER_H_
#define _HEADER_H_

/* 本段代码的目的在于当类的析构函数不是虚析构的时候，在继承与派生的各类会造成内存泄漏的情况*/
/* 强烈建议所有的类的析构函数声明成虚析构函数*/

#include <iostream>

using namespace std;

class Something
{
public:
	Something() { cout << "2";  }
	virtual ~Something() { cout << "2"; }
};

class Parent
{
public:
	Parent() { cout << "1"; }
	virtual ~Parent() { cout << "1"; }
};

class Child : public Parent
{
public:
	Child() { cout << "3"; }
	virtual ~Child() { cout << "3"; }
protected:
	Something mData;
};


#endif