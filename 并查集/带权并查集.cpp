#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#define maxn 400010

typedef long long ll;
using namespace std;

ll  p[maxn];
ll val[maxn];

int find(int x) {
	if (x != p[x]) {
		int f = p[x];
		p[x] = find(p[x]);
		val[x] += val[f];
	}
	return p[x];
}



int main() {
	int n, m;
	while(scanf("%d%d", &n, &m)!=EOF){
		memset(p, 0, sizeof(p));
		for (int i = 0; i <=n; i++) {
			p[i] = i;
			val[i] = 0;
		}
		int a, b, v,ans=0;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &v);
			a--;
			int x = find(a), y = find(b);
			if (x != y) {
				p[x] = y;
				val[x] = val[b]-val[a] + v;
			}
			else if (val[a] - val[b] !=  v)ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
