 /*
    1. sort nums in non-decreasing order -> O(nlogn)
    2. iterate nums: i  -> O(n^2)
    3. set two pointer: i+1, size -1
    4. find closet to target - nums[i]
        sums < target - nums[i] : increase left
        sums >= target - nums[i] : decrease right 
*/

#define ABS(a)  ((a > 0) ? (a) : (-(a)))

int cmp(const void*a, const void*b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    /* -4, -1, 1, 2 : target 1
        i   l     r : -4 -1 + 2 = -3    // delta 4
               l  r : -4 + 1 + 2 = -1   // delta 2
            i  l  r : -1 + 1 + 2 = 2    // delta 1

        1 2 3 4 5 : target 1
        i l     r : 1 + 2+ 5 = 8    // delta 7
        i l   r   : 1 + 2+ 4 = 7    // delta 6
        i l r      : 1 2 3 = 6      // delta 5
    */

    int left, right, delta = 100000, tSum;
    for (int i=0; i<numsSize-2; i++) {
        left = i + 1, right = numsSize-1;

        while (left < right) {
            tSum = nums[left] + nums[right] + nums[i];

            if (ABS(target - tSum) < ABS(delta)) {
                delta = target - tSum;
            }

            if (tSum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return target - delta;
}