#include<stdio.h>
#include<iostream>
#include<string.h>

#define maxn 100010 

using namespace std;

//注意题目数据类型，不一定是字符串！！！ 
void cal_next(char*str,int nex[]) {           //算出str的前缀和后缀相同的长度 存入next中 
	int k = -1;                                //如next[0]=-1 不存在，next[1]=0 一个相同 
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
				k = next[k];            //字符串当前位置不相同且有相同匹配的时候，回溯 
			}
			if (ptr[k + 1]==str[q]) {
				k++;                     //相同则继续比较 
			}
			if (k== plen - 1) {
				printf("%d\n", q - k + 1);     // 位置的输出，从1开始 
				  k=next[k];        //得出匹配字符串，位置回到含有相同前缀的点开始比较 
			}
		}
		//  输出子串的next 
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
