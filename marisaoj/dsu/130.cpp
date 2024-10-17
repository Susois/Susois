#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 1;
int parent[maxn];

void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void unions_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        parent[a] = b; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            unions_sets(b, c);
        }
        if (a == 2)
        {
            if (find_set(b) == find_set(c)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}
