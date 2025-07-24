#include "Editor.hpp"
#include "Command.hpp"
#include <iostream>
#include <fstream>

Editor::Editor() {
    text = std::list<char>();
    cursor = text.begin();
}

void Editor::insertChar(char c) {
    auto cmd = std::make_unique<InsertCommand>(c);
    cmd->execute(*this);
    undoStack.push(std::move(cmd));
    while (!redoStack.empty()) redoStack.pop();
}

void Editor::deleteChar() {
    auto cmd = std::make_unique<DeleteCommand>();
    cmd->execute(*this);
    undoStack.push(std::move(cmd));
    while (!redoStack.empty()) redoStack.pop();
}


void Editor::moveCursorLeft() {
    auto cmd = std::make_unique<MoveCursorCommand>(false);
    cmd->execute(*this);
    undoStack.push(std::move(cmd));
    while (!redoStack.empty()) redoStack.pop();
}

void Editor::moveCursorRight() {
    auto cmd = std::make_unique<MoveCursorCommand>(true);
    cmd->execute(*this);
    undoStack.push(std::move(cmd));
    while (!redoStack.empty()) redoStack.pop();
}


void Editor::insertString(const std::string& str) {
    auto cmd = std::make_unique<InsertStringCommand>(str);
    cmd->execute(*this);
    undoStack.push(std::move(cmd));
    while (!redoStack.empty()) redoStack.pop();
}


void Editor::undo() {
    if (!undoStack.empty()) {
        auto cmd = std::move(undoStack.top());
        undoStack.pop();
        cmd->undo(*this);
        redoStack.push(std::move(cmd));
    }
}

void Editor::redo() {
    if (!redoStack.empty()) {
        auto cmd = std::move(redoStack.top());
        redoStack.pop();
        cmd->execute(*this);
        undoStack.push(std::move(cmd));
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

void Editor::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file for writing.\n";
        return;
    }
    for (char ch : text) {
        file << ch;
    }
    file.close();
    std::cout << "Saved to " << filename << "\n";
}

void Editor::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file for reading.\n";
        return;
    }

    text.clear();
    std::stack<std::unique_ptr<Command>> undoStack;
    std::stack<std::unique_ptr<Command>> redoStack;

    char ch;
    while (file.get(ch)) {
        text.push_back(ch);
    }
    cursor = text.end(); // default ให้ cursor ไปท้ายข้อความ
    file.close();

    std::cout << "Loaded from " << filename << "\n";
}