/*
    2   0   2   1   1   0
    l                   r
    0   0   2   1   1   2
    l               r   
    0   0   1   1   2   2
        l       r

*/

void sortColors(int* nums, int numsSize) {
    // init 3 pointers: i, left, right
    int left = 0, right = numsSize - 1;

    // iterate nums
    for (int i=0; i<numsSize; i++) {
        if (i > right)
            break;
        // 0?
            // swap i, left
            // increase left
        if (nums[i] == 0) {
            int tmp = nums[i];
            nums[i] = nums[left];
            nums[left] = tmp;
            left++;
        } 
        // 2?
            // swap i, right
            // decrease right 
        else if (nums[i] == 2) {
            int tmp = nums[i];
            nums[i] = nums[right];
            nums[right] = tmp;
            right--;
            i--;
        }
    }
}