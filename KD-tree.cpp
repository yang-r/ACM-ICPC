#include<bits/stdc++.h>
#define sq(x) (x)*(x)
#define N (55555)
/*
对于给定的查询点(2,4.5)，我们首先要确定他所在的最小的区域，
显然就是左图左上角那一个矩形的区域。
然后，目前为止我们能够直到的距离查询点最近的点是点(4,7)，
于是我们以这两点之间的距离为半径，
查询点为圆心做一个圆（如果高维那就做超球体）
，判断这个这个最近点的父亲是否在圆内或者圆上。
如果在，那么说明这个它的兄弟所在的区域里面可能会有比它距离查询点更近的点，
所以要对它的兄弟也进行搜索。这样，把所有该搜索的地方都搜索完毕后，
剩下的点就是最邻近的点。如果是求K邻近，那么只需要弄一个优先队列，
里面始终保证有且仅有K个点即可
*/ 
//KD tree     m邻近问题 
//HDU 4347  
using namespace std;

int idx, k, n, m, q;

struct Node
{
	int x[5];
	bool operator < (const Node &u) const
	{
		return x[idx] < u.x[idx];
	}
} P[N];

typedef pair<double, Node> PDN;
priority_queue<PDN> que;

struct KD_Tree
{
	int sz[N << 2]; Node p[N << 2];

	void build(int i, int l, int r, int dep)
	{
		if (l>r) return;
		int mid = (l + r) >> 1;
		idx = dep % k; sz[i] = r - l;
		sz[i << 1] = sz[i << 1 | 1] = -1;
		nth_element(P + l, P + mid, P + r + 1);
		p[i] = P[mid];
		build(i << 1, l, mid - 1, dep + 1);
		build(i << 1 | 1, mid + 1, r, dep + 1);
	}

	void query(int i, int m, int dep, Node a)
	{
		if (sz[i] == -1) return;
		PDN tmp = PDN(0, p[i]);
		for (int j = 0; j<k; j++)
			tmp.first += sq(tmp.second.x[j] - a.x[j]);
		int lc = i << 1, rc = i << 1 | 1, dim = dep % k, flag = 0;
		if (a.x[dim] >= p[i].x[dim]) swap(lc, rc);
		if (~sz[lc]) query(lc, m, dep + 1, a);
		if (que.size()<m) que.push(tmp), flag = 1;
		else
		{
			if (tmp.first<que.top().first) que.pop(), que.push(tmp);
			if (sq(a.x[dim] - p[i].x[dim])<que.top().first) flag = 1;
		}
		if (~sz[rc] && flag) query(rc, m, dep + 1, a);
	}
} KDT;

int main()
{
	while (~scanf("%d%d", &n, &k))
	{
		for (int i = 0; i<n; i++)
			for (int j = 0; j<k; j++)
				scanf("%d", &P[i].x[j]);
		KDT.build(1, 0, n - 1, 0);
		scanf("%d", &q);
		while (q--)
		{
			Node now;
			for (int i = 0; i<k; i++)
				scanf("%d", &now.x[i]);
			scanf("%d", &m); int t = 0;
			KDT.query(1, m, 0, now); Node pp[21];
			for (; !que.empty(); que.pop())
				pp[++t] = que.top().second;
			printf("the closest %d points are:\n", t);
			for (int i = m; i>0; i--)
			{
				printf("%d", pp[i].x[0]);
				for (int j = 1; j<k; j++)
					printf(" %d", pp[i].x[j]);
				puts("");
			}
		}
	}

	return 0;

}
