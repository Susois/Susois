#include <bits/stdc++.h>
#include <string>
using namespace std;

class MonAn
{
private:
    string TenMon;
    double GiaMon;
public:
    MonAn() : TenMon(""), GiaMon(0.0) {}
    MonAn(string ten, double gia) : TenMon(ten), GiaMon(gia) {}
    string getTenMon() const {return TenMon;}
    double getGiaMon() const {return GiaMon;}
};

class BanAn
{
private:
    int SoBan;
    bool TinhTrang; // True nếu bàn đã được đặt, false nếu chưa
public:
    BanAn(int so=0) : SoBan(so), TinhTrang(false) {}
    int getSoBan() const {return SoBan;}
    bool getTrangThai() const {return TinhTrang;}
    void DatBan() {TinhTrang = true;}
    void DonBan() {TinhTrang = false;}
};

class HoaDon
{
private:
    MonAn* DsMonAn;
    int* SoLuong;
    int SoMon;
    double TongTien;
public:
    HoaDon(int SoLuongMon=10) : DsMonAn(new MonAn[SoLuongMon]), SoLuong(new int[SoLuongMon]), SoMon(0), TongTien(0.0) {}
    ~HoaDon() {delete[] DsMonAn; delete[] SoLuong;}

    void ThemMonAn(const MonAn& mon, int sl)
    {
        DsMonAn[SoMon] = mon;
        SoLuong[SoMon] = sl;
        TongTien += mon.getGiaMon() * sl;
        SoMon++;
    }

    void XoaMonAn(int index)
    {
        if (index>=0 && index<SoMon)
        {
            TongTien = DsMonAn[index].getGiaMon() * SoLuong[index];
            for (int i=index; i<SoMon-1; i++)
            {
                DsMonAn[i] = DsMonAn[i+1];
                SoLuong[i] = SoLuong[i+1];
            }
            SoMon--;
        }
        else
        {
            cout<<"Mon an khong co trong thuc don.\n";
        }
    }

    double getTongTien() const {return TongTien;}

    void hienThiHoaDon() const
    {
        cout<<"Hoa don chi tiet:\n";
        for (int i=1; i<SoMon; i++)
        {
            cout<<"- "<<DsMonAn[i].getTenMon()<<" x "<<SoLuong[i]
                <<": "<<DsMonAn[i].getGiaMon() * SoLuong[i]<<" VND\n";
        }
        cout<<"Tong tien: "<<TongTien<<" VND\n";
    }

    bool HoaDonTrong() const
    {
        return SoMon==0;
    }
};

// Lớp quản lý danh sách cơ bản với mảng động
template <typename T>
class QuanLiDanhSach
{
protected:
    T* DanhSach;
    int SoLuong;
    int KichThuoc;
public:
    QuanLiDanhSach(int kt=10) : KichThuoc(kt), SoLuong(0)
    {
        DanhSach = new T[KichThuoc];
    }
    ~QuanLiDanhSach() {delete[] DanhSach;}

    void Them(const T& obj)
    {
        if (SoLuong < KichThuoc)
        {
            DanhSach[SoLuong++] = obj;
        }
        else
        {
            cout<<"Danh sach day, khong the them.\n";
        }
    }

    void Xoa(int index)
    {
        if (index>=0 && index<SoLuong)
        {
            for (int i=index; i<SoLuong-1; i++)
            {
                DanhSach[i] = DanhSach[i+1];
            }
            SoLuong--;
        }
        else
        {
            cout<<"Vi tri khong hop le.\n";
        }
    }

    T& operator[](int index) {return DanhSach[index];}
    const T& operator[](int index) const {return DanhSach[index];}
    int getSoLuong() const {return SoLuong;}
};

class QuanLiMonAn : public QuanLiDanhSach<MonAn>
{
public:
    QuanLiMonAn(int kt=10) : QuanLiDanhSach(kt) {}

    void HienThiThucDon() const
    {
        cout<<"Thuc don:\n";
        for (int i=0; i<SoLuong; i++)
        {
            cout<<i+1<<". "<<DanhSach[i].getTenMon()<<" - "<< DanhSach[i].getGiaMon()<<" VND\n";
        }
    }

    void XoaMonAn(int index)
    {
        Xoa(index);  // Sử dụng phương thức Xoa đã có trong lớp cơ sở
    }
};

class QuanLiBanAn : public QuanLiDanhSach<BanAn>
{
public:
    QuanLiBanAn(int SoBan) : QuanLiDanhSach(SoBan)
    {
        for (int i=0; i<SoBan; i++)
        {
            DanhSach[i] = BanAn(i+1);
        }
        SoLuong = SoBan;
    }
    BanAn& getBanAn(int SoBan) {return DanhSach[SoBan-1];}
};

class QuanLiHoaDon : public QuanLiDanhSach<HoaDon>
{
public:
    QuanLiHoaDon(int SoBan) : QuanLiDanhSach(SoBan) {}
};

// Lớp Nhân Viên và lớp quản lý nhân viên
class NhanVien
{
private:
    string TenNhanVien;
    int MaNhanVien;
public:
    NhanVien() : TenNhanVien(""), MaNhanVien(0) {}
    NhanVien(string ten, int ma) : TenNhanVien(ten), MaNhanVien(ma) {}
    string getTenNhanVien() const {return TenNhanVien;}
    int getMaNhanVien() const {return MaNhanVien;}
};

class QuanLiNhanVien : public QuanLiDanhSach<NhanVien>
{
public:
    QuanLiNhanVien(int kt=10) : QuanLiDanhSach(kt) {}
    void HienThiDanhSach() const
    {
        cout<<"Danh sach nhan vien:\n";
        for (int i=0; i<SoLuong; i++)
        {
            cout<<"Ma: "<<DanhSach[i].getMaNhanVien()<<" - Ten: " <<DanhSach[i].getTenNhanVien()<<"\n";
        }
    }
};

class QuanLiNhaHang
{
private:
    QuanLiMonAn ThucDon;
    QuanLiBanAn DsBanAn;
    QuanLiHoaDon DsHoaDon;
    QuanLiNhanVien DsNhanVien;
    bool BanDaDuocDat;
    bool MonAnTrongThucDon;
public:
    QuanLiNhaHang(int SoBan) : ThucDon(10), DsBanAn(SoBan), DsHoaDon(SoBan), DsNhanVien(10), BanDaDuocDat(false), MonAnTrongThucDon(false) {}

    void ThemMonAn()
    {
        string TenMon;
        double GiaMon;
        cout<<"Nhap ten mon an: ";
        cin.ignore();
        getline(cin, TenMon);
        cout<<"Nhap gia mon an: ";
        cin>>GiaMon;
        ThucDon.Them(MonAn(TenMon, GiaMon));
        MonAnTrongThucDon = true;
    }

    void HienThiThucDon() const
    {
        if (!MonAnTrongThucDon)
        {
            cout<<"Chua co mon an trong thuc don.\n";
            return;
        }
        ThucDon.HienThiThucDon();
    }

    void XoaMonAn()
    {
        if (!MonAnTrongThucDon)
        {
            cout<<"Chua co mon an de xoa.\n";
            return;
        }
        int index;
        cout<<"Nhap vi tri mon an can xoa: ";
        cin>>index;
        ThucDon.XoaMonAn(index-1);  // Chuyển đổi từ 1-based index thành 0-based
    }

    void DatBan()
    {
        if (!MonAnTrongThucDon)
        {
            cout<<"Chua co thuc don de dat ban.\n";
            return;
        }
        int SoBan;
        cout<<"Nhap so ban: ";
        cin>>SoBan;
        if (SoBan<=DsBanAn.getSoLuong() && !DsBanAn.getBanAn(SoBan).getTrangThai())
        {
            DsBanAn.getBanAn(SoBan).DatBan();
            cout<<"Ban so "<<SoBan<<" da duoc dat.\n";
            BanDaDuocDat = true;
        }
        else if (SoBan>DsBanAn.getSoLuong())
        {
            cout<<"Ban so "<<SoBan<<" khong co san.\n";
        }
        else if (DsBanAn.getBanAn(SoBan).getTrangThai())
        {
            cout<<"Ban so "<<SoBan<<" chua thanh toan.\n";
        }
    }

    void GoiMon()
    {
        if (!MonAnTrongThucDon)
        {
            cout<<"Chua co mon an trong thuc don.\n";
            return;
        }
        int SoBan, IdMon, SoLuong;
        cout<<"Nhap so ban: ";
        cin>>SoBan;
        if (!BanDaDuocDat)
        {
            cout<<"Chua dat ban.\n";
            return;
        }
        if (SoBan<=DsBanAn.getSoLuong() && DsBanAn.getBanAn(SoBan).getTrangThai())
        {
            DsHoaDon[SoBan-1].ThemMonAn(ThucDon[IdMon-1], SoLuong);
            cout<<"Nhap ID mon an: ";
            cin>>IdMon;
            if (IdMon > ThucDon.getSoLuong())
            {
                cout<<"Khong co mon an trong thuc dơn";
                return;
            }
        cout<<"Nhap so luong: ";
        cin>>SoLuong;
        DsHoaDon[SoBan-1].ThemMonAn(ThucDon[IdMon-1], SoLuong);
        cout<<"Goi mon thanh cong!\n";
        }
        else
        {
            cout<<"Ban so "<<SoBan<<" khong co san.\n";
        }
    }

    void ThanhToan()
    {
        if (!BanDaDuocDat)
        {
            cout<<"Chua dat ban.\n";
            return;
        }
        int SoBan;
        cout<<"Nhap so ban: ";
        cin>>SoBan;
        if (SoBan<=DsBanAn.getSoLuong() && DsBanAn.getBanAn(SoBan).getTrangThai())
        {
            if (DsHoaDon[SoBan-1].HoaDonTrong())
            {
                cout<<"Chua co mon an nao duoc goi cho ban nay.\n";
                return;
            }
            DsHoaDon[SoBan-1].hienThiHoaDon();
            DsBanAn.getBanAn(SoBan).DonBan();
            DsHoaDon[SoBan-1] = HoaDon(); // Tạo hóa đơn mới sau khi thanh toán
            BanDaDuocDat = false;
            cout<<"Ban so "<<SoBan<<" da duoc thanh toan.\n";
        }
        else
        {
            cout<<"Ban so "<<SoBan<<" chua duoc su dung.\n";
        }
    }

    void ThemNhanVien()
    {
        string TenNhanVien;
        int MaNhanVien;
        cout<<"Nhap ten nhan vien: ";
        cin.ignore();
        getline(cin, TenNhanVien);
        cout<<"Nhap ma nhan vien: ";
        cin>>MaNhanVien;
        DsNhanVien.Them(NhanVien(TenNhanVien, MaNhanVien));
    }

    void HienThiDanhSachNhanVien() const
    {
        if (DsNhanVien.getSoLuong()==0)
        {
            cout<<"Chua co nhan vien.\n";
            return;
        }
        DsNhanVien.HienThiDanhSach();
    }

    void XoaNhanVien()
    {
        if (DsNhanVien.getSoLuong()==0)
        {
            cout<<"Chua co nhan vien de xoa.\n";
            return;
        }
        int MaNhanVien;
        cout<<"Nhap ma nhan vien can xoa: ";
        cin>>MaNhanVien;
        for (int i=0; i<DsNhanVien.getSoLuong(); i++)
        {
            if (DsNhanVien[i].getMaNhanVien() == MaNhanVien)
            {
                DsNhanVien.Xoa(i);
                cout<<"Xoa nhan vien thanh cong.\n";
                return;
            }
        }
        cout<<"Khong co nhan vien nay."<<MaNhanVien<<".\n";
    }
};

int main()
{
    int SoBan;
    cout<<"Nhap so luong ban: ";
    cin>>SoBan;
    QuanLiNhaHang NhaHang(SoBan);

    int LuaChon;
    do {
        cout<<"\nMenu:\n";
        cout<<"1. Them mon an\n";
        cout<<"2. Hien thi thuc don\n";
        cout<<"3. Xoa mon an\n";
        cout<<"4. Dat ban\n";
        cout<<"5. Goi mon\n";
        cout<<"6. Thanh toan\n";
        cout<<"7. Them nhan vien\n";
        cout<<"8. Hien thi danh sach nhan vien\n";
        cout<<"9. Xoa nhan vien\n";
        cout<<"10. Thoat\n";
        cout<<"Nhap lua chon: ";
        cin>>LuaChon;
        switch (LuaChon)
        {
            case 1: NhaHang.ThemMonAn(); break;
            case 2: NhaHang.HienThiThucDon(); break;
            case 3: NhaHang.XoaMonAn(); break;
            case 4: NhaHang.DatBan(); break;
            case 5: NhaHang.GoiMon(); break;
            case 6: NhaHang.ThanhToan(); break;
            case 7: NhaHang.ThemNhanVien(); break;
            case 8: NhaHang.HienThiDanhSachNhanVien(); break;
            case 9: NhaHang.XoaNhanVien(); break;
            case 10:
                cout<<"Thoat chuong trinh.\n";
                break;
            default:
                cout<<"Lua chon khong hop le. Vui long nhap lai.\n";
                break;
        }
    }
    while (LuaChon!=10);
    return 0;
}
