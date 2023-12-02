#include <iostream>
using namespace std;

// напрям сортування
enum SortOrder
{
    ASC // сортуємо масив за зростанням
};

// обмін елементів масиву
void swapElements(int& element1, int& element2)
{
    int tempVar = element1;
    element1 = element2;
    element2 = tempVar;
}

// перевірка на правильність розташування елементів
bool isSorted(int a, int b, SortOrder sortOrder)
{
    if (sortOrder == ASC)
    {
        return a <= b;
    }
    else
    {
        return a >= b;
    }
}

// Сортування Бульбашкою
int* bubbleSort(int* array, int n, SortOrder sortOrder)
{
    bool swappedFlag = false;

    for (int i = 1; i < n; i++)
    {
        swappedFlag = false;

        for (int j = 0; j < n - i; j++)
        {
            if (!isSorted(array[j], array[j + 1], sortOrder))
            {
                swapElements(array[j], array[j + 1]);
                swappedFlag = true;
            }
        }

        // якщо обмінів не було, цикл буде перервано
        if (!swappedFlag)
        {
            break;
        }
    }
    return array;
}

// введеня масиву з клавіатури
int* fillArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    return arr;
}

// виведення масиву на екран
void printArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(int argc, char** argv)
{
    int* arr;
    long int size;

    cout << "n = ";
    cin >> size;

    arr = new int[size];

    arr = fillArray(arr, size);

    arr = bubbleSort(arr, size, ASC);

    printArray(arr, size);

    delete arr;

    cout << endl;

    system("pause");
    return 0;
}