#include "Utilities.h"

vector<string> readLine(string line, const char del)
{
	stringstream ss(line);
	string item;
	vector<string> elements;
	while (getline(ss, item, del))
		elements.push_back(item);
	return elements;
}

void split(string& line, string& name, const char del)
{
	stringstream ss(line);
	getline(ss, name, del);
	string aux;
	getline(ss, aux);
	line = aux;
}

Date date_str(string line)
{
	stringstream ss(line);
	string item;
	vector<int> elements;
	while (getline(ss, item, '/'))
		elements.push_back(stoi(item));
	return Date(elements[0], elements[1], elements[2]);
}