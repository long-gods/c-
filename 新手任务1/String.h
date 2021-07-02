#pragma once

#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


class errorOutRange
{

};

template <class T = char>
class String
{
public:
	String();
	~String();
	String(const T* p);//char* ���캯��

	String(const String& str);//�������캯��
	void operator = (const String& str);//��ֵ���캯��

	String operator + (const String& str);
	void operator += (const String& str);

	T operator [](int id);

	void show();
	//��ʽ���������
	friend ostream& operator << <>(ostream& o, const String<T>& str);
	friend istream& operator >> <>(istream& o, String<T>& str);
private:
	T* pStart = nullptr;
	int length = 0;
};

