#include "node.h"
/*#define MAX_PRINT 10
#define LEN 1234
//1 ne open, 2 ne read
int read_array(student* a, int n, const char* filename)
{
    FILE* fp;
    int i;
    if(!(fp = fopen(filename, "r")))
        return 1;
    for(i = 0; i < n; i++)
    {
        if(a[i].read(fp))
        {
            fclose(fp);
            return 2;
        }
    }
    fclose(fp);
    return 0;
}

void print_array(student* a, int n)
{
    int i;
    n = n > MAX_PRINT ? MAX_PRINT : n;
    for(i = 0; i < n; i++)
    {
        printf("%s %d\n", a[i].get_name(), a[i].get_value());
    }
}

void print_list(node* head)
{
    int i;
    for(i = 0; i < MAX_PRINT && head; i++, head = head->get_next())
    {
        printf("%s %d\n", head->get_name(), head->get_value());
    }
    printf("\n");
}
int read_list(node* a, int n, const char* filename)
{
    FILE* fp;
    node *b = a, *tmp;
    int i;
    if(!(fp = fopen(filename, "r")))
        return 1;
    if(b->read(fp))
    {
        fclose(fp);
        return 2;
    }
    for(i = 1; i < n; i++, a = a->get_next())
    {
        tmp = new node;
        if(!tmp)
        {
            fclose(fp);
            return -10;
        }
        if(tmp->read(fp))
        {
            fclose(fp);
            return 2;
        }
        b->set_next(tmp);
        b = tmp;
    }
    fclose(fp);
    return 0;
}

int read_list_file(node* a, const char* filename)
{
    FILE* fp;
    node *b = a, *tmp;
    char buf[LEN];
    int v;
    if(!(fp = fopen(filename, "r")))
        return -1;
    if(b->read(fp))
    {
        fclose(fp);
        return -12;
    }
    while(fscanf(fp, "%s%d", buf, &v) == 2)
    {
        tmp = new node;
        if(!tmp)
        {
            fclose(fp);
            return -10;
        }
        tmp->init(buf, v);
        b->set_next(tmp);
        b = tmp;
    }
    if(!feof(fp))
    {
        fclose(fp);
        return -3;
    }
    fclose(fp);
    return 0;
}
int readlistfile(node2* a, const char* filename)
{
    FILE* fp;
    node2 *b = a, *tmp;
    char buf[LEN];
    int v;
    if(!(fp = fopen(filename, "r")))
        return 1;
    if(b->read(fp))
    {
        fclose(fp);
        return 2;
    }
    while(fscanf(fp, "%s%d", buf, &v) == 2)
    {
        tmp = new node2;
        if(!tmp)
        {
            fclose(fp);
            return -10;
        }
        tmp->init(buf, v);
        b->set_next(tmp);
        tmp->set_prev(b);
        b = tmp;
    }
    if(!feof(fp))
    {
        fclose(fp);
        return 3;
    }
    fclose(fp);
    return 0;
}
void delete_list(node* a)
{
    node* curr;
    while(a)
    {
        curr = a;
        a = curr->get_next();
        curr->destroy();
        delete curr;

    }
}

void printlist(node2* head)
{
    int i;
    for(i = 0; i < MAX_PRINT && head; i++, head = head->get_next())
    {
        printf("%s %d\n", head->get_name(), head->get_value());
    }
    printf("\n");
}
int readlist(node2* a, int n, const char* filename)
{
    FILE* fp;
    node2 *b = a, *tmp;
    int i;
    if(!(fp = fopen(filename, "r")))
        return 1;
    if(b->read(fp))
    {
        fclose(fp);
        return 2;
    }
    for(i = 1; i < n; i++, a = a->get_next())
    {
        tmp = new node2;
        if(!tmp)
        {
            fclose(fp);
            return -10;
        }
        if(tmp->read(fp))
        {
            fclose(fp);
            return 2;
        }
        b->set_next(tmp);
        tmp->set_prev(b);
        b = tmp;
    }
    fclose(fp);
    return 0;
}

void deletelist(node2* a)
{
    node2* curr;
    while(a)
    {
        curr = a;
        a = curr->get_next();
        curr->destroy();
        delete curr;

    }
}
void downprintlist(node2* head)
{
    int i;
    while(head->get_next())
        head = head->get_next();
    for(i = 0; i < MAX_PRINT && head; i++, head = head->get_prev())
    {
        printf("%s %d\n", head->get_name(), head->get_value());
    }
    printf("\n");
}

int get_count(node* a)
{
    int i = 0;
    node* curr = a;
    while(curr)
    {
        i++;
        curr = curr->get_next();
    }
    return i;
}
int getcount(node2* a)
{
    int i = 0;
    node2* curr = a;
    while(curr)
    {
        i++;
        curr = curr->get_next();
    }
    return i;
}

int cmp(const node* a, const node* b)
{
    return (*a < *b);
}
*/
