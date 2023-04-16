// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  T arr[size];
  int first, last, count;

 public:
  TPQueue(): first(0), last(0), count(0) {}
  void push(const T & value) {
    if (count == size)
      throw std::string("FULL!");
    int mesto = last;
    //находим нужную позицию
    for (int i = first; i < last; i++)
      if (arr[i].prior < value.prior) {
        mesto = i;
        break;
      }
    //сдвигаем
    for (int i = last; i> mesto; i--)
      arr[i % size] = arr[(i - 1) % size];
    //вставляем value
    arr[mesto % size] = value;
    ++last;
  }
  T& pop() {
    if (count == 0) {
      throw std::string("EMPTY!");
    } else {
      count--;
      return arr[first++ % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
