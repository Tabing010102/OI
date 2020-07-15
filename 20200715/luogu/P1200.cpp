#include <cstdio>
#include <cstring>

char s1[10], s2[10];
int d1=1, d2=1, l1, l2;

int main() {
	scanf("%s%s", s1, s2);
	l1 = strlen(s1);
	l2 = strlen(s2);
	for(int i = 0; i < l1; i++) d1 *= (int)s1[i]-'A'+1;
	for(int i = 0; i < l2; i++) d2 *= (int)s2[i]-'A'+1;
	if(d1%47 == d2%47) printf("GO\n");
	else printf("STAY\n");
	return 0;
}
