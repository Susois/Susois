/*
stack:
    class: int st[n];
            int tmp;
    method:
        - hàm tạo, hàm hủy
        - is Empty() - kiểm tra stack có rỗng không
        - is Full() - kiem tra stack co đầy hay không
        - Push(int x)
        - Pop()
        - printstack();
    class Doicoso stack
        int n;
        - dcs2()
        - dcs8();
        - dcs16();
*/
#include<bits/stdc++.h>
using namespace std;
class int_stack
{
    private: 
        int elems[100];
        int tmp;
        int top;
    public: 
        int_stack() = default;
        // int_stack();
        bool isEmpty();
        bool isFull();
        void Push(int elem);
        int Pop();
        void Printstack();


};
bool int_stack::isEmpty() 
{
    bool ok = false;
    if(top<0)ok = true;
    return (ok);
}

bool int_stack::isFull()
{
    bool ok = false;
    if(top==99)ok=true;
    return (ok);
}

void int_stack::Push(int elem)
{
    if(!isFull())
    {
        top++;
        elems[top] = elem;
    }
}

int int_stack::Pop()
{
    int bf;
    if(!isEmpty())
    {
        bf = elems[top];
        top--;
    }
    return bf;
}

void int_stack::Printstack()
{
    while(!isEmpty())
    {
        cout<<Pop();
    }
}
int main()
{
    int_stack st;
    for(int i=1;i<10;i++)
    {
        st.Push(i);
    }
    cout<<endl<<"noi dung stack: ";
    st.Printstack();
    getchar();
        return 0;
}