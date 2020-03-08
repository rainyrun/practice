#include <stdio.h>

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int indices[2];
int* twoSum(int* nums, int numsSize, int target) {
	int i, j;
	for (i = 0; i < numsSize; i++)
		for (j = i + 1; j < numsSize; j++)
			if (nums[i] + nums[j] == target)
			{
				indices[0] = i;
				indices[1] = j;
				return indices;
			}
	return NULL;
}

int main(void)
{
	int nums[] = { 2, 7, 11, 15 };
	int target = 9;
	int *indices;
	indices = twoSum(nums, 4, 9);
	printf("indices is : %d, %d\n", indices[0], indices[1]);
}