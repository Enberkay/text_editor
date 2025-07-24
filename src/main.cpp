#include "Editor.hpp"

int main() {
    Editor editor;

    editor.insertString("Hi");
    editor.display();  // Hi|

    editor.insertChar('!');
    editor.display();  // Hi!|

    editor.undo();     // undo '!'
    editor.display();  // Hi|

    editor.undo();     // undo "Hi"
    editor.display();  // |

    editor.redo();     // redo "Hi"
    editor.display();  // Hi|

    editor.redo();     // redo '!'
    editor.display();  // Hi!|

    return 0;
}

/*

Hi|
Hi!|
Hi|
|
Hi|
Hi!|


*/