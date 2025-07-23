// include/Editor.hpp
#pragma once
#include <list>
#include <stack>

class Editor
{
private:
    std::list<char> text;
    std::list<char>::iterator cursor;

public:
    // Constructor
    Editor();

    void insertChar(char c); // ใส่ตัวอักษร

    // ขยับ cursor
    void moveCursorRight();  
    void moveCursorLeft();
    
    void display();          // แสดงข้อความ
};
