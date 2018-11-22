#include "student.h"

//-1 if ploho mem, 0 horosho
int student::init(const char* name, int value)
{
    if(name)
    {
        this->name = new char[strlen(name) + 1];
        if(!this->name) return -1;
        strcpy(this->name, name);
    }
    else this->name = 0;
    this->value = value;
    return 0;
}
void student::destroy()
{
    if(name)
    {
        delete [] name;
        name = 0; //?
    }
    value = 0;
}

student::student(const char *name, int value){
    init(name, value);
}

student::student(const student &a){
    this->init(a.name, a.value);
}

student::~student(){
    destroy();
}

student& student::operator=(const student &a){
    destroy();
    //this->init(a.name, a.value);
    init(a.name, a.value);
    return *this;
}
//this < a -1, = 0 , > 1
int student::operator<(const student& a)const{
    int res;
    if(name && a.name)
    {
        res = strcmp(name, a.name);
        if(res) return res;
        return value - a.value;
    }
    if(!name && a.name) return -1;
    if(name && !a.name) return 1;
    return value - a.value;
}

//1 - ne prochitalos, -1 mem ploho
int student::read(FILE *fp)
{
    char buf[LEN];
    int v;
    if(fscanf(fp, "%s%d", buf, &v) != 2)
        return 1;
    destroy();
    return init(buf, v);
}

void student::move(student& b)
{
    b.name = name;
    b.value = value;
    value = 0;
    name = 0;
}

void student::swap(student& b)
{
    char *s;
    int v;
    s = this->name;
    this->name = b.name;
    b.name = s;
    v = this->value;
    this->value = b.value;
    b.value = v;
}

