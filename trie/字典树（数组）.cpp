#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int root, sign;
int str[100005][10], vis[100005];
char s[15];
void insert(char *s, int v) {
	int u, ans;
	u = ans = 0;
	for (; *s; s++) {
		if (!str[u][*s - '0']) {
			str[u][*s - '0'] = root++;
			ans++;
		}
		else
			if (vis[str[u][*s - '0']] != 0)  //在移动的过程中看是否有过字符串是这个串的前缀
				sign = 1;
		u = str[u][*s - '0'];
	}
	if (!ans)                        //这种就是前缀后出现时，走的全是别的字符串走过的路径时
		sign = 1;
	vis[u] = v;    //尾节点编号
}                                   //静态字典树模板
int main() {
	int n, i, t;
	scanf("%d", &t);
	while (t--) {
		root = 1;
		sign = 0;
		scanf("%d", &n);
		memset(str, 0, sizeof(str));
		memset(vis, 0, sizeof(vis));
		for (i = 1; i <= n; i++) {
			cin >> s;
			if (sign)              //如果已经确认存在前缀的话就不用继续插入了
				continue;
			insert(s, i);
		}
		if (sign)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
/*
#include<iostream>
#include<cstring>
#include<cstdio>
#pragma warning (disable :4996);
#define N 100010
using namespace std;

struct Trie
{
	struct node { int size, ch[10], t; }T[N << 5];
	int tot, root;

	void init()
	{
		tot = root = 1;
		memset(T, 0, sizeof(T));
	}

	void ins(char* x, int t)					//t为时间戳
	{
		int o = root;
		cout << "t o  " << t << " " << o;
		if (T[o].t != t) { T[o].size++; T[o].t = t; }			//如果时间戳不相同则增加，否则不
		for (int k = 0; k<strlen(x); k++)
		{
			int c = x[k] - 48;
			if (!T[o].ch[c]) T[o].ch[c] = ++tot;
			o = T[o].ch[c];
			if (T[o].t != t) { T[o].size++; T[o].t = t; }
		}
		cout << " tail: " << T[o].size << endl;
	}

	int query(char* x)
	{
		int o = root;
		for (int k = 0; k<strlen(x); k++)
		{
			int c = x[k] - 48;
			o = T[o].ch[c];
		}
		for (int i = 0; i < strlen(x); i++) {
			cout << x[i];
		}
		cout << endl;
		cout <<"querry T[o].size " <<" x: "<< T[o].size << endl;
		return T[o].size;
	}
} Trie;

char str[N][10], s[10];
int n;

int main()
{
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i]);
		for (int j = 0; j<strlen(str[i]); j++)
		{
			strcpy(s, str[i] + j);	
			cout << " s:"<<s << endl;//把每一位到最后的子串加到字典树中
			Trie.ins(s, i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		bool flag = 0;
		for (int len = 1; len <= strlen(str[i]); len++)
		{
			for (int b = 0; b + len - 1<strlen(str[i]); b++)
			{
				memset(s, 0, sizeof(s));
				for (int j = 0; j<len; j++)
					s[j] = str[i][j + b];						
				//暴力枚举特征码，从短的开始枚举
				if (Trie.query(s) == 1) {
					flag = 1; 
					break;
				}			
				//如果只出现一次，那么合法，直接输出
			}
			if (flag) { printf("ans :%s\n", s); break; }
		}
	}
	return 0;
}
*/ 

