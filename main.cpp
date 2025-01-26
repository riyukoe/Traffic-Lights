#include <iostream>
#include <windows.h>
#include <thread>
using namespace std;

int Lights = 1;

void gotoxy(int x, int y)//used to change text cursor position (Don't touch)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void street()//makes the road format
{
    int x = 9;

    for(int a = 0; a < 2; a++)// top part of the highway
    {
        for(int i = 0; i < 4; i++)
        {
            gotoxy(x,i);
            cout << "|";
        }
        x = 15;
    }
    x = 9;
    for(int a = 0; a < 2; a++)// bottom part of the highway
    {
        for(int i = 11; i < 15; i++)
        {
            gotoxy(x,i);
            cout << "|";
        }
        x = 15;
    }
    x = 4;
    for(int a = 0; a < 2; a++)  // left part of the side road
    {
        for(int i = 0; i < 9; i++)
        {
            gotoxy(i,x);
            cout << "=";
        }
        x = 10;
    }
    x = 4;
    for(int a = 0; a < 2; a++) // right part of the side road
    {
        for(int i = 16; i < 26; i++)
        {
            gotoxy(i,x);
            cout << "=";
        }
        x = 10;
    }
    x = 12;
    for(int i = 0; i < 15; i++) //middle part of the highway
    {
        gotoxy(x,i);
        if(i < 4 || i > 10 )
                cout << "|";
    }
    x = 7;
    for(int a = 0; a < 2; a++) //middle part of the side road
    {
        for(int i = 0; i < 26; i++)
        {
            gotoxy(i,x);
            if(i < 9 || i > 15 )
                cout << "-";
        }
    }

    gotoxy(13,11);
    cout << "A";
    gotoxy(7,8);
    cout << "B";
    gotoxy(17,6);
    cout << "C";

    gotoxy(0,15);
    cout << "Highway: Green";
    gotoxy(0,16);
    cout << "Top Cross Roads: Red";
    gotoxy(0,17);
    cout << "Bottom Cross Roads: Red";

}

void UpdateA(int a) //A checks direction
{
    switch(a)
    {
        case 1:
            gotoxy(13,11);
            cout << " ";
            gotoxy(13,8);
            cout << "A";
            Sleep(1000);

            gotoxy(13,8);
            cout << " ";
            gotoxy(11,6);
            cout << "A";
            Sleep(1000);

            gotoxy(11,6);
            cout << " ";
            gotoxy(7,5);
            cout << "A";
            break;
        case 2:
            gotoxy(13,11);
            cout << " ";
            gotoxy(14,10);
            cout << "A";
            Sleep(1000);

            gotoxy(14,10);
            cout << " ";
            gotoxy(17,9);
            cout << "A";
            break;
        case 3:
            gotoxy(13,11);
            cout << " ";
            gotoxy(13,7);
            cout << "A";
            Sleep(1000);

            gotoxy(13,7);
            cout << " ";
            gotoxy(13,2);
            cout << "A";
            break;

        default:
            cout << "Lol" << endl;
    }
}

void UpdateB(int a) // A checks direction
{
    switch(a)
    {
        case 1:
            gotoxy(7,8);
            cout << " ";
            gotoxy(12,7);
            cout << "B";
            Sleep(1000);

            gotoxy(12,7);
            cout << " ";
            gotoxy(13,3);
            cout << "B";
            break;
        case 2:
            gotoxy(7,8);
            cout << " ";
            gotoxy(10,9);
            cout << "B";
            Sleep(1000);

            gotoxy(10,9);
            cout << " ";
            gotoxy(10,11);
            cout << "B";
            break;
        case 3:
            gotoxy(7,8);
            cout << " ";
            gotoxy(13,8);
            cout << "B";
            Sleep(1000);

            gotoxy(13,8);
            cout << " ";
            gotoxy(17,8);
            cout << "B";
            break;
        default:
            cout << "Lol" << endl;
    }
}

void UpdateC(int a) // A checks direction
{
    switch(a)
    {
        case 1:
            gotoxy(17,6);
            cout << " ";
            gotoxy(12,7);
            cout << "C";
            Sleep(1000);

            gotoxy(12,7);
            cout << " ";
            gotoxy(11,11);
            cout << "C";
            break;
        case 2:
            gotoxy(17,6);
            cout << " ";
            gotoxy(15,5);
            cout << "C";
            Sleep(1000);

            gotoxy(15,5);
            cout << " ";
            gotoxy(14,3);
            cout << "C";
            break;
        case 3:
            gotoxy(17,6);
            cout << " ";
            gotoxy(13,6);
            cout << "C";
            Sleep(1000);

            gotoxy(13,6);
            cout << " ";
            gotoxy(7,6);
            cout << "C";
            break;
        default:
            cout << "Lol" << endl;
    }
}

void Allofthelights() //Traffic light for the roads
{       //If Lights is 1 highway is red then the bottom cross road is green and the top one is red
    switch(Lights)//if 2 highway is red, bottom cross road is red, and top cross road is green
    {//Programs starts with Highway as green
        case 1:
            Sleep(3000);            //Switch case to filter through which traffic light is green or red
            gotoxy(9,15);
            cout << "Yellow" << endl;
            Sleep(5000);

            gotoxy(9,15);
            cout << "Red   " << endl;
            gotoxy(20,17);
            cout << "Green " << endl;
            Lights = 2;
            break;

        case 2:
            Sleep(3000);
            gotoxy(20,17);
            cout << "Yellow" << endl;
            Sleep(5000);

            gotoxy(20,17);
            cout << "Red   " << endl;
            gotoxy(17,16);
            cout << "Green " << endl;
            Lights = 3;
            break;
        case 3:
            Sleep(3000);
            gotoxy(17,16);
            cout << "Yellow" << endl;
            Sleep(5000);

            gotoxy(17,16);
            cout << "Red   " << endl;
            gotoxy(9,15);
            cout << "Green " << endl;
            Lights = 1;
            break;
        default:
            cout << "Lol";
            break;
    }
}

bool CheckInput(int check) //checks if the input is within the options
{
    if(check < 1 || check > 3)
    {
        gotoxy(0,22);
        cout << "Wrong Input. Please try again.";
        return true;
    }
    else
    {
        gotoxy(0,22);
        cout << "                              ";
        return false;
    }
}

int main()
{
    int wayA = 0, wayB = 0, wayC = 0;

    street(); //initializes the visuals

    WrongA: //Label to go back to when Input for A is wrong
    gotoxy(0,18);//coordinates to be printed at
 	cout << "1 - Left\n2 - Right\n3 - Straight\n"
         << "Please input direction for car A: ";
    cin >> wayA;

    if(CheckInput(wayA))
        goto WrongA;

    thread CA(UpdateA,wayA);
    thread t1(Allofthelights);
    CA.join();
    t1.join();

    WrongB: //Label to go back to when Input for B is wrong
    gotoxy(0,18);
    cout << "1 - Left\n2 - Right\n3 - Straight\n"
         << "Please input direction for car B:  ";
    cin >> wayB;

    if(CheckInput(wayB))
        goto WrongB;

    thread CB(UpdateB,wayB);
    thread t2(Allofthelights);
    CB.join();
    t2.join();

    WrongC: //Label to go back to when Input for C is wrong
    gotoxy(0,18);
    cout << "1 - Left\n2 - Right\n3 - Straight\n"
         << "Please input direction for car C:   ";
    cin >> wayC;

    if(CheckInput(wayC))
        goto WrongC;

    thread CC(UpdateC,wayC);
    thread t3(Allofthelights);
    CC.join();
    t3.join();

    gotoxy(0,22);
    system("pause");
    return 0;
}
