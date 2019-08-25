/*
There two valid pairs in numbers = [1, 1, 2, 2, 3, 3] 
for k = 1, a + 1 = b:
(1, 2)(2, 3)
*/

/*
 * Complete the 'countPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY numbers
 *  2. INTEGER k
 */
int cmp(const void* a,const void* b)
 {
     return *(int*)a - *(int*)b;
 }
int countPairs(int numbers_count, int* numbers, int k) 
{
qsort(numbers,numbers_count,sizeof(int),cmp);
int i,c=0;
for(i=0;i<numbers_count;i++)
{
    if(i!=0 && (numbers[i]==numbers[i-1]))
    {
        continue;
    }
    else
    {
        int a=numbers[i];
        int b=numbers[i]+k;
        int l=i,r=numbers_count-1,flag=0,mid;
        while(l<r)
        {
            mid=(l+r)/2;
            if(numbers[mid]==b)
            {
                flag=1;
                break;
            }
            else if(numbers[mid]<b)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        if(flag==1 || numbers[l]==b)
        {
            c++;
        }
    }
}
return c;
}
