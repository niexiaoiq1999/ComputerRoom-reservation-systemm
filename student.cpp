#include"student.h"
#include<fstream>
#include<algorithm>
#include"YuFile.h"


Student::Student()
{
	
}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ComputerRoom cr;
	ifstream ifs(COMPUTER_FILE, ios::in);
	while (ifs >> cr.m_RoomNum && ifs >> cr.m_ComputerNum)
	{
		sCom.push_back(cr);
	}
	ifs.close();

}

void Student::OpenMenu()
{
	cout << "��ӭѧ��" << this->m_Name << "��¼��" << endl;

	cout << "\t\t -------------------------------\n" << endl;
	cout << "\t\t|                              |\n" << endl;
	cout << "\t\t|      1.����ԤԼ              |\n" << endl;
	cout << "\t\t|                              |\n" << endl;
	cout << "\t\t|      2.�鿴�ҵ�ԤԼ          |\n" << endl;
	cout << "\t\t|                              |\n" << endl;
	cout << "\t\t|      3.�鿴����ԤԼ          |\n" << endl;
	cout << "\t\t|                              |\n" << endl;
	cout << "\t\t|      4.ȡ��ԤԼ              |\n" << endl;
	cout << "\t\t|                              |\n" << endl;
	cout << "\t\t|      0.ע����¼              |\n" << endl;
	cout << "\t\t|                              |\n" << endl;
	cout << "\t\t ------------------------------ \n" << endl;
	cout << endl << " ��ѡ�����Ĳ�����" << endl;
}

void Student::showMyYu()
{
	YuFile yu;
	if (yu.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
    }
//studenID:1 studenName : 1 chooseDate : 3 chooseTime : 2 chooseRoom : 2 status : 1
	else
	{
		cout<< "����ԤԼ��¼���£�" << endl;

		for (int i = 0; i < yu.m_Size; i++)
		{
			if (this->m_Id == atoi(yu.YuMap[i]["studenID"].c_str()))
			{
				cout << "ԤԼ���ڣ���" << yu.YuMap[i]["chooseDate"] <<
					"  ԤԼʱ�䣺" << (yu.YuMap[i]["chooseTime"] == "1" ? "����" : "����")
					<< "  ԤԼ������" << yu.YuMap[i]["chooseRoom"];
				string status="  ״̬��";
				if (yu.YuMap[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (yu.YuMap[i]["status"] == "2")
				{
					status += "ͨ�����";
				}
				else if (yu.YuMap[i]["status"] == "-1")
				{
					status += "δͨ�����";
				}
				else
				{
					status += "ȡ��ԤԼ";
				}
				cout << status << endl;
			}
			
		}

	}
	system("pause");
	system("cls");
}

void Student::showAllYu()
{
	YuFile yu;
	if (yu.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����ԤԼ��¼���£�" << endl;
	for (int i = 0; i < yu.m_Size; i++)
	{
	//studenID:1 studenName : 1 chooseDate : 3 chooseTime : 2 chooseRoom : 2 status : 1
		cout << i + 1 << "�� ";
		cout << "ѧ�ţ�" << yu.YuMap[i]["studenID"]
			<< "  ������" << yu.YuMap[i]["studenName"]
			<< "  ԤԼ���ڣ���" << yu.YuMap[i]["chooseDate"]
			<< "  ԤԼʱ�䣺" << (yu.YuMap[i]["chooseTime"] == "1" ? "����" : "����")
			<< "  ���䣺" << yu.YuMap[i]["chooseRoom"];
		string status = "  ״̬��";
		if (yu.YuMap[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (yu.YuMap[i]["status"] == "2")
		{
			status += "ͨ�����";
		}
		else if (yu.YuMap[i]["status"] == "-1")
		{
			status += "δͨ�����";
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

void Student::applyYu()
{
	cout << "������ԤԼ����" << endl;
	cout << "������Ϣ���£�" << endl;
	cout << "�����ţ�" << sCom[0].m_RoomNum << "������" << sCom[0].m_ComputerNum << endl;
	cout << "�����ţ�" << sCom[1].m_RoomNum << "������" << sCom[1].m_ComputerNum << endl;
	cout << "�����ţ�" << sCom[2].m_RoomNum << "������" << sCom[2].m_ComputerNum << endl;

	cout << "��������ѡ��Ļ����ţ�" << endl;
	int chooseRoom = 0;
	cin >> chooseRoom;
	while (true)
	{
		if (chooseRoom >= 1 && chooseRoom <= 3)
		{

			break;
		}
		cout << "����������������������" << endl;
	}
     cout << "��������ѡ���ԤԼ���ڣ�" << endl;
	 cout << "1.��һ��" << endl;
	 cout << "2.�ܶ���" << endl;
 	 cout << "3.������" << endl;
	 cout << "4.���ģ�" << endl;
	 cout << "5.���壺" << endl;
	int chooseDate = 0;
	cin >> chooseDate;
	while (true)
	{
		if (chooseDate >= 1 || chooseDate <= 5)
		{
			break;
		}
		cout << "����������������������" << endl;
	}
	
	cout << "��������ѡ���ԤԼʱ�䣺" << endl;
	cout << "1.���磺" << endl;
	cout << "2.���磺" << endl;
	int chooseTime = 0;
	cin >> chooseTime;
	while (true)
	{
		if (chooseTime >= 1 || chooseTime<=2)
		{
			break;
		}
		cout << "����������������������" << endl;
	}
					
	cout << "���ύԤԼ���ȴ����" << endl;
	
	ofstream ofs(YU_FILE, ios::app);
	ofs << "studenID:"<< this->m_Id << " ";
	ofs << "studenName:" << this->m_Name << " ";
	ofs << "chooseDate:" << chooseDate << " ";
	ofs << "chooseTime:" << chooseTime << " ";
	ofs << "chooseRoom:" << chooseRoom << " ";
	ofs << "status:" <<1 <<" "<< endl;
	ofs.close();
	system("pause");
	system("cls");

}


void Student::cancelYu()
{
	YuFile yu;
	if (yu.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��ԤԼ��¼���£�����к���˳ɹ���ԤԼ����ȡ����" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < yu.m_Size; i++)
	{
		if (this->m_Id == atoi(yu.YuMap[i]["studenID"].c_str()))
		{
			if (yu.YuMap[i]["status"] == "1" || yu.YuMap[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << yu.YuMap[i]["chooseDate"] << "  ";
				cout << "ԤԼʱ�䣺" << (yu.YuMap[i]["chooseTime"] == "1" ? "����" : "����") << "  ";
				cout << "ԤԼ�����ţ�" << yu.YuMap[i]["chooseRoom"] << "  ";
				string status = "״̬��";
				if (yu.YuMap[i]["status"] == "1")
				{
					status += "�����";
				}
				else
				{
					status += "��˳ɹ�";
				}
				cout << status << endl;
			}
		}	
	}
	cout << "����������Ҫȡ����ԤԼ��¼����0���Է��أ�" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				yu.YuMap[v[select - 1]]["status"] = "0";
				yu.updateFile();
				cout << "ȡ��ԤԼ�ɹ���" << endl;
				break;
			}

		}
		cout << "����������������������" << endl;
	}
	system("pause");
	system("cls");
}