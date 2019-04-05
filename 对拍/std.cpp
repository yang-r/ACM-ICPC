#pragma warning (disable :4996)
#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;
int ans = 0;
//ע����Ŀ�������ͣ���һ�����ַ��������� 
void cal_next(char*str, int nex[]) {           //���str��ǰ׺�ͺ�׺��ͬ�ĳ��� ����next�� 
	int k = -1;                                //��next[0]=-1 �����ڣ�next[1]=0 һ����ͬ 
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

void kmp(char*str, char*ptr) {
	int next[10010];
	memset(next, 0, sizeof(next));
	cal_next(ptr, next);
	int slen = strlen(str);
	int plen = strlen(ptr);
	int k = -1;
	int mark = 0;
	for (int q = 0; q < slen; q++) {
		while (k > -1 && ptr[k + 1] != str[q]) {
			k = next[k];            //�ַ�����ǰλ�ò���ͬ������ͬƥ���ʱ�򣬻��� 
		}
		if (ptr[k + 1] == str[q]) {
			k++;                     //��ͬ������Ƚ� 
		}
		if (k == plen - 1) {
			ans++;   // λ�õ��������1��ʼ 
			k = next[k]; 
		}
	}
	//  ����Ӵ���next 
	for (int i = 0; i <strlen(ptr); i++) {
	printf("%d ", next[i] );
	}
	printf("\n");

}
int main() {
	char a[10010], b[1000010];
	int T;
	scanf("%d", &T);
	getchar();
	while (T--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		ans = 0;
		gets(a);
		gets(b);
		kmp(b, a);
		printf("%d\n", ans);
	}

	return 0;
}
