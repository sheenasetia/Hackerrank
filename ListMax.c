/*
a b k list
      [ 0, 0, 0, 0, 0]
1 2 10[ 10, 10, 0, 0, 0]
2 4 5 [ 10, 15, 5, 5, 0]
3 5 12[ 10, 15, 17, 17, 12]
*/

/*
 * Complete the 'listMax' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY operations
 */

long listMax(int n, int operations_rows, int operations_columns, int** operations) {
long max;
long *arr=(long*)malloc(n*sizeof(long));
int i,j;
for(i=0;i<n;i++)
{
    arr[i]=0;
}
for(i=0;i<operations_rows;i++)
{
   arr[operations[i][0]-1]=arr[operations[i][0]-1]+operations[i][2];
   arr[operations[i][1]]=arr[operations[i][1]]-(operations[i][2]);
}
max=arr[0];
for(i=1;i<n;i++)
{
    arr[i]=arr[i]+arr[i-1];
    if(arr[i]>max)
    max=arr[i];
}
return max;
}