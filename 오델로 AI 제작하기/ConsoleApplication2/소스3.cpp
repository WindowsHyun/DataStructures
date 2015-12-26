//void isAiWhiteStones(){
//
//	for(int i=0; i<isAiArrangement-1; ++i){
//		for(int j=i+1; j<isAiArrangement; ++j){
//
//			if( isAiCount[i] < isAiCount[j] ){
//				ismovetemp[0]=isAiCount[i];
//				ismovetemp[1]=isAIx[i];
//				ismovetemp[2]=isAIy[i];
//
//				isAiCount[i] = isAiCount[j];
//				isAIx[i] = isAIx[j];
//				isAIy[i] = isAIy[j];
//
//				isAiCount[j] = ismovetemp[0];
//				isAIx[j] = ismovetemp[1];
//				isAIy[j] = ismovetemp[2];
//			} // if( isAiCount[i] < isAiCount[j] ){
//		} // for(int j=i+1; j<isAiArrangement; ++j){
//
//		// 각 모서리가 있을경우 우선시 한다.
//		if(isAIx[i] == 0 && isAIy[i] == 0 && isAiCount[i] != 0){
//			isAIx[0] = 0, isAIy[0] =0;
//			break;
//		}else if(isAIx[i] == 7 && isAIy[i] == 0){
//			isAIx[0] = 7, isAIy[0] =0;
//			break;
//		}else if(isAIx[i] == 7 && isAIy[i] == 7){
//			isAIx[0] = 7, isAIy[0] =7;
//			break;
//		}else if(isAIx[i] == 0 && isAIy[i] == 7){
//			isAIx[0] = 0, isAIy[0] =7;
//			break;
//		} 
//
//
//		// 각 가장자리가 있을경우 우선시 한다.
//		/*	if( isAIy[i] == 0 && isAiCount[i] != 0){
//		isAIx[0] = isAIx[i], isAIy[0] =0;
//		break;
//		}else if( isAIy[i] == 7 && isAiCount[i] != 0){
//		isAIx[0] = isAIx[i], isAIy[0] =7;
//		break;
//		}else if( isAIx[i] == 0 && isAiCount[i] != 0){
//		isAIy[0] = isAIy[i], isAIx[0] =0;
//		break;
//		}else if( isAIx[i] == 7 && isAiCount[i] != 0){
//		isAIy[0] = isAIy[i], isAIx[0] =7;
//		break;
//		}*/
//
//
//	} // for(int i=0; i<isAiArrangement-1; ++i){
//
//	if(isAIx[0] == 1 && isAIy[0] == 1){
//		isAIx[0] = isAIx[1], isAIy[0] =isAIy[1];
//	}else if(isAIx[0] == 6 && isAIy[0] == 6){
//		isAIx[0] = isAIx[1], isAIy[0] =isAIy[1];					 
//	}else if(isAIx[0] == 1 && isAIy[0] == 6){
//		isAIx[0] = isAIx[1], isAIy[0] =isAIy[1];				 
//	}else if(isAIx[0] == 6 && isAIy[0] == 1){
//		isAIx[0] = isAIx[1], isAIy[0] =isAIy[1];	
//	}
//
//	srand(time(NULL));
//	if(isAIx[0] == isAIx[1] && isAiCount[0] != 0 && isAiCount[1] != 0){
//		int isRandData = rand()%1+1;
//		tempX = isAIx[isRandData]+1, tempY = isAIy[isRandData]+1;
//	}else{
//		tempX = isAIx[0]+1, tempY = isAIy[0]+1;
//	}
//	isAddStones();
//}
