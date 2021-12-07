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
	cout << "欢迎学生" << this->m_Name << "登录！" << endl;

	cout << "\t\t -------------------------------\n" << endl;
	cout << "\t\t|                              |\n" << endl;
	cout << "\t\t|      1.申请预约              |\n" << endl;
	cout << "\t\t|                              |\n" << endl;
	cout << "\t\t|      2.查看我的预约          |\n" << endl;
	cout << "\t\t|                              |\n" << endl;
	cout << "\t\t|      3.查看所有预约          |\n" << endl;
	cout << "\t\t|                              |\n" << endl;
	cout << "\t\t|      4.取消预约              |\n" << endl;
	cout << "\t\t|                              |\n" << endl;
	cout << "\t\t|      0.注销登录              |\n" << endl;
	cout << "\t\t|                              |\n" << endl;
	cout << "\t\t ------------------------------ \n" << endl;
	cout << endl << " 请选择您的操作：" << endl;
}

void Student::showMyYu()
{
	YuFile yu;
	if (yu.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
    }
//studenID:1 studenName : 1 chooseDate : 3 chooseTime : 2 chooseRoom : 2 status : 1
	else
	{
		cout<< "您的预约记录如下：" << endl;

		for (int i = 0; i < yu.m_Size; i++)
		{
			if (this->m_Id == atoi(yu.YuMap[i]["studenID"].c_str()))
			{
				cout << "预约日期：周" << yu.YuMap[i]["chooseDate"] <<
					"  预约时间：" << (yu.YuMap[i]["chooseTime"] == "1" ? "上午" : "下午")
					<< "  预约机房：" << yu.YuMap[i]["chooseRoom"];
				string status="  状态：";
				if (yu.YuMap[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (yu.YuMap[i]["status"] == "2")
				{
					status += "通过审核";
				}
				else if (yu.YuMap[i]["status"] == "-1")
				{
					status += "未通过审核";
				}
				else
				{
					status += "取消预约";
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "所有预约记录如下：" << endl;
	for (int i = 0; i < yu.m_Size; i++)
	{
	//studenID:1 studenName : 1 chooseDate : 3 chooseTime : 2 chooseRoom : 2 status : 1
		cout << i + 1 << "、 ";
		cout << "学号：" << yu.YuMap[i]["studenID"]
			<< "  姓名：" << yu.YuMap[i]["studenName"]
			<< "  预约日期：周" << yu.YuMap[i]["chooseDate"]
			<< "  预约时间：" << (yu.YuMap[i]["chooseTime"] == "1" ? "上午" : "下午")
			<< "  房间：" << yu.YuMap[i]["chooseRoom"];
		string status = "  状态：";
		if (yu.YuMap[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (yu.YuMap[i]["status"] == "2")
		{
			status += "通过审核";
		}
		else if (yu.YuMap[i]["status"] == "-1")
		{
			status += "未通过审核";
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

void Student::applyYu()
{
	cout << "您正在预约机房" << endl;
	cout << "机房信息如下：" << endl;
	cout << "机房号：" << sCom[0].m_RoomNum << "容量：" << sCom[0].m_ComputerNum << endl;
	cout << "机房号：" << sCom[1].m_RoomNum << "容量：" << sCom[1].m_ComputerNum << endl;
	cout << "机房号：" << sCom[2].m_RoomNum << "容量：" << sCom[2].m_ComputerNum << endl;

	cout << "请输入您选择的机房号：" << endl;
	int chooseRoom = 0;
	cin >> chooseRoom;
	while (true)
	{
		if (chooseRoom >= 1 && chooseRoom <= 3)
		{

			break;
		}
		cout << "您的输入有误，请重新输入" << endl;
	}
     cout << "请输入您选择的预约日期：" << endl;
	 cout << "1.周一：" << endl;
	 cout << "2.周二：" << endl;
 	 cout << "3.周三：" << endl;
	 cout << "4.周四：" << endl;
	 cout << "5.周五：" << endl;
	int chooseDate = 0;
	cin >> chooseDate;
	while (true)
	{
		if (chooseDate >= 1 || chooseDate <= 5)
		{
			break;
		}
		cout << "您的输入有误，请重新输入" << endl;
	}
	
	cout << "请输入您选择的预约时间：" << endl;
	cout << "1.上午：" << endl;
	cout << "2.下午：" << endl;
	int chooseTime = 0;
	cin >> chooseTime;
	while (true)
	{
		if (chooseTime >= 1 || chooseTime<=2)
		{
			break;
		}
		cout << "您的输入有误，请重新输入" << endl;
	}
					
	cout << "已提交预约，等待审核" << endl;
	
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "您预约记录如下，审核中和审核成功的预约可以取消：" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < yu.m_Size; i++)
	{
		if (this->m_Id == atoi(yu.YuMap[i]["studenID"].c_str()))
		{
			if (yu.YuMap[i]["status"] == "1" || yu.YuMap[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << yu.YuMap[i]["chooseDate"] << "  ";
				cout << "预约时间：" << (yu.YuMap[i]["chooseTime"] == "1" ? "上午" : "下午") << "  ";
				cout << "预约机房号：" << yu.YuMap[i]["chooseRoom"] << "  ";
				string status = "状态：";
				if (yu.YuMap[i]["status"] == "1")
				{
					status += "审核中";
				}
				else
				{
					status += "审核成功";
				}
				cout << status << endl;
			}
		}	
	}
	cout << "请输入您需要取消的预约记录，按0可以返回：" << endl;
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
				cout << "取消预约成功！" << endl;
				break;
			}

		}
		cout << "您的输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}