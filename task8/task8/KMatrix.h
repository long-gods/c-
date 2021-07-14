#pragma once
#include<vector>
#include<iostream>
using namespace std;

struct MyStruct
{
	int x=5;
	int y=5;
	int a[5][5] = {
		{1,2,3,4,5},{6,7,8,9,0},{2,3,4,5,6},{4,2,1,65,34},{2,3,4,7,9,}
	};
};

template<class T>
class KMatrix
{
private:
	vector<vector<T>> m_matrix;
	int row_count;
	int col_count;
public:
	KMatrix() {};
	KMatrix(KMatrix& mat);
	void init(int row_count, int col_count);
	void initpro(MyStruct my) {
		row_count = my.x;
		col_count = my.y;
		m_matrix.resize(row_count);
		for (int i = 0; i < row_count; i++)
		{
			m_matrix[i].resize(row_count);
			for (int j = 0; j < col_count; j++)
				m_matrix[i][j] = my.a[i][j];
		}
	}
	int getRows() const {
		return row_count;
	};
	int getCols() const {
		return col_count;
	};
	void get() {
		typename vector<vector<T>>::iterator it = m_matrix.begin();
		typename vector<T>::iterator itit = (*it).begin();
		cout << *itit << endl;
	}
	void setData(int row, int col, T value);
	T getData(int row,int col) const;
	void erase_row(int row);
	void erase_col(int col);
	KMatrix operator+(KMatrix& mat);
	void dotMul(const KMatrix&);
	KMatrix transpose(); //��������
	void print() const;

};

template<class T>
inline KMatrix<T>::KMatrix(KMatrix& mat)
{
	row_count = mat.row_count;
	col_count = mat.col_count;
	m_matrix.resize(row_count);
	for (int i = 0; i < row_count; i++)
	{
		m_matrix[i].resize(row_count);
		for (int j = 0; j < col_count; j++)
			m_matrix[i][j] = mat.m_matrix[i][j];
	}
}

template<class T>
inline void KMatrix<T>::init(int row_count, int col_count)
{
	this->row_count = row_count;
	this->col_count = col_count;
	KMatrix<T>::m_matrix.resize(row_count);
	for (int i = 0; i < row_count; i++)
		KMatrix<T>::m_matrix[i].resize(col_count);
}

template<class T>
inline void KMatrix<T>::setData(int row, int col, T value)
{
	m_matrix[row][col] = value;
}

template<class T>
inline T KMatrix<T>::getData(int row,int col) const
{
	return m_matrix[row][col];
}

template<class T>
inline void KMatrix<T>::erase_row(int row)
{
	typename vector<vector<T>>::iterator it = m_matrix.begin();
	while (row--)
	{
		it++;
	}
	row_count--;
	m_matrix.erase(it);
}

template<class T>
inline void KMatrix<T>::erase_col(int col)
{
	typename vector<vector<T>>::iterator it = m_matrix.begin();
	typename vector<T>::iterator itit = (*it).begin();
	for (int i = 0; i < col; i++)
	{
		while (col--);
			itit++;
		m_matrix[i].erase(itit);
	}
	col_count--;
}

template<class T>
KMatrix<T> operator+(KMatrix<T>& mat)
{
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
		{
			m_matrix[i][j] += mat.m_matrix[i][j];
		}
	}//��Ҫ���־���Ļ����ṹ
	return *this;
}




template<class T>
inline void KMatrix<T>::dotMul(const KMatrix& mat)
{
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
		{
			m_matrix[i][j] *= mat.m_matrix[i][j];
		}
	}//��Ҫ���־���Ļ����ṹ
}

template<class T>
inline KMatrix<T> KMatrix<T>::transpose() //��������
{
	T* a=new T[row_count*col_count];
	int k = 0;
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
		{
			a[k] = m_matrix[j][i];
			k++;
		}
	}
	k=0;
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
		{
			m_matrix[i][j] = a[k];
			k++;
		}
	}
	return *this;
}

template<class T>
inline void KMatrix<T>::print() const
{
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
		{
			cout <<m_matrix[i][j]<<" ";
		}
		cout << endl;
	}//��Ҫ���־���Ļ����ṹ
}
