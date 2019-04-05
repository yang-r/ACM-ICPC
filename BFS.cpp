/*
��Ŀ����
СAͬѧ���ڱ�������һ���Թ����棬��������Թ����߳��������������ϡ����¡����������ƶ���ÿ�ƶ�һ����Ҫ����1���ʱ�䣬���ܹ��ߵ��߽�֮�⡣����СA���ڵ�λ����S���Թ��ĳ�����E���Թ������ж�����ڡ���СA��Ҫ�ߵ��Թ�����������Ҫ���Ѷ����룿
����
�ж���������ݡ�
��һ����������������H��0 < H <= 100����W��0 < W <= 100�����ֱ��ʾ�Թ��ĸߺͿ�
������H�У�ÿ��W���ַ������С�*����ʾ·����#����ʾǽ����S����ʾСA��λ�ã���E����ʾ�Թ����ڣ���
��H��W������0ʱ���������
���
���СA�ߵ��Թ�����������Ҫ���Ѷ����룬�����Զ�޷��ߵ������������-1����
��������
3 3
S*#
**#
#*E
0 0
�������
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
bool vis[105][105] = { 0 };   //����Ƿ��߹�
int s1, s2;
int num = 1;

int bfs(int x, int y) {
	int arr[4][2] = { 1,0,-1,0,0,1,0,-1 };
	 q{ x, y, 0 };
	vis[x][y] = 1;     //����ֵ�����
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
		for (int i = 0; i < 4; i++) {           //�ĸ�������ж�
			nx = p.x1 + arr[i][0];
			ny = p.y1 + arr[i][1];
			if (mg[nx][ny] == '#')
				continue;
			else {
				if (!vis[nx][ny]) {
					vis[nx][ny] = 1;
					check.push(q{nx,ny,p.step+1}); //�˴������ǵ�ǰ��p���ܵ������һ���ط�����ֵ����1��   ��ŵ�Ҳ��p����һ�� 
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
