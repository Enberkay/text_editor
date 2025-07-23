#pragma once
#include <list>

class Editor; // forward declaration

class Command {
public:
    virtual void execute(Editor& editor) = 0;
    virtual void undo(Editor& editor) = 0;
    virtual ~Command() = default;
};

// ------------------ InsertCommand ------------------

class InsertCommand : public Command {
    char ch;
    std::list<char>::iterator insertedIt;

public:
    InsertCommand(char c);
    void execute(Editor& editor) override;
    void undo(Editor& editor) override;
};

// ------------------ DeleteCommand ------------------

class DeleteCommand : public Command {
    char deletedChar;
    std::list<char>::iterator pos;
    bool deleted = false;

public:
    DeleteCommand();
    void execute(Editor& editor) override;
    void undo(Editor& editor) override;
};
