#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;
    static int count;

public:
    String() : str(new char[81]) {
        str[0] = '\0';
        count++;
    }

    String(size_t size) : str(new char[size + 1]) {
        str[0] = '\0';
        count++;
    }

    String(const char* input) : str(new char[strlen(input) + 1]) {
        strcpy(str, input);
        count++;
    }

    ~String() {
        delete[] str;
        count--;
    }

    void input() {
        cin.getline(str, 81);
    }

    void output() const {
        cout << str << endl;
    }

    static int getCount() {
        return count;
    }
};

int String::count = 0;

int main() {
    String str1;
    cout << "Введите строку (max 80 символов): ";
    str1.input();
    cout << "Вы ввели: ";
    str1.output();

    String str2(50);
    cout << "Введите строку (max 50 символов): ";
    str2.input();
    cout << "Вы ввели: ";
    str2.output();

    String str3("Hello, World!");
    cout << "Строка 3: ";
    str3.output();

    cout << "Количество объектов String: " << String::getCount() << endl;

    return 0;
}
