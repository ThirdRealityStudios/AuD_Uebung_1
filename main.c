#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct struct_Knoten Knoten;

Knoten *root = NULL;

struct struct_Knoten
{
    int key;

    Knoten *parent, *left, *right;
};

void treeinit()
{
    root = calloc(1, sizeof(Knoten));
}

void traverse(Knoten *node)
{
    printf("%d ", node -> key);

    if(node -> left != NULL)
        traverse(node -> left);

    if(node -> right != NULL)
        traverse(node -> right);
}

// level must be at least 1
void fullBinaryTreeInit(Knoten *node, int level, int maxLevel)
{
    if(maxLevel == 0) return;

    if(node == root)
    {
        level = 1;
    }

    Knoten *left = calloc(1, sizeof(Knoten));
    left -> key = level;
    node -> left = left;

    Knoten *right = calloc(1, sizeof(Knoten));
    right -> key = level;
    node -> right = right;

    if(level < maxLevel)
    {
        fullBinaryTreeInit(node -> left, level + 1, maxLevel);
        fullBinaryTreeInit(node -> right, level + 1, maxLevel);
    }
}

int main(void)
{
    treeinit();

    fullBinaryTreeInit(root, 1, 3);

    traverse(root);

    free(root);
    root = NULL;

    return EXIT_SUCCESS;
}