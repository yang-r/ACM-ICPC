#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 100010
using namespace std;
typedef long long LL;
int a[N];       //ԭ����
int sorted[N];  //����õ�����
//��һ����������ͬһ��ķ���һ�������
int num[20][N];   //num[i] ��ʾiǰ���ж��ٸ����������
int val[20][N];   //20��,ÿһ��Ԫ���ŷţ�0�����ԭ����
void build(int l,int r,int ceng)
{
  if(l==r) return ;
  int mid=(l+r)/2,isame=mid-l+1;  //isame�����ж��ٺ�sorted[mid]һ���������������
  for(int i=l;i<=r;i++) if(val[ceng][i]<sorted[mid]) isame--;
  int ln=l,rn=mid+1;   //������������ӽ��Ŀ�ͷ��ln��
  for(int i=l;i<=r;i++)
  {
    if(i==l) num[ceng][i]=0;
    else num[ceng][i]=num[ceng][i-1];
    if(val[ceng][i]<sorted[mid] || val[ceng][i]==sorted[mid]&&isame>0)
    {
      val[ceng+1][ln++]=val[ceng][i];
      num[ceng][i]++;
      if(val[ceng][i]==sorted[mid]) isame--;
    }
    else
    {
      val[ceng+1][rn++]=val[ceng][i];
}
  }
  build(l,mid,ceng+1);
  build(mid+1,r,ceng+1);
}


int look(int ceng,int sl,int sr,int l,int r,int k)
{
  if(sl==sr) return val[ceng][sl];
  int ly;  //ly ��ʾl ǰ���ж���Ԫ�ؽ�������
  if(l==sl) ly=0;  //����˵��غ�ʱ
  else ly=num[ceng][l-1];
  int tolef=num[ceng][r]-ly;  //��һ��l��r֮���������������tolef��
  if(tolef>=k)
  {
    return look(ceng+1,sl,(sl+sr)/2,sl+ly,sl+num[ceng][r]-1,k);
  }
  else
  {
    // l-sl ��ʾlǰ���ж��������ټ�ly ��ʾ��Щ����ȥ���������ж��ٸ�
    int lr = (sl+sr)/2 + 1 + (l-sl-ly);  //l-r ȥ�ұߵĿ�ͷλ��
    // r-l+1 ��ʾl��r�ж���������ȥȥ��ߵģ�ʣ����ȥ�ұߵģ�ȥ�ұ�1�����±����lr�����Լ�1
    return look(ceng+1,(sl+sr)/2+1,sr,lr,lr+r-l+1-tolef-1,k-tolef);
  }
}

int main()
{
  int n,m,l,r,k;
  while(scanf("%d%d",&n,&m)!=EOF)
  {

    for(int i=1;i<=n;i++)
    {
      scanf("%d",&val[0][i]);
      sorted[i]=val[0][i];
    }
    sort(sorted+1,sorted+n+1);
    build(1,n,0);
    while(m--)
    {
      scanf("%d%d%d",&l,&r,&k);
      printf("%d\n",look(0,1,n,l,r,k));
    }
  }
  return 0;
}
