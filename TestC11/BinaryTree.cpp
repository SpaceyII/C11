#include "stdafx.h"
#include "BinaryTree.h"

#include <vector>
#include <iostream>

namespace NumberAlgm
{
	//算法实现：需要递归，首先确定中节点和左右部分，preOrder的第一个就是主节点，inOrder在主节点左右两边的就是左和右部分
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

		//先找出中序InOrder中左边和右边的部分，再找出先序中左边和右边的部分
		cout << "InOrder: " << inOrder << " PreOrder:" << preOrder << endl;
		subInL = inOrder.substr(0, posNode);
		subInR = inOrder.substr(posNode + 1, inOrder.size() - posNode);
		cout << posNode << " subInL: " << subInL << " subInR: " << subInR << endl;

		subPreL = preOrder.substr(1, posNode);
		subPreR = preOrder.substr(posNode + 1, preOrder.size() - posNode);
		cout << posNode << " subPreL: " << subPreL << " subPreR: " << subPreR << endl;

		return postOrder(subInL, subPreL) + postOrder(subInR, subPreR) + preOrder.at(0);
	}
}