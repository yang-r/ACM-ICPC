#include<queue>
#include<stdio.h>
#include<iostream>
#include<functional>
using namespace std;
//������Ԫ��ʱ������������ȼ���Ԫ������ɾ����
���ȶ��о�����߼��ȳ� ��first in, largest out������Ϊ������
//Ĭ�ϴӴ�С�Զ����� 
struct cmp {//���������
	bool operator ()(int &a, int &b) {
		return a<b;//���ֵ����
	}
};

int main() {
	int	a[10] = { 9,4,10,2,1,3,5,4,6,1};
	
	priority_queue<int>q;
	priority_queue<int,vector<int>,greater<int> >qq;
	priority_queue<int, vector<int>, cmp>q1;
	for (int i = 0; i <= 9; i++) {
		q.push(a[i]);
		qq.push(a[i]);
		q1.push(a[i]);
	}
	for (int i = 0; i<10; i++){
		printf("%3d", q.top());
		q.pop();
		printf("\n");
		printf("%d", qq.top());
		printf("\n");
		qq.pop();
		printf("%5d\n", q1.top());
		q1.pop();
	}
	system("pause");
	return 0;
}
 /*        �Թ� 
struct node
{
	int sx, sy, step;
	friend bool operator <(const node &s1, const node &s2)
	{
		return s1.step>s2.step; //s2��֧��  
	}
};
*/
