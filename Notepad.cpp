#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include<Windows.h>
#include<stdlib.h>

using namespace std;

void gotoxy(int x, int y)
{

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

class node
{
public:
    char data;
    node* next;
    node* prev;
    node* up;
    node* down;
    node(char c)
    {
        data = c;
        next = NULL;
        prev = NULL;
        up = NULL;
        down = NULL;
    }
};

class Notepad
{
    node* first;
	node* cursor;

public:

    Notepad()
    {
        first = NULL;
        cursor = NULL;
    }

    void Insertion(char c)
    {
        node* temp = new node(c);
        node* temp2 = new node(' | ');
        if (first == NULL)
        {
            first = temp;
            cursor = temp;
        }
        else
        {
            if (cursor->next == NULL)
            {
                cursor->next = temp;
                temp->prev = cursor;
                cursor = temp;
            }
            else
            {
                temp->next = cursor->next;
                cursor->next->prev = temp;
                cursor->next = temp;
                temp->prev = cursor;
                cursor = temp;
            }
        }
    }

    void Printing()
    {
        node* temp = first;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
    }

    void Save()
    {
        ofstream file("file.txt");
        if (!file.is_open()) {
            cout << "Failed to open the file!" << endl;
            return;
        }

        node* temp = first;
        while (temp != NULL) {
            file << temp->data;
            temp = temp->next;
        }

        file.close();
    }
  void PrintCursor()
    {
        node* temp = first;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
        while (temp != NULL)
        {
            if (temp == cursor)
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 3);
                cout << "|";
            }
            cout << temp->data;
            temp = temp->next;
        }
    }
    void Load()
    {
        ifstream file("file.txt");
        if (!file.is_open()) {
            cout << "Failed to open the file!" << endl;
            return;
        }

        node* temp = first;
        while (temp != NULL) {
            node* next = temp->next;
            delete temp;
            temp = next;
        }
        first = NULL;
        cursor = NULL;

        char c;
        while (file >> c) {
            Insertion(c);
        }

        file.close();
    }



    void Up()
    {
        if (cursor->up != NULL)
        {
            cursor = cursor->up;
        }
    }

    void Down()
    {
        if
            (cursor->down != NULL)
        {
            cursor = cursor->down;
        }
    }

    void Left()
    {
        if (cursor->prev != NULL)
        {
            cursor = cursor->prev;
        }
    }

    void Right()
    {
        if (cursor->next != NULL)
        {
            cursor = cursor->next;
        }
    }

  

    void PrintCursor(int x, int y)
    {
        node* temp = first;
        int i = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
        while (temp != NULL)
        {
            if (temp == cursor)
            {
                gotoxy(x + i, y);
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 3);
                cout << "|";
            }
            gotoxy(x + i, y);
            cout << temp->data;
            temp = temp->next;
            i++;
        }
    }

   void PrintAll(int x, int y, int start, int end)
    {
        node* temp = first;
        int i = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

        while (temp != NULL)
        {
            if (temp == cursor)
            {
                gotoxy(x + i, y);
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 3);
                cout << "|";
            }
            gotoxy(x + i, y);
            cout << temp->data;
            temp = temp->next;
            i++;
        }
    }

    void New_line()
    {
        node* temp = new node('\n');
        if (cursor->next == NULL)
        {
            cursor->next = temp;
            temp->prev = cursor;
            cursor = temp;
        }
        else
        {
            temp->next = cursor->next;
            cursor->next->prev = temp;
            cursor->next = temp;
            temp->prev = cursor;
            cursor = temp;
        }
    }


    void PrintCursor(int x, int y, int start, int end)
    {
        node* temp = first;
        int i = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

        while (temp != NULL)
        {
            if (temp == cursor)
            {
                gotoxy(x + i, y);
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 3);
                cout << "|";
            }
            gotoxy(x + i, y);
            cout << temp->data;
            temp = temp->next;
            i++;
        }
    }


 

    void PrintAll()
    {
        node* temp = first;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
        while (temp != NULL)
        {
           
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h, 3);
            cout << temp->data;
             if (temp == cursor)
            {
                
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 7);
                cout << "|";
            }
            temp = temp->next;
        }
    }
    void Deletion()
    {
        if (cursor->next == NULL)
        {
            if (cursor->prev == NULL)
            {
                delete cursor;
                cursor = NULL;
                first = NULL;
            }
            else
            {
                cursor = cursor->prev;
                delete cursor->next;
                cursor->next = NULL;
            }
        }
        else
        {
            if (cursor->prev == NULL)
            {
                first = cursor->next;
                delete cursor;
                cursor = first;
                cursor->prev = NULL;
            }
            else
            {
                cursor->prev->next = cursor->next;
                cursor->next->prev = cursor->prev;
                node* temp = cursor;
                cursor = cursor->next;
                delete temp;
            }
        }
    }
    void PrintAll(int x, int y)
    {
        node* temp = first;
        int i = 0;
        while (temp != NULL)
        {
            gotoxy(x + i, y);
            cout << temp->data;
            temp = temp->next;
            i++;
        }
    }



 
};


int main()
{
	system("color A1");
	 cout << "			----------------Notepad------------" << endl;
    cout << "For Save: Press escape" << endl;
    cout << "For Load: Press L" << endl;
    cout << "For up: Press H" << endl;
    cout << "For down: Press P" << endl;
    cout << "For left: Press K" << endl;
    cout << "For right: Press M" << endl;
    //TO save file first make file.txt in solution explorer
    Notepad t;
   
    t.PrintAll();
    char c;
    while (1)
    {
        c = _getch();
        if (c == 13)
        {
            t.New_line();
        }
        else if (c == 8)
        {
            t.Deletion();
        }
        else if (c == 27)
        { //excape key
            t.Save();
            break;
        }
        else if (c == 72)
        {
            t.Up();
        }
        else if (c == 80)
        {
            t.Down();
        }
        else if (c == 75)
        {
            t.Left();
        }
        else if (c == 77)
        {
            t.Right();
        }
        else if(c=='L'){
        	t.Load();		
        }
		else
		{
            t.Insertion(c);
        }
        system("cls");
        t.PrintAll();
    }
    return 0;
}
