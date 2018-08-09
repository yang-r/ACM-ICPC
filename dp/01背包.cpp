
Kaiwen is an excellent student who loves studying
The final exam is approaching in N hours, and now he starts to prepare for his ¡¶Computer network¡· exam

¡¶Computer network¡· has M chapters
Kaiwen can get vi points if he has studyed the chapter i
Studying the chapter i needs ti hours

Obviously N hours is not enough to study all chapters for Kaiwen
So the question is how many points can Kaiwen get at most ?

Input


The first line is an integer T standing for the number of test cases.
Then T test cases follow.
For each case
The first line has two integers N and M
then M lines follow, every line has two integers v and t represent vi and ti
(1¡ÜN, M, v, t¡Ü200)



Output


For each case, output the maximum point Kaiwen can get

Sample Input


1
8 5
5 3
2 10
2 6
3 8
5 14

Sample Output



24







#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

struct node {
	int v, t;
}a[210];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int f[210] = { 0 };
		int m, n,maxn=0;
		scanf("%d%d",&m,&n);
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].t,&a[i].v);
		}
		for (int i = 0; i < n; i++) {
			for (int j =m; j >= a[i].t; j--) {
				f[j] = max(f[j], f[j - a[i].t] + a[i].v);
			}
		}
		printf("%d\n", f[m]);
	}

	return 0;
}