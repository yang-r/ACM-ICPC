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
	//����Ϊ�������ʼ���������޸�
	//random(a,b)����[a,b]���������
	
	//����д���Լ����������ɴ��� 
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
