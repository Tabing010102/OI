#include <cstdio>
#include <queue>
using namespace std;
const int maxx = 182+3+10;
const int INF = 500+10;
const int cx[] = { 1, -1, 0, 0 };
const int cy[] = { 0, 0, 1, -1 };
FILE *fin, *fout;
int n, m, G[maxx][maxx], d[maxx][maxx];
//1ÊÇ°×É«µÄ 
char buf[maxx];
inline int abs(int a) { return a<0?-a:a; }
struct P {
	int xx, yy;
};
queue<P> q;
int main() {
	fin = fopen("bit.in", "r");
	fout = fopen("bit.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		fscanf(fin, "%s", buf);
		for(int j = 0; j < m; j++)
			if(buf[j] == '0') { G[i][j+1] = 0; d[i][j+1] = INF; }
			else { G[i][j+1] = 1; d[i][j+1] = 0; }
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
	if(G[i][j] == 1) q.push((P){i, j});
	while(!q.empty()) {
		P x = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			int x1=x.xx+cx[i], y1=x.yy+cy[i];
			if(x1>=1 && x1<=n && y1>=1 && y1<=m) {
				if(d[x1][y1] == INF) {
					d[x1][y1] = d[x.xx][x.yy]+1;
					q.push((P){x1, y1});
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) fprintf(fout, "%d ", d[i][j]);
		fprintf(fout, "\n");
	}
	return 0;
}
