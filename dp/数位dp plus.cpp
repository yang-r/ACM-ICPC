
/*小A很喜欢6这个数字，他想要知道从L到R之间有多少个love数。 
什么是love数呢？对于任意一个正整数，如果它的10进制数上某一位数字为6，那么这个数就是love数。比如：600、606、26、6、61、6666就是love数。


输入

有多组测试数据。
输入两个正整数L和R（1 <= L <= R <= 10 ^ 18）。


输出

输出L到R之间有多少个love数。
*/

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

typedef long long ll;

ll dp[20][2];                       //dp只有两种状态（6和非6）
ll num[20];							//dp[0][0]=1,dp[0][1]=10;
ll l, r;

ll dfs(ll pos, ll s6, bool limit, bool fzero) {                      //bool 类型只有真假
	if (pos == -1) return s6;
	if (!limit && !fzero && dp[pos][s6] != -1)return dp[pos][s6];    //fzero 前导0  
	ll up = limit ? num[pos] : 9;                                    //limit 判断当前位数的可以枚举范围
	ll ans = 0;
	for (ll i = 0; i <= up; ++i) {
		ll now6 = s6;
		if (s6 == 0) {
			if (i == 6) now6 = 1;
		}
		ans += dfs(pos - 1, now6, limit && i == up, fzero && !i);
	}
	//return (limit || fzero) ? ans : dp[pos][s6] = ans;        //记忆化数组避免重复枚举，节约时间
	if (limit || fzero) {
		return ans;
	}
	else {
		dp[pos][s6] = ans;
		return  ans;
	}
}

ll cal(ll n) {
	ll len = 0;
	while (n) {
		num[len++] = n % 10;
		n /= 10;
	}
	return dfs(len - 1, 0, 1, 1);
}


int main() {

	memset(dp, -1, sizeof(dp));
	while (scanf_s("%lld%lld", &l, &r) != EOF) {
		printf("%lld\n", cal(r) - cal(l - 1));  //cal(l-1)计算时不加入l，cal（r）加入l
	}
	return 0;
}
