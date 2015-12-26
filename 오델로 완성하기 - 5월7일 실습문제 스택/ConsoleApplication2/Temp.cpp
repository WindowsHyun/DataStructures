for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){
			// (-1,-1) ~ (1,1) 검사하는 for문 [ 검정색을 기준으로 시작 ]
			// 내 돌이 현재 있는 위치를 (tempX-1, tempY-1) 로 설정
			if(arr[tempY-1+k][tempX-1+l] != None && arr[tempY-1+k][tempX-1+l] != Hint){ 
				// └ 내돌이 놓여있는 위치에서 +k , +l 한 위치에 돌이 아무것도 없지 않고, 힌트를 주는 돌이 아닐경우

					if( arr[tempY-1+k][tempX-1+l] == White){ // 내 돌이 놓여있는 위치에서 +k, +l 한 위치에 흰색의 돌이 있을경우
						int tXt=tempX-1+l, tYt=tempY-1+k; // txt, tyt 로 각가의 지역변수에 저장한다.
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){ // 해당 범위 안에 있을때까지 계속 돌아간다
							if(arr[tYt][tXt]!=White || arr[tYt][tXt]==Hint)
								// └ 연달아 체크하는데 흰색이 아닌 다른색이나 힌트가 나오면 의미가없는거니깐 Break;
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(arr[tYt][tXt]==None || arr[tYt][tXt]==Hint)
								// └ 해당값이 빈칸이거나 힌트일 경우 해당 구문을 띄어넘는다. [ 돌 색깔을 변경하는것 ]
								continue;

							tXt-=l; tYt-=k;
							// └ ●○○○● 검은색까지 체크를 한거니깐, 검은색은 바꿀필요 없으므로 한단계 아래로 바꾼다.
							//  └ 즉 체크를 한 위치는 이미 검은색이니 거기까지 다시 색칠하지 말고 그전까지만 색칠하게 한다.
							while(tXt!=tempX-1||tYt!=tempY-1){ 
								arr[tYt][tXt]=Black; // txt, tyt 위치의 돌을 검정색으로 바꾼다
								tXt-=l;tYt-=k; // 체크한 위치만큼 다시 내려오게 하는부분
								isSetBlockTF = 1; // void 함수로 선언을 하여서 체크가 끝난지 확인이 안되니, 전역변수로 선언 해당 1이 되면 끝난걸로 간주하는 부분
								isClearTempBW(); // 힌트를 줬던 위치를 초기화 해주는데 사용 되는 부분 
							} // while(tXt!=tempX-1||tYt!=tempY-1){
						} // if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
					} // if( arr[tempY-1+k][tempX-1+l] == White){
			} // if(arr[tempY-1+k][tempX-1+l] != None && arr[isTempRy+k][isTempRx+l] != Hint){
		} // for(int l=-1;l<=1; ++l){
} // for(int k=-1; k<=1; ++k){