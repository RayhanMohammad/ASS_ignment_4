#include <stdio.h>
#include <string.h>
#include <stdlib.h>







typedef struct tree_node_struct
{
    char treeName[32];
    struct tree_node_struct *parent, *left, *right;
    struct item_node_struct *theTree;
}tree_node;

typedef struct item_node_struct
{
    char name[32];
    int count;
    struct item_node_struct *parentItem, *left, *right;
    struct tree_node_struct *parentTree;
}item_node;

tree_node *createTreeNode(char *name)
{
    tree_node *temp = malloc(sizeof(tree_node));
    strcpy(temp->treeName, name);
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    temp->theTree = NULL;
}



void addChildTopRoot(tree_node *tree, tree_node *leaf)
{
    if(tree->left != NULL && tree->right != NULL)
    {
        addChildTopRoot(tree->left, leaf);
    }
    else if (tree->right == NULL)
    {
        tree->right = leaf;
        return;
    }
    else
    {
        tree->left = leaf;
        return;
    }
}

item_node *createItemTopNode(char *name, int count, tree_node *dada)
{
    item_node *temp = malloc(sizeof(item_node));
    strcpy(temp->name, name);
    temp->count = count;
    temp->parentTree = dada;
    temp->parentItem = NULL;
    temp->left = NULL;
    temp->right = NULL;
}

item_node *createItemNode(char *name, int count, item_node *papa)
{
    item_node *temp = malloc(sizeof(item_node));
    strcpy(temp->name, name);
    temp->count = count;
    temp->parentItem = papa;
    temp->left = NULL;
    temp->right = NULL;
}

void addItemChildToTreeParent(tree_node *tree, item_node *child)
{
    tree->theTree  = child;
}
void addItemChildToItemParent(item_node *parent, item_node *child)
{
    child->parentItem = parent;
    if(parent->left != NULL)
    {
         2
    }

}




int main() {
    printf("Hello, World!\n");
    return 0;
}
