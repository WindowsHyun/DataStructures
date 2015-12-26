#include "OdeloBattleSystem.h"
#include <stdio.h>

typedef struct dostone2{
	int x;
	int y;
	int score;
	int reversenum;
};

int board2[8][8];
dostone2 stoneP2[8][8];
dostone2 temp2;
int howmany;


BOOL isfirst2 = false;
int canStone2(int , int );
void reversestoneB2(int, int);
void reversestoneW2(int , int);

// 0 ºóÄ­, 1 Èæµ¹, 2 ¹éµ¹

void WhiteAttack( int *x, int *y )
{

	for(int i = 0; i<8; ++i){
		printf("%d\n",  canStone2(0, 0) );
		for(int j = 0; j<8; ++j){
			
			if(canStone2(i, j ) == 1){
				if((i == 0 && j == 0) || (i == 0 && j ==7) || (i == 7 && j ==0) || (i == 7 && j ==7)){
					stoneP2[i][j].score = 150;
					stoneP2[i][j].x = j;
					stoneP2[i][j].y = i;
					stoneP2[i][j].reversenum = howmany-1;
				}

				else if(((i == 0 || i == 7) && (1<=j && j<=6))||((j == 0 || j == 7) && (1<=i && i<=6))){
					stoneP2[i][j].score = 100;
					stoneP2[i][j].x = j;
					stoneP2[i][j].y = i;
					stoneP2[i][j].reversenum = howmany-1;
				}
				else if( (2<=i && i<= 5) && (2<=j && j<= 5) ){
					stoneP2[i][j].score = 50;
					stoneP2[i][j].x = j;
					stoneP2[i][j].y = i;
					stoneP2[i][j].reversenum = howmany-1;
				}
				else if( (i == 1 && j == 1) || (i == 1 && j == 6) || (i == 6 && j == 1) || (i == 6 && j == 6) ){
					stoneP2[i][j].score = 1;
					stoneP2[i][j].x = j;
					stoneP2[i][j].y = i;
					stoneP2[i][j].reversenum = howmany-1;
				}
				else {
					stoneP2[i][j].score = 30;
					stoneP2[i][j].x = j;
					stoneP2[i][j].y = i;
					stoneP2[i][j].reversenum = howmany-1;
				}
			}
		}
	}

	howmany = 0;

	temp2.score = 0;
	temp2.reversenum = 0;

	for(int i = 0; i<8; ++i){
		for(int j = 0; j<8; ++j){
			if(temp2.score <= stoneP2[i][j].score){
				temp2.score = stoneP2[i][j].score;
				temp2.x = stoneP2[i][j].x;
				temp2.y = stoneP2[i][j].y;
			}
			else if(temp2.score == stoneP2[i][j].score){
				if(temp2.reversenum <= stoneP2[i][j].reversenum){
					temp2.reversenum = stoneP2[i][j].reversenum;
					temp2.x = stoneP2[i][j].x;
				    temp2.y = stoneP2[i][j].y;
				}
				else if(temp2.reversenum > stoneP2[i][j].reversenum){
					temp2.x = temp2.x;
					temp2.y = temp2.y;
				}
				
			}
		}
	}

	printf( " %d, %d\n", temp2.x,temp2.y );

	*x = temp2.x;
	*y = temp2.y;

	for(int i = 0; i<8; ++i){
		for(int j = 0; j<8; ++j){
			stoneP2[i][j].score = 0;
			stoneP2[i][j].x = 0;
			stoneP2[i][j].y = 0;
			
		}
	}
	board2[temp2.y][temp2.x] = 2;
	reversestoneW2(temp2.y,temp2.x );

	temp2.score = 0;
	temp2.x = 0;
	temp2.y = 0;

	for(int i = 0; i<8; ++i){
		for(int j = 0; j<8; ++j){
			printf( "%d ", board2[i][j] );
		}
		printf("\n");
	}
}

void WhiteDefence( int x, int y ){
	if(!(isfirst2)){
		for(int i = 0; i<8; ++i){
			for(int j = 0; j<8; ++j){
				board2[i][j] = 0;
			}
		}
		board2[3][3] = 1;
		board2[4][4] = 1;
		board2[3][4] = 2;
		board2[4][3] = 2;

		isfirst2 = true;
	}
	board2[y][x] = 1;
	reversestoneB2(y, x);
}

int canStone2(int y, int x){
    if(board2[y][x] == 0){
        for(int k=-1; k<=1; ++k){
            for(int l=-1;l<=1; ++l){
                if(board2[y+k][x+l]== 1){
                    int sigx = x+l;
                    int sigy = y+k;
                    int n = 0;
                    while(n<8){
						if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
							
                            break;
                        }
                        if(board2[sigy][sigx]==2){
                          return 1;
                            break;
                        }

                        else if(board2[sigy][sigx]!=1 || board2[sigy][sigx]==0){
							
                            break;
							
                        }

                        else if(n==7){
							
                            break;

                        }
                        sigy+=k;
                        sigx+=l;
                        n+=1;
						howmany = n;
                    }



                }

                else if(k==1 && l==1)
					 return 0;		
            }
        }
	}

    
}


void reversestoneB2(int y, int x){
   
        for(int k=-1; k<=1; ++k){
            for(int l=-1;l<=1; ++l){
                if(board2[y+k][x+l]==2){
                    int sigx = x+l;
                    int sigy = y+k;
                    int n = 0;
                    while(n<7){
                        if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
                            break;
                        }
                        if(board2[sigy][sigx]==1){
                            while(n>0){
                                if(sigy == y && sigx == x){
                                    break;
                                } 
                                else if(n==0){
                                    break;
                                }

                                board2[sigy-k][sigx-l] = 1;
                                sigy-=k;
                                sigx-=l;
                                n-=1;                                                              
                            }                            


                            break;
                        }
                        else if(board2[sigy][sigx]!=2){
                            break;
                        }

                        else if(n==6){

                            break;
                        }

                        sigy+=k;
                        sigx+=l;
                        n+=1;
                    }



                }

                else if(k==1 && l==1)
                    return;			
            }
        }
}


void reversestoneW2(int y, int x){
   
        for(int k=-1; k<=1; ++k){
            for(int l=-1;l<=1; ++l){
                if(board2[y+k][x+l]==1){
                    int sigx = x+l;
                    int sigy = y+k;
                    int n = 0;
                    while(n<7){
                        if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
                            break;
                        }
                        if(board2[sigy][sigx]==2){
                            while(n>0){
                                if(sigy == y && sigx == x){
                                    break;
                                } 
                                else if(n==0){
                                    break;
                                }

                                board2[sigy-k][sigx-l] = 2;
                                sigy-=k;
                                sigx-=l;
                                n-=1;                                                              
                            }                            


                            break;
                        }
                        else if(board2[sigy][sigx]!=1){
                            break;
                        }

                        else if(n==6){

                            break;
                        }

                        sigy+=k;
                        sigx+=l;
                        n+=1;
                    }



                }

                else if(k==1 && l==1)
                    return;			
            }
        }
}

