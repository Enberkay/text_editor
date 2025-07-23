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

    editor.insertChar('X');
    editor.display(); // HelX|lo

    return 0;
}
