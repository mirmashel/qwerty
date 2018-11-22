#ifndef NODE_H
#define NODE_H

#include "queue.h"
//uzel, sostoyashiy iz stacka iz studentov
template <class T, template <class> class container>

class node : public container <T>{
private:
    node* level;
    node* down;
public:
    node() : container<T>(){
        down = 0;
        level = 0;
    }
    node(const node& a) : container<T>(a){
        level = 0;
        down = 0;
    }
    ~node(){
        down = 0;
        level = 0;
    }
    /*node &operator=(const T& rhs){
        *((T *) this) = rhs;
        down = 0;
        level = 0;
        return *this;
    }*/
    node* get_down() const{
        return down;
    }
    node* get_level() const{
        return level;
    }
    void set_down(node* down){
        this->down = down;
    }
    void set_level(node* level){
        this->level = level;
    }
    void print_node() const{
        this->print();
    }
    //friend void add(node* root, node* a);
};
#endif
