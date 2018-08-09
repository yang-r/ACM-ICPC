#include<iostream>
using namespace std;
void merge(int *data, int start, int mid, int end, int *result)
{
	int i, j, k;
	i = start;
	j = mid + 1;                        //�����ظ��Ƚ�data[mid]
	k = 0;
	while (i <= mid && j <= end)        //����data[start,mid]������(mid,end]��û��ȫ����������result��ȥ
	{
		if (data[i] <= data[j])         //���data[i]С�ڵ���data[j]
			result[k++] = data[i++];    //��data[i]��ֵ����result[k]��֮��i,k����һ����ʾ����һλ
		else
			result[k++] = data[j++];    //���򣬽�data[j]��ֵ����result[k]��j,k����һ
	}
	while (i <= mid)                    //��ʾ����data(mid,end]�Ѿ�ȫ������result������ȥ�ˣ�������data[start,mid]����ʣ��
		result[k++] = data[i++];        //������data[start,mid]ʣ�µ�ֵ����һ��������result
	while (j <= end)                    //��ʾ����data[start,mid]�Ѿ�ȫ�����뵽result������ȥ�ˣ�������(mid,high]����ʣ��
		result[k++] = data[j++];        //������a[mid,high]ʣ�µ�ֵ����һ��������result

	for (i = 0; i < k; i++)             //���鲢��������ֵ��һ��������data[start,end]
		data[start + i] = result[i];    //ע�⣬Ӧ��data[start+i]��ʼ��ֵ
}
void merge_sort(int *data, int start, int end, int *result)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		merge_sort(data, start, mid, result);                    //����߽�������
		merge_sort(data, mid + 1, end, result);                  //���ұ߽�������
		merge(data, start, mid, end, result);                    //������õ����ݺϲ�
	}
}
void amalgamation(int *data1, int *data2, int *result)
{
	for (int i = 0; i < 10; i++)
		result[i] = data1[i];
	for (int i = 0; i < 10; i++)
		result[i + 10] = data2[i];
}
int main()
{
	int data1[10] = { 1,7,6,4,9,14,19,100,55,10 };
	int data2[10] = { 2,6,8,99,45,63,102,556,10,41 };
	int *result = new int[20];
	int *result1 = new int[20];
	amalgamation(data1, data2, result);
	for (int i = 0; i < 20; ++i)
		cout << result[i] << "  ";
	cout << endl;
	merge_sort(result, 0, 19, result1);
	for (int i = 0; i < 20; ++i)
		cout << result[i] << "  ";
	delete[]result;
	delete[]result1;
	return 0;
}