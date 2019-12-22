#include<stdio.h>
#include<iostream>
#include<vector>
#include<ctime>

using namespace std;
const int N = 10;

void quicksort(vector<int> &nums, int left, int right)
{
	if (left >= right) return;
	int size = nums.size();
	int pivot = nums[left];
	int i = left, j = right;
	int index = 0;
	while (i<j)
	{
		while (i<j&&nums[i] <= pivot) ++i;
		while (i<j&&nums[j]>pivot) --j;
		if (i<j)
		{
			swap(nums[i++], nums[j--]);
		}
	}
	if (nums[i]>pivot)
	{
		swap(nums[i - 1], nums[left]);
		index = i - 1;
	}
	else
	{
		swap(nums[i], nums[left]);
		index = i;
	}
	quicksort(nums, left, index - 1);
	quicksort(nums, index + 1, right);

}
int main()
{
	vector<int> nums;
	srand(time(0));
    for (int i = 0; i<N; ++i)
	{
		 int a=rand()%100;
		 nums.push_back(a);
	}
	cout << "ÅÅÐòÇ°£º";
	for (int i = 0; i<nums.size(); ++i)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	quicksort(nums, 0, nums.size() - 1);
	cout << "ÅÅÐòºó£º";
	for (int i = 0; i<nums.size(); ++i)
	{
		cout  << nums[i] << " ";
	}
	system("pause");
	return 0;
}