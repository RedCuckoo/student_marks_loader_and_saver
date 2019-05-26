#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <iostream>

//class of things
class Student{

public:
    //class of details
    class marks{
    private:
        int final_mark;
        int semester_mark;
        int semester_national_mark;
        int exam_mark;
        char* group_code;
        char* subject;

        bool check_final_and_national (int nat, int fin);

        void set_final_mark (int m);
        void set_semester_mark(int m);
        void set_semester_national_mark(int m);
        void set_exam_mark(int m);
        void set_group_code(char* m);
        void set_subject(char* m);
    public:
        int get_final_mark ();
        int get_semester_mark();
        int get_semester_national_mark();
        int get_exam_mark();
        char* get_group_code();
        char* get_subject();
        marks(int finM, int semM, int semNatM, int exaM, char* groupCode, char* subj);
        bool operator==(marks com);
        bool operator!=(marks com);
        bool operator<(marks com);
        bool operator<=(marks com);
        bool operator>(marks com);
        bool operator>=(marks com);
        void out();
        void out(std::ostream& where, bool full = 0);

    };

    //container of details
    class marksSafer{
    private:
        std::vector<marks> cont;
    public:
        bool empty();
        void sort();
        void add(marks& a);
        size_t size();
        int rating();
        marks* operator[] (size_t i);
        void out();
        void out(std::ostream& where, bool full = 0);
    };

    char* get_family_name ();
    char* get_first_name ();
    char* get_ID ();
    size_t get_exam_amount();
    int get_rating();
    int get_stability();
    void sort();
    Student(char* firN, char* ID, char* famN);

    bool operator==(Student com);
    bool operator!=(Student com);
    bool operator<(Student com);
    bool operator<=(Student com);
    bool operator>(Student com);
    bool operator>=(Student com);
    void test();
    void out();
    void out(std::ostream& where, bool full = 0);
    bool allTop();
    void load (int finM, int semM, int semNatM, int exaM, char* groupCode, char* subj);
private:
    marksSafer all_marks;
    char* family_Name;
    char* first_Name;
    char* ID;
    void set_family_Name(char* famN);
    void set_first_Name (char* firN);
    void set_ID (char* ID);
};


#endif // STUDENT_H
