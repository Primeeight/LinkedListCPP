
#include "Sequence.h"
#include <optional>
#include <string>
#include <sstream>
// !!!Do not use the following line!!!.
//using namespace std;
// This is a horrible practice and leads to invisible side effects.
// Instead, use the scope resolution operator :: to prefix std to the method.
// ex. std::cout

template <class T>
Sequence<T>::Sequence ()
{
    head = NULL;
    size = 0;
}

template <class T>
Sequence<T>::~Sequence ()
{
    reclaimAllNodes(head);
}

template <class T>
void Sequence<T>::clear ()
{
    reclaimAllNodes(head);
    head = NULL;
    size = 0;
}

template <class T>
void Sequence<T>::reclaimAllNodes (NodeRecord*& initialP)
{
    if (initialP != NULL) {
        reclaimAllNodes(initialP->next);
        delete (initialP);
    }
}


template <class T>
void Sequence<T>::transferFrom(Sequence& source)
{
    std::optional<T> temp;
    clear(); //clears self
    for (int i = 0; i < source.length(); i++)//traverses source
    {
        temp = source.entry(i);
        if(temp != std::nullopt) {
            add(temp.value(), length());//adds source elements to self
        }
    }
    source.clear();//clears source
}

template <class T>
Sequence<T>& Sequence<T>::operator=(Sequence const& rhs) = default;


template<class T>
void Sequence<T>::add(T &x, int pos) {

}

template<class T>
void Sequence<T>::remove(T &x, int pos) {

}

template<class T>
std::optional<T> Sequence<T>::entry(int pos)  {
    NodeRecord* currentValue = head;

    if (pos >= size) {
        return std::nullopt;
    }
    //You will need to create the else condition for when the position is within the NodeRecord.
    //You will need to replace the return here.
    else {
        return std::nullopt;
    }

}

template<class T>
int Sequence<T>::length() {
    return 0;
}

template<class T>
std::string Sequence<T>::outputSequence() {
    std::stringstream ss;

    //Use insertion operator (<<) to build the string.
    return ss.str();

}

