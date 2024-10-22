#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    // Khởi tạo seed cho random
    srand((unsigned)time(0));

    // Danh sách student_id đã cung cấp
    vector<int> student_ids = {5, 6, 7, 8, 11, 14, 19, 24, 30, 36, 42, 43, 45, 49, 51, 53, 
                               55, 58, 59, 62, 66, 69, 72, 76, 77, 79, 81, 84, 86, 88, 89, 
                               95, 96, 97, 98, 103, 104, 107, 109, 113, 114, 119, 123, 124, 
                               126, 130, 131, 136, 137, 138, 139, 141, 142, 150, 154, 157, 
                               159, 160, 163, 164, 166, 170, 171, 175, 176, 179, 180, 183, 
                               184, 185, 187, 192, 193, 194, 195, 196, 197};

    ofstream file("insert_dang_ki_khoa_hoc.sql");
    if (file.is_open()) {
        for (int i = 0; i < 200; ++i) {
            int dang_ki_khoa_hoc_id = 9999000 + i;  // Tạo ID tự động cho mỗi đăng ký khóa học
            int course_id = 8888001 + rand() % 200;  // Random course_id trong khoảng từ 8888001 tới 8888200
            int student_id = student_ids[rand() % student_ids.size()];  // Random student_id từ danh sách đã cung cấp

            // Ghi câu lệnh SQL vào file
            file << "EXEC THEM_DANG_KI_KHOA_HOC " 
                 << dang_ki_khoa_hoc_id << ", "
                 << course_id << ", "
                 << student_id << ";\n";
        }
        file.close();
        cout << "File insert_dang_ki_khoa_hoc.sql đã được tạo thành công với 200 dòng dữ liệu.\n";
    } else {
        cout << "Không thể mở file để ghi.\n";
    }

    return 0;
}
