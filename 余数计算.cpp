#include<vector>
#include<queue>
#include<stdio.h>
#include<iostream>

using namespace std;
typedef long long LL;

const int maxn = 200000 + 10;
LL a[maxn] = { 0 };
int w[maxn] = { 0 };
struct node {
	int w;    //取模剩余的值
	int pos;
	int val;
}p[maxn];
int n, m;
LL ans = 0;
queue<node> q;
vector<int> v;

int cmp(node a, node b) {
	if (a.w < b.w) return 1;
	else return 0;
}

void Solve() {
	int k = n / m;
	for (int i = 0; i < m; i++) {
		if (w[i] == k) continue;
		if (w[i] > k) {         //取模后个数大于所需
			int t = w[i] - k;   //多出的数
			int pos = lower_bound(v.begin(), v.end(), i) - v.begin();  //第i个元素的下标
			while (t--) {
				node now;
				now.pos = p[pos].pos;
				now.w = p[pos].w;
				q.push(now);   //多出的数放入队列
			 	pos++;       //p是已经排序的数组，多出来的数相邻            
			}
		}
		else {
			int t = k - w[i];
			while (t > 0 && !q.empty()) {
				node now;
				now = q.front();
				q.pop();
				if (i > now.w) {
					ans += i - now.w;
					a[now.pos] += i - now.w;
					w[now.w]--;
				}
				else {
					ans += m - (now.w - i);  //大于所需的余数值
					a[now.pos] += m - (now.w - i); 
					w[now.w]--;  //用过之后减一
				}
				w[i]++;
				t--;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		w[a[i] % m]++;
		p[i].pos = i;
		p[i].w = a[i] % m;
		p[i].val = a[i];
	}
	sort(p, p + n, cmp);
	for (int i = 0; i < n; i++) v.push_back(p[i].w);
	Solve();
	Solve();  //避免多出来的数在最后面，第一次存进队列后，第二次再for一遍。
	printf("%lld\n", ans);
	for (int i = 0; i < n; i++) printf("%lld ", a[i]);
	printf("\n");
	return 0;
}
