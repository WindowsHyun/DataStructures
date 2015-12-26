#ifndef _ATTACK_1_H_
#define _ATTACK_1_H_

#include "OdeloBattleSystem.h"
#include <Windows.h>
#include <time.h>

typedef struct Odelo_Count
{
	int Attack_Point;
	bool check_position;
}OC;
OC Black_Attack_Check[g_nMax][g_nMax];
OC White_Attack_Check[g_nMax][g_nMax];


int b_check_2012181008_eunjea(int xPos, int yPos){
	int x,y;
	int tx,ty;	//�ӽú���
	int **b_pan_2012181008_eunjea = OdeloGame.Get_OdeloPan();

	if(BLACK==b_pan_2012181008_eunjea[yPos][xPos] || WHITE==b_pan_2012181008_eunjea[yPos][xPos]){
		return 0;				//�� �ڸ��� �̹� ���� ������� �Լ��� �������´�
	}else{
		/*��ǥ�� �׵θ� �˻�*/
		for(y=-1; y<=1; ++y){
			for(x=-1; x<=1; ++x){
				if(xPos+x<0 || xPos+x>7 || yPos+y<0 || yPos+y>7){
					continue;
				}

				if(b_pan_2012181008_eunjea[yPos+y][xPos+x]==PAN || b_pan_2012181008_eunjea[yPos+y][xPos+x]==BLACK ){
					continue;	//��ǥ ���� �׵θ��� ���� ���ų� ���� ���� ���̰ų� ��Ʈ���� ��쿡�� �ٸ� ������ �˻��Ѵ�
				}
				else			//���� �Ͽ� ���� �ٸ����� ���� ��� �ش� x,y�������� �� �˻��غ���.
					tx = x+x;	//�˻��ϴ� �ش� �������� x��ǥ�� ��ĭ�� �� ������
					ty = y+y;	//�˻��ϴ� �ش� �������� y��ǥ�� ��ĭ�� �� ������

					/*������ ���� �� ��ǥ�� ����� ������� ������ �����Ѵ�*/
					while((0<=xPos+tx) && (0<=yPos+ty) && (xPos+tx<8) && (yPos+ty<8)){
						if(BLACK==b_pan_2012181008_eunjea[yPos+ty][xPos+tx]){
							//printf("x : %d, y : %d\n",xPos+tx,yPos+ty);
							return 1;	//�ش� ��ǥ�� �������̶�� ���� �� �ִ� �ڸ�
						}
						else if(PAN==b_pan_2012181008_eunjea[yPos+ty][xPos+tx]){
							break;		//�ش� ��ǥ�� ����ְų� ��Ʈ���� �ִٸ� �ٸ� ��ǥ�� Ž���ϰ� �������´�
						}
						tx += x;		//�˻��ϴ� �ش� �������� x��ǥ�� ��ĭ�� �� ������
						ty += y;		//�˻��ϴ� �ش� �������� y��ǥ�� ��ĭ�� �� ������
					}
				}
			}
		}
	return 0;		//���� �� ���� �ڸ��� ���ϰ� 0 ��ȯ
}

void BlackAttack_2012181008_eunjae( int *x, int *y )
{
	int **b_pan_2012181008_eunjea = OdeloGame.Get_OdeloPan();	//������ �� ����
	int b_k_2012181008_eunjea = 0;								//���� �� �ִ� ��ǥ�� ����
	int b_put_2012181008_eunjea[30][2];							//���� �� �ִ� ��ǥ �����ϴ� ����
	int tx = 0 , ty = 0;										//���� �� �����ϴ� �ӽ� ����
	int num[30];												//���� �� �ִ� ��ǥ�� Ȯ�� �ִ� ����
	int max;													//�ִ� Ȯ�� �ִ� ����
	int max_index;												//�ִ� Ȯ���� �ִ� �ε��� �����ϴ� ����
	//srand(time(unsigned(NULL)));

	for(int i=0; i<8; ++i){						
		for(int j=0; j<8; ++j){
			if(b_check_2012181008_eunjea(j, i)){					//���� �� �ִ� ��ǥ�� ã�� �迭�� �ִ´�
				b_put_2012181008_eunjea[b_k_2012181008_eunjea][0]   = j;
				b_put_2012181008_eunjea[b_k_2012181008_eunjea++][1] = i;
			}
		}
	}

	for(int i=0; i<b_k_2012181008_eunjea; ++i){
		/***********************�𼭸�**************************/
		if(b_put_2012181008_eunjea[i][0]==0 && b_put_2012181008_eunjea[i][1]==0 ||	//���� �� �𼭸�
			b_put_2012181008_eunjea[i][0]==7 && b_put_2012181008_eunjea[i][1]==7 ||	//������ �� �𼭸�
			b_put_2012181008_eunjea[i][0]==0 && b_put_2012181008_eunjea[i][1]==7 || //���� �Ʒ� �𼭸�
			b_put_2012181008_eunjea[i][0]==7 && b_put_2012181008_eunjea[i][1]==0){	//������ �Ʒ� �𼭸�

				//�ظ𼭸��� ���� �߿��Ѱ��̹Ƿ� ����ġ ���� �𼭸���
				//  ���� �� ������ ��ٷ� ���� �Լ��� �������´�.
				
				*x = b_put_2012181008_eunjea[i][0];
				*y = b_put_2012181008_eunjea[i][1];

				return;
		}
		/***********************�𼭸� ���� �� ����**************************/
		else if(1<=b_put_2012181008_eunjea[i][0] && b_put_2012181008_eunjea[i][0]<=6 && b_put_2012181008_eunjea[i][1]==0 ||	//���� ��
			1<=b_put_2012181008_eunjea[i][0] && b_put_2012181008_eunjea[i][0]<=6 && b_put_2012181008_eunjea[i][1]==7 ||		//�Ʒ��� ��
			1<=b_put_2012181008_eunjea[i][1] && b_put_2012181008_eunjea[i][1]<=6 && b_put_2012181008_eunjea[i][0]==0 ||		//���� ��
			1<=b_put_2012181008_eunjea[i][1] && b_put_2012181008_eunjea[i][1]<=6 && b_put_2012181008_eunjea[i][0]==7 ){		//������ ��

				/*�� ���� ��*/
				if(1<=b_put_2012181008_eunjea[i][0] && b_put_2012181008_eunjea[i][0]<=6 && b_put_2012181008_eunjea[i][1]==0){
					if(b_pan_2012181008_eunjea[0][0]==BLACK && b_pan_2012181008_eunjea[0][7]==BLACK){
						//===>�� �� �𼭸� �Ѵ� �ΰ������� ������ ������<===

						if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[2][0]==BLACK && b_pan_2012181008_eunjea[1][1]==WHITE  && b_pan_2012181008_eunjea[0][0]==PAN||
							b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[2][7]==BLACK && b_pan_2012181008_eunjea[1][6]==WHITE && b_pan_2012181008_eunjea[0][7]==PAN){
								//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

								num[i] = 1;

						}else if(b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
							//���� ��ǥ �� ���� �������� �ִٸ�

							num[i] = 98;

						}else if(b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE ||
							b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� ���� ���϶�

								if(b_put_2012181008_eunjea[i][0]==2 && b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE){
									num[i] = 1;
								}else if(b_put_2012181008_eunjea[i][0]==5 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
									num[i] = 1;
								}else{
									num[i] = 75;
								}

						}else if(b_put_2012181008_eunjea[i][0]-1==WHITE || b_put_2012181008_eunjea[i][0]+1==WHITE){
							//���� ��ǥ �� ���߿� �ϳ��� �ٸ����϶�

							if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
								num[i] = 3;
							}else{
								num[i] = 85;
							}

						}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){	//Default ��ġ
							num[i] = 90;
						}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){	//Default ��ġ
							num[i] = 80;
						}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){	//Default ��ġ
							num[i] = 5;
						}

					}else if(b_pan_2012181008_eunjea[0][0]==PAN && b_pan_2012181008_eunjea[0][7]==BLACK ||
						b_pan_2012181008_eunjea[0][0]==BLACK && b_pan_2012181008_eunjea[0][7]==PAN){
							//===>�� �� �𼭸� �� �ϳ� ���� �𼭸��� �ΰ������� �������϶�<===

							if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[2][0]==BLACK && b_pan_2012181008_eunjea[1][1]==WHITE && b_pan_2012181008_eunjea[0][0]==PAN ||
								b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[2][7]==BLACK && b_pan_2012181008_eunjea[1][6]==WHITE && b_pan_2012181008_eunjea[0][7]==PAN){
									//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

									num[i] = 1;

							}else if(b_pan_2012181008_eunjea[0][7]==WHITE && b_put_2012181008_eunjea[i][0]!=6 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE ||
								b_pan_2012181008_eunjea[0][0]==WHITE && b_put_2012181008_eunjea[i][0]!=1 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
									//���� ��ǥ �� ���� ����� ���� �ְ� �Ծ����� ���� �𼭸��� ���� ������ ���� �����϶�

									num[i] = 98;	//�ڡڡڡڡڡ��׽�Ʈ�� ����ġ üũ �غ���

							}else if(b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE ||
								b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
									//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� ���� ���϶�

									if(b_put_2012181008_eunjea[i][0]==2 && b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE){
										num[i] = 1;
									}else if(b_put_2012181008_eunjea[i][0]==5 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
										num[i] = 1;
									}else{
										num[i] = 75;
									}

							}else if(b_put_2012181008_eunjea[i][0]-1==WHITE || b_put_2012181008_eunjea[i][0]+1==WHITE){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����϶�

								if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
									num[i] = 3;
								}else{
									num[i] = 85;
								}

							}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){	//Default ��ġ
								num[i] = 90;
							}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){	//Default ��ġ
								num[i] = 80;
							}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){	//Default ��ġ
								num[i] = 5;
							}

					}else if(b_pan_2012181008_eunjea[0][0]==BLACK && b_pan_2012181008_eunjea[0][7]==WHITE ||
						b_pan_2012181008_eunjea[0][0]==WHITE && b_pan_2012181008_eunjea[0][7]==BLACK){
							//===>�� �� �𼭸� �� �ϳ��� �ΰ������� �ϳ��� ������ �������϶�<===

							if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[2][0]==BLACK && b_pan_2012181008_eunjea[1][1]==WHITE && b_pan_2012181008_eunjea[0][0]==PAN ||
								b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[2][7]==BLACK && b_pan_2012181008_eunjea[1][6]==WHITE && b_pan_2012181008_eunjea[0][7]==PAN){
									//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

									num[i] = 1;

							}else if(b_pan_2012181008_eunjea[0][7]==WHITE && b_put_2012181008_eunjea[i][0]!=6 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE ||
								b_pan_2012181008_eunjea[0][0]==WHITE && b_put_2012181008_eunjea[i][0]!=1 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
									//���� ��ǥ �� ���� ����� ���� �ְ� �Ծ����� ���� �𼭸��� ���� ������ ���� �����϶�

									num[i] = 98;	//�ڡڡڡڡڡ��׽�Ʈ�� ����ġ üũ �غ���
							}else if(b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE ||
								b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
									//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̶��

									if(b_put_2012181008_eunjea[i][0]==2 && b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE){
										num[i] = 1;
									}else if(b_put_2012181008_eunjea[i][0]==5 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
										num[i] = 1;
									}else{
										num[i] = 75;
									}

							}else if(b_put_2012181008_eunjea[i][0]-1==WHITE || b_put_2012181008_eunjea[i][0]+1==WHITE){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����϶�

								if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
									num[i] = 3;
								}else{
									num[i] = 85;
								}
							}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){	//Default ��ġ
								num[i] = 90;
							}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){	//Default ��ġ
								num[i] = 80;
							}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){	//Default ��ġ
								num[i] = 5;
							}

					}else if(b_pan_2012181008_eunjea[0][7]==PAN && b_pan_2012181008_eunjea[0][0]==PAN){
						//===>�� �� �𼭸� �Ѵ� �ƹ��� �ȸԾ�����<===

						if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[2][0]==BLACK && b_pan_2012181008_eunjea[1][1]==WHITE && b_pan_2012181008_eunjea[0][0]==PAN ||
							b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[1][7]==BLACK && b_pan_2012181008_eunjea[2][6]==WHITE && b_pan_2012181008_eunjea[0][7]==PAN){
								//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

								num[i] = 1;

						}else if(b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
							//���� ��ǥ �� ���� �������� �ִٸ�

							num[i] = 95;

						}else if(b_put_2012181008_eunjea[i][0]-1==PAN && b_put_2012181008_eunjea[i][0]+1==PAN){
							//�ƹ��͵� ���ٸ�
							num[i] = 99;

						}else if(b_put_2012181008_eunjea[i][0]-1==PAN && b_put_2012181008_eunjea[i][0]+1==WHITE ||
							b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==PAN){

								if(b_put_2012181008_eunjea[i][0]-1==PAN && b_put_2012181008_eunjea[i][0]+1==WHITE){//�������� ��뵹�� �������� �װ�
									for(int j=1; b_put_2012181008_eunjea[i][0]+j<8; ++j){	 //�� ���� �� �ִ��� ����
										if( (b_put_2012181008_eunjea[i][0]+j)==WHITE){
											continue;
										}else if((b_put_2012181008_eunjea[i][0]+j)==BLACK){	
											num[i] = 98;
											break;
										}else{		//��ĭ
											num[i] = 15;
											break;
										}
									}
								}else{
									for(int j=1; 0 <= b_put_2012181008_eunjea[i][0]-j; ++j){
										if( (b_put_2012181008_eunjea[i][0]-j)==WHITE){
											continue;
										}else if((b_put_2012181008_eunjea[i][0]-j)==BLACK){	
											num[i] = 98;
											break;
										}else{		//��ĭ
											num[i] = 15;
											break;
										}
									}
								}

						}else if(b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE ||
							b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� ���� ���϶�

								if(b_put_2012181008_eunjea[i][0]==2 && b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE){
									num[i] = 1;
								}else if(b_put_2012181008_eunjea[i][0]==5 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
									num[i] = 1;
								}else{
									num[i] = 85;
								}

						}else if(b_put_2012181008_eunjea[i][0]-1==WHITE || b_put_2012181008_eunjea[i][0]+1==WHITE){
							//���� ��ǥ �� ���߿� �ϳ��� �ٸ����϶�

							if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
								num[i] = 3;
							}else{
								num[i] = 85;
							}
						}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){	//Default ��ġ
							num[i] = 90;
						}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){	//Default ��ġ
							num[i] = 80;
						}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){	//Default ��ġ
							num[i] = 5;
						}
					}else if(b_pan_2012181008_eunjea[0][7]==WHITE && b_pan_2012181008_eunjea[0][0]==PAN ||
						b_pan_2012181008_eunjea[0][7]==PAN && b_pan_2012181008_eunjea[0][0]==WHITE){
							//==>�𼭸� �ѱ��븦 ������ ������ ���� ���<==

							if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[2][0]==BLACK && b_pan_2012181008_eunjea[1][1]==WHITE && b_pan_2012181008_eunjea[0][0]==PAN ||
								b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[1][7]==BLACK && b_pan_2012181008_eunjea[2][6]==WHITE && b_pan_2012181008_eunjea[0][7]==PAN){
									//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

									num[i] = 1;

							}else if(b_put_2012181008_eunjea[i][0]-1!=0 && b_put_2012181008_eunjea[i][0]+1!=7 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
								//���� ��ǥ �� ���� �������� �ִٸ� �׸��� �� ������ �𼭸� �κ��� �ƴҶ�

								num[i] = 55;

							}else if(b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE ||
								b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
									//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̶��

									if(b_put_2012181008_eunjea[i][0]==2 && b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE){
										num[i] = 1;
									}else if(b_put_2012181008_eunjea[i][0]==5 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
										num[i] = 1;
									}else{
										num[i] = 75;
									}

							}else if(b_put_2012181008_eunjea[i][0]-1==WHITE || b_put_2012181008_eunjea[i][0]+1==WHITE){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����϶�

								if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
									num[i] = 3;
								}else{
									num[i] = 85;
								}

								//�ظ𼭸� �ϳ��� ���濡�� �������Ƿ� Default-50
							}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){	//Default ��ġ - 50
								num[i] = 40;
							}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){	//Default ��ġ - 50
								num[i] = 30;
							}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){	//Default ��ġ - 50
								num[i] = -45;
							}
					}else if(b_pan_2012181008_eunjea[0][7]==WHITE && b_pan_2012181008_eunjea[0][0]==WHITE){
						//==>�𼭸� �α��� ��� ������ ������ ���� ���<==

						if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[2][0]==BLACK && b_pan_2012181008_eunjea[1][1]==WHITE && b_pan_2012181008_eunjea[0][0]==PAN||
							b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[1][7]==BLACK && b_pan_2012181008_eunjea[2][6]==WHITE && b_pan_2012181008_eunjea[0][7]==PAN){
								//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

								num[i] = 1;

						}else if(b_put_2012181008_eunjea[i][0]-1!=0 && b_put_2012181008_eunjea[i][0]+1!=7 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
							//���� ��ǥ �� ���� �������� �ִٸ� �׸��� �� ������ �𼭸� �κ��� �ƴҶ�

							num[i] = 55;

						}else if(b_put_2012181008_eunjea[i][0]-1==WHITE || b_put_2012181008_eunjea[i][0]+1==WHITE){
							//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̶��

							if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){	//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
								num[i] = 3;
							}else{
								num[i] = 85;
							}
							//�ظ𼭸� �ΰ��� ���濡�� �������Ƿ� Default-60
						}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){	//Default ��ġ - 60
							num[i] = 30;
						}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){	//Default ��ġ - 60
							num[i] = 20;
						}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){	//Default ��ġ - 60
							num[i] = -55;
						}
					}
				}//end of ���ʺ�
				
				/*�� �Ʒ��� ��*/
				else if(1<=b_put_2012181008_eunjea[i][0] && b_put_2012181008_eunjea[i][0]<=6 && b_put_2012181008_eunjea[i][1]==7){
					if(b_pan_2012181008_eunjea[7][0]==BLACK && b_pan_2012181008_eunjea[7][7]==BLACK){
						//===>�� �� �𼭸� �Ѵ� �ΰ������� ������ ������<===

						if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[5][0]==BLACK && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[7][0]==PAN ||
							b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[5][7]==BLACK && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN){
								//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

								num[i] = 1;

						}else if(b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
							//���� ��ǥ �� ���� �������� �ִٸ�

							num[i] = 98;

						}else if(b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE ||
							b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� �� ���϶�

								if(b_put_2012181008_eunjea[i][0]==2 && b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE){
									num[i] = 1;
								}else if(b_put_2012181008_eunjea[i][0]==5 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
									num[i] = 1;
								}else{
									num[i] = 75;
								}

						}else if(b_put_2012181008_eunjea[i][0]-1==WHITE || b_put_2012181008_eunjea[i][0]+1==WHITE){
							//���� ��ǥ �� ���߿� �ϳ��� �ٸ����϶�

							if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
								num[i] = 3;
							}else{
								num[i] = 85;
							}
						}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){	//Default ��ġ
							num[i] = 90;
						}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){	//Default ��ġ
							num[i] = 80;
						}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){	//Default ��ġ
							num[i] = 5;
						}
					}else if(b_pan_2012181008_eunjea[7][0]==PAN && b_pan_2012181008_eunjea[7][7]==BLACK ||
							b_pan_2012181008_eunjea[7][0]==BLACK && b_pan_2012181008_eunjea[7][7]==PAN){
							//===>�� �� �𼭸� �� �ϳ� ���� �𼭸��� �ΰ������� �������϶�<===

							if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[5][0]==BLACK && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[7][0]==PAN ||
								b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[5][7]==BLACK && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN){
									//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

									num[i] = 1;

							}else if(b_pan_2012181008_eunjea[7][7]==WHITE && b_put_2012181008_eunjea[i][0]!=6 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE ||
								b_pan_2012181008_eunjea[7][0]==WHITE && b_put_2012181008_eunjea[i][0]!=1 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
									//���� ��ǥ �� ���� ����� ���� �ְ� �Ծ����� ���� �𼭸��� ���� ������ ���� �����϶�

									num[i] = 98;	//�ڡڡڡڡڡ��׽�Ʈ�� ����ġ üũ �غ���

							}else if(b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
								//���� ��ǥ �� ���� �������� �ִٸ�

								num[i] = 98;

							}else if(b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE ||
									b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
									//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� �� ���϶�

									if(b_put_2012181008_eunjea[i][0]==2 && b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE){
										num[i] = 1;
									}else if(b_put_2012181008_eunjea[i][0]==5 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
										num[i] = 1;
									}else{
										num[i] = 75;
									}

							}else if(b_put_2012181008_eunjea[i][0]-1==WHITE || b_put_2012181008_eunjea[i][0]+1==WHITE){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����϶�

								if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
									num[i] = 3;
								}else{
									num[i] = 85;
								}
							}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){	//Default ��ġ
								num[i] = 90;
							}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){	//Default ��ġ
								num[i] = 80;
							}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){	//Default ��ġ
								num[i] = 5;
							}
					}else if(b_pan_2012181008_eunjea[7][0]==PAN && b_pan_2012181008_eunjea[7][7]==PAN){
						//===>�� �� �𼭸� �Ѵ� �ƹ��� �ȸԾ�����<===

						if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[5][0]==BLACK && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[7][0]==PAN||
							b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[5][7]==BLACK && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN){
								//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

								num[i] = 1;

						}else if(b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
							//���� ��ǥ �� ���� �������� �ִٸ�

							num[i] = 95;

						}else if(b_put_2012181008_eunjea[i][0]-1==PAN && b_put_2012181008_eunjea[i][0]+1==PAN){
							//�ƹ��͵� ���ٸ�
							num[i] = 99;

						}else if(b_put_2012181008_eunjea[i][0]-1==PAN && b_put_2012181008_eunjea[i][0]+1==WHITE ||
								b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==PAN){

								if(b_put_2012181008_eunjea[i][0]-1==PAN && b_put_2012181008_eunjea[i][0]+1==WHITE){//�������� ��뵹�� �������� �װ�
									for(int j=1; b_put_2012181008_eunjea[i][0]+j<8; ++j){	 //�� ���� �� �ִ��� ����
										if( (b_put_2012181008_eunjea[i][0]+j)==WHITE){
											continue;
										}else if((b_put_2012181008_eunjea[i][0]+j)==BLACK){	
											num[i] = 98;
											break;
										}else{		//��ĭ
											num[i] = 15;
											break;
										}
									}
								}else{
									for(int j=1; 0 <= b_put_2012181008_eunjea[i][0]-j; ++j){
										if( (b_put_2012181008_eunjea[i][0]-j)==WHITE){
											continue;
										}else if((b_put_2012181008_eunjea[i][0]-j)==BLACK){	
											num[i] = 98;
											break;
										}else{		//��ĭ
											num[i] = 15;
											break;
										}
									}
								}


						}else if(b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE ||
							b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� �� ���϶�

								if(b_put_2012181008_eunjea[i][0]==2 && b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE){
									num[i] = 1;
								}else if(b_put_2012181008_eunjea[i][0]==5 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
									num[i] = 1;
								}else{
									num[i] = 85;
								}

						}else if(b_put_2012181008_eunjea[i][0]-1==WHITE || b_put_2012181008_eunjea[i][0]+1==WHITE){
							//���� ��ǥ �� ���߿� �ϳ��� �ٸ����϶�

							if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
								num[i] = 3;
							}else{
								num[i] = 85;
							}
						}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){	//Default ��ġ
							num[i] = 90;
						}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){	//Default ��ġ
							num[i] = 80;
						}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){	//Default ��ġ
							num[i] = 5;
						}

					}else if(b_pan_2012181008_eunjea[7][0]==BLACK && b_pan_2012181008_eunjea[7][7]==WHITE ||
							b_pan_2012181008_eunjea[7][0]==WHITE && b_pan_2012181008_eunjea[7][7]==BLACK){
							//===>�� �� �𼭸� �� �ϳ��� �ΰ������� �ϳ��� ������ �������϶�<===

							if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[5][0]==BLACK && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[7][0]==PAN||
								b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[5][7]==BLACK && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN){
									//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

									num[i] = 1;

							}else if(b_pan_2012181008_eunjea[7][7]==WHITE && b_put_2012181008_eunjea[i][0]!=6 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE ||
								b_pan_2012181008_eunjea[7][0]==WHITE && b_put_2012181008_eunjea[i][0]!=1 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
									//���� ��ǥ �� ���� ����� ���� �ְ� �Ծ����� ���� �𼭸��� ���� ������ ���� �����϶�

									num[i] = 98;	//�ڡڡڡڡڡ��׽�Ʈ�� ����ġ üũ �غ���

							}else if(b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
									//���� ��ǥ �� ���� �������� �ִٸ�

									num[i] = 98;

							}else if(b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE ||
								b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
									//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� �� ���϶�

									if(b_put_2012181008_eunjea[i][0]==2 && b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE){
										num[i] = 1;
									}else if(b_put_2012181008_eunjea[i][0]==5 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
										num[i] = 1;
									}else{
										num[i] = 75;
									}

							}else if(b_put_2012181008_eunjea[i][0]-1==WHITE || b_put_2012181008_eunjea[i][0]+1==WHITE){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����϶�

								if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
									num[i] = 3;
								}else{
									num[i] = 85;
								}
							}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){	//Default ��ġ
								num[i] = 90;
							}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){	//Default ��ġ
								num[i] = 80;
							}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){	//Default ��ġ
								num[i] = 5;
							}
					}else if(b_pan_2012181008_eunjea[7][0]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN || 
							b_pan_2012181008_eunjea[7][0]==PAN && b_pan_2012181008_eunjea[7][7]==WHITE){
							//==>�𼭸� �ѱ��븦 ������ ������ ���� ���<==

							if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[5][0]==BLACK && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[7][0]==PAN||
								b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[5][7]==BLACK && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN){
									//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

									num[i] = 1;

							}else if(b_put_2012181008_eunjea[i][0]-1!=0 && b_put_2012181008_eunjea[i][0]+1!=7 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
								//���� ��ǥ �� ���� �������� �ִٸ� �׸��� �� ������ �𼭸� �κ��� �ƴҶ�

								num[i] = 55;

							}else if(b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==WHITE){		
								//���� ��ǥ �� ���� �������� �ִٸ�

								num[i] = 98;

							}else if(b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE ||
								b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
									//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� �� ���϶�

									if(b_put_2012181008_eunjea[i][0]==2 && b_put_2012181008_eunjea[i][0]-1==BLACK && b_put_2012181008_eunjea[i][0]+1==WHITE){
										num[i] = 1;
									}else if(b_put_2012181008_eunjea[i][0]==5 && b_put_2012181008_eunjea[i][0]-1==WHITE && b_put_2012181008_eunjea[i][0]+1==BLACK){
										num[i] = 1;
									}else{
										num[i] = 75;
									}

							}else if(b_put_2012181008_eunjea[i][0]-1==WHITE || b_put_2012181008_eunjea[i][0]+1==WHITE){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����϶�

								if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
									num[i] = 3;
								}else{
									num[i] = 85;
								}
								//�ظ𼭸� �ϳ��� ���濡�� �������Ƿ� Default-50
							}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){	//Default ��ġ - 50
								num[i] = 40;
							}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){	//Default ��ġ - 50
								num[i] = 30;
							}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){	//Default ��ġ - 50
								num[i] = -45;
							}
					}else if(b_pan_2012181008_eunjea[7][7]==WHITE && b_pan_2012181008_eunjea[0][0]==WHITE){
						//==>�𼭸� �α��� ��� ������ ������ ���� ���<==

						if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[5][0]==BLACK && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[7][0]==PAN||
							b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[5][7]==BLACK && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN){
							//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

								num[i] = 1;

						}else if( (b_put_2012181008_eunjea[i][0]-1)!=0 && (b_put_2012181008_eunjea[i][0]+1)!=7 && (b_put_2012181008_eunjea[i][0]-1)==WHITE && (b_put_2012181008_eunjea[i][0]+1)==WHITE){		
							//���� ��ǥ �� ���� �������� �ִٸ� �׸��� �� ������ �𼭸� �κ��� �ƴҶ�

							num[i] = 55;
							//�ظ𼭸� �ΰ��� ���濡�� �������Ƿ� Default-60

						}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){	//Default ��ġ - 60
							num[i] = 30;
						}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){	//Default ��ġ - 60
							num[i] = 20;
						}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){	//Default ��ġ - 60
							num[i] = -55;
						}
					}
				}//end of �� �Ʒ��� ����

				/*�� ���� ����*/
				else if(1<=b_put_2012181008_eunjea[i][1] && b_put_2012181008_eunjea[i][1]<=6 && b_put_2012181008_eunjea[i][0]==0){
					if(b_pan_2012181008_eunjea[0][0]==BLACK && b_pan_2012181008_eunjea[7][0]==BLACK){
						//===>�� �� �𼭸� �Ѵ� �ΰ������� ������ ������<===

						if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[0][2]==BLACK && b_pan_2012181008_eunjea[1][1]==WHITE && b_pan_2012181008_eunjea[0][0]==PAN ||
							b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[7][2]==BLACK && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[7][0]==PAN){
								//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

								num[i] = 1;

						}else if(b_put_2012181008_eunjea[i][1]-1==PAN && b_put_2012181008_eunjea[i][1]+1==WHITE || 
							b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==PAN){

								num[i] = 20;

						}else if(b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE){		
							//���� ��ǥ �� ���� �������� �ִٸ�

							num[i] = 98;

						}else if(b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE ||
							b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� �� ���϶�

								if(b_put_2012181008_eunjea[i][1]==2 && b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE){
									num[i] = 1;
								}else if(b_put_2012181008_eunjea[i][1]==5 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
									num[i] = 1;
								}else{
									num[i] = 75;
								}
						}else if(b_put_2012181008_eunjea[i][1]-1==WHITE || b_put_2012181008_eunjea[i][1]+1==WHITE){
							//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̶��

							if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
								num[i] = 3;
							}else{
								num[i] = 85;
							}

						}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){	//Default ��ġ
							num[i] = 90;
						}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){	//Default ��ġ
							num[i] = 80;
						}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){	//Default ��ġ
							num[i] = 5;
						}

					}else if(b_pan_2012181008_eunjea[7][0]==PAN && b_pan_2012181008_eunjea[0][0]==BLACK ||
						b_pan_2012181008_eunjea[7][0]==BLACK && b_pan_2012181008_eunjea[0][0]==PAN){
							//===>�� �� �𼭸� �� �ϳ� ���� �𼭸��� �ΰ������� �������϶�<===

							if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[0][2]==BLACK && b_pan_2012181008_eunjea[1][1]==WHITE && b_pan_2012181008_eunjea[0][0]==PAN||
								b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[7][2]==BLACK && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[7][0]==PAN){
									//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

									num[i] = 1;

							}else if(b_pan_2012181008_eunjea[0][0]==WHITE && b_put_2012181008_eunjea[i][1]!=1 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE ||
								b_pan_2012181008_eunjea[7][0]==WHITE && b_put_2012181008_eunjea[i][1]!=6 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE){		
									//���� ��ǥ �� ���� ����� ���� �ְ� �Ծ����� ���� �𼭸��� ���� ������ ���� �����϶�

									num[i] = 98;	//�ڡڡڡڡڡ��׽�Ʈ�� ����ġ üũ �غ���

							}else if(b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE ||
								b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
									//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� �� ���϶�

									if(b_put_2012181008_eunjea[i][1]==2 && b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE){
										num[i] = 1;
									}else if(b_put_2012181008_eunjea[i][1]==5 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
										num[i] = 1;
									}else{
										num[i] = 75;
									}
							}else if(b_put_2012181008_eunjea[i][1]-1==WHITE || b_put_2012181008_eunjea[i][1]+1==WHITE){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̶��

								if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
									num[i] = 3;
								}else{
									num[i] = 85;
								}

							}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){	//Default ��ġ
								num[i] = 90;
							}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){	//Default ��ġ
								num[i] = 80;
							}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){	//Default ��ġ
								num[i] = 5;
							}
					}else if(b_pan_2012181008_eunjea[7][0]==PAN && b_pan_2012181008_eunjea[0][0]==PAN){
						//===>�� �� �𼭸� �Ѵ� �ƹ��� �ȸԾ�����<===

						if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[0][2]==BLACK && b_pan_2012181008_eunjea[1][1]==WHITE && b_pan_2012181008_eunjea[0][0]==PAN||
							b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[7][2]==BLACK && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[7][0]==PAN){
								//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

								num[i] = 1;

						}else if(b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE){		
							//���� ��ǥ �� ���� �������� �ִٸ�

							num[i] = 95;

						}else if(b_put_2012181008_eunjea[i][1]-1==PAN && b_put_2012181008_eunjea[i][1]+1==PAN){
							//�ƹ��͵� ���ٸ�
							num[i] = 99;

						}else if(b_put_2012181008_eunjea[i][1]-1==PAN && b_put_2012181008_eunjea[i][1]+1==WHITE ||
							b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==PAN){

								if(b_put_2012181008_eunjea[i][1]-1==PAN && b_put_2012181008_eunjea[i][1]+1==WHITE){//�������� ��뵹�� �������� �װ�
									for(int j=1; b_put_2012181008_eunjea[i][1]+j<8; ++j){	 //�� ���� �� �ִ��� ����
										if( (b_put_2012181008_eunjea[i][1]+j)==WHITE){
											continue;
										}else if((b_put_2012181008_eunjea[i][1]+j)==BLACK){	
											num[i] = 98;
											break;
										}else{		//��ĭ
											num[i] = 15;
											break;
										}
									}
								}else{
									for(int j=1; 0 <= b_put_2012181008_eunjea[i][1]-j; ++j){
										if( (b_put_2012181008_eunjea[i][1]-j)==WHITE){
											continue;
										}else if((b_put_2012181008_eunjea[i][1]-j)==BLACK){	
											num[i] = 98;
											break;
										}else{		//��ĭ
											num[i] = 15;
											break;
										}
									}
								}

						}else if(b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE ||
							b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� �� ���϶�

								if(b_put_2012181008_eunjea[i][1]==2 && b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE){
									num[i] = 1;
								}else if(b_put_2012181008_eunjea[i][1]==5 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
									num[i] = 1;
								}else{
									num[i] = 85;
								}
						}else if(b_put_2012181008_eunjea[i][1]-1==WHITE || b_put_2012181008_eunjea[i][1]+1==WHITE){
							//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̶��
							if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
								num[i] = 3;					 
							}else{
								num[i] = 85;
							}
						}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){	//Default ��ġ
							num[i] = 90;
						}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){	//Default ��ġ
							num[i] = 80;
						}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){	//Default ��ġ
							num[i] = 5;
						}

					}else if(b_pan_2012181008_eunjea[7][0]==BLACK && b_pan_2012181008_eunjea[0][0]==WHITE ||
							b_pan_2012181008_eunjea[7][0]==WHITE && b_pan_2012181008_eunjea[0][0]==BLACK){
							//===>�� �� �𼭸� �� �ϳ��� �ΰ������� �ϳ��� ������ �������϶�<===

							if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[0][2]==BLACK && b_pan_2012181008_eunjea[1][1]==WHITE && b_pan_2012181008_eunjea[0][0]==PAN||
								b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[7][2]==BLACK && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[7][0]==PAN){
									//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

									num[i] = 1;

							}else if(b_pan_2012181008_eunjea[0][0]==WHITE && b_put_2012181008_eunjea[i][1]!=1 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE ||
								b_pan_2012181008_eunjea[7][0]==WHITE && b_put_2012181008_eunjea[i][1]!=6 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE){		
									//���� ��ǥ �� ���� ����� ���� �ְ� �Ծ����� ���� �𼭸��� ���� ������ ���� �����϶�

									num[i] = 98;	//�ڡڡڡڡڡ��׽�Ʈ�� ����ġ üũ �غ���

							}else if(b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE ||
								b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
									//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� �� ���϶�

									if(b_put_2012181008_eunjea[i][1]==2 && b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE){
										num[i] = 1;
									}else if(b_put_2012181008_eunjea[i][1]==5 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
										num[i] = 1;
									}else{
										num[i] = 75;
									}
							}else if(b_put_2012181008_eunjea[i][1]-1==WHITE || b_put_2012181008_eunjea[i][1]+1==WHITE){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̶��
								if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
									num[i] = 3;					 
								}else{
									num[i] = 85;
								}

							}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){	//Default ��ġ
								num[i] = 90;
							}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){	//Default ��ġ
								num[i] = 80;
							}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){	//Default ��ġ
								num[i] = 5;
							}
					}else if(b_pan_2012181008_eunjea[7][0]==WHITE && b_pan_2012181008_eunjea[0][0]==PAN || 
						b_pan_2012181008_eunjea[7][0]==PAN && b_pan_2012181008_eunjea[0][0]==WHITE){
							//==>�𼭸� �ѱ��븦 ������ ������ ���� ���<==

							if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[0][2]==BLACK && b_pan_2012181008_eunjea[1][1]==WHITE && b_pan_2012181008_eunjea[0][0]==PAN||
								b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[7][2]==BLACK && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[7][0]==PAN){
									//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

									num[i] = 1;

							}else if(b_put_2012181008_eunjea[i][1]-1!=0 && b_put_2012181008_eunjea[i][1]+1!=7 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE){		
								//���� ��ǥ �� ���� �������� �ִٸ� �׸��� �� ������ �𼭸� �κ��� �ƴҶ�

								num[i] = 55;

							}else if(b_put_2012181008_eunjea[i][1]-1==WHITE || b_put_2012181008_eunjea[i][1]+1==WHITE){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̶��

								if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
									num[i] = 3;
								}else{
									num[i] = 85;
								}
								//�ظ𼭸� �ϳ��� ���濡�� �������Ƿ� Default-50
							}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){	//Default ��ġ - 50
								num[i] = 40;
							}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){	//Default ��ġ - 50
								num[i] = 30;
							}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){	//Default ��ġ - 50
								num[i] = -45;
							}

					}else if(b_pan_2012181008_eunjea[0][0]==WHITE && b_pan_2012181008_eunjea[7][0]==WHITE){
						//==>�𼭸� �α��� ��� ������ ������ ���� ���<==

						if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[0][2]==BLACK && b_pan_2012181008_eunjea[1][1]==WHITE && b_pan_2012181008_eunjea[0][0]==PAN||
							b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[7][2]==BLACK && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[7][0]==PAN){
								//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

								num[i] = 1;

						}else if(b_put_2012181008_eunjea[i][1]-1!=0 && b_put_2012181008_eunjea[i][1]+1!=7 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE){		
							//���� ��ǥ �� ���� �������� �ִٸ� �׸��� �� ������ �𼭸� �κ��� �ƴҶ�

							num[i] = 55;
							//�ظ𼭸� �ΰ��� ���濡�� �������Ƿ� Default-60
						}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){	//Default ��ġ - 60
							num[i] = 30;
						}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){	//Default ��ġ - 60
							num[i] = 20;
						}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){	//Default ��ġ - 60
							num[i] = -55;
						}
					}
				}//end of �� ���� ����

				/*�� ������ ����*/
				else if(1<=b_put_2012181008_eunjea[i][1] && b_put_2012181008_eunjea[i][1]<=6 && b_put_2012181008_eunjea[i][0]==7){
					if(b_pan_2012181008_eunjea[0][7]==BLACK && b_pan_2012181008_eunjea[7][7]==BLACK){
						//===>�� �� �𼭸� �Ѵ� �ΰ������� ������ ������<==

						if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[0][5]==BLACK && b_pan_2012181008_eunjea[1][6]==WHITE && b_pan_2012181008_eunjea[0][7]==PAN||
							b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[7][5]==BLACK && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN){
								//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

								num[i] = 1;

						}else if(b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE){		
							//���� ��ǥ �� ���� �������� �ִٸ�

							num[i] = 98;

						}else if(b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE ||
							b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� �� ���϶�

								if(b_put_2012181008_eunjea[i][1]==2 && b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE){
									num[i] = 1;
								}else if(b_put_2012181008_eunjea[i][1]==5 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
									num[i] = 1;
								}else{
									num[i] = 75;
								}
						}else if(b_put_2012181008_eunjea[i][1]-1==WHITE || b_put_2012181008_eunjea[i][1]+1==WHITE){
							//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̶��

							if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
								num[i] = 3;
							}else{
								num[i] = 85;
							}
						}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){	//Default ��ġ
							num[i] = 90;
						}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){	//Default ��ġ
							num[i] = 80;
						}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){	//Default ��ġ
							num[i] = 5;
						}
					}else if(b_pan_2012181008_eunjea[0][7]==PAN && b_pan_2012181008_eunjea[7][7]==BLACK ||
						b_pan_2012181008_eunjea[0][7]==BLACK && b_pan_2012181008_eunjea[7][7]==PAN){
							//===>�� �� �𼭸� �� �ϳ� ���� �𼭸��� �ΰ������� �������϶�<===

							if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[0][5]==BLACK && b_pan_2012181008_eunjea[1][6]==WHITE && b_pan_2012181008_eunjea[0][7]==PAN||
								b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[7][5]==BLACK && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN){
									//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

									num[i] = 1;

							}else if(b_pan_2012181008_eunjea[0][7]==WHITE && b_put_2012181008_eunjea[i][1]!=1 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE ||
								b_pan_2012181008_eunjea[7][7]==WHITE && b_put_2012181008_eunjea[i][1]!=6 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE){		
									//���� ��ǥ �� ���� ����� ���� �ְ� �Ծ����� ���� �𼭸��� ���� ������ ���� �����϶�

									num[i] = 98;	//�ڡڡڡڡڡ��׽�Ʈ�� ����ġ üũ �غ���

							}else if(b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE ||
								b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
									//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� �� ���϶�

									if(b_put_2012181008_eunjea[i][1]==2 && b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE){
										num[i] = 1;
									}else if(b_put_2012181008_eunjea[i][1]==5 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
										num[i] = 1;
									}else{
										num[i] = 75;
									}
							}else if(b_put_2012181008_eunjea[i][1]-1==WHITE || b_put_2012181008_eunjea[i][1]+1==WHITE){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̶��

								if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
									num[i] = 3;
								}else{
									num[i] = 85;
								}

							}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){	//Default ��ġ
								num[i] = 90;
							}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){	//Default ��ġ
								num[i] = 80;
							}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){	//Default ��ġ
								num[i] = 5;
							}
					}else if(b_pan_2012181008_eunjea[0][7]==PAN && b_pan_2012181008_eunjea[7][7]==PAN){
						//===>�� �� �𼭸� �Ѵ� �ƹ��� �ȸԾ�����<===

						if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[0][5]==BLACK && b_pan_2012181008_eunjea[1][6]==WHITE && b_pan_2012181008_eunjea[0][7]==PAN ||
							b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[7][5]==BLACK && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN){
								//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

								num[i] = 1;

						}else if(b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE){		
							//���� ��ǥ �� ���� �������� �ִٸ�

							num[i] = 95;

						}else if(b_put_2012181008_eunjea[i][1]-1==PAN && b_put_2012181008_eunjea[i][1]+1==PAN){
							//�ƹ��͵� ���ٸ�
							num[i] = 99;

						}else if(b_put_2012181008_eunjea[i][1]-1==PAN && b_put_2012181008_eunjea[i][1]+1==WHITE ||
							b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==PAN){

								if(b_put_2012181008_eunjea[i][1]-1==PAN && b_put_2012181008_eunjea[i][1]+1==WHITE){//�������� ��뵹�� �������� �װ�
									for(int j=1; b_put_2012181008_eunjea[i][1]+j<8; ++j){	 //�� ���� �� �ִ��� ����
										if( (b_put_2012181008_eunjea[i][1]+j)==WHITE){
											continue;
										}else if((b_put_2012181008_eunjea[i][1]+j)==BLACK){	
											num[i] = 98;
											break;
										}else{		//��ĭ
											num[i] = 15;
											break;
										}
									}
								}else{
									for(int j=1; 0 <= b_put_2012181008_eunjea[i][1]-j; ++j){
										if( (b_put_2012181008_eunjea[i][1]-j)==WHITE){
											continue;
										}else if((b_put_2012181008_eunjea[i][1]-j)==BLACK){	
											num[i] = 98;
											break;
										}else{		//��ĭ
											num[i] = 15;
											break;
										}
									}
								}

						}else if(b_put_2012181008_eunjea[i][1]-1==PAN && b_put_2012181008_eunjea[i][1]+1==WHITE ||
							b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==PAN){	

								num[i] = 15;

						}else if(b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE ||
							b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� �� ���϶�

								if(b_put_2012181008_eunjea[i][1]==2 && b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE){
									num[i] = 1;
								}else if(b_put_2012181008_eunjea[i][1]==5 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
									num[i] = 1;
								}else{
									num[i] = 85;
								}
						}else if(b_put_2012181008_eunjea[i][1]-1==WHITE || b_put_2012181008_eunjea[i][1]+1==WHITE){
							//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̶��
							if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
								num[i] = 3;					 
							}else{
								num[i] = 85;
							}

						}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){	//Default ��ġ
							num[i] = 90;
						}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){	//Default ��ġ
							num[i] = 80;
						}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){	//Default ��ġ
							num[i] = 5;
						}
					}else if(b_pan_2012181008_eunjea[0][7]==BLACK && b_pan_2012181008_eunjea[7][7]==WHITE ||
						b_pan_2012181008_eunjea[0][7]==WHITE && b_pan_2012181008_eunjea[7][7]==BLACK){
							//===>�� �� �𼭸� �� �ϳ��� �ΰ������� �ϳ��� ������ �������϶�<===

							if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[0][5]==BLACK && b_pan_2012181008_eunjea[1][6]==WHITE && b_pan_2012181008_eunjea[0][7]==PAN||
								b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[7][5]==BLACK && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN){
									//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

									num[i] = 1;

							}else if(b_pan_2012181008_eunjea[0][7]==WHITE && b_put_2012181008_eunjea[i][1]!=1 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE ||
								b_pan_2012181008_eunjea[7][7]==WHITE && b_put_2012181008_eunjea[i][1]!=6 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE){		
									//���� ��ǥ �� ���� ����� ���� �ְ� �Ծ����� ���� �𼭸��� ���� ������ ���� �����϶�

									num[i] = 98;	//�ڡڡڡڡڡ��׽�Ʈ�� ����ġ üũ �غ���

							}else if(b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE ||
								b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
									//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̰� ������ �ϳ��� �� ���϶�

									if(b_put_2012181008_eunjea[i][1]==2 && b_put_2012181008_eunjea[i][1]-1==BLACK && b_put_2012181008_eunjea[i][1]+1==WHITE){
										num[i] = 1;
									}else if(b_put_2012181008_eunjea[i][1]==5 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==BLACK){
										num[i] = 1;
									}else{
										num[i] = 75;
									}
							}else if(b_put_2012181008_eunjea[i][1]-1==WHITE || b_put_2012181008_eunjea[i][1]+1==WHITE){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̶��
								if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
									num[i] = 3;					 
								}else{
									num[i] = 85;
								}
							}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){	//Default ��ġ
								num[i] = 90;
							}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){	//Default ��ġ
								num[i] = 80;
							}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){	//Default ��ġ
								num[i] = 5;
							}
					}else if(b_pan_2012181008_eunjea[0][7]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN || 
							b_pan_2012181008_eunjea[0][7]==PAN && b_pan_2012181008_eunjea[7][7]==WHITE){
							//==>�𼭸� �ѱ��븦 ������ ������ ���� ���<==

							if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[0][5]==BLACK && b_pan_2012181008_eunjea[1][6]==WHITE && b_pan_2012181008_eunjea[0][7]==PAN||
								b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[7][5]==BLACK && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN){
									//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

									num[i] = 1;

							}else if(b_put_2012181008_eunjea[i][1]-1!=0 && b_put_2012181008_eunjea[i][1]+1!=7 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE){		
								//���� ��ǥ �� ���� �������� �ִٸ� �׸��� �� ������ �𼭸� �κ��� �ƴҶ�

								num[i] = 55;

							}else if(b_put_2012181008_eunjea[i][1]-1==WHITE || b_put_2012181008_eunjea[i][1]+1==WHITE){
								//���� ��ǥ �� ���߿� �ϳ��� �ٸ����̶��

								if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){//���⿡ �����ÿ� �𼭸��� ���� Ȯ���� ũ�Ƿ� ���� ��ġ�� ���´�
									num[i] = 3;
								}else{
									num[i] = 85;
								}
								//�ظ𼭸� �ϳ��� ���濡�� �������Ƿ� Default-50
							}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){	//Default ��ġ - 50
								num[i] = 40;
							}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){	//Default ��ġ - 50
								num[i] = 30;
							}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){	//Default ��ġ - 50
								num[i] = -45;
							}
					}else if(b_pan_2012181008_eunjea[7][7]==WHITE && b_pan_2012181008_eunjea[0][7]==WHITE){
						//==>�𼭸� �α��� ��� ������ ������ ���� ���<==

						if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[0][5]==BLACK && b_pan_2012181008_eunjea[1][6]==WHITE && b_pan_2012181008_eunjea[0][7]==PAN||
							b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[7][5]==BLACK && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[7][7]==PAN){
								//�ش� ��ǥ�� ������ ���� ���������鼭 ���� ������ �ȵ� �ι�° �𼭸��� �Ծ�����

								num[i] = 1;

						}else if(b_put_2012181008_eunjea[i][1]-1!=0 && b_put_2012181008_eunjea[i][1]+1!=7 && b_put_2012181008_eunjea[i][1]-1==WHITE && b_put_2012181008_eunjea[i][1]+1==WHITE){		
							//���� ��ǥ �� ���� �������� �ִٸ� �׸��� �� ������ �𼭸� �κ��� �ƴҶ�

							num[i] = 55;
							//�ظ𼭸� �ΰ��� ���濡�� �������Ƿ� Default-60
						}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){	//Default ��ġ - 60
							num[i] = 30;
						}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){	//Default ��ġ - 60
							num[i] = 20;
						}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){	//Default ��ġ - 60
							num[i] = -55;
						}
					}
				}//end of �� ������ ����
		}//end of ����

		/**********************�ι�° �� ��**************************/
		else if(1<=b_put_2012181008_eunjea[i][0] && b_put_2012181008_eunjea[i][0]<=6 && b_put_2012181008_eunjea[i][1]==1 ||		//���� �ι�°��
			1<=b_put_2012181008_eunjea[i][0] && b_put_2012181008_eunjea[i][0]<=6 && b_put_2012181008_eunjea[i][1]==6 ||			//�Ʒ��� �ι�°��
			1<=b_put_2012181008_eunjea[i][1] && b_put_2012181008_eunjea[i][1]<=6 && b_put_2012181008_eunjea[i][0]==1 ||			//���� �ι�°��
			1<=b_put_2012181008_eunjea[i][1] && b_put_2012181008_eunjea[i][1]<=6 && b_put_2012181008_eunjea[i][0]==6){			//������ �ι�°��

				/*���� �ι�°��*/
				if(1<=b_put_2012181008_eunjea[i][0] && b_put_2012181008_eunjea[i][0]<=6 && b_put_2012181008_eunjea[i][1]==1){	
					if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[1][1]==WHITE && b_pan_2012181008_eunjea[1][0]==BLACK && b_pan_2012181008_eunjea[0][0]==PAN||
						b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[1][6]==WHITE && b_pan_2012181008_eunjea[1][7]==BLACK && b_pan_2012181008_eunjea[0][7]==PAN){

							num[i] = 1;

					}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){

						num[i] = 1;

					}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){

						num[i] = 30;

					}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){

						num[i] = 20;

					}
				}
				/*�Ʒ��� �ι��� ��*/
				else if(1<=b_put_2012181008_eunjea[i][0] && b_put_2012181008_eunjea[i][0]<=6 && b_put_2012181008_eunjea[i][1]==6){	
					if(b_put_2012181008_eunjea[i][0]==2 && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[6][0]==BLACK && b_pan_2012181008_eunjea[7][0]==PAN||
						b_put_2012181008_eunjea[i][0]==5 && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[6][7]==BLACK && b_pan_2012181008_eunjea[7][7]==PAN){

							num[i] = 1;

					}else if(b_put_2012181008_eunjea[i][0]==1 || b_put_2012181008_eunjea[i][0]==6){

						num[i] = 1;

					}else if(b_put_2012181008_eunjea[i][0]==3 || b_put_2012181008_eunjea[i][0]==4){

						num[i] = 30;

					}else if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){

						num[i] = 20;

					}
				}
				/*���� �ι�°��*/
				else if(1<=b_put_2012181008_eunjea[i][1] && b_put_2012181008_eunjea[i][1]<=6 && b_put_2012181008_eunjea[i][0]==1){	
					if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[1][1]==WHITE && b_pan_2012181008_eunjea[0][1]==BLACK && b_pan_2012181008_eunjea[0][0]==PAN||
						b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[6][1]==WHITE && b_pan_2012181008_eunjea[7][1]==BLACK && b_pan_2012181008_eunjea[7][0]==PAN){

							num[i] = 1;

					}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){

						num[i] = 1;

					}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){

						num[i] = 30;

					}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){

						num[i] = 20;

					}
				}
				/*������ �ι�° ��*/
				else if(1<=b_put_2012181008_eunjea[i][1] && b_put_2012181008_eunjea[i][1]<=6 && b_put_2012181008_eunjea[i][0]==6){	
					if(b_put_2012181008_eunjea[i][1]==2 && b_pan_2012181008_eunjea[1][6]==WHITE && b_pan_2012181008_eunjea[0][6]==BLACK && b_pan_2012181008_eunjea[0][7]==PAN||
						b_put_2012181008_eunjea[i][1]==5 && b_pan_2012181008_eunjea[6][6]==WHITE && b_pan_2012181008_eunjea[7][6]==BLACK && b_pan_2012181008_eunjea[7][7]==PAN){

							num[i] = 1;

					}else if(b_put_2012181008_eunjea[i][1]==1 || b_put_2012181008_eunjea[i][1]==6){

						num[i] = 1;

					}else if(b_put_2012181008_eunjea[i][1]==3 || b_put_2012181008_eunjea[i][1]==4){

						num[i] = 30;

					}else if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){

						num[i] = 20;

					}
				}
		}//end of �ι�° ��
		/**********************����° �� ��**************************/
		else if(1<=b_put_2012181008_eunjea[i][0] && b_put_2012181008_eunjea[i][0]<=6 && b_put_2012181008_eunjea[i][1]==2 ||		//���� ����°��
			1<=b_put_2012181008_eunjea[i][0] && b_put_2012181008_eunjea[i][0]<=6 && b_put_2012181008_eunjea[i][1]==5 ||			//�Ʒ��� ����°��
			1<=b_put_2012181008_eunjea[i][1] && b_put_2012181008_eunjea[i][1]<=6 && b_put_2012181008_eunjea[i][0]==2 ||			//���� ����°��
			1<=b_put_2012181008_eunjea[i][1] && b_put_2012181008_eunjea[i][1]<=6 && b_put_2012181008_eunjea[i][0]==5){			//������ ����°��

				/*���� ����° ��*/
				if(1<=b_put_2012181008_eunjea[i][0] && b_put_2012181008_eunjea[i][0]<=6 && b_put_2012181008_eunjea[i][1]==2){		
					if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){				//����° ���� �𼭸� �κ�
						num[i] = 70;
					}else{
						num[i] = 50;
					}
				}
				/*�Ʒ��� ����° ��*/
				else if(1<=b_put_2012181008_eunjea[i][0] && b_put_2012181008_eunjea[i][0]<=6 && b_put_2012181008_eunjea[i][1]==5){
					if(b_put_2012181008_eunjea[i][0]==2 || b_put_2012181008_eunjea[i][0]==5){				//����° ���� �𼭸� �κ�
						num[i] = 70;
					}else{
						num[i] = 50;
					}
				}
				/*���� ����° ��*/
				else if(1<=b_put_2012181008_eunjea[i][1] && b_put_2012181008_eunjea[i][1]<=6 && b_put_2012181008_eunjea[i][0]==2){
					if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){				//����° ���� �𼭸� �κ�
						num[i] = 70;
					}else{
						num[i] = 50;
					}
				}
				/*������ ����° ��*/
				else{
					if(b_put_2012181008_eunjea[i][1]==2 || b_put_2012181008_eunjea[i][1]==5){				//����° ���� �𼭸� �κ�
						num[i] = 70;
					}else{
						num[i] = 50;
					}
				}
		}
	}

	max = num[0];
	max_index = 0;

	for(int i=0; i<b_k_2012181008_eunjea; ++i){
		if(max < num[i]){
			max		  = num[i];
			max_index = i;
		}
	}

	*x = b_put_2012181008_eunjea[max_index][0];
	*y = b_put_2012181008_eunjea[max_index][1];
}

void BlackDefence_2012181008_eunjae( int x, int y )
{
	return;
}


#endif