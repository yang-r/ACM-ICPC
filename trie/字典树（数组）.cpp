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
			if (vis[str[u][*s - '0']] != 0)  //���ƶ��Ĺ����п��Ƿ��й��ַ������������ǰ׺
				sign = 1;
		u = str[u][*s - '0'];
	}
	if (!ans)                        //���־���ǰ׺�����ʱ���ߵ�ȫ�Ǳ���ַ����߹���·��ʱ
		sign = 1;
	vis[u] = v;    //β�ڵ���
}                                   //��̬�ֵ���ģ��
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
			if (sign)              //����Ѿ�ȷ�ϴ���ǰ׺�Ļ��Ͳ��ü���������
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

	void ins(char* x, int t)					//tΪʱ���
	{
		int o = root;
		cout << "t o  " << t << " " << o;
		if (T[o].t != t) { T[o].size++; T[o].t = t; }			//���ʱ�������ͬ�����ӣ�����
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
			cout << " s:"<<s << endl;//��ÿһλ�������Ӵ��ӵ��ֵ�����
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
				//����ö�������룬�Ӷ̵Ŀ�ʼö��
				if (Trie.query(s) == 1) {
					flag = 1; 
					break;
				}			
				//���ֻ����һ�Σ���ô�Ϸ���ֱ�����
			}
			if (flag) { printf("ans :%s\n", s); break; }
		}
	}
	return 0;
}
*/ 

