#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int maxn = 1000+10;
const int maxk = 26+5;
const double eps = 1e-5;

struct Stu {
	int score;
	int team;
	Stu(int a=0, int b=0): score(a), team(b) {};
}d[maxn];
int d2[maxk][maxk];
double tt[maxk];
double tt2[maxk];
int tt3[maxk];
int n, k;

double abs2(const double a) { return a<0?-a:a; }

bool cmp(const Stu &a, const Stu &b) {
	if(a.score != b.score) return a.score>b.score;
	else return a.team<b.team;
}

int main() {
	scanf("%d%d", &n ,&k);
	for(int i = 0; i < n; i++) {
		int t; char buf[10];
		scanf("%d%s", &t, buf);
		d[i].score = t;
		d[i].team = buf[0]-'A';
	}
	for(int i = 0; i < k; i++) for(int j = 0; j < k; j++) scanf("%d", &d2[j][i]);
	//for(int i = 0; i < k; i++) { for(int j = 0; j < k; j++) printf("%d ", d2[i][j]); printf("\n"); }
	memset(tt, 0, sizeof(tt));
	for(int i = 0; i < k; i++)
		for(int j = 0; j < k; j++) {
			tt[i] += d2[i][j];
		}
	for(int i = 0; i < k; i++) tt[i] /= (double)k;
	//for(int i = 0; i < k; i++) printf("%lf ", tt[i]); printf("\n");
	for(int i = 0; i < k; i++) {
		int cntn = 0;
		for(int j = 0; j < k; j++)
			if(abs2(d2[i][j]-tt[i])-15.0 <= eps) {
				//printf("%d: %d\n", i, d2[i][j]);
				tt2[i] += d2[i][j];
				cntn++;
			}
		tt2[i] /= cntn;
	}
	for(int i = 0; i < k; i++) tt3[i] = round(tt2[i]);
	//for(int i = 0; i < k; i++) printf("%lf ", tt2[i]); printf("\n");
	for(int i = 0; i < n; i++)
		d[i].score = round(0.6*d[i].score + 0.4*tt3[d[i].team]);
	sort(d, d+n, cmp);
	bool first = true;
	for(int i = 0; i < n; i++) {
		if(!first) printf("\n");
		if(first) first = false;
		printf("%d %c", d[i].score, d[i].team+'A');
	}
	return 0;
}
