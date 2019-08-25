/*
Given a singly-linked list and a maximum value, remove any values from the list that are greater than the given maximum while maintaining list order
*/


/*
 * Complete the 'removeNodes' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST listHead
 *  2. INTEGER x
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

SinglyLinkedListNode* removeNodes(SinglyLinkedListNode* listHead, int x) {
    SinglyLinkedListNode* temp=listHead,*remove=NULL;
    while(temp && temp->data>x)
    {
        remove=temp;
        temp=temp->next;
        free(remove);
        remove=NULL;
    }
    listHead=temp;
    if(!temp)
    return listHead;
    while(temp->next)
    {
        if(temp->next->data>x)
        {
            remove=temp->next;
            temp->next=temp->next->next;
            free(remove);
            remove=NULL;
        }
        else
        {
            temp=temp->next;
        }      
    }
    return listHead;
}