#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define  ll long long
ll n, m;
ll t[10005 * 4];
ll lazy[10005 * 4];
ll sum=0 ;
void build(ll l, ll r, ll rt) {
	if (l == r) {
		scanf("%lld", &t[rt]);
		return;
	}
	lazy[rt] = 0;
	ll mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	t[rt] = t[rt << 1]+ t[rt << 1 | 1];
	//cout << "区间最大 " << l << ' ' << r << " is " << t[rt] << " rt " << rt << endl;
}

//延迟更新

void pushdown(ll l, ll r, ll rt) {
	if (lazy[rt]) {
		lazy[rt << 1]+= lazy[rt];
		lazy[rt << 1 | 1]+= lazy[rt];
		t[rt << 1]+= l * lazy[rt];
		t[rt << 1 | 1]+= r * lazy[rt];
		lazy[rt] = 0;
	}
}
//区间更新
void update(ll l, ll r, ll rt, ll L, ll R,ll c1) {
	if (L<=l&&r<=R) {
		t[rt]+=(r-l+1)*c1;
		lazy[rt]+= c1;
		return;
	}
	
	ll mid = (l + r) >> 1;
	pushdown(mid - l + 1, r - mid, rt);
	if (mid >= L)update(l, mid, rt << 1, L,R, c1);
	if(mid<R) update(mid + 1, r, rt << 1 | 1, L,R, c1);
	t[rt] = t[rt << 1]+t[rt << 1 | 1];
}


void query(ll l, ll r, ll rt, ll L, ll R) {
	if (l >= L && r <= R) {
		sum += t[rt];
		return;
	}

	ll mid = (l + r) >> 1;
	pushdown(mid - l + 1, r - mid, rt);
	if (mid >= L)query(l, mid, rt << 1, L, R);
	if (mid < R)query(mid + 1, r, rt << 1 | 1, L, R);
	return;
}

int main() {

	ll a, b,c;
	char x;
	while (scanf("%lld%lld", &n, &m) != EOF) {
		memset(t, 0, sizeof(t));
		memset(lazy, 0, sizeof(lazy));
		build(1, n, 1);
 		for (ll i = 0; i <m; i++) {
			getchar();
			scanf("%c", &x);
			if (x == 'C') {
				scanf("%lld%lld%lld", &a, &b,&c);
				update(1, n, 1, a, b,c);
			}
			if (x == 'Q') {
				scanf("%lld%lld", &a, &b);
				query(1, n, 1, a, b);
				printf("%lld\n", sum);
				sum = 0;
			}
		}
	}
	return 0;
}