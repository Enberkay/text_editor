#include "Editor.hpp"

int main() {
    Editor editor;

    // STEP 1: Insert A, B, C
    editor.insertChar('A');
    editor.insertChar('B');
    editor.insertChar('C');
    editor.display();  //คาดหวัง: ABC|

    // STEP 2: Delete one char (ลบ C)
    editor.deleteChar();
    editor.display();  //คาดหวัง: AB|

    // STEP 3: Undo delete → กลับมาเป็น ABC|
    editor.undo();
    editor.display();  //คาดหวัง: ABC|

    // STEP 4: Undo insert C → กลับเป็น AB|
    editor.undo();
    editor.display();  //คาดหวัง: AB|

    // STEP 5: Redo insert C → กลับเป็น ABC|
    editor.redo();
    editor.display();  //คาดหวัง: ABC|

    // STEP 6: Insert C เพิ่มอีก → ABCC|
    editor.insertChar('C');
    editor.display();  //คาดหวัง: ABCC|

    // STEP 7: Undo insert C ตัวใหม่ → ABC|
    editor.undo();
    editor.display();  //คาดหวัง: ABC|

    // STEP 8: Undo insert C ก่อนหน้า → AB|
    editor.undo();
    editor.display();  //คาดหวัง: AB|

    // STEP 9: Undo insert B → A|
    editor.undo();
    editor.display();  //คาดหวัง: A|

    // STEP 10: Redo insert B → AB|
    editor.redo();
    editor.display();  //คาดหวัง: AB|

    // STEP 11: Redo insert C → ABC|
    editor.redo();
    editor.display();  //คาดหวัง: ABC|

    return 0;
}

//output
/*

ABC|
AB|
ABC|
AB|
ABC|
ABCC|
ABC|
AB|
A|
AB|
ABC|


*/