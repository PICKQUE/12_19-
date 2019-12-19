#include "head.h"

int main()
{
	int n1 = 0; //多项式1的项数
	int n2 = 0; //多项式2的项书
	MathNode express1;  //多项表达式1
	MathNode express2;  //多项表达式2
	initLinkList(&express1);
	initLinkList(&express2);

	cout << "多项式1的项数:";
	cin >> n1;
	cout << "多项式2的项数:";
	cin >> n2;
	cout << "请为两个多项式赋值:" << endl;
	setExpressValue(&express1, n1);
	setExpressValue(&express2, n2);

	//printLinkList(&express1);

	cout << "\n排序" << endl;
	sortByCoef(&express1, n1);
	sortByCoef(&express2, n2);
	printLinkList(&express1);
	printLinkList(&express2);

	cout << "\n 多项式相加:" << endl;
	MathNode* addRetLinkList = addLinkList(&express1, &express2);
	MathNode* pCur = addRetLinkList->_next;
	while (pCur != nullptr)
	{
		cout << pCur->coef << " ";
		pCur = pCur->_next;
	}
	system("pause");
	return 0;
}