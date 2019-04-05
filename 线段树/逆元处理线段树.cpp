#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define  ll long long
const int mod = 1000000007; //注意大小
const int maxn = 1e6 + 10;
ll n, m;
ll t[1000001 * 4];
ll lazy[1000001 * 4];
ll sum = 1;

inline ll qpow(ll x, ll n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1) res = (res * x) % mod;
		x = (x * x % mod);
		n >>= 1;
	}
	return res;
}

void build(ll l, ll r, ll rt) {
	if (l == r) {
		t[rt] = 1;
		return;
	}
	ll mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	t[rt] = t[rt << 1] * t[rt << 1 | 1];

}

//点更新
void update(ll l, ll r, ll rt, ll point, ll val) {
	if (point == l && r == point) {
		t[rt] = (t[rt] * val) % mod;
		return;
	}

	ll mid = (l + r) >> 1;
	if (mid >= point)update(l, mid, rt << 1, point, val);
	else update(mid + 1, r, rt << 1 | 1, point, val);
	t[rt] = (t[rt << 1] * t[rt << 1 | 1]) % mod;
}


ll query(ll l, ll r, ll rt, ll L, ll R)
{
	if (L <= l && r <= R)return t[rt];
	int mid = (l + r) / 2;
	ll ans = 1;
	if (L <= mid)ans = ans * query(l, mid, rt * 2, L, R) % mod;
	if (R>mid)ans = ans * query(mid + 1, r, rt * 2 + 1, L, R) % mod;
	return ans;
}
int main() {

	ll a, b, c;
	ll x;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) t[i] = 1;
	build(1, n, 1);
	for (ll i = 0; i <m; i++) {
		scanf("%lld", &x);
		if (x == 1) {
			scanf("%lld%lld", &b, &c);
			update(1, n, 1, b, c);
		}
		//除法（除以c）  （此时c不为1/c）
		if (x == 2) {
			scanf("%lld%lld", &b, &c);
			ll k = qpow(c, mod - 2); //逆元  处理c
			//printf("k  %lld\n",k);
			update(1, n, 1, b, k);
		}
		
		if (x == 3) {
			scanf("%lld%lld", &a, &b);
			sum = query(1, n, 1, a, b);
			printf("%lld\n", sum%mod);

		}
	}
	return 0;
}

