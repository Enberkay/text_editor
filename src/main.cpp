#include "Editor.hpp"
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    Editor editor;
    std::string line;

    std::cout << "Simple Text Editor (type 'help' to see commands)\n";

    while (true)
    {
        std::cout << "\n> ";
        std::getline(std::cin, line);

        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;

        if (cmd == "insert")
        {
            char ch;
            if (iss >> ch)
                editor.insertChar(ch);
            else
                std::cout << "Usage: insert <char>";
        }

        else if (cmd == "insert_str")
        {
            std::string str;
            if (iss >> str)
                editor.insertString(str);
            else
                std::cout << "Usage: insert_str <string>";
        }

        else if (cmd == "delete")
        {
            editor.deleteChar();
        }

        else if (cmd == "move_left")
        {
            editor.moveCursorLeft();
        }

        else if (cmd == "move_right")
        {
            editor.moveCursorRight();
        }

        else if (cmd == "undo")
        {
            editor.undo();
        }

        else if (cmd == "redo")
        {
            editor.redo();
        }

        else if (cmd == "save")
        {
            std::string filename;
            if (iss >> filename)
                editor.saveToFile(filename);
            else
                std::cout << "Usage: save <filename>";
        }

        else if (cmd == "load")
        {
            std::string filename;
            if (iss >> filename)
                editor.loadFromFile(filename);
            else
                std::cout << "Usage: load <filename>";
        }

        else if (cmd == "show")
        {
            editor.display();
        }

        else if (cmd == "help")
        {
            std::cout << "Available commands:\n"
                         "  insert <char>\n"
                         "  insert_str <string>\n"
                         "  delete\n"
                         "  move_left\n"
                         "  move_right\n"
                         "  undo\n"
                         "  redo\n"
                         "  show\n"
                         "  exit\n";
        }

        else if (cmd == "exit")
        {
            break;
        }

        else
        {
            std::cout << "Unknown command. Type 'help' for list.";
        }
    }

    return 0;
}
