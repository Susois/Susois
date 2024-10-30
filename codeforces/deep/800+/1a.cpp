#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

// Kích thước bản đồ
const int width = 20;
const int height = 20;

// Vị trí rắn, thức ăn và điểm số
int x, y, foodX, foodY, score;

// Biến để kiểm tra hướng di chuyển của rắn
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

// Vị trí thân rắn và chiều dài của rắn
int tailX[100], tailY[100];
int nTail;

bool gameOver;

// Hàm khởi tạo trò chơi
void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;
}

// Hàm vẽ trò chơi
void Draw() {
    system("cls"); // Xóa màn hình

    // Vẽ viền trên
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#"; // Viền trái

            if (i == y && j == x)
                cout << "O"; // Vẽ đầu rắn
            else if (i == foodY && j == foodX)
                cout << "F"; // Vẽ thức ăn
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o"; // Vẽ thân rắn
                        print = true;
                    }
                }
                if (!print) cout << " ";
            }

            if (j == width - 1)
                cout << "#"; // Viền phải
        }
        cout << endl;
    }

    // Vẽ viền dưới
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}

// Hàm xử lý điều khiển của người chơi
void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

// Hàm cập nhật trạng thái trò chơi
void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // Nếu rắn đụng viền, kết thúc trò chơi
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    // Nếu rắn đụng thân mình, kết thúc trò chơi
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    // Nếu rắn ăn thức ăn
    if (x == foodX && y == foodY) {
        score += 10;
        foodX = rand() % width;
        foodY = rand() % height;
        nTail++;
    }
}

// Hàm chính
int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100); // Điều chỉnh tốc độ của trò chơi
    }
    return 0;
}
