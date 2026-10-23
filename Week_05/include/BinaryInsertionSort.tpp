//
// Created by aldin on 01/04/2025.
//

#ifndef BINARYINSERTIONSORT_TPP
#define BINARYINSERTIONSORT_TPP

/**
 * You may add any helper methods, if you need them.
 */

template<typename Data>
void BinaryInsertionSort::sort(LinkedList<Data>& list) {
    if (list.head == nullptr) {
        return;
    }

    Node<Data>* last_sorted = list.head;
    for (int i = 1; i < list.size; ++i) {
        Node<Data>* current = last_sorted->next;
        int index = find_insertion_point(list, i - 1, current->data);

        if (index == i) {
            last_sorted = current;
            continue;
        }

        last_sorted->next = current->next;
        if (index == 0) {
            current->next = list.head;
            list.head = current;
        } else {
            Node<Data>* prev = list.head;
            for (int j = 0; j < index - 1; ++j) {
                prev = prev->next;
            }
            current->next = prev->next;
            prev->next = current;
        }
    }
}

template<typename Data>
int BinaryInsertionSort::find_insertion_point(LinkedList<Data>& list, int high, Data key) {
    int low = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (key < list.get(mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

#endif //BINARYINSERTIONSORT_TPP
