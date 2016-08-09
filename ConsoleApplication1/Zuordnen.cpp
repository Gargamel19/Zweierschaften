
#include "stdafx.h"
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
	int zugeordnet[36];
	int zaehler = 0;
	int seed;

	cout << "bitte geben sie einen parameter ein!" << endl;
	cin >> seed;

	zugeordnet[0] = 1;
	zugeordnet[1] = 1;
	zugeordnet[2] = 1;
	zugeordnet[3] = 1;
	zugeordnet[4] = 1;
	zugeordnet[5] = 1;
	zugeordnet[6] = 1;
	zugeordnet[7] = 1;
	zugeordnet[8] = 1;
	zugeordnet[9] = 1;
	zugeordnet[10] = 1;
	zugeordnet[11] = 1;
	zugeordnet[12] = 1;
	zugeordnet[13] = 1;
	zugeordnet[14] = 1;
	zugeordnet[15] = 1;
	zugeordnet[16] = 1;
	zugeordnet[17] = 1;
	zugeordnet[18] = 1;
	zugeordnet[19] = 1;
	zugeordnet[20] = 1;
	zugeordnet[21] = 1;
	zugeordnet[22] = 1;
	zugeordnet[23] = 1;
	zugeordnet[24] = 1;
	zugeordnet[25] = 1;
	zugeordnet[26] = 1;
	zugeordnet[27] = 1;
	zugeordnet[28] = 1;
	zugeordnet[29] = 1;
	zugeordnet[30] = 1;
	zugeordnet[31] = 1;
	zugeordnet[32] = 1;
	zugeordnet[33] = 1;
	zugeordnet[34] = 1;
	zugeordnet[35] = 1;
	
	
		

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

	int random[36];

	srand(seed);

	int randomint;


	for (int i = 0; i < 36; i++)
	{


		random[i] = (rand() % 36);

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

				randy = (rand() % 36);
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
	if (!datei) throw "Fehler beim Öffnen!";
	
	datei << "Zweierschaften:" + output;
	datei.close();

	

	int zahl;
	cin >> zahl;

	
	return(0);
}



