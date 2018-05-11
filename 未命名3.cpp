
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
		//将起点到其他点的距离赋给"其他" 
    dis[1] = 0;  
    for(int a = 1; a <= n; a++)  
    {  
        int k = -1;  
        for(int b = 1; b <= n; b++)  
        {    
            if(!vis[b] && (k==-1 || dis[b]<dis[k])) 
			 //找未标记的点及当前距离最小的点  
                k = b;  
        }  
        if(k == -1) break;  //遍历完所有的点 
        vis[k] = true;    //标记 
        for(int q = 1; q <= n; q++)  
        {  int p;
        	p=dis[k]+g[k][q];
            if(!vis[q]) dis[q] = min(dis[q],p);
			 //更新从k出发的所有的边    
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
		//将vis数组初始化为0，当做标记数组  
        for(int i = 1; i <= n; i++)  
            for(int j = 1; j <= n; j++)  
            {  
                if(i == j) g[i][j] = 0;  
                else g[i][j] = INF;  
                //将g数组中；不相同点之间的距离初始化为无穷大 
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
// if(!vis[b])中！vis为逻辑判断，除了0（非）其余皆视为真 
