#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int whole;
    int numerator;
    int denominator;
} MixedNumber;

typedef struct {
    int numerator;
    int denominator;
} Fraction;

Fraction mixedToFraction(MixedNumber mn);
MixedNumber fractionToMixed(Fraction frac);
int compareMixedNumbers(MixedNumber a, MixedNumber b);
MixedNumber addMixedNumbers(MixedNumber a, MixedNumber b);
MixedNumber subtractMixedNumbers(MixedNumber a, MixedNumber b);
MixedNumber multiplyMixedNumbers(MixedNumber a, MixedNumber b);
MixedNumber divideMixedNumbers(MixedNumber a, MixedNumber b);
void interchangeSortMixedNumbers(MixedNumber* arr, int n, int ascending);
void selectionSortMixedNumbers(MixedNumber* arr, int n, int ascending);
void quickSortMixedNumbers(MixedNumber* arr, int left, int right, int ascending);

// Hàm tạo mảng chứa giá trị hỗn số ngẫu nhiên
void createRandomMixedNumberArray(MixedNumber* arr, int n) {
    for (int i = 0; i < n; ++i) {
        arr[i].whole = rand() % 100; // Phần nguyên từ 0 đến 99
        arr[i].numerator = rand() % 100; // Tử số từ 0 đến 99
        do {
            arr[i].denominator = 1 + rand() % 99; // Mẫu số từ 1 đến 99
        } while (arr[i].denominator == 0); // Đảm bảo mẫu số khác 0
    }
}

// Hàm xuất danh sách hỗn số
void printMixedNumberArray(MixedNumber* arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d %d/%d\n", arr[i].whole, arr[i].numerator, arr[i].denominator);
    }
}

// Hàm so sánh 2 hỗn số
int compareMixedNumbers(MixedNumber a, MixedNumber b) {
    // Chuyển hỗn số thành phân số
    Fraction fracA = mixedToFraction(a);
    Fraction fracB = mixedToFraction(b);

    // So sánh phân số
    int commonDenomA = fracA.numerator * fracB.denominator;
    int commonDenomB = fracB.numerator * fracA.denominator;

    if (commonDenomA < commonDenomB) return -1;
    if (commonDenomA > commonDenomB) return 1;
    return 0;
}

// Hàm chuyển hỗn số sang phân số
Fraction mixedToFraction(MixedNumber mn) {
    Fraction frac;
    frac.numerator = mn.whole * mn.denominator + mn.numerator;
    frac.denominator = mn.denominator;
    return frac;
}

// Hàm chuyển phân số sang hỗn số
MixedNumber fractionToMixed(Fraction frac) {
    MixedNumber mn;
    mn.whole = frac.numerator / frac.denominator;
    mn.numerator = frac.numerator % frac.denominator;
    mn.denominator = frac.denominator;
    return mn;
}

// Hàm tính tổng 2 hỗn số
MixedNumber addMixedNumbers(MixedNumber a, MixedNumber b) {
    Fraction fracA = mixedToFraction(a);
    Fraction fracB = mixedToFraction(b);
    Fraction sum;
    sum.numerator = fracA.numerator * fracB.denominator + fracB.numerator * fracA.denominator;
    sum.denominator = fracA.denominator * fracB.denominator;
    return fractionToMixed(sum);
}

// Hàm tính hiệu 2 hỗn số
MixedNumber subtractMixedNumbers(MixedNumber a, MixedNumber b) {
    Fraction fracA = mixedToFraction(a);
    Fraction fracB = mixedToFraction(b);
    Fraction diff;
    diff.numerator = fracA.numerator * fracB.denominator - fracB.numerator * fracA.denominator;
    diff.denominator = fracA.denominator * fracB.denominator;
    return fractionToMixed(diff);
}

// Hàm tính tích 2 hỗn số
MixedNumber multiplyMixedNumbers(MixedNumber a, MixedNumber b) {
    Fraction fracA = mixedToFraction(a);
    Fraction fracB = mixedToFraction(b);
    Fraction product;
    product.numerator = fracA.numerator * fracB.numerator;
    product.denominator = fracA.denominator * fracB.denominator;
    return fractionToMixed(product);
}

// Hàm tính thương 2 hỗn số
MixedNumber divideMixedNumbers(MixedNumber a, MixedNumber b) {
    Fraction fracA = mixedToFraction(a);
    Fraction fracB = mixedToFraction(b);
    Fraction quotient;
    quotient.numerator = fracA.numerator * fracB.denominator;
    quotient.denominator = fracA.denominator * fracB.numerator;
    return fractionToMixed(quotient);
}

// Hàm sắp xếp mảng tăng/giảm theo giải thuật Interchange Sort
void interchangeSortMixedNumbers(MixedNumber* arr, int n, int ascending) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((ascending && compareMixedNumbers(arr[i], arr[j]) > 0) ||
                (!ascending && compareMixedNumbers(arr[i], arr[j]) < 0)) {
                MixedNumber temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng tăng/giảm theo giải thuật Selection Sort
void selectionSortMixedNumbers(MixedNumber* arr, int n, int ascending) {
    for (int i = 0; i < n - 1; ++i) {
        int selectedIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if ((ascending && compareMixedNumbers(arr[j], arr[selectedIdx]) < 0) ||
                (!ascending && compareMixedNumbers(arr[j], arr[selectedIdx]) > 0)) {
                selectedIdx = j;
            }
        }
        MixedNumber temp = arr[i];
        arr[i] = arr[selectedIdx];
        arr[selectedIdx] = temp;
    }
}

// Hàm sắp xếp mảng tăng/giảm theo giải thuật Quick Sort
void quickSortMixedNumbers(MixedNumber* arr, int left, int right, int ascending) {
    if (left < right) {
        MixedNumber pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            if ((ascending && compareMixedNumbers(arr[j], pivot) < 0) ||
                (!ascending && compareMixedNumbers(arr[j], pivot) > 0)) {
                i++;
                MixedNumber temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        MixedNumber temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;

        quickSortMixedNumbers(arr, left, i, ascending);
        quickSortMixedNumbers(arr, i + 2, right, ascending);
    }
}

// Hàm nhập hỗn số từ bàn phím
MixedNumber inputMixedNumber() {
    MixedNumber mn;
    printf("Nhap phan nguyen: ");
    scanf("%d", &mn.whole);
    printf("Nhap tu so: ");
    scanf("%d", &mn.numerator);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &mn.denominator);
    } while (mn.denominator == 0);
    return mn;
}

// Hàm nhập mảng hỗn số từ bàn phím
void inputMixedNumberArray(MixedNumber* arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("Nhap hon so thu %d:\n", i + 1);
        arr[i] = inputMixedNumber();
    }
}

int main() {
    srand(time(0)); // Khởi tạo seed cho rand()

    int n;
    printf("Nhap so luong hon so: ");
    scanf("%d", &n);

    // Cấp phát bộ nhớ cho mảng hỗn số
    MixedNumber* arr = (MixedNumber*)malloc(n * sizeof(MixedNumber));
    if (arr == NULL) {
        printf("Khong cap phat duoc bo nho.\n");
        return 1;
    }

    // Tạo mảng hỗn số ngẫu nhiên
    createRandomMixedNumberArray(arr, n);
    printf("\nMang ngau nhien:\n");
    printMixedNumberArray(arr, n);

    // Thực hiện các phép toán với 2 hỗn số nhập từ bàn phím
    printf("\nThuc hien cac phep toan voi 2 hon so nhap tu ban phim:\n");
    printf("\nNhap hon so thu nhat:\n");
    MixedNumber a = inputMixedNumber();
    printf("Nhap hon so thu hai:\n");
    MixedNumber b = inputMixedNumber();

    MixedNumber sum = addMixedNumbers(a, b);
    printf("\nTong: %d %d/%d\n", sum.whole, sum.numerator, sum.denominator);

    MixedNumber diff = subtractMixedNumbers(a, b);
    printf("Hieu: %d %d/%d\n", diff.whole, diff.numerator, diff.denominator);

    MixedNumber product = multiplyMixedNumbers(a, b);
    printf("Tich: %d %d/%d\n", product.whole, product.numerator, product.denominator);

    MixedNumber quotient = divideMixedNumbers(a, b);
    printf("Thuong: %d %d/%d\n", quotient.whole, quotient.numerator, quotient.denominator);

    // Sắp xếp mảng
    interchangeSortMixedNumbers(arr, n, 1);
    printf("\nMang sau khi sap xep tang dan (Interchange Sort): \n");
    printMixedNumberArray(arr, n);

    selectionSortMixedNumbers(arr, n, 0);
    printf("\nMang sau khi sap xep giam dan (Selection Sort): \n");
    printMixedNumberArray(arr, n);

    quickSortMixedNumbers(arr, 0, n - 1, 1);
    printf("\nMang sau khi sap xep tang dan (Quick Sort): \n");
    printMixedNumberArray(arr, n);

    // Giải phóng bộ nhớ
    free(arr);

    return 0;
}