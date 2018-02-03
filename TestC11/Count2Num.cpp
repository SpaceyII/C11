#include "stdafx.h"
#include "Count2Num.h"

#include <iostream>
#include <map>
#include <iterator>
#include <cmath>

using namespace std;

int count2Num(int num)
{
	map<int, int> decom;
	int i = 0;
	int digit = 0;
	int res = 0, tmp = num - 1; //不包括num
	while (tmp >= 10)
	{
		digit = tmp % 10;
		decom.insert(make_pair(i, digit));
		++i;
		tmp /= 10;
	}
	decom.insert(make_pair(i, tmp));

	for (auto itx = decom.rbegin(); itx != decom.rend(); ++itx)
	{
		cout << "  " << itx->first << '\t' << itx->second << endl;
	}

	//比如 233 = 2*100 + 3*10 + 2 = 2*[0-99] + 3 * [0-9] + [3-1] + [200-232] = 2*20 +（ 3*1 + pow(10, 1)）+ 1 +（32+1）= 87
	//[0-99] = 100*2/10=20 (10*10的矩阵，0-9个数字，每个出现概率为相等的，一共100*2个数字再除以10是每个出现概率)，同理[0-999] = 1000*3/10 = 300
	//开头是2的必须得单独计算多出的部分
	for (auto it = decom.rbegin(); it != decom.rend(); ++it) //高位->低位 pair(位置，值)
	{
		if (it->first > 0) //>10
		{
			if (it->second < 2)
			{
				res += 1 * static_cast<int>(pow(10, it->first)) * (it->first) / 10;
			}
			else if (it->second > 2)
			{
				res += (it->second) * static_cast<int>(pow(10, it->first)) * (it->first) / 10 + static_cast<int>(pow(10, it->first));
			}
			else
			{
				res += 2 * static_cast<int>(pow(10, it->first)) * (it->first) / 10 + (num - 1) % (static_cast<int>(pow(10, it->first))) + 1;
			}
		}
		else //(0-9)
		{
			res += 1;
		}
		
	}

	return res;
}

void test()
{
	map<int, int> tm;
	tm[1] = 4;
	tm[2] = 6;
	tm[3] = 2;
	tm.insert(make_pair(4, 6));

	for (auto it = tm.begin(); it != tm.end(); ++it)
	{
		cout << "  " << it->first << '\t' << it->second << endl;
	}
	cout << endl;
	for (auto it = tm.rbegin(); it != tm.rend(); ++it)
	{
		cout << "  " << it->first << '\t' << it->second << endl;
	}
}