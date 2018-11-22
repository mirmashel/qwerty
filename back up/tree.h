#include "node.h"



template <class T, template <class> class container>
class tree : public container <T>{
private:
    node<T, container>* root;
    node<T, container>* curr;
    void delete_tree(node<T, container>* root);
    static void add(node<T, container>* tree, node<T, container>* a);
public:
    tree();
    ~tree();
    void test_all(int k);
    void print_tree(node<T, container>* curr = 0, int lev = 0, int kol = 0);
    int read_tree(int m, const char* filename);
    static void set_eq(node<T, container>* root, node<T, container>* a);
    int solve1(int k, int* kol);
    void goto_level(){
        curr = curr->get_level();
    }
    void goto_down(){
        curr = curr->get_down();
    }
    void goto_root(){
        curr = root;
    }
    node<T, container>* get_root(){
        return root;
    }
    node<T, container>* get_curr(){
        return curr;
    }
    void set_root(node<T, container>* a){
        root = a;
    }
    void set_curr(node<T, container>* a){
        curr = a;
    }
};
