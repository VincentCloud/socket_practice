#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
typedef struct node {
    int val;
    struct node *next;
} node_t;

void add_node (node_t *node, int val) {
    node_t *current = node;
    while(current->next != NULL) {
        current = current->next;
    }
    current ->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;

}

void find_and_remove(node_t *pid, node_t *rval, int val) {
    /*
     * We know that pids are unique, we only remove the corresponding values of pid according to rval
     */

    node_t *curr1 = pid;
    node_t *curr2 = rval;

    while (curr2 != NULL && curr2->next != NULL) {
        if (curr2->next->val == val) {
            node_t * temp = curr2->next;
            node_t * temp2 = curr1->next;
            curr2->next = curr2->next->next;
            curr1->next = curr1->next->next;
            free(temp);
            free(temp2);
        } else {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
}

node_t* tail(node_t *node) {
    node_t * curr = node;
    while(curr->next !=NULL) {
        curr = curr -> next;
    }
    return curr;
}

int main() {
    node_t pid = {0, NULL};
    node_t rval = {0, NULL};
    add_node(&pid, 12314);
    add_node(&pid, 12315);
    add_node(&pid, 12324);
    node_t *t = tail(&pid);
    printf("t %d\n", t->val);


    add_node(&rval, 0);
    add_node(&rval, 3);
    add_node(&rval, 2);

    find_and_remove(&pid, &rval, 3);
    node_t *node1 = &pid;
    while (node1 != NULL) {
        printf("%d ",node1->val);
        node1 = node1->next;
    }

    node_t *node2 = &rval;
    while (node2 != NULL) {
        printf("%d ",node2->val);
        node2 = node2->next;
    }
}
