void bubbleSort(int numbers[], int array_size)
{
  int i, j, temp;
  int ctr = 0;
  for (i = (array_size - 1); i >= 0; i--)
  {
    ctr++;
    for (j = 1; j <= i; j++)
    {
      ctr++;
      if (numbers[j - 1] > numbers[j])
      {
        ctr++;
        temp = numbers[j - 1];
        numbers[j - 1] = numbers[j];
        numbers[j] = temp;
      }
    }
  }
}
