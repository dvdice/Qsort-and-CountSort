namespace itis {

#include <iostream>

  using namespace std;

  void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
  }

  /*Функция берет за пивот последний элемент, ставит его в верную позицию в списке
 и перемещает все что меньше левее,
 а все что больше правее пивота.*/
  int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // пивот
    int i = (low - 1);  // индекс меншего элемента, указывающего на верную позицию пивота

    for (int j = low; j <= high - 1; j++) {
      if (arr[j] < pivot) {
        i++;
        swap(&arr[i], &arr[j]);
      }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
  }

  /* Реализация QuickSort
arr[] --> массив
low --> началный индекс
high --> конечный индекс */
  void quickSort(int arr[], int low, int high) {
    if (low < high) {
      /* pi - разделительный индекс , arr[pi]
        на верной позиции*/
      int pi = partition(arr, low, high);

      // Раздельно сортирует элементы до и после пивота
      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
    }
  }

  void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
      cout << arr[i] << " ";
    std::cout << endl;
  }

  int getMax(int array[], int size) {
    int max = array[1];
    for (int i = 2; i <= size; i++) {
      if (array[i] > max)
        max = array[i];
    }
    return max;
  }

#include <vector>
#include <map>
  void countSort(vector<int>& input) {
    // создает пустую мапу для хранения частоты элементов массива
    map<int, int> freq;

    for (int x : input) {
      freq[x]++;
    }

    //  перемещаемся по мапе и перезаписываем входной массив отсортированными элементами
    // (мапа будет повторяться в соответствии с отсортированным порядком ключей)
    int i = 0;
    for (auto p : freq) {
      while (p.second--) {
        input[i++] = p.first;
      }
    }
  }

}