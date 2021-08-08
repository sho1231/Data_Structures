#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tree
{
    int da;
    struct tree *left, *right;
};
struct tree *root;
struct tree *create()
{
    struct tree *new;
    new = (struct tree *)malloc(sizeof(struct tree));
    printf("Enter data:");
    scanf("%d", &new->da);
    if (new->da == -1)
        return 0;
    printf("Enter left child for %d\n", new->da);
    new->left = create();
    printf("Enter right child for %d\n", new->da);
    new->right = create();
    return new;
}
void preorder(struct tree *root)
{
    if (root == 0)
        return;
    printf("%d ", root->da);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct tree *root)
{
     if(root==0)
        return ;
    inorder(root->left);
    printf("%d ",root->da);
    inorder(root->right);
}
void postorder(struct tree *root)
{
    if(root==0)
        return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->da);
}
int main()
{
    root = 0;
    root = create();
    postorder(root);
    return 0;
}