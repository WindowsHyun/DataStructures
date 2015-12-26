void SortNode(void)
{
    Node *current, **ptr;
    int i, j,cnt; 
    
    if(gp_head == NULL){
        printf("데이타가 없습니다.\n");
        return;
    }
    
    current = gp_head, cnt = 1;
    while(current->p_next != NULL){
        cnt++;
        current = current->p_next;
    }
    
    ptr = (Node**)malloc(sizeof(Node*) * cnt);
    for(i = 0, current = gp_head; i < cnt; i++, current = current->p_next) {
		ptr[i] = current;
	}

    for(i = 0; i < cnt; i++){
        for(j = i+1; j < cnt; j++){
            if(strcmp(ptr[i]->data_sting , ptr[j]->data_sting) > 0){
                current = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = current;
            }
        }
    }
    
    for(gp_head = ptr[0], current = gp_head, i = 1; i < cnt; i++, current = current->p_next){
        current->p_next = ptr[i];
    }
    current->p_next = NULL;
    printf("정렬이 완료되었습니다.\n");
    free(ptr);
}