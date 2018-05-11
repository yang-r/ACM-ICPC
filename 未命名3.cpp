
#include <stdio.h>    
#include <string.h>  
#include <iostream>  
  
using namespace std;  
  
  
  
const int N = 1000;  
const int INF = 0x3f3f3f3f;  
  
int dis[N], g[N][N], n, s;  
bool vis[N];  
  
void dijkstra()  
{  
    for(int a= 1; a <= n; a++)  
        dis[a] = g[1][a];  
		//����㵽������ľ��븳��"����" 
    dis[1] = 0;  
    for(int a = 1; a <= n; a++)  
    {  
        int k = -1;  
        for(int b = 1; b <= n; b++)  
        {    
            if(!vis[b] && (k==-1 || dis[b]<dis[k])) 
			 //��δ��ǵĵ㼰��ǰ������С�ĵ�  
                k = b;  
        }  
        if(k == -1) break;  //���������еĵ� 
        vis[k] = true;    //��� 
        for(int q = 1; q <= n; q++)  
        {  int p;
        	p=dis[k]+g[k][q];
            if(!vis[q]) dis[q] = min(dis[q],p);
			 //���´�k���������еı�    
        }   
    }  
    printf("%d\n", dis[n]);  
}  
  int main()  
{  
     
    int m, e, w;  
    while(scanf("%d%d", &n, &m)!=EOF)  
    {  
        if(n == 0 && m == 0) break;  
        memset(vis, 0, sizeof(vis));
		//��vis�����ʼ��Ϊ0�������������  
        for(int i = 1; i <= n; i++)  
            for(int j = 1; j <= n; j++)  
            {  
                if(i == j) g[i][j] = 0;  
                else g[i][j] = INF;  
                //��g�����У�����ͬ��֮��ľ����ʼ��Ϊ����� 
            }  
        for(int i = 1; i <= m; i++)  
        {  
            scanf("%d%d%d", &s, &e, &w);  
            g[s][e] = g[e][s] = w;  
        }  
        dijkstra();
		}
		return 0; 
}
// if(!vis[b])�У�visΪ�߼��жϣ�����0���ǣ��������Ϊ�� 
