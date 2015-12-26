#ifndef _ATTACK_1_H_
#define _ATTACK_1_H_

#include "OdeloBattleSystem.h"
#include <time.h>
typedef struct Odelo_Count
{
	int Attack_Point;
	bool check_position;
}OC;
OC Black_Attack_Check[g_nMax][g_nMax];
OC White_Attack_Check[g_nMax][g_nMax];


void BlackAttack_2012180027( int *x, int *y )
{
	srand((unsigned)time(NULL));
	int **pan;
	int n =2;
	int count = 1;
	int Large = 0;
	bool mosery = false;
	pan = OdeloGame.Get_OdeloPan();
	switch(rand()%4)
	{
	case 0:
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
							n = 2;
							count = 1;
							if(j+l!=-1&&j+l!=g_nMax&&i+k!=-1&&i+k!=g_nMax)
							{
								if(pan[j+l][i+k]==WHITE)
								{
									while(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax)
									{
										if(pan[j+(l*n)][i+(k*n)]==BLACK||pan[j+(l*n)][i+(k*n)]==PAN)
											break;
										else
										{
											n++;
											count++;
										}
									}
									if(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax)
									{
										if(pan[j+(l*n)][i+(k*n)]==BLACK&&(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax))
										{
											
											if((i==0&&j==0)||(i==7&&j==0)||(i==0&&j==7)||(i==7&&j==7))
										{
											*x = i;
											*y = j;
											mosery = true;
										}
										else
										{
											if(mosery == false)
											{
												*x = i;
												*y = j;
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
		}
		break;
	case 1:
		for(int i=g_nMax-1;i>-1;--i)
		{
			for(int j=0;j<g_nMax;++j)
			{
				if(pan[j][i]==PAN)
				{
					for(int k=-1;k<2;++k)
					{
						for(int l=-1;l<2;++l)
						{
							n = 2;
							if(j+l!=-1&&j+l!=g_nMax&&i+k!=-1&&i+k!=g_nMax)
							{
								if(pan[j+l][i+k]==WHITE)
								{
									while(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax)
									{
										if(pan[j+(l*n)][i+(k*n)]==BLACK||pan[j+(l*n)][i+(k*n)]==PAN)
											break;
										else
											n++;
									}
									if(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax)
									{
										if(pan[j+(l*n)][i+(k*n)]==BLACK&&(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax))
										{
											if((i==0&&j==0)||(i==7&&j==0)||(i==0&&j==7)||(i==7&&j==7))
										{
											*x = i;
											*y = j;
											mosery = true;
										}
										else
										{
											if(mosery == false)
											{
												*x = i;
												*y = j;
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
		}
		break;
	case 2:
		for(int i=0;i<g_nMax;++i)
		{
			for(int j=g_nMax-1;j>-1;--j)
			{
				if(pan[j][i]==PAN)
				{
					for(int k=-1;k<2;++k)
					{
						for(int l=-1;l<2;++l)
						{
							n = 2;
							if(j+l!=-1&&j+l!=g_nMax&&i+k!=-1&&i+k!=g_nMax)
							{
								if(pan[j+l][i+k]==WHITE)
								{
									while(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax)
									{
										if(pan[j+(l*n)][i+(k*n)]==BLACK||pan[j+(l*n)][i+(k*n)]==PAN)
											break;
										else
											n++;
									}
									if(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax)
									{
										if(pan[j+(l*n)][i+(k*n)]==BLACK&&(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax))
										{
											if((i==0&&j==0)||(i==7&&j==0)||(i==0&&j==7)||(i==7&&j==7))
										{
											*x = i;
											*y = j;
											mosery = true;
										}
										else
										{
											if(mosery == false)
											{
												*x = i;
												*y = j;
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
		}
		break;
	case 3:
		for(int i=g_nMax-1;i>-1;--i)
		{
			for(int j=g_nMax-1;j>-1;--j)
			{
				if(pan[j][i]==PAN)
				{
					for(int k=-1;k<2;++k)
					{
						for(int l=-1;l<2;++l)
						{
							n = 2;
							if(j+l!=-1&&j+l!=g_nMax&&i+k!=-1&&i+k!=g_nMax)
							{
								if(pan[j+l][i+k]==WHITE)
								{
									while(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax)
									{
										if(pan[j+(l*n)][i+(k*n)]==BLACK||pan[j+(l*n)][i+(k*n)]==PAN)
											break;
										else
											n++;
									}
									if(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax)
									{
										if(pan[j+(l*n)][i+(k*n)]==BLACK&&(j+(l*n)!=-1&&j+(l*n)!=g_nMax&&i+(k*n)!=-1&&i+(k*n)!=g_nMax))
										{
											if((i==0&&j==0)||(i==7&&j==0)||(i==0&&j==7)||(i==7&&j==7))
										{
											*x = i;
											*y = j;
											mosery = true;
										}
										else
										{
											if(mosery == false)
											{
												*x = i;
												*y = j;
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
		}
		break;
	}
	delete pan;
}
void BlackDefence( int x, int y )
{

}


#endif