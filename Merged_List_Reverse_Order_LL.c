#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/* 
Sample Input:
15 20 25 // List A
6 8 10 // List B

Sample Output:
25 20 15 10 8 6 // Merged List in reverse order
*/

struct node
{
    int data;
    struct node* next;
};
void insertNode(struct node** h,int x)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    if(*h==NULL)
    {
        *h=n;
    }
    else
    {
        struct node* temp=*h;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
}
int main() {
    int i,x;
    struct node* h1=NULL,*h2=NULL,*h3=NULL;
    for(i=0;i<3;i++)
    {
        scanf("%d",&x);
        insertNode(&h1,x);
    } 
    for(i=0;i<3;i++)
    {
        scanf("%d",&x);
        insertNode(&h2,x);
    }
    struct node* t1=h1,*t2=h2,*t3=h3;
    while(t1 && t2)
    {
        if(t1->data<t2->data)
        {
            if(h3==NULL)
            {
                h3=t1;
                t3=t1;
            }
            else
            {
                t3->next=t1;
                t3=t3->next;
            }
            t1=t1->next;
        }
        else 
        {
            if(h3==NULL)
            {
                h3=t2;
                t3=t2;
            }
            else
            {
                t3->next=t2;
                t3=t3->next;
            }         
            t2=t2->next;
        }
        
    }
    if(!t2)
    {
        while(t1)
        {
            t3->next=t1;
            t3=t3->next;
            t1=t1->next;
        }
    }
    else if(!t1)
    {
        while(t2)
        {
            t3->next=t2;
            t3=t3->next;
            t2=t2->next;
        }        
    }
    struct node* curr=h3,*prev=NULL,*next;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    h3=prev;
    struct node* temp=h3;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

