#include <cstdio>
#include <cstring>

using namespace std;
typedef long long l;

char buf[1000000];
l n;

bool check_1100(l i) {
	if (i < 0) return false;
	if (i >= n - 3) return false;
	if (buf[i] == '1' && buf[i + 1] == '1' && buf[i + 2] == '0' && buf[i + 3] == '0') return true;
	return false;
}

void solve() {
	scanf("%s", buf);
	n = strlen(buf);
	l count = 0;
	for (l i = 0; i < n; i++)
		if (check_1100(i)) count++;
	
	l q; scanf("%lld", &q);
	while (q--) {
		l i, v; scanf("%lld %lld", &i, &v); i--;
		if (buf[i] != '0' + v) {
		    bool before = check_1100(i - 3) || check_1100(i - 2) || check_1100(i - 1) || check_1100(i);
		    buf[i] = '0' + v;
		    bool after = check_1100(i - 3) || check_1100(i - 2) || check_1100(i - 1) || check_1100(i);
		    count += after - before;
		}
		printf(count ? "YES\n" : "NO\n");
	}
}

int main() {
	l t; scanf("%lld", &t);
	while (t--) solve();
}