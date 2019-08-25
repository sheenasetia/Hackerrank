/*
n = 7, arr = [2, 3, 10, 2, 4, 8, 1]
Differences are calculated as:
3 - [2] = [1]
10 - [3, 2] = [7, 8]
4 - [2, 3, 2] = [2, 1, 2]
8 - [4, 2, 3, 2] = [4, 6, 5, 6]
The maximum is found at 10 - 2 = 8
*/

/*
 * Complete the 'maxDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int maxDifference(int arr_count, int* arr) {
    int max=-9999999,min=arr[0],m=arr[0];
    for(int i=1;i<arr_count;i++)
    {
        if(arr[i]>min)
        if(arr[i]-min>max)
        {
            max=arr[i]-min;
            m=arr[i];
        }
        min=arr[i]<min?arr[i]:min;
    }
    if(m==arr[0])
    return -1;
return max;
}