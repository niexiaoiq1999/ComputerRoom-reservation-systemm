#include<ostream>
#include<iostream>
#include<fstream>
#include<string>
#include"Identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include"YuFile.h"


using namespace std;

void ManagerMenu(Identity*& manager)
{
	while (true)
	{
		manager->OpenMenu();
		Manager* man = (Manager*)manager;

		int select=0;

		cin >> select;

		if (select == 1)
		{
			man->addPerson();
			
		}
		else if (select == 2)
		{
			man->showPerson();
		}
		else if (select == 3)
		{
			man->showCompuer();
		}
		else if (select == 4)
		{
			man->cleanYu();
		}
		else
		{
			delete manager;
			cout << "注销登录" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void StudentMenu(Identity*& student)
{
	while (true)
	{
		student->OpenMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			stu->applyYu();
		}
		else if (select == 2)
		{
			stu->showMyYu();
			
		}
		else if (select == 3)
		{
			stu->showAllYu();
		}
		else if (select == 4)
		{
			stu->cancelYu();
		}
		else 
		{
			delete student;
			cout << "注销登录" << endl;
			system("pause");
			system("cls");
			return;
		}
		
	}
}

void TeacherMenu(Identity*& teacher)
{
	
	while (true)
	{
		teacher->OpenMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tea->showYu();
		}
		else if (select == 2)
		{
			tea->validYu();
		}
		else
		{
			delete teacher;
			cout << "注销登录" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	

}

void LoginIN(string fileName, int type)
{
	Identity* person = NULL;
	
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
			cout << "请输入您的学号：" << endl;
			cin>>id;

	}
	else if (type == 2)
		{
			cout << "请输入您的职工号：" << endl;
			cin>>id;
		}

		cout << "请输入您的账户：" << endl;
		cin >> name;
		cout << "请输入您的密码" << endl;
		cin >> pwd;

	if (type == 1)
		{
		int stuId;
		string stuName;
		string stuPwd;
		while (ifs >> stuId && ifs >> stuName && ifs>> stuPwd)
			if (id == stuId && name == stuName && pwd == stuPwd)
			{
				cout << "登陆验证成功" << endl;
				
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				StudentMenu(person);
				return;
			}

		}
	else if (type == 2)
		{
		int teaId;
		string teaName;
		string teaPwd;
		while (ifs >> teaId && ifs >> teaName && ifs >> teaPwd)
		{
			if (id == teaId && name == teaName && pwd == teaPwd)
			{
				cout << "登陆验证成功" << endl;
				
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;

			}
		}

		}
	else if (type == 3)
		{
		string manaName;
		string manaPwd;
		while (ifs >> manaName && ifs >> manaPwd)
		{
			if (name == manaName && pwd == manaPwd)
			{
				cout << "登陆验证成功" << endl;
			
				
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				ManagerMenu(person);
				return;
			}
		}
		}
		cout << "登陆验证失败" << endl;
		system("pause");
		system("cls");
		return;

}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "===================欢迎进入机房预约系统=============" << endl;
		cout << endl<<" 请选择您的身份：" << endl;
		cout << "\t\t -----------------------\n" << endl;
		cout << "\t\t|                      |\n" << endl;
		cout << "\t\t|      1.学生          |\n" << endl;
		cout << "\t\t|                      |\n" << endl;
		cout << "\t\t|      2.老师          |\n" << endl;
		cout << "\t\t|                      |\n" << endl;
		cout << "\t\t|      3.管理员        |\n" << endl;
		cout << "\t\t|                      |\n" << endl;
		cout << "\t\t|      0.退出          |\n" << endl;
		cout << "\t\t|                      |\n" << endl;
		cout << "\t\t ---------------------- \n" << endl;
		cout << " 请输入您的选择：" << endl;
		cin >> select;
	switch (select)
		{
		case 1:
			LoginIN(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIN(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIN(MANAGER_FILE, 3);
			break;
		case 0:
			cout << " 欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "您的输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	
	}
	system("pause");
	return 0;
}