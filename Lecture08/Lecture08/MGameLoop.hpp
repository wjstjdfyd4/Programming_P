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
		//x,y 좌표 설정
		COORD pos = { x,y };
		//커서 이동
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
			std::cout << "초기화 완료" <<std:: endl;
		}

		void Release()
		{
			gotoxy(0, 10);
			std::cout << "시스템 해제 완료" <<std:: endl;
		}

		void Update()
		{
			gotoxy(0, 10);
			std::cout << "업데이트중 완료" << std::endl;

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
			std::cout << "렌더링 완료" << std::endl;
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
			case Key_LEFT:  //32 : 왼쪽 화살표키
				gotoxy(2, 5);
				std::cout << "왼쪽이 눌렸다 ! " << std::endl;
				break;
			case Key_RIGHT:  //32 : 오른쪽 화살표키
				gotoxy(2, 5);
				std::cout << "오른쪽이 눌렸다 ! " << std::endl;
				break;
				/*27 : esc 게임 종료키 입니다 
				* 한번 눌렀을땐 일시정지
				* 두번 눌렀을땐 게임 종료
				*/
			case Key_Exit:
				isGameRunning = false;
				//24일 8주차과제				
				std::cout << "정말 게임을 종료하시겠습니까?" << std::endl;
				break;
			case Key_ENTER:  //13 : 엔터키
				gotoxy(2, 5);
				std::cout << "엔터 버튼이 눌렸다 ! " << std::endl;
				break;
			default:
				break;
			}
		}
	};
}