#pragma once
#include "Plane.h"
#include "Bus.h"
#include "User.h"

template<class T> class IRepo
{
protected:
	vector<T*> elem;
public:
	IRepo() {}
	virtual ~IRepo() {}
	void add(T* ent)
	{
		elem.push_back(ent->clone());
	}
	void del(T* ent)
	{
		for (auto it = elem.begin(); it != elem.end(); ++it)
			if (*ent == **it)
			{
				delete *it;
				elem.erase(it);
				return;
			}
		throw runtime_error("Elementul nu exista!");
	}
	void mod(T* oldE, T* newE)
	{
		for (auto it = elem.begin(); it != elem.end(); ++it)
			if (*oldE == **it)
			{
				*it = newE->clone();
				return;
			}
		throw runtime_error("Elementul nu exista!");
	}
	int size() { return elem.size(); }
	vector<T*>& all() { return elem; }
	T* at(int i)
	{
		int j = 0;
		for (auto it = elem.begin(); it != elem.end(); ++it)
		{
			if (i == j)
				return *it;
			j++;
		}
		return NULL;
	}
	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
	virtual void save(T*) = 0;
};

