#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <cstdlib>
#include "KsoString.h"



template <class T>
KsoString<T>::KsoString() :pStart(nullptr), length(0)
{
}

template <class T>
KsoString<T>::KsoString(const T* p)
{
	//c++��Ҫ�ϸ�ע������ƥ�䡣
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		this->length = strlen(reinterpret_cast<const char*>(p)) + 1;//�ַ���������Ҫ��1 \0
		this->pStart = new T[this->length];

		strcpy(reinterpret_cast<char*>(this->pStart), reinterpret_cast<const char*>(p));

	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		this->length = wcslen(reinterpret_cast<const wchar_t*>(p)) + 1;
		this->pStart = new T[this->length];
		wcscpy(reinterpret_cast<wchar_t*>(this->pStart), reinterpret_cast<const wchar_t*>(p));

	}
	else
	{
		cout << "���Ͳ�ƥ�䣬�������������" << endl;
	}
}

template <class T>
void KsoString<T>::operator = (const KsoString& str)
{
	//�ͷ�ԭ��������
	if (this->pStart != nullptr)
	{
		delete[] this->pStart;
	}
	this->length = 0;


	this->length = str->length;
	this->pStart = new T[this->length];
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		strcpy(reinterpret_cast<char*>(this->pStart), reinterpret_cast<const char*>(str->pStart));

	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wscpy(reinterpret_cast<wchar_t*>(this->pStart), reinterpret_cast<const wchar_t*>(str->pStart));

	}
	else
	{
		cout << "���Ͳ�ƥ�䣬�������������" << endl;
	}

}
template <class T>
T KsoString<T>::operator [](int id)
{
	if (id < 0 || id >= this->length)
	{
		throw errorOutRange();
	}
	return this->pStart[id];
}

template <class T>
KsoString<T>::KsoString(const KsoString& str)
{
	//�������캯����Ҫ�ͷ�ԭ��������
	if (this->pStart != nullptr)
	{
		delete[] this->pStart;
	}
	this->length = 0;

	this->length = str.length;
	this->pStart = new T[this->length];

	if (strcmp(typeid(T).name(), "char") == 0)
	{
		strcpy(reinterpret_cast<char*>(this->pStart), reinterpret_cast<const char*>(str.pStart));

	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcscpy(reinterpret_cast<wchar_t*>(this->pStart), reinterpret_cast<const wchar_t*>(str.pStart));

	}
	else
	{
		cout << "���Ͳ�ƥ�䣬�������������" << endl;
	}
}

template <class T>
void KsoString<T>::show()
{
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		cout << reinterpret_cast<char*>(this->pStart) << endl;
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcout << reinterpret_cast<wchar_t*>(this->pStart) << endl;
	}
	else
	{
		cout << "���Ͳ�ƥ�䣬�������������" << endl;
	}
}

template <class T>
KsoString<T>::~KsoString()
{
	if (this->pStart != nullptr)
	{
		delete[] this->pStart;
	}
}


//���ض�����Ҫʵ���� KsoString<T>
template <class T>
KsoString<T> KsoString<T>::operator + (const KsoString& str)
{
	KsoString<T> strTemp;
	strTemp.length = this->length + str.length - 1;
	strTemp.pStart = new T[strTemp.length];
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		strcpy(reinterpret_cast<char*>(strTemp.pStart), reinterpret_cast<char*>(this->pStart));
		strcat(reinterpret_cast<char*>(strTemp.pStart), reinterpret_cast<const char*>(str.pStart));
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcscpy(reinterpret_cast<wchar_t*>(strTemp.pStart), reinterpret_cast<wchar_t*>(this->pStart));
		wcscat(reinterpret_cast<wchar_t*>(strTemp.pStart), reinterpret_cast<const wchar_t*>(str.pStart));
	}
	else
	{
		cout << "���Ͳ�ƥ�䣬�������������" << endl;
	}

	//����ÿ������캯��
	return strTemp;

}

template <class T>
void KsoString<T>::operator += (const KsoString& str)
{
	//"123"  4 "1234" 5
	this->length += (str.length - 1);//����

	T* temp = new T[this->length];
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		strcpy(reinterpret_cast<char*>(temp), reinterpret_cast<char*>(this->pStart));
		strcat(reinterpret_cast<char*>(temp), reinterpret_cast<const char*>(str.pStart));
		delete[] this->pStart;

		this->pStart = temp;//����
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcscpy(reinterpret_cast<wchar_t*>(temp), reinterpret_cast<wchar_t*>(this->pStart));
		wcscat(reinterpret_cast<wchar_t*>(temp), reinterpret_cast<const wchar_t*>(str.pStart));

		delete[] this->pStart;
		this->pStart = temp;//����

	}
	else
	{
		cout << "���Ͳ�ƥ�䣬�������������" << endl;
	}


}

template <class T>
ostream& operator <<(ostream& o, const KsoString<T>& str)
{
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		cout << reinterpret_cast<char*>(str.pStart);
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wcout << reinterpret_cast<wchar_t*>(str.pStart);
	}
	else
	{
		cout << "���Ͳ�ƥ�䣬�������������" << endl;
	}
	return o;
}

template <class T>
istream& operator >>(istream& i, KsoString<T>& str)
{
	if (strcmp(typeid(T).name(), "char") == 0)
	{
		char a[1000];
		cin >> a;
		delete[]str.pStart;
		str.length = strlen(reinterpret_cast<const char*>(a)) + 1;
		str.pStart = new T[str.length];
		strcpy(reinterpret_cast<char*>(str.pStart), reinterpret_cast<const char*>(a));
	}
	else if (strcmp(typeid(T).name(), "wchar_t") == 0)
	{
		wchar_t a[1000];
		wcin >> a;
		delete[]str.pStart;
		str.length = wcslen(reinterpret_cast<const wchar_t*>(a)) + 1;
		str.pStart = new T[str.length];
		wcscpy(reinterpret_cast<wchar_t*>(str.pStart), reinterpret_cast<const wchar_t*>(a));
	}
	else
	{
		cout << "���Ͳ�ƥ�䣬�������������" << endl;
	}
	return i;
}

int main()
{

	//KsoString<char> str1;
	//KsoString<wchar_t> str2;
	KsoString<char> str1("hello");
	KsoString<wchar_t> str2(L"world");
	KsoString<char> str3;
	cin >> str3;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str1 + str3 << endl;
	cout << str1[2] << endl;
	return 0;

}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
