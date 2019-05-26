#include "Lexer.h"

void Lexer::load(std::string const& in){
    input = in;
    eos = false;
    currentPosition = -1; lastPosition = -1;
    return;
}

void Lexer::lineType(const std::string &field){
    if (field.empty()){
        type = Empty;
    }
    else if (field == "header"){
        type = Header;
    }
    else if (field == "footer"){
        type = Footer;
    }
    else if (isdigit(field[0])){
        type = Line;
    }
    else{
        type = Line;
        //???
    }
}

bool Lexer::checkEmpty(){
    int t_cp = currentPosition;
    int t_lp = lastPosition;
    currentPosition = -1; lastPosition = -1;
    std::string field;
    while (this->next(field)){
        if (!(field.empty())){
            currentPosition = t_cp;
            lastPosition = t_lp;
            return false;
        }
    }
    currentPosition = t_cp;
    lastPosition = t_lp;

    return true;
}

bool Lexer::next (std::string& field){
    bool first = false;

    if (input.empty()){
        field.clear();

        //input string is empty
        lineType(field);

        eos = true;
        return false;
    }
    else{
        if (currentPosition==-1){
            //if beginning
            first = true;
            currentPosition = input.find_first_not_of (" \n\r\t\v\f");
        }
        else{
            currentPosition = input.find_first_not_of (" \n\r\t\v\f",currentPosition);
        }

        if ((size_t)currentPosition == input.npos){
            field.clear();

            //if it was the first field however we got to the end of line ==
            //empty input string
            if (first) lineType(field);

            eos = true;
            return false;
        }
        else{
            //currentPosition points to some value
            lastPosition = input.find_first_of (",/", currentPosition);
            if ((size_t)lastPosition == input.npos){
                //no divider
                lastPosition = input.find_last_not_of (" \n\t\v\r\f");
                field = input.substr(currentPosition,lastPosition-currentPosition+1);

                //it is the last field without dividers
                //the if checks it is the only field
                if (first) {
                    lineType(field);
                    if (type == Header || type == Footer){
                        field.clear();
                    }
                }

                eos = true;
                return false;
            }
            else if (lastPosition == currentPosition){
                field.clear();
                currentPosition++;

                //if the field is empty and there is nothing, like <divider><divider>
                if (first){
                    lineType(field);

                    int t_cp = currentPosition,t_lp = lastPosition;
                    bool endFunc;
                    do {
                        endFunc = this->next(field);
                        if (!field.empty()){
                            currentPosition = t_cp;
                            lastPosition = t_lp;
                            field.clear();
                            type = Line;
                            return true;
                        }
                    }while(endFunc);

                    currentPosition = t_cp;
                    lastPosition = t_lp;
                    type = Empty;
                    return true;

                }

                return true;
            }
            else{
                //there is a divider
                //finding the end of field
                lastPosition = input.find_last_not_of (" \n\t\v\r\f",lastPosition-1);
                field = input.substr(currentPosition,lastPosition-currentPosition+1);

                //finding the next divider to prepare function for next check
                lastPosition = input.find_first_of (",/",lastPosition);
                currentPosition = lastPosition+1;


                if (first){
                    lineType(field);
                    //checking for header/footer
                    if (type == Header || type == Footer){
                        return this->next (field);

                    }
                }
            }
        }
    }

    return true;
}

bool Lexer::eof()const noexcept{
    return eos;
}

size_t Lexer::outType (){
    return type;
}
