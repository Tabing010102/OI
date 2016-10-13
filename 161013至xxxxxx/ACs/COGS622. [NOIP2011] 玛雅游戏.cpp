/*
数据结构
6|
5|
4|
3|
2|
1|
0|
(2)---------
(1)0 1 2 3 4 
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
FILE *fin, *fout;
struct mayan {
	int G[5][7];
	void drop() {
		for(int i = 1; i < 7; i++) for(int j = 0; j < 5; j++)
			if(G[j][i]) {
				int k = i;//k可落到的最下面的空格
				while(k > 0 && G[j][k-1] == 0) k--;
				if(k < i) swap(G[j][i], G[j][k]); 
			}
	}
	bool check(){
		for(int i = 0; i < 5; i++) for(int j = 0; j < 7; j++)
			if(G[i][j]) return false;
		return true;
	}
	bool vis[5][7];
	bool clear() {
		bool flag = false;
		memset(vis, 0, sizeof(vis));
		//先消纵
		for(int i = 0; i < 5; i++) {
			int now, p=0, tmpp;
			while(p <= 4) {
				if(G[i][p+2] != G[i][p]) p++;
				else if(G[i][p] == 0) break;
				else {
					now = G[i][p]; tmpp = p;
					while(G[i][tmpp+1]==now && tmpp<6) tmpp++;
					if(tmpp-p+1 >= 3) {
						for(int k = p; k <= tmpp; k++) vis[i][k] = true;
						p = tmpp+1;
						flag = true;
					} else p++;
				}
			}
		}
		//再消横
		for(int i = 0; i < 7; i++) {
			int now, p=0, tmpp;
			while(p <= 2) {
				if(G[p+2][i] != G[p][i]) p++;
				else if(G[p][i] == 0) break;
				else {
					now = G[p][i]; tmpp = p;
					while(G[tmpp+1][i]==now && tmpp<4) tmpp++;
					if(tmpp-p+1 >= 3) {
						for(int k = p; k <= tmpp; k++) vis[k][i] = true;
						p = tmpp+1;
						flag = true;
					} else p++;
				}
			}
		}
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 7; j++)
				if(vis[i][j]) G[i][j] = 0;
		return flag;
	}
	void print_graph() {
		for(int i = 6; i >= 0; i--) {
			for(int j = 0; j < 5; j++)
				fprintf(fout, "%d ", G[j][i]);
			fprintf(fout, "\n");
		}
	}
}origin;
struct Step {
	int x, y, op;
};
vector<Step> steps;
int max_step;
void read(){
	fscanf(fin, "%d", &max_step);
	for(int i = 0; i < 5; i++) {
		int t=0, cnt = 0;
		fscanf(fin, "%d", &t);
		while(t != 0) {
			origin.G[i][cnt++] = t;
			fscanf(fin, "%d", &t);
		}
	}
}
void print_steps() {
	vector<Step>::iterator it;
	for(it = steps.begin(); it != steps.end(); it++)
		fprintf(fout, "%d %d %d\n", it->x, it->y, it->op);
}
struct Blank {
	int x, y;
};
//dfs字典序需分两种情况，把非空气向右移优先考虑
void dfs(mayan &now, int cnt_step) {
//	fprintf(fout, "dfs(cnt_step=%d)\n", cnt_step);
	if(cnt_step == max_step+1) {
		if(now.check()) { print_steps(); exit(0); }
		return;
	}
	queue<Blank> que;
	for(int i = 0; i <= 3; i++) for(int j = 0; j < 7; j++)
	if(now.G[i][j]!=0 || now.G[i+1][j]!=0) {
		mayan tmp = now;
		if(tmp.G[i][j] != 0) {
			if(!que.empty()) {
				Blank b = que.front();
				if(b.x<i && b.y<j) {
					que.pop();
					swap(tmp.G[b.x][b.y], tmp.G[b.x+1][b.y]);
					steps.push_back((Step){b.x+1, b.y, -1});
					tmp.drop();
					while(tmp.clear()) tmp.drop();
					dfs(tmp, cnt_step+1);
					steps.pop_back();
					tmp = now;
				}
			}
			steps.push_back((Step){i, j, 1});
		} else { que.push((Blank){i, j}); continue; }
		swap(tmp.G[i][j], tmp.G[i+1][j]);
//		fprintf(fout, "dfs(cnt_step=%d), x=%d, y=%d, op=1\n", cnt_step, i, j);
//		fprintf(fout, "Before drop&&clear:\n");
//		tmp.print_graph();
		tmp.drop();
		while(tmp.clear()) tmp.drop();
//		fprintf(fout, "After drop&&clear:\n");
//		tmp.print_graph();
		dfs(tmp, cnt_step+1);
		steps.pop_back();
	}
	while(!que.empty()) {
		Blank b = que.front();
		que.pop();
		mayan tmp = now;
		swap(tmp.G[b.x][b.y], tmp.G[b.x+1][b.y]);
		steps.push_back((Step){b.x+1, b.y, -1});
//		fprintf(fout, "dfs(cnt_step=%d), x=%d, y=%d, op=-1\n", cnt_step, b.x+1, b.y);
//		fprintf(fout, "Before drop&&clear:\n");
//		tmp.print_graph();
		tmp.drop();
		while(tmp.clear()) tmp.drop();
//		fprintf(fout, "After drop&&clear:\n");
//		tmp.print_graph();
		dfs(tmp, cnt_step+1);
		steps.pop_back();
	}
}
int main() {
	fin = fopen("mayan.in", "r");
	fout = fopen("mayan.out", "w");
//	fout = stdout;
	read();
//	origin.print_graph();
	dfs(origin, 1);
	fprintf(fout, "-1\n");
//	fprintf(fout, "Before clear:\n");
//	origin.print_graph();
//	origin.clear();
//	fprintf(fout, "After clear:\n");
//	origin.print_graph();
	return 0;
}
