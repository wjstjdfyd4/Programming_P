#define DEBUG
#include <iostream>
#include <conio.h>
#include <Windows.h>

const int MAX_STAGE_WIDTH = 30;
const int MAX_STAGE_HEIGHT = 20;

// game_state == 0 일때
int print_title_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*              지렁이 게임               *" << std::endl;
    std::cout << "*             (Snake  Bite)              *" << std::endl;

#ifdef DEBUG
    std::cout << "*            - 디버그 모드 -             *" << std::endl;
#else
    std::cout << "*                                        *" << std::endl;
#endif  
    std::cout << "*   1. 게임 시작                         *" << std::endl;
    std::cout << "*   2. 게임 설명                         *" << std::endl;
    std::cout << "*   3. 게임 랭킹 보기                    *" << std::endl;
    std::cout << "*   4. 게임 종료 (esc)                   *" << std::endl;
    std::cout << "******************************************" << std::endl;

    return 0;
}

void gotoxy(int x, int y) {
    //x, y 좌표 설정
    COORD pos = { x,y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int print_game_screen(int stage_width, int stage_height)
{
    // 2차원 배열을 만들고 초기화
    char** stage = new char* [stage_height];
    for (int i = 0; i < stage_height; i++) {
        stage[i] = new char[stage_width];
        memset(stage[i], '.', stage_width);
    }

    // 외곽에 '#' 문자를 채우기
    for (int i = 0; i < stage_width; i++) {
        stage[0][i] = '#';
        stage[stage_height - 1][i] = '#';
    }
    for (int i = 0; i < stage_height; i++) {
        stage[i][0] = '#';
        stage[i][stage_width - 1] = '#';
    }

    // 스테이터스 출력
    for (int i = 0; i < stage_height; i++) {
        for (int j = 0; j < stage_width; j++) {
            std::cout << stage[i][j];
        }
        std::cout << std::endl;
    }

    // 동적 할당한 메모리 반환
    for (int i = 0; i < stage_height; i++) {
        delete[] stage[i];
    }
    delete[] stage;

    return 0;
}

// game_state == 2 일때
int print_introduction_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "타이틀화면으로 돌아갈까요? (Y/N)" << std::endl;
    return 0;
}

int main()
{

    int game_state = 0;
    int is_game_running = 1;

    while (is_game_running)
    {
        char key_input = '0';
        switch (game_state)
        {
        case 0:
            print_title_screen();
            key_input = _getch();
            switch (key_input)
            {
            case '1':
                game_state = 1;
                break;
            case '2':
                game_state = 2;
                break;
            case '3':
                break;
            case '4':
                is_game_running = 0;
                break;
            case 27:
                is_game_running = 0;
                break;
            default:
                break;
            }
            break;
        case 1:
            print_game_screen(10, 10);
            key_input = _getch();
        case 2:
            print_introduction_screen();
            key_input = _getch();
            switch (key_input)
            {
            case 'y':
                game_state = 0;
                break;
            case 'n':
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
