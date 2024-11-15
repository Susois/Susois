#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;cin>>n;
    vector<int> se(n);
    queue<int> q;
    int cnt=0;
    for(int i=0;i<n;i++)cin>>se[i];
    for(int i=0;i<n-1;i++){
        bool check = true;
        for(int j=i+1;j<n;j++){
            if(se[i]==se[j]){check = false;break;}
        }
        if(check){
            q.push(se[i]);
            cnt++;
        }
    }
    q.push(se[n-1]);
    cout<<q.size()<<'\n';
    for(int i=0;i<=cnt;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}