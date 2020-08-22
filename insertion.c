int insertionSort(int numbers[], int array_size){
  int i, j, index;
  
  long int cnt = 0;
  
  for (i = 1; i < array_size; i++){
    index = numbers[i];
    j = i;
    while ((j > 0) && (numbers[j - 1] > index)){
      cnt++;	
      numbers[j] = numbers[j - 1];
      j = j - 1;
    }
    numbers[j] = index;
  }
  
//  printf("Insertion Count: %ld\n", cnt);
  return cnt;
}
