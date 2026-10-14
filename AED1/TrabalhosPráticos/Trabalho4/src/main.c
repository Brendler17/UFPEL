#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int difficulty;
  int profit;
} Job;

int orderJobs(const void *a, const void *b) { return ((Job *)a)->difficulty - ((Job *)b)->difficulty; }

int orderWorkers(const void *a, const void *b) { return (*(int *)a) - (*(int *)b); }

int maxProfitAssignment(int *difficulty, int difficultySize, int *profit, int profitSize, int *worker, int workerSize) {
  Job *jobs = (Job *)malloc(difficultySize * sizeof(Job));
  if (jobs == NULL) {
    printf("\nError allocating memory!\n");
    return -1;
  }

  for (int counter = 0; counter < difficultySize; counter++) {
    jobs[counter].difficulty = difficulty[counter];
    jobs[counter].profit = profit[counter];
  }

  qsort(jobs, difficultySize, sizeof(Job), orderJobs);
  qsort(worker, workerSize, sizeof(int), orderWorkers);

  int maxProfit = 0, higherProfit = 0;
  int i = 0;
  for (int counter = 0; counter < workerSize; counter++) {
    while (i < difficultySize && jobs[i].difficulty <= worker[counter]) {
      if (jobs[i].profit > higherProfit) {
        higherProfit = jobs[i].profit;
      }

      i++;
    }

    maxProfit += higherProfit;
  }

  free(jobs);
  return maxProfit;
}

int main() { return 0; }