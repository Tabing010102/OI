#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> s;
int n, t;
string ts;

void find(string &ts) {
	int tl = ts.length();
	for(int i = 0; i < tl; i++)
		if(ts[i] == '*') {
			for(int j = 'a'; j <= 'z'; j++) {
				ts[i] = j;
				//cout << "ts=" << ts << endl;
				if(s.count(ts)) { cout << "YES" << endl; return; }
			}
			cout << "NO" << endl; return;
		}
	if(s.count(ts)) { cout << "YES" << endl; return; }
	else { cout << "NO" << endl; return; }
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t >> ts;
		if(t == 1) s.insert(ts);
		else find(ts);
	}
	return 0;
}
