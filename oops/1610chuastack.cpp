#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

class Stack {
private:
    int st[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void Push(int n) {
        if (!isFull()) {
            st[++top] = n;
        }
    }

    int Pop() {
        if (!isEmpty()) {
            return st[top--];
        } else {
            return -1; // Giá trị mặc định khi ngăn xếp rỗng
        }
    }

    void printstack() {
        while (!isEmpty()) {
            int value = Pop();
            if (value != -1) {
                cout << setw(3) << value;
            }
        }
        cout << endl;
    }
};

class DCS : public Stack {
private:
    int n;

public:
    DCS() {}

    DCS(int n1) {
        n = n1;
    }

    void dcs2() {
        int bf = n;
        while (bf) {
            Push(bf % 2);
            bf /= 2;
        }
        printstack();
    }

    int getx() {
        return n;
    }
};

int main() {
    DCS d(15);
    cout << endl << "co so 2 cua so " << d.getx() << endl;
    d.dcs2();

    DCS d1(16);
    cout << endl << "co so 2 cua so " << d1.getx() << endl;
    d1.dcs2();

    return 0;
}
