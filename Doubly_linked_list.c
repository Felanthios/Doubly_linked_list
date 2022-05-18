#include <stdio.h>
#include <stdlib.h>

#include "DS.h"

void InsertHead(NodePtr *head_ptr, void *data) {
    NodePtr new_node = (NodePtr) malloc(sizeof(struct Node));
    new_node -> data = data;
    if (*head_ptr == NULL) {
        new_node -> prev = NULL;
        new_node -> next = NULL;
        return;  
    }
    
    (*head_ptr) -> prev = new_node;
    new_node -> next = *head_ptr;
    new_node -> prev = NULL;
    *head_ptr = new_node;
}

void InsertTail(NodePtr *head_ptr, void *data) {
    
    NodePtr new_node = (NodePtr) malloc(sizeof(struct Node));
    new_node -> data = data;
    new_node -> next = NULL;
    NodePtr cur_node = *head_ptr;
    
    if (*head_ptr == NULL) {
        new_node -> prev = NULL;
        *head_ptr = new_node;
        return;
    }
    
    while (cur_node -> next != NULL)
        cur_node = cur_node -> next;
    
    cur_node -> next = new_node;
    new_node -> prev = cur_node;
}

void Print(NodePtr *head_ptr) {
    if (*head_ptr == NULL) return;
    NodePtr cur_node = *head_ptr;
    printf("%d", *(int*)(cur_node -> data));
    while (cur_node -> next != NULL) {
        cur_node = cur_node -> next;
        printf("%d", *(int*)(cur_node -> data));
    }
}

NodePtr SearchNode(NodePtr *head_ptr, void *data) {
    NodePtr cur_node = *head_ptr;
    while (cur_node != NULL && cur_node -> data != data) {
        cur_node = cur_node -> next;
    }
    return cur_node;
}

void DeleteNodeByData(NodePtr *head_ptr, void *data) {
    NodePtr node = SearchNode(head_ptr, data);
    if (node == NULL) return;
    if (*head_ptr == node) {
        *head_ptr = node -> next;
    }
    if (node -> next != NULL) {
        node -> next -> prev = node -> prev;
    }
    if (node -> prev != NULL) {
        node -> prev -> next = node -> next;
    }
    free(node);
}
