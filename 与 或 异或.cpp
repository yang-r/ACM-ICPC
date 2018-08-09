
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;



int main() {
	int data[100005];
	int nand[100];
	int n, p;
//	printf("%d",2^3^4^2);//a^b^a==b
	while (scanf_s("%d%d", &n, &p) != EOF) {
		memset(data,0,sizeof(data));
		memset(nand,0,sizeof(nand));
		int nnn = 0;
		int AND, OR, XOR = 0;
		int i, j;
		for (i = 1; i <= n; i++) {
			scanf_s("%d", &data[i]);
			XOR = XOR ^data[i];   //异或的值
			int flag = data[i];
			int nowi = 1;
			while (flag) {   //二进制转换
				nand[nowi++] += (flag % 2); //如果当前位不为0，则该位的数组加一
				flag /= 2;
			}
			nnn = max(nnn, nowi);//数据位数统计
		}
		for (i = 0; i<p; i++) {
			int q;
			scanf_s("%d", &q);
			int ans1 = XOR ^data[q];
			int ans2 = 0, ans3 = 0;
			int now2 = data[q];
			int fi = 1;
			int fj = nnn;
			while (fj--) {
				if ((nand[fi] - (now2 % 2)) == n - 1)
					ans2 += pow(2, fi - 1);
				if ((nand[fi] - (now2 % 2))>0)
					ans3 += pow(2, fi - 1);
				fi++;
				now2 /= 2;
			}
			printf("%d %d %d\n", ans2, ans3, ans1);
		}
	}
	return 0;
}