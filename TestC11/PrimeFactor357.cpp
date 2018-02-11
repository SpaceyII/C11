#include "stdafx.h"

#include "PrimeFactor357.h"
#include <vector>
#include <iostream>
#include <algorithm> //min max

using namespace std;

namespace NumberAlgm
{
	int getKNum(int k)
	{
		auto minFunc = [=](int c1, int c2) -> int {return c1 < c2 ? c1 : c2; };
		int k3(0), k5(0), k7(0);
		vector<int> vec(k + 1, 1);

		//cout << minFunc(minFunc(56 , 32), 73) << endl;
		for (int index = 1; index <= k; ++index)
		{
			vec[index] = minFunc(vec[k3] * 3, minFunc(vec[k5] * 5, vec[k7] * 7));
			//vec[index] = minFunc(minFunc(vec[k3] * 3, vec[k5] * 5), vec[k7] * 7);
			if (vec[index] == vec[k3] * 3)
				++k3;
			if (vec[index] == vec[k5] * 5)
				++k5;
			if (vec[index] == vec[k7] * 7)
				++k7;
		}

		return vec[k];
	}

	//Copy from Internet
	int nthUglyNumber(int n) {
		vector<int> vec(n + 1, 1);
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
}