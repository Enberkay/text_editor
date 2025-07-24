#include "Editor.hpp"
#include "Command.hpp"
#include <iostream>

Editor::Editor() {
    text = std::list<char>();
    cursor = text.begin();
}

void Editor::insertChar(char c) {
    Command* cmd = new InsertCommand(c);
    cmd->execute(*this);
    undoStack.push(cmd);
    while (!redoStack.empty()) redoStack.pop();
}

void Editor::deleteChar() {
    Command* cmd = new DeleteCommand();
    cmd->execute(*this);
    undoStack.push(cmd);
    while (!redoStack.empty()) redoStack.pop();
}

void Editor::moveCursorLeft() {
    Command* cmd = new MoveCursorCommand(false);
    cmd->execute(*this);
    undoStack.push(cmd);
    while (!redoStack.empty()) redoStack.pop();
}

void Editor::moveCursorRight() {
    Command* cmd = new MoveCursorCommand(true);
    cmd->execute(*this);
    undoStack.push(cmd);
    while (!redoStack.empty()) redoStack.pop();
}


void Editor::undo() {
    if (!undoStack.empty()) {
        Command* cmd = undoStack.top();
        undoStack.pop();
        cmd->undo(*this);
        redoStack.push(cmd);
    }
}

void Editor::redo() {
    if (!redoStack.empty()) {
        Command* cmd = redoStack.top();
        redoStack.pop();
        cmd->execute(*this);
        undoStack.push(cmd);
    }
}

void Editor::display() {
    for (auto it = text.begin(); it != text.end(); ++it) {
        if (it == cursor)
            std::cout << '|';
        std::cout << *it;
    }
    if (cursor == text.end())
        std::cout << '|';
    std::cout << '\n';
}
