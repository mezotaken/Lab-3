#include "arithmetic.h"
#include <cstdlib>
#define MAX_JOURNAL_NOTES 50
using namespace std;
char main_menu()
{
	system("cls");
	char res;
	cout << "1. Calculate new expression\n";
	cout << "2. Set variables\n";
	cout << "3. View journal\n";
	cout << "4. Exit\n\n";

	for (int i = 0; i < 6; i++)
		cout <<"  "<< (char)(117 + i)<<" = "<< arithmetic::GetVar(i);
	
	cout << "\n\n";
	cout << "Choose menu item: ";
	cin >> res;
	return res;
}

char var_menu()
{
	system("cls");
	char res;
		for (int i = 0; i < 6; i++)
			cout  << (char)(117 + i) << " = " << arithmetic::GetVar(i)<<endl;
		cout << "\n";
		cout << "1. Exit" << endl;
		cout << "\n\n";
		cout << "Choose variable ";
		cin >> res;
		return res;
}

int main()
{	
	int nCalc = 0;
	string journal[MAX_JOURNAL_NOTES];

	cout.precision(15);
	arithmetic cur("");
	char pmenu;
	do {
		pmenu = main_menu();
		
		switch (pmenu)
		{
		case '1':
		{	
			system("cls");
			cout << "Input expression:"<<endl;
			string input;
			getline(cin, input);
			getline(cin,input);
			cur = arithmetic(input);
			if (cur.IsCorrect())
			{
				journal[nCalc] += (input + " = " + to_string(cur.Calc()));
				cout << journal[nCalc] << endl;
				nCalc++;
				if (nCalc == MAX_JOURNAL_NOTES)
					nCalc = 0;
			}

			system("pause");
			break;
		}
		case '2':
		{
			do {
				pmenu = var_menu();
				if (pmenu <= 'z' && pmenu >= 'u')
				{
					double inp;
					cout << "Input value " << pmenu << ": ";
					cin >> inp;
					arithmetic::SetVar((int)pmenu - 117, inp);
				}
			} while (pmenu != '1');
		}
		break;
		case '3':
		{
			system("cls");
			for (int i = 0; i < nCalc; i++)
				cout << journal[i] << endl;
			system("pause");
			break;
		}
		case '4': break;
		}
	} while (pmenu != '4');
	return 0;
}