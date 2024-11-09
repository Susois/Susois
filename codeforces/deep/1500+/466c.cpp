#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n;cin>>n;
    long long s=0;
    vector<int> se(n+1);
    vector<int> pref(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>se[i];
        s+=se[i];
    }
    if(s%3!=0){
        cout<<0;
        return 0;
    }
    int cnt=0,k=s/3;
    for(int i=1;i<=n;i++)pref[i]=pref[i-1]+se[i];
    for(int i=1;i<n;i++){
        if(pref[i+1]-pref[i]==k)cnt++;
    }
    cout<<cnt;
}