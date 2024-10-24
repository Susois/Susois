#include <iostream>
#include <vector>
#include <string>
using namespace std;
class MonAn //Lớp món ăn
{
private:
    string TenMon;
    double GiaMon;
public:
    MonAn(string ten, double gia) : TenMon(ten), GiaMon(gia) {}
    string getTenMon() const {return TenMon;}
    double getGiaMon() const {return GiaMon;}
};
class BanAn //Lớp bàn ăn
{
private:
    int SoBan;
    bool TinhTrang;
public:
    BanAn(int so) : SoBan(so), TinhTrang(false) {}
    int getSoBan() const {return SoBan;}
    bool getTrangThai() const {return TinhTrang;}
    void DatBan() {TinhTrang=true;}
    void DonBan() {TinhTrang=false;}
};
class HoaDon //Lớp hóa đơn
{
private:
    vector<pair<MonAn, int>> dsMonAn;
    double TongTien;
public:
    HoaDon() : TongTien(0.0) {}
    void ThemMonAn(const MonAn& mon, int soLuong) 
    {
        dsMonAn.push_back(make_pair(mon, soLuong));
        TongTien += mon.getGiaMon() * soLuong;
    }
    double getTongTien() const {return TongTien;}
    void hienThiHoaDon() const 
    {
        cout<<"Hoa don chi tiet:\n";
        for (auto& mon : dsMonAn) 
        {
            cout<<"- "<<mon.first.getTenMon()<<" x "<< mon.second
                <<" : "<<mon.first.getGiaMon()*mon.second<<" VND\n";
        }
        cout<<"Tong tien: "<<TongTien<<" VND\n";
    }
    bool HoaDonTrong() const //Hóa đơn trống
    {
        return dsMonAn.empty();
    }
};
class HeThongBep //Lớp hệ thống bếp
{
public:
    void ThongBaoMonAn(const MonAn& mon, int soLuong) 
    {
        cout<<"Bep nhan duoc don: "<<mon.getTenMon()<<" x "<<soLuong<<endl;
    }
};
class NhanVien //Lớp nhân viên
{
private:
    string Ten;
    int SoGioLam;
    double LuongTheoGio;
public:
    NhanVien(string t, int gio, double Luong) : Ten(t), SoGioLam(gio), LuongTheoGio(Luong) {}
    double TinhLuong() const 
    {
        return SoGioLam*LuongTheoGio;
    }
    string getTen() const 
    {
        return Ten;
    }
};
class QuanLyNhanVien //Lớp quản lý nhân viên
{
private:
    vector<NhanVien> dsNhanVien;
public:
    void ThemNhanVien(const string& TenNhanVien, int SoGio, double Luong) 
    {
        dsNhanVien.push_back(NhanVien(TenNhanVien, SoGio, Luong));
    }
    void HienThiNhanVien() const 
    {
        if (dsNhanVien.empty()) 
        {
            cout<<"Danh sach nhan vien hien tai khong co nhan vien nao.\n";
        }
        else 
        {
            cout<< "Danh sach nhan vien:\n";
            for (const auto& nv : dsNhanVien) 
            {
                cout<<"- "<<nv.getTen()<<" - Luong: "<<nv.TinhLuong()<<" VND\n";
            }
        }
    }
    bool CoNhanVien() const 
    {
        return !dsNhanVien.empty();
    }
};
class QuanLyNhaHang //Quản lý thực đơn, đặt bàn, thanh toán và quản lý nhân viên
{
private:
    vector<MonAn> ThucDon;
    vector<BanAn> dsBanAn;
    vector<HoaDon> dsHoaDon;
    HeThongBep bep;
    QuanLyNhanVien qlNhanVien;
    bool BanDaDuocDat;
public:
    QuanLyNhaHang(int SoBan) : BanDaDuocDat(false) 
    {
        for (int i=1; i<=SoBan; ++i) 
        {
            dsBanAn.push_back(BanAn(i));
            dsHoaDon.push_back(HoaDon()); //Tạo một hóa đơn trống cho mỗi bàn
        }
    }
    void ThemMonAn() 
    {
        string TenMon;
        double GiaMon;
        cout<<"Nhap ten mon an: ";
        cin.ignore();
        getline(cin, TenMon);
        cout<<"Nhap gia mon an: ";
        cin>>GiaMon;
        ThucDon.push_back(MonAn(TenMon, GiaMon));
    }
    void HienThiThucDon() const 
    {
        if (ThucDon.empty()) 
        {
            cout<<"Thuc don hien tai khong co mon an nao.\n";
        }
        else
        {
            cout<<"Thuc don:\n";
            for (size_t i=0; i<ThucDon.size(); ++i) 
            {
                cout<<i+1<<". "<<ThucDon[i].getTenMon()<<" - "<<ThucDon[i].getGiaMon()<<" VND\n";
            }
        }
    }
    bool CoMonAn() const 
    {
        return !ThucDon.empty();
    }
    void DatBan() 
    {
        if (!CoMonAn()) 
        {
            cout<<"Chua co mon an trong thuc don. Vui long them mon truoc khi dat ban.\n";
            return;
        }
        int SoBan;
        cout<<"Nhap so ban can dat: ";
        cin>>SoBan;
        if (SoBan<=dsBanAn.size() && !dsBanAn[SoBan-1].getTrangThai()) 
        {
            dsBanAn[SoBan-1].DatBan();
            BanDaDuocDat=true;
            cout<<"Ban so "<<SoBan<<" da duoc dat.\n";
        }
        else
        {
            cout<<"Ban so "<<SoBan<<" khong co san hoac da duoc dat.\n";
        }
    }
    bool DaCoBanDat() const 
    {
        return BanDaDuocDat;
    }
    void ThanhToan(int SoBan) 
    {
        if (SoBan<=dsBanAn.size() && dsBanAn[SoBan-1].getTrangThai()) 
        {
            if (dsHoaDon[SoBan-1].HoaDonTrong()) 
            {
                cout<<"Chua co mon an nao duoc goi cho ban nay.\n";
                return;
            }
            dsHoaDon[SoBan-1].hienThiHoaDon();
            dsBanAn[SoBan-1].DonBan();
            dsHoaDon[SoBan-1]=HoaDon(); //Tạo hóa đơn mới sau khi thanh toán
            BanDaDuocDat=false;  //Khi thanh toán, không còn bàn nào được đặt
            cout<<"Ban so "<<SoBan<<" da duoc thanh toan va don ban.\n";
        }
        else 
        {
            cout<<"Ban so "<<SoBan<<" chua duoc su dung.\n";
        }
    }
    void goiMon(int SoBan, int monId, int soLuong) 
    {
        if (SoBan<=dsBanAn.size() && dsBanAn[SoBan-1].getTrangThai()) 
        {
            if (monId>0 && monId<=ThucDon.size()) 
            {
                MonAn mon = ThucDon[monId-1];
                dsHoaDon[SoBan-1].ThemMonAn(mon, soLuong);
                bep.ThongBaoMonAn(mon, soLuong);
            }
            else
            {
                cout<<"Mon an khong ton tai.\n";
            }
        }
        else
        {
            cout<<"Ban so "<<SoBan<<" chua duoc su dung.\n";
        }
    }
    void ThemNhanVien() //Tích hợp quản lý nhân viên
    {
        string TenNhanVien;
        int SoGio;
        double Luong;
        cout<<"Nhap ten nhan vien: ";
        cin.ignore();
        getline(cin, TenNhanVien);
        cout<<"Nhap so gio lam: ";
        cin>>SoGio;
        cout<<"Nhap Luong theo gio: ";
        cin>>Luong;
        qlNhanVien.ThemNhanVien(TenNhanVien, SoGio, Luong);
    }
    void HienThiNhanVien() const 
    {
        if (!qlNhanVien.CoNhanVien()) 
        {
            cout <<"Chua co nhan vien nao trong danh sach. Vui long them nhan vien.\n";
        }
        else
        {
            qlNhanVien.HienThiNhanVien();
        }
    }
};
int main() 
{
    int SoBan;
    cout<<"Nhap so Luong ban: ";
    cin>>SoBan;
    QuanLyNhaHang NhaHang(SoBan);
    int LuaChon;
    do 
    {
        cout<<"\nMenu:\n";
        cout<<"1. Them mon an\n";
        cout<<"2. Hien thi thuc don\n";
        cout<<"3. Dat ban\n";
        cout<<"4. Goi mon\n";
        cout<<"5. Thanh toan\n";
        cout<<"6. Them nhan vien\n";
        cout<<"7. Hien thi nhan vien\n";
        cout<<"8. Thoat\n";
        cout<<"Nhap lua chon: ";
        cin>>LuaChon;
        switch (LuaChon) 
        {
            case 1:
                NhaHang.ThemMonAn();
                break;
            case 2:
                NhaHang.HienThiThucDon();
                break;
            case 3:
                NhaHang.DatBan();
                break;
            case 4:
            {
                if (!NhaHang.CoMonAn()) 
                {
                    cout << "Chua co ban nao duoc dat. Vui long dat ban truoc khi goi mon.\n";
                }
                else if (!NhaHang.DaCoBanDat())
                {
                    cout << "Chua co ban nao duoc dat. Vui long dat ban truoc khi goi mon.\n";
                }
                else
                {
                    int SoBan, SoHieuMon, SoLuong;
                    cout<<"Nhap so ban: ";
                    cin>>SoBan;
                    cout<<"Nhap ID mon an: ";
                    cin>>SoHieuMon;
                    cout<<"Nhap so Luong: ";
                    cin>>SoLuong;
                    NhaHang.goiMon(SoBan, SoHieuMon, SoLuong);
                }
                break;
            }
            case 5:
            {
                if (!NhaHang.CoMonAn()) 
                {
                    cout << "Chua co ban nao duoc su dung. Vui long goi mon truoc khi thanh toan.\n";
                }
                else if (!NhaHang.DaCoBanDat()) 
                {
                    cout << "Chua co ban nao duoc su dung. Vui long goi mon truoc khi thanh toan.\n";
                }
                else 
                {
                    int SoBan;
                    cout<<"Nhap so ban: ";
                    cin>>SoBan;
                    NhaHang.ThanhToan(SoBan);
                }
                break;
            }
            case 6:
                NhaHang.ThemNhanVien();
                break;
            case 7:
                NhaHang.HienThiNhanVien();
                break;
            case 8:
                cout<<"Thoat chuong trinh.\n";
                break;
            default:
                cout<<"Lua chon khong hop le.\n";
                break;
        }
    }
    while (LuaChon!=8);
    return 0;
}

