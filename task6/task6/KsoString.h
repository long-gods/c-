#pragma once

#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template<class T=char>
struct node {
	T data;
	node* next=NULL;
};
class errorOutRange
{

};

template <class T = char>
class KsoString
{
public:
	KsoString();
	KsoString(const T* p);//char* ���캯��
	KsoString(KsoString<T>& str);
	int getlength() { return length; }
	void insert_point(int n, T data);
	void delete_point(int n, T data);

	T operator [](int id);
	void show() {
		node<T>* p;
		p = m_node;
		if (strcmp(typeid(T).name(), "char") == 0)
			while (p->next != NULL)
			{
				cout << p->data;
				p = p->next;
			}
		else if (strcmp(typeid(T).name(), "wchar_t") == 0)
			while (p->next != NULL)
			{
				wcout << p->data;
				p = p->next;
			}
		else
				cout << "���Ͳ�ƥ�䣬�������������" << endl;
		cout << endl;
	}
	KsoString operator+(KsoString str) {
		node<T>* p = m_node;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = str.m_node;
		return *this;
	}
	KsoString operator=(const KsoString<T>& str) {
		node<T>* p;
		m_node->data = str.m_node->data;
		while (str.m_node->next != NULL)
		{
			p = (node<T>*)malloc(sizeof(node<T>));
			p->data = str.m_node->data;
			p->next = m_node;
			m_node->next = p;
		}
		length = str.length;
		return *this;
	}
	~KsoString()
	{
		node<T>* p;
		p = m_node;
		while (p->next != NULL)
		{
			m_node = p;
			p = p->next;
			free(m_node);
		}
	}

private:
	node<T>* m_node;
	int length = 0;
};


template <class T>
KsoString<T>::KsoString()
{
	m_node = (node<T>*)malloc(sizeof(node<T>));
	m_node->data = {};
	m_node->next = NULL;
	length = 0;
}

template <class T>
KsoString<T>::KsoString(const T* p)
{
	m_node = (node<T>*)malloc(sizeof(node<T>));
	m_node->data = {};
	m_node->next = NULL;
	length = 0;
	//c++��Ҫ�ϸ�ע������ƥ�䡣
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		this->length = strlen(reinterpret_cast<const char*>(p)) + 1;//�ַ���������Ҫ��1 \0
		for (int i = 0; i < this->length; i++)
			insert_point(i, p[i]);

	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		this->length = wcslen(reinterpret_cast<const wchar_t*>(p)) + 1;
		for (int i = 0; i < this->length; i++)
			insert_point(i, p[i]);

	}
	else
	{
		cout << "���Ͳ�ƥ�䣬�������������" << endl;
	}
}

template<class T>
inline KsoString<T>::KsoString(KsoString<T>& str)
{
	m_node = (node<T>*)malloc(sizeof(node<T>));
	m_node->data = str.m_node->data;
	node<T>* p=str.m_node;
	while (p->next != NULL)
	{
		m_node->next = (node<T>*)malloc(sizeof(node<T>));
		m_node->next->data = p->data;
		p = p->next;
	}
	length = str.length;
}



template <class T>
T KsoString<T>::operator [](int id)
{
	if (id < 0 || id >= this->length)
	{
		return '0';
	}
	node<T>* p;
	p = m_node;
	while (id--)
	{
		p = p->next;

	}
	return p->data;
}

template<class T>
inline void KsoString<T>::insert_point(int n, T data)
{
	node<T>* p;
	p = m_node;
	for (int i = 0; i < n-1; i++)
	{
		p = p->next;
	}
	node<T>* insertpoint;
	insertpoint = (node<T>*)malloc(sizeof(node<T>));
	if (n == 0)
	{
		insertpoint->data = data;
		insertpoint->next = p;
		m_node = insertpoint;
	}
	else
	{
		insertpoint->data = data;
		insertpoint->next = p->next;
		p->next = insertpoint;
	}
}

template<class T>
inline void KsoString<T>::delete_point(int n, T data)
{
	node<T>* p;
	p = m_node;
	for (int i = 0; i < n; i++)
	{
		p = p->next;
	}
	node<T>* d;
	d = p;
	p = p->next;
	free(d);
}






