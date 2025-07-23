
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
    for (char c : text)
        std::cout << c;
    std::cout << '\n';
}
