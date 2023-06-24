#include "MeticRegister.h"
#include <iostream>

using namespace std;

MetricRegister &MetricRegister::instance() {
  static MetricRegister instance;
  return instance;
}

bool MetricRegister::add_metr(int resp_t, int wait_t) {
  metrics[nextKey++] = make_pair(resp_t, wait_t);
  return true;
}

bool MetricRegister::show_mert() {
  if (metrics.empty())
    return false;

  for (auto &metric : metrics) {
    cout << "Key: " << metric.first
              << " Response Time: " << metric.second.first
              << " Waiting Time: " << metric.second.second << endl;
  }

  return true;
}

int MetricRegister::count_cometr(int key) {
  if (metrics.find(key) == metrics.end())
    return -1;

  return metrics[key].first + metrics[key].second;
}

MetricRegister::MetricRegister() : nextKey(0) {}
