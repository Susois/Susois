#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int a,b;cin >> a >> b;
    deque<int> d;
    int aa = a;
    int sum = 0;
    while( a ){
        sum += a%10;
        d.push_front(a%10);
        a/=10;
    }
    if(sum<=b){
        cout<<"0\n";
        return;
    }
    a = aa;
    sum =0;
    for(int i=0;i<d.size();++i){
        sum += d[i];
        if(sum>=b){
            int res = 1;
            for(int j=0; j<d.size()-i;++j) res*=10;
            aa /= res;
            aa *=res;
            aa +=res;
            cout<<aa-a<<'\n';
            return;
        }
    }
}
#undef int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;
    while(t--)solve();
    return 0;
}