
/*
HDU 3333
*/ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int maxn = 30010;
ll num[maxn << 2];
void update(int pos, int val, int le, int ri, int node) {
    if (le == ri) {
        num[node] = val;
        return;
    }
    int t = (le + ri) >> 1;
    if (pos <= t) update(pos, val, le, t, node << 1);
    else update(pos, val, t + 1, ri, node << 1 | 1);
    num[node] = num[node << 1] + num[node << 1 | 1];
}
ll query(int l, int r, int le, int ri, int node) {
    if (l <= le && ri <= r) return num[node];
    int t = (le + ri) >> 1;
    ll ans = 0;
    if (l <= t) ans += query(l, r, le, t, node << 1);
    if (r>t) ans += query(l, r, t + 1, ri, node << 1 | 1);
    return ans;
}
struct edge {
    int num, num1, pos;
}B[maxn * 4];
bool cmp2(const edge &a, const edge &b) {
    return a.num1<b.num1;
}
int vis[maxn], tmp[maxn], pre[maxn], A[maxn];
ll ans[maxn * 4];
int main() {
    int T, n, m, a, b;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        memset(ans, 0, sizeof(ans));
        memset(pre, -1, sizeof(pre));
        memset(num, 0, sizeof(num));
        for (int i = 0; i<n; i++) {
            scanf("%d", &A[i]);
            tmp[i] = A[i];
        }
        sort(tmp, tmp + n);
        scanf("%d", &m);
        for (int i = 0; i<m; i++) {
            scanf("%d%d", &B[i].num, &B[i].num1);
            B[i].pos = i;
        }
        //按照查询区间右端点排序
        sort(B, B + m, cmp2);
        for (int i = 0, j = 0; i<n; i++) {
            int t = lower_bound(tmp, tmp + n, A[i]) - tmp;//二分查找数据的位置
            if (vis[t]) {//数字曾出现过
                //pre为之前出现过的数字的位置
                //出现过则清零之前位置的数字
                update(pre[t], 0, 1, n, 1);
                //i+1为当前位置
                update(i + 1, A[i], 1, n, 1);
                pre[t] = i + 1;
            }
            else {
                vis[t] = 1;
                update(i + 1, A[i], 1, n, 1);
                pre[t] = i + 1;
            }
            for (; j<m; j++) {
                //若当前位置为查询区间的右端点，进行查询
                if (i + 1 != B[j].num1) break;
                ans[B[j].pos] = query(B[j].num, B[j].num1, 1, n, 1);
            }
        }
        for (int i = 0; i<m; i++) printf("%I64d\n", ans[i]);
    }
    return 0;
}
