/********************
//	�ó������һԪ����ʽ�����㣬
//	���õ�����ʵ����Ӧ�Ĳ���
//	���ֶ���Ϊ����ʽ��ֵ�����ͨ�����򣬽�����ʽ����Ϊ�������ʽ�ٽ��м���
********************/
#include <iostream>

using namespace std;

//�ڵ��࣬ 3, 1 ===> 3x
typedef struct MathNode{
	int coef; //ϵ��
	int exp; //ָ��
	struct MathNode* _next;
} MathNode;

//��ʼ��
void initLinkList(MathNode* pHead)
{
	pHead->_next = nullptr;
	cout << "����ʽ��ʼ���ɹ�!" << endl;
}

//�����½ڵ�
MathNode* buyNewNode()
{
	MathNode* newNode = new MathNode;
	return newNode;
}

//Ϊ����ʽ��ֵ
void setExpressValue(MathNode* pHead, int n)
{
	if (n == 0)
	{
		cout << "��ֵ���!" << endl;
		return;
	}
	MathNode* pFirst = buyNewNode();
	cout << "ϵ����";
	cin >> pFirst->coef;
	cout << "ָ����";
	cin >> pFirst->exp;
	pHead->_next = pFirst;
	pFirst->_next = nullptr;
	MathNode* pCur = pFirst;
	for (int i = 0; i < n-1; ++i)
	{
		MathNode* newNode = buyNewNode();
		cout << "ϵ����";
		cin >> newNode->coef;
		cout << "ָ����";
		cin >> newNode->exp;
		pCur->_next = newNode;
		newNode->_next = nullptr;
		pCur = pCur->_next;
	}
	pCur->_next = nullptr;
	cout << "��ֵ���!" << endl;
}

//��ӡ����ʽ
void printLinkList(MathNode* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "����û���κ�Ԫ��!" << endl;
		return;
	}
	MathNode* pCur = pHead->_next;
	while (pCur != nullptr)
	{
		cout << pCur->coef << " ";
		pCur = pCur->_next;
	}
}



//���ݶ���ʽ��ָ����������
void sortByCoef(MathNode* pHead, int n)
{
	if (pHead->_next == nullptr)
	{
		return;
	}
	//�Ե��������ָ���Ĵ�С����ð������ʹ�ö���ʽת��Ϊ����Ķ���ʽ
	
	

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

//��ȡ�������ЧԪ�صĳ���
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

//����ʽ��Ӽ���
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
	//����ʽ����Ϊ��,ʼ����p1��ָ�Ľڵ��ָ��ΪС��

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
	cout << "������!" << endl;
	return newHead;
}