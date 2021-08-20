#include <bits/stdc++.h>

using namespace std;

const string cmds1 = " < ./Input/in";
const string txt = ".txt";
const string cmds2 = " > ./Output/ans";

int main(int argc, char *argv[]) {
	if(argc != 2) exit(0);
	string exe = argv[1];
	for(int i = 0; i < 10; i++) {
		string cmd = exe + cmds1 + (char)(i+'0') + txt + cmds2 + (char)(i+'0') + txt;
		cout << cmd << endl;
		system(cmd.c_str());
	}
	return 0;
}
