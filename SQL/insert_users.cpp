#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

// Hàm để tạo một chuỗi ngẫu nhiên
string generateRandomString(int length) {
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"; // Các ký tự có thể sử dụng
    string result;
    result.reserve(length); // Dự trữ không gian cho chuỗi kết quả

    for (int i = 0; i < length; ++i) {
        int index = rand() % chars.length(); // Chọn một ký tự ngẫu nhiên
        result += chars[index]; // Thêm ký tự ngẫu nhiên vào chuỗi kết quả
    }

    return result; // Trả về chuỗi ngẫu nhiên
}
string randomho(){
    string ho[] = {"Hoàng", " Trần", "Phạm", "Lê", "Nguyễn","Ông","VŨ","Phan","Trương","Bùi","Đặng","Đỗ","Ngô","Hồ","Dương","Trịnh","Đinh"};
    return ho[rand()%17];
}
string randomten(){
    string ten[] = {"An", "Thị", "Huyền", "Phong", "Anh","Hà","Quang","Nga","Thanh","Vinh","Minh","Hải","Nam","Lâm","Liệu","Châu","Hữu","Tâm","Hoài","Huế"};
    return ten[rand()%20]; 
}


// Hàm để tạo vai trò ngẫu nhiên
string randomVaiTro() {
    string roles[] = {"student", "teacher", "admin"};
    return roles[rand() % 3];
}

int main() {
    // srand(time(0)); // Seed cho hàm rand()
    
    ofstream file("insert_users.sql");
    
    if (file.is_open()) {
        // file << "INSERT INTO Users (user_id, first_name, last_name, email, password_hash, vai_tro) VALUES\n";
        
        for (int i = 1; i <= 200; i++) {
            string first_name = randomten();  // Tạo tên đầu ngẫu nhiên
            string last_name = randomho();   // Tạo tên họ ngẫu nhiên
            string email = first_name + to_string(i) + "@example.com"; // Tạo email ngẫu nhiên
            string password_hash = generateRandomString(10);  // Tạo mật khẩu băm giả định
            string vai_tro = randomVaiTro();  // Tạo vai trò ngẫu nhiên
            
            file << "Exec THEM_USERS '" << i << "', N'" << first_name << "', N'" << last_name << "', N'" << email << "', '" 
                 << password_hash << "', '" << vai_tro <<"'"<<'\n';

        }
        
        file.close();
        cout << "Tạo dữ liệu SQL thành công! File đã được lưu dưới tên 'insert_users.sql'.\n";
    } else {
        cout << "Không thể mở file!\n";
    }
    
    return 0;
}
