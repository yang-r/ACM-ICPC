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
	int a[] = { 1,2,3,4,4,5,5,5,6,6,6,6 };//下标从零开始  二分查找
	int result = (lower_bound(a, a + 12, 1) - a); // lower_bound(（范围+查找值）-数组开头)  大于或等于查找值的数的下标
	cout << " 1 "<<result << endl;//result 1 0
	result = (lower_bound(a, a + 12, 3) - a);
	cout << " 3"<<result << endl;// result : 3 2
	result = (lower_bound(a, a + 12, 4) - a);
	cout <<  " 4 "<<result << endl; // result   4: 3
	result = (upper_bound(a, a + 12, 5) - a);// upper_bound: 大于查找值的下标
	cout << " 5: "<<result << endl;     // result 5: 8
	result = (upper_bound(a, a + 12, 8) - a);//没有找到则返回最后end  即（坐标：12）
	cout << result << endl;
	int n=unique(a,a+12) -a;  //”去重“将相同的数放在数组的最后面
	//此处是将去重后的数据个数传给n。unique(范围)-数组名。 
	cout<<n<<endl;            // n=6
	for(int i=0;i<12;i++)
	cout<<a[i]<<" ";         //结果：1 2 3 4 5 6（隔开） 5 5 6 6 6 6
	cout<<endl;      
	return 0;
}

