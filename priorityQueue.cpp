#include <iostream>
#include <vector>

using namespace std;

class PQ {
   public:
    vector<int> arr;
    PQ() {}

    void Swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }

    //Them 1 phan tu vao trong vector
    void swim(int index) {
        while (index > 1 && arr[index] < arr[(index - 1) / 2]) {
            Swap(arr[(index - 1) / 2], arr[index]);
            //update vi tri
            index = (index - 1) / 2;
        }
    }

    void Insert(int value) {
        //lay size cua vector
        int temp = arr.size();
        //chen value vao vector
        arr.push_back(value);
        //swim
        swim(temp);
    }

    void sink(int index) {
        int temp = arr.size();
        while (index * 2 + 1 < temp) {
            //chac chan ton tai 1 con
            int left = index * 2 + 1;
            //kiem tra xem co con thu 2 khong
            if (left + 1 < temp) {
                if (arr[left] > arr[left + 1]) {
                    left++;
                }
            }
            if (arr[left] < arr[index])
                Swap(arr[left], arr[index]);
            //update vi tri cua index
            index = left;
        }
    }

    void Remove() {
        //lay size cua arr
        int temp = arr.size();
        //thay gia tri tai min value bang gia tri o cuoi vector
        arr[0] = arr[temp - 1];
        //xoa gia tri o cuoi vector
        arr.pop_back();
        //duy tri ket cau dung cho cay (day gia tri xuong dung cho)
        sink(0);
    }

    int Size() {
        return arr.size();
    }

    void display() {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
    }
    void heapSort(vector<int>& aux) {
        int i = arr.size() - 1;
        while (i >= 0) {
            aux[i] = arr[0];
            Remove();
            sink(0);
            i--;
        }
    }

    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> aux;
        //! Co 3 truong hop
        int i = low, j = mid + 1, k, temp;

        for (k = 0; k < arr.size(); k++) {
            //*Truong hop chi co trai (left)
            if (j > high) {
                aux[k] = aux[j++];
            }
            //*Truong hop chi co phai (right)
            if (i > mid) {
                aux[k] = aux[j++];
            }
            //*Truong hop co ca hai
            if (arr[i] <= arr[j]) {
                aux[k] = arr[i++];
            } else {
                aux[k] = arr[j++];
            }
        }

        for (temp = low; temp <= high; temp++) {
            arr[temp] = arr[temp - low];
        }
    }

    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) {
            return;
        }

        int mid = low + (high - low) / 2;
        //*Ben trai
        mergeSort(arr, low, mid);
        //*Ben phai
        mergeSort(arr, mid + 1, high);
        //*Ghep trai phai
        merge(arr, low, mid, high);
    }
};
int main() {
    PQ priority_Queue;
    priority_Queue.Insert(20);
    priority_Queue.Insert(5);
    priority_Queue.Insert(90);
    priority_Queue.Insert(80);
    priority_Queue.Insert(100);
    priority_Queue.Insert(0);
    priority_Queue.Insert(-22);
    priority_Queue.display();
    cout << endl;
    vector<int> aux(priority_Queue.Size());
    priority_Queue.heapSort(aux);
    for (int num : aux)
        cout << num << ' ';
    cout << endl;
    //	cout << endl;
    //	priority_Queue.Remove();
    //	priority_Queue.display();
    //	cout << endl;
    //	priority_Queue.Remove();
    //	priority_Queue.display();
    return 0;
}
