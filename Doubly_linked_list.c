#include <stdio.h>
#include <stdlib.h>

#include "DS.h"

void InsertHead(NodePointer *head_pointer, void *data) {
    NodePointer new_node = (NodePointer) malloc(sizeof(struct Node));
    new_node -> data = data;
    if (*head_pointer == NULL) {
        new_node -> prev = NULL;
        new_node -> next = NULL;
        return;  
    }
    
    (*head_pointer) -> prev = new_node;
    new_node -> next = *head_pointer;
    new_node -> prev = NULL;
    *head_pointer = new_node;
}

void InsertTail(NodePointer *head_pointer, void *data) {
    
    NodePointer new_node = (NodePointer) malloc(sizeof(struct Node));
    new_node -> data = data;
    new_node -> next = NULL;
    NodePointer cur_node = *head_pointer;
    
    if (*head_pointer == NULL) {
        new_node -> prev = NULL;
        *head_pointer = new_node;
        return;
    }
    
    while (cur_node -> next != NULL)
        cur_node = cur_node -> next;
    
    cur_node -> next = new_node;
    new_node -> prev = cur_node;
}

void Print(NodePointer *head_pointer) {
    if (*head_pointer == NULL)
        return;
    NodePointer cur_node = *head_pointer;
    printf("%d", *(int*)(cur_node -> data));
    while (cur_node -> next != NULL) {
        cur_node = cur_node -> next;
        printf("%d", *(int*)(cur_node -> data));
    }
}

NodePointer SearchNode(NodePointer *head_pointer, void *data) {
    NodePointer cur_node = *head_pointer;
    while (cur_node != NULL && cur_node -> data != data) {
        cur_node = cur_node -> next;
    }
    return cur_node;
}

void DeleteNodeByData(NodePointer *head_pointer, void *data) {
    NodePointer node = SearchNode(head_pointer, data);
    if (node == NULL)
        return;
    if (*head_pointer == node) {
        *head_pointer = node -> next;
    }
    if (node -> next != NULL) {
        node -> next -> prev = node -> prev;
    }
    if (node -> prev != NULL) {
        node -> prev -> next = node -> next;
    }
    free(node);
}
