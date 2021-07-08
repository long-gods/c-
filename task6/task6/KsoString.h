#pragma once

#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template<class T=char>
struct node {
	T data;
	node* n;
};
class errorOutRange
{

};

template <class T = char>
class KsoString
{
	node* n; 
public:
	KsoString();
	~KsoString();
	KsoString(const T* p);//char* ���캯��

	KsoString(const KsoString& str);//�������캯��
	void operator = (const KsoString& str);//��ֵ���캯��

	KsoString operator + (const KsoString& str);
	void operator += (const KsoString& str);

	T operator [](int id);

	void show();
	//��ʽ���������
	friend ostream& operator << <>(ostream& o, const KsoString<T>& str);
	friend istream& operator >> <>(istream& o, KsoString<T>& str);
private:
	T* pStart = nullptr;
	int length = 0;
};



