//Hossein Shirani - 4011406134
#include <iostream>
using namespace std;
class sort {
    public:
        void bubbleSort(int arr[], int n) {
            for (int i = 0; i < n - 1; i++)
                for (int j = 0; j < n - i - 1; j++)
                    if (arr[j] > arr[j + 1])
                        swap(arr[j], arr[j + 1]);
        }
        void selectionSort(int arr[], int n) {
            int i, j, min_idx;
            for (i = 0; i < n - 1; i++) {
                min_idx = i;
                for (j = i + 1; j < n; j++)
                    if (arr[j] < arr[min_idx])
                        min_idx = j;
                swap(arr[min_idx], arr[i]);
            }
        }
        void insertionSort(int arr[], int n) {
            int i, key, j;
            for (i = 1; i < n; i++) {
                key = arr[i];
                j = i - 1;
                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
            }
        }
};
class search {
public:
    int binarySearch(int arr[], int left, int right, int x) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    int linearSearch(int arr[], int n, int x) {
        for (int i = 0; i < n; i++)
            if (arr[i] == x)
                return i;
        return -1;
    }
};

int main() {
    int arr[] = { 5, 2, 8, 1, 9 };
    sort s;
    s.bubbleSort(arr,5);
    cout << arr[0];
    return 0;
}