//#include "OdeloBattleSystem.h"
//#include <stdio.h>
//
//typedef struct dostone{
//	int x;
//	int y;
//	int score;
//	int reversenum;
//};
//
//int board[8][8];
//dostone stoneP[8][8];
//dostone temp;
//int howmany2;
//int count = 0;
//
//
//BOOL isfirst = false;
//int canStone(int , int );
//void reversestoneB(int, int);
//void reversestoneW(int , int);
//
//
//// 0 ºóÄ­, 1 Èæµ¹, 2 ¹éµ¹
//
//void BlackAttack( int *x, int *y )
//{
//	++count;
//	if(!(isfirst)){
//		for(int i = 0; i<8; ++i){
//			for(int j = 0; j<8; ++j){
//				board[i][j] = 0;
//			}
//		}
//		board[3][3] = 1;
//		board[4][4] = 1;
//		board[3][4] = 2;
//		board[4][3] = 2;
//
//		isfirst = true;
//	}
//
//	for(int i = 0; i<8; ++i){
//		for(int j = 0; j<8; ++j){
//			//printf("%d\n",  canStone(3, 3) );
//			if(canStone(i, j ) == 1){
//				if((i == 0 && j == 0) || (i == 0 && j ==7) || (i == 7 && j ==0) || (i == 7 && j ==7)){
//					stoneP[i][j].score = 150;
//					stoneP[i][j].x = j;
//					stoneP[i][j].y = i;
//					stoneP[i][j].reversenum = howmany2-1;
//				}
//
//				else if(((i == 0 || i == 7) && (1<=j && j<=6))||((j == 0 || j == 7) && (1<=i && i<=6))){
//					stoneP[i][j].score = 100;
//					stoneP[i][j].x = j;
//					stoneP[i][j].y = i;
//					stoneP[i][j].reversenum = howmany2-1;
//					if((i==0 && (j== 1 || j == 6)) || (i== 1 &&( j==0 || j ==7)) || (i==7 && (j== 1 || j == 6)) || (i== 6 &&( j==0 || j ==7))){
//						stoneP[i][j].score = 60;
//						stoneP[i][j].x = j;
//						stoneP[i][j].y = i;
//						stoneP[i][j].reversenum = howmany2-1;
//					}
//				}
//				else if( (2<=i && i<= 5) && (2<=j && j<= 5) ){
//					stoneP[i][j].score = 50;
//					stoneP[i][j].x = j;
//					stoneP[i][j].y = i;
//					stoneP[i][j].reversenum = howmany2-1;
//					if( (i == 2 && i == 2) || (i == 2 && j == 5) || ( i == 5 && j == 2 ) || ( i == 5 && j == 5) ){
//						stoneP[i][j].score = 70;
//						stoneP[i][j].x = j;
//						stoneP[i][j].y = i;
//						stoneP[i][j].reversenum = howmany2-1;
//					}
//				}
//				else if( (i == 1 && j == 1) || (i == 1 && j == 6) || (i == 6 && j == 1) || (i == 6 && j == 6) ){
//					stoneP[i][j].score = 1;
//					stoneP[i][j].x = j;
//					stoneP[i][j].y = i;
//					stoneP[i][j].reversenum = howmany2-1;
//				}
//				else {
//					stoneP[i][j].score = 30;
//					stoneP[i][j].x = j;
//					stoneP[i][j].y = i;
//					stoneP[i][j].reversenum = howmany2-1;
//					if((i==1 && (j== 2 || j == 5)) || (i== 2 &&( j==1 || j ==6)) || (i==5 && (j== 1 || j == 6)) || (i== 6 &&( j==2 || j ==5))){
//						stoneP[i][j].score = 40;
//						stoneP[i][j].x = j;
//						stoneP[i][j].y = i;
//						stoneP[i][j].reversenum = howmany2-1;
//					}
//				}
//			}
//		}
//	}
//	howmany2 = 0;
//
//	temp.score = 0;
//
//	for(int i = 0; i<8; ++i){
//		for(int j = 0; j<8; ++j){
//			if(temp.score <= stoneP[i][j].score){
//				temp.score = stoneP[i][j].score;
//				temp.x = stoneP[i][j].x;
//				temp.y = stoneP[i][j].y;
//			}
//			else if(temp.score == stoneP[i][j].score){
//				if(temp.reversenum <= stoneP[i][j].reversenum){
//					temp.reversenum = stoneP[i][j].reversenum;
//					temp.x = stoneP[i][j].x;
//				    temp.y = stoneP[i][j].y;
//				}
//				else if(temp.reversenum > stoneP[i][j].reversenum){
//					//temp2.x = temp2.x;
//					//temp2.y = temp2.y;
//				}
//				
//			}
//		}
//	}
//
//	printf( " %d, %d\n", temp.x,temp.y );
//
//	*x = temp.x;
//	*y = temp.y;
//
//	for(int i = 0; i<8; ++i){
//		for(int j = 0; j<8; ++j){
//			stoneP[i][j].score = 0;
//			stoneP[i][j].x = 0;
//			stoneP[i][j].y = 0;
//			
//		}
//	}
//	board[temp.y][temp.x] = 1;
//	reversestoneB(temp.y,temp.x );
//
//	temp.score = 0;
//	temp.x = 0;
//	temp.y = 0;
//
//	for(int i = 0; i<8; ++i){
//		for(int j = 0; j<8; ++j){
//			printf( "%d ", board[i][j] );
//		}
//		printf("\n");
//	}
//}
//
//void BlackDefence( int x, int y ){
//	board[y][x] = 2;
//	reversestoneW(y, x);
//}
//
//int canStone(int y, int x){
//    if(board[y][x] == 0){
//        for(int k=-1; k<=1; ++k){
//            for(int l=-1;l<=1; ++l){
//                if(board[y+k][x+l]== 2){
//                    int sigx = x+l;
//                    int sigy = y+k;
//                    int n = 0;
//                    while(n<8){
//						if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
//							
//                            break;
//                        }
//                        if(board[sigy][sigx]==1){
//                          return 1;
//                            break;
//                        }
//
//                        else if(board[sigy][sigx]!=2 || board[sigy][sigx]==0){
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
//						howmany2 = n;
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
//void reversestoneB(int y, int x){
//   
//        for(int k=-1; k<=1; ++k){
//            for(int l=-1;l<=1; ++l){
//                if(board[y+k][x+l]==2){
//                    int sigx = x+l;
//                    int sigy = y+k;
//                    int n = 0;
//                    while(n<7){
//                        if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
//                            break;
//                        }
//                        if(board[sigy][sigx]==1){
//                            while(n>0){
//                                if(sigy == y && sigx == x){
//                                    break;
//                                } 
//                                else if(n==0){
//                                    break;
//                                }
//
//                                board[sigy-k][sigx-l] = 1;
//                                sigy-=k;
//                                sigx-=l;
//                                n-=1;                                                              
//                            }                            
//
//
//                            break;
//                        }
//                        else if(board[sigy][sigx]!=2){
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
//void reversestoneW(int y, int x){
//   
//        for(int k=-1; k<=1; ++k){
//            for(int l=-1;l<=1; ++l){
//                if(board[y+k][x+l]==1){
//                    int sigx = x+l;
//                    int sigy = y+k;
//                    int n = 0;
//                    while(n<7){
//                        if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
//                            break;
//                        }
//                        if(board[sigy][sigx]==2){
//                            while(n>0){
//                                if(sigy == y && sigx == x){
//                                    break;
//                                } 
//                                else if(n==0){
//                                    break;
//                                }
//
//                                board[sigy-k][sigx-l] = 2;
//                                sigy-=k;
//                                sigx-=l;
//                                n-=1;                                                              
//                            }                            
//
//
//                            break;
//                        }
//                        else if(board[sigy][sigx]!=1){
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

#include "OdeloBattleSystem.h"
#include <stdio.h>

typedef struct dostone{
	int x;
	int y;
	int score;
	int reversenum;
};

int board[8][8];
dostone stoneP[8][8];
dostone temp;
int howmany2;
int count = 0;


BOOL isfirst = false;
int canStone(int , int );
void reversestoneB(int, int);
void reversestoneW(int , int);


// 0 ºóÄ­, 1 Èæµ¹, 2 ¹éµ¹

void BlackAttack( int *x, int *y )
{
	++count;
	if(!(isfirst)){
		for(int i = 0; i<8; ++i){
			for(int j = 0; j<8; ++j){
				board[i][j] = 0;
			}
		}
		board[3][3] = 1;
		board[4][4] = 1;
		board[3][4] = 2;
		board[4][3] = 2;

		isfirst = true;
	}

	for(int i = 0; i<8; ++i){
		for(int j = 0; j<8; ++j){
			//printf("%d\n",  canStone(3, 3) );
			if(canStone(i, j ) == 1){
				if((i == 0 && j == 0) || (i == 0 && j ==7) || (i == 7 && j ==0) || (i == 7 && j ==7)){
					stoneP[i][j].score = 150;
					stoneP[i][j].x = j;
					stoneP[i][j].y = i;
					stoneP[i][j].reversenum = howmany2-1;
				}

				else if(((i == 0 || i == 7) && (1<=j && j<=6))||((j == 0 || j == 7) && (1<=i && i<=6))){
					stoneP[i][j].score = 80;
					stoneP[i][j].x = j;
					stoneP[i][j].y = i;
					stoneP[i][j].reversenum = howmany2-1;
					if((i==0 && (j== 1 || j == 6)) || (i== 1 &&( j==0 || j ==7)) || (i==7 && (j== 1 || j == 6)) || (i== 6 &&( j==0 || j ==7))){
						stoneP[i][j].score = 60;
						stoneP[i][j].x = j;
						stoneP[i][j].y = i;
						stoneP[i][j].reversenum = howmany2-1;
					}
				}
				else if( (2<=i && i<= 5) && (2<=j && j<= 5) ){
					stoneP[i][j].score = 50;
					stoneP[i][j].x = j;
					stoneP[i][j].y = i;
					stoneP[i][j].reversenum = howmany2-1;
					if(count <= 7){
						stoneP[i][j].score = 110;
					}
					if( (i == 2 && i == 2) || (i == 2 && j == 5) || ( i == 5 && j == 2 ) || ( i == 5 && j == 5) ){
						stoneP[i][j].score = 70;
						stoneP[i][j].x = j;
						stoneP[i][j].y = i;
						stoneP[i][j].reversenum = howmany2-1;
						if(count <= 7){
							stoneP[i][j].score = 120;
						}
					}
				}
				else if( (i == 1 && j == 1) || (i == 1 && j == 6) || (i == 6 && j == 1) || (i == 6 && j == 6) ){
					stoneP[i][j].score = 1;
					stoneP[i][j].x = j;
					stoneP[i][j].y = i;
					stoneP[i][j].reversenum = howmany2-1;
					if( board[0][0]!=0 && board[0][7] != 0 && board[7][0] != 0 && board[7][7] != 0){
						stoneP[i][j].score = 150;
					}
				}
				else {
					stoneP[i][j].score = 90;
					stoneP[i][j].x = j;
					stoneP[i][j].y = i;
					stoneP[i][j].reversenum = howmany2-1;
					if((i==1 && (j== 2 || j == 5)) || (i== 2 &&( j==1 || j ==6)) || (i==5 && (j== 1 || j == 6)) || (i== 6 &&( j==2 || j ==5))){
						stoneP[i][j].score = 100;
						stoneP[i][j].x = j;
						stoneP[i][j].y = i;
						stoneP[i][j].reversenum = howmany2-1;
					}
				}
			}
		}
	}
	howmany2 = 0;

	temp.score = 0;

	for(int i = 0; i<8; ++i){
		for(int j = 0; j<8; ++j){
			if(temp.score <= stoneP[i][j].score){
				temp.score = stoneP[i][j].score;
				temp.x = stoneP[i][j].x;
				temp.y = stoneP[i][j].y;
			}
			//else if(temp.score == stoneP[i][j].score){
			//	if(temp.reversenum <= stoneP[i][j].reversenum){
			//		temp.reversenum = stoneP[i][j].reversenum;
			//		temp.x = stoneP[i][j].x;
			//	    temp.y = stoneP[i][j].y;
			//	}
			//	else if(temp.reversenum > stoneP[i][j].reversenum){
			//		//temp2.x = temp2.x;
			//		//temp2.y = temp2.y;
			//	}
			//	
			//}
		}
	}

	printf( " %d, %d\n", temp.x,temp.y );

	*x = temp.x;
	*y = temp.y;

	for(int i = 0; i<8; ++i){
		for(int j = 0; j<8; ++j){
			stoneP[i][j].score = 0;
			stoneP[i][j].x = 0;
			stoneP[i][j].y = 0;
			
		}
	}
	board[temp.y][temp.x] = 1;
	reversestoneB(temp.y,temp.x );

	temp.score = 0;
	temp.x = 0;
	temp.y = 0;

	for(int i = 0; i<8; ++i){
		for(int j = 0; j<8; ++j){
			printf( "%d ", board[i][j] );
		}
		printf("\n");
	}
}

void BlackDefence( int x, int y ){
	board[y][x] = 2;
	reversestoneW(y, x);
}

int canStone(int y, int x){
    if(board[y][x] == 0){
        for(int k=-1; k<=1; ++k){
            for(int l=-1;l<=1; ++l){
                if(board[y+k][x+l]== 2){
                    int sigx = x+l;
                    int sigy = y+k;
                    int n = 0;
                    while(n<8){
						if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
							
                            break;
                        }
                        if(board[sigy][sigx]==1){
                          return 1;
                            break;
                        }

                        else if(board[sigy][sigx]!=2 || board[sigy][sigx]==0){
							
                            break;
							
                        }

                        else if(n==7){
							
                            break;

                        }
                        sigy+=k;
                        sigx+=l;
                        n+=1;
						howmany2 = n;
                    }



                }

                else if(k==1 && l==1)
					 return 0;		
            }
        }
	}

    
}


void reversestoneB(int y, int x){
   
        for(int k=-1; k<=1; ++k){
            for(int l=-1;l<=1; ++l){
                if(board[y+k][x+l]==2){
                    int sigx = x+l;
                    int sigy = y+k;
                    int n = 0;
                    while(n<7){
                        if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
                            break;
                        }
                        if(board[sigy][sigx]==1){
                            while(n>0){
                                if(sigy == y && sigx == x){
                                    break;
                                } 
                                else if(n==0){
                                    break;
                                }

                                board[sigy-k][sigx-l] = 1;
                                sigy-=k;
                                sigx-=l;
                                n-=1;                                                              
                            }                            


                            break;
                        }
                        else if(board[sigy][sigx]!=2){
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

void reversestoneW(int y, int x){
   
        for(int k=-1; k<=1; ++k){
            for(int l=-1;l<=1; ++l){
                if(board[y+k][x+l]==1){
                    int sigx = x+l;
                    int sigy = y+k;
                    int n = 0;
                    while(n<7){
                        if(sigx <= -1 || sigx >=8 || sigy <= -1 || sigy >=8){
                            break;
                        }
                        if(board[sigy][sigx]==2){
                            while(n>0){
                                if(sigy == y && sigx == x){
                                    break;
                                } 
                                else if(n==0){
                                    break;
                                }

                                board[sigy-k][sigx-l] = 2;
                                sigy-=k;
                                sigx-=l;
                                n-=1;                                                              
                            }                            


                            break;
                        }
                        else if(board[sigy][sigx]!=1){
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

