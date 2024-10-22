#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

// Hàm để random ngày giữa hai mốc thời gian
tm randomDate(tm start, tm end) {
    time_t startTime = mktime(&start);
    time_t endTime = mktime(&end);
    
    // Tạo một giá trị ngẫu nhiên trong khoảng từ startTime tới endTime
    time_t randomTime = startTime + rand() % (endTime - startTime);
    return *localtime(&randomTime);
}

int main() {
    // Khởi tạo seed cho random
    srand((unsigned)time(0));

    // Các trạng thái điểm danh
    vector<string> trang_thai = {"co mat", "vang mat", "di tre"};

    // Mốc thời gian cho việc random ngày
    tm startDate = {0, 0, 0, 22, 9, 2024 - 1900};  // 22/10/2024
    tm endDate = {0, 0, 0, 10, 11, 2024 - 1900};   // 10/12/2024

    ofstream file("insert_diem_danh.sql");
    if (file.is_open()) {
        for (int i = 0; i < 200; ++i) {
            int diem_danh_id = 12345001 + i;  // Tạo ID tự động cho mỗi bản ghi điểm danh
            string trang_thai_random = trang_thai[rand() % trang_thai.size()];  // Random trạng thái
            tm diem_danh_date = randomDate(startDate, endDate);  // Random ngày điểm danh
            int dang_ki_khoa_hoc_id = 9999000 + rand() % 200;  // Random từ 9999000 tới 9999199
            int schedule_id = 100000 + rand() % 49;  // Random schedule_id từ 100000 tới 100200

            // Ghi câu lệnh SQL vào file
            file << "EXEC THEM_DIEM_DANH " 
                 << diem_danh_id << ", N'" 
                 << trang_thai_random << "', '"
                 << diem_danh_date.tm_year + 1900 << "-" 
                 << diem_danh_date.tm_mon + 1 << "-" 
                 << diem_danh_date.tm_mday << "', "
                 << dang_ki_khoa_hoc_id << ", "
                 << schedule_id << ";\n";
        }
        file.close();
        cout << "File insert_diem_danh.sql đã được tạo thành công với 200 dòng dữ liệu.\n";
    } else {
        cout << "Không thể mở file để ghi.\n";
    }

    return 0;
}
