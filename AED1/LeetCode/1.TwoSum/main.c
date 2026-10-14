#include <stdio.h>
#include <stdlib.h>

int *main() {
  // INPUTS
  // 1 -> [2,7,11,15] ; target = 9 ; Output [0,1]
  // 2 -> [3, 2, 4] ; target = 6 ; Output [1,2]
  // 3 -> [3, 3] ; target = 6; Output [0,1]

  int nums[2] = {3, 3};
  int target = 6;
  int numsSize = sizeof(nums) / sizeof(nums[0]);

  int *response = (int *)malloc(sizeof(int) * 2);
  // *returnSize = 2;

  for (int arrayCounter = 0; arrayCounter < numsSize; arrayCounter++) {
    for (int sumCounter = 0; sumCounter < numsSize; sumCounter++) {
      if (arrayCounter != sumCounter) {
        if (nums[arrayCounter] + nums[sumCounter] == target) {
          response[0] = arrayCounter;
          response[1] = sumCounter;

          printf("%d %d \n\n", response[0], response[1]);
          return response;
        }
      }
    }
  }

  free(response);
}