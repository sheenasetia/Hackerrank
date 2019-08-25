/*
Given values are n = 4, teamA = [1, 4, 2, 4], m = 2, and teamB = [3, 5].
For teamB[0] = 3, we have 2 elements in teamA (teamA[0] = 1 and teamA[2] = 2) that are <=teamB[0].
For teamB[1] = 5, we have 4 elements in teamA (teamA[0] = 1, teamA[1] = 4, teamA[2] = 2, and teamA[3] = 4) that are<= teamB[1].
Thus, the function returns the array [2, 4] as the answer.
*/

/*
 * Complete the 'counts' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY teamA
 *  2. INTEGER_ARRAY teamB
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
 int upper(int *arr,int n,int x)
 {
     int l=0;
     int r=n-1,mid;
     if(x>arr[r])
     return n;
     else if(x<arr[0])
     return 0;
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
     return r;
 }
 int cmp(const void* a,const void* b)
 {
     return *(int*)a - *(int*)b;
 }
int* counts(int teamA_count, int* teamA, int teamB_count, int* teamB, int* result_count) {
    int *res=(int*)malloc(teamB_count*sizeof(int));
    *result_count=teamB_count;
    qsort(teamA,teamA_count,sizeof(int),cmp);
    int i;
    for(i=0;i<teamB_count;i++)
    {
        res[i]=upper(teamA,teamA_count,teamB[i]);
    }
    return res;
}
