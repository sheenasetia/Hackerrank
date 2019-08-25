#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct stack
{
int data;
struct stack* next;

}st;

void push(st** top, int data)
{
    st* new = (st*)malloc(sizeof(st));
    
    new->data = data;
    new->next = *top;
    *top = new;
    
}

int peek(st* top)
{
    return top->data;
}

int empty(st* top)
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}
int pop(st** top)
{
    
    int num;
        st* temp=*top;
        num=temp->data;
        *top=(*top)->next;
        free(temp);
        temp=NULL;    
        return num;
}

int main() {
    int n;
    scanf("%d",&n);
    int i;   
    while(n!=0)
    {
    int arr[n],x;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        st* s=NULL;
        int res[n],k=0;
        for(i=0;i<n;i++)
        {
            if(empty(s) || arr[i]<peek(s))
            {
                push(&s,arr[i]);
            }
            else
            {
                while(!empty(s) && arr[i]>peek(s))
                {
                    res[k]=pop(&s);
                    k++;
                }
                push(&s,arr[i]);
            }
        }
        while(!empty(s))
        {
            res[k]=pop(&s);
            k++;
        }
        int curr=res[0],flag=1;
        for(i=1;i<k;i++)
        {
            if(res[i]!=(curr+1))
            {
                flag=0;
                break;
            }
            curr++;

        }
        if(flag==1)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
        scanf("%d",&n);
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}