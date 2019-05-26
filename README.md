# student_marks_loader_and_saver
by Momotenko Yurii

Information about student's marks is stored in files

"Field" is a word or set of words separated either with '/' or ','.

The first line is always a header, which starts with "header" key word. Two following integers are some statistics of the file: number of students who are not allowed to take exams and number of students who have only top marks.

The following can be either a regular line or an empty line (it will be skipped).

A regular line starts with the number of the line, which should be in order. 
  The following field are relatively:
    final mark for the subject (from 0 to 100);
    mark for the term (from 0 to 60);
    final mark in national grading system (from 1 to 5);
    mark for the exam in this subject (from 0 to 40);
    code of the group which consists of 3 chars;
    name of the subject which consists not more than 59 chars;
    first name of the student (not more than 27 characters);
    unique identification number (ID) of the student (each student charaterised by ID), the length is 7;
    family name of the student (not more than 20 characters);
   
The last line is always a footer, which starts with "footer" key word. The following is the integer, which charactarizes the shortest family name in the file.

_____________________________________

Program runs, using command line.
The first command is required, it starts with "input" and follows by the name of the file.
The program will say whether the file was read successfully or not.
One loaded, there two commands:
  "-output" followed either by the name of the file or "#con". The command says the program to show the information to the user by either outputting it to the file or the console relatively.
  "-stat" followed either by the name of the file or "#con". The command says the program to show some statistics to the user by either outputting it to the file or the console relatively. The statistic is formed from the students, who had top marks in all subjects, outputting: family name, first name, ID, number of exams taken, stability, rating; then each subject from the new line with the following information: mark for the term, mark for the exam in this subject, final mark for the subject, name of the subject.
If the unloading was unsuccessful relatable diagnostic message will inform of the error.
_____________________________________
