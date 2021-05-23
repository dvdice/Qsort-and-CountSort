#pragma once

// Заголовочный файл с объявлением структуры данных

#include <vector>
namespace itis {

  void quickSort(int arr[], int low, int high);
  void printArray(int arr[], int size);
  int getMax(int array[], int size);
  int partition(int arr[], int low, int high);
  void countSort(std::vector<int>& input);

}  // namespace itis