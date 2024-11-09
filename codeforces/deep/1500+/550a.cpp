#include<bits/stdc++.h>
using namespace std;
bool checkk= false;
void solve(){
    string s;cin>>s;
    vector<int> cntab,cntba;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]=='A'&&s[i+1]=='B')cntab.push_back(i);
        if(s[i]=='B'&&s[i+1]=='A')cntba.push_back(i);
    }
    for(int i=0;i<cntab.size();i++){
        for(int j=0;j<cntba.size();j++){
            if(abs(cntab[i]-cntba[j])>=2){
                checkk = true;
                return ;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    if(checkk)cout<<"YES";
    else cout<<"NO";
    return 0;
}