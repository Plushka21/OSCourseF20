#include <stdio.h>
#include <stdlib.h>

// Each node has value and reference to the next element
struct Node{
    int value;
    struct Node *next;
};

// For each new node we put some value and next node is NULL by default
struct Node* new_node(int value){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    return node;
}

// To create a list we just need to create head of the list
struct Node* create_list(){
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->next = NULL;
    return head;
};

// Insertion node using its index
void insert_node(int value, int index, struct Node* head){
    // Create new node
    struct Node *node = new_node(value);
    // Move to the parent node for new node
    int i = -1;
    while (head->next != NULL && i < index - 1){
        head = head->next;
        i++;
    }
    // Remake references
    node->next=head->next;
    head->next = node;
}

// Deleting node using its index
void delete_node(int index, struct Node* head){
    // Move to the parent node for required node
    int i = -1;
    while (head->next != NULL && i < index - 1){
        head = head->next;
        i++;
    }
    // Remake reference
    struct Node *node = head->next;
    head->next = node->next;
    // Free memory
    free(node);
};

// Printing list
void print_list(struct Node *head){
    // Go through the list and print each value
    head = head->next;
    while (head != NULL){
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct Node *list = create_list();

    printf("Insert 1 in list: \n");
    insert_node(1,0, list);
    print_list(list);

    printf("Insert 3 in list: \n");
    insert_node(3,1, list);
    print_list(list);

    printf("Insert 2 in list: \n");
    insert_node(2,1,list);
    print_list(list);

    printf("Insert 4 in list: \n");
    insert_node(4,3, list);
    print_list(list);

    printf("Delete 1 from list: \n");
    delete_node(0,list);
    print_list(list);

    printf("Delete 3 from list: \n");
    delete_node(1,list);
    print_list(list);

    printf("Delete 4 from list: \n");
    delete_node(1,list);
    print_list(list);

    printf("Delete 2 from list: \n");
    delete_node(0,list);
    print_list(list);

    printf("The list is empty \n");
}
