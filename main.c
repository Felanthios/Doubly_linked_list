int main() {

    int x, position, value;
    while (1) {
                printf("*************************\n");
                printf("\n1: Insert at first\n2: Insert at last\n3: Insert at position \n4: Search\n5: Delete\n6: Forward Traverse\n7: Backward Traverse\n8: Exit\n");
                scanf("%d", &x);

                switch (x) {
                case 1:
                        printf("Oruulax utga: ");
                        scanf("%d", &value);
                        insert_at_first(value);
                        break;
                case 2:
                        printf("Oruulax utga: ");
                        scanf("%d", &value);
                        insert_at_last(value);
                        break;
                case 3:
                        printf("Oruulax bairlal: ");
                        scanf("%d", &position);
                        printf("Oruulax utga: ");
                        scanf("%d", &value);
                        insert_at_position(position, value);
                        break;
                case 4:
                        printf("Haih utga: ");
                        scanf("%d", &value);
                        search(value);
                        break;
                case 5:
                        printf("Ustgax utga: ");
                        scanf("%d", &value);
                        delete_node(value);
                        break;
                case 6:
                        forward_traverse();
                        break;
                case 7:
                        backward_traverse();
                        break;
                case 8:
                        exit(0);
                default:
                        break;
                }
        }
        return 0;
}
