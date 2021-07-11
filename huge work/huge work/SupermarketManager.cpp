#include "SupermarketManager.h"
using namespace std;
vector<Commodity*> SupermarketManager::operator[](const string str)
{
	int i = 0;
	for(i=0;i<5;i++)
		if(a[i]==str)
			return com[i];
}

void SupermarketManager::init()
{
	string name;
	int id;
	double price;
	int num;
	while (name != "end")
	{
		cin >> name >> id >> price >> num;
		initdrinks(name, id, price, num);
	}
	while (name != "end")
	{
		cin >> name >> id >> price >> num;
		initpapers(name, id, price, num);
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
		cout << "���ƣ�";
		cin >> name;
		double price;
		cout << "�۸�";
		cin >> price;
		int id;
		cout << "id��";
		cin >> id;
		int num;
		cout << "������";
		cin >> num;
		for (auto c : com[i])
		{
			if (c->getname() == name)
			{
				c->num+=num;
				flag = 0;
			}
		}

		if (flag == 1)
		{
			com[i].push_back(new drinks(name, id, price,num));
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
	cout << endl;
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
			if (ve->getname() == name)
			{
				ve->num -= number;
				flag = 1;
				if (ve->num <= 0)
				{
					delete ve;
					ve = NULL;
				}
				cout << "ɾ���ɹ�������" << endl;
			}
		}
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
			if (com[i].empty())
			{
				cout << "������Ʒ������" << endl;
				break;
			}
			Sort(com[i]);
			show(com[i]);
			break;
		}
	if (i == 5)
		cout << "�����ڴ�����Ʒ��" << endl;
	if (!ifback())
		Search();
}

void SupermarketManager::SortAndOut()
{
	cout << ">>>>>>��Ʒ�������<<<<<" << endl;
	
	for (int i = 0; i < 5; i++)
		for (auto co : com[i])
			sorts.push_back(co);
	if (sorts.empty())
		cout << "��ƷΪ��" ;
	else if (sorts.size() == 1)
		cout<<"ֻ��һ������" << *sorts.begin();
	else
	{
		cout << "�������ͣ�1=�ɸߵ��ͣ�2=�ɵ͵��ߣ�:" << endl;
		int in;
		cin >> in;
		if (in == 1)
		{
			Sort(sorts);
			cout << *sorts.begin();
			if (sorts.size() != 1)
				for (vector<Commodity*>::iterator it = sorts.begin() + 1; it != sorts.end(); it++)
					cout << " > " << *it;
		}
		else if (in == 2)
		{
			Sort(sorts);
			cout << (sorts[sorts.size()-1]);
			for (int i= sorts.size() - 2;i>=0;i--)
				cout << " < " << sorts[i];
		}
		else
			cout << "���������" ;
	}
	sorts.clear();
	cout << endl;
	if (!ifback())
		SortAndOut();
	//cout << ">>>>>>��Ʒ�������<<<<<" << endl;
	//cout << "���ͣ�";
	//string type;
	//cin >> type;
	//for (int i = 0; i < 5; i++)
	//{
	//	if (a[i] == type)
	//	{
	//		cout << "�������ͣ�1=�ɸߵ��ͣ�2=�ɵ͵��ߣ�:" << endl;
	//		int in;
	//		cin >> in;
	//		if (in == 1)
	//		{
	//			rSort(com[i]);
	//			cout << *com[i].begin();
	//			for (vector<Commodity*>::iterator it = com[i].begin() + 1; it != com[i].end(); it++)
	//				cout << " > " << *it;
	//		}
	//		else if (in == 2)
	//		{
	//			Sort(com[i]);
	//			cout << *com[i].begin();
	//			for (vector<Commodity*>::iterator it = com[i].begin() + 1; it != com[i].end(); it++)
	//				cout << " < " << *it;
	//		}
	//		else
	//			cout << "���������" << endl;
	//	}
	//}
	//if (!ifback())
	//	SortAndOut();
}

void Quicksort(vector<Commodity*>& a, int low, int high)
{
	int i = low, j = high;
	if (i<j)
	{
		Commodity* key = a[i];
		while (j != i)
		{
			if (a[i] == key)
			{
				if (a[j]->getprice() > key->getprice())
				{
					a[i] = a[j];
					a[j] = key;
				}
				else
					j--;
			}
			else
			{
				if (a[i]->getprice() < key->getprice())
				{
					a[j] = a[i];
					a[i] = key;
				}
				else
					i++;
			}
		}

		Quicksort(a, 0, i-1);
		Quicksort(a, i+1, high);
	}
}


void SupermarketManager::Sort(vector<Commodity*>& com)
{
	int n = com.size();
	Quicksort(com, 0, n-1);
}

//void SupermarketManager::rSort(vector<Commodity*> com)
//{
//	vector<Commodity*>::iterator i = com.begin(), j = com.end();
//	Quicksort(com, i, j);
//
//}

void SupermarketManager::PriceNum5()
{
	for (int i = 0; i < 5; i++)
		for (auto co : com[i])
			sorts.push_back(co);
	if (sorts.empty())
		cout << "��ƷΪ��";
	else if (sorts.size() == 1)
		cout << *sorts.begin();
	else
	{
		Sort(sorts);
		cout << *sorts.begin();
		if (sorts.size() < 5)
		{
			cout << *sorts.begin();
			if (sorts.size() != 1)
				for (vector<Commodity*>::iterator it = sorts.begin() + 1; it != sorts.end(); it++)
					cout << " > " << *it;
			sorts.clear();
		}
		else
		{
			for (int i = 1; i < 5; i++)
				cout << ">" << sorts[i];
		}
	}
	cout << endl;
	if (!ifback())
		PriceNum5();
	sorts.clear();
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

