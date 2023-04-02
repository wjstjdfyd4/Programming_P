#include <iostream>
#include <conio.h>
int main(void)
{
    char ch;
    while(true)
    {
        std::cout << "Hi !!\n";
        if (_kbhit())
        {
            ch = _getch();
            std::cout << ch;
            if(ch == 27)
            {
                std::cout << "exit" <<std::endl;
                break;
            }
        }

    }
    return 0;
}
