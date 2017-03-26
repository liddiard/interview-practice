// find all numbers that occur an odd number of times in an array

#include <unordered_set>
#include <iostream>
using namespace std;

void odd_numbers(int arr[], int size)
{
    unordered_set<int> numbers;
    for (int i = 0; i < size; i++)
    {
        if (numbers.find(arr[i]) != numbers.end())
            numbers.erase(arr[i]);
        else
            numbers.insert(arr[i]);
    }
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        cout << *it << endl;
    }
}

int main()
{
    const int SIZE = 15;
    int numbers[SIZE] = {5, 6, 2, 3, 5, 6, 4, 2, 0, 99, 5, 1, 1, 1, 2};
    odd_numbers(numbers, SIZE);
    return 0;
}
