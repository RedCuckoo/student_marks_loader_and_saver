#include "builder.h"
#include <string.h>

char* Builder::strdup (const char* s){
      size_t slen = strlen(s);
      char* result = (char*)malloc(slen + 1);
      if(result == NULL)
      {
        return NULL;
      }
      memcpy(result, s, slen+1);
      return result;
}

void Builder::reloadLexer (std::ifstream &input, std::string& work){
    getline (input, work);
    reader.load(work);
}

void Builder::readHeader(std::ifstream& input, std::string& work,std::string &not_allowed, std::string &excellent_stds){
    reloadLexer(input, work);
   if (reader.next(not_allowed)){
        //new
        counter++;
        //we've read first field and set a type
        if (reader.outType() == 2){
            //is a header
            if (reader.next(excellent_stds)){
                //there are more fields
                throw ("103");
            }
            else{
                return;
            }
        }
        else if (reader.outType() == 0){
            //empty string
            if (!reader.eof()){
                reloadLexer(input,work);
                readHeader(input, work,not_allowed,excellent_stds);
            }
            else{
                throw ("100");
            }
        }
        else{
            throw ("100");
        }
    }
    else{
        throw ("103");
    }
}

std::vector<std::string>& Builder::readLine (std::ifstream& input, std::string& work){
    std::vector<std::string> *res = new std::vector<std::string>;
    std::string temp;

    //numeration
    reloadLexer(input,work);
    reader.next(temp);

    while (reader.outType() == 0){
        //empty string
        reloadLexer(input,work);
        reader.next(temp);
        //if (reader.eof()){
      //      throw "303" ;
        //}
    }

    if (reader.outType() == 1){
        return *res;
    }

    if (temp.size() && stoi(temp)!=counter){
        throw ("301");
    }
    else{
        //line and footer errors should be counter-1
        counter++;
    }


    while (!reader.eof()){
        //while not the end of the string
        reader.next(temp);
        res->push_back(temp);
    }


    if (res->size()!=9){
        throw ("302");
    }
    return *res;
}

void Builder::readFooter (std::ifstream& input, std::string& work, std::string shortest){
    if (!reader.next(shortest)){
        //we've set a type and read the only existing field
        if (reader.outType() == 1){
            //is a footer
            return;
        }
        else if (reader.outType()==0){
            //empty string
            reloadLexer(input,work);
            readFooter(input,work,shortest);
        }
        else{
            throw ("200");
        }
    }
    else{
        throw ("203");
    }
}

bool Builder::loadData(Info& data,const char* filename){
    std::ifstream input (filename);
    std::string work;

    if (input.fail()){
        throw ("400");
    }

    //reloadLexer(input,work);

   //std::cout<<work;

    //it should be 9 elements all together
    std::vector <std::string> temp;

    std::string t1, t2;
    readHeader(input, work,t1, t2);

    //can throw invalid argument!
    data.set_header(stoi(t1),stoi(t2));

    //reloadLexer(input,work);

    //ready to read 9 fields
    temp = readLine(input,work);
    //std::cout<<reader.outType();
    //load!!!
    //std::cout<<temp.size();
    data.load(temp);
    //data.out();
    //changed 1 to 3
    while (reader.outType() == 3){
        temp = readLine(input,work);
        //changed 3 to 1
        if (reader.outType() == 1){
            reader.load(work);
            readFooter(input,work,t1);
            data.set_footer(stoi(t1));
        }
        else if (reader.outType() == 2){
            throw ("300");
        }
        else{
            data.load(temp);
            //data.out();
        }
    }

    return true;
}

int Builder::get_counter(){
    return counter;
}
