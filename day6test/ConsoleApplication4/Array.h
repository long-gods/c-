#pragma once
#include <iostream> 
#include <vector>
#include <limits>
using namespace std;

template<class T>
class Array
{
private:
	T* data_=new T[100];
	int size_;
public:
    Array(vector<T> v) {
        size_ = v.size();
        data_ = static_cast<T*> (new T[size_]);
        for (int i = 0; i < size_; i++) {
            data_[i] = v[i];
        }
    }
    ~Array();           // �����������ͷ��Ѿ����뵽���ڴ�
    void sort();        // ���򣬽�����������Ԫ����С��������
    int seek(T key);    // ����ָ����Ԫ��key������������λ�ã�λ�ñ�Ŵ�0��ʼ��; ���û���ҵ����򷵻� -1
	void display() {
		int i;
		for (i = 0; i < size_; i++) {
			cout << data_[i];
			if (i != size_ - 1)
				cout << " ";  // ���һ���ո�
		}
	}
};

template<class T>
void Swap(T* a, T* b)
{
	T c = *a;
	*a = *b;
	*b = c;
}

template<class T>
inline Array<T>::~Array()
{
    delete[] data_;
}

template<class T>
inline void Array<T>::sort()
{
	for (int i = 0; i < size_ - 1; ++i)
	{
		int flag = 0;
		for (int j = 0; j < size_ - 1 - i; ++j)
		{
			if (data_[j] > data_[j + 1])
			{
				Swap(&data_[j], &data_[j + 1]);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}
	}
}

template<class T>
inline int Array<T>::seek(T key)
{
	for(int i=0;i<size_;i++)
		if (data_[i] == key)
			return i;
	return -1;
}


