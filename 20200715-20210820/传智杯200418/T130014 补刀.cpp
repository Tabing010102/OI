#include <iostream>

using namespace std;

typedef long long LL;

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		LL h, x, y;
		cin >> h >> x >> y;
		if(h <= 0) cout << "Yes" << endl;
		else if(y <= 0) cout << "No" << endl;
		else if(x <= 0) cout << "Yes" << endl;
		else {
			LL s=h/x, left=h%x;
			if(left <= 0) { s--; left+=x; }
			if(left <= y) { cout << "Yes" << endl; continue; }
			LL t1=left/y; if(left > t1*y) t1++;
			if(t1 > s+1) cout << "No" << endl;
			else cout << "Yes" << endl;
		}
	}
	return 0;
}
