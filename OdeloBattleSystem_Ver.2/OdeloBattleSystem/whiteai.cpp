//#include "OdeloBattleSystem.h"
//#include <stdio.h>
//
//typedef struct dostone2{
//	int x;
//	int y;
//	int score;
//	int reversenum;
//};
//
//int board2_2010182012[8][8];
//dostone2 stoneP2_2010182012[8][8];
//dostone2 temp2_2010182012;
//int howmany_2010182012;
//
//
//BOOL isfirst2_2010182012 = false;
//int canStone2_2010182012(int , int );
//void reversestoneB2_2010182012(int, int);
//void reversestoneW2_2010182012(int , int);
//
//// 0 ºóÄ­, 1 Èæµ¹, 2 ¹éµ¹
//
//void WhiteAttack_2010182012( int *x, int *y )
//{
//
//	for(int i = 0; i<8; ++i){
//		printf("%d\n",  canStone2_2010182012(4, 0) );
//		for(int j = 0; j<8; ++j){
//			
//			if(canStone2_2010182012(i, j ) == 1){
//				if((i == 0 && j == 0) || (i == 0 && j ==7) || (i == 7 && j ==0) || (i == 7 && j ==7)){
//					stoneP2_2010182012[i][j].score = 150;
//					stoneP2_2010182012[i][j].x = j;
//					stoneP2_2010182012[i][j].y = i;
//					stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
//				}
//
//				else if(((i == 0 || i == 7) && (1<=j && j<=6))||((j == 0 || j == 7) && (1<=i && i<=6))){
//					stoneP2_2010182012[i][j].score = 100;
//					stoneP2_2010182012[i][j].x = j;
//					stoneP2_2010182012[i][j].y = i;
//					stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
//					if((i==0 && (j== 1 || j == 6)) || (i== 1 &&( j==0 || j ==7)) || (i==7 && (j== 1 || j == 6)) || (i== 6 &&( j==0 || j ==7))){
//						stoneP2_2010182012[i][j].score = 60;
//						stoneP2_2010182012[i][j].x = j;
//						stoneP2_2010182012[i][j].y = i;
//						stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
//					}
//				}
//				else if( (2<=i && i<= 5) && (2<=j && j<= 5) ){
//					stoneP2_2010182012[i][j].score = 50;
//					stoneP2_2010182012[i][j].x = j;
//					stoneP2_2010182012[i][j].y = i;
//					stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
//					if( (i == 2 && i == 2) || (i == 2 && j == 5) || ( i == 5 && j == 2 ) || ( i == 5 && j == 5) ){
//						stoneP2_2010182012[i][j].score = 70;
//						stoneP2_2010182012[i][j].x = j;
//						stoneP2_2010182012[i][j].y = i;
//						stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
//					}
//				}
//				else if( (i == 1 && j == 1) || (i == 1 && j == 6) || (i == 6 && j == 1) || (i == 6 && j == 6) ){
//					stoneP2_2010182012[i][j].score = 1;
//					stoneP2_2010182012[i][j].x = j;
//					stoneP2_2010182012[i][j].y = i;
//					stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
//				}
//				else {
//					stoneP2_2010182012[i][j].score = 30;
//					stoneP2_2010182012[i][j].x = j;
//					stoneP2_2010182012[i][j].y = i;
//					stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
//					if((i==1 && (j== 2 || j == 5)) || (i== 2 &&( j==1 || j ==6)) || (i==5 && (j== 1 || j == 6)) || (i== 6 &&( j==2 || j ==5))){
//						stoneP2_2010182012[i][j].score = 40;
//						stoneP2_2010182012[i][j].x = j;
//						stoneP2_2010182012[i][j].y = i;
//						stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
//					}
//				}
//			}
//		}
//	}
//
//	howmany_2010182012 = 0;
//
//	temp2_2010182012.score = 0;
//	
//
//	for(int i = 0; i<8; ++i){
//		for(int j = 0; j<8; ++j){
//			if(temp2_2010182012.score <= stoneP2_2010182012[i][j].score){
//				temp2_2010182012.score = stoneP2_2010182012[i][j].score;
//				temp2_2010182012.x = stoneP2_2010182012[i][j].x;
//				temp2_2010182012.y = stoneP2_2010182012[i][j].y;
//			}
//			//else if(temp2_2010182012.score == stoneP2_2010182012[i][j].score){
//			//	if(temp2_2010182012.reversenum <= stoneP2_2010182012[i][j].reversenum){
//			//		temp2_2010182012.reversenum = stoneP2_2010182012[i][j].reversenum;
//			//		temp2_2010182012.x = stoneP2_2010182012[i][j].x;
//			//	    temp2_2010182012.y = stoneP2_2010182012[i][j].y;
//			//	}
//			//	else if(temp2_2010182012.reversenum > stoneP2_2010182012[i][j].reversenum){
//			//		//temp2_2010182012.x = temp2_2010182012.x;
//			//		//temp2_2010182012.y = temp2_2010182012.y;
//			//	}
//			//	
//			//}
//		}
//	}
//
//	printf( " %d, %d\n", temp2_2010182012.x,temp2_2010182012.y );
//
//	*x = temp2_2010182012.x;
//	*y = temp2_2010182012.y;
//
//	for(int i = 0; i<8; ++i){
//		for(int j = 0; j<8; ++j){
//			stoneP2_2010182012[i][j].score = 0;
//			stoneP2_2010182012[i][j].x = 0;
//			stoneP2_2010182012[i][j].y = 0;
//			
//		}
//	}
//	board2_2010182012[temp2_2010182012.y][temp2_2010182012.x] = 2;
//	reversestoneW2_2010182012(temp2_2010182012.y,temp2_2010182012.x );
//	temp2_2010182012.reversenum = 0;
//	temp2_2010182012.score = 0;
//	temp2_2010182012.x = 0;
//	temp2_2010182012.y = 0;
//
//	for(int i = 0; i<8; ++i){
//		for(int j = 0; j<8; ++j){
//			printf( "%d ", board2_2010182012[i][j] );
//		}
//		printf("\n");
//	}
//}
//
//void WhiteDefence_2010182012( int x, int y ){
//	if(!(isfirst2_2010182012)){
//		for(int i = 0; i<8; ++i){
//			for(int j = 0; j<8; ++j){
//				board2_2010182012[i][j] = 0;
//			}
//		}
//		board2_2010182012[3][3] = 1;
//		board2_2010182012[4][4] = 1;
//		board2_2010182012[3][4] = 2;
//		board2_2010182012[4][3] = 2;
//
//		isfirst2_2010182012 = true;
//	}
//	board2_2010182012[y][x] = 1;
//	reversestoneB2_2010182012(y, x);
//}
//
//int canStone2_2010182012(int y, int x){
//    if(board2_2010182012[y][x] == 0){
//        for(int k=-1; k<=1; ++k){
//            for(int l=-1;l<=1; ++l){
//                if(board2_2010182012[y+k][x+l]== 1){
//                    int sigx = x+l;
//                    int sigy = y+k;
//                    int n = 0;
//                    while(n<8){
//						if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
//							
//                            break;
//                        }
//                        if(board2_2010182012[sigy][sigx]==2){
//                          return 1;
//                            break;
//                        }
//
//                        else if(board2_2010182012[sigy][sigx]!=1 || board2_2010182012[sigy][sigx]==0){
//							
//                            break;
//							
//                        }
//
//                        else if(n==7){
//							
//                            break;
//
//                        }
//                        sigy+=k;
//                        sigx+=l;
//                        n+=1;
//						howmany_2010182012 = n;
//                    }
//
//
//
//                }
//
//                else if(k==1 && l==1)
//					 return 0;		
//            }
//        }
//	}
//
//    
//}
//
//
//void reversestoneB2_2010182012(int y, int x){
//   
//        for(int k=-1; k<=1; ++k){
//            for(int l=-1;l<=1; ++l){
//                if(board2_2010182012[y+k][x+l]==2){
//                    int sigx = x+l;
//                    int sigy = y+k;
//                    int n = 0;
//                    while(n<7){
//                        if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
//                            break;
//                        }
//                        if(board2_2010182012[sigy][sigx]==1){
//                            while(n>0){
//                                if(sigy == y && sigx == x){
//                                    break;
//                                } 
//                                else if(n==0){
//                                    break;
//                                }
//
//                                board2_2010182012[sigy-k][sigx-l] = 1;
//                                sigy-=k;
//                                sigx-=l;
//                                n-=1;                                                              
//                            }                            
//
//
//                            break;
//                        }
//                        else if(board2_2010182012[sigy][sigx]!=2){
//                            break;
//                        }
//
//                        else if(n==6){
//
//                            break;
//                        }
//
//                        sigy+=k;
//                        sigx+=l;
//                        n+=1;
//                    }
//
//
//
//                }
//
//                else if(k==1 && l==1)
//                    return;			
//            }
//        }
//}
//
//
//void reversestoneW2_2010182012(int y, int x){
//   
//        for(int k=-1; k<=1; ++k){
//            for(int l=-1;l<=1; ++l){
//                if(board2_2010182012[y+k][x+l]==1){
//                    int sigx = x+l;
//                    int sigy = y+k;
//                    int n = 0;
//                    while(n<7){
//                        if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
//                            break;
//                        }
//                        if(board2_2010182012[sigy][sigx]==2){
//                            while(n>0){
//                                if(sigy == y && sigx == x){
//                                    break;
//                                } 
//                                else if(n==0){
//                                    break;
//                                }
//
//                                board2_2010182012[sigy-k][sigx-l] = 2;
//                                sigy-=k;
//                                sigx-=l;
//                                n-=1;                                                              
//                            }                            
//
//
//                            break;
//                        }
//                        else if(board2_2010182012[sigy][sigx]!=1){
//                            break;
//                        }
//
//                        else if(n==6){
//
//                            break;
//                        }
//
//                        sigy+=k;
//                        sigx+=l;
//                        n+=1;
//                    }
//
//
//
//                }
//
//                else if(k==1 && l==1)
//                    return;			
//            }
//        }
//}

#include "OdeloBattleSystem.h"
#include <stdio.h>

typedef struct dostone2{
	int x;
	int y;
	int score;
	int reversenum;
};

int board2_2010182012[8][8];
dostone2 stoneP2_2010182012[8][8];
dostone2 temp2_2010182012;
int howmany_2010182012;
int count2_2010182012 = 0;
int count =12;

BOOL isfirst2_2010182012 = false;
int canStone2_2010182012(int , int );
void reversestoneB2_2010182012(int, int);
void reversestoneW2_2010182012(int , int);

// 0 ºóÄ­, 1 Èæµ¹, 2 ¹éµ¹

void WhiteAttack_2010182012( int *x, int *y )
{

	for(int i = 0; i<8; ++i){
		
		for(int j = 0; j<8; ++j){
			
			if(canStone2_2010182012(i, j ) == 1){
				if((i == 0 && j == 0) || (i == 0 && j ==7) || (i == 7 && j ==0) || (i == 7 && j ==7)){
					stoneP2_2010182012[i][j].score = 150;
					stoneP2_2010182012[i][j].x = j;
					stoneP2_2010182012[i][j].y = i;
					stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
				}

				else if(((i == 0 || i == 7) && (1<=j && j<=6))||((j == 0 || j == 7) && (1<=i && i<=6))){
					stoneP2_2010182012[i][j].score = 95;
					stoneP2_2010182012[i][j].x = j;
					stoneP2_2010182012[i][j].y = i;
					stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
					if((i==0 && (j== 1 || j == 6)) || (i== 1 &&( j==0 || j ==7)) || (i==7 && (j== 1 || j == 6)) || (i== 6 &&( j==0 || j ==7))){
						stoneP2_2010182012[i][j].score = 1;
						stoneP2_2010182012[i][j].x = j;
						stoneP2_2010182012[i][j].y = i;
						stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
						if( board2_2010182012[0][0]!=0 && board2_2010182012[0][7] != 0 && board2_2010182012[7][0] != 0 && board2_2010182012[7][7] != 0){
						stoneP2_2010182012[i][j].score = 150;
					}
					}
				}
				else if( (2<=i && i<= 5) && (2<=j && j<= 5) ){
					stoneP2_2010182012[i][j].score = 50;
					stoneP2_2010182012[i][j].x = j;
					stoneP2_2010182012[i][j].y = i;
					stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
					if(count2_2010182012 <= 6){
						stoneP2_2010182012[i][j].score = 110;
					}
					if( (i == 2 && i == 2) || (i == 2 && j == 5) || ( i == 5 && j == 2 ) || ( i == 5 && j == 5) ){
						stoneP2_2010182012[i][j].score = 70;
						stoneP2_2010182012[i][j].x = j;
						stoneP2_2010182012[i][j].y = i;
						stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
						if(count2_2010182012 <= 6){
							stoneP2_2010182012[i][j].score = 120;
						}
					}
				}
				else if( (i == 1 && j == 1) || (i == 1 && j == 6) || (i == 6 && j == 1) || (i == 6 && j == 6) ){
					stoneP2_2010182012[i][j].score = 1;
					stoneP2_2010182012[i][j].x = j;
					stoneP2_2010182012[i][j].y = i;
					stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
				}
				else {
					stoneP2_2010182012[i][j].score = 30;
					stoneP2_2010182012[i][j].x = j;
					stoneP2_2010182012[i][j].y = i;
					stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
					if((i==1 && (j== 2 || j == 5)) || (i== 2 &&( j==1 || j ==6)) || (i==5 && (j== 1 || j == 6)) || (i== 6 &&( j==2 || j ==5))){
						stoneP2_2010182012[i][j].score = 30;
						stoneP2_2010182012[i][j].x = j;
						stoneP2_2010182012[i][j].y = i;
						stoneP2_2010182012[i][j].reversenum = howmany_2010182012-1;
					}
				}
			}
		}
	}

	howmany_2010182012 = 0;
	if(count2_2010182012 <= count){
		temp2_2010182012.reversenum = 100;
	}
	else if(count2_2010182012 > count){
		temp2_2010182012.reversenum = 0;
	}

	temp2_2010182012.score = 0;


	for(int i = 0; i<8; ++i){
		for(int j = 0; j<8; ++j){
			if(temp2_2010182012.score <stoneP2_2010182012[i][j].score){
				temp2_2010182012.score = stoneP2_2010182012[i][j].score;
				temp2_2010182012.x = stoneP2_2010182012[i][j].x;
				temp2_2010182012.y = stoneP2_2010182012[i][j].y;
			}
			else if(temp2_2010182012.score == stoneP2_2010182012[i][j].score){
				if(count2_2010182012 <= count){
					if(temp2_2010182012.reversenum > stoneP2_2010182012[i][j].reversenum){
						temp2_2010182012.reversenum = stoneP2_2010182012[i][j].reversenum;
						temp2_2010182012.x = stoneP2_2010182012[i][j].x;
						temp2_2010182012.y = stoneP2_2010182012[i][j].y;
					}
					else if(temp2_2010182012.reversenum < stoneP2_2010182012[i][j].reversenum){
						temp2_2010182012.reversenum = temp2_2010182012.reversenum;
						temp2_2010182012.x = temp2_2010182012.x;
						temp2_2010182012.y = temp2_2010182012.y;
					}
					else if(temp2_2010182012.reversenum == stoneP2_2010182012[i][j].reversenum){
						temp2_2010182012.reversenum = stoneP2_2010182012[i][j].reversenum;
						temp2_2010182012.x = stoneP2_2010182012[i][j].x;
						temp2_2010182012.y = stoneP2_2010182012[i][j].y;
					}

				}
				else if(count2_2010182012 > count){
					if(temp2_2010182012.reversenum < stoneP2_2010182012[i][j].reversenum){
						temp2_2010182012.reversenum = stoneP2_2010182012[i][j].reversenum;
						temp2_2010182012.x = stoneP2_2010182012[i][j].x;
						temp2_2010182012.y = stoneP2_2010182012[i][j].y;
					}
					else if(temp2_2010182012.reversenum > stoneP2_2010182012[i][j].reversenum){
						temp2_2010182012.reversenum = temp2_2010182012.reversenum;
						temp2_2010182012.x = temp2_2010182012.x;
						temp2_2010182012.y = temp2_2010182012.y;
					}
					else if(temp2_2010182012.reversenum == stoneP2_2010182012[i][j].reversenum){
						temp2_2010182012.reversenum = stoneP2_2010182012[i][j].reversenum;
						temp2_2010182012.x = stoneP2_2010182012[i][j].x;
						temp2_2010182012.y = stoneP2_2010182012[i][j].y;
					}
				}
			}
		}
	}

	printf( " %d, %d\n", temp2_2010182012.x,temp2_2010182012.y );

	
	if(temp2_2010182012.score != 0){
		*x = temp2_2010182012.x;
		*y = temp2_2010182012.y;
		++count2_2010182012;
	}

	for(int i = 0; i<8; ++i){
		for(int j = 0; j<8; ++j){
			stoneP2_2010182012[i][j].score = 0;
			stoneP2_2010182012[i][j].x = 0;
			stoneP2_2010182012[i][j].y = 0;
			stoneP2_2010182012[i][j].reversenum = 0;
			
		}
	}
	board2_2010182012[temp2_2010182012.y][temp2_2010182012.x] = 2;
	reversestoneW2_2010182012(temp2_2010182012.y,temp2_2010182012.x );
	temp2_2010182012.score = 0;
	if(count2_2010182012 <= count){
		temp2_2010182012.reversenum = 100;
	}
	else if(count2_2010182012 > count){
		temp2_2010182012.reversenum = 0;
	}
	temp2_2010182012.x = 0;
	temp2_2010182012.y = 0;

	/*for(int i = 0; i<8; ++i){
		for(int j = 0; j<8; ++j){
			printf( "%d ", board2_2010182012[i][j] );
		}
		printf("\n");
	}*/
	//++count2_2010182012;
}

void WhiteDefence_2010182012( int x, int y ){
	if(!(isfirst2_2010182012)){
		for(int i = 0; i<8; ++i){
			for(int j = 0; j<8; ++j){
				board2_2010182012[i][j] = 0;
			}
		}
		board2_2010182012[3][3] = 1;
		board2_2010182012[4][4] = 1;
		board2_2010182012[3][4] = 2;
		board2_2010182012[4][3] = 2;

		isfirst2_2010182012 = true;
	}
	board2_2010182012[y][x] = 1;
	reversestoneB2_2010182012(y, x);
}

int canStone2_2010182012(int y, int x){
    if(board2_2010182012[y][x] == 0){
        for(int k=-1; k<=1; ++k){
            for(int l=-1;l<=1; ++l){
                if(board2_2010182012[y+k][x+l]== 1){
                    int sigx = x+l;
                    int sigy = y+k;
                    int n = 0;
                    while(n<8){
						if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
							
                            break;
                        }
                        if(board2_2010182012[sigy][sigx]==2){
                          return 1;
                            break;
                        }

                        else if(board2_2010182012[sigy][sigx]!=1 || board2_2010182012[sigy][sigx]==0){
							
                            break;
							
                        }

                        else if(n==7){
							
                            break;

                        }
                        sigy+=k;
                        sigx+=l;
                        n+=1;
						howmany_2010182012 = n;
                    }



                }

                else if(k==1 && l==1)
					 return 0;		
            }
        }
	}

    
}


void reversestoneB2_2010182012(int y, int x){
   
        for(int k=-1; k<=1; ++k){
            for(int l=-1;l<=1; ++l){
                if(board2_2010182012[y+k][x+l]==2){
                    int sigx = x+l;
                    int sigy = y+k;
                    int n = 0;
                    while(n<7){
                        if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
                            break;
                        }
                        if(board2_2010182012[sigy][sigx]==1){
                            while(n>0){
                                if(sigy == y && sigx == x){
                                    break;
                                } 
                                else if(n==0){
                                    break;
                                }

                                board2_2010182012[sigy-k][sigx-l] = 1;
                                sigy-=k;
                                sigx-=l;
                                n-=1;                                                              
                            }                            


                            break;
                        }
                        else if(board2_2010182012[sigy][sigx]!=2){
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


void reversestoneW2_2010182012(int y, int x){
   
        for(int k=-1; k<=1; ++k){
            for(int l=-1;l<=1; ++l){
                if(board2_2010182012[y+k][x+l]==1){
                    int sigx = x+l;
                    int sigy = y+k;
                    int n = 0;
                    while(n<7){
                        if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
                            break;
                        }
                        if(board2_2010182012[sigy][sigx]==2){
                            while(n>0){
                                if(sigy == y && sigx == x){
                                    break;
                                } 
                                else if(n==0){
                                    break;
                                }

                                board2_2010182012[sigy-k][sigx-l] = 2;
                                sigy-=k;
                                sigx-=l;
                                n-=1;                                                              
                            }                            


                            break;
                        }
                        else if(board2_2010182012[sigy][sigx]!=1){
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
