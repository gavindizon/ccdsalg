

void siftDown(int numbers[], int root, int bottom, long int * cnt){
  int done, maxChild, temp;
	
  done = 0;
  while ((root*2 <= bottom) && (!done)){
    (*cnt)++;
	if (root*2 == bottom){
      maxChild = root * 2;
	}
    else if (numbers[root * 2] > numbers[root * 2 + 1]){
      maxChild = root * 2;    	
	}
    else{
      maxChild = root * 2 + 1;    	
	}
	
    if (numbers[root] < numbers[maxChild]){
      temp = numbers[root];
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
 
    }
    else{
      done = 1;
	}
  }
}

int heapSort(int numbers[], int array_size){
  int i, temp;
  long int cnt = 0;

  for (i = (array_size / 2)-1; i >= 0; i--){
    siftDown(numbers, i, array_size, &cnt);
  	
  }

  for (i = array_size-1; i >= 1; i--){
    temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i-1, &cnt);
  }
  
  printf("Heap Count: %ld\n", cnt);
	return cnt;
}

