#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<set>
#include<math.h>
#include<algorithm>

using namespace std;

typedef  long long ll;

int main() {
	int a[] = { 1,2,3,4,4,5,5,5,6,6,6,6 };//�±���㿪ʼ  ���ֲ���
	int result = (lower_bound(a, a + 12, 1) - a); // lower_bound(����Χ+����ֵ��-���鿪ͷ)  ���ڻ���ڲ���ֵ�������±�
	cout << " 1 "<<result << endl;//result 1 0
	result = (lower_bound(a, a + 12, 3) - a);
	cout << " 3"<<result << endl;// result : 3 2
	result = (lower_bound(a, a + 12, 4) - a);
	cout <<  " 4 "<<result << endl; // result   4: 3
	result = (upper_bound(a, a + 12, 5) - a);// upper_bound: ���ڲ���ֵ���±�
	cout << " 5: "<<result << endl;     // result 5: 8
	result = (upper_bound(a, a + 12, 8) - a);//û���ҵ��򷵻����end  �������꣺12��
	cout << result << endl;
	int n=unique(a,a+12) -a;  //��ȥ�ء�����ͬ������������������
	//�˴��ǽ�ȥ�غ�����ݸ�������n��unique(��Χ)-�������� 
	cout<<n<<endl;            // n=6
	for(int i=0;i<12;i++)
	cout<<a[i]<<" ";         //�����1 2 3 4 5 6�������� 5 5 6 6 6 6
	cout<<endl;      
	return 0;
}

