void create() {
    int value;

    while(1) {
        printf("Input a value, Enter -1 to exit\n");
        scanf("%d", &value);

        if (value == -1) {
            break;
        }

        insert_at_last(value);
    }
}

void insert_at_first(int value) {
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = value;
	temp->prev = NULL;
	temp->next = front;

	if(front == NULL) {
		end = temp;
	} else {
		front->prev = temp;
	}

	front = temp;
}

void insert_at_last(int value) {
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = value;
	temp->prev = end;
	temp->next = NULL;

	if(end == NULL) {
		front = temp;
	} else {
		end->next = temp;
	}

	end = temp;
}

void insert_at_position(int position, int value) {
	node *temp_node = front;
	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = value;

	for (int i = 0; i < (position - 1); i++) {
		temp_node = temp_node->next;
	}

	if (temp_node == NULL) {
		printf("\nThis position is too far\n");
		return;
	}


	new_node->next = temp_node->next;
	new_node->prev = temp_node;
	temp_node->next = new_node;
}

void search(int value) {
    node *temp_node = front;
    int flag = 0;

    while (temp_node != NULL) {
        if (temp_node->data == value) {
            printf("%d is present in this list. Memory address is %p\n", value, temp_node);
            flag = 1;
            break;
        } else {
            temp_node = temp_node->next;
        }
    }

    if (flag == 0) {
        printf("Item not found\n");
    }
}

void delete_node(int value) {
	node *temp_node = front;
	int flag = 0;

    while (temp_node != NULL) {
        if (temp_node->data == value) {
            if (temp_node->prev == NULL) {
                front = temp_node->next;
                front->prev = NULL;
            } else if (temp_node->next == NULL) {
            	end = temp_node->prev;
            	end->next = NULL;
            } else {
            	temp_node->prev->next = temp_node->next;
            	temp_node->next->prev = temp_node->prev;
            }

            free(temp_node);
            printf("%d is deleted from list\n", value);
            flag = 1;
            break;
        }

        temp_node = temp_node->next;
    }

    if (flag == 0) {
        printf("%d is not in the list!\n", value);
    }
}

void forward_traverse() {
	node *temp = front;

	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("\n");
}

void backward_traverse() {
	node *temp = end;

	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}

	printf("\n");
}
