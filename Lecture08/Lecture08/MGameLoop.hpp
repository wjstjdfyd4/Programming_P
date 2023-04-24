#pragma once //#define _IS_THIS_HEADER_INCLUDED
#include <Windows.h>
#include <conio.h>

#define Key_Exit 27
#define Key_RIGHT 'd'
#define Key_LEFT 'a'
#define Key_ENTER 13

namespace MuSoeun
{
	void gotoxy(int x, int y)
	{
		//x,y ��ǥ ����
		COORD pos = { x,y };
		//Ŀ�� �̵�
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	class MGameLoop
	{
	public :
		
		bool isGameRunning = false;

		MGameLoop(){}
		~MGameLoop(){}

		void Initialize()
		{
			gotoxy(0, 10);
			isGameRunning = true;
			std::cout << "�ʱ�ȭ �Ϸ�" <<std:: endl;
		}

		void Release()
		{
			gotoxy(0, 10);
			std::cout << "�ý��� ���� �Ϸ�" <<std:: endl;
		}

		void Update()
		{
			gotoxy(0, 10);
			std::cout << "������Ʈ�� �Ϸ�" << std::endl;

			if (_kbhit())
			{
				keyEvent(_getch());
			}
			/*char a;
			a=getchar();

			if (a == '1')
			{
				isGameRunning = false;
			}*/
		}
		void Render()
		{
			gotoxy(0, 10);
			std::cout << "������ �Ϸ�" << std::endl;
		}


		void Run()
		{
			Initialize();

			while (isGameRunning)
			{
				Update();
				Render();
			}

			Release();
	
		}

		void keyEvent(char Keyinput)
		{
			switch (Keyinput)
			{
			case Key_LEFT:  //32 : ���� ȭ��ǥŰ
				gotoxy(2, 5);
				std::cout << "������ ���ȴ� ! " << std::endl;
				break;
			case Key_RIGHT:  //32 : ������ ȭ��ǥŰ
				gotoxy(2, 5);
				std::cout << "�������� ���ȴ� ! " << std::endl;
				break;
				/*27 : esc ���� ����Ű �Դϴ� 
				* �ѹ� �������� �Ͻ�����
				* �ι� �������� ���� ����
				*/
			case Key_Exit:
				isGameRunning = false;
				//24�� 8��������				
				std::cout << "���� ������ �����Ͻðڽ��ϱ�?" << std::endl;
				break;
			case Key_ENTER:  //13 : ����Ű
				gotoxy(2, 5);
				std::cout << "���� ��ư�� ���ȴ� ! " << std::endl;
				break;
			default:
				break;
			}
		}
	};
}