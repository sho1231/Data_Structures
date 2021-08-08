#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct t
{
    int d;
    struct t *left;
    struct t *right;
};
void create_node(struct t *n)
{
    //printf("Enter data:",n->d);
    scanf("%d",&n->d);
    if(n->d==-1)
        return ;
    struct t *le=(struct t*)malloc(sizeof(struct t));
    printf("Enter left child for root %d:",n->d);
    n->left=le;
    create_node(le);
    struct t *ri=(struct t*)malloc(sizeof(struct t));
    printf("Enter data of rigth child for %d:",n->d);
    n->right=ri;
    create_node(ri);

}
void pre_or(struct t *n)
{
  if(n->d==-1)
    return ;
 printf("%d ",n->d);
 pre_or(n->left);
 pre_or(n->right);
   
}
void post_or(struct t *n)
{
    if(n->d!=-1)
    {
        post_or(n->left);
        post_or(n->right);
        printf("%d ",n->d);
    }
}
void in_or(struct t *n)
{
    if(n->d!=-1)
    {
        in_or(n->left);
        printf("%d ",n->d);
        in_or(n->right);
    }
}
int main()
{
 printf("Enter root value:");
 struct t *new=(struct t*)malloc(sizeof(struct t));
create_node(new);
//pre_or(new);
//post_or(new);
in_or(new);
return 0;
}