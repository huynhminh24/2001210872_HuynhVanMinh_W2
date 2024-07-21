#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm để tạo mảng ngẫu nhiên với số phần tử >= 15
void createRandomArray(int* arr, int n, int lower, int upper) {
    if (n < 15) n = 15;
    for (int i = 0; i < n; ++i) {
        arr[i] = lower + rand() % (upper - lower + 1);
    }
}

// Hàm để tạo mảng chứa toàn số chẵn
void createEvenArray(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = 2 * (rand() % 50); // Số chẵn từ 0 đến 98
    }
}

// Hàm tìm kiếm tuyến tính
int linearSearch(int* arr, int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1; // Không tìm thấy
}

// Hàm sắp xếp tăng dần/giảm dần theo giải thuật Interchange Sort
void interchangeSort(int* arr, int n, int ascending) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm tìm kiếm nhị phân
int binarySearch(int* arr, int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Không tìm thấy
}

// Hàm sắp xếp tăng dần theo giải thuật Selection Sort
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

// Hàm sắp xếp tăng dần theo giải thuật Quick Sort
void quickSort(int* arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;

        quickSort(arr, left, i);
        quickSort(arr, i + 2, right);
    }
}

int main() {
    srand(time(0)); // Khởi tạo seed cho rand()

    int n = 15;
    int arr[100];

    // Tạo mảng ngẫu nhiên
    createRandomArray(arr, n, 0, 100);
    printf("1. Mang ngau nhien: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Tạo mảng chứa toàn số chẵn
    createEvenArray(arr, n);
    printf("2. Mang so chan: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Tìm kiếm tuyến tính
    int x = 10; // Số cần tìm
    int pos = linearSearch(arr, n, x);
    if (pos != -1) {
        printf("3. Tim thay %d o vi tri %d\n", x, pos);
    }
    else {
        printf("3. Khong tim thay %d\n", x);
    }

    // Sắp xếp tăng dần theo Interchange Sort
    interchangeSort(arr, n, 1);
    printf("4. Mang sau khi sap xep tang dan (Interchange Sort): ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Tìm kiếm nhị phân
    pos = binarySearch(arr, n, x);
    if (pos != -1) {
        printf("5. Tim thay %d o vi tri %d (Binary Search)\n", x, pos);
    }
    else {
        printf("5. Khong tim thay %d (Binary Search)\n", x);
    }

    // Sắp xếp tăng dần theo Selection Sort
    selectionSort(arr, n);
    printf("6. Mang sau khi sap xep tang dan (Selection Sort): ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sắp xếp tăng dần theo Quick Sort
    quickSort(arr, 0, n - 1);
    printf("7. Mang sau khi sap xep tang dan (Quick Sort): ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
