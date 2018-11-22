#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_PRINT 10
#define MAX_LEVEL 5
#define LEN 1234

class student
{
private:
    char* name;
    int value;
public:
    student(const char* name = 0, int value = 0);
    student(const student & a);
    ~student();
    student& operator=(const student& a);
    int operator<(const student& a)const;
    int get_value()const{
        return value;
    }
    const char* get_name()const{
        return name;
    }
    void print(){
        printf("[%s %d]", name, value);
    }
    int read(FILE* fp);
    void destroy();
    int init(const char* name = 0, int value = 0);
    void swap(student& b);
    void move(student& b);
};
#endif
