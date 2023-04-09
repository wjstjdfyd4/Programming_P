#include <iostream>
#include <conio.h>

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 10;

int print_title_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*              지렁이 게임               *" << std::endl;
    std::cout << "*             (Snake  Bite)              *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*   1. 게임 시작                         *" << std::endl;
    std::cout << "*   2. 게임 설명                         *" << std::endl;
    std::cout << "*   3. 게임 랭킹 보기                    *" << std::endl;
    std::cout << "*   4. 게임 종료 (esc)                   *" << std::endl;
    std::cout << "******************************************" << std::endl;

    return 0;
}

int print_introduction_screen()
{
    std::cout << "타이틀화면으로 돌아갈까요? (Y/N)" << std::endl;
    return 0;
}

int print_board()
{
    std::cout << " ";
    for (int i = 0; i < BOARD_WIDTH; ++i)
    {
        std::cout << "_";
    }
    std::cout << std::endl;

    for (int i = 0; i < BOARD_HEIGHT; ++i)
    {
        std::cout << "|";
        for (int j = 0; j < BOARD_WIDTH; ++j)
        {
            std::cout << "#";
        }
        std::cout << "|" << std::endl;
    }

    std::cout << " ";
    for (int i = 0; i < BOARD_WIDTH; ++i)
    {
        std::cout << "_";
    }
    std::cout << std::endl;

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
            switch(key_input)
            {
            case '1':
                std::cout << "^^" << std::endl;
                print_board();
                is_game_running = 0;
                break;
            case '2':
                game_state = 2;
                break;
            case '3':
                break;
            case '4':
            case 27:
                is_game_running = 0;
                break;
            default:
                break;
            }
            break;
        case 2:
            print_introduction_screen();
            key_input = _getch();
            switch (key_input)
            {
            case 'y':
            case 'Y':
                game_state = 0;
                break;
            case 'n':
            case 'N':
                is_game_running = 0;
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
