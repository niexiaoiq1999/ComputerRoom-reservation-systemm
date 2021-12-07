#include"manager.h"
#include<string>
#include"globalFile.h"
#include<fstream>
#include<algorithm>


Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd=pwd;
	this->initVector();

	ifstream ifs;
	ComputerRoom computer;
	ifs.open(COMPUTER_FILE, ios::in);
	while (ifs >> computer.m_RoomNum && ifs >> computer.m_ComputerNum)
	{
		Com.push_back(computer);
	}
	cout << "��ǰ��������Ϊ" << Com.size() << endl;
	ifs.close();
}

void Manager::OpenMenu()
{
	cout << "��ӭ����Ա" <<this->m_Name<<"��¼��"<< endl;
	
	cout << "\t\t --------------------------\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      1.����˺�          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      2.�鿴�˺�          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      3.�鿴����          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      4.���ԤԼ          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      0.ע����¼          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t -------------------------- \n" << endl;
	cout << endl << " ��ѡ�����Ĳ�����" << endl;
}


void Manager::initVector()
{
	
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Stu.clear();
	Tea.clear();
	Com.clear();

	
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		Stu.push_back(s);
	}
	
	cout << "��ǰѧ������Ϊ" << Stu.size() << endl;
	ifs.close();

	Teacher t;
	ifs.open(TEACHER_FILE, ios::in);
	while (ifs >> t.m_empId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		Tea.push_back(t);
	}

	cout << "��ǰ��ʦ����Ϊ" << Tea.size() << endl;
	ifs.close();

	
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = Stu.begin(); it != Stu.end(); it++)
		{
			if (id ==it->m_Id)
			{
				return true;
			}
		}
	}
	else 
	{
		for (vector<Teacher>::iterator it = Tea.begin(); it != Tea.end(); it++)
		{
			if (id == it->m_empId)
			{
				return true;
			}
		}
	}
	return false;
}

void Manager::addPerson()
{
	 
		cout << "��ѡ����ӵ��˻���" << endl;
		cout << "1.ѧ����" << endl;
		cout << "2.��ʦ��" << endl;

		string tip;
		string FileName;
		string errorTip;

		ofstream ofs;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tip = "���������ѧ��ѧ�ţ�";
			FileName = STUDENT_FILE;
			errorTip = "ѧ���ظ�������������";
		}

		else if (select == 2)
		{
			tip = "�����������ʦְ���ţ�";
			FileName = TEACHER_FILE;
			errorTip = "ְ�����ظ�������������";
		}

		else
		{
			cout << "������������������" << endl;
			return;
		}
		int id;
		string name;
		string pwd;

		ofs.open(FileName, ios::out | ios::app);
		cout << tip << endl;
		while (true)
		{
			cin >> id;
			bool ref =this->checkRepeat(id, select);
			if (ref)
			{
				cout << errorTip << endl;
			}
			else
			{
				break;
			}
		}
		
		cout << "������������" << endl;
		cin >> name;
		cout << "���������룺" << endl;
		cin >> pwd;
		ofs << id << " " << name << " " << pwd<<" " << endl;
		cout << "��ӳɹ���" << endl;

		system("pause");
		system("cls");

		ofs.close();
		this->initVector();

}


void printStudent(Student &s)
{
		cout << "ѧ�ţ�" << s.m_Id << "  " << "������" << s.m_Name << "  " << "���룺" << s.m_Pwd << endl;
}
void printTeacher(Teacher &t)
{
		cout << "ְ���ţ�" << t.m_empId << "  " << "������" << t.m_Name << "  " << "���룺" << t.m_Pwd << endl;
}
void Manager::showPerson()
{

	cout << "����������Ҫ�鿴���ݣ�" << endl;
	cout << "1.����ѧ��" << endl;
	cout << "2.������ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ������Ϣ���£�" << endl;
		for_each(Stu.begin(), Stu.end(), printStudent);
	}
	else
	{
		cout << "������ʦ����Ϣ���£�" << endl;
		for_each(Tea.begin(), Tea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
void Manager::showCompuer()
{
	cout << "���л�������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = Com.begin(); it != Com.end(); it++)
	{
		cout << "�����ţ�" << it->m_RoomNum << "  ��������" << it->m_ComputerNum << endl;
	}
	system("pause");
	system("cls");
}
void Manager::cleanYu()
{
	ofstream ofs;
	ofs.open(YU_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}
