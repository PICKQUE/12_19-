/********************
//	该程序完成一元多项式的运算，
//	利用单链表，实现相应的操作
//	先手动地为多项式赋值，最后通过排序，将多项式排序为有序多项式再进行计算
********************/
#include <iostream>

using namespace std;

//节点类， 3, 1 ===> 3x
typedef struct MathNode{
	int coef; //系数
	int exp; //指数
	struct MathNode* _next;
} MathNode;

//初始化
void initLinkList(MathNode* pHead)
{
	pHead->_next = nullptr;
	cout << "多项式初始化成功!" << endl;
}

//申请新节点
MathNode* buyNewNode()
{
	MathNode* newNode = new MathNode;
	return newNode;
}

//为多项式赋值
void setExpressValue(MathNode* pHead, int n)
{
	if (n == 0)
	{
		cout << "赋值完毕!" << endl;
		return;
	}
	MathNode* pFirst = buyNewNode();
	cout << "系数：";
	cin >> pFirst->coef;
	cout << "指数：";
	cin >> pFirst->exp;
	pHead->_next = pFirst;
	pFirst->_next = nullptr;
	MathNode* pCur = pFirst;
	for (int i = 0; i < n-1; ++i)
	{
		MathNode* newNode = buyNewNode();
		cout << "系数：";
		cin >> newNode->coef;
		cout << "指数：";
		cin >> newNode->exp;
		pCur->_next = newNode;
		newNode->_next = nullptr;
		pCur = pCur->_next;
	}
	pCur->_next = nullptr;
	cout << "赋值完毕!" << endl;
}

//打印多项式
void printLinkList(MathNode* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "链表没有任何元素!" << endl;
		return;
	}
	MathNode* pCur = pHead->_next;
	while (pCur != nullptr)
	{
		cout << pCur->coef << " ";
		pCur = pCur->_next;
	}
}



//根据多项式的指数进行排序
void sortByCoef(MathNode* pHead, int n)
{
	if (pHead->_next == nullptr)
	{
		return;
	}
	//对单链表根据指数的大小进行冒泡排序，使该多项式转换为有序的多项式
	
	

	for (MathNode* p1 = pHead->_next; p1 != nullptr; p1 = p1->_next)
	{
		for (MathNode* p2 = p1->_next; p2 != nullptr; p2 = p2->_next)
		{
			if (p1->exp > p2->exp)
			{
				int tmpCoef = p1->coef;
				int tmpExp = p1->exp;
				p1->coef = p2->coef;
				p1->exp = p2->exp;
				p2->coef = tmpCoef;
				p2->exp = tmpExp;
			}
		}
	}
}

//获取链表的有效元素的长度
/*int getLength(MathNode* pHead)
{
	int len = 0;
	if (pHead->_next == nullptr)
	{
		return 0;
	}
	MathNode* pCur = pHead->_next;
	while (pCur != nullptr)
	{
		++len;
		pCur = pCur->_next;
	}
	return len;
}*/

//多项式相加计算
MathNode* addLinkList(MathNode* pHead1, MathNode* pHead2)
{

	if (pHead1->_next == nullptr)
	{
		return pHead2;
	}
	if (pHead2->_next == nullptr)
	{
		return pHead1;
	}
	if (pHead1->_next == nullptr && pHead2->_next == nullptr)
	{
		return nullptr;
	}
	//多项式均不为空,始终让p1所指的节点的指数为小的

	MathNode* p1 = pHead1->_next;
	MathNode* p2 = pHead2->_next;

	if (p1->exp > p2->exp)
	{
		MathNode* tmp = p1;
		p1 = p2;
		p2 = tmp;
		pHead1->_next = p2;
		pHead2->_next = p1;
	}

	MathNode* p1tmp = nullptr;
	MathNode* p2tmp = nullptr;

	MathNode* newHead = new MathNode();
	newHead->_next = p1;

	while (p1 != nullptr && p2 != nullptr)
	{
		if (p1->exp < p2->exp)
		{
		    p1tmp = p1;
			p1 = p1->_next;
		}
		else if (p1->exp > p2->exp)
		{
			p1tmp->_next = p2;
			p2tmp = p2;
			p2 = p2->_next;
		}
		else
		{
			p1tmp = p1;
			p1->coef = p1->coef + p2->coef;
			if (p2tmp != nullptr)
			{
				p2tmp->_next = p1;
			}
			p1 = p1->_next;
			p2 = p2->_next;
		}
	}
	cout << "相加完毕!" << endl;
	return newHead;
}