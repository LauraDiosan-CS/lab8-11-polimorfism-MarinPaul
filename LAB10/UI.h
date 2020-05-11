#pragma once
#include "Service.h"

class UI
{
private:
	Service service;
	void add_ui();
	void del_ui();
	void mod_ui();
	void all_ui();
	void client();
	void boss();
	void login(int);
public:
	UI();
	~UI();
	void show();
};