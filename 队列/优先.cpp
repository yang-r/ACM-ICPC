#include<queue>
#include<stdio.h>
#include<iostream>
#include<functional>
using namespace std;
//当访问元素时，具有最高优先级的元素最先删除。
优先队列具有最高级先出 （first in, largest out）的行为特征。
//默认从大到小自动排序 
struct cmp {//运算符重载
	bool operator ()(int &a, int &b) {
		return a<b;//最大值优先
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
 /*        迷宫 
struct node
{
	int sx, sy, step;
	friend bool operator <(const node &s1, const node &s2)
	{
		return s1.step>s2.step; //s2сеох  
	}
};
*/
