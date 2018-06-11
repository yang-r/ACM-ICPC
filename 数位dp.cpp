
//HDU  2089

#include<stdio.h>
#include<string.h>

int dp[10][10];
int d[10];
void init() {
	dp[0][0] = 1;
	for (int i = 1; i < 9; i++) {
		for (int j = 0; j < 10; j++) { 
			for (int k = 0; k < 10; k++)
				if (j != 4 && (j != 6 || k != 2))    //d[i-1][k]所表达的是当前位数的下一位（低位）的数字
					dp[i][j] += dp[i - 1][k];//d[i][0]里面存放的是前一位（i-1）满足条件的所有个数和
		}
	}
}


int sta(int num) {
	int len = 0;
	while (num)
	{						//数据位数的统计
		++len;
		d[len] = num % 10;
		num /= 10;
	}                  
	d[len + 1] = 0;
	int ans = 0;
	for (int i = len; i > 0; i--) {
		for (int j = 0; j < d[i]; j++) {
			if (d[i + 1] != 6 || j != 2) {
				ans += dp[i][j];
			}
		}
		if (d[i] == 4 || (d[i + 1] == 6 && d[i] == 2))
			break;
	}
	memset(d, 0, sizeof(d));
	return ans;
}

int main() {
	init();
	int m, n;
	while (scanf("%d%d", &m, &n))
	{
		if (n == 0 && m == 0)
			break;
		printf("%d\n", sta(n + 1) - sta(m));      //n+1是因为求得的是小于n的数，所以求[0,n]之间的数需要求n+1
	}
	return 0;

}
//https://wenku.baidu.com/view/9de41d51168884868662d623.html
//http://www.cnblogs.com/wenruo/p/4725005.html
