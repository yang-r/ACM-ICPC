
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
				if (j != 4 && (j != 6 || k != 2))    //d[i-1][k]�������ǵ�ǰλ������һλ����λ��������
					dp[i][j] += dp[i - 1][k];//d[i][0]�����ŵ���ǰһλ��i-1���������������и�����
		}
	}
}


int sta(int num) {
	int len = 0;
	while (num)
	{						//����λ����ͳ��
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
		printf("%d\n", sta(n + 1) - sta(m));      //n+1����Ϊ��õ���С��n������������[0,n]֮�������Ҫ��n+1
	}
	return 0;

}
//https://wenku.baidu.com/view/9de41d51168884868662d623.html
//http://www.cnblogs.com/wenruo/p/4725005.html
