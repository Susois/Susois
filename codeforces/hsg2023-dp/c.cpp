// xcas định được bài toán con cơ sở đã có lời giải
// độ dài của dãy con tăng dài nhất kết thúc ở chỉ số i
// L[i] = 1 
// xét các phần tử trước i, đưa i vào dãy con tăng dần đứng trước nó hay không
#include<bits/stdc++.h>
using namespace std;
#define ll long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("in.inp","r",stdin);
    // freopen("out.out","w" ,stdout);

    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    vector<int> l(n,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i] > a[j])
            {
                l[i] = max(l[i], l[j]+1); 
            }
        }
    }
    
    cout<<*max_element(l.begin(),l.end())<<endl;

    return 0;
}