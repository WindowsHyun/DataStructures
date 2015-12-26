#include "OdeloBattleSystem.h"

COdeloBattleSytem::COdeloBattleSytem()
{
	Init();
}

//------ �Լ� �����͸� ����	------
void COdeloBattleSytem::SetYourFunc(
		void (*pfuncBlackAttack) ( int *x, int *y ),
		void (*pfuncBlackDefence)( int  x, int  y ),
		void (*pfuncWhiteAttack) ( int *x, int *y ),
		void (*pfuncWhiteDefence)( int  x, int  y ) )
//--------------------------------
{
	// �浹 �Լ�
	m_funcBlackAttack	= pfuncBlackAttack;
	m_funcBlackDefence	= pfuncBlackDefence;

	// �鵹 �Լ�
	m_funcWhiteAttack	= pfuncWhiteAttack;
	m_funcWhiteDefence	= pfuncWhiteDefence;

}

//--------- ���� ���� ------------
bool COdeloBattleSytem::BeginGame()
//--------------------------------
{
	int x = -1, y = -1;
	float fLimitTime = 0.0f;
	
	while( m_nCurrentGameCount < g_nGameCount )
	{

		// ���º�
		if( m_nBlack + m_nWhite >= g_nMax * g_nMax )
		{
			std::cout << "���º� �Դϴ�.";
			++m_nCurrentGameCount;
			continue;
		}

		//------------------------------ �浹 ����, �鵹 ���------------------------------------
		getchar();
		
		StartTime();
		m_funcBlackAttack( &x, &y );		
		if( CheckTime( &m_fAttackExcuteTime ) )
		{
			std::cout << "���浹 Attack ����ð� : " << m_fAttackExcuteTime << "��\n";
			std::cout << "���ѽð� : " << g_fLimitTime <<"�ʸ� �ʰ��Ͽ����Ƿ� �浹�� �����ϴ�.\n";
			Init();
			++m_nCurrentGameCount;
			continue;
		}
		
		if( PutStone( x, y, BLACK ) )
		{
			++m_nCurrentGameCount;
			continue;
		}

		StartTime();
		m_funcWhiteDefence( x, y );
		if( CheckTime( &m_fDefenceExcuteTime ) )
		{
			std::cout << "�۹鵹 Defence ����ð� : " << m_fDefenceExcuteTime << "��\n";
			std::cout << "���ѽð� : " << g_fLimitTime <<"�ʸ� �ʰ��Ͽ����Ƿ� �浹�� �����ϴ�.";
			Init();
			++m_nCurrentGameCount;
			continue;
		}

		//------------------------------------------------------------------------------------------


		//------------------------------ �鵹 ����, �浹 ���------------------------------------
		getchar();

		StartTime();
		m_funcWhiteAttack( &x, &y );
		if( CheckTime( &m_fAttackExcuteTime ) )
		{
			std::cout << "�۹鵹 Attack ����ð� : " << m_fAttackExcuteTime << "��\n";
			std::cout << "���ѽð� : " << g_fLimitTime <<"�ʸ� �ʰ��Ͽ����Ƿ� �鵹�� �����ϴ�.";
			Init();
			++m_nCurrentGameCount;
			continue;
		}

		if( PutStone( x, y, WHITE ) )
		{
			++m_nCurrentGameCount;
			continue;
		}

		StartTime();
		m_funcBlackDefence( x, y );
		if( CheckTime( &m_fDefenceExcuteTime ) )
		{
			std::cout << "���浹 Denfence ����ð� : " << m_fDefenceExcuteTime << "��\n";
			std::cout << "���ѽð� : " << g_fLimitTime <<"�ʸ� �ʰ��Ͽ����Ƿ� �浹�� �����ϴ�.";
			Init();
			++m_nCurrentGameCount;
			continue;
		}

		//------------------------------------------------------------------------------------------
	}

	return true;
}


//--------- ���� �ʱ�ȭ -----------
void COdeloBattleSytem::Init()
//---------------------------------
{
	::ZeroMemory( m_nOdeloPan, sizeof(m_nOdeloPan) );
	::ZeroMemory( m_nUserWin, sizeof(m_nUserWin) );

	m_nOdeloPan[3][3] = BLACK;
	m_nOdeloPan[3][4] = WHITE;
	m_nOdeloPan[4][3] = WHITE;
	m_nOdeloPan[4][4] = BLACK;

	m_bActive			= true;
	m_nOdeloType		= BLACK;
	m_nCurrentGameCount = 0;
	m_nBlack			= 0;
	m_nWhite			= 0;
	m_fAttackExcuteTime = 0.0f;
	m_fDefenceExcuteTime= 0.0f;


	if( QueryPerformanceFrequency( (LARGE_INTEGER*)&m_Freq ) )
	{
		QueryPerformanceCounter( (LARGE_INTEGER*)&m_nCurrentTime); 
		m_bPerHardware = true;
	}
	else
	{
		m_nCurrentTime	= timeGetTime();
		m_bPerHardware	= false;
	}	

	Draw();
}

//--------- ��� ��� ���---------
void COdeloBattleSytem::StartTime()
//---------------------------------
{
	if( m_bPerHardware )
	{
		QueryPerformanceCounter( (LARGE_INTEGER*)&m_nCurrentTime); 
	}
	else
	{
		m_nCurrentTime = timeGetTime();
	}
		
}
	

//--------- ��� �ð� �ʰ�---------
bool COdeloBattleSytem::CheckTime( float *fResultTime )
//---------------------------------
{
	if( m_bPerHardware )
	{
		QueryPerformanceFrequency( (LARGE_INTEGER*)&m_Freq );
		QueryPerformanceCounter( (LARGE_INTEGER*)&m_nLastTime); 

		*fResultTime = static_cast<float>( (m_nLastTime - m_nCurrentTime ) / static_cast<float>(m_Freq) );

		if( *fResultTime > g_fLimitTime )
			return true;
	}
	else
	{
		m_nLastTime = timeGetTime();

		*fResultTime = static_cast<float>( ( m_nLastTime - m_nCurrentTime ) * 0.0001f );

		if( *fResultTime > g_fLimitTime )
			return true;
	}	

	return false;
}

//--------- ��� ��� ���---------
void COdeloBattleSytem::Result()
//---------------------------------
{

	std::cout<<"The End"<<std::endl;
}

//--------- ������ �׸��� --------
void COdeloBattleSytem::Draw()
//--------------------------------
{
	system("cls");
	for( int y = 0; y < g_nMax; y++)
	{
		for( int x = 0; x < g_nMax; x++)
		{
			
			if( m_nOdeloPan[ y ][ x ] == PAN )
			{
				if( x == 0 && y == 0 )
					std::cout<< "��";
				else if( x == 7 && y == 7 )
					std::cout<< "��";
				else if( x == 7 && y == 0  )
					std::cout<< "��";
				else if( x == 0	 && y == 7 )
					std::cout<< "��";
				else if( y == 0 )
					std::cout<< "��";
				else if( y == 7 )
					std::cout<< "��";
				else if( x == 0 )
					std::cout<< "��";
				else if( x == 7 )
					std::cout<< "��";
				else
					std::cout<< "��";
			}
			else if( m_nOdeloPan[ y ][ x ] == BLACK )
				std::cout<< "��"; 
			else if( m_nOdeloPan[ y ][ x ] == WHITE )
				std::cout<< "��";
		}
		std::cout<< "\n";
	}
	
	printf("%s Attack  ����ð� : %.5f��\n", m_nOdeloType == BLACK ? "���浹" : "�ܹ鵹", m_fAttackExcuteTime );
	printf("%s Defence ����ð� : %.5f��\n", m_nOdeloType == BLACK ? "�ܹ鵹" : "���浹", m_fDefenceExcuteTime );

	int blackdata =0, whitedata=0;
	for(int i=0; i<8; ++i){
		for(int j=0; j<8;++j){
			if(m_nOdeloPan[i][j] == BLACK)
				++blackdata;
			if(m_nOdeloPan[i][j] == WHITE)
				++whitedata;
		}
	}
	printf("\n");
	std::cout<< "���浹 ���� : " << blackdata << "  �ܹ鵹 ���� : " << whitedata << std::endl;
	std::cout<< "���浹 �ϼ� : " << m_nBlack << "  �ܹ鵹 �ϼ� : " << m_nWhite << std::endl;

}

//--------- �¸� ���� �Ǵ� ----------
int COdeloBattleSytem::CheckWin(int CheckCount, int type)
//-----------------------------------
{
	int m_WhiteStoneCount = 0;
	int m_BlackStoneCount = 0;

	for(int i=0; i<g_nMax; i++)
	{
		for(int j=0; j<g_nMax; j++)
		{
			if(m_nOdeloPan[i][j] == WHITE)
				m_WhiteStoneCount++;
			else
				m_BlackStoneCount++;
		}
	}

	if(CheckCount > 0 && CheckCount < g_nMax * g_nMax - 4)
	{
		
		if(type == WHITE && m_BlackStoneCount == 0)
		{
			return WHITEWIN;
		}
		else if(type == BLACK && m_WhiteStoneCount == 0)
		{
			return BLACKWIN;
		}
		else return NOWIN;
	}

	else
	{
		if(m_WhiteStoneCount > m_BlackStoneCount)
		{
			std::cout<<m_WhiteStoneCount<<" "<<m_BlackStoneCount<<std::endl;
			return WHITEWIN;
		}
		else if(m_BlackStoneCount > m_WhiteStoneCount)
		{
			std::cout<<m_WhiteStoneCount<<" "<<m_BlackStoneCount<<std::endl;
			return BLACKWIN;
		}
		else
			return DROW;
	}

}

/*
//--------- ���� ����( ��, �� ) -----
void COdeloBattleSytem::ChangeType()
//-----------------------------------
{



}
*/

//--------- ���� ����( ��, �� ) -----
bool COdeloBattleSytem::PutStone(int x, int y, int type )
//-----------------------------------
{
	if( m_nOdeloPan[ y ][ x ] == PAN )
	{
	
		if( type == BLACK )
		{
			if(CheckStone(x,y,type))
			{
				m_nOdeloPan[ y ][ x ] = BLACK;
				++m_Count;
				ReverseStone(x, y, type);
				Draw();
				++m_nBlack;
				switch( CheckWin( m_Count, BLACK ) )
				{
				case BLACKWIN:
					std::cout << " �浹�� �¸��Ͽ����ϴ�.\n ";
					return true;
					break;

				case WHITEWIN:
					std::cout << " �鵹�� �¸��Ͽ����ϴ�.\n ";
					return true;
					break;

				case DROW:
					std::cout << " ���º��Դϴ�.\n ";
					return true;
					break;
				}
			}

			else
			{
				std::cout << " �鵹�� �¸��Ͽ����ϴ�.\n ";
				return true;
			}

			m_nOdeloType = WHITE;
		}
		
		else
		{
			if(CheckStone(x,y,type))
			{
				m_nOdeloPan[ y ][ x ] = WHITE;
				++m_Count;
				ReverseStone(x, y, type);
				Draw();
				++m_nWhite;
				switch( CheckWin( m_Count, WHITE ) )
				{
				case BLACKWIN:
					std::cout << " �浹�� �¸��Ͽ����ϴ�.\n ";
					return true;
					break;

				case WHITEWIN:
					std::cout << " �鵹�� �¸��Ͽ����ϴ�.\n ";
					return true;
					break;

				case DROW:
					std::cout << " ���º��Դϴ�.\n ";
					return true;
					break;
				}
			}

			else
			{
				std::cout << " �浹�� �¸��Ͽ����ϴ�.\n ";
				return true;
			}
			m_nOdeloType = BLACK;

		}
	}

	return false;
}

void COdeloBattleSytem::ReverseStone(int x, int y, int type)
{
	int dx, dy, _dx, _dy;
	int count = 0;
	
	for( int j = 0; j < 4; j++ )
	{
		dx = _dx = x ;
		dy = _dy = y ;

		dx = dx + g_Directiontable[ j ][ 0 ];
		dy = dy + g_Directiontable[ j ][ 1 ];

		_dx = _dx + g_Directiontable[ j + 4 ][ 0 ];
		_dy = _dy + g_Directiontable[ j + 4 ][ 1 ];
		
		count = 0;	
		
		while( ( dx >= 0 && dx <= 7 ) && ( dy >= 0 && dy <= 7 ) )
		{
			
			if( m_nOdeloPan[ dy ][ dx ] == type ) //�ۡۡ� , �ۡ�  ���� ���� ���
			{
				if(!(dx == x + g_Directiontable[ j ][ 0 ] && dy == y + g_Directiontable[ j ][ 1 ]))
				{
					dx = x + g_Directiontable[ j ][ 0 ];
					dy = y + g_Directiontable[ j ][ 1 ];
					for(int i=0; i<count; i++)
					{
						if(m_nOdeloPan[dy][dx] == BLACK)
							m_nOdeloPan[dy][dx] = WHITE;
						else if(m_nOdeloPan[dy][dx] == WHITE)
							m_nOdeloPan[dy][dx] = BLACK;

						dx = dx + g_Directiontable[ j ][ 0 ];
						dy = dy + g_Directiontable[ j ][ 1 ];
					}
					break;

				}
				else break;
			}
			
			else if( m_nOdeloPan[ dy ][ dx ] == PAN)  
				break;
		
			else if( ( m_nOdeloPan[ dy ][ dx ] != PAN ) && ( m_nOdeloPan[ dy ][ dx ] != type ) )
			{	
				dx = dx + g_Directiontable[ j ][ 0 ];
				dy = dy + g_Directiontable[ j ][ 1 ];
			}
					
		
			else
				break;

			count++;
		}

		count = 0;

		while( ( _dx >= 0 && _dx <= 7 ) && ( _dy >= 0 && _dy <= 7 ) )
		{
			
			if( m_nOdeloPan[ _dy ][ _dx ] == type ) //�ۡۡ� , �ۡ�  ���� ���� ���
			{
				if(!(_dx == x + g_Directiontable[ j ][ 0 ] && _dy == y + g_Directiontable[ j ][ 1 ]))
				{
					_dx = x + g_Directiontable[ j + 4 ][ 0 ];
					_dy = y + g_Directiontable[ j + 4 ][ 1 ];
					for(int i=0; i<count; i++)
					{
						if(m_nOdeloPan[_dy][_dx] == BLACK)
							m_nOdeloPan[_dy][_dx] = WHITE;
						else if(m_nOdeloPan[_dy][_dx] == WHITE)
							m_nOdeloPan[_dy][_dx] = BLACK;

						_dx = _dx + g_Directiontable[ j + 4 ][ 0 ];
						_dy = _dy + g_Directiontable[ j + 4 ][ 1 ];
					}
					break;

				}
				else break;
			}
			
			else if( m_nOdeloPan[ _dy ][ _dx ] == PAN)  
				break;
		
			else if( ( m_nOdeloPan[ _dy ][ _dx ] != PAN ) && ( m_nOdeloPan[ _dy ][ _dx ] != type ) )
			{	
				_dx = _dx + g_Directiontable[ j + 4 ][ 0 ];
				_dy = _dy + g_Directiontable[ j + 4 ][ 1 ];
			}
					
		
			else
				break;

			count++;
		}
	}
}


bool COdeloBattleSytem::CheckStone(int x, int y, int type)
{
	int CheckPutStone = 0;
	bool Check_State = false;
	int type_opposite;
	int dx, dy;

	if(type == WHITE)
		type_opposite = BLACK;
	else if(type == BLACK)
		type_opposite = WHITE;

	if(m_nOdeloPan[y][x] != PAN)
		return false;

	else
	{
		for(int i=0; i<8; i++)
		{
			dx = x + g_Directiontable[i][0];
			dy = y + g_Directiontable[i][1];
			if(m_nOdeloPan[dy][dx] == PAN)
				Check_State = Check_State;

			else if(m_nOdeloPan[dy][dx] == type)
				Check_State = Check_State;

			else if(m_nOdeloPan[dy][dx] == type_opposite)
			{
				while(dy>=0 && dy<=7 && dx>=0 && dx<=7)
				{
					dx = dx + g_Directiontable[i][0];
					dy = dy + g_Directiontable[i][1];

					if(m_nOdeloPan[dy][dx] == type)
					{
						Check_State = true;
						break;
					}
					else if(m_nOdeloPan[dy][dx] == type_opposite)
					{
						continue;
					}
					else if(m_nOdeloPan[dy][dx] == PAN)
					{
						Check_State = Check_State;
					}
				}
			}
	
		}
		if(Check_State == false)
			return false;
	
		else return true;
	}
}

int** COdeloBattleSytem::Get_OdeloPan()
{
	int** OdeloPan;
	OdeloPan = new int*[g_nMax];
	for(int i=0; i<g_nMax; i++)
	{
		OdeloPan[i] = new int[g_nMax];
	}
	for(int i=0; i<g_nMax; i++)
	{
		for(int j=0; j<g_nMax; j++)
		{
			OdeloPan[i][j] = m_nOdeloPan[i][j];
		}
	}
	return OdeloPan;
}