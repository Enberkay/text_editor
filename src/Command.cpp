#include "Command.hpp"
#include "Editor.hpp"
#include <string>

// ========== InsertCommand ==========

InsertCommand::InsertCommand(char c) : ch(c) {}

void InsertCommand::execute(Editor& editor) {
    insertedIt = editor.text.insert(editor.cursor, ch);
    editor.cursor = insertedIt;
    ++editor.cursor;
}

void InsertCommand::undo(Editor& editor) {
    editor.cursor = editor.text.erase(insertedIt); // คืน iterator ตัวถัดไป
}

// ========== DeleteCommand ==========

DeleteCommand::DeleteCommand() {}

void DeleteCommand::execute(Editor& editor) {
    if (editor.cursor != editor.text.begin()) {
        pos = editor.cursor;
        auto it = editor.cursor;
        --it;
        deletedChar = *it;
        editor.text.erase(it);
        deleted = true;
    }
}

void DeleteCommand::undo(Editor& editor) {
    if (deleted) {
        editor.text.insert(pos, deletedChar);
        editor.cursor = pos;
    }
}

// ========== MoveCursorCommand ==========

MoveCursorCommand::MoveCursorCommand(bool right) : moveRight(right) {}

void MoveCursorCommand::execute(Editor& editor) {
    prevPos = editor.cursor;
    if (moveRight && editor.cursor != editor.text.end()) {
        ++editor.cursor;
    } else if (!moveRight && editor.cursor != editor.text.begin()) {
        --editor.cursor;
    }
    newPos = editor.cursor;
}

void MoveCursorCommand::undo(Editor& editor) {
    editor.cursor = prevPos;
}

InsertStringCommand::InsertStringCommand(const std::string& str) {
    for (char ch : str) {
        commands.push_back(new InsertCommand(ch));
    }
}

InsertStringCommand::~InsertStringCommand() {
    for (auto cmd : commands)
        delete cmd;
}

void InsertStringCommand::execute(Editor& editor) {
    for (auto cmd : commands) {
        cmd->execute(editor);
    }
}

void InsertStringCommand::undo(Editor& editor) {
    for (auto it = commands.rbegin(); it != commands.rend(); ++it) {
        (*it)->undo(editor);
    }
}