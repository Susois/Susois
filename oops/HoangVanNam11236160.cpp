#include<bits/stdc++.h>
using namespace std;

class sinh_vien{
protected:
    string msv;
    string hoten;
    float dtb;
    static int count;
public:
    sinh_vien(string mvs = "", string hoten = "",float dtb =0.0):msv(mvs), hoten(hoten), dtb(dtb) {
        count++;
    }

    virtual ~sinh_vien(){
        count--;
    }

    virtual void nhap(){
        cout<<"nhap MSV(co 5 ky tu): ";cin>>msv;
        cout<<"nhap Ho Ten: ";cin.ignore();getline(cin,hoten);
    }

    virtual void xuat(){
        // cout<<"MSV: "<<msv<<endl;
        // cout<<"Ho Ten: "<<hoten<<endl;
        // cout<<"Diem Trung Binh: "<<dtb<<endl;
        int demsokhoangcach = hoten.length();
        int demsomsv = msv.length();
        // cout<<"|   "<<msv<<"   |    "<<hoten<<"   |   "<<dtb<<"    |"<<'\n';
        // cout<<"|   "<<msv<<"   |";
        demsomsv = 12- demsomsv;
        int temp = demsomsv/2;
        for(int i=1;i<=temp;i++)cout<<" ";cout<<msv;
        for(int i=1;i<=temp+1;i++)cout<<" ";cout<<"|";
        demsokhoangcach = 30 - demsokhoangcach;
        int tmp = demsokhoangcach/2;
        for(int i=1;i<=tmp;i++)
        cout<<" ";
        cout<<hoten;
        for(int i=1;i<=tmp;i++)
        cout<<" ";
        cout<<"|    "<<dtb<<"      |"<<'\n';
        
    }

    static int Dem(){
        return count;
    }

    bool operator<(const sinh_vien& other)const{
        return dtb < other.dtb;
    }

    virtual void tinhdiemtrungbinh() = 0;
};

int sinh_vien::count = 0;


class hoc_truc_tiep: public sinh_vien{
private: 
    float danh_gia, kiem_tra, thi;
public:
    void nhap(){
        sinh_vien::nhap();
        cout<<"nhap Diem Danh Gia: ";cin>>danh_gia;
        cout<<"nhap DIem Kiem Tra: ";cin>>kiem_tra;
        cout<<"nhap Diem Thi: ";cin>>thi;
        tinhdiemtrungbinh();
    }
    void tinhdiemtrungbinh() {
        dtb = 0.1 * danh_gia + 0.4 * kiem_tra + 0.5 * thi;
    }
};
class hoc_truc_tuyen: public sinh_vien{
private:
    float bai_tap_lon, thuyet_trinh;
public:
    void nhap(){
        sinh_vien::nhap();
        cout<<"nhap Diem Bai Tap Lon: ";cin>>bai_tap_lon;
        cout<<"nhap Diem Thuyet Trinh: ";cin>>thuyet_trinh;
        tinhdiemtrungbinh();
    }
    void tinhdiemtrungbinh() {
        dtb = 0.5 * bai_tap_lon + 0.5* thuyet_trinh;
    }

};
    void danhsachsv(vector<sinh_vien*> &students){
        cout<<"---------------------------------------------------------------------"<<'\n';
        cout<<"|   Stt   |   Ma SV    |          Ho va ten           |   Diem Tb   |"<<'\n';
        for(size_t i=0; i <students.size();i++){
            cout<<"|    "<<i+1<<"    |";
            students[i]->xuat();
        }
        cout<<"---------------------------------------------------------------------"<<'\n';
        cout<<'\t'<<"Tong so sinh vien: "<<sinh_vien::Dem()<<endl;
    }
int main(){
    vector<sinh_vien*> students;
    int n, se;
    cout<<"Nhap so sinh vien: ";cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Sinh vien thu: "<<i+1<<'\n'<<'\t'<<"Chon chuong trinh theo hoc (1 - Hoc truc tiep, 2 - Hoc truc tuyen): ";cin>>se;
        sinh_vien* sv = nullptr;

        if(se==1){
            sv = new hoc_truc_tiep();
        }
        else if(se==2){
            sv = new hoc_truc_tuyen();
        }

        if(sv){
            sv->nhap();
            students.push_back(sv);
        }
    }
    sort(students.begin(),students.end(), [](sinh_vien*a,sinh_vien*b){
        return *a<*b;
    });
    danhsachsv(students);
    for(auto sv: students){
        delete sv;
    }
    return 0;

}
