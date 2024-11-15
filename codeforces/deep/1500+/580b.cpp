#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n,m;cin>>n>>m;
    vector<tuple<long long,long long>> se(n);
    for(int i=0;i<n;i++){
        auto &&[x,y]  = se[i];
        cin>>x>>y;
    }

    sort(se.begin(),se.end());
    long long dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0] = get<1>(se[0]);
    for(int i=1;i<n;i++){
        // dp[i] = dp[i-1];
        dp[i] = get<1>(se[i]);
        for(int j=0;j<i;j++){
            if(get<0>(se[i]) - get<0>(se[j]) <=m){
                dp[i] = max(dp[i],get<1>(se[i])+dp[j]);
            }
        }
    }
    cout<<*max_element(dp,dp+n+1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    solve();
    return 0;

}

// #include<iostream>
// #include<math.h>
// #include<algorithm>
// #include<stdio.h>
// #include<map>
// #include<vector>
// #include<set>
// #include<iomanip>
// #define F first
// #define S second
// #define P system("PAUSE");
// #define H return 0;
// #define pb push_back
// using namespace std;
// const long long A=100000000000000LL,N=228228;

// char e[21];
// vector<string> ot;
// pair<int,pair<int,string> > a[N];
// long long o,p[3]={-1,-1,-1};
// int i,j,l,r,n,m;

// int main(){
// 	cin>>n>>m;
// 	for(i=0;i<n;++i){
// 	    scanf("%d%d",&a[i].F,&a[i].S.F);
// 	    a[i].S.S=e;
// 	}
// 	sort(a,a+n);
// 	for(l=0;l<n;o-=a[l].S.F,++l){
// 		while(r<n && abs(a[l].F-a[r].F)<m)o+=a[r].S.F,++r;
// 		if(o>=p[0])p[0]=o,p[1]=l,p[2]=r;
// 	}
// 	for(i=p[1];i<p[2];++i)ot.pb(a[i].S.S);
// 	cout<<p[0]<<"\n";
// }