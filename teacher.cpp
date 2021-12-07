#include"teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_empId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::OpenMenu()
{
	cout << "��ӭ��ʦ" << this->m_Name << "��¼��" << endl;

	cout << "\t\t --------------------------\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      1.�鿴����ԤԼ      |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      2.���ԤԼ          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      0.ע����¼          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t -------------------------- \n" << endl;
	cout << endl << " ��ѡ�����Ĳ�����" << endl;
}

void Teacher::showYu()
{
	YuFile yu;
	if (yu.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout <<  " ����ԤԼ��¼���£�" << endl;
	for (int i = 0; i < yu.m_Size; i++)
	{
		cout << i + 1 << "��";
		//studenID:1 studenName : 1 chooseDate : 3 chooseTime : 2 chooseRoom : 2 status : 1
		cout << "ѧ�ţ�" << yu.YuMap[i]["chooseTime"] << "  ";
		cout << "������" << yu.YuMap[i]["chooseTime"] << "  ";
		cout << "ԤԼ���ڣ���" << yu.YuMap[i]["chooseDate"] << "  ";
		cout << "ԤԼʱ�䣺" << (yu.YuMap[i]["chooseTime"]=="1"?"����":"����") << "  ";
		cout << "ԤԼ����ţ�" << yu.YuMap[i]["chooseRoom"] << "  ";
		string status = "״̬��";
		if (yu.YuMap[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (yu.YuMap[i]["status"] == "2")
		{
			status += "��˳ɹ�";
		}
		else if (yu.YuMap[i]["status"] == "-1")
		{
			status += "δ��˳ɹ�";
		}
		else
		{
			status += "ȡ��ԤԼ";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::validYu()
{
	YuFile yu;
	if (yu.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ѧ����ԤԼ��¼���£�" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < yu.m_Size; i++)
	{
		if (yu.YuMap[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index<< "��";
			//studenID:1 studenName : 1 chooseDate : 3 chooseTime : 2 chooseRoom : 2 status : 1
			cout << "ѧ�ţ�" << yu.YuMap[i]["chooseTime"] << "  ";
			cout << "������" << yu.YuMap[i]["chooseTime"] << "  ";
			cout << "ԤԼ���ڣ���" << yu.YuMap[i]["chooseDate"] << "  ";
			cout << "ԤԼʱ�䣺" << (yu.YuMap[i]["chooseTime"] == "1" ? "����" : "����") << "  ";
			cout << "ԤԼ����ţ�" << yu.YuMap[i]["chooseRoom"] << "  ";
			string status = "״̬�������";
			cout << status << endl;
		}
	}
	int select = 0;
	int ref = 0;
	cout << "��ѡ����Ҫ��˵�ѧ����ԤԼ��¼,��0�ɷ���" << endl;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= yu.m_Size)
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��ѡ�����Ĳ�����" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> ref;
				if (ref == 1)
				{
					yu.YuMap[v[select - 1]]["status"] = "2";
				}
				else
				{
					yu.YuMap[v[select - 1]]["status"] = "-1";
				}
				yu.updateFile();
				cout << "������" << endl;
				break;
			}
			
    	}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}
