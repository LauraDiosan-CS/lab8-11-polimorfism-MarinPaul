#include "UI.h"

UI::UI() {}

UI::~UI() {}

void UI::add_ui()
{
	string opt;
	cout << "Doriti <utilizator> sau <calatorie>?" << endl << "Introduceti: ";
	cin >> opt;
	if (opt == "utilizator")
	{
		char* name = new char[30];
		char* password = new char[30];
		cout << "Introduceti numele: ";
		cin >> name;
		cout << "Introduceti parola: ";
		cin >> password;
		if (service.find_by_name(name) != NULL)
		{
			delete[] name;
			delete[] password;
			throw runtime_error("Nume utilizat deja!");
		}
		service.add<User>(new User(name, password));
		cout << "Adaugat!";
		delete[] name;
		delete[] password;
		return;
	}
	else if (opt == "calatorie")
	{
		string opt_2;
		cout << "Doriti <autobuz> sau <avion>?" << endl << "Introduceti: ";
		cin >> opt_2;
		if (opt_2 == "autobuz")
		{
			char* code = new char[30];
			char* departure = new char[30];
			char* arrival = new char[30];
			Date date;
			int time, total_seats, booked_seats;
			cout << "Introduceti codul: ";
			cin >> code;
			cout << "Introduceti locatia plecarii: ";
			cin >> departure;
			cout << "Introduceti locatia destiantiei: ";
			cin >> arrival;
			cout << "Introduceti data plecarii sub forma <dd/mm/yyyy>: ";
			cin >> date;
			cout << "Introduceti durata calatoriei: ";
			cin >> time;
			cout << "Introduceti numarul de locuri totale: ";
			cin >> total_seats;
			cout << "Introduceti numarul de locuri rezervate: ";
			cin >> booked_seats;
			if (service.find_by_code(code) != NULL)
			{
				delete[] code;
				delete[] departure;
				delete[] arrival;
				throw runtime_error("Cod utilizat deja!");
			}
			service.add<Transport>(new Bus(code, departure, arrival, date, time, total_seats, booked_seats));
			cout << "Adaugat!";
			delete[] code;
			delete[] departure;
			delete[] arrival;
			return;
		}
		else if (opt_2 == "avion")
		{
			char* code = new char[30];
			char* departure = new char[30];
			char* arrival = new char[30];
			Date date;
			char* transit = new char[30];
			int total_seats, booked_seats;
			cout << "Introduceti codul: ";
			cin >> code;
			cout << "Introduceti locatia plecarii: ";
			cin >> departure;
			cout << "Introduceti locatia destiantiei: ";
			cin >> arrival;
			cout << "Introduceti data plecarii sub forma <dd/mm/yyyy>: ";
			cin >> date;
			cout << "Este cu escala calatoria? Introduceti <da> sau <nu>: ";
			cin >> transit;
			cout << "Introduceti numarul de locuri totale: ";
			cin >> total_seats;
			cout << "Introduceti numarul de locuri rezervate: ";
			cin >> booked_seats;
			if (service.find_by_code(code) != NULL)
			{
				delete[] code;
				delete[] departure;
				delete[] arrival;
				delete[] transit;
				throw runtime_error("Cod utilizat deja!");
			}
			service.add<Transport>(new Plane(code, departure, arrival, date, transit, total_seats, booked_seats));
			cout << "Adaugat!";
			delete[] code;
			delete[] departure;
			delete[] arrival;
			delete[] transit;
			return;
		}
		throw runtime_error("Comanda invalida!");
	}
	throw runtime_error("Comanda invalida!");
}

void UI::del_ui()
{
	string opt;
	cout << "Doriti <utilizator> sau <calatorie>?" << endl << "Introduceti: ";
	cin >> opt;
	if (opt == "utilizator")
	{
		char* name = new char[30];
		cout << "Introduceti numele: ";
		cin >> name;
		if (service.find_by_name(name) == NULL)
		{
			delete[] name;
			throw runtime_error("Nume inexistent!");
		}
		service.del<User>(service.find_by_name(name));
		cout << "Sters!";
		delete[] name;
		return;
	}
	else if (opt == "calatorie")
	{
		char* code = new char[30];
		cout << "Introduceti codul: ";
		cin >> code;
		if (service.find_by_code(code) == NULL)
		{
			delete[] code;
			throw runtime_error("Cod inexistent!");
		}
		service.del<Transport>(service.find_by_code(code));
		cout << "Sters!";
		delete[] code;
		return;
	}
	throw runtime_error("Comanda invalida!");
}

void UI::mod_ui()
{
	string opt;
	cout << "Doriti <utilizator> sau <calatorie>?" << endl << "Introduceti: ";
	cin >> opt;
	if (opt == "utilizator")
	{
		char* oldName = new char[30];
		cout << "Introduceti numele: ";
		cin >> oldName;
		if (service.find_by_name(oldName) == NULL)
		{
			delete[] oldName;
			throw runtime_error("Nume inexistent!");
		}
		char* name = new char[30];
		char* password = new char[30];
		cout << "Introduceti numele: ";
		cin >> name;
		cout << "Introduceti parola: ";
		cin >> password;
		if (service.find_by_name(name) != NULL && strcmp(oldName, name) != 0)
		{
			delete[] oldName;
			delete[] name;
			delete[] password;
			throw runtime_error("Nume utilizat deja!");
		}
		service.mod<User>(service.find_by_name(oldName), new User(name, password));
		cout << "Modificat!";
		delete[] oldName;
		delete[] name;
		delete[] password;
		return;
	}
	else if (opt == "calatorie")
	{
		char* oldCode = new char[30];
		cout << "Introduceti codul: ";
		cin >> oldCode;
		if (service.find_by_code(oldCode) == NULL)
		{
			delete[] oldCode;
			throw runtime_error("Cod inexistent!");
		}
		string opt_2;
		cout << "Doriti <autobuz> sau <avion>?" << endl << "Introduceti: ";
		cin >> opt_2;
		if (opt_2 == "autobuz")
		{
			char* code = new char[30];
			char* departure = new char[30];
			char* arrival = new char[30];
			Date date;
			int time, total_seats, booked_seats;
			cout << "Introduceti codul: ";
			cin >> code;
			cout << "Introduceti locatia plecarii: ";
			cin >> departure;
			cout << "Introduceti locatia destiantiei: ";
			cin >> arrival;
			cout << "Introduceti data plecarii sub forma <dd/mm/yyyy>: ";
			cin >> date;
			cout << "Introduceti durata calatoriei: ";
			cin >> time;
			cout << "Introduceti numarul de locuri totale: ";
			cin >> total_seats;
			cout << "Introduceti numarul de locuri rezervate: ";
			cin >> booked_seats;
			if (service.find_by_code(code) != NULL && strcmp(oldCode, code) != 0)
			{
				delete[] oldCode;
				delete[] code;
				delete[] departure;
				delete[] arrival;
				throw runtime_error("Cod utilizat deja!");
			}
			service.mod<Transport>(service.find_by_code(oldCode), new Bus(code, departure, arrival, date, time, total_seats, booked_seats));
			cout << "Modificat!";
			delete[] oldCode;
			delete[] code;
			delete[] departure;
			delete[] arrival;
			return;
		}
		else if (opt_2 == "avion")
		{
			char* code = new char[30];
			char* departure = new char[30];
			char* arrival = new char[30];
			Date date;
			char* transit = new char[30];
			int total_seats, booked_seats;
			cout << "Introduceti codul: ";
			cin >> code;
			cout << "Introduceti locatia plecarii: ";
			cin >> departure;
			cout << "Introduceti locatia destiantiei: ";
			cin >> arrival;
			cout << "Introduceti data plecarii sub forma <dd/mm/yyyy>: ";
			cin >> date;
			cout << "Este cu escala calatoria? Introduceti <da> sau <nu>: ";
			cin >> transit;
			cout << "Introduceti numarul de locuri totale: ";
			cin >> total_seats;
			cout << "Introduceti numarul de locuri rezervate: ";
			cin >> booked_seats;
			if (service.find_by_code(code) != NULL && strcmp(oldCode, code) != 0)
			{
				delete[] oldCode;
				delete[] code;
				delete[] departure;
				delete[] arrival;
				delete[] transit;
				throw runtime_error("Cod utilizat deja!");
			}
			service.mod<Transport>(service.find_by_code(oldCode), new Plane(code, departure, arrival, date, transit, total_seats, booked_seats));
			cout << "Modificat!";
			delete[] oldCode;
			delete[] code;
			delete[] departure;
			delete[] arrival;
			delete[] transit;
			return;
		}
		throw runtime_error("Comanda invalida!");
	}
	throw runtime_error("Comanda invalida!");
}

void UI::all_ui()
{
	cout << "Calatorii:";
	for (auto it = service.all<Transport>().begin(); it != service.all<Transport>().end(); ++it)
		cout << endl << (*it)->toString();
	cout << endl;
	cout << "Utilizatori:";
	for (auto it = service.all<User>().begin(); it != service.all<User>().end(); ++it)
		cout << endl << (*it)->toString();
}

void UI::client()
{
	cout << "Sorry... nimic momentan!" << endl;
}

void UI::boss()
{
	try
	{
		string opt;
		cout << "Introduceti: <add> pentru adaugare; <del> pentru stergere; <mod> pentru modificare; <all> pentru afisare totala; <x> pentru inchidere" << endl;
		cout << "Introduceti: ";
		cin >> opt;
		if (opt == "add")
			add_ui();
		else if (opt == "del")
			del_ui();
		else if (opt == "mod")
			mod_ui();
		else if (opt == "all")
			all_ui();
		else if (opt == "x")
			return;
		else throw runtime_error("Comanda invalida!");
	}
	catch (exception& exc)
	{
		cout << exc.what();
	}
	cout << endl;
	boss();

}

void UI::login(int tries)
{
	try
	{
		if (tries == 0)
		{
			cout << "Ati epuizat numarul de incercari!";
			return;
		}
		cout << "Aveti " << tries << " incercari." << endl;
		char* name = new char[30];
		char* password = new char[30];
		cout << "Introduceti numele: ";
		cin >> name;
		cout << "Introduceti parola: ";
		cin >> password;
		if (service.login(name, password))
		{
			cout << "Buna ziua, " << name << "!" << endl;
			boss();
			delete[] name;
			delete[] password;
			return;
		}
		else cout << "Nume sau parola incorecte!";
		cout << endl;
	}
	catch (exception& exc)
	{
		cout << exc.what();
	}
	login(tries - 1);
}

void UI::show()
{
	try
	{
		char* opt_2 = new char[3];
		cout << "Doriti <csv> sau <txt>?" << endl << "Introduceti: ";
		cin >> opt_2;
		service.csv_or_txt(opt_2);
		string opt;
		cout << "Doriti <patron> sau <client>?" << endl << "Introduceti: ";
		cin >> opt;
		if (opt == "patron")
		{
			login(3);
			cout << "La revedere!";
			return;
		}
		if (opt == "client")
		{
			login(3);
			cout << "La revedere!";
			return;
		}
		throw runtime_error("Comanda invalida!");
	}
	catch (exception& exc)
	{
		string opt_3;
		cout << exc.what() << endl;
		cout << "Reincercati? <da> sau <nu>? Introduceti: ";
		cin >> opt_3;
		if (opt_3 == "da")
			show();
		else if (opt_3 == "nu")
			cout << "La revedere!";
		else cout << "Nu stii sa scrii! Avem dreptul sa ne alegem clientii! Pa!";
	}
}