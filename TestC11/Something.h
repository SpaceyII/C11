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
	virtual ~Parent() { cout << "1"; }  //�������Ϊ��������ֹ�ڴ�й©
};

class Child : public Parent
{
public:
	Child() { cout << "3"; }
	~Child() { cout << "3"; }   //���ϲ���������������Ѿ�Ϊ�麯���ˣ�����������һ��Ϊvirtual���Եģ�������������Ҳ�ɲ�����
protected:
	Something mData;
};


#endif