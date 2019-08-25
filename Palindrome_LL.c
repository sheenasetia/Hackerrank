#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
1->2->1 is a valid palindrome while 1->2->2 is not
*/

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode listnode;

listnode* listnode_new(int val) {
	listnode* node = (listnode *) malloc(sizeof(listnode));
	node->val = val;
	node->next = NULL;
	return node;
}

void addNode(listnode* A, int i){
	listnode* temp = listnode_new(i);
	listnode* t = A;
	while(t->next != NULL){
		t = t->next;
	}
	t->next = temp;
}

/*
 * Complete the function below.
 */
int isPalin(listnode* A){
listnode* head=NULL,*curr=A,*prev=NULL,*next,*temp1,*temp2;
while(curr)
{
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
}
head=prev;
temp1=A;
temp2=head;
while(temp1 && temp2)
{
    if(temp1->val!=temp2->val)
    break;
    temp1=temp1->next;
    temp2=temp2->next;
}
if(temp1 && temp2)
return 0;
else
return 1;
}
int main(){
	int count = 0;
	int i;
	int v;
	scanf("%d",&count);
	scanf("%d",&v);
	listnode* A = listnode_new(v);
	for(i=0;i<count-1;i++){
		scanf("%d",&v);
		addNode(A,v);
	}
	if(isPalin(A) == 1) printf("true");
	else printf("false");
}
