#ifndef QUEUE_H
#define QUEUE_H

#include "student.h"
template <class T>
class node_queue : public T{
private:
    node_queue* next;
public:
    node_queue(const char* name = 0, int value = 0) : T(name, value){
        next = 0;
    }
    node_queue(const node_queue & i) : T(i){
        next = 0;
    }
    ~node_queue(){
        next = 0;
    }
    node_queue<T>& operator=(const T& rhs){
        *((T *) this) = rhs;
        next = 0;
        return *this;
    }
    node_queue<T>* get_next() const{
        return next;
    }
    void set_next(node_queue<T>* next){
        this->next = next;
    }
};

template <class T>
class queuee : public T{
private:
    node_queue<T>* head;
    node_queue<T>* tail;
    node_queue<T>* curr;
public:
    queuee(){
        head = 0;
        tail = 0;
        curr = 0;
    }
    ~queuee(){
        delete_queue();
        curr = 0;
        head = 0;
        tail = 0;
    }
    node_queue<T>* get_head() const{
        return head;
    }
    node_queue<T>* get_curr() const{
        return curr;
    }
    node_queue<T>* get_tail() const{
        return tail;
    }
    void set_head(node_queue<T>* a){
        head = a;
    }
    void set_tail(node_queue<T>* a){
        tail = a;
    }
    int empty_queue(){
        if(!tail)
            return 1;
        return 0;
    }
    void delete_queue(node_queue<T>* curr = 0);
    void print(node_queue<T>* curr = 0) const;
    int read(int n, FILE* fp);
    int read_queue_file(FILE* fp);
    void add(node_queue<T>* a);
    int operator<(const queuee<T>& a)const{
        return (*head < *(a.get_head()));
    }
};
#endif
