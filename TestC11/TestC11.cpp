// TestC11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include <numeric>

#include "Something.h"
#include "MyArray.h"

using namespace std;
bool high5Num(int num){ return (num > 5); }

int _tmain(int argc, _TCHAR* argv[])
{
	/********************************************************************/
	/********************************************************************/
	//测试虚析构函数
	Parent* ptr = new Child();
	delete ptr;

	/********************************************************************/
	/********************************************************************/
	//使用类模板
	MyArray<int> arrInt(10);
	cout << "\n\nArray size: " << arrInt.getSize() << endl;
	arrInt.at(3) = 42;
	cout << "arrInt[3] = " << arrInt.at(3) << endl;

	try
	{
		arrInt.at(10) = 3;
	}
	catch (const exception& e)
	{
		cout << "Caught exception: '" << e.what() << "'" << endl;
	}

	//使用类模板
	MyArray<string> arrStr(5);
	cout << "\n\nArray size: " << arrStr.getSize() << endl;
	arrStr.at(3) = "This is a test";
	cout << "arrStr[3] = " << arrStr.at(3) << endl;

	try
	{
		arrStr.at(10) = 3;
	}
	catch (const exception& e)
	{
		cout << "Caught exception: '" << e.what() << "'" << endl;
	}

	/********************************************************************/
	/********************************************************************/
	//测试STL里面基本find() find_if() accumulate()算法
	int num;
	vector<int> myVec;
	while (true)
	{
		cout << "Enter a number to add (0 to stop):";
		cin >> num;
		if (num == 0)
		{
			break;
		}
		myVec.push_back(num);
	}

	//find algorithm
	cout << "Enter a number to lookup (0 to stop): ";
	cin >> num;

	auto end = myVec.end(); //vector<int>::iterator end = myVec.end();
	auto it = find(myVec.begin(), end, num);
	if (it == end)
	{
		cout << "find: Could not find " << num << endl;
	}
	else
	{
		cout << "find: Found" << *it << endl;
	}

	//find_if algorithm
	//it = find_if(myVec.begin(), myVec.end(), high5Num);
	it = find_if(myVec.begin(), myVec.end(), [](int i){return i > 5; });
	if (it == end)
	{
		cout << "find_if: No number higher than 5 " << endl;
	}
	else
	{
		cout << "find_if: The first num higher than 5: " << *it << endl;
	}

	/********************************************************************/
	/********************************************************************/
	//C++ 11 initialization
	vector<int> v1 = { 1, 3, 5, 7, 9, 11 };

	//连乘 with Lamda expression
	int res = accumulate(v1.begin(), v1.end(), 1, [](int n1, int n2){return n1*n2; });
	cout << " The result is : " << res << endl;


	return 0;
}

