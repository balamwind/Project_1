#include <iostream>
#include <string>

using namespace std;


float GetTotal(float* array, int size)
{
	float result = 0;
	for (int i = 0; i < size; i++)
		result += array[i];

	return result;
}

float Average(float totalNumber, int size)
{
	return totalNumber / size;
}

//오름차순
//선택 알고리즘을 사용하기로 함
float* AscendingOrder(float* array, int size)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j > 0 && array[j] < array[j - 1]; j--)
		{
			float temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
		}

	return array;
}

//퀵 정렬에서 쓰는 분할
//설정된 pivot의 다음 요소부터 right까지 서로 비교해서 값이 차이나면 조건대로 변경 (현재는 내림차순이다)
//변경을 한번 쭉 하고, pivot과 high의 위치를 교환 후, 피봇을 기준으로 양옆을 다시 같은 조건으로 정렬을 반복한다
int Partition(float* array, int pivot, int right)
{
	int low, high;
	int pivotValue = array[pivot]; // pivot 값 설정

	low = pivot + 1;	// low 는 pivot의 바로 다음 위치에서부터
	high = right;		// high는 전달된 끝지점

	while (low <= high) {
		while (array[low] > pivotValue) low++;	// pivot 보다 작은 값이 나올때마다 이동
		while (array[high] < pivotValue) high--; // pivot 보다 큰 값이 나올때마다 이동

		if (low <= high) { // low와 high 가 중단된 지점이 서로 위치가 역전된 지점이 아니라면
			int temp = array[low];    // low 와 high 의 값 변경
			array[low] = array[high];
			array[high] = temp;
		}
	}

	// 피벗과 high 위치 교환
	int temp = array[pivot];
	array[pivot] = array[high];
	array[high] = temp;

	return high; // 피벗 위치 반환
}


void QuickSort(float* array, int left, int right)
{
	if (left < right)
	{
		int pivot = Partition(array, left, right);

		QuickSort(array, left, pivot - 1);
		QuickSort(array, pivot + 1, right);
	}
}

//내림차순
//퀵 정렬을 사용하기로 함
float* DescendingOrder(float* array, int size)
{
	QuickSort(array, 0, size - 1);

	return array;
}

float* Clone(float* array, int size)
{
	float* result = new float[size];
	for (int i = 0; i < size; i++)
		result[i] = array[i];

	return result;
}

int main()
{
	int arraySize = 0;
	cout << "배열의 갯수를 입력해주세요. ";
	cin >> arraySize;

	float* numbers = new float[arraySize];
	cout << "숫자를 " + to_string(arraySize) + "개 입력해주세요. ";

	for (int i = 0; i < arraySize; i++)
		cin >> numbers[i];
	cout << endl;


	cout << "입력 받은 숫자" << endl;

	for (int i = 0; i < arraySize; i++)
		cout << numbers[i] << endl;
	cout << endl;


	cout << "오름차순" << endl;

	float* ascending = AscendingOrder(Clone(numbers, arraySize), arraySize);

	for (int i = 0; i < arraySize; i++)
		cout << ascending[i] << endl;
	cout << endl;


	cout << "내림차순" << endl;

	float* descending = DescendingOrder(Clone(numbers, arraySize), arraySize);

	for (int i = 0; i < arraySize; i++)
		cout << descending[i] << endl;
	cout << endl;

	cout << "합계 : " << GetTotal(numbers, arraySize) << endl;
	cout << "평균 : " << Average(GetTotal(numbers, arraySize), arraySize) << endl;


	delete[] ascending, descending, numbers;

	return 0;
}