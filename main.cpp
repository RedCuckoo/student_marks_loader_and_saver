//by Momotenko Yurii

#include <iostream>
#include "info.h"
#include "builder.h"
#include "cmd.h"

#define DEBUG

//#include "copyright.h"

void help (){
    std::cout<<"<name of input file .txt> - first argument\n";
    std::cout<<"-output - to write out the info to the following <name of the output file .txt>\n";
    std::cout<<"if you would like to write out to the console - enter #con instead of filename\n";
    std::cout<<"-stat - some statistics on the program\n";
    std::cout<<"you can use multiple commands, however only single input file\n";
}



int main(int argc, char* argv[]){

    Builder build;
    try{
        //copyright();
        help();
        Info cont;
        cmd(build,cont,func,argc,argv);
    }
    catch(const  char* msg){
        std::cout<<"\n"<<msg<<" "<<build.get_counter()<<" ";
        switch (atoi(msg)){
        case 100:
            std::cout<<"missing header";
            break;
        case 101:
            std::cout<<"more than one header";
            break;
        case 102:
            std::cout<<"header type is wrong";
            break;
        case 103:
            std::cout<<"wrong amount of fields in the header";
            break;
        case 104:
            std::cout<<"some problems with a header";
            break;
        case 200:
            std::cout<<"missing footer";
            break;
        case 201:
            std::cout<<"more than one footer";
            break;
        case 202:
            std::cout<<"footer type is wrong";
            break;
        case 203:
            std::cout<<"wrong amount of fields in the footer";
            break;
        case 204:
            std::cout<<"some problems with a footer";
            break;
        case 300:
            std::cout<<"wrong order of header - lines - footer";
            break;
        case 301:
            std::cout<<"wrong numeration of lines";
            break;
        case 302:
            std::cout<<"wrong amount of fields in the line";
            break;
        case 303:
            std::cout<<"some problems with the line";
            break;
        case 400:
            std::cout<<"file error";
            break;
        case 500:
            std::cout<<"bad_alloc";
            break;

        }
    }
}
