#include<stdio.h>
#include<iostream>
#include<string.h>

#define maxn 100010 

using namespace std;

//ע����Ŀ�������ͣ���һ�����ַ��������� 
void cal_next(char*str,int nex[]) {           //���str��ǰ׺�ͺ�׺��ͬ�ĳ��� ����next�� 
	int k = -1;                                //��next[0]=-1 �����ڣ�next[1]=0 һ����ͬ 
	int len = strlen(str);
	nex[0] = -1;
	for (int q = 1; q < len; q++) {
		while (k > -1 && str[k + 1] != str[q]) {
				k = nex[k];
		} 
			if (str[k+1] == str[q]) {
				k++;
			}
			nex[q] = k;   
	}

}

void kmp(char*str, char*ptr){
	int next[maxn];
	cal_next(ptr,next);
		int slen = strlen(str);
		int plen = strlen(ptr);
		int k = -1;
		int mark = 0;
		for (int q = 0; q < slen; q++) {
			while (k > -1 && ptr[k + 1] != str[q]) {
				k = next[k];            //�ַ�����ǰλ�ò���ͬ������ͬƥ���ʱ�򣬻��� 
			}
			if (ptr[k + 1]==str[q]) {
				k++;                     //��ͬ������Ƚ� 
			}
			if (k== plen - 1) {
				printf("%d\n", q - k + 1);     // λ�õ��������1��ʼ 
				  k=next[k];        //�ó�ƥ���ַ�����λ�ûص�������ͬǰ׺�ĵ㿪ʼ�Ƚ� 
			}
		}
		//  ����Ӵ���next 
		for (int i = 0; i <strlen(ptr); i++) {
			printf("%d ", next[i] + 1);
		}
		printf("\n");	
}
int main() {
	char a[maxn],b[maxn];
	gets_s(a);
	gets_s(b);
	kmp(a,b);

	return 0;
	}
