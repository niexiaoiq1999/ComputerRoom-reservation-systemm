#pragma once
#include<iostream>
#include<string>
#include<map>
#include"globalFile.h"
#include<fstream>

using namespace std;

class YuFile
{
public:
	YuFile();
	map<int, map<string, string>>YuMap;
	void updateFile();
	int m_Size;

	
};
