
#include <iostream>
#include <fstream>
using namespace std;
#include <string>
using namespace std;
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {



	ifstream namenliste("C:\\Users\\Ferdinand\\Desktop\\Zweierschaften\\res\\teilnemer.txt", ios::in);
	
	
	
	string zeichenkette;
	string namen[36];
	string output;
	string f;
	int namenID[36];
	int zaehler = 0;
	int seed;

	cout << "bitte geben sie einen parameter ein!" << endl;
	cin >> seed;

	
		

	while (getline(namenliste, zeichenkette))
	{

		int a;
		string b;

		for (int d = 0; d < zeichenkette.size(); d++)
		{

			stringstream datenstrom(zeichenkette);
			datenstrom >> a >> b;

		}

		namenID[zaehler] = a;
		namen[zaehler] = b;

		cout << namenID[zaehler] << " " << namen[zaehler] << endl;

		zaehler++;
	}


	int zugeordnet[zaehler];

	for(int i = 0; i < zaehler; i++){

		zugeordnet[i] = 1;
	
	}

	int random[zaehler];

	srand(seed);

	int randomint;


	for (int i = 0; i < zaehler; i++)
	{


		random[i] = (rand() % zaehler);

		randomint = random[i];

		if ((zugeordnet[randomint]) == 1)
		{
			string temp = namen[randomint];
			cout << temp;
			

			if (i % 2 != 0)
			{
				f = "\t \t";
			}
			else if(i % 2 == 0)
			{
				f = "\n";
			}
			
			output = output+ f + temp ;

			zugeordnet[randomint] = 0;
		}
		else if (zugeordnet[randomint] == 0) {
			
			int randy;

			do
			{

				randy = (rand() % zaehler);
				if (zugeordnet[randy] == 1)
				{
					zugeordnet[randy] = 1;
				}


			} while (zugeordnet[randy] == 0);

			string temp = namen[randy];
			cout << temp;

			if (i % 2 != 0)
			{
				f = "\t \t";
			}
			else if (i % 2 == 0)
			{
				f = "\n";
			}

			output = output + f + temp;
			zugeordnet[randy] = 0;

		}

		if (i%2 == 0)
		{
			cout << "\t \t";
		}
		else
		{
			cout << endl;
		}



	}
	cout << output;
	
	ofstream datei("C:\\Users\\Ferdinand\\Desktop\\Zweierschaften\\Zweierschaften.txt");
	if (!datei) throw "Fehler beim �ffnen!";
	
	datei << "Zweierschaften:" + output;
	datei.close();

	

	int zahl;
	cin >> zahl;

	
	return(0);
}



