#ifndef __METRIC_H__
#define __METRIC_H__

#include <time.h>

typedef struct metric_t {
  int moves;
  int comparisons;
  clock_t time;
} Metric;

void metricInit(Metric *metric);
int metricGetMoves(Metric *metric);
int metricGetComparisons(Metric *metric);
double metricGetSeconds(Metric metric);
void metricSetMoves(Metric *metric, int moves);
void metricSetComparisons(Metric *metric, int comparisons);
void metricFinish(Metric *metric);

#endif
