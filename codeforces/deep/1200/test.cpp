#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MonAn {
private:
    string TenMon;
    unsigned long long GiaMon;
public:
    MonAn(string ten, unsigned long long gia) : TenMon(ten), GiaMon(gia) {}
    string getTenMon() const { return TenMon; }
    unsigned long long getGiaMon() const { return GiaMon; }
};

class Menu {
private:
    vector<MonAn> danhSachMonAn;
public:
    Menu() {
        danhSachMonAn = {
            MonAn("Pho", 30000), MonAn("Bun Bo", 35000), MonAn("Com Tam", 25000),
            MonAn("Goi Cuon", 20000), MonAn("Banh Mi", 15000), MonAn("Ca Ri Ga", 40000),
            MonAn("Hu Tieu", 25000), MonAn("Chao Long", 20000), MonAn("Nem Nuong", 30000),
            MonAn("Banh Xeo", 30000), MonAn("Banh Khot", 25000), MonAn("Goi Du Du", 30000),
            MonAn("Bun Rieu", 35000), MonAn("Bun Cha", 30000), MonAn("Banh Cuon", 25000),
            MonAn("Bo Luc Lac", 50000), MonAn("Lau Thai", 60000), MonAn("Cha Gio", 20000),
            MonAn("Sup Cua", 25000), MonAn("Che Ba Mau", 15000)
        };
    }

    void hienThiMenu() const {
        cout << "Thuc don:\n";
        for (size_t i = 0; i < danhSachMonAn.size(); ++i) {
            cout << i + 1 << ". " << danhSachMonAn[i].getTenMon() << " - " 
                 << danhSachMonAn[i].getGiaMon() << " VND\n";
        }
    }
    
    const vector<MonAn>& getDanhSachMonAn() const {
        return danhSachMonAn;
    }
};

class BanAn {
private:
    int SoBan;
    bool TinhTrang;
public:
    BanAn(int so) : SoBan(so), TinhTrang(false) {}
    int getSoBan() const { return SoBan; }
    bool getTrangThai() const { return TinhTrang; }
    void DatBan() { TinhTrang = true; }
    void DonBan() { TinhTrang = false; }
};

class HoaDon {
private:
    vector<pair<MonAn, int>> dsMonAn;
    unsigned long long TongTien;
public:
    HoaDon() : TongTien(0.0) {}
    void ThemMonAn(const MonAn& mon, int soLuong) {
        dsMonAn.push_back(make_pair(mon, soLuong));
        TongTien += mon.getGiaMon() * soLuong;
    }
    unsigned long long getTongTien() const { return TongTien; }
    void hienThiHoaDon() const {
        cout << "Hoa don chi tiet:\n";
        for (auto& mon : dsMonAn) {
            cout << "- " << mon.first.getTenMon() << " x " << mon.second
                 << " : " << mon.first.getGiaMon() * mon.second << " VND\n";
        }
        cout << "Tong tien: " << TongTien << " VND\n";
    }
    bool HoaDonTrong() const { return dsMonAn.empty(); }
};

class HeThongBep {
public:
    void ThongBaoMonAn(const MonAn& mon, int soLuong) {
        cout << "Bep nhan duoc don: " << mon.getTenMon() << " x " << soLuong << endl;
    }
};

class NhanVien {
private:
    string Ten;
    int SoGioLam;
    unsigned long long LuongTheoGio;
public:
    NhanVien(string t, int gio, unsigned long long Luong) : Ten(t), SoGioLam(gio), LuongTheoGio(Luong) {}
    unsigned long long TinhLuong() const { return SoGioLam * LuongTheoGio; }
    string getTen() const { return Ten; }
};

class QuanLyNhanVien {
private:
    vector<NhanVien> dsNhanVien;
public:
    void ThemNhanVien(const string& TenNhanVien, int SoGio, unsigned long long Luong) {
        dsNhanVien.push_back(NhanVien(TenNhanVien, SoGio, Luong));
    }
    void HienThiNhanVien() const {
        if (dsNhanVien.empty()) {
            cout << "Danh sach nhan vien hien tai khong co nhan vien nao.\n";
        } else {
            cout << "Danh sach nhan vien:\n";
            for (const auto& nv : dsNhanVien) {
                cout << "- " << nv.getTen() << " - Luong: " << nv.TinhLuong() << " VND\n";
            }
        }
    }
    bool CoNhanVien() const { return !dsNhanVien.empty(); }
};

class QuanLyNhaHang {
private:
    vector<BanAn> dsBanAn;
    vector<HoaDon> dsHoaDon;
    HeThongBep bep;
    QuanLyNhanVien qlNhanVien;
    Menu menu;
    bool BanDaDuocDat;
public:
    QuanLyNhaHang(int SoBan) : BanDaDuocDat(false) {
        for (int i = 1; i <= SoBan; ++i) {
            dsBanAn.push_back(BanAn(i));
            dsHoaDon.push_back(HoaDon());
        }
    }

    void HienThiMenu() const {
        menu.hienThiMenu();
    }
    
    void DatBan() {
        int SoBan;
        cout << "Nhap so ban can dat: ";
        cin >> SoBan;
        if (SoBan <= dsBanAn.size() && !dsBanAn[SoBan - 1].getTrangThai()) {
            dsBanAn[SoBan - 1].DatBan();
            BanDaDuocDat = true;
            cout << "Ban so " << SoBan << " da duoc dat.\n";
        } else {
            cout << "Ban so " << SoBan << " khong co san hoac da duoc dat.\n";
        }
    }

    bool DaCoBanDat() const { return BanDaDuocDat; }

    void ThanhToan(int SoBan) {
        if (SoBan <= dsBanAn.size() && dsBanAn[SoBan - 1].getTrangThai()) {
            if (dsHoaDon[SoBan - 1].HoaDonTrong()) {
                cout << "Chua co mon an nao duoc goi cho ban nay.\n";
                return;
            }
            dsHoaDon[SoBan - 1].hienThiHoaDon();
            dsBanAn[SoBan - 1].DonBan();
            dsHoaDon[SoBan - 1] = HoaDon();
            BanDaDuocDat = false;
            cout << "Ban so " << SoBan << " da duoc thanh toan va don ban.\n";
        } else {
            cout << "Ban so " << SoBan << " chua duoc su dung.\n";
        }
    }

    void goiMon(int SoBan, int monId, int soLuong) {
        if (SoBan <= dsBanAn.size() && dsBanAn[SoBan - 1].getTrangThai()) {
            const vector<MonAn>& ThucDon = menu.getDanhSachMonAn();
            if (monId > 0 && monId <= ThucDon.size()) {
                MonAn mon = ThucDon[monId - 1];
                dsHoaDon[SoBan - 1].ThemMonAn(mon, soLuong);
                bep.ThongBaoMonAn(mon, soLuong);
            } else {
                cout << "Mon an khong ton tai.\n";
            }
        } else {
            cout << "Ban so " << SoBan << " chua duoc su dung.\n";
        }
    }

    void ThemNhanVien() {
    string Ten;
    int SoGio;
    double Luong;
    
    cout << "Nhap ten nhan vien: ";
    cin.ignore();  // Bỏ qua ký tự newline còn lại từ lần nhập trước
    getline(cin, Ten);  // Sử dụng getline để nhận tên đầy đủ có khoảng trắng
    
    cout << "Nhap so gio lam: ";
    cin >> SoGio;
    
    cout << "Nhap luong theo gio: ";
    cin >> Luong;
    
    qlNhanVien.ThemNhanVien(Ten, SoGio, Luong);
    cout << "Nhan vien da duoc them.\n";
}


    void HienThiNhanVien() const {
        qlNhanVien.HienThiNhanVien();
    }
};

int main() {
    int SoBan;
    cout << "Nhap so luong ban: ";
    cin >> SoBan;
    QuanLyNhaHang NhaHang(SoBan);
    int LuaChon;
    do {
        cout << "\nMenu:\n";
        cout << "1. Xem menu\n";
        cout << "2. Dat ban\n";
        cout << "3. Goi mon\n";
        cout << "4. Thanh toan\n";
        cout << "5. Them nhan vien\n";
        cout << "6. Hien thi nhan vien\n";
        cout << "7. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> LuaChon;
        switch (LuaChon) {
            case 1:
                NhaHang.HienThiMenu();
                break;
            case 2:
                NhaHang.DatBan();
                break;
            case 3: {
                int SoBan, monId, soLuong;
                cout << "Nhap so ban: ";
                cin >> SoBan;
                cout << "Nhap ma mon an: ";
                cin >> monId;
                cout << "Nhap so luong: ";
                cin >> soLuong;
                NhaHang.goiMon(SoBan, monId, soLuong);
                break;
            }
            case 4: {
                int SoBan;
                cout << "Nhap so ban can thanh toan: ";
                cin >> SoBan;
                NhaHang.ThanhToan(SoBan);
                break;
            }
            case 5:
                NhaHang.ThemNhanVien();
                break;
            case 6:
                NhaHang.HienThiNhanVien();
                break;
            case 7:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
                break;
        }
    } while (LuaChon != 7);
    return 0;
}
