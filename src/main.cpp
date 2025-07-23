// src/main.cpp
#include <iostream>
#include "Editor.hpp"

int main() {
    Editor editor;
    editor.insertChar('H');
    editor.insertChar('i');
    editor.display();  // ควรแสดง Hi

    return 0;
}
