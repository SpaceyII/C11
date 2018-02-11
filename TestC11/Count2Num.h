#ifndef __COUNT2NUM_H__
#define __COUNT2NUM_H__

namespace NumberAlgm
{
	//计算0-n之间每个数中出现2的个数总和
	//比如输入13 （不包含13，包含13的情况）（0，1，2，3，4，5，6，7，8，9，10，11，12）
	//输出位2 （2和12包含两个2）
	int count2Num(int num);

	void test();
}

#endif