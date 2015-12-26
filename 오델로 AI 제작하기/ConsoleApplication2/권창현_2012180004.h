#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define LEFT   75      // ��������Ű
#define RIGHT  77      // ��������Ű
#define UP     72      // ���ʹ���Ű
#define DOWN   80      // �Ʒ�����Ű
#define ENTER   13      // EnterŰ
#define SPACE   32      // SpaceŰ
#define isOdelloData 8 // ������ ��
#define isAiArrangement 20 // AI �迭 ��
#define isAiTempData 3 // AI �迭 ��
#define isGameTheEndData isOdelloData*isOdelloData // �� ���� ����
#define isWaitTime 1 // AI ���ð�
#define isSpace 32 // ���� ��ĭ <�ƽ�Ű�ڵ�ǥ>

void WhiteAttck_2012180004(int*, int*);
void WhiteDefence_2012180004(int, int);
void BlackAttck_2012180004(int*, int*);
void BlackDefence_2012180004(int, int);

void isAIGetGPS(int, int); //�������� ��� ������ Ȯ���ϱ� ���Ѻκ�
void isBlackStonesChecker(); //AI Next�� ���ºκ�
void isWhiteStonesChecker(); //AI �ڽ��� ���� �ѱ涧
void isHintLoad(); // ��Ʈ�κ��� Ȯ���� �Ҷ� ����Ѵ�.
void isHintCheck(); // ��Ʈ�κ��� üŷ�Ϸ��� �Ҷ� ����Ѵ�.
void isHintClear(); //Hint�� �ʱ�ȭ�Ѵ�.
void isAiTotalPlus(int, int []); // ����ġ ����ϱ�