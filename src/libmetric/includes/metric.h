#ifndef __METRIC_H__
#define __METRIC_H__

typedef struct metric_t {
  int moves;
  int comparisons;
} Metric;

void metricInit(Metric *metric);
int metricGetMoves(Metric *metric);
int metricGetComparisons(Metric *metric);
void metricSetMoves(Metric *metric, int moves);
void metricSetComparisons(Metric *metric, int comparisons);

#endif