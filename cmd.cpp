#include "cmd.h"
#include <string.h>

std::ostream& func (std::ostream& fstr, Info& i, bool command){
    //0 - -output, 1 - -stat
    std::ostream* a = &fstr;
    if (command)
        i.findMain(*a);
    else{
        i.out(*a,1);

    }
    *a<<"\n";
    return (*a);
}

bool do_command (Builder& build,Info& i, const char* fname, InfoResults f,bool command){
    //0 - -output, 1 - -stat
    if (!strcmp(fname, "#con")){
        return (bool)(f(std::cout,i,command));
    }
    std::ofstream ff (fname);
    bool res = (bool)f(ff,i,command);
    ff.close();
    if (ff.fail())
        res = false;
    return res;
}

bool isCommand (const char* com){
    return (strcmp(com, "-output")==0 || strcmp(com, "-stat")==0) ? (true) : (false);
}

void outUndef (const char* fname){
    std::cout<<fname<<" undefined\n";
}

void outOk(bool ok){
    std::cout<< ((ok)? ("OK\n") : ("UPS\n"));
}

void outIgnored (char* mes){
    std::cout<<mes<<" : ignored\n";
}

bool input (Builder& build, Info& data, const char* filename){
    std::cout<<"input "<<filename<<" : ";
    if (build.loadData(data,filename)){
        outOk(1);
        return true;
    }
    else{
        outOk(0);
    }
    return false;
}

void cmd (Builder& build,Info& data,InfoResults f,int num, char* arg []){
    std::cout<<"*****\n";
    if (num <2){
        outUndef("input");
        std::cout<<"*****\n";
        return;
    }

    if (!input(build, data, arg[1])){
        std::cout<<"*****\n";
        return;
    }

    for (int i = 2;i<num;i++){
        if (isCommand(arg[i])){
            //checked if the i element is a command
            if (arg[i+1] && !isCommand(arg[i+1])){
                //argument after command
                //0 - -output, 1 - -stat
                bool command = (!strcmp(arg[i],"-output")) ? false : true;

                if (command){
                    std::cout<<"stat";
                }
                else{
                    std::cout<<"output";
                }

                std::cout<<" "<<arg[i+1]<<" : ";

                if (!strcmp(arg[i+1],"#con")){
                    //std::cout<<std::endl;
                    do_command(build,data,arg[i+1],f, command);
                }
                else{
                    if (do_command(build,data,arg[i+1],f, command)){
                        outOk(1);
                    }
                    else{
                        outOk(0);
                    }
                }
                 i++;
            }
            else{
                outUndef(arg[i]);
            }
        }
        else{
            outIgnored(arg[i]);
        }
    }
    std::cout<<"*****";
}
