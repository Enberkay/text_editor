#pragma once
#include <list>
#include <stack>
#include <memory>
#include "Command.hpp"

class Editor {
private:
    std::list<char> text;
    std::list<char>::iterator cursor;

    std::stack<std::unique_ptr<Command>> undoStack;
    std::stack<std::unique_ptr<Command>> redoStack;

public:
    // Constructor
    Editor();

    void insertChar(char c);
    void deleteChar();
    void insertString(const std::string& str);

    void moveCursorRight();
    void moveCursorLeft();

    void undo();
    void redo();

    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);

    void display();

    friend class InsertCommand;
    friend class DeleteCommand;
    friend class MoveCursorCommand;
};