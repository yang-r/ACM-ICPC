#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#pragma warning (disable :4996);
#define mod 1000000007
#define maxn 20000
using namespace std;


char str[maxn];//ԭ�ַ���
char tmp[maxn << 1];//ת������ַ���
int Len[maxn << 1];
bool vis[maxn << 1];
//ת��ԭʼ��

int INIT(char *st)
{
	int i, len = strlen(st);
	tmp[0] = '@';//�ַ�����ͷ����һ�������ַ�����ֹԽ��
	for (i = 1; i <= 2 * len; i += 2)
	{
		tmp[i] = '#';
		tmp[i + 1] = st[i / 2];
	}
	tmp[2 * len + 1] = '#';
	tmp[2 * len + 2] = '$';//�ַ�����β��һ���ַ�����ֹԽ��
	tmp[2 * len + 3] = 0;
	return 2 * len + 1;//����ת���ַ����ĳ���
}
//Manacher�㷨�������
int MANACHER(char *st, int len)
{
	int mx = 0, ans = 0, po = 0;//mx��Ϊ��ǰ������Ĵ����ұ��ַ������ֵ
	for (int i = 1; i <= len; i++)
	{
		if (mx>i)
			Len[i] = min(mx - i, Len[2 * po - i]);//��Len[j]��mx-i��ȡ��С
		else
			Len[i] = 1;//���i>=mx��Ҫ��ͷ��ʼƥ��
		while (st[i - Len[i]] == st[i + Len[i]])
			Len[i]++;
		if (Len[i] + i>mx)//���¼���Ļ��Ĵ��Ҷ˵�λ�ô���mx��Ҫ����po��mx��ֵ
		{
			mx = Len[i] + i;
			po = i;
		}
		ans = max(ans, Len[i]);
	}
	return ans - 1;//����Len[i]�е����ֵ-1��Ϊԭ����������Ӵ���� 
}

int main() {
	memset(str, 0, sizeof(str));
	scanf("%s", &str);
	int len=INIT(str);
	int cnt = 0;
	cnt=MANACHER(tmp,len);
	cout << cnt << endl;
	return 0;
}
