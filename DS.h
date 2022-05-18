#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST

typedef struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
} *NodePointer;

void InsertHead(NodePointer *head_pointer, void *data);
void InsertTail(NodePointer *head_pointer, void *data);
void print(NodePointer *head_pointer);
NodePointer SearchNode(NodePointer *head_pointer, void *data);
void DeleteNodeByData(NodePointer *head_pointer, void *data);

#endif
