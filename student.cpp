#include "student.h"
#include <exception>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <cmath>

//getters for class of details (marks)
int Student::marks::get_final_mark (){
    return final_mark;
}

int Student::marks::get_semester_mark(){
    return semester_mark;

}

int Student::marks::get_semester_national_mark(){
    return semester_national_mark;
}

int Student::marks::get_exam_mark(){
    return exam_mark;
}

char* Student::marks::get_group_code(){
    return group_code;
}

char* Student::marks::get_subject(){
    return subject;
}

void Student::marks::out(){
    std::cout<<semester_mark<<" "<<exam_mark<<" "<<final_mark<<" "<<subject;
    //std::cout<<final_mark<<" "<<semester_mark<<" ";
   // std::cout<<semester_national_mark<<" "<<exam_mark<<" ";
   // std::cout<<group_code<<" "<<subject<<"\n";
}

void Student::marks::out(std::ostream& where, bool full){
    if (!full)
        where<<semester_mark<<" "<<exam_mark<<" "<<final_mark<<" "<<subject;
    else{
        where<<final_mark<<" "<<semester_mark<<" ";
        where<<semester_national_mark<<" "<<exam_mark<<" ";
        where<<group_code<<" "<<subject;
    }
}

//setters for class of details (marks)
bool Student::marks::check_final_and_national(int nat, int fin){
    switch (nat){
    case 2:
        return(fin>=60)? 0 : 1;
    case 3:
        return (fin<60||fin>75) ? 0 : 1;
    case 4:
        return (fin<75 || fin>=90) ? 0 : 1;
    case 5:
        return (fin<90) ? 0 : 1;
    default:
        return (fin<60) ? 1 : 0;
    }
}

void Student::marks::set_final_mark (int m){
    if (m>100 || m<0){
        throw ("303");
    }
    else{
        final_mark = m;
    }
}

void Student::marks::set_semester_mark(int m){
    if (m>60 || m<0){
        throw ("303");
    }
    else{
        semester_mark = m;
    }
}

void Student::marks::set_semester_national_mark(int m){
    if (m>5 || m<-1 || !check_final_and_national(m, get_final_mark())){
        throw ("303");
    }
    else{
        semester_national_mark = m;
    }
}

void Student::marks::set_exam_mark(int m){
    if ((m>40 || m<24) && m!=0){
        throw ("303");
    }
    else{
        exam_mark = m;
    }
}

void Student::marks::set_group_code(char* m){
    int m_len = strlen(m);
    if (m_len>3){
        throw std::exception();
        return;
    }

    for (int i = 0; i < m_len;i++){
        if (!isalnum(m[i]) && m[i]!= '-'){
            throw std::exception();
            return;
        }
    }
    group_code = m;
}

void Student::marks::set_subject(char* m){
    int m_len = strlen(m);
    if (m_len>59){
        throw std::exception();
        return;
    }

    for (int i = 0 ; i < m_len; i++){
        if (!isalpha(m[i]) && m[i]!= ' ' && m[i]!= '"' && m[i] != '-'){
            throw std::exception();
            return;
        }
    }
    subject = m;

}

//constructor and operators overload for class of details (marks)
Student::marks::marks(int finM, int semM, int semNatM, int exaM, char* groupCode, char* subj){
    set_final_mark(finM);
    set_semester_mark(semM);
    set_semester_national_mark(semNatM);
    set_exam_mark(exaM);
    set_group_code(groupCode);
    set_subject(subj);
}

bool Student::marks::operator==(marks com){
    if (semester_mark == com.get_semester_mark()){
        return (subject == com.subject) ? (true) : (false);
    }
    else{
        return false;
    }
}

bool Student::marks::operator!=(marks com){
    if (semester_mark != com.get_semester_mark()){
        return true;
    }
    else{
        return (subject != com.subject)?(true) :(false);
    }
}

bool Student::marks::operator<(marks com){
    if (semester_mark < com.get_semester_mark()){
        return true;
    }
    else{
        if (semester_mark == com.get_semester_mark()){
            return (strcmp(subject, com.subject)<0)?(true):(false);
        }
        else{
            return false;
        }
    }
}

bool Student::marks::operator<=(marks com){
    if (semester_mark < com.get_semester_mark()){
        return true;
    }
    else{
        if (semester_mark == com.get_exam_mark()){
            return (strcmp(subject,com.get_subject())<=0)? (true) : (false);
        }
        else{
            return false;
        }
    }
}

bool Student::marks::operator>(marks com){
    if (semester_mark > com.get_semester_mark()){
        return true;
    }
    else{
        if (semester_mark == com.get_semester_mark()){
            return (strcmp(subject, com.subject)>0)?(true):(false);
        }
        else{
            return false;
        }
    }
}

bool Student::marks::operator>=(marks com){
    if (semester_mark > com.get_semester_mark()){
        return true;
    }
    else{
        if (semester_mark == com.get_exam_mark()){
            return (strcmp(subject,com.get_subject())>=0)? (true) : (false);
        }
        else{
            return false;
        }
    }
}
//********************************************************************************

//getters for class of things (Students)
char* Student::get_family_name (){
    return family_Name;
}

char* Student::get_first_name (){
    return first_Name;
}

char* Student::get_ID (){
    return ID;
}

size_t Student::get_exam_amount(){
    return all_marks.size();
}

int Student::get_rating(){
    return all_marks.rating();
}

int Student::get_stability(){
    int max, min;
    if (all_marks.size() == 0){
        return -1;
    }
    else{
        max = all_marks[0]->get_final_mark();
        min = all_marks[0]->get_final_mark();

        for (size_t i = 0; i < all_marks.size(); i++){
            if (all_marks[i]->get_final_mark() > max){
                max = all_marks[i]->get_final_mark();
            }
            if (all_marks[i]->get_final_mark() < min){
                min = all_marks[i]->get_final_mark();
            }
        }
    }


    return abs(max-min);
}

void Student::sort(){
    all_marks.sort();
}

//setters
void Student::set_family_Name(char* famN){
    int len = strlen(famN);

    if (len>20 ){
        throw std::exception();
        return;
    }

    for (int i = 0; i<len;++i){
        if (!isalpha(famN[i]) && famN[i]!= '\'' && famN [i]!='-'){
            throw std::exception();
            return;
        }
    }

    family_Name = famN;
}

void Student::set_first_Name (char* firN){
    int len = strlen (firN);

    if (len >27){
        throw std::exception();
    }


    for (int i = 0; i<len;++i){
        if (!isalpha(firN[i]) && firN[i]!= '\'' && firN [i]!='-'){
            throw std::exception();
            return;
        }
    }

    first_Name = firN;
}

void Student::set_ID (char* ID){
    if (strlen(ID) != 7){
        throw std::exception ();
    }
    else{
        for (int i = 0; i<7;i++){
            if (!isdigit(ID[i])){
                throw std::exception();
            }
        }
        this->ID = ID;
    }
}

Student::Student(char* firN, char* ID, char* famN){
    set_first_Name(firN);
    set_family_Name(famN);
    set_ID(ID);
}

void Student::load (int finM, int semM, int semNatM, int exaM, char* groupCode, char* subj){
    marks ret (finM,semM,semNatM,exaM,groupCode,subj);
    all_marks.add(ret);
    //this->out();

}

bool Student::allTop(){
    for (size_t i = 0; i < all_marks.size(); i++){
        if (all_marks[i]->get_semester_national_mark() != 5){
            return false;
        }
    }
    return true;
}

Student::marks* Student::marksSafer::operator[](size_t i){
    return &cont[i];
}

bool Student::operator==(Student com){
    return (strcmp(ID, com.get_ID())==0)? (true) : (false);
}

bool Student::operator!=(Student com){
    return (strcmp(ID,com.get_ID())!=0)? (true) : (false);
}

bool Student::operator<(Student com){
    if (all_marks.size() < com.get_exam_amount()){
        return true;
    }
    else if (all_marks.size() == com.get_exam_amount()){
        if (all_marks.rating()<com.get_rating()){
            return true;
        }
        else if (all_marks.rating() == com.get_rating()){
            if (strcmp(family_Name, com.get_family_name())<0){
                return true;
            }
            else if (!strcmp(family_Name,com.get_family_name())){
                if (strcmp(ID, com.get_ID())<0){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

}

bool Student::operator<=(Student com){
    if(*this==com || *this<com){
        return true;
    }
    else{
        return false;
    }
}

bool Student::operator>(Student com){
    if (all_marks.size() > com.get_exam_amount()){
        return true;
    }
    else if (all_marks.size() == com.get_exam_amount()){
        if (all_marks.rating()>com.get_rating()){
            return true;
        }
        else if (all_marks.rating() == com.get_rating()){
            if (strcmp(family_Name, com.get_family_name())>0){
                return true;
            }
            else if (strcmp(family_Name,com.get_family_name())==0){
                if (strcmp(ID, com.get_ID())>0){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

}

bool Student::operator>=(Student com){
    if(*this==com || *this>com){
        return true;
    }
    else{
        return false;
    }
}

void Student::test(){
    marks k (90,50,5,40,(char*)"K-1",(char*)"PRogramming");
    marks a (90,50,5,40,(char*)"K-1",(char*)"PRogramming");
    marks b (80,40,4,40,(char*)"K-1",(char*)"Dyscrete Mathematics");
    (a<=b)? (std::cout<<"OK\n") : (std::cout<<"UPS\n");
    (k<a)? (std::cout<<"OK\n") : (std::cout<<"UPS\n");
    (b==a)? (std::cout<<"OK\n") : (std::cout<<"UPS\n");
}

void Student::out(){
   // std::cout<<family_Name<<" "<<first_Name<<" "<<ID<<" ";
    all_marks.out();
    //std::cout<<"\n\t";
}

void Student::out(std::ostream& where, bool full){
    if(full)
        where<<"\n"<<family_Name<<" "<<first_Name<<" "<<ID<<" ";
    all_marks.out(where, full);
}

//********************************************************************
//safer class

void Student::marksSafer::add(marks& a){
    cont.push_back(a);
}

bool Student::marksSafer::empty(){
    return (cont.size()) ? false : true;
}

int Student::marksSafer::rating(){
    int ans = 0;
    for(size_t i = 0; i < cont.size(); i++){
        ans += cont[i].get_final_mark();
    }
    ans /=cont.size();


    return ans;
}

size_t Student::marksSafer::size(){
    return cont.size();
}

void Student::marksSafer::out(){
    for (size_t i = 0; i < cont.size(); i++){
        std::cout<<"\n\t";
        cont[i].out();
    }
}

void Student::marksSafer::out(std::ostream& where, bool full){
    for(size_t i = 0; i < cont.size(); i++){
        where<<"\n\t";
        cont[i].out(where, full);
    }
}

void Student::marksSafer::sort(){
    size_t size = cont.size();
    bool t = false;
    for (size_t i = 0; i < size-1; i++){
        t = false;
        for(size_t j = 0; j < size - 1; j++){
            if (cont[j] < cont[j+1]){
                std::swap(cont[j],cont[j+1]);
                t = true;
            }
        }
        if (!t)
            break;
    }
}

