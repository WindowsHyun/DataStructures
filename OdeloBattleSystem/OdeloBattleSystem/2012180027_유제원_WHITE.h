#ifndef _ATTACK_2_H_
#define _ATTACK_2_H_
#include "OdeloBattleSystem.h"

#include<time.h>
void WhiteAttack( int *x, int *y )
{
	srand((unsigned)time(NULL));
	int **pan;
	int n =2;
	int count = 0;
	int Large = 0;
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
										//if(count>Large)
										//{
											*x = i;
											*y = j;
											//Large = count;
										//}
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
										//if(count>Large)
										//{
										*x = i;
										*y = j;
										Large = count;
										//}
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
										//if(count>Large)
										//{
										*x = i;
										*y = j;
										Large = count;
										//}
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
										//if(count>Large)
										//{
										*x = i;
										*y = j;
										Large = count;
										//}
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
	delete pan;
}

void WhiteDefence( int x, int y )
{

}


#endif