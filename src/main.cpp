#include <iostream>
#include "Editor.hpp"

int main() {
    Editor editor;

    editor.insertChar('H');
    editor.insertChar('e');
    editor.insertChar('l');
    editor.insertChar('l');
    editor.insertChar('o');
    editor.display(); // Hello|

    editor.moveCursorLeft();
    editor.moveCursorLeft();
    editor.display(); // Hel|lo

    editor.deleteChar(); // ลบ l
    editor.display();    // He|lo

    editor.deleteChar(); // ลบ e
    editor.display();    // H|lo

    editor.deleteChar(); // ลบ H
    editor.display();    // |lo

    editor.deleteChar(); // ไม่มีอะไรให้ลบ
    editor.display();    // |lo

    return 0;
}
