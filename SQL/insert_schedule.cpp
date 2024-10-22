// #include <iostream>
// #include <vector>
// #include <random>
// #include <ctime>
// #include <string>
// #include <set>
// #include <iomanip>
// // #include<bits/stdc++.h>

// using namespace std;

// // Hàm để tạo một thời gian ngẫu nhiên trong khoảng thời gian cho trước
// time_t randomTime(int startHour, int endHour) {
//     // Khởi tạo mốc thời gian cơ sở là ngày hôm nay
//     time_t now = time(0);
//     tm* localTime = localtime(&now);

//     // Thiết lập thời gian khởi đầu và kết thúc
//     localTime->tm_hour = startHour;
//     localTime->tm_min = 0;
//     time_t startTime = mktime(localTime);

//     localTime->tm_hour = endHour;
//     time_t endTime = mktime(localTime);

//     // Tạo thời gian ngẫu nhiên trong khoảng
//     uniform_int_distribution<int> dist(startTime, endTime);
//     return dist(default_random_engine(time(0)));
// }

// // Hàm kiểm tra sự tồn tại của lịch trình
// bool scheduleExists(set<string>& existingSchedules, const string& schedule) {
//     return existingSchedules.find(schedule) != existingSchedules.end();
// }

// int main() {
//     ofstream file("insert_schedule.sql");
//     if(file.is_open()) {
//     const int numberOfSchedules = 10; // Số lượng lịch trình cần tạo
//     set<string> existingSchedules; // Set để lưu lịch trình đã tồn tại
//     vector<string> daysOfWeek = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

//     for (int i = 0; i < numberOfSchedules; i++) {
//         int schedule_id = 100000 + i; // Tạo schedule_id
//         int course_id = 8888001 + rand() % 200; // Random course_id từ 8888001 đến 8888200
//         int room_id = 8683001 + rand() % 200; // Random room_id từ 8683001 đến 8683200

//         // Random ngày trong tuần
//         string day_of_week = daysOfWeek[rand() % daysOfWeek.size()];

//         // Tạo thời gian bắt đầu và kết thúc
//         time_t start_time = randomTime(8, 17); // Thời gian bắt đầu từ 8h đến 17h
//         time_t end_time = start_time + 3600; // Thời gian kết thúc sau 1 giờ

//         // Kiểm tra lịch trình đã tồn tại
//         string scheduleKey = to_string(schedule_id) + to_string(start_time) + day_of_week;
//         if (!scheduleExists(existingSchedules, scheduleKey)) {
//             existingSchedules.insert(scheduleKey);
//             // In thông tin lịch trình
//             file<<Exec THEM_SCHEDULE << "'" << schedule_id 
//                  << "', '" << put_time(localtime(&start_time), "%Y-%m-%d %H:%M:%S") 
//                  << "',' " << put_time(localtime(&end_time), "%Y-%m-%d %H:%M:%S") 
//                  << "','" << day_of_week 
//                  << "', " << course_id 
//                  << "," << room_id << endl;

//             // Gọi thủ tục lưu vào cơ sở dữ liệu
//             // (Thay thế đoạn sau với việc gọi thủ tục SQL thực tế)
//             // CallStoredProc(schedule_id, start_time, end_time, day_of_week, course_id, room_id);
//         } else {
//             // Nếu đã tồn tại, giảm i để tạo lại lịch trình
//             i--;
//         }
//     }
//     }
//     else {
//         cout << "Không thể mở file!\n";}

//     return 0;
// }

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>
#include <set>
#include <iomanip>
#include <fstream>
using namespace std;

// Function to generate a random time within a specified range
time_t randomTime(int startHour, int endHour) {
    time_t now = time(0);
    tm localTime = *localtime(&now);
    localTime.tm_hour = startHour;
    localTime.tm_min = 0;
    time_t startTime = mktime(&localTime);
    localTime.tm_hour = endHour;
    time_t endTime = mktime(&localTime);
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, difftime(endTime, startTime));
    
    return startTime + dist(gen);
}

// Function to check if a schedule already exists
bool scheduleExists(set<string>& existingSchedules, const string& schedule) {
    return existingSchedules.find(schedule) != existingSchedules.end();
}

int main() {
    ofstream file("insert_schedule.sql");
    if(file.is_open()) {
        const int numberOfSchedules = 50;
        set<string> existingSchedules;
        vector<string> daysOfWeek = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

        for (int i = 0; i < numberOfSchedules; i++) {
            int schedule_id = 100000 + i;
            int course_id = 8888001 + rand() % 200;
            int room_id = 8683001 + rand() % 200;
            string day_of_week = daysOfWeek[rand() % daysOfWeek.size()];
            
            time_t start_time = randomTime(8, 17);
            time_t end_time = start_time + 3600;

            string scheduleKey = to_string(schedule_id) + to_string(start_time) + day_of_week;

            if (!scheduleExists(existingSchedules, scheduleKey)) {
                existingSchedules.insert(scheduleKey);

                file << "EXEC THEM_SCHEDULE '"
                     << schedule_id << "', '"
                     << put_time(localtime(&start_time), "%Y-%m-%d %H:%M:%S") << "', '"
                     << put_time(localtime(&end_time), "%Y-%m-%d %H:%M:%S") << "', '"
                     << day_of_week << "', "
                     << course_id << ", "
                     << room_id << ";\n";

                // Here you can call the actual SQL procedure if needed
                // CallStoredProc(schedule_id, start_time, end_time, day_of_week, course_id, room_id);
            } else {
                i--; // Decrement to regenerate this schedule
            }
        }
    } else {
        cout << "Không thể mở file!\n";
    }

    return 0;
}


