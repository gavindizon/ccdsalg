unsigned long long bubbleSort(int numbers[], int array_size)
{
  int i, j, temp;
  unsigned long long int ctr = 0;
  for (i = (array_size - 1); i >= 0; i--)
  {
    for (j = 1; j <= i; j++) // i = 5;  
    {
      ctr++;
      if (numbers[j - 1] > numbers[j])
      {
        temp = numbers[j - 1];
        numbers[j - 1] = numbers[j];
        numbers[j] = temp;
      }
    }
  }
  return ctr;
}
