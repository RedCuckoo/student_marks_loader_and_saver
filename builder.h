#ifndef BUILDER_H
#define BUILDER_H

#include "info.h"
#include "Lexer.h"
#include <string>
#include <fstream>
#include <vector>

class Builder{

private:
    Lexer reader;
    int counter = 0;
    size_t stringCounter = 0;
    void reloadLexer (std::ifstream &input, std::string& work);
    void readHeader (std::ifstream& input, std::string& work,std::string &not_allowed, std::string &excellent_stds);
    std::vector<std::string>& readLine (std::ifstream& input, std::string& work);
    void readFooter (std::ifstream& input, std::string& work, std::string shortest);
    void loadToInfo(Info& data,std::vector<std::string>& in);
public:
    static char* strdup (const char* s);
    int get_counter ();
    bool loadData (Info&,const char* filename);
};

#endif // BUILDER_H
