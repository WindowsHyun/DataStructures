for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){
			// (-1,-1) ~ (1,1) �˻��ϴ� for�� [ �������� �������� ���� ]
			// �� ���� ���� �ִ� ��ġ�� (tempX-1, tempY-1) �� ����
			if(arr[tempY-1+k][tempX-1+l] != None && arr[tempY-1+k][tempX-1+l] != Hint){ 
				// �� ������ �����ִ� ��ġ���� +k , +l �� ��ġ�� ���� �ƹ��͵� ���� �ʰ�, ��Ʈ�� �ִ� ���� �ƴҰ��

					if( arr[tempY-1+k][tempX-1+l] == White){ // �� ���� �����ִ� ��ġ���� +k, +l �� ��ġ�� ����� ���� �������
						int tXt=tempX-1+l, tYt=tempY-1+k; // txt, tyt �� ������ ���������� �����Ѵ�.
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){ // �ش� ���� �ȿ� ���������� ��� ���ư���
							if(arr[tYt][tXt]!=White || arr[tYt][tXt]==Hint)
								// �� ���޾� üũ�ϴµ� ����� �ƴ� �ٸ����̳� ��Ʈ�� ������ �ǹ̰����°Ŵϱ� Break;
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(arr[tYt][tXt]==None || arr[tYt][tXt]==Hint)
								// �� �ش簪�� ��ĭ�̰ų� ��Ʈ�� ��� �ش� ������ ���Ѵ´�. [ �� ������ �����ϴ°� ]
								continue;

							tXt-=l; tYt-=k;
							// �� �ܡۡۡۡ� ���������� üũ�� �ѰŴϱ�, �������� �ٲ��ʿ� �����Ƿ� �Ѵܰ� �Ʒ��� �ٲ۴�.
							//  �� �� üũ�� �� ��ġ�� �̹� �������̴� �ű���� �ٽ� ��ĥ���� ���� ���������� ��ĥ�ϰ� �Ѵ�.
							while(tXt!=tempX-1||tYt!=tempY-1){ 
								arr[tYt][tXt]=Black; // txt, tyt ��ġ�� ���� ���������� �ٲ۴�
								tXt-=l;tYt-=k; // üũ�� ��ġ��ŭ �ٽ� �������� �ϴºκ�
								isSetBlockTF = 1; // void �Լ��� ������ �Ͽ��� üũ�� ������ Ȯ���� �ȵǴ�, ���������� ���� �ش� 1�� �Ǹ� �����ɷ� �����ϴ� �κ�
								isClearTempBW(); // ��Ʈ�� ��� ��ġ�� �ʱ�ȭ ���ִµ� ��� �Ǵ� �κ� 
							} // while(tXt!=tempX-1||tYt!=tempY-1){
						} // if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
					} // if( arr[tempY-1+k][tempX-1+l] == White){
			} // if(arr[tempY-1+k][tempX-1+l] != None && arr[isTempRy+k][isTempRx+l] != Hint){
		} // for(int l=-1;l<=1; ++l){
} // for(int k=-1; k<=1; ++k){