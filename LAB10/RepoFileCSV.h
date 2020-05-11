#pragma once
#include "RepoFile.h"

template <class T> class RepoFileCSV {};

template <> class RepoFileCSV<Transport>: public RepoFile<Transport>
{
private:
	char delimit = ',';
public:
	RepoFileCSV() {}
	RepoFileCSV(const char* newFile) :RepoFile<Transport>(newFile) {}
	void saveToFile()
	{
		ofstream f(RepoFile<Transport>::fileName);
		f.clear();
		for (Transport* crt : IRepo<Transport>::elem)
			f << crt->className() << delimit << crt->toStringFile(delimit) << endl;
		f.close();
	}
	void save(Transport* crt)
	{
		ofstream f(RepoFile<Transport>::fileName);
		f << crt->className() << delimit << crt->toStringFile(delimit) << endl;
		f.close();
	}
	void loadFromFile()
	{
		string line;
		string name;
		ifstream f(RepoFile<Transport>::fileName);
		Transport* ent;
		while (!f.eof())
		{
			getline(f, line);
			if (line == "")
				return;
			split(line, name, delimit);
			if (name == "Plane")
			{
				ent = new Plane(line, delimit);
				IRepo<Transport>::elem.push_back(ent->clone());
				delete[] ent;
			}
			if (name == "Bus")
			{
				ent = new Bus(line, delimit);
				IRepo<Transport>::elem.push_back(ent->clone());
				delete ent;
			}
		}
		f.close();
	}
	~RepoFileCSV() {}
};

template <> class RepoFileCSV<User> : public RepoFile<User>
{
private:
	char delimit = ',';
public:
	RepoFileCSV() {}
	RepoFileCSV(const char* newFile) :RepoFile<User>(newFile) {}
	void saveToFile()
	{
		ofstream f(RepoFile<User>::fileName);
		f.clear();
		for (User* crt : IRepo<User>::elem)
			f << crt->toStringFile(delimit) << endl;
		f.close();
	}
	void save(User* crt)
	{
		ofstream f(RepoFile<User>::fileName);
		f << crt->toStringFile(delimit) << endl;
		f.close();
	}
	void loadFromFile()
	{
		ifstream f(RepoFile<User>::fileName);
		string line;
		User* ent;
		while (!f.eof())
		{
			getline(f, line);
			if (line == "")
				return;
			ent = new User(line, delimit);
			IRepo<User>::elem.push_back(ent->clone());
			delete ent;
		}
		f.close();
	}
	~RepoFileCSV() {}
};