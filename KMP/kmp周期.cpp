#pragma warning (disable :4996)
#include<stdio.h>
#include<iostream>
#include<string.h>

#define maxn 100010

using namespace std;
int nex[maxn];
//ע����Ŀ�������ͣ���һ�����ַ��������� 
void cal_next(char*str) {           //���str��ǰ׺�ͺ�׺��ͬ�ĳ��� ����next�� 
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
		//�����ݳ��ȣ���Сѭ�����ȣ�--- len
		len = alen - nex[alen - 1] - 1;
		if (nex[alen - 1] == -1) {  //������һλ��ǰ׺��ͬ��ֱ������ַ�������
			printf("%d\n", alen);
			continue;
		}
		if (alen%len == 0) //���û��������ѭ���ڲ������
			ans = 0;
		else {    //ѭ���ڲ���پͼӶ���
			ans = len - alen % len;
		}
		printf("%d\n", ans);

	}

	return 0;
}
