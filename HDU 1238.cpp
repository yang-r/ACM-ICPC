#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pi acos(-1)
#define ll long long
#define mod 10007
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1

using namespace std;

const double g = 10.0, eps = 1e-9;
const int N = 100 + 5, maxn = (1 << 18) - 1, inf = 0x3f3f3f3f;

int Next[N], slen, plen;
string a[N], ptr, str;

void getnext()
{
	int k = -1;
	Next[0] = -1;
	for (int i = 1; i<slen; i++)
	{
		while (k>-1 && str[k + 1] != str[i])k = Next[k];
		if (str[k + 1] == str[i])k++;
		Next[i] = k;
	}
}
bool kmp()
{
	int k = -1;
	for (int i = 0; i<plen; i++)
	{
		while (k>-1 && str[k + 1] != ptr[i])k = Next[k];
		if (str[k + 1] == ptr[i])k++;
		if (k == slen - 1)return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//   cout<<setiosflags(ios::fixed)<<setprecision(2);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i<n; i++)cin >> a[i];
		int ans = 0;
		for (int i = 1; i <= a[0].size(); i++)
		{
			for (int j = 0; j <= a[0].size() - i; j++)
			{
				str = a[0].substr(j, i); //匹配的子串枚举
				slen = str.size();
				getnext();
				bool flag = 1;
				for (int k = 1; k<n; k++)//与其他字符窜枚举
				{
					ptr = a[k];
					plen = a[k].size();
					if (kmp())continue;
					reverse(ptr.begin(), ptr.end());
					if (kmp())continue;
					flag = 0;
					break;
				}
				if (flag)ans = max(ans, slen);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
