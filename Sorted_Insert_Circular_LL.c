/*
insert every new value in a sorted Circular Linked List (CLL). 
For example, if the input CLL is following:
2->5->8->10
After inserting 7 circular linked list will be:
2->5->7->8->10
*/

#include<stdio.h>
#include<stdlib.h>

/* structure for a node */
struct node
{
  int data;
  struct node *next;
};

void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node* temp=*head_ref;
if(*head_ref==NULL)
{
    *head_ref=new_node;
    new_node->next=*head_ref;
}
else
{
     temp=*head_ref;
    if(temp->data >= new_node->data)
    {
        while(temp->next!=*head_ref)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=*head_ref;
        *head_ref = new_node;
    }
    else
    {
        int flag=0;
        while(temp->next != *head_ref)
        {
        if((temp->next->data) < (new_node->data))
        {
            temp=temp->next;
        }
        else
        {
            new_node->next=temp->next;
            temp->next=new_node;
            flag=1;
            break;
        }            
        }
        if(flag==0)
        {
            new_node->next=*head_ref;
            temp->next=new_node;
        }
    }       
}
    //complete the code
    
}

void printList(struct node *start)
{
  struct node *temp;

  if(start != NULL)
  {
    temp = start;
    
    do {
      printf("%d\n", temp->data);
      temp = temp->next;
    } while(temp != start);
  }
}

/* Driver program to test above functions */
int main()
{
  int arr; //= {12, 56, 2, 11, 1, 90};
  int list_size, i;

  /* start with empty linked list */
  struct node *start = NULL;
  struct node *temp;
    
  int n;
  scanf("%d",&n);

  /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
  for(i = 0; i< n; i++)
  {
    temp = (struct node *)malloc(sizeof(struct node));
    scanf("%d",&arr);
    temp->data = arr;
    sortedInsert(&start, temp);
  }

  printList(start);
  //getchar();
  return 0;
}