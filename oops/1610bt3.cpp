#include<bits/stdc++.h>
using namespace std;

class nguoi{
    private:
        int mst;
        char hoten[50];
        long long luong;
    // protected:
    //     char maso[5];
    //     float luong;
    public:
        nguoi()= default;
        nguoi(int a, string b, long long c)
        {
            mst = a;
            strcpy(hoten, b.c_str());
            luong = c;
        }
};

class Bienche:public nguoi {
    private: 
        float hesoluong;
        long long tienphucap;
        char chucvu[50];
    public:
        Bienche()=default;
        Bienche(float a, long long b, string c)
        {
            hesoluong = a;
            tienphucap = b;
            strcpy(chucvu, c.c_str());
        }
};

class hopdong: public nguoi{
    private:
        long long tiencong;
        int songaylamviec;
        float hesovuotgio;
    public:
        hopdong() = default;
        hopdong(long long a, int b, float c)
        {
            tiencong = a;
            songaylamviec = b;
            hesovuotgio = c;
        }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


}