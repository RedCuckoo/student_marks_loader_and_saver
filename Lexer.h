#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <string>

class Lexer {
private:
    enum LineType {Empty, Footer, Header, Line};
    LineType type;
    std::string input;
    bool eos = false;
    int currentPosition = -1, lastPosition = -1;
public:
    void load (std::string const& in);
    bool next (std::string& field);
    bool eof()const noexcept;
    void lineType (const std::string& field);
    bool checkEmpty();
    size_t outType ();
};
#endif
