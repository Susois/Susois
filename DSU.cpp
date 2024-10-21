#include<bits/stdc++.h>
#define ll long long
#define lli int64_t
#define fi first 
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define vec vector<int> 
#define pii pair<int,int>
#define re return
#define br break
#define fast                        \
ios_base::sync_with_stdio(false);   \
cin.tie(0);cout.tie(0);             
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
using namespace std;

int parent[N];
void make_set(int v)
{
    parent[v] = v;
    // sz[v] = 1; kich co
    // rank[v] = 0; // goc cua day co do cao la 0
}
int find_set(int v)
{
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void unions_sets(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        parent[a] = b; // hướng đi từ a tới b
        // if(sz[a] <sz[b])swap(a,b)// dat bien a la cay co kich co lon hon
        // sz[b] += sz[a]; //update kich co cua cay

        // if(rank[a]<rank[b])swap(a,b);    //dat bien a la goc cua cay co kich thuoc lon ho    
        // if(rank[a]==rank[b])rank[a]++;   // neu nhu 2 cay co kich thuoc bang nhau thi tang kich thuoc cay a len 1;
        
    }
}
int main()
{
    fast

    return 0;
}