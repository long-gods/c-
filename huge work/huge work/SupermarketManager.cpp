#include "SupermarketManager.h"
using namespace std;
void SupermarketManager::menu()
{
	int num = 1;
	while (num)
	{
		cout << "1��������Ʒ��Ϣ" << endl;
		cout << "2��ɾ����Ʒ��Ϣ" << endl;
		cout << "3���޸���Ʒ��Ϣ��ps�����簴Id�޸ļ۸������ȣ�" << endl;
		cout << "4����Ʒ��Ϣ����" << endl;
		cout << "5����Ʒ���۸��������" << endl;
		cout << "6������۸�ǰ�����Ʒ" << endl;
		cout << "0���˳�" << endl;
		cout << "��ѡ����(0 - 6)��" << endl;
		cin >> num;
		switch (num) {
		case 0:break; break;
		case 1:add(); break;
		case 2:del(); break;
		case 3:changeinfor(); break;
		case 4:Search(); break;
		case 5:SortAndOut(); break;
		case 6:PriceNum5(); break;
		}
	}
}
void SupermarketManager::add()
{
	cout << ">>>>>>������Ʒ<<<<<<" << endl;
	int flag = 0,i=0;
	string obj;
	cout << "���ͣ�";
	cin >> obj;
	for (i = 0; i < 5; i++)
	{
		if (a[i] == obj)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		string name;
		int i = 0, flag = 0;
		cout << "���ƣ�";
		cin >> name;
		double price;
		cout << "�۸�";
		cin >> price;
		int id;
		cout << "id��";
		cin >> id;
		for (auto c : com[i])
		{
			if (c->getname() == name)
			{
				c->num++;
				flag = 1;
			}
		}

		if (flag == 0)
		{
			com[i].push_back(new drinks(name, id, price));
		}
		cout << "��Ʒ��ӳɹ�" << endl;
		if (!ifback())
			add();
	}
	else
		cout << "û����������" << endl;
}

//void SupermarketManager::adddrinks()
//{
//	string name;
//	int i = 0,flag=0;
//	cout << "���ƣ�";
//	cin >> name;
//	double price;
//	cout << "�۸�";
//	cin >> price;
//	int id;
//	cout << "id��";
//	cin >> id;
//	for (auto dr:dri)
//	{
//		if (dr->getname() == name)
//		{
//			dr->addnum();
//			flag = 1;
//		}
//	}
//
//	if (flag == 0)
//	{
//		dri.push_back(new drinks(name,id,price));
//	}
//	cout << "��Ʒ��ӳɹ�" << endl;
//	if (!ifback())
//		add();
//}

//void SupermarketManager::show()
//{
//	Sort();
//	cout << *dri.begin();
//	for (vector<drinks*>::iterator it = dri.begin()+1; it != dri.end(); it++)
//		cout<<" , " << *it;
//}

void SupermarketManager::del()
{
	cout << ">>>>>>ɾ����Ʒ<<<<<<" << endl;
	cout << "���ͣ�";
	string type;
	int i = 0;
	cin >> type;
	while (a[i] != type) {
		i++;
		if (i == 5)
			break;
	}
	if (i == 5)
		cout << "û���������ͣ�"<<endl;
	else
	{
		int flag = 0;
		cout << "ɾ����Ʒ���������磺���ϼ� 2����";
		string name;
		int number;

		cin >> name >> number;
		for (auto ve : com[i])
		{
			if (ve->getname() == name && ve->num >= number)
			{
				ve->num -= number;
				flag = 1;
				if (ve->num == 0)
				{
					delete ve;
					ve = NULL;
				}
			}
		}
		if (flag == 0)
			cout << "ɾ��ʧ�ܣ�����" << endl;
		else
			cout << "ɾ���ɹ�������" << endl;
		if (ifback())
			menu();
		else
			del();
		
	}

}

void SupermarketManager::changeinfor()
{
	cout << ">>>>>>�޸���Ʒ<<<<<" << endl;
	cout << "���ƣ�";
	string name;
	cin >> name;

}

//void SupermarketManager::Sort()
//{
//	sort(dri.begin(), dri.end());
//}

bool SupermarketManager::ifback()
{
	cout << "�Ƿ񷵻����˵���y���أ�n�˳�����";
	char in;
	cin >> in;
	if (in == 'y')
		return true;
	else if (in == 'n')
		return false;
	else
		ifback();		
}
