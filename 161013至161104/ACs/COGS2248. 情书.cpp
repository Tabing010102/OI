#include <fstream>
#include <string>
using namespace std;
const int maxn = 100+10;
int n;
string str[maxn];
string tmp;
fstream fin, fout;
int main() {
	fin.open("lettera.in", ios::in);
	fout.open("lettera.out", ios::out);
	fin >> n;
	for(int i = 0; i < n; i++) fin >> str[i];
	while(fin >> tmp) {
		bool flag = true;
		for(int i = 0; i < n; i++)
			if(tmp.find(str[i]) == string::npos) {
				fout << "No" << endl;
				flag = false;
				break;
			}
		if(flag) fout << "Yes" << endl;
	}
	return 0;
}
