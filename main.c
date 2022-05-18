#include <stdio.h>
#include <stdlib.h>

#include "DS.h"

int main(void) {
    NodePointer head = NULL;
    
    while (1) {
                printf("\n1: Insert Head, 2: Insert Tail, 3: Search 4: Delete, 5: Print, 6: Exit\n");
                scanf("%d", &x);

                switch (x) {
                case 1:
                        printf("Oruulax utga: ");
                        scanf("%d", &x);
                        InsertHead(&head, &x);
                        break;
                case 2:
                        printf("Oruulax utga: ");
                        scanf("%d", &x);
                        InsertTail(&head, &x);
                        break;
                case 3:
                        printf("Ustgax utga: ");
                        scanf("%d", &x);
                        NodePointer node = SearchNode(&head, &x);
                        printf("%d", *(int*)(node -> data));
                        break;
                case 4:
                        printf("Ustgax utga: ");
                        scanf("%d", &x);
                        DeleteNodeByData(&head, &x);
                        break;
                case 5:
                        Print(&head);
                        break;
                case 6:
                        exit(0);
                default:
                        break;
                }
        }
        return 0;
}
