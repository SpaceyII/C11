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
	virtual ~Parent() { cout << "1"; }  //基类必须为虚析构防止内存泄漏
};

class Child : public Parent
{
public:
	Child() { cout << "3"; }
	~Child() { cout << "3"; }   //最上层基类中析构函数已经为虚函数了，子类中析构一定为virtual属性的，这边子类可声明也可不声明
protected:
	Something mData;
};


#endif