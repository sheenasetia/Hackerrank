/*
Given scores = [1, 3, 5, 6, 8], lowerLimits = [2], and upperLimits = [6], 
perform the following q = 1 query:
Find all the scores in the inclusive range [2, 6]. 

There are three such candidates (i.e., scores 3, 5, and 6), so store 3 in index 0 of the return array.
The function then returns the array [3]
*/

/*
 * Complete the function below.
 * Please store the size of the int array to be returned in result_size pointer. For example,
 * int a[3] = {1, 2, 3};
 * *result_size = 3;
 * return a;
 * 
 */
int lowerBound(int arr[],int n,int x)
{
    int l=0,r=n-1,mid;
    if(x>arr[n-1])
    return -1;
    while(l<r)
    {
        mid=(l+r)/2;
        if(arr[mid]>=x)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
}
int upperBound(int arr[],int n,int x)
{
    int l=0,r=n-1,mid;
    if(x>=arr[n-1])
    return n;
    while(l<r)
    {
        mid=(l+r)/2;
        if(arr[mid]>x)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
}
int cmp(const void* a,const void* b)
{
    return *(int*)a - *(int*)b;
}
int* jobOffers(int scores_size, int* scores, int lowerLimits_size, int* lowerLimits, int upperLimits_size, int* upperLimits, int* result_size) {
int *res=(int*)malloc(lowerLimits_size*sizeof(int));
qsort(scores,scores_size,sizeof(int),cmp);
int i;
for(i=0;i<lowerLimits_size;i++)
{
    int x=lowerBound(scores,scores_size,lowerLimits[i]);
    printf("%d",x);
    int y=upperBound(scores,scores_size,upperLimits[i]);
    printf("%d",y);
    if(x==-1)
    res[i]=0;
    else
    res[i]=y-x;    
}
*result_size=lowerLimits_size;
return res;
}