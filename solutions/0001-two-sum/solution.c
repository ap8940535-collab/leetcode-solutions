/**
 * Problem: 1. Two Sum
 * Difficulty: Easy
 * Category: Arrays & Hashing
 *
 * Time Complexity:  O(N^2) brute force / O(N log N) sorted
 * Space Complexity: O(1) auxiliary
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    if (!result) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    free(result);
    return NULL;
}

int main(void) {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize = 0;

    int* res = twoSum(nums, 4, target, &returnSize);
    if (res != NULL && returnSize == 2) {
        printf("Indices: [%d, %d]\n", res[0], res[1]);
        free(res);
    }
    return 0;
}
