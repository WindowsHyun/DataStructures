#include <stdio.h>
#include <windows.h>
 
void gotoxy(int x, int y);
 
void main()
{
    int save[8][8] = {0, };
    int delta_x[8] = {1, 1, 0, -1, -1, -1, 0, 1};   // 3시 위치부터 시계방향
    int delta_y[8] = {0, 1, 1, 1, 0, -1, -1, -1};   // 3시 위치부터 시계방향
    int x, y;       // 입력 좌표
    int xi, yi;     // 조사를 하기 위한 좌표
    int i, j, k;
    int turn = 2;   // 순서
    int count1 = 0, count2 = 0; // 백돌수, 흑돌수
    int dir, changed;   // 조사방향(8방향), 변화된 돌 수
 
    printf("        0     1     2     3     4     5     6     7   \n"); //흑돌 2 백돌 1
    printf("    ┏━━┳━━┳━━┳━━┳━━┳━━┳━━┳━━┓\n");
    printf(" 0  ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃\n");
    printf("    ┣━━╋━━╋━━╋━━╋━━╋━━╋━━╋━━┫\n");
    printf(" 1  ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃\n");
    printf("    ┣━━╋━━╋━━╋━━╋━━╋━━╋━━╋━━┫\n");
    printf(" 2  ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃\n");
    printf("    ┣━━╋━━╋━━╋━━╋━━╋━━╋━━╋━━┫\n");
    printf(" 3  ┃    ┃    ┃    ┃ ● ┃ ○ ┃    ┃    ┃    ┃\n");
    printf("    ┣━━╋━━╋━━╋━━╋━━╋━━╋━━╋━━┫\n");
    printf(" 4  ┃    ┃    ┃    ┃ ○ ┃ ● ┃    ┃    ┃    ┃\n");
    printf("    ┣━━╋━━╋━━╋━━╋━━╋━━╋━━╋━━┫\n");
    printf(" 5  ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃\n");
    printf("    ┣━━╋━━╋━━╋━━╋━━╋━━╋━━╋━━┫\n");
    printf(" 6  ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃\n");
    printf("    ┣━━╋━━╋━━╋━━╋━━╋━━╋━━╋━━┫\n");
    printf(" 7  ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃\n");
    printf("    ┗━━┻━━┻━━┻━━┻━━┻━━┻━━┻━━┛\n");
 
    save[3][3] = 2;
    save[4][4] = 2;
    save[3][4] = 1;
    save[4][3] = 1;
 
    while(1)
    {  
        gotoxy(0, 20); //입력부분, 잘못된 입력입니다 올바르게 입력했을경우 화면 클리어
        printf("                    ");
        gotoxy(0, 21);
        printf("                    ");
        gotoxy(0, 22);
        printf("                    ");
 
        // 돌이 다 놓여졌으면 게임끝
        if(count1 + count2 == 64) break;
 
        while(1)
        {
            gotoxy(0, 19);
            if(turn == 2)
                printf("흑돌의 차례입니다.");
            else
                printf("백돌의 차례입니다.");
            gotoxy(0, 18);
            printf("입력은 가로좌표부터입니다.");
            gotoxy(0, 20);
            scanf("%d %d",&x, &y); //배열 좌표를 입력
 
            // 바뀌는 돌이 있는지 조사
            // 방금 놓인 돌의 좌료를 중심으로 8방향을 조사하여
            // 연속적으로 상대 돌이 존재하고 그 끝에 자신의 돌이 있으면 바꿀 수 있다
            // 즉, 상대방 돌을 가로막을 수 있으면 그 돌들 모두를 자신의 돌로 바꿀 수 있다
            changed = 0;    // 바뀐 돌 수
            for(dir = 0; dir < 8; dir++)    // 8방향 조사
            {
                xi = x; // 기준 좌표
                yi = y; // 기준 좌표
                j = 0;  // 현재 방향에서 연속된 상대 돌 수
                for(i = 0; i < 7; i++)  // 현재방향에서 1씩 증가 또는 감소
                {
                    xi += delta_x[dir]; // 검사 위치 좌표
                    yi += delta_y[dir]; // 검사 위치 좌표
                    if(xi < 0 || xi > 7 || yi < 0 || yi > 7 || save[xi][yi] == 0)   // 범위를 벗어나면 조사 중단
                        break;
                    if(save[xi][yi] == turn)    // 자신의 돌이 발견되면
                    {
                        for( ; i > 0; i--)  // 역으로 추적하면서 상대 돌을 자신의 돌로 바꿈
                        {
                            xi -= delta_x[dir];
                            yi -= delta_y[dir];
                            save[xi][yi] = turn;
                        }
                        changed += j;   // 방향 전체를 통해 바뀔 수 있는 돌 수 증가
                        break;
                    }
                    j++;    // 현재 방향에서 연속된 상대 돌 수 증가
                }
            }
 
            // 전체 방향으로 모두 조사한 후 바꿀 수 있는 돌이 있다면
            if(changed)
            {
                save[x][y] = turn;      // 방금 놓은 위치
                count1 = count2 = 0;    // 전체 돌 수 계산
                for(i = 0; i < 8; i++)
                {
                    for(j = 0; j < 8; j++)
                    {
                        if(save[i][j] == 2)
                        {
                            gotoxy(i * 6 + 7, j * 2 + 2);
                            printf("●");
                            count2++;
                        }
                        else if(save[i][j] == 1)
                        {
                            gotoxy(i * 6 + 7, j * 2 + 2);
                            printf("○");
                            count1++;
                        }
                    }
                }
                turn = 3 - turn;    // 상대방으로 순서 바꿈
            }
            else
            {
                gotoxy(0, 22);
                printf("잘못된 입력입니다.");
            }
        }
    }
 
    gotoxy(0, 22);
    printf("백돌 : %d개, 흑돌 : %d개\n", count1, count2);
    if(count1 > count2)
        printf("백이 승리하였습니다.\n");
    else if(count2 > count1)
        printf("흑이 승리하였습니다.\n");
    else
        printf("서로 비겼습니다.\n");
}  
 
void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}