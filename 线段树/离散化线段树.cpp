#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct point {
	int l, r;
	int mark, sum;
};
point tree[10001 * 4 * 4], num[10001 * 4];
int ans, res[10001 * 4], visit[10001 * 4];
void build(int i, int left, int right)
{
	tree[i].l = left, tree[i].r = right;
	tree[i].mark = tree[i].sum = 0;
	if (left == right) return;  //赋值完成 
	int mid = (left + right) / 2;
	build(i * 2, left, mid);
	build(i * 2 + 1, mid + 1, right);
}
void update(int i, int left, int right, int val)
{
	if (left <= tree[i].l&&tree[i].r <= right) { tree[i].mark = tree[i].sum = val; return; }
	if (tree[i].mark)
	{
		tree[i * 2].mark = tree[i * 2 + 1].mark = tree[i].mark;
		tree[i * 2].sum = tree[i * 2 + 1].sum = tree[i].mark;
		tree[i].mark = 0;
	}
	int mid = (tree[i].r + tree[i].l) / 2;
	//此时的mid取决于i所以要判断mid>left，right<= 的情况。
	if (left>mid) update(i * 2 + 1, left, right, val);
	else if (right <= mid) update(i * 2, left, right, val);
	else
	{
		update(i * 2, left, mid, val);
		update(i * 2 + 1, mid + 1, right, val);
	}
}

//查找
int find(int i)
{
	if (tree[i].l == tree[i].r)
	{
		if (!visit[tree[i].sum])
		{
			visit[tree[i].sum] = 1;
			++ans;
		}

		return ans;
	}
	if (tree[i].mark)
	{
		tree[i * 2].mark = tree[i * 2 + 1].mark = tree[i].mark;
		tree[i * 2].sum = tree[i * 2 + 1].sum = tree[i].mark;
		tree[i].mark = 0;
	}
	find(i * 2);
	find(i * 2 + 1);
}
int main()
{
	int t, i, n, tn, tn1, powr, powl;
	scanf("%d", &t);

	if (t == 0) return 0;
	while (t--)
	{
		res[0] = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d %d", &num[i].l, &num[i].r);
			if (num[i].l>num[i].r) swap(num[i].l, num[i].r);
			res[++res[0]] = num[i].l;
			res[++res[0]] = num[i].r;
		}
		sort(res + 1, res + res[0] + 1);//排序
		tn1 = tn = unique(res + 1, res + res[0] + 1) - res;//去重 
		for (i = 2; i<tn; i++)//插入数
			if (res[i] - res[i - 1]>1)
				res[tn1++] = res[i] - 1; //每个相邻的差值大于1的时候要插入一个数(就插入x[i]-1好了)
		res[0] = tn1 - 1;//插入后的数据个数
		sort(res + 1, res + res[0] + 1);
		build(1, 1, res[0]);//以新的区间建树
		for (i = 1; i <= n; i++)
		{ 
			powl = lower_bound(res + 1, res + 1 + res[0], num[i].l) - res;//寻找数据离散后对应的值 
			powr = lower_bound(res + 1, res + 1 + res[0], num[i].r) - res;
			update(1, powl, powr, i);
		}
		ans = 0;
		memset(visit, 0, sizeof(visit));
		visit[0] = 1;
		printf("%d\n", find(1));
	}

	return 0;
}
