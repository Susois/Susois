#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++){cin>>s[i];}
    sort(s.begin(),s.end(),[&](const string &a, const string &b){
        return a.size() < b.size();
    });
    for(int i=0;i<n-1;i++){
        if(s[i+1].find(s[i])==string::npos){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<'\n';
    for(int i=0;i<n;i++){
        cout<<s[i]<<'\n';
    }
    return 0;
}