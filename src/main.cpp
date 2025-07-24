#include "Editor.hpp"

int main() {
    Editor editor;

    editor.insertChar('A');
    editor.insertChar('B');
    editor.insertChar('C');
    editor.display(); // ABC|

    editor.moveCursorLeft();
    editor.moveCursorLeft();
    editor.display(); // A|BC

    editor.undo();
    editor.display(); // AB|C ← ย้อน cursor ไปขวา

    editor.undo();
    editor.display(); // ABC| ← ย้อนอีกครั้ง

    editor.redo();
    editor.display(); // AB|C

    editor.redo();
    editor.display(); // A|BC

    return 0;
}
