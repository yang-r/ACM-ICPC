#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct Tree//字典树 
{
	int fail;//失配指针
	int nex[26];//子节点的位置
	int end;//标记有几个单词以这个节点结尾 
}AC[1000000];//Trie树
int cnt = 0;//Trie的指针 
inline void Build(string s)
{
	int l = s.length();
	int now = 0,id;//字典树的当前指针 
	for (int i = 0; i<l; ++i)//构造Trie树
	{
		id= s[i] - 'a';
		if (AC[now].nex[id] == 0)//Trie树没有这个子节点
			AC[now].nex[id] = ++cnt;//构造出来
		now = AC[now].nex[id];//向下构造 
	}
	AC[now].end += 1;//标记单词结尾 
}
void Get_fail()//构造fail指针
{
	queue<int> Q;//队列 
	for (int i = 0; i<26; ++i)//第二层的fail指针提前处理一下
	{
		if (AC[0].nex[i] != 0)
		{
			AC[AC[0].nex[i]].fail = 0;//指向根节点
			Q.push(AC[0].nex[i]);//压入队列 
		}
	}
	while (!Q.empty())//BFS求fail指针 
	{
		int u=Q.front();
		Q.pop();
		for (int i = 0; i<26; ++i)//枚举所有子节点
		{
			if (AC[u].nex[i] != 0)//存在这个子节点
			{
				AC[AC[u].nex[i]].fail = AC[AC[u].fail].nex[i];
				//子节点的fail指针指向当前节点的
				//fail指针所指向的节点的相同子节点 
				Q.push(AC[u].nex[i]);//压入队列 
			}
			else//不存在这个子节点 
				AC[u].nex[i] = AC[AC[u].fail].nex[i];
			//当前节点的这个子节点指向当
			//前节点fail指针的这个子节点 
		}
	}
}
int AC_Query(string s)//AC自动机匹配
{
	int l = s.length();
	int now = 0, ans = 0;
	for (int i = 0; i<l; ++i)
	{
		now = AC[now].nex[s[i] - 'a'];//向下一层
		for (int t = now; t&&AC[t].end != -1; t = AC[t].fail)//循环求解
		{
			ans += AC[t].end;
			AC[t].end = -1;
		}
	}
	return ans;
}
int main()
{
	int n;
	string s;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s;
		Build(s);
	}
	AC[0].fail = 0;//结束标志 
	Get_fail();//求出失配指针
	cin >> s;//文本串 
	cout << AC_Query(s) << endl;
	return 0;
}
