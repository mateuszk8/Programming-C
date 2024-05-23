#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void add_first(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Brak wystarczającej pamięci\n");
        exit(1);
    }
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int pop(Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Lista jest pusta\n");
        return -1;
    }

    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    int popped_data = temp->data;
    free(temp);
    return popped_data;
}

void print_list(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);
    printf("Lista przed usunięciem elementu:\n");
    print_list(head);
    int popped_value = pop(&head);
    if (popped_value != -1) {
        printf("Usunięty element: %d\n", popped_value);
    }
    printf("Lista po usunięciu elementu:\n");
    print_list(head);
    
    return 0;
}
