
#include "Sequence.h"
#include <optional>
#include <string>
#include <sstream>
// !!!Do not use the following line!!!.
//using namespace std;
// This is a horrible practice and leads to invisible side effects.
// Instead, use the scope resolution operator :: to prefix std to the method.
// ex. std::cout

template<class T>
Sequence<T>::Sequence() {
    head = NULL;
    size = 0;
}

template<class T>
Sequence<T>::~Sequence() {
    reclaimAllNodes(head);
}

template<class T>
void Sequence<T>::clear() {
    reclaimAllNodes(head);
    head = NULL;
    size = 0;
}

template<class T>
void Sequence<T>::reclaimAllNodes(NodeRecord *&initialP) {
    if (initialP != NULL) {
        reclaimAllNodes(initialP->next);
        delete (initialP);
    }
}


template<class T>
void Sequence<T>::transferFrom(Sequence &source) {
    std::optional<T> temp;
    clear(); //clears self
    for (int i = 0; i < source.length(); i++)//traverses source
    {
        temp = source.entry(i);
        if (temp != std::nullopt) {
            add(temp.value(), length());//adds source elements to self
        }
    }
    source.clear();//clears source
}

template<class T>
Sequence<T> &Sequence<T>::operator=(Sequence const &rhs) = default;


template<class T>
void Sequence<T>::add(T &x, int pos) {
    /*
     * Check if pos is out of bounds
     * Create a new node record and populate it with x
     * point the new node record to the next node
     * point the previous node to the new node record
     */
    if (pos > 0 || pos > size) {
        return;
    }
    if (pos == 0) {
        NodeRecord *newNode = new NodeRecord();
        newNode->value = x;
        newNode->next = head;
        head = newNode;
    } else {

//Create a new node and populate with data.
        NodeRecord *currentNode = head, *prevNode = NULL;
        NodeRecord *newNode = new NodeRecord();
        newNode->value = x;
        for (int i = 0; i < pos; i++) {
            prevNode = currentNode;
            currentNode = currentNode->next;

            //currentNode->value = x;
            //point the new node record to the next node
            //currentNode->next = head->next;
            //point the previous node to the new node record
            //head->next = currentNode;
        }
        newNode->next = currentNode;
        prevNode->next = newNode;
    }
    size++;
    return;
}

template<class T>
void Sequence<T>::remove(T &x, int pos) {
    /*
     * Check if the position in the list is out of bounds
     * Increment through the list until pos
     * Delete the node
     * Link the previous node to the next node
     * Store x as the deleted node
     */
// Check if the position in the list is out of bounds
    if (pos < 0 || pos >= size) {
        return;
    }
    if (pos == 0) {
        NodeRecord *currentNode = head;
        x = currentNode->value;
        head = head->next;
        delete currentNode;

    } else {
        NodeRecord *currentNode = head, *prevNode = NULL;
        //Increment through the list until pos
        for (int i = 0; i < pos; i++) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        //Store x as the deleted node
        x = currentNode->value;
        // Link the previous node to the next node
        prevNode->next = currentNode->next;
        //Delete the node
        delete currentNode;
    }
    size--;
    return;
}

template<class T>
std::optional<T> Sequence<T>::entry(int pos) {
    /*
     * Check if the position is out of bounds.
     * May also check if the list is not empty
     * If position is not out of bounds:{
     * Start currentValue at head
     * Iterate through the length of the list
     * Return the value by reference.}
     * else return NULL
     * Will a case be required if head is the only node?
     */

    NodeRecord *currentNode = head;

    if (pos >= size) {
        return std::nullopt;
    } else {
        //Create a var to hold the value.
        int val = 0;
        //Iterate through the list.
        for (int i = 0; i < pos; ++i) {
            currentNode = currentNode->next;
        }
        val = currentNode->value;
        return val;
    }

}

template<class T>
int Sequence<T>::length() {
    return size;
}

template<class T>
std::string Sequence<T>::outputSequence() {
    std::stringstream ss;

    //Use insertion operator (<<) to build the string.
    return ss.str();

}

