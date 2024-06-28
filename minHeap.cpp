//Hossein Shirani - 4011406134
#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    private:
        vector<int> heap;
        int parent(int index) { return (index - 1) / 2; }
        int leftChild(int index) { return (2 * index + 1); }
        int rightChild(int index) { return (2 * index + 2); }
        void up(int index){
            if(index && heap[parent(index)] > heap[index]) {
                swap(heap[index], heap[parent(index)]);
                up(parent(index));
            }
        }
        void down(int index) {
            int left = leftChild(index);
            int right = rightChild(index);
            int smallest = index;
            if (left < size() && heap[left] < heap[smallest]){
                smallest = left;
            }
            if (right < size() && heap[right] < heap[smallest]){
                smallest = right;
            }
            if (smallest != index){
                swap(heap[index], heap[smallest]);
                down(smallest);
            }
        }
    public:
        MinHeap(){}
        void insert(int element){
            heap.push_back(element);
            int index = size() - 1;
            up(index);
        }
        void pop(){
            if (size() == 0){
                cout << "khalie" << endl;
                return;
            }
            heap[0] = heap.back();
            heap.pop_back();
            down(0);
        }
        int root(){
            if (size() == 0) {
                cout << "no root available :D" << endl;
                return -1;
            }
            return heap.front();
        }
        void print() {
            for (int i : heap){
                cout << i << " ";}
            cout << endl;
        }
        int size(){
            return heap.size(); 
        }
};

int main() {
    MinHeap MH;
    MH.insert(0);
    MH.insert(9);
    MH.insert(13);
    MH.insert(21);
    MH.insert(6);
    MH.print();
    cout<<MH.root()<<endl;
    MH.pop();
    MH.print();

    return 0;
}