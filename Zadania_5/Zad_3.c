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

int remove_last(Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Lista jest pusta\n");
        return -1;
    }
    if ((*head_ref)->next == NULL) {
        int last_data = (*head_ref)->data;
        free(*head_ref);
        *head_ref = NULL;
        return last_data;
    }
    Node* current = *head_ref;
    while (current->next->next != NULL) {
        current = current->next;
    }
    int last_data = current->next->data;
    free(current->next);
    current->next = NULL;

    return last_data;
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
    printf("Lista przed usunięciem elementów:\n");
    print_list(head);
    int last_value = remove_last(&head);
    if (last_value != -1) {
        printf("Usunięty ostatni element: %d\n", last_value);
    }
    printf("Lista po usunięciu ostatniego elementu:\n");
    print_list(head);

    return 0;
}
