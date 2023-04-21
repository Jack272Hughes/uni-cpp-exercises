#include <iostream>
#include <ctime>

using namespace std;

typedef void (*SortFunction)(int arr[], int size);

int timeSortFunction(SortFunction sortFunction, int arr[], int size) {
    std::clock_t startTime = std::clock();
    sortFunction(arr, size);
    return (std::clock() - startTime) / (double) (CLOCKS_PER_SEC / 1000);
}

void printArray(int arr[], int size) {
    cout << "Array has elements: " << arr[0];
    for (int i = 1; i < size; i++) {
        cout << ", " << arr[i];
    }
    cout << endl;
}

void testWithBasicData(SortFunction sortFunction) {
    int dataSize = 10;
    int data[] = { 4, 5, 6, 1, 3, 9, 4, 8, 2, 7 };
    sortFunction(data, dataSize);
    printArray(data, dataSize);
}

void testWithRandomData(SortFunction sortFunction, int randomDataSize) {
    int randomData[randomDataSize];
    for (int i = 0; i < randomDataSize; i++) {
        randomData[i] = rand() % 101;
    }
    int timeTaken = timeSortFunction(sortFunction, randomData, randomDataSize);
    cout << "An array of random data took " << (double) timeTaken / 1000 << " seconds to sort" << endl;
}

void testWithRandomSortedData(SortFunction sortFunction, int randomDataSize) {
    int randomData[randomDataSize];
    for (int i = 0; i < randomDataSize; i++) {
        randomData[i] = i;
    }
    int timeTaken = timeSortFunction(sortFunction, randomData, randomDataSize);
    cout << "An already sorted array took " << (double) timeTaken / 1000 << " seconds to sort" << endl;
}

void swapInt(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int smallestIndex = i;
        for (int ii = i; ii < size; ii++) {
            if (arr[ii] < arr[smallestIndex]) {
                smallestIndex = ii;
            }
        }
        swapInt(&arr[i], &arr[smallestIndex]);
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int ii = 0; ii < size - 1; ii++) {
            if (arr[ii] > arr[ii + 1]) {
                swapInt(&arr[ii], &arr[ii + 1]);
            }
        }
    }
}

void enhancedBubbleSort(int arr[], int size) {
    bool sorted;
    int lastUnsorted = size - 1;
    do {
        sorted = true;
        for (int ii = 0; ii < lastUnsorted; ii++) {
            if (arr[ii] > arr[ii + 1]) {
                swapInt(&arr[ii], &arr[ii + 1]);
                sorted = false;
            }
        }
    } while (!sorted);
}

int sequentialSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int key) {
    int middle = 0, lower = 0, upper = size - 1;

    while (lower <= upper) {
        middle = (lower + upper) / 2;
        if (key < arr[middle]) {
            upper = middle - 1;
        } else if (key > arr[middle]) {
            lower = middle + 1;
        } else return middle;
    }

    return -1;
}

int main() {
    srand(time(0));

    cout << "-=== Exercise 1 & 2 & 3 ===-" << endl;
    testWithBasicData(selectionSort);
    testWithRandomData(selectionSort, 40000);

    cout << "-=== Exercise 4 ===-" << endl;
    testWithBasicData(bubbleSort);
    testWithRandomData(bubbleSort, 20000);

    cout << "-=== Exercise 5 ===-" << endl;
    testWithRandomData(enhancedBubbleSort, 20000);

    testWithRandomSortedData(bubbleSort, 30000);
    testWithRandomSortedData(enhancedBubbleSort, 50000);

    cout << "-=== Exercise 6 ===-" << endl;
    int sortedData[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "The index of number '8' using sequential search is " << sequentialSearch(sortedData, 10, 8) << endl;

    cout << "-=== Exercise 7 ===-" << endl;
    cout << "The index of number '10' using binary search is " << binarySearch(sortedData, 10, 10) << endl;
}