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

