#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <cstdlib>
#include "KsoString.h"




int main()
{

	//KsoString<char> str1;
	//KsoString<wchar_t> str2;
	KsoString<char> str1("hello");
	KsoString<wchar_t> str2(L"world");
	KsoString<char> str3("world");
	str1.show();
	cout << str1.getlength() << endl;
	cout << str1[0] << endl;
	str2.show();
	cout << str2.getlength() << endl;
	wcout << str2[3] << endl;
	str3 = str1;
	str3.show();
	KsoString<char> str4(str3);
	str4.show();
	return 0;

}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ��������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б����ڲ鿴����
//   5. ת������Ŀ��>����������Դ����µĴ����ļ�����ת������Ŀ��>������������Խ����д����ļ����ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
//template<class T>
//KsoString<T> operator+(const KsoString<T>& str1, const KsoString<T>& str2)
//{
//	node<T>* p = m_node;
//	while (p->next != NULL)
//	{
//		p = p->next;
//	}
//	p->next = str.m_node;
//	return *this;
//	}
//	KsoString<T> kso;
//	return KsoString();
//}