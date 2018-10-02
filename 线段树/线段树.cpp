#include<cstdio>
#include<iostream>
#include<string.h>
#define lson rt<<1
#define rson rt<<1|1

using namespace std;
//注意数组大小
//足够的空间 = 数据大小n的四倍。
//实际上足够的空间 = （n向上扩充到最近的2的某个次方）的两倍。
int t[50010 * 4];
int ans;
void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &t[rt]);
		//	printf("第%d节点的值为%d\n", rt, t[rt]);
		return;
	}
	int m1 = 0;
	m1 = (l + r) >> 1;
	build(l, m1, lson);
	build(m1 + 1, r, rson);
	t[rt] = t[lson] + t[rson];
	//	printf("[%d to %d] val is %d\n", l, r, t[rt]);
}
//单点更新
void update(int l, int r, int rt, int k, int c) {
	if (l == r) {
		t[rt] += c;
		//cout <<"rt is"<<rt<<"  val is"<<t[rt] << endl;
		return;
	}
	int m1 = (l + r) >> 1;
	if (m1 >= k)update(l, m1, lson, k, c);
	else update(m1 + 1, r, rson, k, c);
	t[rt] = t[lson] + t[rson];
	//cout << "区间[ " << l << ", " << r << "] " << "值为" <<t[rt]<<"  节点:"<<rt<<endl;
}
//区间查询
void query(int l, int r, int rt, int L, int R) {
	if (l >= L && r <= R) {
		ans += t[rt];
		return;
	}
	int m1 = (l + r) >> 1;
	if (m1 >= L)query(l, m1, lson, L, R);
	if (m1<R) query(m1 + 1, r, rson, L, R);
	return;
}

int main() {
	int T, mark = 1, rep = 0;
	char x[10];
	int  a1, b1;
	scanf("%d", &T);
	while (T--) {
		memset(t, 0, sizeof(t));
		int m;
		ans = 0;
		printf("Case %d:\n", mark++);
		scanf("%d", &m);
		build(1, m, 1);
		getchar();
		while (true) {
			scanf("%s", x);
			if (x[0] == 'Q') {
				scanf("%d%d", &a1, &b1);
				query(1, m, 1, a1, b1);
				printf("%d\n", ans);
				ans = 0;
			}
			else if (x[0] == 'A' || x[0] == 'S') {
				scanf("%d%d", &a1, &b1);
				if (x[0] == 'A')
					update(1, m, 1, a1, b1);
				else {
					b1 = b1 * (-1);
					update(1, m, 1, a1, b1);
				}
			}
			else if (x[0] == 'E') break;
		}


	}

	return 0;
}
