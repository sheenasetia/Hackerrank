/*
Given a list of integers, remove any nodes that have values that have previously occurred in the list and return a reference to the head of the list
*/

/*
 * Complete the 'condense' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST head as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* condense(SinglyLinkedListNode* head) {
SinglyLinkedListNode* temp1=head,*temp2;
while(temp1)
{
    if(!temp1->next)
    {
        break;
    }
    temp2=temp1;
    while(temp2->next)
    {
        if(temp2->next->data==temp1->data)
        {
            SinglyLinkedListNode* temp=temp2->next;
            temp2->next=temp2->next->next;
            free(temp);
            temp=NULL;
        }
        else
        {
            temp2=temp2->next;
        }
    }
    temp1=temp1->next;
}
return head;
}