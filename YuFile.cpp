#include"YuFile.h"


YuFile::YuFile()
{
	ifstream ifs(YU_FILE, ios::in);
	string studenID;
	string studenName;
	string chooseDate;
	string chooseTime;
	string chooseRoom;
	string status;
	this->m_Size = 0;
	while (ifs >> studenID && ifs >> studenName && ifs >> chooseDate && ifs >> chooseTime && ifs >> chooseRoom && ifs >> status)
	{
		
		string key;
		string stay;
		map<string, string>m;
		int Pos = studenID.find(":");
		if (Pos != -1)
		{
			key = studenID.substr(0, Pos);
			stay = studenID.substr(Pos + 1, studenID.size() - Pos - 1);
			m.insert(make_pair(key, stay));
		}

		 Pos = studenName.find(":");
		if (Pos != -1)
		{
			key = studenName.substr(0, Pos);
			stay = studenName.substr(Pos + 1, studenName.size() - Pos - 1);
			m.insert(make_pair(key, stay));
		}

		Pos = chooseDate.find(":");
		if (Pos != -1)
		{
			key = chooseDate.substr(0, Pos);
			stay = chooseDate.substr(Pos + 1, chooseDate.size() - Pos - 1);
			m.insert(make_pair(key, stay));
		}


		Pos = chooseTime.find(":");
		if (Pos != -1)
		{
			key = chooseTime.substr(0, Pos);
			stay = chooseTime.substr(Pos + 1, chooseTime.size() - Pos - 1);
			m.insert(make_pair(key, stay));
		}

		Pos = chooseRoom.find(":");
		if (Pos != -1)
		{
			key = chooseRoom.substr(0, Pos);
			stay = chooseRoom.substr(Pos + 1, chooseRoom.size() - Pos - 1);
			m.insert(make_pair(key, stay));
		}

		Pos = status.find(":");
		if (Pos != -1)
		{
			key = status.substr(0, Pos);
			stay = status.substr(Pos + 1, status.size() - Pos - 1);
			m.insert(make_pair(key, stay));
		}
	
		YuMap.insert(make_pair(this->m_Size, m));	
		this->m_Size++;
	}
	ifs.close();

}
void YuFile::updateFile()
{
	if (this->m_Size == 0)
	{
		return;
	}
	ofstream ofs(YU_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "studenID:" << YuMap[i]["studenID"]<<" ";
		ofs << "studenName:" << YuMap[i]["studenName"] << " ";
		ofs << "chooseDate:" << YuMap[i]["chooseDate"] << " ";
		ofs << "chooseTime:" << YuMap[i]["chooseTime"] << " ";
		ofs << "chooseRoom:" << YuMap[i]["chooseRoom"] << " ";
		ofs << "status:" << YuMap[i]["status"] << endl;
	}
	ofs.close();

}