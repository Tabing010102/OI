#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1000+10;
fstream fin, fout;
int n;
string d[maxn];
bool cmp(const string &s1, const string &s2) { return s1+s2 < s2+s1; }
int main() {
	fin.open("brick.in", ios::in);
	fout.open("brick.out", ios::out);
	fin >> n;
	for(int i = 1; i <= n; i++) fin >> d[i];
	sort(d+1, d+1+n, cmp);
	for(int i = n; i >= 1; i--) fout<<d[i];
	return 0;
}
