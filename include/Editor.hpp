// include/Editor.hpp
#pragma once
#include <list>
#include <stack>

class Editor {
private:
    std::list<char> text;
    std::list<char>::iterator cursor;

public:
    Editor();                       // Constructor
    void insertChar(char c);       // ใส่ตัวอักษร
    void display();                // แสดงข้อความ
};
