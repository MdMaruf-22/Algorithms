#include <iostream>
#include <vector>
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    int left = low;
    int right = high - 1;

    while (true) {
        while (left <= right && arr[left] < pivot) {
            left++;
        }
        while (right >= left && arr[right] > pivot) {
            right--;
        }

        if (left >= right) {
            break;
        }

        std::swap(arr[left], arr[right]);
    }

    std::swap(arr[left], arr[high]);
    return left;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int size;std::cin>>size;
    std::vector<int> arr(size);
    for(int i=0;i<size;i++){
        std::cin>>arr[i];
    }
    quickSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
