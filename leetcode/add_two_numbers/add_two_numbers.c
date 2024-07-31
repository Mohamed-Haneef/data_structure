#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode{
	int val;
	struct ListNode *next; 
};

struct ListNode *node(int var){
	struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
	n->val = var;
	n->next = NULL;
	printf("size of listnode : %ld \n", sizeof(struct ListNode));
	return n;
}

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
	printf("Got reverse node");
	return prev;
}

// struct ListNode* add_two_nodes(struct ListNode* l1, struct ListNode* l2) {
//     struct ListNode* current = NULL;
//     struct ListNode* sum = NULL;
//     char node1[128] = {0}; 
//     char node2[128] = {0};

//     printf("I am here\n");
    
//     l1 = reverse_node(l1);
//     l2 = reverse_node(l2);
    
//     printf("After reversing\n");
    
//     while (l1 != NULL) {
//         char temp1[8];
//         sprintf(temp1, "%d", l1->val);
//         strcat(node1, temp1);
//         printf("node1 str: %s\n", node1);
//         l1 = l1->next;
//     }
    
//     while (l2 != NULL) {
//         char temp2[8];
//         sprintf(temp2, "%d", l2->val);
//         strcat(node2, temp2);  
//         printf("node2 str: %s\n", node2);
//         l2 = l2->next;
//     }
    
//     long long result = atoi(node1) + atoi(node2);

//     char str[128];
//     sprintf(str, "%lld", result);

//     for (int i = 0; str[i] != '\0'; i++) {
//         int digit = str[i] - '0';  
//         struct ListNode* newNode = node(digit);
//         if (sum == NULL) {
//             sum = newNode;
//             current = sum;
//         } else {
//             current->next = newNode;
//             current = current->next;
//         }
//         printf("The final node: %d\n", newNode->val);
//     }

//     return reverse_node(sum); 
// }

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = node(0);
    struct ListNode* current = dummy;
    int remainder = 0;

    while (l1 != NULL || l2 != NULL || remainder != 0) {
        int val1 = (l1 != NULL) ? l1->val : 0; 
        int val2 = (l2 != NULL) ? l2->val : 0; 
        int total = val1 + val2 + remainder;       
        remainder = total / 10;                

        struct ListNode* newNode = node(total % 10);
        current->next = newNode;               
        current = newNode;                  

        if (l1 != NULL) l1 = l1->next;        
        if (l2 != NULL) l2 = l2->next;         
    }


    struct ListNode* result = (dummy->next); 
    free(dummy);                        
    return result;
}

int main(){
	struct ListNode *l = node(2);
    printf("Node 1: %d \n",l->val);
    l->next = node(4);
    printf("Node 2: %d \n",l->next->val);
    l->next->next = node(3);
    printf("Node 3: %d \n",l->next->next->val);

	struct ListNode *p = node(4);
    printf("Node 1: %d \n",p->val);
    p->next = node(5);
    printf("Node 2: %d \n",p->next->val);
    p->next->next = node(6);
    printf("Node 3: %d \n",p->next->next->val);

	add_two_nodes(l, p);
}
