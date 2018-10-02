#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct Tree//�ֵ��� 
{
	int fail;//ʧ��ָ��
	int nex[26];//�ӽڵ��λ��
	int end;//����м�������������ڵ��β 
}AC[1000000];//Trie��
int cnt = 0;//Trie��ָ�� 
inline void Build(string s)
{
	int l = s.length();
	int now = 0,id;//�ֵ����ĵ�ǰָ�� 
	for (int i = 0; i<l; ++i)//����Trie��
	{
		id= s[i] - 'a';
		if (AC[now].nex[id] == 0)//Trie��û������ӽڵ�
			AC[now].nex[id] = ++cnt;//�������
		now = AC[now].nex[id];//���¹��� 
	}
	AC[now].end += 1;//��ǵ��ʽ�β 
}
void Get_fail()//����failָ��
{
	queue<int> Q;//���� 
	for (int i = 0; i<26; ++i)//�ڶ����failָ����ǰ����һ��
	{
		if (AC[0].nex[i] != 0)
		{
			AC[AC[0].nex[i]].fail = 0;//ָ����ڵ�
			Q.push(AC[0].nex[i]);//ѹ����� 
		}
	}
	while (!Q.empty())//BFS��failָ�� 
	{
		int u=Q.front();
		Q.pop();
		for (int i = 0; i<26; ++i)//ö�������ӽڵ�
		{
			if (AC[u].nex[i] != 0)//��������ӽڵ�
			{
				AC[AC[u].nex[i]].fail = AC[AC[u].fail].nex[i];
				//�ӽڵ��failָ��ָ��ǰ�ڵ��
				//failָ����ָ��Ľڵ����ͬ�ӽڵ� 
				Q.push(AC[u].nex[i]);//ѹ����� 
			}
			else//����������ӽڵ� 
				AC[u].nex[i] = AC[AC[u].fail].nex[i];
			//��ǰ�ڵ������ӽڵ�ָ��
			//ǰ�ڵ�failָ�������ӽڵ� 
		}
	}
}
int AC_Query(string s)//AC�Զ���ƥ��
{
	int l = s.length();
	int now = 0, ans = 0;
	for (int i = 0; i<l; ++i)
	{
		now = AC[now].nex[s[i] - 'a'];//����һ��
		for (int t = now; t&&AC[t].end != -1; t = AC[t].fail)//ѭ�����
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
	AC[0].fail = 0;//������־ 
	Get_fail();//���ʧ��ָ��
	cin >> s;//�ı��� 
	cout << AC_Query(s) << endl;
	return 0;
}
