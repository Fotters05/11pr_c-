#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class MergeSort {
public:
    void Sort(vector<int>& arr) {
        if (arr.size() > 1) {
            vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
            vector<int> right(arr.begin() + arr.size() / 2, arr.end());

            Sort(left);
            Sort(right);

            merge(arr, left, right);
        }
    }

private:
    void merge(vector<int>& arr, const vector<int>& left, const vector<int>& right) {
        size_t i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            }
            else {
                arr[k++] = right[j++];
            }
        }
        while (i < left.size()) {
            arr[k++] = left[i++];
        }
        while (j < right.size()) {
            arr[k++] = right[j++];
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    vector<int> numbers(10);
    cout << "Введите любые десять чисел: ";
    for (int& num : numbers) {
        cin >> num;
    }

    MergeSort sorter;
    thread sortThread([&sorter, &numbers] { sorter.Sort(numbers); });
    sortThread.join();

    cout << "Отсортированный массив: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
