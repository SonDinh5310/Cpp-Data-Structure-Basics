#include <iostream>
#include <vector>

using namespace std;

void basicsort(vector<int> &a)  // n^2 && o(1)
{
    int i, j, temp;
    for (i = 0; i < a.size(); i++) {
        for (j = i + 1; j < a.size(); j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void selectionSort(vector<int> &arr) {
    int min_index;
    for (int i = 0; i < arr.size() - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
}
void Merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> aux(high - low + 1);
    //co 3 truong hop
    int i = low, j = mid + 1, k;
    for (k = 0; k < aux.size(); k++) {
        //truong hop chi co trai (left)
        if (j > high) {
            aux[k] = arr[i++];
            continue;
        }
        //truong hop chi co phai (right)
        if (i > mid) {
            aux[k] = arr[j++];
            continue;
        }
        //truong hop co ca hai
        if (arr[i] <= arr[j]) {
            aux[k] = arr[i++];
        } else
            aux[k] = arr[j++];
    }
    for (int temp = low; temp <= high; temp++) {
        arr[temp] = aux[temp - low];
    }
}
void merge_sort(vector<int> &arr, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = low + (high - low) / 2;
    //ben trai
    merge_sort(arr, low, mid);
    //ben phai
    merge_sort(arr, mid + 1, high);
    //
    Merge(arr, low, mid, high);
}

void Shell_sort(vector<int> &array) {
    //invariant : is variation of insertion sort in oder to increase times value find location
    // h = 1, 4, 13, 40, .... 3*k+1
    //h = 3*h+1
    //time complexity: O(N^3/2); space : O(1)
    int h = 0, size = array.size();
    while (h < size) {
        h = h * 3 + 1;
    }
    while (1) {
        int i, j, value;
        h = (h - 1) / 3;
        if (h == 0)
            break;
        for (i = h; i < size; i += h) {
            j = i;
            value = array[i];
            while (j >= h && array[j - h] > value) {
                array[j] = array[j - h];
                j -= h;
            }
            array[j] = value;
        }
    }
}

int partition(vector<int> &arr, int low, int high) {
    int i, p_index = low;
    int pivot = arr[high];

    for (i = low; i < high; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[p_index]);
            p_index++;
        }
    }
    swap(arr[p_index], arr[high]);
    return p_index;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

int main() {
    vector<int> v;
    v.push_back(20);
    v.push_back(90);
    v.push_back(80);
    v.push_back(0);
    v.push_back(-22);
    v.push_back(100);
    v.push_back(5);
    // quickSort(v, 0, v.size() - 1);
    Shell_sort(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
