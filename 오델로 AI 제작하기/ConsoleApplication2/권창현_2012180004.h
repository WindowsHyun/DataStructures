#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define LEFT   75      // 좌측방향키
#define RIGHT  77      // 우측방향키
#define UP     72      // 위쪽방향키
#define DOWN   80      // 아래방향키
#define ENTER   13      // Enter키
#define SPACE   32      // Space키
#define isOdelloData 8 // 오델로 판
#define isAiArrangement 20 // AI 배열 판
#define isAiTempData 3 // AI 배열 판
#define isGameTheEndData isOdelloData*isOdelloData // 총 돌의 갯수
#define isWaitTime 1 // AI 대기시간
#define isSpace 32 // 띄어쓰기 한칸 <아스키코드표>

void WhiteAttck_2012180004(int*, int*);
void WhiteDefence_2012180004(int, int);
void BlackAttck_2012180004(int*, int*);
void BlackDefence_2012180004(int, int);

void isAIGetGPS(int, int); //검정색이 어디에 놓은지 확인하기 위한부분
void isBlackStonesChecker(); //AI Next를 보는부분
void isWhiteStonesChecker(); //AI 자신의 돌을 넘길때
void isHintLoad(); // 힌트부분을 확인을 할때 사용한다.
void isHintCheck(); // 힌트부분을 체킹하려고 할때 사용한다.
void isHintClear(); //Hint를 초기화한다.
void isAiTotalPlus(int, int []); // 가중치 계산하기