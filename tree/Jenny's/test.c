#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct t
{
    int d;
    struct t *left;
    struct t *right;
};
int main()
{
     struct t *new=(struct t*)malloc(sizeof(struct t));
     new->d=5;
     if(new->left==NULL)
        printf("C");
    else
        printf("D");
}