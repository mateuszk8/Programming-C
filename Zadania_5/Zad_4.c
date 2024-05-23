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

int remove_by_index(Node** head_ref, int index) {
    if (*head_ref == NULL) {
        printf("Lista jest pusta\n");
        return -1;
    }
    Node* temp = *head_ref;
    if (index == 0) {
        *head_ref = temp->next;
        int data = temp->data;
        free(temp);
        return data;
    }
    for (int i = 0; temp != NULL && i < index-1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        return -1;
    }
    Node* next = temp->next->next;
    int data = temp->next->data;
    free(temp->next);
    temp->next = next;

    return data;
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
    add_first(&head, 4);
    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);
    printf("Lista przed usunięciem elementu:\n");
    print_list(head);
    int removed_data = remove_by_index(&head, 2);
    if (removed_data != -1) {
        printf("Usunięty element: %d\n", removed_data);
    }
    printf("Lista po usunięciu elementu:\n");
    print_list(head);

    return 0;
}
