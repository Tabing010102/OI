#include<fstream>
#include<string>
#include<set>
using namespace std;
string s1, s2, s3;
char p[26];
set<char>sc;
fstream fin, fout;
int main(){
	fin.open("spy.in", ios::in);
	fout.open("spy.out", ios::out);
	fin >> s2 >> s1 >> s3;
	for(int i = 0; i <= s2.size()-1; i++)
		if(p[s2[i]-'A'] && p[s2[i]-'A']!=s1[i]) { fout << "Failed"; return 0; }
		else p[s2[i]-'A'] = s1[i];
	for(int i = 0; i <= 25; i++)
		if(!p[i]) { fout << "Failed"; return 0; }
		else sc.insert(p[i]);
	if(sc.size() != 26) { fout << "Failed"; return 0; }
	for(int i = 0; i <= s3.size()-1; i++) fout.put(p[s3[i]-'A']);
	return 0;
}
