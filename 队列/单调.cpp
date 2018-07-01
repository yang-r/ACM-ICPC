
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[200000];
struct node
{
	int x, p;
	node() {}
	node(int xx, int pp) { x = xx; p = pp; }
}list[200000];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int head = 1, tail = 1;
	list[1] = node(a[1], 1);
	for (int i = 2; i <= n; i++)
	{
		while (head <= tail && list[tail].x <= a[i]) tail--;//ɾβ
		list[++tail] = node(a[i], i);//�õ����ŽⲢ����
		while (i - list[head].p >= m) head++;//ȥͷ
		if (i >= m) printf("%d\n", list[head]);
	}
	return 0;
}