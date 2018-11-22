#include "tree.h"

int main(int argc, char* argv[])
{
    int m = atoi(argv[1]);
    queuee<student> a;
    FILE* fp = fopen("a.txt", "r");
    a.read(m, fp);
    a.print();
    fclose(fp);
    tree<student, queuee> b;
    b.read_tree(m, "a.txt");
    b.print_tree();
    return 0;
}
