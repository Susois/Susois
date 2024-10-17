#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 1;
int parent[maxn];
ll sum[maxn]; 
void make_set(int v)
{
    parent[v] = v;
    sum[v] = v; 
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void unions_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sum[a] < sum[b]) 
            swap(a, b);
        parent[b] = a; 
        sum[a] += sum[b]; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    // Khởi tạo tập hợp ban đầu cho các đỉnh
    for (int i = 1; i <= n; i++) make_set(i);

    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            int u, v;
            cin >> u >> v;
            unions_sets(u, v);
        }
        if (k == 2)
        {
            int u;
            cin >> u;
            cout << sum[find_set(u)] << "\n"; // In ra tổng đỉnh trong thành phần liên thông chứa u
        }
    }

    return 0;
}
