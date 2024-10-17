
// cài đặt ngây thơ với độ phức tạp O(n)
void make_set(int v)
{
    parent[v] = v; // tạo ra cây mới có gốc là đỉnh v
}

int find_set(int v)
{
    if(v==parents[v])return v; // trả về đỉnh v nếu như đinihr v là gốc của cây
    return find_set(parent[v]) // đệ quy lên cha của đỉnh v
}


void union_sets(int a,int b)
{
    a = find_set(a); // tìm gốc của cây có chứa đỉnh a
    b = find_set(b); // tìm gốc của cây có chứa đỉnh b
    if(a != b )parent[b] = a; // gộp 2 cây nếu như 2 phần tử ở 2 cây khác nhau
}


// tối ưu 1 - gộp theo kích cỡ / độ cao


// tối ưu theo kích cỡ
 void make_set(int v)
 {
    parentd [v] = v;
    sz[v] = 1; // ban đầu tập hợp chứa v có kích cỡ là 1
 }

 void union_sets(int a, int b)
 {
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(sz[a] <sz[b])swap(a,b);// đặt biến a là gốc của cây có kích cỡ lớn hơn
        parent[b] = a;
        sz[a] +=sz[b]; // cập nhât kích cỡ của cây mới gộp lại
    }
 }

 // tối ưu theo độ cao
  void make_set(int v)
  {
    parent[v] = v;
    rank[v] = 0;// gốc của cây có độ cao là 0;
}

 void union_sets(int a,int b)
 {
    a = find_set(a);
    b = find_set(b);

    if(a!=b)
    {
        if(rank[a]< rank[b])swap(a,b); // đặt biến a là gốc của cây có độ cao lớn hơn
        parent[b] = a;
        if(rank[a]==rank[b])rank[a]++;  // nếu như 2 cây có cùng 1 độ cao, độ cao mới sau khi gộp sẽ tăng 1
    }
 }

 // tối ưu 2 - nén đường đi

int find_set(int v)
{
    if( v == parent[v]) return v; // tra ve dinh v neu nhu dinh v la goc cua cay
    int p=find_set(parent[v]);  // de quy len cha cua dinh v
    parent[v] = p; // nén đoạn từ v lên gốc của cây
    return p;
}

// cài đặt khác tương đương
int find_set(int v)
{
    return v ==parent[v] ? v : parent[v] = find_set(parent[v]);
}