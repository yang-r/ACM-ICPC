
/*СA��ϲ��6������֣�����Ҫ֪����L��R֮���ж��ٸ�love���� 
ʲô��love���أ���������һ�����������������10��������ĳһλ����Ϊ6����ô���������love�������磺600��606��26��6��61��6666����love����


����

�ж���������ݡ�
��������������L��R��1 <= L <= R <= 10 ^ 18����


���

���L��R֮���ж��ٸ�love����
*/

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

typedef long long ll;

ll dp[20][2];                       //dpֻ������״̬��6�ͷ�6��
ll num[20];							//dp[0][0]=1,dp[0][1]=10;
ll l, r;

ll dfs(ll pos, ll s6, bool limit, bool fzero) {                      //bool ����ֻ�����
	if (pos == -1) return s6;
	if (!limit && !fzero && dp[pos][s6] != -1)return dp[pos][s6];    //fzero ǰ��0  
	ll up = limit ? num[pos] : 9;                                    //limit �жϵ�ǰλ���Ŀ���ö�ٷ�Χ
	ll ans = 0;
	for (ll i = 0; i <= up; ++i) {
		ll now6 = s6;
		if (s6 == 0) {
			if (i == 6) now6 = 1;
		}
		ans += dfs(pos - 1, now6, limit && i == up, fzero && !i);
	}
	//return (limit || fzero) ? ans : dp[pos][s6] = ans;        //���仯��������ظ�ö�٣���Լʱ��
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
		printf("%lld\n", cal(r) - cal(l - 1));  //cal(l-1)����ʱ������l��cal��r������l
	}
	return 0;
}
