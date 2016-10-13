#include <cstdio>
using namespace std;
const int maxn = 5000+10;
const int INF = 50000+100;
int x[maxn], n, m;
FILE *fin, *fout;
inline int max(int a, int b) { return a<b?b:a; }
inline int min(int a, int b) { return a<b?a:b; }
bool check(int v) {
    int tot = 0;
    for(int i = 1; i <= n; i++) tot += x[i]/v;
    return tot >= m;
}
int main() {
//     fin = fopen("chocolate.in", "r");
//     fout = fopen("chocolate.out", "w");
    fin = stdin; fout = stdout;
    fscanf(fin, "%d%d", &n, &m);
    int _min = INF, _max = 0;
    for(int i = 1; i <= n; i++) {
        fscanf(fin, "%d", &x[i]);
        _min = min(_min, x[i]);
        _max = max(_max, x[i]);
    }
    int L = _min, R = _max, M;
    while(L < R-1) {
        M = L + (R-L)/2;
        if(check(M)) L = M;
        else R = M-1;
    }
    int ans;
    if(check(R)) ans = R;
    else ans = L;
    fprintf(fout, "%d", ans);
    return 0;
}
