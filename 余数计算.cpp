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
	int w;    //ȡģʣ���ֵ
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
		if (w[i] > k) {         //ȡģ�������������
			int t = w[i] - k;   //�������
			int pos = lower_bound(v.begin(), v.end(), i) - v.begin();  //��i��Ԫ�ص��±�
			while (t--) {
				node now;
				now.pos = p[pos].pos;
				now.w = p[pos].w;
				q.push(now);   //��������������
			 	pos++;       //p���Ѿ���������飬�������������            
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
					ans += m - (now.w - i);  //�������������ֵ
					a[now.pos] += m - (now.w - i); 
					w[now.w]--;  //�ù�֮���һ
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
	Solve();  //������������������棬��һ�δ�����к󣬵ڶ�����forһ�顣
	printf("%lld\n", ans);
	for (int i = 0; i < n; i++) printf("%lld ", a[i]);
	printf("\n");
	return 0;
}
