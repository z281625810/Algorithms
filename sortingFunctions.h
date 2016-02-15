/* ***  Author:  Feng Sun
*  Last Update:  Octorber 13, 2014
*        Class:  CSI-281
*     Filename:  sortingFunctions.cpp
*
*  Description:
*      This is the template of sorting algorithms' implementations.
*
*  Certification of Authenticity:
*     I certify that this assignment is entirely my own work.
**********************************************************************/

#ifndef sortingFunctions_h
#define sortingFunctions_h


template <class T>
void bubbleSort (T list[], int size);

template <class T>
void insertionSort(T list[], int size);

template <class T>
void selectionSort(T list[], int size);

template <class T>
void shellSort(T list[], int size);

template <class T>
void mergeSort (T list[], int lowerBound, int upperBound);

template <class T>
void quickSort(T list[], int lowerBound, int upperBound);

/*     Pre:  an array and its size
*     Post:  sort the array with bubble sort
*  Purpose:  to sort the array
*****************************************************************************/
template <class T>
void bubbleSort(T list[], int size)
{
	bool swapped = true;
	int temp,
		i;
	while (swapped)
	{
		swapped = false;
		for (i = 0; i < size - 1; i++)
		{
			if (list[i+1] < list[i])
			{
				temp = list[i+1];
				list[i+1] = list[i];
				list[i] = temp;
				swapped = true;
			}
		}
	}
}


/*     Pre:  an array and its size
*     Post:  sort the array with insertion sort
*  Purpose:  to sort the array
*****************************************************************************/
template <class T>
void insertionSort(T list[], int size)
{
	int i,
		j;
	T value;
	for (i = 1; i < size; i++)
	{
		value = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > value)
		{
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = value;	
	}
}


/*     Pre:  an array and its size
*     Post:  sort the array with selection sort
*  Purpose:  to sort the array
*****************************************************************************/
template <class T>
void selectionSort(T list[], int size)
{
	int i,
		j,
		temp,
		minIndex;

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (list[j] < list[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			temp = list[i];
			list[i] = list[minIndex];
			list[minIndex] = temp;
		}
	}
}


/*     Pre:  an array and its size
*     Post:  sort the array with shell sort
*  Purpose:  to sort the array
*****************************************************************************/
template <class T>
void shellSort(T list[], int size)
{
	int gap,
		i,
		temp;

	gap = size / 2;
	while (gap > 0)
	{
		for (i = 0; i < size - gap; i++)
		{
			if (list[i] > list[i + gap])
			{
				temp = list[i];
				list[i] = list[i + gap];
				list[i + gap] = temp;
			}
		}
		gap /= 2;
	}
	bubbleSort(list, size);
}


/*     Pre:  an array, lowerbound of the array, middle index of the array
			 and upper bound of the array
*     Post:  merge elements together
*  Purpose:  to merge elements together
*****************************************************************************/
template <class T>
void merge(T list[], int lowerBound, int middle, int upperBound)
{
	int sizeOne,
		sizeTwo,
		i,
		j,
		k;

	sizeOne = middle - lowerBound + 1;
	sizeTwo = upperBound - middle;

	T* tempOne = new T[sizeOne];
	T* tempTwo = new T[sizeTwo];

	for (i = 0; i < sizeOne; i++)
	{
		tempOne[i] = list[lowerBound + i];
	}
	for (j = 0; j < sizeTwo; j++)
	{
		tempTwo[j] = list[middle + 1 + j];
	}

	i = 0;
	j = i;

	for (k = lowerBound; k <= upperBound; k++)
	{
		if (i == sizeOne) 
        {
            list[k] = tempTwo[j];
            j++;
        }
        else if (j == sizeTwo) 
        {
            list[k] = tempOne[i];
            i++;
        }
        else if ( tempOne[i] < tempTwo[j] )
        {
            list[k] = tempOne[i];
            i++;
        }
        else
        {
            list[k] = tempTwo[j];
            j++;
        }
	}

	delete [] tempOne;
	delete [] tempTwo;
}


/*     Pre:  an array, lowerbound of the array, upper bound of the array
*     Post:  sort the array with merge sort
*  Purpose:  to sort the array
*****************************************************************************/
template <class T>
void mergeSort(T list[], int lowerBound, int upperBound)
{
	int middle;
	if (upperBound-lowerBound>1)
	{
		middle = (lowerBound + upperBound) / 2;
		mergeSort(list, lowerBound, middle);
		mergeSort(list, middle + 1, upperBound);
		merge(list, lowerBound, middle, upperBound);
	}
	else 
    {
		if (list[upperBound] < list[lowerBound])
        {
            int tmp = list[upperBound];
            list[upperBound] = list[lowerBound];
            list[lowerBound] = tmp;
        }
    }
}


/*     Pre:  an array, lowerbound of the array, upper bound of the array
*     Post:  sort the array with quick sort
*  Purpose:  to sort the array
*****************************************************************************/
template <class T>
void quickSort(T list[], int lowerBound, int upperBound)
{
	int i,
		j,
		pivot,
		temp;

	i = lowerBound;
	j = upperBound;
	pivot = list[(i + j) / 2];
	
	while (i <= j)
	{
		while (list[i] < pivot)
		{
			i++;
		}
		while (list[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
			i++;
			j--;
		}
	}
	

	if (lowerBound < j)
	{
		quickSort(list, lowerBound, j);
	}

	if (i < upperBound)
	{
		quickSort(list, i, upperBound);
	}
}


#endif //! sortingFunctions_h