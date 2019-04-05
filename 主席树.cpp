��ϯ�����������õ��ĵ㣺
1.��ѯ�����k�����ߣ�
2.��ѯ�����k�����и��½ڵ���������ߣ�������Ҫ��Ϊ�˽��߶����ϵ�ֵ��ɢ���������ֵ��ΧС����Ҫ��ɢ����Ҳ����Ҫ���ߣ�������²�����Ҫ����״���飩
3.��ѯ���䲻ͬ���ĸ�������״�������ʵ�֣���ֻ�����ߣ���ϯ��ʵ�ֿ������ߣ�
���кܶ��߶�����ʵ�ֵģ�����һЩ����������������ϯ�����⡣
//poj2104
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1e5+100;

int a[maxn];
int rt[maxn];//rt[i]��ʾ������ǰi��Ԫ����ɵ��߶����ĸ����
struct node
{
    int l,r;//�߶��������ӽ���
    int sum;//�����Ϣ����ʾ����������ڵ�Ԫ�ص���Ŀ
}T[maxn*20];
int tot=0;//�����
vector<int> v;
int getid(int k)
{
    return lower_bound(v.begin(),v.end(),k)-v.begin()+1;
}
void build(int &o,int l,int r)//����һ�ſ���
{
    o=++tot;
    T[o].sum=0;
    if(l==r) return;
    int mid=(l+r)/2;
    build(T[o].l,l,mid);
    build(T[o].r,mid+1,r);
}
void update(int l,int r,int &now,int last,int k)
{
    T[++tot]=T[last];//�����߶���
    //���µ�ǰ�߶����ĸ����
    now=tot;
    T[tot].sum++;
    if(l==r) return;//�޸ĵ�Ҷ�ӽ��Ϊֹ
    //������Ҫ�޸ĵ�k��ȷ�����޸������������޸�������
    int mid=(l+r)/2;
    if(k<=mid)
        update(l,mid,T[now].l,T[last].l,k);
    else
        update(mid+1,r,T[now].r,T[last].r,k);
}
int query(int l,int r,int x,int y,int k)//��ѯ���䡾x��y���е�С����
{
    if(l==r) return l;//��ѯ��Ҷ�ӽ��Ϊֹ
    int mid=(l+r)/2;
    int cnt=T[T[y].l].sum-T[T[x].l].sum;//��y�����ȵ�x�������������϶�Ľ����
    if(cnt>=k)//������������
        return query(l,mid,T[x].l,T[y].l,k);
    else
        return query(mid+1,r,T[x].r,T[y].r,k-cnt);
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            v.push_back(a[i]);
        }
        //build(,1,n);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        build(rt[0],1,n);
        for(int i=1;i<=n;i++)
            update(1,n,rt[i],rt[i-1],getid(a[i]));
        while(m--)
        {
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            printf("%d\n",v[query(1,n,rt[x-1],rt[y],k)-1]);
        }
    }
    return 0;
}
