#include "Command.hpp"
#include "Editor.hpp"

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

