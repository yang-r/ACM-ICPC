#include<iostream>
#include<cstdio>
#include<cstring>
#pragma warning(disable :4996);
using namespace std;

//ababacbd
//aba
//最长前后公共子串 
int nex[10010];
void get_next(char s[], int len) {
	nex[0] = 0;
	int k;
	for (int i = 1; i<len; i++) {
		k = i;
		int j = nex[k - 1];
		if (s[j] == s[i]) {
			nex[k] = j + 1;
		}
		else if (s[i] == s[0])nex[k] = 1;
		else nex[k] == 0;
	}
	//for (int i = 0; i<len; i++)cout << nex[i] << endl;
}

void kmp(char t[], char m[], int tlen, int mlen) {
	get_next(m, mlen);
	int cnt = 0;
	for (int j = 0, i = 0; i<tlen;) {
		while (t[i] != m[j] && i<tlen) {
			i++;
		}
		while (t[i] == m[j] && j<mlen&&i<tlen) {
			i++, j++;
		}
		if (j == mlen) {
			cnt++;	
		}
		j = nex[j- 1];//回溯
	}
	//cout << "cnt" << endl;
	printf("%d\n", cnt);

}

int main() {
	int n;
	char t[1000100];
	char m[10010];

	cin >> n;
	while (n--) {
		scanf("%s%s", &m, &t);
		//cout << m << endl;
		//cout << t << endl;
		int tlen = strlen(t);
		int mlen = strlen(m);
		kmp(t, m, tlen, mlen);
		memset(t, 0, sizeof(t));
		memset(m, 0, sizeof(m));
	}

	return 0;
}
