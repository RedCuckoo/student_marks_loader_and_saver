#include "info.h"
#include "builder.h"
//#include <string.h>
//#include <iostream>

void Info::studentsSafer::add(Student& a){
    cont.push_back(a);
    //cont[cont.size()-1]->out();
}

bool Info::studentsSafer::empty(){
    return (cont.size()) ? false : true;
}

size_t Info::studentsSafer::size(){
    return cont.size();
}

void Info::studentsSafer::sort(){
    size_t size = cont.size();
    bool swapped = false;
    for(size_t i = 0; i < size-1; i++){
        swapped = false;
        for (size_t j = 0; j < size-1; j++){
            if (cont[j]<cont[j+1]){
                std::swap(cont[j],cont[j+1]);
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
}

size_t Info::studentsSafer::find(char* firN, char* ID, char* famN){
    for (size_t i = 0; i < cont.size(); i++){
        if (atoi(ID) == atoi(cont[i].get_ID())){
            return i;
        }
    }

    Student *a = new Student (firN,ID,famN);
    cont.push_back(*a);
    return cont.size()-1;
}

void Info::studentsSafer::out(){
    for(size_t i = 0; i < cont.size(); i++){
        cont[i].out();
        std::cout<<"\n\t";
    }
}

void Info::studentsSafer::out(std::ostream& where, bool full){
    for(size_t i = 0; i < cont.size(); i++){
        cont[i].out(where, full);
    }
}

Student* Info::studentsSafer::operator[](size_t i){
    return &cont[i];
}

//***********************

void Info::set_header(int not_allowed, int exc_st){
    not_allowed_to_take_Students = not_allowed;
    excellent_Students = exc_st;
}

void Info::set_footer(int short_fam){
    shortestFamName = short_fam;
}

int Info::get_not_allowed_Stds(){
    return not_allowed_to_take_Students;
}

int Info::get_excellent_Stds(){
    return excellent_Students;
}

int Info::get_shortest_famName(){
    return shortestFamName;
}

void Info::load(std::vector<std::string> i){
    load(stoi(i[0]),stoi(i[1]),stoi(i[2]),stoi(i[3]),Builder::strdup(i[4].c_str()),Builder::strdup(i[5].c_str()),Builder::strdup(i[6].c_str()),Builder::strdup(i[7].c_str()),Builder::strdup(i[8].c_str()));
}

void Info::load (char* first_Name, char* ID, char* family_Name){
    Student a (first_Name,ID, family_Name);
    studentsSafer().add(a);
}
void Info::load (int final_mark, int sem_mark, int nat_sem_mark, int ex_mark, char* code_group,char* subj, char* firN,char* ID, char* famN){
    size_t which = all_Students.find(firN, ID, famN);
    all_Students[which]->load(final_mark,sem_mark,nat_sem_mark,ex_mark,code_group,subj);
}

void Info::out(){
    all_Students.out();
}

void Info::out(std::ostream& where, bool full){
    all_Students.out(where, full);
}

Student* Info::operator[] (size_t i){
    return all_Students[i];
}

std::vector<size_t> Info::findTop(){
    std::vector<size_t> ans;
    for(size_t i = 0; i < all_Students.size(); i++){
        if (all_Students[i]->allTop()){
            ans.push_back(i);
            //all_Students[i]->out();
        }
    }
    return ans;
}

void Info::sortMain(){
    all_Students.sort();
}

void Info::findMain(std::ostream& out){
    all_Students.sort();
   // this->out();
    std::vector<size_t> to_out = findTop();
      for(size_t i = 0; i < to_out.size(); i++){
        out<<"\n"<<all_Students[i]->get_family_name()<<" "<<all_Students[i]->get_first_name()<<" "<<all_Students[i]->get_ID();
        out<<" "<<all_Students[i]->get_exam_amount()<<" "<<all_Students[i]->get_stability()<<" "<<all_Students[i]->get_rating();
        //std::cout<<"\n\t";
        all_Students[i]->sort();
        all_Students[i]->out(out);
        //out<<"\n";
    }


}
