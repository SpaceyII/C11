#ifndef _HEADER_H_
#define _HEADER_H_

/* ���δ����Ŀ�����ڵ������������������������ʱ���ڼ̳��������ĸ��������ڴ�й©�����*/
/* ǿ�ҽ������е����������������������������*/

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