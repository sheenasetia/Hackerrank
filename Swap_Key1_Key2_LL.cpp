#include<iostream>
using namespace std;
/*
SAMPLE INPUT 
Nodes= 5 
78 
22
43
48
98 
key1=78
key2=98 
SAMPLE OUTPUT
78 22 43 48 98
98 22 43 48 78
*/
struct node
{
int info;
node *link;
};
int main()
{
int i,k,key1,key2,item;
struct node *start;
start=NULL;
scanf("%d",&k);
for(i=0;i<k;i++)
{
    scanf("%d",&item);
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->info=item;
    new_node->link=NULL;
    if(start==NULL)
    {
        start=new_node;
    }
    else
    {
        new_node->link=start;
        start=new_node;
    }
}
scanf("%d %d ",&key1,&key2);
struct node* temp=start;
while(temp)
{
    printf("%d ",temp->info);
    temp=temp->link;
}
struct node* curr1=start,*p1=NULL,*n1=start->link,*curr2=start,*p2=NULL,*n2=start->link;
temp=start;
struct node* demo=(struct node*)malloc(sizeof(struct node));
demo->link=start;
p1=demo;
p2=demo;
while(temp->link)
{
    if(temp->link->info==key1)
    {
        p1=temp;
        curr1=temp->link;
        n1=curr1->link;
    }
    else if(temp->link->info == key2)
    {
        p2=temp;
        curr2=temp->link;
        n2=curr2->link;
    }
    temp=temp->link;
}

temp=start;
while(temp)
{
    if(temp->info==key1 || temp->info==key2)
    {
        p1->link=curr2;
        curr2->link=n1;

        p2->link=curr1;
        curr1->link=n2;
        break;
    }
    temp=temp->link;
}
start=demo->link;
temp=start;
printf("\n");
while(temp)
{
    printf("%d ",temp->info);
    temp=temp->link;
}


return 0;
}