#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST

typedef struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
} *NodePtr;

void InsertHead(NodePtr *head_ptr, void *data);
void InsertTail(NodePtr *head_ptr, void *data);
void print(NodePtr *head_ptr);
NodePtr SearchNode(NodePtr *head_ptr, void *data);
void DeleteNodeByData(NodePtr *head_ptr, void *data);

#endif
