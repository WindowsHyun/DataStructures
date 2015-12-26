#ifndef _ATTACK_2_H_
#define _ATTACK_2_H_
#include "OdeloBattleSystem.h"

#include<time.h>
void WhiteAttack( int *x, int *y )
{
	class Doll
	{
	public:
		int x,y,k,g;
	};
	srand((unsigned)time(NULL));
	int **pan;
	int n =2;
	int count = 0;
	int cheat=0;
	Doll cht;

	Doll CanDoll[200];
	int cn=0;
	int MAX_K=0;

	pan = OdeloGame.Get_OdeloPan();
 
	for(int i=0;i<g_nMax;++i)
	{
		for(int j=0;j<g_nMax;++j)
		{
			if(pan[j][i]==PAN)
			{
				for(int k=-1;k<2;++k)
				{
					for(int l=-1;l<2;++l)
					{
						n =2;
						count = 1;
						if(j+l!=-1&&j+l!=g_nMax&&i+k!=-1&&i+k!=g_nMax)
						{
							if(pan[j+l][i+k]==BLACK)
							{
								while(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax)
								{
									if(pan[j+(l*n)][i+(k*n)]==WHITE||pan[j+(l*n)][i+(k*n)]==PAN)
										break;
									else
									{
										n++;
										count++;
									}
								}
								if(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax)
								{
									if(pan[j+(l*n)][i+(k*n)]==WHITE&&(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax))
									{
										if( !(cn!=0 && ( (i==1 && (j==0||j==1 || j== 6||j==7)) || (i==6 && (j==0||j==1 || j==6||j==7) ) 
											        ||   (j==1 && (i==0||i==1 || i== 6||i==7)) || (j==6 && (i==0||i==1 || i==6||i==7) )    )  ))
										{
											CanDoll[cn].x=i;
											CanDoll[cn].y=j;
	
											if( (i==2 && (j==2 || j==3 || j==4 || j==5)) || (i==5 && (j==2 || j==3 || j==4 || j==5)) 
												 || (j==2 && (i==2 || i==3 || i==4 || i==5)) || (j==2 && (i==2 || i==3 || i==4 || i==5)) )
											{
												cn++;
												cheat=2;
												cht.x=i;
												cht.y=j;
											}

											if( (j==0 && i==0) || (j==0 && i==7) || (j==7 && i==0) || (j==7 && i==7) )
											{	
												cn++;
												cheat=3;
												cht.x=i;
												cht.y=j;
											}
											if( (j==0 &&(i==2 || i==3 || i==4 || i==5)) || (j==7 &&( i==2 || i==3 || i==4 || i==5))
												|| (i==0 &&(j==2 || j==3 || j==4 || j==5)) || (i==0 &&(j==2 || j==3 || j==4 || j==5)) )
											{
												cn++;
												cheat=1;
												cht.x=i;
												cht.y=j;
											}
										cn++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	if(cheat ==3)
	{
		for(int i=0;i<cn+30;i++)
		{
			CanDoll[i].x=cht.x;
			CanDoll[i].y=cht.y;
		}
	}

	else if(cheat ==2)
	{
		for(int i=0;i<cn+20;i++)
		{
			CanDoll[i].x=cht.x;
			CanDoll[i].y=cht.y;
		}
	}
	else if(cheat ==1)
	{
		for(int i=0;i<cn+10;i++)
		{
			CanDoll[i].x=cht.x;
			CanDoll[i].y=cht.y;
		}
	}

	if(cn!=0)
	{
		int r=rand()%cn;
		*x=CanDoll[r].x;
		*y=CanDoll[r].y;
	}
	
	delete pan;
}

void WhiteDefence( int x, int y )
{

}


#endif