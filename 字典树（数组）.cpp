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

