#pragma once
#include <memory>
#include <iostream>
using namespace std;

struct a {
    int data;
    int get() {
        return data;
    }
};
template<typename T>
class sharepoint {
private:
    T* _ptr;
    int* _count; //reference counting
public:
    //���캯��
    sharepoint(T* ptr = nullptr) :_ptr(ptr) {
        if (_ptr) {
            _count = new int(1);
        }
        else {
            _count = new int(0);
        }
    }

    //��������
    sharepoint(const sharepoint& ptr) {
        if (this != &ptr) {
            this->_ptr = ptr._ptr;
            this->_count = ptr._count;

            (*this->_count)++;
        }
    }

    //����operator=
    sharepoint operator=(const T* ptr) {
        if (this->_ptr == ptr._ptr) {
            return *this;
        }
        this->_ptr = _ptr;
        return *this;
    }
    //����operator=
    sharepoint operator=(const sharepoint& ptr) {
        if (this->_ptr == ptr._ptr) {
            return *this;
        }
        if (this->_ptr) {
            (*this->_count)--;
            if (this->_count == 0) {
                delete this->_ptr;
                delete this->_count;
            }
        }
        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;
        return *this;
    }

    //operator*����
    T& operator*() {
        return *(this->_ptr);
    }

    //operator->����
    T* operator->() {
        return _ptr;
    }
    //T* operator () {
    //    return this->_ptr;
    //}
    //T& operator->() {
    //    return _ptr;
    //}
    explicit operator bool() const noexcept;
    //��������
    ~sharepoint() {
        (*this->_count)--;
        if (*this->_count == 0) {
            delete this->_ptr;
            delete this->_count;
        }
    }
    bool isempty() {
        if (_ptr)
            return true;
        else
            return false;
    }
    T* get() {
        return this->_ptr;
    }
    //return reference counting
    int use_count() {
        return *this->_count;
    }
};

template<typename T>
sharepoint<T>::operator bool() const noexcept
{
    return this->_ptr;
}
