#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <exception>

using namespace std;


class DeleteException2 : public exception
{
private:
	char* msg;
public:
	DeleteException2()
	{
		msg = new char[17];
		strcpy_s(msg, 17, "DeleteException2");
	}
	DeleteException2(const char* m)
	{
		msg = new char[strlen(m) + 1];
		strcpy_s(msg, strlen(m) + 1, m);
	}
	virtual const char* what() const throw() { return msg; }
	~DeleteException2() { if (msg) delete[] msg; }
};

class DeleteException1 : public DeleteException2
{
private:
	char* msg;
public:
	DeleteException1()
	{
		msg = new char[17];
		strcpy_s(msg, 17, "DeleteException1");
	}
	DeleteException1(const char* m)
	{
		msg = new char[strlen(m) + 1];
		strcpy_s(msg, strlen(m) + 1, m);
	}
	virtual const char* what() const throw() { return msg; }
	~DeleteException1() { if (msg) delete[] msg; }
};


struct Date
{
	int day;
	int month;
	int year;
	Date():day(0), month(0), year(0) {}
	Date(const int newD, const int newM, const int newY):day(newD),month(newM),year(newY) {}
	Date(const Date& d):day(d.day),month(d.month),year(d.year) {}
	Date(const char* newD)
	{
		string str(newD);
		stringstream ss(str);
		string item;
		vector<int> elements;
		while (getline(ss, item, '/'))
			elements.push_back(stoi(item));
		*this = Date(elements[0], elements[1], elements[2]);
	}
	Date& operator=(const Date& d)
	{
		day = d.day;
		month = d.month;
		year = d.year;
		return *this;
	}
	bool operator<(const Date& d)
	{
		return (365 * year + 30 * month + day < 365 * d.year + 30 * d.month + d.day);
	}
	bool operator==(const Date& d)
	{
		return (365 * year + 30 * month + day == 365 * d.year + 30 * d.month + d.day);
	}
	bool operator>(const Date& d)
	{
		return (365 * year + 30 * month + day > 365 * d.year + 30 * d.month + d.day);
	}
	bool operator<=(const Date& d)
	{
		return (operator<(d) || operator==(d));
	}	
	bool operator>=(const Date& d)
	{
		return (operator>(d) || operator==(d));
	}
	friend string to_string(const Date& d) { return to_string(d.day) + '/' + to_string(d.month) + '/' + to_string(d.year); }
	friend ostream& operator<<(ostream& os, Date& d)
	{
		os << d.day << "/" << d.month << "/" << d.year;
		return os;
	}
	friend istream& operator>>(istream& is, Date& d)
	{
		int day, month, year;
		is >> day;
		if (is.get() != '/')
			return is;
		is >> month;
		if (is.get() != '/')
			return is;
		is >> year;
		d.day = day;
		d.month = month;
		d.year = year;
		return is;
	}
};

vector<string> readLine(string, const char);
void split(string&, string&, const char);
Date date_str(string);