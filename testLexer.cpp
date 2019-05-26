#include "testLexer.h"

void testLexer(const std::string& testString){
    Lexer test ;
    test.load(testString);

    std::string field;

    while (test.next(field)){
        std::cout<<"["<<field<<"]\n";
    }
    std::cout<<"["<<field<<"]";


    //std::cout<<"\n"<<test.outType();

}
