#include<stdio.h>
#include<iostream>
#include<string.h>

#define maxn 400010

using namespace std;
int nex[maxn];

void cal_next(char*str) {          
    int k = -1;                              
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
    char a[maxn];
    int ans[maxn];
    int alen, temp;

    int i=1;
    while (scanf("%s",&a)!=EOF) {
        if (a[0]=='.')break;
        cal_next(a);
        alen = strlen(a);

        ans[alen - i] = nex[alen - 1]+1;    //这里直接找next最后一个数的，这样前缀和后缀必然相同
        //（然后判断前缀或者后缀中是否还含有相同的片段，即前缀的前缀和（前缀的）后缀是否相同）

        temp = alen - 1;
        for (;;) {                       //如此反复可得结果

            if (nex[temp] >=0){
                ans[alen - i] = nex[temp]+1;
                temp = nex[temp];
            }
            else break;
            i++;
        }
        for ( i =alen-i+1; i <alen; i++) { //输出答案
            printf("%d ", ans[i]);
        }
        printf("%d\n",alen);         //最后输出字符串本身
        memset(a, 0, sizeof(a));
        memset(nex, 0, sizeof(nex));
        i = 1;
    }
    return 0;
}
