#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	set<int> el;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (!el.count(x)) {
			ans.push_back(i);
			el.insert(x);
		}
	}
	
	if (int(ans.size()) < k) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i = 0; i < k; ++i)
			cout << ans[i] + 1 << " ";
		cout << endl;
	}
	
	return 0;
}