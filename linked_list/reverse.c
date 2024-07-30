#include<stdio.h>
#include<stdlib.h>

// the node structure
struct ListNode{
	int val;
	struct ListNode *next; 
};

// creating up new nodes function
struct ListNode *node(int var){
	struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
	n->val = var;
	n->next = NULL;
	return n;
}

// To reverse a linked list
struct ListNode *reverse_node(struct ListNode *l){
	struct ListNode* prev = NULL;
    struct ListNode* current = l;
    struct ListNode* next = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

// usage:
int main(){
    
	struct ListNode *l = node(2);
    printf("Given Node 1: %d \n",l->val);
    l->next = node(4);
    printf("Given Node 2: %d \n",l->next->val);
    l->next->next = node(3);
    printf("Given Node 3: %d \n",l->next->next->val);

    struct ListNode *p = reverse_node(l);
    while(p != NULL){
        printf("Reversed Node : %d \n", p->val);
        p = p->next;
    }
}