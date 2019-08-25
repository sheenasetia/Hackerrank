#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars
*/

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

int getMaxArea(int* hist, int n)
{
    st* s=NULL;
    int res,i,max=INT_MIN;
    for(i=0;i<n;i++)
    {
        if(empty(s) || hist[i]>=hist[peek(s)])
        {
            push(&s,i);
        }
        else
        {
            while(!empty(s) && hist[i]<=hist[peek(s)])
            {
                int a=pop(&s);
                if(empty(s))
                {
                    res=hist[a]*i;
                }
                else
                {
                    res=hist[a]*(i-peek(s)-1);
                }
                if(res>=max)
                {
                    max=res;
                }
            }
            push(&s,i);
        }
    }
    while(!empty(s))
    {
        int a=pop(&s);
        if(empty(s))
        {
            res=hist[a]*n;
        }
        else
        {
            res=hist[a]*(n-peek(s)-1);
        }

        if(res>=max)
        {
            max=res;
        }
    }
    return max;
    //complete this function
    
}


int main() {
   
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        
    }
    
    int r = getMaxArea(arr, n);
    printf("%d", r);
    return 0;
}

