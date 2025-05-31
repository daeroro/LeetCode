/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** ret;
int cnt;

static int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

/*
    -2 -1 0 0 1 2   // 0
    i   j l     r   // -1: move l
    i   j     l r   // 0: save -2 -1 1 2
    i     j l   r   // 0: save -2 0 0 2
    i     j   l r   // 1: move r
    i       j l r   // 1: move r
        i j l   r   // 1: move r
        i j l r     // 0: save -1 0 0 1
          i j l r   // 3: 
*/

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    // sort nums in non-decreasing order
    qsort(nums, numsSize, sizeof(int), cmp);

    ret = (int**)malloc(sizeof(int*) * numsSize * numsSize * numsSize);
    cnt = 0;

    // pick 2 indices
    // iterate nums: i from 0 to numsSize -4
    for (int i=0; i<numsSize-3; i++) {
        // iterate nums: j starts from i+1 to numsSize-3
        for (int j=i+1; j<numsSize-2; j++) {
            // set left, right index
            int left = j + 1, right = numsSize-1;
            // while left < right
            while (left < right) {
                long long int sums = (long long int)nums[left] + nums[right];
                long long int tmp = (long long int)target - nums[i] - nums[j];
                // sums == target - nums[i] - nums[j]
                    // save quadruplets
                    // increase left to non-equal value
                if (sums == tmp) {
                    ret[cnt] = (int*)malloc(sizeof(int) * 4);
                    ret[cnt][0] = nums[i];
                    ret[cnt][1] = nums[j];
                    ret[cnt][2] = nums[left];
                    ret[cnt][3] = nums[right];
                    cnt++;

                    while (((left + 1) < right) && (nums[left] == nums[left + 1]))
                        left++;
                    left++;                    

                }
                // sums > target - nums[i] - nums[j]
                    // decrease right to non-equal value
                else if (sums > tmp) {
                    while (((right - 1) > left) && (nums[right] == nums[right - 1]))
                        right--;
                    right--;
                }
                // sums < target - nums[i] - nums[j]
                    // increase left to non-equal-value
                else {
                    while (((left + 1) < right) && (nums[left] == nums[left + 1]))
                        left++;
                    left++;
                }
            }

            while (((j + 1) < (numsSize - 2)) && (nums[j] == nums[j + 1]))
                j++;
        }

        while (((i + 1) < (numsSize - 3)) && (nums[i] == nums[i + 1]))
            i++;
    }

    *returnSize = cnt;
    *returnColumnSizes = (int*)malloc(sizeof(int) * cnt);
    for (int i=0; i<cnt; i++) {
        (*returnColumnSizes)[i] = 4;
    }

    // return int**
    return ret;
}