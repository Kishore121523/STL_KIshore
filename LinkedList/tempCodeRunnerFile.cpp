  while(temp){
    if(temp->next == nullptr){
      temp->next = newLast;
    }
    temp=temp->next;
  }