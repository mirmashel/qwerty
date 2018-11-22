#include "tree.h"
template <class T, template <class> class container>
tree<T, container>::tree()
{
    root = new node<T, container>;
    curr = root;
}
template <class T, template <class> class container>
tree<T, container>::~tree()
{
    if(root)
        delete_tree(root);
    root = 0;
    curr = 0;
}
template <class T, template <class> class container>
void tree<T, container>::delete_tree (node<T, container> *root){
    if (root->get_level()){
        delete_tree(root->get_level());
    }
    if (root->get_down()){
        delete_tree(root->get_down());
    }
    delete root;
    root = 0;
}


template <class T, template <class> class container>
void tree<T, container>::test_all(int k)
{
    double t;
    int res, kol = 0, lev = 0, flag = 0;
    goto_root();
    t = clock();
    res = solve1(k, &kol);
    t = (clock() - t) / CLOCKS_PER_SEC;
    printf("1:\ntime = %.2f\nres = %d\n", t, res);
}
template <class T, template <class> class container>
void tree<T, container>::print_tree(node<T, container>* curr, int lev, int kol)
{
    int i = 0;
    if(!curr)
        curr = root;

    if(lev > MAX_LEVEL)
        return;

    curr->print_node();

    if(curr->get_level()){
        printf("--->");
        print_tree(curr->get_level(), lev, kol + 1);
    }
    printf("\n");
    if(curr->get_down()){
        for(i = 0; i < kol; i++) printf("         ");
        print_tree(curr->get_down(), lev + 1, kol);
    }
}
template <class T, template <class> class container>
void tree<T, container>::set_eq(node<T, container>* root, node<T, container>* a)
{
    if(root->get_down())
        set_eq(root->get_down(), a);
    else
        root->set_down(a);
}
template <class T, template <class> class container>
void tree<T, container>::add(node<T, container>* root, node<T, container>* a)
{
    //root != 0
    int cmp = (*a < *root), cmp_;
    node<T, container>* tmp, *tmp_;
    tmp = root->get_down();
    if(!tmp){
        root->set_down(a);
        return;
    }
    if(cmp < 0){
        if((*tmp < *root) < 0)
           add(tmp, a);
        else{
            root->set_down(a);
            a->set_level(tmp);
        }
    }
    if(cmp == 0){
        if((*tmp < *root) > 0){
            root->set_down(a);
            a->set_level(tmp);
        }
        else{
            tmp_ = tmp->get_level();
            if((*tmp < *root) < 0){
                if(!tmp_)
                    tmp->set_level(a);
                else{
                    if((*tmp_ < *root) > 0){
                        a->set_level(tmp_);
                        tmp->set_level(a);
                    }
                    else
                        set_eq(tmp_, a);
                }
            }
            else
                set_eq(tmp, a);
        }
    }
    if(cmp > 0){
        if((*tmp < *root) > 0)
            add(tmp, a);
        else{
            tmp_ = tmp->get_level();
            if(!tmp_)
                tmp->set_level(a);
            else{
                if((*tmp < *root) < 0){
                    if((*tmp_ < *root) == 0){
                        if(!tmp_->get_level())
                            tmp_->set_level(a);
                        else
                            add(tmp_->get_level(), a);
                    }
                    else
                        add(tmp_, a);
                }
                else
                    add(tmp_, a);
            }
        }
    }
}

template <class T, template <class> class container>
int tree<T, container>::read_tree(int m, const char* name)
{
    int i = 1, k;
    node<T, container> *tmp;
    FILE* fp = fopen(name, "r");
    if(!fp){
        printf("ploho in %s\n", name);
        return -1;
    }
    root->read(m, fp);
    //if(feof(fp)){
    //    fclose(fp);
    //    return i;
    //}
    //tmp = new node<T, container>;
    while(!feof(fp) && (tmp = new node<T, container>) && (k = tmp->read(m, fp))){
        printf("pisun%d", k);
        add(root, tmp);

    }
    if(!feof(fp)){
        fclose(fp);
        return -4;
    }
    fclose(fp);
    printf("\n");
    return i;
}


/*
//1
int tree::solve1(int k, int* kol)
{
    int lev = 0, res = 0;
    node* down = curr->get_down(), *level = curr->get_level();
    if(down)
    {
        set_curr(down);
        res = solve1(k, &lev);
        if(lev == k - 1)
            res += 1;
    }
    if(level)
    {
        set_curr(level);
        *kol = *kol + 1;
        res += solve1(k, kol);
    }
    return res;
}

*/
