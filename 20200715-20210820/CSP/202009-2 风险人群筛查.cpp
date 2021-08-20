#include <cstdio>

int n, k, t, x1, y1, x2, y2, ans1=0, ans2=0;

bool isin(int x, int y) { return x>=x1&&x<=x2&&y>=y1&&y<=y2; }

int main() {
	scanf("%d%d%d%d%d%d%d", &n, &k, &t, &x1, &y1, &x2, &y2);
	for(int i = 0; i < n; i++) {
		int cont=0, cnum=0;
		bool isstay=false, ispass=false;
		for(int j = 0; j < t; j++) {
			int tx, ty;
			scanf("%d%d", &tx, &ty);
			if(isin(tx, ty)) {
				ispass = true;
				if(cont) { cnum++; }
				else { cont=1; cnum=1; }
			} else {
				if(cont) { cont=0; cnum=0; }
			}
			if(cnum >= k) isstay = true;
		}
		if(ispass) {
			ans1++;
			if(isstay) ans2++;
		}
	}
	printf("%d\n%d", ans1, ans2);
	return 0;
}
