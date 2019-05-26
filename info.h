#ifndef INFO_H
#define INFO_H
#include <string>
#include <vector>
#include "student.h"
#include <iostream>

class Info{
public:
    //container of things
    class studentsSafer{
    private:
        std::vector<Student> cont;
    public:
        void out();
        void out(std::ostream& where, bool full = 0);
        void add(Student& a);
        size_t find(char* firN, char* ID, char* famN);
        Student* operator[](size_t i);
        bool empty();
        size_t size();
        void sort();
    };
    void out();
    void out(std::ostream& where,bool full = 0);
    void set_header(int not_allowed, int exc_st);
    void set_footer(int short_fam);

    int get_not_allowed_Stds();
    int get_excellent_Stds();
    int get_shortest_famName();

    void load (std::vector<std::string> i);
    void load (char* first_Name, char* ID, char* family_Name);
    void load (int final_mark, int sem_mark, int nat_sem_mark, int ex_mark, char* code_group,char* subj, char* firN,char* ID, char* famN);
    Student* operator[] (size_t i);
    void sortMain();
    void findMain(std::ostream& out);
private:
    std::vector<size_t>findTop();
    int not_allowed_to_take_Students;
    int excellent_Students;
    int shortestFamName;
    studentsSafer all_Students;
};


#endif // INFO_H
