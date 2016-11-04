/*
状态定义：f[i]为剩余量为i时 
状态转移方程： f[i] = max(f[i], f[i-w[i]]+v[i]);
答案：f[0]; 
*/
#include <cstdio>
using namespace std;
const int maxn = 500+10;
const int maxH = 45000+10;
int H, n, w[maxn], v[maxn], f[maxH];
FILE *fin, *fout;
inline int max(int a, int b) { return a < b ? b : a; }
int main() {
	fin = fopen("diet.in", "r");
	fout = fopen("diet.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d", &H, &n);
	for(int i = 1; i <= n; i++) {
		int a; 
		fscanf(fin, "%d", &a);
		w[i] = v[i] = a;
	}
	for(int i = 1; i <= n; i++) 
		for(int j = H; j >= 0; j--) 
			if(j >= w[i]) f[j] = max(f[j], f[j-w[i]]+v[i]);
	fprintf(fout, "%d", f[H]);
	return 0;
}
