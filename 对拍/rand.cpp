#include<bits/stdc++.h>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))

stringstream ss;

int main( int argc, char *argv[] )
{ 
	int seed=time(NULL);
	if(argc)
	{
		ss.clear();
		ss<<argv[1];
		ss>>seed;
	}
	srand(seed);
	//以上为随机数初始化，请勿修改
	//random(a,b)生成[a,b]的随机整数
	
	//以下写你自己的数据生成代码 
	printf("1\n");
	char n[10000];
	int k=random(1,10); 
	for(int i=0;i<k;i++){
		n[i]='a'+random(0,21);
	}
	char m[1001000];
	int num=random(k,1000010);
	for(int i=0;i<num;i++){
		m[i]='a'+random(0,21);
	}
	printf("%s\n%s\n",n,m);
	return 0;
}
