#include <iostream>
#include <stdlib.h>
using namespace std;

struct treeNode
{
    int item;
    struct treeNode * left;
    struct treeNode * right;
};

struct treeNode * root;


void initializeTree()
{
    root = 0;
}
struct treeNode * makeTreeNode(int item)
{
    struct treeNode * node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};
struct treeNode * insertItem(struct treeNode * node, int item)
{
    if(node==0)
    {
        struct treeNode * newNode = makeTreeNode(item);
        root = newNode;
        return newNode;
    }

    if(node->item == item) return 0;

    if(item < node->item && node->left==0)
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->left = newNode;
        return newNode;
    }

    if(item > node->item && node->right==0)
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->right = newNode;
        return newNode;
    }

    if(item < node->item)
        return insertItem(node->left, item);
    else
        return insertItem(node->right, item); //insert at right sub-tree
}

void printInOrder(struct treeNode * node)
{
    if(node==0) return ;

    printInOrder(node->left);



    cout<<node->item<<" ";


    printInOrder(node->right);
}

int main()
{
    initializeTree();
    while(1)
    {
        cout<<"\n1. Insert item. 2. PrintInOrder."<<endl ;


        int ch;
        cin>>ch;
  int item;
  if(ch==1){
            cin>>item;
            insertItem(root, item);
  }
  else if(ch==2)
             printInOrder(root);
    }
    return 0;
}
