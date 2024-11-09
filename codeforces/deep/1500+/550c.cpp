#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;cin>>s;
    int tmp;
    if(s.length()==1){
        tmp = s[0]-'0';
        if(tmp%8==0)cout<<"YES"<<'\n'<<s[0];
        else cout<<"NO";
        return;
    }
    else if(s.length()==2){
        tmp = (s[0]-'0')*10 + s[1]-'0';
        if(tmp%8==0){cout<<"YES"<<'\n'<<s[0]<<s[1];return;}
        if(s[0]=='0' || s[1]=='0'){
            cout<<"YES"<<'\n'<<0;
            return;
        }
        cout<<"NO";
        return;
    }
    for(int i=0;i<s.length();i++){
        tmp = s[i] -'0';
        if(tmp%8==0){cout<<"YES"<<'\n'<<tmp;
        return;}
    }
    int tmp2=0;
    for(int i=0;i<s.length()-1;i++){
        for(int j=i+1;j<s.length();j++){
            tmp2= (s[i]-'0')*10 +  (s[j]-'0');
            if(tmp2 %8==0){
                cout<<"YES"<<'\n';
                cout<<tmp2;
                return;
            }
        }
    }
    int tmp3=0;
    for(int i=0;i<s.length()-2;i++){
        for(int j=i+1;j<s.length()-1;j++){
            for(int k=j+1;k<s.length();k++){
                tmp3 = (s[i]-'0')*100 + (s[j]-'0')*10+ s[k]-'0';
                if(tmp3%8==0){
                    cout<<"YES"<<'\n';
                    cout<<tmp3;
                    return;
                }
        }
    }
    }
    cout<<"NO"<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}