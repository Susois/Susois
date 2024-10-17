void make_set(int v)
{
    parent[v]  = v;
    sz[v] = 1;
    mx[v] = v;
}

int find_set(int v)
{
    return v == parent[v] ? v :parent[v] = find_set(parent[v]);
}

void union_sets(int a,int b)
{
    a = find_set(a);
    b=  find_set(b);
    if(a!=b)
    {
        if(sz[a]<sz[b])swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
        mx[a] =  max(mx[z],mx[b]);
    }
}

void leave(int v) // nguoi thu v roi khoi hang
{
    union_sets(v,v+1);
}
int find_nex(int p)
{
    // tra ve thu tu cua nguoi gan nhat ve ben phai vi tri p ma chua roi khoi hang
     p = find_set(p);
     return mx[p];
}