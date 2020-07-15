#include <iostream>

using namespace std;

const int maxn = 1e6+10;

int d[maxn], n, d2[maxn];
int d3[maxn][2];
long long ans=0;

int max(int a) { return a<0?-a:a; }

int main() {
	//cout << "ans = " << ans << endl;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> d[i];
	d[0] = d[n+1] = -1;
	int cntp=0, op=1;
	while(1) {
		int num = 1;
		while(d[op] == d[op+1]) { num++; op++; }
		cntp++;
		d3[cntp][0] = d[op];
		d3[cntp][1] = num;
		op++;
		if(op > n) break;
	}
	int nn = cntp;
	d3[0][0] = 0x7fffffff; d3[nn+1][0] = -1;
	/*int cntp=0, Ll=0, Rl=0, glastp=0;
	while(1) {
		int lastp = cntp;
		while(1) {
			while(d[cntp] == d[cntp+1]) { cntp++; }
			while(d[cntp] < d[cntp+1]) { Ll++; cntp++; }
			if(cntp == lastp) break;
			else lastp = cntp;
		}
		lastp = cntp;
		while(1) {
			while(d[cntp] == d[cntp+1]) { cntp++; }
			while(d[cntp] > d[cntp+1]) { Rl++; cntp++; }
			if(cntp == lastp) break;
			else lastp = cntp;
		}
		if(Ll > Rl) {
			
		}
	}*/
	//cout << "ans = " << ans << endl;
	/*cntp = 1;
	while(1) {
		//cout << "ans = " << ans << endl;
		while(d[cntp] > d[cntp+1]) cntp++;
		d2[cntp] = 1; int lastp = cntp;
		while(1) {
			while(d[cntp] == d[cntp+1]) { d2[cntp+1] = d2[cntp]; cntp++; }
			while(d[cntp] < d[cntp+1]) { d2[cntp+1] = d2[cntp]+1; cntp++; }
			if(lastp == cntp) break;
			else lastp = cntp;
		}
		if(cntp > n) break;
		//cout << cntp << endl;
	}
	//cout << "ans = " << ans << endl;
	cntp = n;
	while(1) {
		while(1) {
			while(d[cntp] > d[cntp-1]) cntp--;
		}
		d2[cntp] = 1; int lastp = cntp;
		while(1) {
			while(d[cntp] == d[cntp-1]) { d2[cntp-1] = max(d2[cntp], d2[cntp-1]); cntp--; }
			while(d[cntp] < d[cntp-1]) { d2[cntp-1] = max(d2[cntp]+1, d2[cntp-1]); cntp--; }
			if(lastp == cntp) break;
			else lastp = cntp;
		}
		if(cntp < 1) break;
		//cout << cntp << endl;
	}*/
	cntp = 1;
	while(1) {
		//cout << "ans = " << ans << endl;
		while(d3[cntp][0] > d3[cntp+1][0]) cntp++;
		d2[cntp] = 1; int lastp = cntp;
		while(1) {
			//while(d[cntp] == d[cntp+1]) { d2[cntp+1] = d2[cntp]; cntp++; }
			while(d3[cntp][0] < d3[cntp+1][0]) { d2[cntp+1] = d2[cntp]+1; cntp++; }
			if(lastp == cntp) break;
			else lastp = cntp;
		}
		if(cntp > nn) break;
		//cout << cntp << endl;
	}
	//cout << "ans = " << ans << endl;
	cntp = nn;
	while(1) {
		while(d3[cntp][0] > d3[cntp-1][0]) cntp--;
		d2[cntp] = 1; int lastp = cntp;
		while(1) {
			//while(d[cntp] == d[cntp-1]) { d2[cntp-1] = max(d2[cntp], d2[cntp-1]); cntp--; }
			while(d3[cntp][0] < d3[cntp-1][0]) { d2[cntp-1] = max(d2[cntp]+1, d2[cntp-1]); cntp--; }
			if(lastp == cntp) break;
			else lastp = cntp;
		}
		if(cntp < 1) break;
		//cout << cntp << endl;
	}
	//cout << "ans = " << ans << endl;
	//for(int i = 1; i <= nn; i++) cout << d3[i][1] << ' '; cout << endl;
	//for(int i = 1; i <= nn; i++) cout << d3[i][0] << ' '; cout << endl;
	//for(int i = 1; i <= nn; i++) cout << d2[i] << ' '; cout << endl;
	ans = 0;
	for(int i = 1; i <= nn; i++) ans += d2[i]*d3[i][1];
	cout << ans;
	return 0;
}
