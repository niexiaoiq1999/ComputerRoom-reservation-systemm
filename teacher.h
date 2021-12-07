#pragma once
#include<iostream>
#include<string>
#include"Identity.h"
#include"YuFile.h"
#include<vector>

using namespace std;

class Teacher :public Identity
{
public:
	Teacher();
	Teacher(int empId, string name, string pwd);
	virtual void OpenMenu();
	void showYu();
	void validYu();
	int m_empId;

};