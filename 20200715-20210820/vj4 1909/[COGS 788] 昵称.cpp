#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int n;
string s;
map<string, int> ma;
map<string, int>::iterator it;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s;
		for(int j = 0; j < s.size(); j++) s[j] = tolower(s[j]);
		ma[s]++;
	}
	for(it = ma.begin(); it != ma.end(); it++)
		cout << it->first << ' ' << it->second << endl;
	return 0;
}
