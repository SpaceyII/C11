// TestC11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "TestC11.h"
#include "Count2Num.h"
#include "BinaryTree.h"
#include "PrimeFactor357.h"

using namespace std;

int nthUglyNumber(int n) {
	vector<int> vec(n+1, 1);
	int fac3Ind = 0;
	int fac5Ind = 0;
	int fac7Ind = 0;
	int start = 1;
	while (start <= n){
		vec[start] = min(vec[fac3Ind] * 3, min(vec[fac5Ind] * 5, vec[fac7Ind] * 7));
		if (vec[start] == vec[fac3Ind] * 3)
			fac3Ind++;
		if (vec[start] == vec[fac5Ind] * 5)
			fac5Ind++;
		if (vec[start] == vec[fac7Ind] * 7)
			fac7Ind++;
		start++;
	}
	return vec[n];
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Test C11
//	testC11();

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
//	cout << "PostOrder is " << postOrder("CBDAEF", "ABCDEF") << endl;;

	//Ugly Unmber 3/5/7
	cout << getKNum(4) << endl;
	//cout << getKNum(1) << '\t' << getKNum(2) << '\t' << getKNum(3) << '\t' << getKNum(4) << '\t' << getKNum(5) << endl;

	cout << nthUglyNumber(4) << endl;

	return 0;
}

