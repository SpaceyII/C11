#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <string>

using namespace std;

namespace NumberAlgm
{
	//已知先序遍历和中序遍历求后序遍历 如先序ABC，中序BAC, 求得后序BCA
	string postOrder(string inOrder, string preOrder);
}

#endif