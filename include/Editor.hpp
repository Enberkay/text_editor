#pragma once
#include <list>
#include <stack>
#include "Command.hpp"

class Editor {
private:
    std::list<char> text;
    std::list<char>::iterator cursor;

    std::stack<Command*> undoStack;
    std::stack<Command*> redoStack;

public:
    // Constructor
    Editor();

    void insertChar(char c);
    void deleteChar();

    void moveCursorRight();
    void moveCursorLeft();

    void undo();
    void redo();
    void display();

    friend class InsertCommand;
    friend class DeleteCommand;
};
