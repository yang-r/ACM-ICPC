/*
题目描述
小A同学现在被困在了一个迷宫里面，他很想从迷宫中走出来，他可以向上、向下、向左、向右移动、每移动一格都需要花费1秒的时间，不能够走到边界之外。假设小A现在的位置在S，迷宫的出口在E，迷宫可能有多个出口。问小A想要走到迷宫出口最少需要花费多少秒？
输入
有多组测试数据。
第一行输入两个正整数H（0 < H <= 100）和W（0 < W <= 100），分别表示迷宫的高和宽。
接下来H行，每行W个字符（其中‘*’表示路，‘#’表示墙，‘S’表示小A的位置，‘E’表示迷宫出口）。
当H与W都等于0时程序结束。
输出
输出小A走到迷宫出口最少需要花费多少秒，如果永远无法走到出口则输出“-1”。
样例输入
3 3
S*#
**#
#*E
0 0
样例输出
4
*/




#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>
#include<string.h>
using namespace std;

struct q {
	int x1, y1;
	int step;
};
char mg[105][105];
bool vis[105][105] = { 0 };   //标记是否走过
int s1, s2;
int num = 1;

int bfs(int x, int y) {
	int arr[4][2] = { 1,0,-1,0,0,1,0,-1 };
	 q{ x, y, 0 };
	vis[x][y] = 1;     //传的值做标记
	queue<q> check;
	check.push(q{x,y,0});
	int flag = 0;
	int ans = -1;
	while (!check.empty() && !flag) {
		q p= check.front();
		check.pop();
		if(mg[p.x1][p.y1] == 'E') {
			ans = p.step;
			break;
		}
		int nx, ny;
		for (int i = 0; i < 4; i++) {           //四个方向的判断
			nx = p.x1 + arr[i][0];
			ny = p.y1 + arr[i][1];
			if (mg[nx][ny] == '#')
				continue;
			else {
				if (!vis[nx][ny]) {
					vis[nx][ny] = 1;
					check.push(q{nx,ny,p.step+1}); //此处计数是当前（p所能到达的下一个地方）的值加上1。   存放的也是p的下一步 
				}
			}
		}
	}
	return ans;
}


int main() {
	int h, w;
	while (scanf_s("%d%d", &h, &w) != EOF && (h || w)) {
		getchar();
		memset(mg, '#', sizeof(mg));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < h; i++) {
			gets_s(mg[i]);
		}
		int flag = 0;
		for (int i = 0; i < h; i++) {
			if (!flag)
				for (int j = 0; j < w; j++) {
					if (mg[i][j] == 'S') {
						s1 = i;
						s2 = j;
						flag = 1;
						break;
					}
				}
		}
		int cnt;
		cnt = bfs(s1, s2);
		printf("%d\n", cnt);
	}
	return 0;
}
