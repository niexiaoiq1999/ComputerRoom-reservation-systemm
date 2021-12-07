#pragma once
#include<iostream>
#include<string>
#include"Identity.h"
#include"CompuerRoom.h"
#include"globalFile.h"
#include<vector>

using namespace std;
class Student:public Identity
{
public:
	Student();
	Student(int id,string name,string pwd);
	virtual void OpenMenu();
	void applyYu();
	void showMyYu();
	void showAllYu();
	void cancelYu();
	int m_Id;
	vector<ComputerRoom>sCom;
	

};

