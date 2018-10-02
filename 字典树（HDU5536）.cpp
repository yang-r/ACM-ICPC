/*
HDU  5536
求最大异或值max （a1+a2）a3
三个数不相同 
*/ 

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const MAX = 1e5;
int a[MAX];

struct Trie
{
	int root, tot, next[MAX][2], cnt[MAX], end[MAX];

	inline int Newnode()
	{
		memset(next[tot], -1, sizeof(next[tot]));
		cnt[tot] = 0;
		end[tot] = 0;
		return tot++;//节点值 
	}

	inline void Init()
	{
		tot = 0;
		root = Newnode();
	}

	inline void Insert(int x)
	{
		int p = root;
		cnt[p] ++;
		for (int i = 31; i >= 0; i--)
		{
			int idx = ((1 << i) & x) ? 1 : 0;
			if (next[p][idx] == -1)
				next[p][idx] = Newnode();
			p = next[p][idx];
			cnt[p] ++;  //出现次数
		}
		end[p] = x;//存值
	}

	inline void Del(int x)
	{
		int p = root;
		cnt[p] --;
		for (int i = 31; i >= 0; i--)
		{
			int idx = ((1 << i) & x) ? 1 : 0;
			p = next[p][idx];
			cnt[p] --;
		}
	}

	inline int Search(int x)
	{
		int p = root;
		for (int i = 31; i >= 0; i--)
		{
			int idx = ((1 << i) & x) ? 1 : 0;
			if (idx == 0)
			{
				if (next[p][1] != -1 && cnt[next[p][1]])
					p = next[p][1];
				else
					p = next[p][0];
			}
			else
			{
				if (next[p][0] != -1 && cnt[next[p][0]])
					p = next[p][0];
				else
					p = next[p][1];
			}
		}
		return x ^ end[p];
	}
}tr;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		tr.Init();
		int n, ma = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			tr.Insert(a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			tr.Del(a[i]);
			for (int j = i + 1; j < n; j++)
			{
				
				tr.Del(a[j]);
				ma = max(ma, tr.Search(a[i] + a[j]));
			
				tr.Insert(a[j]);
			}
			tr.Insert(a[i]);
		}
		printf("%d\n", ma);
	}
}

