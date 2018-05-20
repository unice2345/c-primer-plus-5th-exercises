#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"

typedef struct pair {
    Node * parent;
    Node * child;
} Pair;

static Pair SeekItem(const Item * pitem, const Tree * ptree);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static Node * MakeNode(const Item * pitem);
static void AddNode(Node * new_node, Node * root);
static void InOrder(const Node * node, void (*pfun)(Item item));
static void DeleteNode(Node ** ptr);
static void DeleteAllNodes(Node * root);

void InitializeTree(Tree * ptree) {
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree) {
    return ptree->size == 0;
}

bool TreeIsFull(const Tree * ptree) {
    return ptree->size == MAXITEMS;
}

int TreeItemCount(const Tree * ptree) {
    return ptree->size;
}

bool AddItem(const Item * pitem, Tree * ptree) {
    Node * new_node;
    
    if (TreeIsFull(ptree)) {
        fprintf(stderr, "Tree is full\n");
        return false;
    }
    
    Pair pair;
    pair = SeekItem(pitem, ptree);
    //if (SeekItem(pitem, ptree).child != NULL) {
    if (pair.child != NULL) {
        fprintf(stderr, "Attempted to add duplicate item\n");
        return false;
    }
    
    new_node = MakeNode(pitem);
    if (new_node == NULL) {
        fprintf(stderr, "Could not create new node\n");
        return false;
    }
    
    ptree->size++;
    if (ptree->root == NULL) {
        ptree->root = new_node;
    } else {
        AddNode(new_node, ptree->root);
        //pair.child = new_node; // 为什么这样写不行？？？child只是将Node取出，但是没有插入到树中？？？
//        if (ToLeft(pitem, &(pair.parent->item))) //OK
//            pair.parent->left = new_node;
//        else if (ToRight(pitem, &(pair.parent->item)))
//            pair.parent->right = new_node;

//        if (pair.parent->left == pair.child) // 有问题. 有可能parent的左右子节点都是NULL，不知道该往哪个节点添加
//            pair.parent->left = new_node;
//        else if (pair.parent->right == pair.child)
//            pair.parent->right = new_node;
    }
    return true;
}

static Pair SeekItem(const Item * pitem, const Tree * ptree) {
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    
    if (look.child == NULL)
        return look;
        
    while (look.child != NULL) {
        if(ToLeft(pitem, &(look.child->item))) {
            look.parent = look.child;
            look.child = look.child->left;
        } else if (ToRight(pitem, &(look.child->item))) {
            look.parent = look.child;
            look.child = look.child->right;
        } else 
            break; // item相等
    }
    
    return look;
}

static bool ToLeft(const Item * i1, const Item * i2) {
    int comp1;
    
    if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
        return true;
    else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0)
        return true;
    else 
        return false;
}

static bool ToRight(const Item * i1, const Item * i2) {
    int comp1;
    
    if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
        return true;
    else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0)
        return true;
    else 
        return false;
}

static Node * MakeNode(const Item * pitem) {
    Node * new_node;
    
    new_node = (Node *) malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node->item = *pitem;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static void AddNode(Node * new_node, Node * root) {
    if (ToLeft(&(new_node->item), &(root->item))) {
        if (root->left == NULL) {
            root->left = new_node;
        } else {
            AddNode(new_node, root->left);
        }
    } else if (ToRight(&(new_node->item), &(root->item))) {
        if (root->right == NULL) {
            root->right = new_node;
        } else {
            AddNode(new_node, root->right);
        }
    } else { // 不应该含有相同的项目
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
}



void Traverse(const Tree * ptree, void (*pfun)(Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

static void InOrder(const Node * node, void (*pfun)(Item item)) {
    if (node != NULL) {
        InOrder(node->left, pfun);
        pfun(node->item);
        InOrder(node->right, pfun);
    }
}

bool InTree(const Item * pitem, const Tree * ptree) {
    return (SeekItem(pitem, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item * pitem, Tree * ptree) {
    Pair look;
    look = SeekItem(pitem, ptree);
    if (look.child == NULL)
        return false;
        
    if (look.parent == NULL) 
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child) 
        DeleteNode(&(look.parent->left));
    else 
        DeleteNode(&(look.parent->right));
    ptree->size--;
    return true;
}

/**
 * @brief 删除节点
 * @param ptr 指向待删除节点的指针的指针，即*ptr是待删除节点的指针
 */
static void DeleteNode(Node ** ptr) {
    Node * temp;
    
    if ((*ptr)->left == NULL) {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    } else if ((*ptr)->right == NULL) {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    } else {
        // 找到右子树的依附位置
        for (temp = (*ptr)->right; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

void DeleteAll(Tree * ptree) {
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->size = 0;
    ptree->root = NULL;
}

static void DeleteAllNodes(Node * root) {
    Node * pright;
    if (root != NULL) {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}