#include "GL_variable_2012181017.h"


int	board_2012181017[B_SIZE_2012181017][B_SIZE_2012181017] = {	{NONE_STONE_2012181017},
																{NONE_STONE_2012181017},
																{NONE_STONE_2012181017},
																{0, 0, 0, BLACK_STONE_2012181017, WHITE_STONE_2012181017, 0, 0, 0},
																{0, 0, 0, WHITE_STONE_2012181017, BLACK_STONE_2012181017, 0, 0, 0},
																{NONE_STONE_2012181017},
																{NONE_STONE_2012181017},
																{NONE_STONE_2012181017}};

STONE_2012181017 checkPen_2012181017 = {0};

B_UNIT_2012181017*	head_2012181017 = createHeadSL_2012181017();

int	boardWeight_2012181017[B_SIZE_2012181017][B_SIZE_2012181017] = {	{15, -7, 10, 10, 10, 10, -7, 15},
																		{-7, -7, -4, -4, -4, -4, -7, -7},
																		{10, -4, 10, 5, 5, 10, -4, 10},
																		{10, -4, 5, 0, 0, 5, -4, 10},
																		{10, -4, 5, 0, 0, 5, -4, 10},
																		{10, -4, 10, 5, 5, 10, -4, 10},
																		{-7, -7, -4, -4, -4, -4, -7, -7},
																		{15, -7, 10, 10, 10, 10, -7, 15}};


//----------------------제일 큰 수를 찾아서 둔다
void checkMaxTurnStone_2012181017(int userStone, int* resultX, int* resultY){
	static	int	turnCount = 0;
	int maxTurn = 0;
	int minTurn = 0xfffffff;
	STONE_2012181017 result;

	int x, y;
	if(BLACK_STONE_2012181017 == userStone){
		for(int tmpI=0; tmpI<B_SIZE_2012181017; ++tmpI){
			for(int tmpJ = 0; tmpJ<B_SIZE_2012181017; ++tmpJ){
				for(int i=-1; i<2; ++i){
					for(int j=-1; j<2; ++j){
						x = tmpJ + j;
						y = tmpI + i;
						int tmpMax = 0;

						if(board_2012181017[tmpI][tmpJ] == NONE_STONE_2012181017){
							while((board_2012181017[y][x] != userStone && board_2012181017[y][x] != NONE_STONE_2012181017)&& (0<=x && x<B_SIZE_2012181017) && (0<=y && y<B_SIZE_2012181017)){
								x += j;
								y += i;
								tmpMax++;
							}

							if(board_2012181017[y][x] == userStone){
								if(turnCount < BLACK_TURN_MIN_2012181017){
									if(tmpMax != 0 && tmpMax < minTurn){
										minTurn = tmpMax;
										result.x = tmpJ;
										result.y = tmpI;
										result.checkFlag = true;
									}
								}else{
									if(maxTurn < tmpMax){
										maxTurn = tmpMax;
										result.x = tmpJ;
										result.y = tmpI;
										result.checkFlag = true;
									}
								}
							}
						}else{
							i = 3;
							j = 3;
						}
					}
				}
			}
		}
	}else if(userStone == WHITE_STONE_2012181017){
		for(int tmpI=0; tmpI<B_SIZE_2012181017; ++tmpI){
			for(int tmpJ = B_SIZE_2012181017-1; 0 <= tmpJ; --tmpJ){
				for(int i=-1; i<2; ++i){
					for(int j=-1; j<2; ++j){
						x = tmpJ + j;
						y = tmpI + i;
						int tmpMax = 0;

						if(board_2012181017[tmpI][tmpJ] == NONE_STONE_2012181017){
							while((board_2012181017[y][x] != userStone && board_2012181017[y][x] != NONE_STONE_2012181017)&& (0<=x && x<B_SIZE_2012181017) && (0<=y && y<B_SIZE_2012181017)){
								x += j;
								y += i;
								tmpMax++;
							}

							if(board_2012181017[y][x] == userStone){
								if(turnCount < WHITE_TURN_MIN_2012181017){
									if(tmpMax != 0 && tmpMax < minTurn){
										minTurn = tmpMax;
										result.x = tmpJ;
										result.y = tmpI;
										result.checkFlag = true;
									}
								}else{
									if(maxTurn < tmpMax){
										maxTurn = tmpMax;
										result.x = tmpJ;
										result.y = tmpI;
										result.checkFlag = true;
									}
								}
							}
						}else{
							i = 3;
							j = 3;
						}
					}
				}
			}
		}
	}

	turnCount++;



	if(result.checkFlag){
		*resultX = result.x;
		*resultY = result.y;
	}else{
		*resultX = -1;
		*resultY = -1;
	}
}

//----------------------돌 뒤집기
void	changeStone_2012181017(int x, int y, int userStone){
	int tmpX = x, tmpY = y;
	if(board_2012181017[y][x] == NONE_STONE_2012181017){

		for(int i=-1; i<2; ++i){
			for(int j=-1; j<2; ++j){
				board_2012181017[y][x] = userStone;
				changeStone_2012181017(x+j, y+i, userStone, j, i);
			}
		}
	}



	/*for(int i=0; i<B_SIZE_2012181017; ++i){
		for(int j=0; j<B_SIZE_2012181017; ++j){
			if(NONE_STONE_2012181017 == board_2012181017[i][j]){
				printf("▣");
			}else if(BLACK_STONE_2012181017 == board_2012181017[i][j]){
				printf("○");
			}else{
				printf("●");
			}
		}
		printf("\n");
	}*/
}

bool	changeStone_2012181017(int x, int y, int userStone, int tX, int tY){
	if(x < 0 || B_SIZE_2012181017 == x || y < 0 || B_SIZE_2012181017 == y)
		return false;
	if(board_2012181017[y][x] == userStone){
		return true;
	}else if(board_2012181017[y][x] == userStone%2+1){
		if(changeStone_2012181017(x+tX, y+tY, userStone, tX, tY)){
			board_2012181017[y][x] = userStone;
			return true;
		}
	}else{
		return false;
	}

	return false;
}

int		maxTurn_2012181017(int userStone, int x, int y){
	int maxCount = 0;
	int tmpX, tmpY;
	int tmpCount = 0;
	for(int i=-1; i<2; ++i){
		for(int j=-1; j<2; ++j){
			tmpCount = 0;
			tmpX = x+j;
			tmpY = y+i;
			if(board_2012181017[tmpY][tmpX] == userStone%2+1){
				while(board_2012181017[tmpY][tmpX] == userStone%2+1 && (0 < tmpX && tmpX < B_SIZE_2012181017) && ( 0 < tmpY && tmpY < B_SIZE_2012181017)){
					tmpX += j;
					tmpY += i;
					tmpCount++;
					
				}
				/*if(board_2012181017[tmpY][tmpY] != userStone){
					tmpCount = 0;
				}*/
				maxCount += tmpCount;
			}
		}
	}
	return maxCount;
}

//-------------------------리스트
int	insertCount_2012181017 = 0;
B_UNIT_2012181017*	createHeadSL_2012181017(){
	B_UNIT_2012181017*	head = (B_UNIT_2012181017*)malloc(sizeof(B_UNIT_2012181017));
	head->link = NULL;
	return head;
}

void	insertSL_2012181017(B_UNIT_2012181017*	head, B_UNIT_2012181017* unit){
	unit->link = head->link;
	head->link = unit;
	insertCount_2012181017++;
}

void	putStone_2012181017(int userStone, int* resultX, int* resultY){
	

	/*for(int i=0; i<B_SIZE_2012181017; ++i){
		for(int j=0; j<B_SIZE_2012181017; ++j){
			printf("%3d ",boardWeight_2012181017[i][j]);
		}
		printf("\n");
	}*/

	srand((unsigned)time(NULL));
	int tmpNum = rand()%10;

	B_UNIT_2012181017*	p = head_2012181017->link;

	int weightCount = -7;
	int maxCount = 0;
	int tmpCount = 0;

	if(p == NULL){
		*resultX = -1;
		*resultY = -1;
		return;
	}
	for(; p!= NULL;){
		//printf("%d,%d \n",p->stone.x, p->stone.y);
		if(board_2012181017[p->stone.y][p->stone.x] == NONE_STONE_2012181017){
			tmpCount = maxTurn_2012181017(userStone, p->stone.x, p->stone.y);
			if(weightCount+maxCount <= boardWeight_2012181017[p->stone.y][p->stone.x]+tmpCount){
				*resultX = p->stone.x;
				*resultY = p->stone.y;
				weightCount = boardWeight_2012181017[p->stone.y][p->stone.x];
				maxCount = tmpCount;
			}else if(weightCount == boardWeight_2012181017[p->stone.y][p->stone.x]){
				if(maxCount <= tmpCount){
					*resultX = p->stone.x;
					*resultY = p->stone.y;
					weightCount = boardWeight_2012181017[p->stone.y][p->stone.x];
					maxCount = tmpCount;
				}
			}
		}
		p = p->link;
	}
	return;
}

void	clearSL_2012181017(){
	B_UNIT_2012181017*	tmp = head_2012181017->link;
	for( ; head_2012181017->link != NULL ; ){
		tmp = head_2012181017->link;
		head_2012181017->link = tmp->link;
		free(tmp);
	}

	insertCount_2012181017 = 0;
}

void	checkPutStone_2012181017(int userStone, int x, int y){
	int u = userStone%2+1;
	B_UNIT_2012181017*	unit = (B_UNIT_2012181017*)malloc(sizeof(B_UNIT_2012181017));
	insertCount_2012181017 = 0;
	for(int i=0; i<B_SIZE_2012181017; ++i){
		for(int j=0; j<B_SIZE_2012181017; ++j){
			unit->stone.x = j;
			unit->stone.y = i;
			if(board_2012181017[i][j] == NONE_STONE_2012181017 && checkStone_2012181017(*unit, userStone)){
				unit->stone.x = j;
				unit->stone.y = i;
				insertSL_2012181017(head_2012181017, unit);
				unit = (B_UNIT_2012181017*)malloc(sizeof(B_UNIT_2012181017));
			}
		}
	}
}

bool	checkStone_2012181017(B_UNIT_2012181017 unit, int userStone){
	bool	result = false;

	int x, y;
	for(int i=-1; i<2; ++i){
		for(int j=-1; j<2; ++j){
			x = unit.stone.x + j;
			y = unit.stone.y + i;
			if(board_2012181017[y][x] == userStone%2+1){
				while(board_2012181017[y][x] == userStone%2+1 && (0<=x && x<B_SIZE_2012181017) && (0<=y && y<B_SIZE_2012181017)){
					x += j;
					y += i;
				}
				if(board_2012181017[y][x] == userStone && (0<=x && x<B_SIZE_2012181017) && (0<=y && y<B_SIZE_2012181017)){
					return true;
				}
			}
		}
	}
	return result;
}

void	checkTurnStone_2012181017(int userStone, int* resultX, int* resultY){
	static	int		tCount = 0;
	checkPutStone_2012181017(userStone, *resultX, *resultY);
	//if(tCount < 26){
		if(insertCount_2012181017 == 0 && tCount == 0){
			checkMaxTurnStone_2012181017(userStone, resultX, resultY);
		}else if(insertCount_2012181017 == 0 && tCount){
			printf("?");
			*resultX = -1;
			*resultY = -1;
		}else{
			putStone_2012181017(userStone, resultX, resultY);
		}
	/*}else{
		checkMaxTurnStone_2012181017(userStone, resultX, resultY);
	}*/
	tCount++;
}

void	changeStoneSL_2012181017(int x, int y, int userStone){
	changeStone_2012181017(x, y, userStone);
	clearSL_2012181017();
	//checkPutStone_2012181017(userStone, x, y);
}