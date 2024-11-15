// #include<bits/stdc++.h>
// using namespace std;
// void solve(){
//     int k; cin>>k;
//     vector<pair<int, pair<int,int>>> se;
//     for(int i=0;i<k;i++){
//         int n;cin>>n;
//         vector<int> a(n);
//         for(int j=0;j<n;j++){
//             cin>>a[j];
//         }
//         int sum = accumulate(a.begin(), a.end(),0);
//         for(int j=0;j<n;j++){
//             se.push_back(make_pair(sum-a[j],make_pair(i,j)));
//         }
//     }
//         stable_sort(se.begin(), se.end());
//         for(int i =0;i<se.size() - 1;i++){
//             if(se[i].first == se[i+1].first  && se[i].second.first != se[i+1].second.second){
//                 cout<<"YES"<<endl;
//                 cout<<se[i+1].second.first + 1<<" "<<se[i+1].second.second+1<<endl;
//                 cout<<se[i].second.first + 1<<" "<<se[i].second.second+1<<endl;
//                 return;
//             }
//         }
//     cout<<"NO\n";
//     return ; 
// }
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     solve();
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int k;
	cin >> k;
	vector<pair<int, pair<int, int>>> a;
	for (int i = 0; i < k; ++i) {
		int n;
		cin >> n;
		vector<int> x(n);
		for (int j = 0; j < n; ++j)
			cin >> x[j];
		int sum = accumulate(x.begin(), x.end(), 0);
		for (int j = 0; j < n; ++j)
			a.push_back(make_pair(sum - x[j], make_pair(i, j)));
	}
	
	stable_sort(a.begin(), a.end());
	for (int i = 0; i < int(a.size()) - 1; ++i) {
		if (a[i].first == a[i + 1].first && (a[i].second.first != a[i + 1].second.first)) {
			cout << "YES" << endl;
			cout << a[i + 1].second.first + 1 << " " << a[i + 1].second.second + 1 << endl;
			cout << a[i].second.first + 1 << " " << a[i].second.second + 1 << endl;
			return 0;
		}
	}
	
	cout << "NO\n";
	
	return 0;
}