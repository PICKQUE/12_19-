#include "head.h"

int main()
{
	int n1 = 0; //����ʽ1������
	int n2 = 0; //����ʽ2������
	MathNode express1;  //������ʽ1
	MathNode express2;  //������ʽ2
	initLinkList(&express1);
	initLinkList(&express2);

	cout << "����ʽ1������:";
	cin >> n1;
	cout << "����ʽ2������:";
	cin >> n2;
	cout << "��Ϊ��������ʽ��ֵ:" << endl;
	setExpressValue(&express1, n1);
	setExpressValue(&express2, n2);

	//printLinkList(&express1);

	cout << "\n����" << endl;
	sortByCoef(&express1, n1);
	sortByCoef(&express2, n2);
	printLinkList(&express1);
	printLinkList(&express2);

	cout << "\n ����ʽ���:" << endl;
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