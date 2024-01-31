#include <iostream>
#include "linked_list.h"

using namespace std;

struct node * build_new_linked_list(int total_new_elements) {
    if (0 == total_new_elements) {
        return NULL;
    } else {
        struct node *root = new node;
        root->data = 1;  
        struct node *linked_list = root;

        for (int i = 1; i < total_new_elements; i++) {  
            linked_list->next = new node;
            linked_list = linked_list->next;
            linked_list->data = i + 1;  
        }
        linked_list->next = NULL;  

        return root;
    }
}

int get_linked_list_data_item_value(struct node *start, int node_number, int total_elements) {
    
    if (node_number > total_elements) {
        return -1;
    } else {
        struct node *linked_list = start;

        for (int i = 0; i < node_number - 1; i++) {
            linked_list = linked_list->next;
        }

        return linked_list->data;
    }
}

void print_linked_list(struct node *start, int total_elements) {
    struct node *linked_list = start;

    for (int i = 0; i < total_elements; i++) {
        cout << linked_list->data << endl;
        linked_list = linked_list->next;
    }
}

bool update_data_in_linked_list(struct node *start, int node_to_update, int update_val, int total_elements) {
    if (node_to_update > total_elements) {
        return false;
    } else {
        struct node *linked_list = start;

        for (int i = 1; i < node_to_update; i++) {
            linked_list = linked_list->next;
        }

        linked_list->data = update_val;
        return true;
    }
}

void delete_linked_list(struct node *start) {
    struct node *linked_list = start;
    struct node *next = NULL;

    while (linked_list != NULL) {
        next = linked_list->next; 
        delete linked_list;       
        linked_list = next;      
    }
}


