#include "OdeloBattleSystem.h"
//---- �̰��� Header File�� Include �ϼ��� ----
// ex)
//#include "BLACK_4444444444.h"	
//#include "WHITE_6666666666.h"
//
#include "Attack_1.h"
//#include "Attack_2.h"
//#include "�ڿ���_2009180017b.h"
#include "Attack_3.h"
//#include "Attack_2_2012181017.h"
//#include "GL_variable_2012181017.h"
//#include "2012180027_������_WHITE.h"
//#include "2012180027_������_BLACK.h"


//---------------------------------------------

int main()
{


	OdeloGame.Init();

	for(int i=0; i<g_nMax; i++)
	{
		for(int j=0; j<g_nMax; j++)
		{
			Black_Attack_Check[g_nMax][g_nMax].check_position = false;
			White_Attack_Check[g_nMax][g_nMax].check_position = false;
		}
	}

	Black_Attack_Check[3][5].check_position = true;
	Black_Attack_Check[3][5].Attack_Point = 1;
	Black_Attack_Check[5][3].check_position = true;
	Black_Attack_Check[5][3].Attack_Point = 1;
	Black_Attack_Check[4][2].check_position = true;
	Black_Attack_Check[4][2].Attack_Point = 1;
	Black_Attack_Check[2][4].check_position = true;
	Black_Attack_Check[2][4].Attack_Point = 1;
	White_Attack_Check[3][2].check_position = true;
	White_Attack_Check[3][2].Attack_Point = 1;
	White_Attack_Check[2][3].check_position = true;
	White_Attack_Check[2][3].Attack_Point = 1;
	White_Attack_Check[5][4].check_position = true;
	White_Attack_Check[5][4].Attack_Point = 1;
	White_Attack_Check[4][5].check_position = true;
	White_Attack_Check[4][5].Attack_Point = 1;
	//------------ �̰��� �ڽ��� �Լ��� ��������.-------------------------
	//
	// �տ� 2���� �浹�� �� Attack, Defnece �Լ��̸� 
	// �ڿ� 2���� �鵹�� �� Attack, Defence �Լ��̸��� �����ø� �˴ϴ�.
	//
	//--------------------------------------------------------------------

	OdeloGame.SetYourFunc( 
		/*�浹Attack*/ BlackAttack_2012181008_eunjae, /*�浹Defence*/BlackDefence_2012181008_eunjae, 
		// /*�浹Attack*/ BlackAttack_2012180004, /*�浹Defence*/BlackDefence_2012180004, 
		//	/*�浹Attack*/ BlackAttack_2012180027, /*�浹Defence*/BlackDefence, 
		//  /*�鵹Attack*/ WhiteAttack_2012181017, /*�鵹Defence*/WhiteDefence_2012181017 );
		/*�鵹Attack*/ WhiteAttack_2012180004, /*�鵹Defence*/WhiteDefence_2012180004 );
	//	/*�鵹Attack*/ WhiteAttack, /*�鵹Defence*/WhiteDefence );
	// /*�鵹Attack*/ WhiteAttack_2012181008_eunjae, /*�鵹Defence*/WhiteDefence_2012181008_eunjae );
	// /*�鵹Attack*/ WhiteAttack_2012181017, /*�鵹Defence*/WhiteDefence_2012181017 );
	if( OdeloGame.BeginGame() )
		OdeloGame.Result();

	return 0;
}