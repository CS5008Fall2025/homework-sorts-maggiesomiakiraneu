/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
   
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    
    return result;
}

//link to the problem: https://leetcode.com/problems/two-sum/

// This was one of the questions I encountered in my first tech interview a few years ago. At the time, I was using Python rather than C. Regardless of the language, I was self-taught and had no formal background in algorithms. My solution had a time complexity of $O(n^2)$, which worked fine because the array size was small.

// However, when the interviewer asked why my solution was $O(n^2)$, I didn’t really understand the question. Now I can explain it clearly that the input size is small, the slower algorithm is still be fast enough, making the extra complexity of a faster algorithm unnecessary.