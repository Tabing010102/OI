#include <fstream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 10000+10;
const LL maxm = 1000+10;
fstream fin, fout;
LL n, m, k;
LL d[maxn];
LL tIme[maxm], from[maxm], to[maxm];
LL spn[maxn];//i->i+1????????(station_passing_num)
LL rt[maxn];//?i???????(real_tIme)
LL stwt[maxn];//?i??????(station_total_wait_tIme)
LL sr[maxn];//????(station_raking)
bool cmp(const int &a, const int &b) {
	if(spn[a] == spn[b]) return stwt[a]<stwt[b];
	else return spn[a]>spn[b];
}
int main() {
	fin.open("bus.in", ios::in);
	fout.open("bus.out", ios::out);
	fin >> n >> m >> k;
	for(LL i = 1; i < n; i++) fin >> d[i];
	for(LL i = 1; i <= m; i++) {
		fin >> tIme[i] >> from[i] >> to[i];
		if(tIme[i] > rt[from[i]]) {
			stwt[from[i]] += spn[i]*(tIme[i]-rt[from[i]]);
			rt[from[i]] = tIme[i];
		} else stwt[from[i]] += rt[from[i]]-tIme[i];
		for(LL j = from[i]; j < to[i]; j++) spn[j]++;
	}
//	for(LL i = 1; i <= m; i++)
//		fout << i << ": from=" << from[i] << ", to=" << to[i] << ", time=" << tIme[i] << endl; 
	for(LL i = 0; i < n; i++)
		rt[i+1] = max(rt[i+1], rt[i]+d[i]);
//	for(LL i = 1; i <= n; i++) fout << rt[i] << ' ';
//	fout << endl;
//	fout << "stwt:";
//	for(LL i = 1; i <= n; i++) fout << stwt[i] << ' ';
//	fout << endl;
	for(LL i = 1; i <= n; i++) sr[i] = i;
	sort(sr+1, sr+n, cmp);
	/*
	LL p = 1;
	while(k > 0) {//?????
		if(k >= d[sr[p]]) {
			k -= d[sr[p]];
			d[sr[p]] = 0;
			p++;
		} else {
			d[sr[p]] -= k;
			k = 0;
		}
	}
	*/
	LL p = 1;
	while(k > 0) {
		LL L=p, R=p;
		while(spn[sr[R+1]] == spn[sr[L]]) R++;
		while(d[sr[R]]>0 && k>0) {
			for(LL i = L; i <= R; i++) {
				if(k == 0) break;
				if(d[sr[i]] > 0) {
					d[sr[i]]--;
					k--;
				} else continue;
			}
		}
		p = L+1;
	}
//	fout<< "After speedup, d:";
//	for(LL i = 1; i < n; i++) fout << d[i] << ' ';
//	fout << endl;
	LL ans = 0;
	for(LL i = 1; i <= m; i++) {
		LL nt = tIme[i];
		for(LL j = from[i]; j < to[i]; j++) {
			ans += rt[j]-nt;
//			fout << "rt[j=" << j << "]=" << rt[j] << ' ';
//			fout << "nt=" << nt << ' ';
//			fout << "Value=" << rt[j]-nt << ' ';
//			fout << "ans=" << ans << ' ';
			nt = rt[j];
//			fout << "d[j]=" << d[j] << ' ';
			ans += d[j];
			nt += d[j];
//			fout << "ans=" << ans << ", nt=" << nt << endl;
		}
	}
	fout << ans;
	return 0;
}
