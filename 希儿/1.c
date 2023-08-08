#include "2.h"

_Choose MenuChoose = none;
int main()
{
    Infor_CreateLinkHead();
 File_ReadLink();
    int s = 0;
    while (1)
    {
      
start:
        System_Menu();
        scanf("%u", &MenuChoose);
        switch (MenuChoose)
        {
        case add:
            Infor_AddPerson();
            continue;
        case delete:
            Infor_delete();
            continue;
        case change:
            Infor_changePerson();
            continue;
        case find:
            Infor_find();
            continue;
        case quit:
            s = quitt();
            if( s == 1)
            {
                system("clear");
                continue;
            }
            else if(s == 0)
            {
                system("clear");
                goto _PPquit;
            }
        default:
            while(1)
            {
                print_text(COLOR(33) "      ♥  输入不合法,请重新输入 ♥   \n\n\n\n\n");
                while(getchar() != '\n');    // 清除全部缓冲区
                goto start;
            }

           
        }
    }
_PPquit:;
File_WriteLink();
 return 0;
}

