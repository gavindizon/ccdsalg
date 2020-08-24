void m_sort(int numbers[], int temp[], int left, int right, unsigned long long int *ctr);
void merge(int numbers[], int temp[], int left, int mid, int right,unsigned long long int *ctr);

unsigned long long mergeSort(int numbers[], int temp[], int array_size)
{
      unsigned long long int ctr = 0;
      m_sort(numbers, temp, 0, array_size - 1, &ctr);

      return ctr;
}

void m_sort(int numbers[], int temp[], int left, int right, unsigned long long int *ctr)
{
      int mid;

      if (right > left)
      {
            (*ctr)++;

            mid = (right + left) / 2;
            m_sort(numbers, temp, left, mid, ctr);
            m_sort(numbers, temp, mid + 1, right, ctr);
            merge(numbers, temp, left, mid + 1, right, ctr);
      }
}

void merge(int numbers[], int temp[], int left, int mid, int right, unsigned long long int *ctr)
{

      int i, left_end, num_elements, tmp_pos;
      left_end = mid - 1;
      tmp_pos = left;
      num_elements = right - left + 1;
      // (*ctr)++;
      while ((left <= left_end) && (mid <= right))
      {

            (*ctr)++;
            if (numbers[left] <= numbers[mid])
            {
                  temp[tmp_pos] = numbers[left];
                  tmp_pos = tmp_pos + 1;
                  left = left + 1;
            }
            else
            {
                  temp[tmp_pos] = numbers[mid];
                  tmp_pos = tmp_pos + 1;
                  mid = mid + 1;
            }
      }


      while (left <= left_end)
      {

            (*ctr)++;
            temp[tmp_pos] = numbers[left];
            left = left + 1;
            tmp_pos = tmp_pos + 1;
      }


      while (mid <= right)
      {

            (*ctr)++;
            temp[tmp_pos] = numbers[mid];
            mid = mid + 1;
            tmp_pos = tmp_pos + 1;
      }


      for (i = 0; i <= num_elements; i++)
      {
            // (*ctr)++;
            numbers[right] = temp[right];
            right = right - 1;
      }
}
