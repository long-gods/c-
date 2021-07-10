#include "SupermarketManager.h"
using namespace std;
vector<Commodity*> SupermarketManager::operator[](const string str)
{
	int i = 0;
	for(i=0;i<5;i++)
		if(a[i]==str)
			return com[i];
}
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

void SupermarketManager::show(vector<Commodity*> com)
{
	cout << *com.begin();
	for (vector<Commodity*>::iterator it = com.begin()+1; it != com.end(); it++)
		cout<<" , " << *it;
}


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
	if (!ifback())
		del();
}

void SupermarketManager::changeinfor()
{
	cout << ">>>>>>�޸���Ʒ<<<<<" << endl;
	cout << "���ƣ�";
	string name;
	cin >> name;
	for(int i=0;i<5;i++)
		for(auto co:com[i])
			if (co->getname() == name)
			{
				cout << " �޸��1 = �۸�2 = ��������";
				int choice;
				cin >> choice;
				if (choice == 1)
				{
					cout << "�¼۸�";
					double newp;
					cin >> newp;
					co->newprice(newp);
					cout << "�۸��޸ĳɹ�" << endl;
				}
				else if (choice == 2)
				{
					cout << "��������";
					string newd;
					cin >> newd;
					co->newdescribe(newd);
					cout << "�����޸ĳɹ�" << endl;
				}
				else
					cout << "�������" << endl;
			}
	if (!ifback())
		changeinfor();
}

void SupermarketManager::Search()
{
	cout << ">>>>>>��Ʒ��Ϣ����<<<<<" << endl;
	cout << "���ͣ�";
	string type;
	int i = 0;
	cin >> type;
	for(i=0;i<5;i++)
		if (a[i] == type)
		{
			rSort(com[i]);
			show(com[i]);
		}
	if (i == 5)
		cout << "�����ڴ�����Ʒ��" << endl;
	if (!ifback())
		Search();
}

void SupermarketManager::SortAndOut()
{
	cout << ">>>>>>��Ʒ�������<<<<<" << endl;
	cout << "���ͣ�";
	string type;
	cin >> type;
	for (int i = 0; i < 5; i++)
	{
		if (a[i] == type)
		{
			cout << "�������ͣ�1=�ɸߵ��ͣ�2=�ɵ͵��ߣ�:" << endl;
			int in;
			cin >> in;
			if (in == 1)
			{
				rSort(com[i]);
				cout << *com[i].begin();
				for (vector<Commodity*>::iterator it = com[i].begin() + 1; it != com[i].end(); it++)
					cout << " > " << *it;
			}
			else if (in == 2)
			{
				Sort(com[i]);
				cout << *com[i].begin();
				for (vector<Commodity*>::iterator it = com[i].begin() + 1; it != com[i].end(); it++)
					cout << " < " << *it;
			}
			else
				cout << "���������" << endl;
		}
	}
	if (!ifback())
		SortAndOut();
	//cout << ">>>>>>��Ʒ�������<<<<<" << endl;
	//cout << "�������ͣ�1=�ɸߵ��ͣ�2=�ɵ͵��ߣ�:";
	// int in;
	//cin >> in;
	//for (int i = 0; i < 5; i++)
	//{
	// 	   for(auto co:com[i])
	//		if (a[i] == type)
	//			{
	//				int in;
	//				cin >> in;
	//				if (in == 1)
	//				{
	//					rSort(com[i]);
	//					show(com[i]);
	//				}
	//		else if (in == 2)
	//		{
	//			Sort(com[i]);
	//			show(com[i]);
	//		}
	//		else
	//			cout << "���������" << endl;
	//	}
	//}
	//if (!ifback())
	//	SortAndOut();
}

void SupermarketManager::Sort(vector<Commodity*> com)
{
	sort(com.begin(), com.end());
}

void SupermarketManager::rSort(vector<Commodity*> com)
{
	sort(com.rbegin(), com.rend());
}

void SupermarketManager::PriceNum5()
{
	for (int i = 0; i < 5; i++)
		rSort(com[i]);

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
