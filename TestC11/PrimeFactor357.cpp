#include "stdafx.h"

#include "PrimeFactor357.h"
#include <vector>
#include <iostream>

using namespace std;

int getKNum(int k)
{
	auto minFunc = [=](int c1, int c2) -> int {return c1 < c2 ? c1 : c2; };
	int k3(0), k5(0), k7(0);
	vector<int> vec(k+1, 1);

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