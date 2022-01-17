#pragma once
#include <memory>

using namespace std;

template<typename node, typename T>
class TIterator {
private:
    shared_ptr<node> ptr;

public:
    TIterator(shared_ptr<node> other) {
        ptr = other;
    }

    shared_ptr<T> operator*() {
        return ptr->pValue;
    }

    shared_ptr<T> operator->() {
        return ptr->pValue;
    }

    TIterator<node, T> operator++() {
        return ptr = ptr->pNextItem;
    }

    TIterator<node, T> operator++(int) {
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator==(TIterator<node, T> const& other) {
        return ptr == other.ptr;
    }

    bool operator!=(TIterator<node, T> const& other) {
        return !(*this == other);
    }

};
