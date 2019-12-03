#ifndef __METRIC_H__
#define __METRIC_H__

#include <time.h>

typedef struct metric_t {
  long int moves;
  long int comparisons;
  clock_t time;
} Metric;

void metricInit(Metric *metric);
int metricGetMoves(Metric *metric);
int metricGetComparisons(Metric *metric);
double metricGetSeconds(Metric metric);
void metricSetMoves(Metric *metric, long int moves);
void metricSetComparisons(Metric *metric, long int comparisons);
void metricFinish(Metric *metric);

#endif
