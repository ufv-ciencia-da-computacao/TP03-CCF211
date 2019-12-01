#include "./includes/metric.h"

void metricInit(Metric *metric) {
  metric->comparisons = 0;
  metric->moves = 0;
  metric->time = clock();
}

int metricGetMoves(Metric *metric) {
  return metric->moves;
}

int metricGetComparisons(Metric *metric) {
  return metric->comparisons;
}

double metricGetSeconds(Metric metric) {
  return (double) metric.time / (double) CLOCKS_PER_SEC;
}

void metricAddOneMove(Metric *metric) {
  metric->moves++;
}

void metricAddOneComparison(Metric *metric) {
  metric->comparisons++;
}

void metricSetMoves(Metric *metric, int moves) {
  metric->moves = moves;
}

void metricSetComparisons(Metric *metric, int comparisons) {
  metric->comparisons = comparisons;
}

void metricFinish(Metric *metric) {
  metric->time = clock() - metric->time;
}
