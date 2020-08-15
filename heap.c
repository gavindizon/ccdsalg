void heapSort(int numbers[], int array_size){
  int i, temp, cnt = 0;

  for (i = (array_size / 2)-1; i >= 0; i--){
    siftDown(numbers, i, array_size, &cnt);
  	
  }

  for (i = array_size-1; i >= 1; i--){
    temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i-1, &cnt);
  }
}


void siftDown(int numbers[], int root, int bottom, int * cnt){
  int done, maxChild, temp;
	
	(*cnt)++;
  done = 0;
  while ((root*2 <= bottom) && (!done)){
    (*cnt)++;
	if (root*2 == bottom){
      maxChild = root * 2;
	  *cnt++;		
	}
    else if (numbers[root * 2] > numbers[root * 2 + 1]){
      maxChild = root * 2;    	
	  (*cnt)++;		
	}
    else{
      maxChild = root * 2 + 1;    	
	  (*cnt)++;
	}
	
	(*cnt)++;
    if (numbers[root] < numbers[maxChild]){
      temp = numbers[root];
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
      (*cnt)++;
    }
    else{
      done = 1;
	  (*cnt)++; 	
	}
  }
}
