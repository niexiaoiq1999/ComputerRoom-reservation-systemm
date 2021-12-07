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
	cout << "当前机房数量为" << Com.size() << endl;
	ifs.close();
}

void Manager::OpenMenu()
{
	cout << "欢迎管理员" <<this->m_Name<<"登录！"<< endl;
	
	cout << "\t\t --------------------------\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      1.添加账号          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      2.查看账号          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      3.查看机房          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      4.清空预约          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      0.注销登录          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t -------------------------- \n" << endl;
	cout << endl << " 请选择您的操作：" << endl;
}


void Manager::initVector()
{
	
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
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
	
	cout << "当前学生数量为" << Stu.size() << endl;
	ifs.close();

	Teacher t;
	ifs.open(TEACHER_FILE, ios::in);
	while (ifs >> t.m_empId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		Tea.push_back(t);
	}

	cout << "当前老师数量为" << Tea.size() << endl;
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
	 
		cout << "请选择添加的账户：" << endl;
		cout << "1.学生：" << endl;
		cout << "2.老师：" << endl;

		string tip;
		string FileName;
		string errorTip;

		ofstream ofs;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tip = "请输入添加学生学号：";
			FileName = STUDENT_FILE;
			errorTip = "学号重复，请重新输入";
		}

		else if (select == 2)
		{
			tip = "请输入添加老师职工号：";
			FileName = TEACHER_FILE;
			errorTip = "职工号重复，请重新输入";
		}

		else
		{
			cout << "输入有误，请重新输入" << endl;
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
		
		cout << "请输入姓名：" << endl;
		cin >> name;
		cout << "请输入密码：" << endl;
		cin >> pwd;
		ofs << id << " " << name << " " << pwd<<" " << endl;
		cout << "添加成功！" << endl;

		system("pause");
		system("cls");

		ofs.close();
		this->initVector();

}


void printStudent(Student &s)
{
		cout << "学号：" << s.m_Id << "  " << "姓名：" << s.m_Name << "  " << "密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher &t)
{
		cout << "职工号：" << t.m_empId << "  " << "姓名：" << t.m_Name << "  " << "密码：" << t.m_Pwd << endl;
}
void Manager::showPerson()
{

	cout << "请输入您想要查看内容：" << endl;
	cout << "1.所有学生" << endl;
	cout << "2.所有老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生的信息如下：" << endl;
		for_each(Stu.begin(), Stu.end(), printStudent);
	}
	else
	{
		cout << "所有老师的信息如下：" << endl;
		for_each(Tea.begin(), Tea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
void Manager::showCompuer()
{
	cout << "所有机房的信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = Com.begin(); it != Com.end(); it++)
	{
		cout << "机房号：" << it->m_RoomNum << "  电脑数：" << it->m_ComputerNum << endl;
	}
	system("pause");
	system("cls");
}
void Manager::cleanYu()
{
	ofstream ofs;
	ofs.open(YU_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}
