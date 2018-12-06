#include <stdio.h>

int** threeSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    if (numsSize == 0) {
        return NULL;
    }

    int minSum,maxSum,i,j,k,sum,s,e,m,flag;
    int **res = (int**)malloc(sizeof(int*)*1000000);

    minSum = maxSum = 0;
    for (i=1;i<numsSize;i++) {
        if (nums[i] < 0)
            minSum += nums[i];
        else
            maxSum += nums[i];
    }

    if (minSum > 0 || maxSum < 0) {
        return NULL;
    }

    for (i = 0; i< numsSize; i++) {
        for (j = 0; j < numsSize-i-1; j++) {
            if (nums[j] > nums[j+1]) {
                m = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = m;
            }
        }
    }

    for (i = 0;i <= numsSize-3; i++) {
        //去除重复
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        for (j = numsSize - 1; j >= i + 2; j--) {
            flag = 0;
            sum = nums[i] + nums[j];
            s = i+1;
            e = j-1;

            while (e >= s) {
                m = (s+e)/2;
                if (nums[m] == -sum) {
                    res[*returnSize] = (int *)malloc(sizeof(int)*3);
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[m];
                    *returnSize = *returnSize + 1;
                    flag = 1;
                    break;
                }

                if (nums[m] > -sum)
                    e = m-1;
                else
                    s = m+1;
            }
            if (flag) {
                //去除重复
                while (nums[j] == nums[j-1]) {
                    j--;
                }
                flag = 0;
            }
        }
    }

    return res;
}

int main()
{
    int a[] = {-1,0,1,2,-1,-4};
    int n,i;
    int **res;
    res = threeSum(a,6,&n);
    for (i=0;i<n;i++) {
        printf("%d %d %d\n", res[i][0],res[i][1],res[i][2]);
    }
    return 0;
}