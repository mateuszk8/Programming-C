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
    print_list(head);
    return 0;
}
