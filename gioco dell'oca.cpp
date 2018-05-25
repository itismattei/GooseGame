#include<iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <conio.h>
#include <fstream>
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;

        return stm.str() ;
    }
}

using namespace std;
int dado = 0;
int I1 = 0, I2 = 0;  //caselle fatte
int O = 0;   //caselle in eccesso
int c = 0;
char regole;  //per visualizzare le regole di gioco
char risposta;
char vs;
int contatore = 0;
int contatore1 = 0;
string nome1;
string nome2;
string tb[40];
string no,no1;
string me,me1;
int n=0;

void SetColor(int forground, int background){
	WORD consoleColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		consoleColor = (forground + (background * 16));
		SetConsoleTextAttribute(hStdOut, consoleColor);
	}
}
void controlloCarattere( int i){
if(tb[i]==no)
    SetColor(2, 0);
else
    if(tb[i]==no+no1)
        SetColor(2, 0);

    if(tb[i]==me)
        SetColor(4, 0);
else
    if(tb[i]==me+me1)
        SetColor(4, 0);
else
    if(tb[i]=="t")
        SetColor(14,0);
else
    if(tb[i]==no+me)
        SetColor(14,0);
}
void win()
{
    Beep (200,100);Sleep(125);
    Beep (300,100);Sleep(125);
    Beep (350,100);Sleep(125);
    Beep (450,100);Sleep(125);
    Beep (600,100);Sleep(125);
    Beep (700,100);Sleep(125);
    Beep (950,100);Sleep(575);
    Beep (950,100);Sleep(125);
    Beep (950,100);Sleep(125);
    Beep (950,100);Sleep(125);
    Beep (1050,675);
}
void lose()
{
	Beep(900,500);
	Beep(800,500);
	Beep(700,500);
	Beep(600,1250);
}

void tirodado(int &contatore)      //tiro del dado
{
	dado = 0;
    srand(time(NULL));
    dado = rand()%6 + 1;
    contatore = contatore + dado;
}
void casella(int &contatore, int &contatore1)
{
    if (contatore == 8)
        {
            contatore = contatore + 3;
        }
    if (contatore == 18)
    {

        Sleep(200);
    		if(contatore!=contatore1)
    		{
            	tirodado(contatore1);
            	if (contatore1 > 40)
            	{
                	O = contatore1 - 40;
            	    contatore1 = 40 - O;
            		Sleep(200);
    			}
    		}
    		else
    		tirodado(contatore);
    }
    if (contatore == 25)
    {
        contatore = 0;
        Sleep(200);
    }
    if (contatore == 30)
    {
        contatore = contatore + 2;
        Sleep(200);
    }

    if(contatore == 36)
    {
        contatore = contatore - 8;
        Sleep(200);
    }
    Sleep(200);
}

void tabella()
{
        for (n=0; n<40; n++)
        tb[n] = patch::to_string(n+1);

        // Funzione per prendere la prima lettera del nome.

        no = nome1.at(0);
        me = nome2.at(0);
        no1 = nome1.at(1);
        me1 = nome2.at(1);
        if(no=="c")
            me="C";

        if (I1==I2)
        {
            if (I1&&I2<10)
                tb[I1-1] = 't';
            else
                tb[I1-1] =no+""+me;

        }
            else
            {
                if(I1<10)
                    tb[I1-1] = no;
                else
                    tb[I1-1] = no+no1;

                if(I2<10)
                    tb[I2-1] = me;
                else
                    tb[I2-1] = me+me1;
            }
cout<<" "<<no<<" = "<<no+no1<<" = "<<nome1<<"  ------> verde"<<endl;
cout<<" "<<me<<" = "<<me+me1<<" = "<<nome2<<"  ------> rosso"<<endl;
cout<<" t = "<<no+me<<" = entrambi i giocatori ------> giallo"<<endl;





    cout << "                                                                TABELLA DI GIOCO                            " << endl;
	cout << "                                    _______________________________________________________________________" << endl;
	cout << "                                    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |" << endl;
	cout << "                         INIZIO__ __|  "; controlloCarattere(0); cout<<tb[0]; SetColor(7,0);cout<<" |  "; controlloCarattere(1); cout<<tb[1]; SetColor(7,0);cout<<" |  "; controlloCarattere(2); cout<<tb[2]; SetColor(7,0);cout<<" |  "; controlloCarattere(3); cout<<tb[3]; SetColor(7,0);cout<<" |  "; controlloCarattere(4); cout<<tb[4]; SetColor(7,0);cout<<" |  "; controlloCarattere(5); cout<<tb[5]; SetColor(7,0);cout<<" |  "; controlloCarattere(6); cout<<tb[6]; SetColor(7,0);cout<<" |  "; controlloCarattere(7); cout<<tb[7]; SetColor(7,0);cout<<" |  "; controlloCarattere(8); cout<<tb[8]; SetColor(7,0);cout<<" | "; controlloCarattere(9); cout<<tb[9]; SetColor(7,0);cout<<" | "; controlloCarattere(10); cout<<tb[10]; SetColor(7,0);cout<<" | "; controlloCarattere(11); cout<<tb[11]; SetColor(7,0);cout<<" | "; controlloCarattere(12); cout<<tb[12]; SetColor(7,0);cout<<" | "; controlloCarattere(13); cout<<tb[13]; SetColor(7,0);cout<<" |" << endl;
	cout << "                                    |____|____|____|____|____|____|____|____|____|____|____|____|____|____|" << endl;
	cout << "                                    |    |                                |                          |    |" << endl;
	cout << "                           FINE__ __| "; controlloCarattere(39); cout<<tb[39]; SetColor(7,0);cout<<" |                                |                          | "; controlloCarattere(14); cout<<tb[14]; SetColor(7,0);cout<<" |" << endl;
	cout << "                                    |____|                        avanti di 3 caselle                |____|" << endl;
	cout << "                                    |    |                                                           |    |" << endl;
	cout << "                                    | "; controlloCarattere(38); cout<<tb[38]; SetColor(7,0);cout<<" |                                                           | "; controlloCarattere(15); cout<<tb[15]; SetColor(7,0);cout<<" |" << endl;
	cout << "                                    |____|                                                           |____|" << endl;
	cout << "                                    |    |                                                           |    |" << endl;
	cout << "                                    | "; controlloCarattere(37); cout<<tb[37]; SetColor(7,0);cout<<" |                                                           | "; controlloCarattere(16); cout<<tb[16]; SetColor(7,0);cout<<" |" << endl;
	cout << "                                    |____|                                                           |____|" << endl;
	cout << "                                    |    |                                                           |    |" << endl;
	cout << "                                    | "; controlloCarattere(36); cout<<tb[36]; SetColor(7,0);cout<<" |                                         fermo 1 turno__ __| "; controlloCarattere(17); cout<<tb[17]; SetColor(7,0);cout<<" |" << endl;
	cout << "                                    |____|                                                           |____|" << endl;
	cout << "                                    |    |                                                           |    |" << endl;
	cout << "                                    | "; controlloCarattere(35); cout<<tb[35]; SetColor(7,0);cout<<" |__ __indietro di 8 caselle                                 | "; controlloCarattere(18); cout<<tb[18]; SetColor(7,0);cout<<" |" << endl;
	cout << "                                    |____|                                                           |____|" << endl;
	cout << "                                    |    |       avanti di 2 caselle      torni al punto di partenza |    |" << endl;
	cout << "                                    | "; controlloCarattere(34); cout<<tb[34]; SetColor(7,0);cout<<" |                 |                        |                | "; controlloCarattere(19); cout<<tb[19]; SetColor(7,0);cout<<" |" << endl;
	cout << "                                    |____|_________________|________________________|________________|____|" << endl;
	cout << "                                    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |" << endl;
	cout << "                                    | "; controlloCarattere(33); cout<<tb[33]; SetColor(7,0);cout<<" | "; controlloCarattere(32); cout<<tb[32]; SetColor(7,0);cout<<" | "; controlloCarattere(31); cout<<tb[31]; SetColor(7,0);cout<<" | "; controlloCarattere(30); cout<<tb[30]; SetColor(7,0);cout<<" | "; controlloCarattere(29); cout<<tb[29]; SetColor(7,0);cout<<" | "; controlloCarattere(28); cout<<tb[28]; SetColor(7,0);cout<<" | "; controlloCarattere(27); cout<<tb[27]; SetColor(7,0);cout<<" | "; controlloCarattere(26); cout<<tb[26]; SetColor(7,0);cout<<" | "; controlloCarattere(25); cout<<tb[25]; SetColor(7,0);cout<<" | "; controlloCarattere(24); cout<<tb[24]; SetColor(7,0);cout<<" | "; controlloCarattere(23); cout<<tb[23]; SetColor(7,0);cout<<" | "; controlloCarattere(22); cout<<tb[22]; SetColor(7,0);cout<<" | "; controlloCarattere(21); cout<<tb[21]; SetColor(7,0);cout<<" | "; controlloCarattere(20); cout<<tb[20]; SetColor(7,0);cout<<" |" << endl;
	cout << "                                    |____|____|____|____|____|____|____|____|____|____|____|____|____|____|" << endl;
	}

int main()
{
        //regole di gioco
        cout << "Questo gioco e' stato sviluppato da: Coacci Nicola" << endl;
        cout << "Volete visualizzare le regole di gioco? (y/n)" << endl;
        cin >> regole;
        cout << endl;
        if (regole == 'y')
        {
            cout << "REGOLE: " << endl;
            cout << "Il gioco dell'oca e' un tradizionale gioco formato da un percorso da completare affidandosi unicamente alla propria fortuna nel lanciare i dadi. E' adatto ad ogni eta'." << endl;
            cout << "Il tabellone di gioco e' formato da una griglia di 40 caselle. Ogni giocatore a turno lancera' un dado e il primo che arrivera' alla casella 40 vince!";
            cout << "Se pero' un giocatore lanciando il dado supera la casella 40 torna indietro (Es. se sono alla casella 39 e lanciando il dado esce 4, torno alla casella 37) " << endl;
            cout << "ATTENZIONE!! ci sono delle caselle speciali che possono darti un vantaggio o uno svantaggio:" << endl;
            cout << "CASELLA 8: vai avanti di 3 caselle!" << endl << "CASELLA 18: stai fermo un turno!" << endl;
            cout << "CASELLA 25: torni al punto di partenza!" << endl << "CASELLA 30: vai avanti di 2 caselle!" << endl;
            cout << "CASELLA 36: torni indietro di 8 caselle!" << endl;
            cout << "ORA SIETE PRONTI PER GIOCARE!!! BUON DIVERTIMENTO!!!" << endl << endl;
        }
        else
             cout << "Bene visto che sapete gia' giocare, BUON DIVERTIMENTO!!" << endl << endl;
		system ("pause");
        system ("cls");

        ifstream load;
        ofstream save;
        bool overwrite = true;
        load.open("memory.save");
        //controllo se il file di salvataggio esiste
        if(load.good()) {
            char resume;
            std::cout << "Salvataggio trovato, vuoi continuare da dove avevi lasciato l'ultima volta? (y/n) ";
            cin >> resume;
            //chiedo se i giocatori vogliono continuare l'ultima sessione salvata
            switch (resume) {
            case 'y':
                load >> I1 >> I2;
                break;
            case 'n':
                overwrite = false;
                break;
            }
            load.close();
        } else {
            load.close();
        }

        cout << "Vuoi giocare contro un tuo amico o contro il computer? (a=amico/p=computer)" << endl;
        cin >> vs;
        cout << endl;
        if (vs == 'a')
        {
            cout << "Inserisci il nome del primo giocatore!" << endl;
            cin >> nome1;
            cout << "Inserisci il nome del secondo giocatore!" << endl;
            cin >> nome2;
            system ("cls");
            while (c == 0)
            {
                //inizio del gioco
				system("pause");
				system("cls");
                while(I1 < 40 && I2 < 40)
                {
                    //turno di I1
                    cout << endl;
                    tirodado(I1);
                    if (I1 > 40)
                    {
                        O = I1 - 40;
                        I1 = 40 -O;
                    }

                    casella(I1,I2);

                    //turno di I2
                    if (I1 < 40)
                    {
                        cout << endl;

                            tirodado(I2);
                            if (I2 > 40)
                            {
                                O = I2 - 40;
                                I2 = 40 -O;
                            }

                        casella(I2,I1);
                        tabella();
                        //se posso sovrascrivere inserisco i punteggi sul file
                        if(overwrite) {
                            save.open("memory.save");
                            save << I1 << endl << I2;
                            save.close();
                        }
						system("pause");
                        system ("cls");
                    }
                }
                if((I1 == 40) && (I2 == 40))
                    cout << "WOW E' UN PAREGGIO!!" << endl;
                else
                    if (I1 == 40)
                       cout << "COMPLIMENTI " << nome1 <<", HAI VINTO!!" << endl;
                    else
                        cout << "COMPLIMENTI " << nome2 << ", HAI VINTO!!" << endl;
                win();
				system("pause");
                system("cls");

                cout << "Volete rigiocare? (y/n)" << endl;
                cin >> risposta;
                if (risposta == 'y')
                {
                    I1 = 0;
                    I2 = 0;
                    c = 0;
                }
                else
                    c = 1;
        }
    }
    else
    {
        if(vs == 'p')
        {
            cout << "Inserisci il tuo nome!" << endl;
            cin >> nome1;
            nome2 = "computer";
            system ("cls");
            while (c == 0)
            {
                //inizio del gioco

                system("pause");
				system("cls");

                while(I1 < 40 && I2 < 40)
                {
                    tirodado(I1);
                    if (I1 > 40)
                    {
                        O = I1 - 40;
                        I1 = 40 -O;
                    }

                    casella(I1,I2);

                    //turno del computer
                    if (I1 < 40)
                    {
                            tirodado(I2);
                            if (I2 > 40)
                            {
                                O = I2 - 40;
                                I2 = 40 -O;
                            }

                            casella(I2,I1);
                            tabella();
                            //se posso sovrascrivere inserisco i punteggi sul file
                            if(overwrite) {
                                save.open("memory.save");
                                save << I1 << endl << I2;
                                save.close();
                            }
							system("pause");
                            system ("cls");
                        }
                }
                if((I1 == 40) && (I2 == 40))
                    cout << "WOW E' UN PAREGGIO!!" << endl;
                else
                    if (I1 == 40)
                    {
                        cout << "COMPLIMENTI " << nome1 <<", HAI VINTO!!" << endl;
                        win ();
                    }

                    else
                    {
                        cout << "PECCATO, HA VINTO IL COMPUTER!!" << endl;
                        lose ();
                    }
                system("cls");

                cout << "Vuoi rigiocare? (y/n)" << endl;
                cin >> risposta;
                if (risposta == 'y')
                {
                    I1 = 0;
                    I2 = 0;
                    c = 0;
                }
                else
                    c = 1;
            }
        }
    }
}



