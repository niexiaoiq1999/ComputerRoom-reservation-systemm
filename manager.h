#pragma once
#include<iostream>
#include"Identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"CompuerRoom.h"

using namespace std;

class Manager :public Identity
{
public:
	Manager();
	Manager(string name, string pwd);
	virtual void OpenMenu();
	void addPerson();
	void showPerson();
	void showCompuer();
	void cleanYu();
	void initVector();
	vector<Student>Stu;
	vector<Teacher>Tea;
	bool checkRepeat(int id, int type);
	vector<ComputerRoom>Com;

};
