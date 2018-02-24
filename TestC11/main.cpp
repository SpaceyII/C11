// TestC11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <string>
#include <iostream>

#include "TestC11.h"
#include "Count2Num.h"
#include "BinaryTree.h"
#include "PrimeFactor357.h"
#include "VirtualBaseClass.h"

using namespace std;

class AAA
{
public:
	friend ostream& operator<< (ostream& s, const AAA& a);

	static AAA a;
	//AAA ab;   //Error for in-class type
	AAA* ac = nullptr;

	void printB(char B = brand);
private:
	static const char brand = 'A';
	//static const string addr("China"); //error
	//static const char addr[] = "China";  //error
	//static const char* pLOC("China");  //error
	const int iAa = 3;
};

ostream& operator<< (ostream& s, const AAA& a)
{
	return s << "[Info]Brand: " << a.brand << " iAa Info:" << a.iAa << std::endl;
}

namespace blip
{
	int bi = 1, bj = 2, bk = 3;
}

void func1()
{
	using namespace blip;
	++bi;
	++bj;
	++bk;
	cout << bi << '\t' << bj << '\t' << bk << endl;
}

void func2()
{
	using namespace blip;
	++bi;
	++bj;
	++bk;
	cout << bi << '\t' << bj << '\t' << bk << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Test C11
	testC11();

	//Test algorithm
//	test();
/*	int i = count2Num(45);
	cout << "45 -> i = " << i << endl;
	int k = count2Num(233);
	cout << "233 -> k = " << k << endl;
	k = count2Num(1000);
	cout << "1000 -> k = " << k << endl;
	k = count2Num(12345);
	cout << "999 -> k = " << k << endl;
*/
	//Test Binary Tree
//	cout << "PostOrder is " << NumberAlgm::postOrder("CBDAEF", "ABCDEF") << endl;;

	//Ugly Unmber 3/5/7
	cout << NumberAlgm::getKNum(1) << '\t' << NumberAlgm::getKNum(2) << '\t' << NumberAlgm::getKNum(3) << '\t' << NumberAlgm::getKNum(4) << '\t' << NumberAlgm::getKNum(5) << endl;

	cout << NumberAlgm::nthUglyNumber(4) << endl;

	//Test Vector capacity
	vector<int> v(24, 1);
	for (int i = 0; i < 10; ++i)
		v.push_back(i);
	cout << "Vector size: " << v.size() << " Max Size: " << v.max_size() << " Capacity: " << v.capacity() << endl;
	cout << std::setfill('0') << std::setw(10) << 30843 << endl;

	//test AAA
	AAA a = AAA();
	cout << a;

	func1();
	func2();
	++blip::bi;
	cout << blip::bi << '\t' << blip::bj << '\t' << blip::bk << endl;
	
	//即使是C类在派生列表的最后，类C也是首先构造，因为C为虚基类。但是如果虚基类还有一个基类而且该基类不是虚基类，则必须先构造基类
	//虽然E是虚基类而C不是，但是还是先构造了C，因为C是E的基类，在构造一个类之前，必须先构造基类，即使是虚继承也不例外。
	D d;

	return 0;
}

