#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 3e5 + 5;
typedef long long LL;

struct Tree {int Len, Fail, Go[26];} Tr[MAXN];

char S[MAXN];
int len, Last, tot, i, Cnt[MAXN];

void InitTree() {
    Tr[0].Len = 0, Tr[1].Len = -1;
    tot = 1, Last = 0;
    Tr[0].Fail = 1;
}

int Get(int Now) {
    while (S[i - Tr[Now].Len - 1] != S[i]) Now = Tr[Now].Fail;
    return Now;
}

void Add(int c) {
    int t = Get(Last);
    if (!Tr[t].Go[c]) {
        Tr[++ tot].Len = Tr[t].Len + 2;
        Tr[tot].Fail = Tr[Get(Tr[t].Fail)].Go[c];
        Tr[t].Go[c] = tot;
    }
    Last = Tr[t].Go[c];
    Cnt[Last] ++;
}

LL GetAns() {
    LL Ans = 0;
    for (int i = tot; i > 1; i --) {
        Cnt[Tr[i].Fail] += Cnt[i]; 
        Ans = max(Ans, LL(Tr[i].Len) * LL(Cnt[i]));
    }
    return Ans;
}

int main() {
    freopen("palindrome.in", "r", stdin), freopen("palindrome.out", "w", stdout);

    scanf("%s", S + 1);
    len = strlen(S + 1);
    InitTree();
    for (i = 1; i <= len; i ++) Add(S[i] - 'a');
    printf("%lld", GetAns());
}
