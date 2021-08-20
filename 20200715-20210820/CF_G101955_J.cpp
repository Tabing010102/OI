#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

const char types[8][15] = { "bool", "char", "int", "long long", "__int128", "float", "double", "long double" };
const int type_length[8] = { 4, 4, 3, 9, 8, 5, 6, 11 };
const int type_size[8] = { 1, 2, 4, 8, 16, 4, 8, 16 };
const int buf_size = 50;

int T, n, t, tt, cnt_size, cnt, ans;
//char buf[buf_size];
bool ok;
string buf;

int main() {
	scanf("%d", &T);
	for(int TT = 1; TT <= T; TT++) {
		ans = 0;
		scanf("%d", &n);
		fflush(stdin);
		for(int k = 1; k <= n; k++) {
			//memset(buf, 0, sizeof(buf));
			buf.clear();
			//gets(buf);
			getline(cin, buf);
			fflush(stdin);
			//while(buf[0] == 0) gets(buf);
			//cnt_size = strlen(buf);
			cnt_size = buf.size();
			for(int i = 0; i < 8; i++) {
				if(cnt_size <= type_length[i]) continue;
				ok = true;
				for(int j = 0; j < type_length[i]; j++) if(types[i][j] != buf[j]) { ok = false; break; }
				if(!ok) continue;
				else {
					if(buf[cnt_size-2] == ']') {
						cnt = cnt_size-3;
						tt = 1; t = 0;
						while(isdigit(buf[cnt])) { t += tt*(buf[cnt]-'0'); tt *= 10; cnt--; }
						ans += type_size[i]*t;
					} else {
						ans += type_size[i];
					}
					//printf("k=%d, type=%d\n", k, i);
					break;
				}
			}
		}
		//printf("ans=%d\n", ans);
		printf("Case #%d: %.0f\n", TT, ceil(ans/1024.0));
		fflush(stdout);
	}
	return 0;
}
