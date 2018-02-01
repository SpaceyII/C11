// TestC11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <list>

#include <atomic>
#include <thread>

#include <numeric>
#include <algorithm>
#include <functional>

#include "ComplexNum.h"
#include "Count2Num.h"

#include "Something.h"
#include "MyArray.h"

using namespace std;
//谓词函数
bool high5Num(int num){ return (num > 5); }

typedef int u32;

//<antId, lcrId>
std::map<int, std::list<int> > _antCells;

int opGetNumberOfCellsOnAntenna(int antId) {
	return _antCells[antId].size();
}

//Callback 函数 - 系统调用的函数
void testCallback(const vector<int>& vec, const function<bool(int)>& callback)
{
	for (auto i : vec)
	{
		if (!callback(i))
			break;
		cout << i << ' ';
	}
	cout << endl;
}

void func(int num, const string& str)
{
	cout << "func(" << num << ", " << str << ")" << endl;
}

void funcX(int counter) //atomic<int>& counter)
{
	for (int i = 0; i < 10000; ++i)
		++counter;
	cout << "Result = " << counter << endl;
}

void testC11()
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
	/*	int num;
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
	*/
	/********************************************************************/
	/********************************************************************/
	//C++ 11 general initialization 统一初始化
	vector<int> v1 = { 1, 3, 5, 7, 9, 11 };

	//连乘 with Lamda expression
	int res = accumulate(v1.begin(), v1.end(), 1, [](int n1, int n2){return n1*n2; });
	cout << " The result is : " << res << endl;

	/********************************************************************/
	/********************************************************************/
	cout << "\n\n\n\n\n" << endl;

	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	//测试项目代码
	cout << "Part 1" << endl;

	_antCells[40400].push_back(27001);
	_antCells[40402].push_back(27001);

	_antCells[40400].push_back(27002);
	_antCells[40402].push_back(27002);

	_antCells[40400].push_back(27003);
	_antCells[40402].push_back(27003);

	_antCells[40400].push_back(27004);
	_antCells[40402].push_back(27004);

	bool isFirstCellOnAntenna = (0 == opGetNumberOfCellsOnAntenna(40400));
	cout << isFirstCellOnAntenna << endl;

	auto itx = _antCells.begin();
	auto itx2 = (itx->second).begin();

	cout << itx->first << '\t' << *itx2 << endl;   //输出40400 27001

	cout << "Part 1 End " << endl;
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	//测试项目代码
	cout << "Part 2" << endl;
	list<pair<int, int> > cellList;

	cellList.push_back(make_pair(27001, 40400));
	cellList.push_back(make_pair(27002, 40400));
	cellList.push_back(make_pair(27003, 40400));
	cellList.push_back(make_pair(27004, 40400));

	cellList.push_back(make_pair(27001, 40402));
	cellList.push_back(make_pair(27002, 40402));
	cellList.push_back(make_pair(27003, 40402));
	cellList.push_back(make_pair(27004, 40402));

	cout << " Before: " << endl;
	for (auto itx3 = cellList.begin(); itx3 != cellList.end(); ++itx3)
	{
		cout << itx3->first << '\t' << itx3->second << endl;
	}

	cellList.sort();
	cout << " After: " << endl;
	for (auto itx3 = cellList.begin(); itx3 != cellList.end(); ++itx3)
	{
		cout << itx3->first << '\t' << itx3->second << endl;
	}

	if (!(_antCells.empty() && cellList.empty()))
	{
		cout << "两个至少有一个不为空~ " << _antCells.empty() << cellList.empty() << endl;
	}
	else
	{
		cout << "两个都为空~ " << endl;
	}

	cout << "Part 2 End " << endl;
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	//测试项目代码
	cout << "Part 3" << endl;
	u32 idBALcrs[] = { 1, 2, 3, 4, 9, 10, 11, 12, 5, 6, 7, 8 }; // cell unit ids for expected missing BranchActivation licenses RnD faults
	u32 idBAAnts[] = { 40400, 40912, 40656 }; // antennas unit ids for expected missing BranchActivation licenses customer faults (EFaultId_MissingLicenseAl)
	set<u32> idBASet(idBALcrs, idBALcrs + sizeof(idBALcrs) / sizeof(idBALcrs[0]));
	set<u32> idBACustomerSet(idBAAnts, idBAAnts + sizeof(idBAAnts) / sizeof(idBAAnts[0]));

	for (auto i1 = idBASet.begin(); i1 != idBASet.end(); ++i1)
	{
		cout << *i1 << endl;
	}

	for (auto i1 = idBACustomerSet.begin(); i1 != idBACustomerSet.end(); ++i1)
	{
		cout << *i1 << endl;
	}

	cout << "Part 3 End " << endl;
	///////////////////////////////////////////////////////////////////////
	cout << "Part 4" << endl;
	//test callback 功能
	vector<int> vec(10);
	int index = 0;
	generate(vec.begin(), vec.end(), [&index]{return ++index; });
	for_each(vec.begin(), vec.end(), [](int i){cout << i << ' '; });
	cout << endl;
	testCallback(vec, [](int i){return i < 6; });

	int cnt = count_if(vec.begin(), vec.end(), [=](int i){return i >= 6; });
	cout << "Find " << cnt << " numbers more than 5~" << endl;

	cout << "Part 4 End " << endl;
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	cout << "Part 5" << endl;
	//Test Bind, not1, men_fn()
	string str = "Bind Fix";
	auto f1 = bind(func, placeholders::_1, str);
	f1(1);
	auto f2 = bind(func, placeholders::_2, placeholders::_1);
	f2(str, 2);

	auto endx = idBASet.end();
	auto resx = find_if(idBASet.begin(), endx, bind(greater_equal<u32>(), placeholders::_1, 10));
	if (resx == endx)
	{
		cout << "No Result~" << endl;
	}
	else
	{
		cout << "Find a \"L10\" num of " << *resx << endl;
	}

	resx = find_if(idBASet.begin(), endx, [=](int i)->bool{return i == 10; });
	if (resx == endx)
	{
		cout << "No Result~" << endl;
	}
	else
	{
		cout << "Find a non \"L10\" num of " << *resx << endl;
	}


	vector<string> svec = { "1", "2", "3", "4", "", "6" };
	auto endx1 = svec.end();
	auto res1 = find_if(svec.begin(), endx1, mem_fn(&string::empty));
	if (res1 != endx1)
	{
		cout << "Empty str pos: " << res1 - svec.begin() << endl;
	}


	cout << "Part 5 End " << endl;
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	cout << "Part 6" << endl;
	//Test function template
	ComplexNum<int> i3, i1{ 5, 6 }, i2{ 3, 4 };  //Template instantiate~
	i1.print();
	i2.print();
	i3.print();

	i1 = i1 + i2;
	i1.print();


	cout << "Part 6 End " << endl;
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	/********************************************************************/
	/********************************************************************/
	//测试多线程和原子操作
	atomic<int> counter = { 0 };
	vector<thread> thr;
	for (int i = 0; i < 10; ++i)
		thr.push_back(thread(funcX, std::ref(counter)));

	for (auto& t : thr)
		t.join();


	/********************************************************************/
	/********************************************************************/
	//测试stringstream
	for (int i = 1970; i <= 1980; ++i)
	{
		char cSet = '/';
		std::stringstream dateStream;
		dateStream << "01" << cSet << "01" << cSet << i;

		cout << dateStream.str() << endl;
	}
	const std::string buildDate1("01/01/1995");
	cout << buildDate1 << endl;

	return;
}

