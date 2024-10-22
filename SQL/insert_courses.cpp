#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

string room_prefixes[] = {"Thuyết Trình Pro", "Tư Duy Sáng Tạo", "Quản Lý Dự Án", " Phân Tích Dữ Liệu",
     "Thiết Kế Photoshop","Lập Trình Web","Giao Tiếp Chuyên Nghiệp","Digital Marketing ","Kinh Doanh Online","Lập Trình Robot"};
string locations[] = {"TTPRO12345", "TDSANG1234", "QLDA123456", "PTDL123456", "TKPS123456","LTWEB12345","GTCN123456","DMKT123456","KDON123456","LTRO123456"};

string generateRandomRoomName() {
    return room_prefixes[rand() % 10] ;
}

string gv[] = { "1","2","3","10","17","21","22","25","26","27","29","32","37","38","39","41","47","48","50","52","54","56","60","61","63","68","70",
"75","87","90","93","94","99","101","106","108","110","112","116","120","121","125","127","128","129","132","144","146","148","153","155","161","168",
"173","182","186","189","190","198","199"};
string giang_vien_id(){
    return gv[rand() % 60];
}





int main() {
    srand(time(0)); // Seed cho hàm rand()

    ofstream file("insert_courses.sql");

    if (file.is_open()) {
        // Bắt đầu ghi các câu lệnh SQL vào file
        for (int i = 1; i <= 200; ++i) {
            int courses_id = 8888000+i;
            string courses_name = generateRandomRoomName(); // Tạo tên phòng ngẫu nhiên
            // int suc_chua = generateRandomCapacity();     // Tạo sức chứa ngẫu nhiên
            // string courses_code = findcourses();
            string courses_code;
            string mo_ta;
            if(courses_name==room_prefixes[0]){
                 courses_code = locations[0];
                 mo_ta = "Khóa học này giúp bạn rèn luyện kỹ năng thuyết trình chuyên nghiệp, thu hút người nghe và tự tin truyền đạt ý tưởng. Bạn sẽ học cách xây dựng cấu trúc bài thuyết trình, làm chủ ngôn ngữ cơ thể và sử dụng công cụ hỗ trợ như PowerPoint để nâng cao hiệu quả.";}
            else if(courses_name==room_prefixes[1]){
                 courses_code =locations[1];
                 mo_ta = "Khóa học này giúp phát triển khả năng tư duy sáng tạo, khuyến khích sự đổi mới trong công việc và cuộc sống. Bạn sẽ học các kỹ thuật để kích thích trí tưởng tượng, tìm giải pháp cho các vấn đề và phát huy tối đa tiềm năng sáng tạo cá nhân.";}
            else if(courses_name==room_prefixes[2]) {courses_code = locations[2];
            mo_ta = "Cung cấp những kiến thức và kỹ năng cần thiết để quản lý dự án hiệu quả, từ lập kế hoạch, phân bổ tài nguyên đến giám sát tiến độ và đánh giá kết quả. Khóa học phù hợp cho những ai muốn nâng cao năng lực quản lý trong mọi lĩnh vực.";}
            else if(courses_name==room_prefixes[3]){
                 courses_code =locations[3];
                 mo_ta = "Khóa học giúp bạn hiểu cách thu thập, phân tích và trình bày dữ liệu một cách hiệu quả. Bạn sẽ nắm được các công cụ phân tích phổ biến như Excel, Python, và các kỹ thuật trực quan hóa dữ liệu để đưa ra quyết định chính xác dựa trên dữ liệu.";}
            else if(courses_name==room_prefixes[4]){ courses_code = locations[4];
            mo_ta = "Khóa học này giúp bạn thành thạo các công cụ thiết kế và chỉnh sửa ảnh chuyên nghiệp bằng Photoshop. Từ chỉnh sửa cơ bản đến thiết kế nâng cao, bạn sẽ học cách tạo ra các sản phẩm đồ họa ấn tượng phục vụ cho công việc hoặc sở thích cá nhân.";}
             else if(courses_name==room_prefixes[5]){ courses_code =locations[5];
             mo_ta = "Khóa học lập trình web từ cơ bản đến nâng cao giúp bạn xây dựng các trang web chuyên nghiệp. Bạn sẽ học các ngôn ngữ phổ biến như HTML, CSS, JavaScript, và các framework hiện đại để phát triển giao diện web thân thiện, hấp dẫn.";}
            else if(courses_name==room_prefixes[6]){ courses_code = locations[6];
            mo_ta = "Khóa học này tập trung vào việc rèn luyện kỹ năng giao tiếp chuyên nghiệp trong môi trường công sở và kinh doanh. Bạn sẽ học cách lắng nghe, diễn đạt ý tưởng một cách rõ ràng, và xây dựng mối quan hệ bền vững với đồng nghiệp và đối tác.";}
             else if(courses_name==room_prefixes[7]) {courses_code =locations[7];
             mo_ta = "Cung cấp kiến thức về tiếp thị số từ cơ bản đến chuyên sâu, bao gồm SEO, quảng cáo Google, quảng cáo trên mạng xã hội và email marketing. Bạn sẽ học cách tối ưu hóa chiến dịch quảng cáo trực tuyến để tiếp cận khách hàng mục tiêu và tăng trưởng doanh thu.";}
            else if(courses_name==room_prefixes[8]) {courses_code = locations[8];
            mo_ta = "Khóa học này hướng dẫn bạn cách bắt đầu và vận hành một doanh nghiệp trực tuyến thành công. Từ việc chọn sản phẩm, xây dựng website bán hàng, cho đến chiến lược marketing và quản lý vận hành, khóa học giúp bạn tăng doanh số và mở rộng quy mô kinh doanh.";}
             else if(courses_name==room_prefixes[9]) {courses_code =locations[9];
             mo_ta = "Khóa học cung cấp kiến thức về lập trình robot, từ các nền tảng cơ bản đến nâng cao. Bạn sẽ học cách lập trình các robot tự động, robot di chuyển và tham gia các dự án thực tế để phát triển kỹ năng trong lĩnh vực công nghệ này.";}
            
            int gv_id  = stoi(giang_vien_id());
        file << "Exec THEM_COURSES '"<<courses_id<<"',N'"<<courses_name<<"','"<<courses_code<<"',N'"<<mo_ta<<"',"<<gv_id<<'\n';

        }
        file.close();
        cout << "Tạo dữ liệu SQL thành công! File đã được lưu dưới tên 'insert_rooms.sql'.\n";
    } else {
        cout << "Không thể mở file!\n";
    }

    return 0;
}
