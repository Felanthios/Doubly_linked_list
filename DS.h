#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST

struct linked_list {
	int data;
    struct linked_list *prev;
	struct linked_list *next;
};

typedef struct linked_list node;
node *front = NULL;
node *end = NULL;
void create();
void insert_at_first(int);
void insert_at_last(int);
void insert_at_position(int, int);
void delete_node(int);
void search(int);
void forward_traverse();
void backward_traverse();

#endif
