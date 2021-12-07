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
	cout << "欢迎教师" << this->m_Name << "登录！" << endl;

	cout << "\t\t --------------------------\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      1.查看所有预约      |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      2.审核预约          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t|      0.注销登录          |\n" << endl;
	cout << "\t\t|                          |\n" << endl;
	cout << "\t\t -------------------------- \n" << endl;
	cout << endl << " 请选择您的操作：" << endl;
}

void Teacher::showYu()
{
	YuFile yu;
	if (yu.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout <<  " 所有预约记录如下：" << endl;
	for (int i = 0; i < yu.m_Size; i++)
	{
		cout << i + 1 << "、";
		//studenID:1 studenName : 1 chooseDate : 3 chooseTime : 2 chooseRoom : 2 status : 1
		cout << "学号：" << yu.YuMap[i]["chooseTime"] << "  ";
		cout << "姓名：" << yu.YuMap[i]["chooseTime"] << "  ";
		cout << "预约日期：周" << yu.YuMap[i]["chooseDate"] << "  ";
		cout << "预约时间：" << (yu.YuMap[i]["chooseTime"]=="1"?"上午":"下午") << "  ";
		cout << "预约房间号：" << yu.YuMap[i]["chooseRoom"] << "  ";
		string status = "状态：";
		if (yu.YuMap[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (yu.YuMap[i]["status"] == "2")
		{
			status += "审核成功";
		}
		else if (yu.YuMap[i]["status"] == "-1")
		{
			status += "未审核成功";
		}
		else
		{
			status += "取消预约";
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的学生的预约记录如下：" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < yu.m_Size; i++)
	{
		if (yu.YuMap[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index<< "、";
			//studenID:1 studenName : 1 chooseDate : 3 chooseTime : 2 chooseRoom : 2 status : 1
			cout << "学号：" << yu.YuMap[i]["chooseTime"] << "  ";
			cout << "姓名：" << yu.YuMap[i]["chooseTime"] << "  ";
			cout << "预约日期：周" << yu.YuMap[i]["chooseDate"] << "  ";
			cout << "预约时间：" << (yu.YuMap[i]["chooseTime"] == "1" ? "上午" : "下午") << "  ";
			cout << "预约房间号：" << yu.YuMap[i]["chooseRoom"] << "  ";
			string status = "状态：审核中";
			cout << status << endl;
		}
	}
	int select = 0;
	int ref = 0;
	cout << "请选择您要审核的学生的预约记录,按0可返回" << endl;
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
				cout << "请选择您的操作：" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
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
				cout << "审核完毕" << endl;
				break;
			}
			
    	}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}
