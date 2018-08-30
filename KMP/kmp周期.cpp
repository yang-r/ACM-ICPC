#pragma warning (disable :4996)
#include<stdio.h>
#include<iostream>
#include<string.h>

#define maxn 100010

using namespace std;
int nex[maxn];
//注意题目数据类型，不一定是字符串！！！ 
void cal_next(char*str) {           //算出str的前缀和后缀相同的长度 存入next中 
	int k = -1;                                //如next[0]=-1 不存在，next[1]=0 一个相同 
	int len = strlen(str);
	nex[0] = -1;
	for (int q = 1; q < len; q++) {
		while (k > -1 && str[k + 1] != str[q]) {
			k = nex[k];
		}
		if (str[k + 1] == str[q]) {
			k++;
		}
		nex[q] = k;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	char a[maxn];
	int alen, len;
	int ans;

	while (T--) {
		ans = 0;
		scanf("%s", &a);
		cal_next(a);
		alen = strlen(a);
		//最大回溯长度（最小循环长度）--- len
		len = alen - nex[alen - 1] - 1;
		if (nex[alen - 1] == -1) {  //如果最后一位与前缀不同则直接输出字符串长度
			printf("%d\n", alen);
			continue;
		}
		if (alen%len == 0) //如果没有余数则循环节不需添加
			ans = 0;
		else {    //循环节差多少就加多少
			ans = len - alen % len;
		}
		printf("%d\n", ans);

	}

	return 0;
}
