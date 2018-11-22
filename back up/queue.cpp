#include "queue.h"

template <class T>
void queuee<T>::delete_queue(node_queue<T>* curr){
    if(!curr)
        curr = head;
    node_queue<T>* next;

    while(curr){
        next = curr->get_next();
        delete curr;
        curr = next;
    }
}
template <class T>
void queuee<T>::print(node_queue<T>* curr)const{
    int i;
    if(!curr)
        curr = head;

    for(i = 0; i < MAX_PRINT && curr; i++, curr = curr->get_next()){
        curr->print();
        printf(" ");
    }
    printf("\n");
}
template <class T>
int queuee<T>::read_queue_file(FILE* fp)
{
    node_queue<T> *tmp = new node_queue<T>;
    char buf[LEN];
    int v;
    if(tmp->read(fp)){
        fclose(fp);
        return -2;
    }
    add(tmp);
    while(fscanf(fp, "%s%d", buf, &v) == 2){
        tmp = new node_queue<T>;
        if(!tmp){
            fclose(fp);
            return -3;
        }
        tmp->init(buf, v);
        add(tmp);
    }
    if(!feof(fp)){
        fclose(fp);
        return -3;
    }
    fclose(fp);
    return 0;
}
template <class T>
int queuee<T>::read(int n, FILE* fp)
{
    node_queue<T> *tmp = new node_queue<T>;
    int i = 1;
    if(tmp->read(fp))
        return -2;
    add(tmp);
    for(i = 1; i < n && !feof(fp); i++){
        tmp = new node_queue<T>;
        if(!tmp)
            return -3;
        if(tmp->read(fp))
            return -4;
        add(tmp);
    }
    return i;
}
template <class T>
void queuee<T>::add(node_queue<T>* a){
    if(empty_queue()){
        set_head(a);
        set_tail(a);
        return;
    }
    tail->set_next(a);
    set_tail(a);
}

//explicit instantiation
template class queuee<student>;
