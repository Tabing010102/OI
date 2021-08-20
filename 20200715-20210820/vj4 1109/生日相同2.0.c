#include <stdio.h>
#include <string.h>

#define MAXN 180+10
#define LENMAX 20+5

struct St {
	char name[LENMAX];
	int month, day;
}d[MAXN];

int n, i, j, lastp, is_print=0;

int isbigger(int a, int b) {//a>b
	if(d[a].month == d[b].month) {
		if(d[a].day == d[b].day) {
			if(strlen(d[a].name) == strlen(d[b].name)) {
				return (strcmp(d[a].name, d[b].name)>0);
			} else return strlen(d[a].name) > strlen(d[b].name);
		} else return d[a].day > d[b].day;
	} else return d[a].month > d[b].month;
}

void swap(int a, int b) {
	int tmpm, tmpd; char buf[LENMAX];
	tmpm = d[a].month; tmpd = d[a].day; strcpy(buf, d[a].name);
	d[a].month = d[b].month; d[a].day = d[b].day; strcpy(d[a].name, d[b].name);
	d[b].month = tmpm; d[b].day = tmpd; strcpy(d[b].name, buf);
}

void print(int st, int end) {
	if(!is_print) is_print = 1;
	printf("%d %d", d[st].month, d[st].day);
	int i; for(i = st; i <= end; i++) printf(" %s", d[i].name);
	printf("\n");
}

int is_same_day(int a, int b) { return d[a].month==d[b].month && d[a].day==d[b].day; }

int main() {
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%s%d%d", d[i].name, &d[i].month, &d[i].day);
	for(i = 0; i < n-1; i++) for(j = 0; j < n-i-1; j++) if(isbigger(j, j+1)) swap(j, j+1);
	lastp = 0;
	for(i = 1; i < n; i++) {
		if(!is_same_day(i, lastp)) {
			if(i-lastp > 1) print(lastp, i-1);
			lastp = i;
		}
	}
	if(n-lastp > 1) print(lastp, n-1);
	if(!is_print) printf("None\n");
	return 0;
}
