#include "MeticRegister.h"
#include <iostream>

using namespace std;

void test() {
  for (int i = 0; i < 10; i++) {
    // генерируем данные для теста
    int resp_t = i + 1;
    int wait_t = i + 2;

    MetricRegister::instance().add_metr(resp_t, wait_t);

    // вызываем тестируемый методд
    int result = MetricRegister::instance().count_cometr(i);

    // проверяем результат
    if (result == resp_t + wait_t) {
      cout << "Test passed for key " << i << endl;
    } else {
      cout << "Test failed for key " << i << ". Expected "
                << (resp_t + wait_t) << ", got " << result << endl;
    }
  }
}

int main() {
  // Тесты
  test();

  MetricRegister::instance().add_metr(5, 3);
  MetricRegister::instance().add_metr(7, 2);
  MetricRegister::instance().add_metr(9, 1);

  MetricRegister::instance().show_mert();

  cout << "Counted metric for key 1: "
            << MetricRegister::instance().count_cometr(1) << endl;

  return 0;
}
