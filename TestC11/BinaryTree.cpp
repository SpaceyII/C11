#include "stdafx.h"
#include "BinaryTree.h"

#include <vector>
#include <iostream>

//�㷨ʵ�֣���Ҫ�ݹ飬����ȷ���нڵ�����Ҳ��֣�preOrder�ĵ�һ���������ڵ㣬inOrder�����ڵ��������ߵľ�������Ҳ���
string postOrder(string inOrder, string preOrder)
{
	if (inOrder.size() == 1 || preOrder.size() == 1)
		return inOrder;
	if (inOrder.size() == 0 || preOrder.size() == 0)
		return "";

	size_t posNode;
	string subInL(""), subInR(""), subPreL(""), subPreR("");
	if (std::string::npos == inOrder.find(preOrder.at(0)))
	{
		cout << preOrder.at(0) << endl;
		return "";
	}
	posNode = inOrder.find(preOrder.at(0));
	
	//���ҳ�����InOrder����ߺ��ұߵĲ��֣����ҳ���������ߺ��ұߵĲ���
	cout << "InOrder: " << inOrder << " PreOrder:" << preOrder << endl;
	subInL = inOrder.substr(0, posNode);
	subInR = inOrder.substr(posNode + 1, inOrder.size() - posNode);
	cout << posNode << " subInL: " << subInL << " subInR: " << subInR << endl;
	
	subPreL = preOrder.substr(1, posNode);
	subPreR = preOrder.substr(posNode + 1, preOrder.size() - posNode);
	cout << posNode << " subPreL: " << subPreL << " subPreR: " << subPreR << endl;
	
	return postOrder(subInL, subPreL) + postOrder(subInR, subPreR) + preOrder.at(0);
}