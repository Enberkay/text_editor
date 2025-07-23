
#include "Editor.hpp"
#include <iostream>

Editor::Editor() {
    text = std::list<char>();
    cursor = text.begin();
}

void Editor::insertChar(char c) {
    cursor = text.insert(cursor, c); // แทรกก่อน cursor
    ++cursor;                        // ขยับ cursor ไปข้างหน้า
}

void Editor::display() {
    for (auto it = text.begin(); it != text.end(); ++it) {
        if (it == cursor)
            std::cout << '|';  // ตำแหน่ง cursor
        std::cout << *it;
    }
    if (cursor == text.end())
        std::cout << '|'; // cursor ที่ท้ายข้อความ
    std::cout << '\n';
}


//ป้องกันไม่ให้ cursor เลยขอบ list ด้วยการเช็ค cursor != begin()/end() ก่อนขยับ
void Editor::moveCursorLeft() {
    if (cursor != text.begin()) {
        --cursor; // ขยับ cursor ไปทางซ้าย
    }
}

void Editor::moveCursorRight() {
    if (cursor != text.end()) {
        ++cursor; // ขยับ cursor ไปทางขวา
    }
}

void Editor::deleteChar() {
    if (cursor != text.begin()) {
        // ถอย cursor กลับมาก่อน 1 ตัว
        auto toDelete = cursor;
        --toDelete;
        cursor = text.erase(toDelete);  // ลบ แล้วคืน iterator ถัดไป
    }
}
