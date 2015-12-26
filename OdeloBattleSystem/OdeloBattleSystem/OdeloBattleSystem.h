#ifndef _OdeloBATTLESYSTEM_H_
#define _OdeloBATTLESYSTEM_H_

#include <cstdio>
#include <iostream>
#include <windows.h>

#pragma comment( lib, "winmm.lib" )

const int	g_nMax			= 8;	// ������ ���� ���� ����
const int	g_nGameCount	= 1;	// ���� Ƚ��
const float	g_fLimitTime	= 2.0f; // AI Attack�Լ� Limit Time 2�� �̻��̸� ���ӿ��� ����.

const int g_Directiontable[8][2] = { 
	{ -1, -1 }, {  0, -1 },			//����,			��
	{  1, -1 }, {  1,  0 },			//������,		����
	{  1,  1 }, {  0,  1 },			//���� �Ʒ�,	�Ʒ�
	{ -1,  1 }, { -1,  0 }			//�޾Ʒ�,		��
};

enum{ PAN, BLACK, WHITE };
enum{ WHITEWIN, BLACKWIN, NOWIN, DROW };

class COdeloBattleSytem
{
	void (*m_funcBlackAttack)( int *x, int *y );	//�浹 �Լ� ������
	void (*m_funcBlackDefence)( int x, int y );
	
	void (*m_funcWhiteAttack)( int *x, int *y );	//�鵹 �Լ� ������
	void (*m_funcWhiteDefence)( int x, int y );

	int		m_nOdeloType;							// ����� Ÿ��
	int		m_nUserWin[2];							// ���� �¸�
	int		m_nCurrentGameCount;					// ���� Ƚ��			
	int		m_nOdeloPan[g_nMax][g_nMax];			// ������

	bool	m_bActive;								// ���� ����

	int		m_nBlack;								// �浹 �� Ƚ��
	int		m_nWhite;								// �� �� Ƚ��
	int		m_Count;								// ��ü �� Ƚ��

	__int64 m_nCurrentTime;							// �ð�
	__int64 m_nLastTime;
	__int64 m_Freq;			
	bool	m_bPerHardware;							// QueryPerformanceFrequency ���� ����	

	float	m_fAttackExcuteTime;					// Attack�Լ� ����ð�
	float	m_fDefenceExcuteTime;					// Defence�Լ� ����ð�


public:

	COdeloBattleSytem();

	void SetYourFunc(
		void (*pfuncBlackAttack)( int *x, int *y ),
		void (*pfuncBlackDefence)( int x, int y ),
		void (*pfuncWhiteAttack)( int *x, int *y ),
		void (*pfuncWhiteDefence)( int x, int y ) );

	int** Get_OdeloPan();

	// ���� ����
	bool BeginGame();
	// ���� ���� 
	bool GetGameState() const { return m_bActive; }
	// ��� ��� ���
	void Result();
	// ���� �ʱ�ȭ
	void Init();	

private:
	// �� �׸���
	void Draw();
	// �Ѽ� �д�.
	bool PutStone(int x, int y, int type );
	// �¸� ���� �Ǵ�
	int CheckWin(int CheckCount, int type);
	// ���� ����( ��, �� )
//	void ChangeType();	
	
	// ���� �ð� üũ
	void StartTime();
	bool CheckStone(int x, int y, int type);
	void ReverseStone(int x, int y, int type);
	bool CheckTime( float *fResultTime );


};

static COdeloBattleSytem OdeloGame;

#endif