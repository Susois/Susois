#include <bits/stdc++.h>
using namespace std;
 
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0); cout.tie(0);
 
bool se[32];
memset(se,false,sizeof(se));
 
int q; cin>>q;
while(q--)
{int u,v;cin>>u>>v;
 
 long long res=0;
if(u==1) se[v] = true;
else if(u==2) se[v] = false;
else se[v] = 1-se[v] ;
for(int i=0;i<32;i++)if(se[i]) res += pow(2,i);
cout<<res<<endl;
}
	return 0;
}