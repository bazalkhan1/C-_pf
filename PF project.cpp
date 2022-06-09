#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void welcome()
{
	system("cls");
	system("COLOR 4F");
	cout << "\t\t(-_-)-(-_-)-(-_-)-(-_-)-(-_-)-(-_-)-(-_-)-(-_-)-(-_-)-(-_-)\t\n";
	cout << "\t\t |                    W E L C O M E                    \t |\n";
	cout << "\t\t |                                                     \t |\n";
	cout << "\t\t |                         T O                         \t |\n";
	cout << "\t\t |                                                     \t |\n";
	cout << "\t\t |                    L I B R A R Y                    \t |\n";
	cout << "\t\t |                                                     \t |\n";
	cout << "\t\t |         M A N A G E M E N T     S Y S T E M         \t |\n";
	cout << "\t\t |                                                     \t |\n";
	cout << "\t\t |                         B Y                         \t |\n";
	cout << "\t\t |                                                     \t |\n";
	cout << "\t\t |               B A Z A L     H A S H I M             \t |\n";
	cout << "\t\t |                                                     \t |\n";
	cout << "\t\t |                (-_-)  (-_-)  (-_-)                  \t |\n";
	cout << "\t\t |                                                     \t |\n";
	cout << "\t\t |                (-_-)  (-_-)  (-_-)                  \t |\n";
	cout << "\t\t |                                                     \t |\n";
	cout << "\t\t(-_-)-(-_-)-(-_-)-(-_-)-(-_-)-(-_-)-(-_-)-(-_-)-(-_-)-(-_-)\t\n\n\n";
	system("pause");
}
void default_books()
{
	ofstream w;
	w.open("Books.txt", ios::app);
	w << "Grand_Design" << " " << "978-05-538053" << " " << "Stephen_Hawking" << " " << 2010 << " " << "Bantam_Books" << endl;
	w << "Periodic_Tales" << " " << "978-05-535397" << " " << " Hugh" << " " << 2005 << " " << "Ecco_Press" << endl;
	w << "Abstract_Algebra" << " " << "978-05-458193" << " " << "David" << " " << 2002 << " " << "Cambridge_University" << endl;
	w << "Diwan_e_Ghalib" << " " << "971-54-729734" << " " << "Mirza_Ghalib" << " " << 1989 << " " << "Rajpal_and_Sons" << endl;
	w << "Jane_Eyre" << " " << "978-05-434453" << " " << "Michael" << " " << 2003 << " " << "Smith" << endl;
	w << "Islamiat_Baraye " << " " << "978-05-654643" << " " << "Sardar_Aftab" << " " << 2001 << " " << "Jahangirs_World" << endl;
	w << "Programming_Perl" << " " << "978-05-123533" << " " << "Larry_Wall" << " " << 2000 << " " << "O_Reilly_Media" << endl;
	w.close();
}

void add_book()
{
	string* p;
	string array[5];
	p = array;
	ofstream write_file;
	write_file.open("Books.txt", ios::app);
	cout << "Enter Book Name : ";
	cin >> *(p + 0);
	cout << "Enter Book ISBN : ";
	cin >> *(p + 1);
	cout << "Enter Book Author : ";
	cin >> *(p + 2);
	cout << "Enter the Book publish year : ";
	cin >> *(p + 3);
	cout << "Enter the Book publisher : ";
	cin >> *(p + 4);
	
	write_file << *(p + 0) << "  " << *(p + 1) << "  " << *(p + 2) << "  " << *(p + 3) << "  " << *(p + 4) << endl;
	cout << "Book Added" << endl;
	write_file.close();
}
void read_data(ifstream& r, string array[])
{
	r >> array[0];
	r >> array[1];
	r >> array[2];
	r >> array[3];
	r >> array[4];
}
void read_issue_data(ifstream& r, string array[])
{
	r >> array[0];
	r >> array[1];
	r >> array[2];
	r >> array[3];
	r >> array[4];
	r >> array[5];
	r >> array[6];
}
void display_all_books()
{
	bool isfilled = false;
	ifstream read_file;
	read_file.open("Books.txt");
	if (!read_file.is_open())
	{
		cout << "File not opened" << endl;
	}
	else
	{
		string array[5];
		read_data(read_file, array);
		while (!read_file.eof())
		{
			isfilled = true;
			for (int i = 0; i < 5; i++)
			{
				cout << array[i] << "\t";
			}
			cout << endl;
			read_data(read_file, array);
		}
		if (isfilled == false)
		{
			cout << "Library is Empty" << endl;
		}
	}
	read_file.close();
}
void display_issued_books()
{
	ifstream read_file;
	read_file.open("issued_books.txt");
	if (!read_file.is_open())
	{
		cout << "File not opened" << endl;
	}
	else
	{
		bool isfilled = false;
		string array[7];
		read_issue_data(read_file, array);
		while (!read_file.eof())
		{
			isfilled = true;
			for (int i = 0; i < 7; i++)
			{
				cout << array[i] << "\t";
			}
			cout << endl;
			read_issue_data(read_file, array);
		}
		if (isfilled == false)
		{
			cout << "Library is Empty" << endl;
		}
	}
	read_file.close();
}
string** get_data_in_array(ifstream &read_file,int &size,string array[])
{
	read_data(read_file, array);
	while (!read_file.eof())
	{
		size++;
		read_data(read_file, array);
	}
	read_file.close();
	string** books = new string * [size];
	for (int i = 0; i < size; i++)
	{
		books[i] = new string[5];
	}
	string** p = books;
	read_file.open("Books.txt");
	read_data(read_file, array);
	int j = 0;
	while (!read_file.eof())
	{
		for (int i = 0; i < 5; i++)
		{
			*(*(p + j) + i) = array[i];
		}
		j++;
		read_data(read_file, array);
	}
	read_file.close();
	return books;
}
string** get_issued_books(ifstream& read_file, int& size, string array[])
{
	read_issue_data(read_file, array);
	while (!read_file.eof())
	{
		size++;
		read_issue_data(read_file, array);
	}
	read_file.close();
	string** books = new string * [size];
	for (int i = 0; i < size; i++)
	{
		books[i] = new string[7];
	}
	string** p = books;
	read_file.open("issued_books.txt");
	read_issue_data(read_file, array);
	int j = 0;
	while (!read_file.eof())
	{
		for (int i = 0; i < 7; i++)
		{
			*(*(p + j) + i) = array[i];
		}
		j++;
		read_issue_data(read_file, array);
	}
	read_file.close();
	return books;
}
void delete_book()
{
	ifstream read_file;
	read_file.open("Books.txt");
	if (!read_file.is_open())
	{
		cout << "File not opened" << endl;
		read_file.close();
	}
	else
	{
		string isbn;
		display_all_books();
		int r = 0;
		string array[5];
		string** books = get_data_in_array(read_file,r, array);
		read_file.close();
		if (r != 0) {
			string** p = books;
			
			cout << "Which Book you want to delete ? Enter its ISBN : ";
			cin >> isbn;
			bool help = false;
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					int l = r - 1;
					if (*(*(p + i) + j) == isbn)
					{
						for (int z = 0; z < 5; z++)
						{
							array[z] = *(*(p + i) + z);
						}
						for (int z = 0; z < 5; z++)
						{
							*(*(p + i) + z) = *(*(p + l) + (z));
						}
						
						for (int z = 0; z < 5; z++)
						{
							*(*(p + l) + (z)) = array[z];
						}
						help = true;
						r--;
						j = 5;
					}
				}
				if (help==true)
				{
					break;
				}
			}
			if (help == true)
			{
				cout << "Book deleted" << endl;
				remove("Books.txt");
				ofstream write_file;
				write_file.open("Books.txt", ios::app);
				for (int i = 0; i < r; i++)
				{
					write_file << *(*(p + i) + 0) << "  " << *(*(p + i) + 1) << "  " << *(*(p + i) + 2) << "  " << *(*(p + i) + 3) << "  " << *(*(p + i) + 4) << endl;
				}
				write_file.close();
			}
			else
			{
				cout << "Book not found" << endl;
			}
		}
		
		}
}
void update_book()
{
	ifstream read_file;
	read_file.open("Books.txt");
	if (!read_file.is_open())
	{
		cout << "File not opened" << endl;
		read_file.close();
	}
	else
	{
		string isbn;
		display_all_books();
		int r = 0;
		string array[5];
		string** books = get_data_in_array(read_file, r, array);
		read_file.close();
		if (r != 0)
		{
			string** p = books;
			bool help = false;
			cout << "Which book you want to update ? Enter its ISBN : ";
			cin >> isbn;
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (*(*(p + i) + j) == isbn)
					{
						cout << "Enter NEW Book Name : ";
						cin >> *(*(p + i)+0);
						cout << "Enter NEW Book ISBN : ";
						cin >> *(*(p + i) + 1);
						cout << "Enter NEW Book Author : ";
						cin >> *(*(p + i) + 2);
						cout << "Enter NEW the Book publish year : ";
						cin >> *(*(p + i) + 3);
						cout << "Enter NEW the Book publisher : ";
						cin >> *(*(p + i) + 4);
						help = true;
						j = 5;
					}
				}
				if (help==true)
				{
					break;
				}
			}
			if (help == true)
			{
				cout << "Book Updated" << endl;
				remove("Books.txt");
				ofstream write_file;
				write_file.open("Books.txt", ios::app);
				for (int i = 0; i < r; i++)
				{
					write_file << *(*(p + i) + 0) << "  " << *(*(p + i) + 1) << "  " << *(*(p + i) + 2) << "  " << *(*(p + i) + 3) << "  " << *(*(p + i) + 4) << endl;
				}
				write_file.close();
			}
			else
			{
				cout << "Book not found" << endl;
			}
		}
		
	}
}
void issue_book()
{
	ifstream read_file;
	read_file.open("Books.txt");
	if (!read_file.is_open())
	{
		cout << "File not opened" << endl;
		read_file.close();
	}
	else
	{
		string isbn;
		display_all_books();
		int r = 0;
		string array[5];
		string** books = get_data_in_array(read_file, r, array);
		read_file.close();
		if (r != 0)
		{
			bool help = false;
			string** p = books;
			cout << "Which Book you want to issue ? Enter its ISBN : ";
			cin >> isbn;
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (isbn == *(*(p + i) + j))
					{
						ofstream write_file;
						write_file.open("issued_books.txt", ios::app);
						string name, phone;
						cout << "Enter the member name : ";
						cin >> name;
						cout << "Enter the member phone number : ";
						cin >> phone;
						write_file << name << "  " << phone << "  " << *(*(p + i) + 0) << "  " << *(*(p + i) + 1) << "  " << *(*(p + i) + 2) << "  " << *(*(p + i) + 3) << "  " << *(*(p + i) + 4) << endl;
						write_file.close();
						
						int l = r - 1;
						
						for (int z = 0; z < 5; z++)
						{
							array[z] = *(*(p + i) + z);
						}
						for (int z = 0; z < 5; z++)
						{
							*(*(p + i) + z) = *(*(p + l) + (z));
						}

						for (int z = 0; z < 5; z++)
						{
							*(*(p + l) + (z)) = array[z];
						}
						r--;
						help = true;
						j = 5;
					}
				}
				if (help == true)
				{
					break;
				}
			}
			if (help == true)
			{
				remove("Books.txt");
				ofstream write_file;
				write_file.open("Books.txt", ios::app);
				for (int i = 0; i < r; i++)
				{
					write_file << *(*(p + i) + 0) << "  " << *(*(p + i) + 1) << "  " << *(*(p + i) + 2) << "  " << *(*(p + i) + 3) << "  " << *(*(p + i) + 4) << endl;
				}
				write_file.close();
			}
			else
			{
				cout << "Book not found" << endl;
			}
		}
	}
}
void return_book()
{
	ifstream read_file;
	read_file.open("issued_books.txt");
	if (!read_file.is_open())
	{
		cout << "File not opened" << endl;
		read_file.close();
	}
	else
	{
		int r = 0;
		string array[7];
		display_issued_books();
		string name, isbn;
		string** books = get_issued_books(read_file, r, array);
		read_file.close();
		if (r != 0)
		{
			bool help = false;
			string** p = books;
			cout << "Enter the member name : ";
			cin >> name;
			cout << "Enter the Book ISBN : ";
			cin >> isbn;
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					if ((*(*(p + i) + 0) == name) && (*(*(p + i) + 3) == isbn))
					{
						help = true;
						ofstream write_file;
						write_file.open("Books.txt", ios::app);
						write_file << *(*(p + i) + 2) << "  " << *(*(p + i) + 3) << "  " << *(*(p + i) + 4) << "  " << *(*(p + i) + 5) << "  " << *(*(p + i) + 6) << endl;
						write_file.close();
						int l = r - 1;
						for (int z = 0; z < 7; z++)
						{
							array[z] = *(*(p + i) + z);
						}
						for (int z = 0; z < 7; z++)
						{
							*(*(p + i) + z) = *(*(p + l) + (z));
						}

						for (int z = 0; z < 7; z++)
						{
							*(*(p + l) + (z)) = array[z];
						}
						r--;
						j = 7;
					}
				}
				if (help == true)
				{
					break;
				}
			}
			if (help == true)
			{
				remove("issued_books.txt");
				ofstream write_file;
				write_file.open("issued_books.txt");
				for (int i = 0; i < r; i++)
				{
					write_file << *(*(p + i) + 0) << "  " << *(*(p + i) + 1) << "  " << *(*(p + i) + 2) << "  " << *(*(p + i) + 3) << "  " << *(*(p + i) + 4)<<"  " << *(*(p + i) + 5) << "  " << *(*(p + i) + 6)<< endl;
				}
				write_file.close();
			}
			else
			{
				cout << "Book not found" << endl;
			}
		}
		
	}
}
void search_book()
{
	int choice;
	ifstream read_file;
	read_file.open("Books.txt");
	if (!read_file.is_open())
	{
		cout << "File not opened" << endl;
		read_file.close();
	}
	else
	{
		string array[5];
		string search;
		int r = 0;
		string** books = get_data_in_array(read_file, r, array);
		read_file.close();
		if (r != 0) 
		{
			string** p = books;
			bool help = false;
			cout << "\t\t\t 1- Search Student on the basis of Title " << endl;
			cout << "\t\t\t 2- Search Student on the basis of ISBN " << endl;
			cout << "\t\t\t 3- Search Student on the basis of Author " << endl;
			cout << "\t\t\t Enter your Option : ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "Enter the title of the book for search : ";
				cin >> search;
				for (int i = 0; i < r; i++)
				{
					if (*(*(p + i) + 0) == search)
					{
							help = true;
							cout << endl;
							cout << "-----------------------------" << endl;
							cout << endl;
							cout << "Book Title = " << *(*(p + i) + 0) << endl;
							cout << "Book ISBN = " << *(*(p + i) + 1) << endl;
							cout << "Book Author = " << *(*(p + i) + 2) << endl;
							cout << "Publish Year = " << *(*(p + i) + 3) << endl;
							cout << "Publisher = " << *(*(p + i) + 4) << endl;
							cout << endl;
							cout << "-----------------------------" << endl;
					}
					
				}
				break;
			case 2:
				cout << "Enter the ISBN of the book for search : ";
				cin >> search;
				for (int i = 0; i < r; i++)
				{
					
						if (*(*(p + i) + 1) == search)
						{
							help = true;
							cout << endl;
							cout << "-----------------------------" << endl;
							cout << endl;
							cout << "Book Title = " << *(*(p + i) + 0) << endl;
							cout << "Book ISBN = " << *(*(p + i) + 1) << endl;
							cout << "Book Author = " << *(*(p + i) + 2) << endl;
							cout << "Publish Year = " << *(*(p + i) + 3) << endl;
							cout << "Publisher = " << *(*(p + i) + 4) << endl;
							cout << endl;
							cout << "-----------------------------" << endl;
						}
					
				}
				break;
			case 3:
				cout << "Enter the Author of the book for search : ";
				cin >> search;
				for (int i = 0; i < r; i++)
				{
						if (*(*(p + i) + 2) == search)
						{
							help = true;
							cout << endl;
							cout << "-----------------------------" << endl;
							cout << endl;
							cout << "Book Title = " << *(*(p + i) + 0) << endl;
							cout << "Book ISBN = " << *(*(p + i) + 1) << endl;
							cout << "Book Author = " << *(*(p + i) + 2) << endl;
							cout << "Publish Year = " << *(*(p + i) + 3) << endl;
							cout << "Publisher = " << *(*(p + i) + 4) << endl;
							cout << endl;
							cout << "-----------------------------" << endl;
						}
					
				}
				break;
			default:
				cout << "Invalid choice" << endl;
			}
			if (help == false)
			{
				cout << "No Book Found" << endl;
			}
		}
	}
}
void change_password()
{
	ifstream read_file;
	read_file.open("setting.txt");
	string pass, current;
	read_file >> pass;
	read_file.close();
	cout << "\t\t\t Enter the Current Password : ";
	cin >> current;
	if (pass == current)
	{
		ofstream write_file;
		write_file.open("setting.txt");
		cout << "\t\t\t Enter New Password : " ;
		cin >> pass;
		write_file << pass;
		write_file.close();
		cout << "\t\t\t Password Changed" << endl;
	}
	else
	{
		cout << "\t\t\t Incorrect Password" << endl;
	}
}
void set_password()
{
	ofstream write_file;
	write_file.open("setting.txt");
	write_file << "bazal";
	write_file.close();
}
void Member_login();
void Librarian_login();
int main()
{
	ifstream w;
	w.open("Books.txt");
	if (!w.is_open())
	{
		default_books();
	}
	w.close();
	int choice;
	welcome();
	system("cls");
option:
	while (1) {
		cout << "************************* M A I N   M E N U *************************" << endl;
		cout << "" << endl;
		cout << "\t\t\t 1 - MEMBER LOGIN" << endl;
		cout << "" << endl;
		cout << "\t\t\t 2 - LIBRARIAN LOGIN" << endl;
		cout << "" << endl;
		cout << "\t\t\t 3 - EXIT APPLICATION" << endl;
		cout << "" << endl;
		cout << "\t\t\t     ENTER YOUR CHOICE : ";
		cin >> choice;
		while (choice <= 0 || choice > 3)
		{
			cout << "\t\t\t     INVALID CHOICE " << endl;
			system("pause");
			system("cls");
			goto option;
		}
		system("cls");
		switch (choice)
		{
		case 1:
			Member_login();
			break;
		case 2:
			Librarian_login();
			break;
		case 3:
			exit(10);
			break;
		}
		system("pause");
	}
	return 0;
	
}
void Member_login()
{
	while (1) {
		int choice;
		cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
		cout << "\t\t\t   M E M B E R   L O G I N  " << endl;
		cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
		cout << "\t\t\t PRESS 1 TO DISPLAY ALL BOOKS " << endl;
		cout << "\t\t\t PRESS 2 TO SEARCH BOOK " << endl;
		cout << "\t\t\t PRESS 3 TO GO BACK" << endl;
		cout << "\t\t\t Enter your Choice ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			display_all_books();
			break;
		case 2:
			search_book();
			break;
		case 3:
			main();
			break;
		default:
			cout << "\t\tInvalid choice " << endl;
		}
		system("pause");
		system("cls");
	}
}
void Libarian_Menu()
{
	cout << "\t\t\t L I B R A R I A N   L O G I N " << endl;
	cout << "" << endl;
	cout << "\t\t\t PRESS 1 TO ADD BOOK IN LIBRARY " << endl;
	cout << "\t\t\t PRESS 2 TO DELETE BOOK FROM LIBRARY  " << endl;
	cout << "\t\t\t PRESS 3 TO MODIFY BOOK IN LIBRAY  " << endl;
	cout << "\t\t\t PRESS 4 TO DISPLAY ALL BOOKS LIST " << endl;
	cout << "\t\t\t PRESS 5 TO ISSUE BOOK " << endl;
	cout << "\t\t\t PRESS 6 TO RETURN ISSUE BOOK" << endl;
	cout << "\t\t\t PRESS 7 TO DISPLAY ALL ISSUE BOOKS LIST" << endl;
	cout << "\t\t\t PRESS C TO CHANGE INFORMATION OF SYSTEM" << endl;
	cout << "\t\t\t PRESS L FOR LOGOUT FROM SYSTEM" << endl;
}
void Librarian_login()
{
	string pass, user_pass;
	ifstream read_file;
	read_file.open("setting.txt");
	if (!read_file.is_open())
	{
		set_password();
	}
	read_file.close();
	read_file.open("setting.txt");
	read_file >> pass;
	read_file.close();
	login:
	cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
	cout << "\t\t\t   L I B R A R I A N   L O G I N  " << endl;
	cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
	cout << "\t\t\t ENTER THE PASSWORD : ";
	cin >> user_pass;
	while (user_pass != pass)
	{
		cout << "\t\t\t WRONG  PASSWORD " << endl;
		system("pause");
		system("cls");
		goto login;
	}
	cout << "\t\t\t CORRECT PASSWORD" << endl;
	system("pause");
	system("cls");
	while (1) {
		Libarian_Menu();
		char ch;
		cout << "\t\t\t Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case '1':
			add_book();
			break;
		case '2':
			delete_book();
			break;
		case '3':
			update_book();
			break;
		case '4':
			display_all_books();
			break;
		case '5':
			issue_book();
			break;
		case '6':
			return_book();
			break;
		case '7':
			display_issued_books();
			break;
		case 'C':
		case 'c':
			change_password();
			break;
		case 'l':
		case 'L':
			main();
			break;
		default:
			cout << "Invalid choice" << endl;
		}
		system("pause");
		system("cls");
	}
}
