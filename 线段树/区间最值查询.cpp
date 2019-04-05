#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define lson rt<<1
#define rson rt<<1|1 
using namespace std;
int n, m;
int t[200005 * 4];
int maxx = 0;
void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &t[rt]);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, lson);
	build(mid + 1, r, rson);
	t[rt] = max(t[lson], t[rson]);
	//存放的是区间的最值 
	//cout << "区间最大 " << l << ' ' << r << " is " << t[rt] << " rt " << rt << endl;
}

void update(int l, int r, int rt, int k, int val) {
	if (l == r) {
		t[rt] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= k)update(l, mid, lson, k, val);
	else update(mid + 1, r, rson, k, val);
	t[rt] = max(t[lson], t[rson]);
}

//查询 
void query(int l, int r, int rt, int L, int R) {
	if (l >= L && r <= R) {
		maxx = max(maxx, t[rt]);
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= L)query(l, mid, lson, L, R);
	if (mid < R)query(mid + 1, r, rson, L, R);
	return;
}

int main() {

	int a, b;
	char x;
	while (scanf("%d%d", &n, &m) != EOF) {
		build(1, n, 1);

		for (int i = 0; i <m; i++) {
			getchar();
			scanf("%c", &x);
			scanf("%d%d", &a, &b);
			if (x == 'U') {
				update(1, n, 1, a, b);
			}
			if (x == 'Q') {
				query(1, n, 1, a, b);
				printf("%d\n", maxx);
				maxx = 0;
			}

		}

	}

	return 0;
}
