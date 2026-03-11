#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

// swap function
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// heapify upward (after insertion)
void heapifyUp(int index){
    int parent = (index - 1) / 2;

    while(index > 0 && heap[parent] > heap[index]){
        swap(&heap[parent], &heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// heapify downward (after deletion)
void heapifyDown(int index){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != index){
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// insert element
void insert(int value){
    if(size == MAX){
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = value;
    size++;

    heapifyUp(size - 1);
}

// extract minimum element
int extractMin(){
    if(size <= 0){
        printf("Heap Empty\n");
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return root;
}

// display heap
void display(){
    for(int i = 0; i < size; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main(){

    insert(10);
    insert(5);
    insert(20);
    insert(2);
    insert(8);

    printf("Min Heap:\n");
    display();

    printf("Extracted Min: %d\n", extractMin());

    printf("Heap after deletion:\n");
    display();

    return 0;
}
