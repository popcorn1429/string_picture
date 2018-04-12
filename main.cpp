#include "string_picture.h"

int main() {

    const char* init[] = { "Paris", "in the", "Spring" };
    StringPicture p(init, 3);
    cout << "\n----------p-----------\n" << endl;
    cout << p << endl;
    cout << "\n-------frame(p)-------\n" << endl;
    cout << frame(p) << endl;
    cout << "\n-----p | frame(p)-----\n" << endl;
    cout << (p | frame(p)) << endl;
    cout << "\n-----p & frame(p)-----\n" << endl;
    cout << (p & frame(p)) << endl;
    cout << "\n-----frame(frame(p) | (p & frame(p)))-----\n" << endl;
    cout << frame(frame(p) | (p & frame(p))) << endl;
    system("pause");
    return 0;
}