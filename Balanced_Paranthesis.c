// Complete the braces function below.

// Please store the size of the string array to be returned in result_count pointer. For example,
// char a[2][6] = {"hello", "world"};
//
// *result_count = 2;
//
// return a;
//
typedef struct stack
{
char data;
struct stack* next;

}st;

void push(st** top, int data)
{
    st* new = (st*)malloc(sizeof(st));
    
    new->data = data;
    new->next = *top;
    *top = new;
    
}

char peek(st* top)
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
void pop(st** top)
{
        st* temp=*top;
        *top=(*top)->next;
        free(temp);
        temp=NULL;    
}

char** braces(int values_count, char** values, int* result_count) {
st* s=NULL;
*result_count=values_count;
char** res=(char** )malloc(values_count*sizeof(char*));
int i,j;
for(i=0;i<values_count;i++)
{
    *(res+i)=(char*)malloc(3*sizeof(char));
}
for(i=0;i<values_count;i++)
{
    s=NULL;
    for(j=0;j<strlen(values[i]);j++)
    {
        if(values[i][j]=='{' ||values[i][j]=='(' || values[i][j]=='[')
        {
            push(&s,values[i][j]);
        }
        else
        {
            if(empty(s))
            {
                push(&s,values[i][j]);
                break;
            }
            else
            {
                switch(values[i][j])
                {
                    case '}':
                    if(peek(s)=='{')
                    {
                        pop(&s);
                    }
                    else
                    {
                        break;
                    }
                    break;
                    case ')':
                    if(peek(s)=='(')
                    {
                        pop(&s);
                    }
                    else
                    {
                        break;
                    }
                    break;
                    case ']':
                    if(peek(s)=='[')
                    {
                        pop(&s);
                    }
                    else
                    {
                        break;
                    }
                    break;
                }
            }
        }
    }
    if(empty(s))
    res[i]="YES";
    else
    res[i]="NO";
    
}
return res;
}