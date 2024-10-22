#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// Hàm để tạo tên phòng ngẫu nhiên
string generateRandomRoomName() {
    string room_prefixes[] = {"Hội nghị", "Gặp Mặt", "Phòng Học", "Phòng Thí Nghiệm", "Văn Phòng"};
    string room_suffixes[] = {"A", "B", "C", "D", "E"};
    return room_prefixes[rand() % 5] + " " + room_suffixes[rand() % 5];
}

// Hàm để tạo vị trí ngẫu nhiên
string generateRandomLocation() {
    string locations[] = {"Tầng 1", "Tầng 2", "Tầng 3", "Tầng 4", "Tầng 5"};
    return locations[rand() % 5];
}

// Hàm để tạo thông tin kỹ thuật ngẫu nhiên
string generateRandomTechInfo() {
    string tech_infos[] = {"Máy Chiếu và Bảng Trắng", "Bảng Trắng và Hệ Thống Âm Thanh", "Hệ Thống Âm Thanh và Wifi Tốc độ cao", "Phòng Riêng Tư Cao Cấp", "Phòng Vippromax"};
    return tech_infos[rand() % 5];
}

// Hàm để tạo sức chứa ngẫu nhiên
int generateRandomCapacity() {
    return rand() % 50 + 10; // Random capacity between 10 and 60
}

// Hàm để tạo building_id ngẫu nhiên (đảm bảo building_id hợp lệ)
// int generateRandomBuildingID() {
//     return rand() % 5 + 1; // Giả sử có 5 buildings với ID từ 1 đến 5
// }

int main() {
    srand(time(0)); // Seed cho hàm rand()

    ofstream file("insert_rooms.sql");

    if (file.is_open()) {
        // Bắt đầu ghi các câu lệnh SQL vào file
        for (int i = 1; i <= 200; ++i) {
            int room_id = 8683000+i;
            string room_name = generateRandomRoomName(); // Tạo tên phòng ngẫu nhiên
            int suc_chua = generateRandomCapacity();     // Tạo sức chứa ngẫu nhiên
            string vitri = generateRandomLocation();     // Tạo vị trí ngẫu nhiên
            string thong_tin_ky_thuat = generateRandomTechInfo(); // Tạo thông tin kỹ thuật ngẫu nhiên
            // int building_id = generateRandomBuildingID(); // Giả sử building_id là khóa ngoại

            // Ghi câu lệnh SQL sử dụng stored procedure THEM_ROOMS
            file << "Exec THEM_ROOMS '" << room_id << "', N'" << room_name << "', " 
                 << suc_chua << ", N'" << vitri << "', N'" << thong_tin_ky_thuat 
                 << "'"<<'\n';
        }

        file.close();
        cout << "Tạo dữ liệu SQL thành công! File đã được lưu dưới tên 'insert_rooms.sql'.\n";
    } else {
        cout << "Không thể mở file!\n";
    }

    return 0;
}
