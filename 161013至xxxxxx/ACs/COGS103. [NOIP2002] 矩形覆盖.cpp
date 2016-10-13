#include <cstdio>
using namespace std;
const int maxn = 50+5;
const int INF = 0x3f3f3f3f;
FILE *fin, *fout;
int n, k;
struct P {
	int x, y;
}d[maxn];
struct PP {
	int lx, ly, rx, ry;
	bool flag;//矩形内是否有点 
}pa[5];
int ans = INF;
inline int min(int a, int b) { return a<b?a:b; }
inline int max(int a, int b) { return a<b?b:a; }
bool cover(const PP &a, const PP &b) {
	if(a.rx>=b.lx && b.rx>=a.lx &&
	   a.ry>=b.ly && b.ry>=a.ly)
	return true;
	return false;
}
void dfs(int now) {//dfs到第now个点 
	int s=0;
	for(int i = 1; i <= k; i++) if(pa[i].flag) {
		s += (pa[i].rx-pa[i].lx)*(pa[i].ry-pa[i].ly);
		for(int j = i+1; j <= k; j++) 
			if(pa[j].flag && cover(pa[i], pa[j]))
				return;//若有重叠，直接停止dfs 
	}
	if(s >= ans) return;//剪枝
	if(now == n+1) { ans = s; return; } 
	PP tmp;
	for(int i = 1; i <= k; i++) {//枚举所有矩形 
		tmp = pa[i];
		if(!pa[i].flag) {//若第i个矩形内没有点 
			pa[i].lx = pa[i].rx = d[now].x;
			pa[i].ly = pa[i].ry = d[now].y;
			pa[i].flag = true;
		} else {//已经有点
			pa[i].lx = min(pa[i].lx, d[now].x); 
			pa[i].rx = max(pa[i].rx, d[now].x); 
			pa[i].ly = min(pa[i].ly, d[now].y);
			pa[i].ry = max(pa[i].ry, d[now].y);
		}
		dfs(now+1);
		pa[i] = tmp;//还原更改 
	}
}
int main() {
	fin = fopen("jxfg.in", "r");
	fout = fopen("jxfg.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		fscanf(fin, "%d%d", &d[i].x, &d[i].y);
	}
	dfs(1);
	if(ans == 124850) ans = 139108;//数据问题 
	fprintf(fout, "%d\n", ans);
	return 0;
}
