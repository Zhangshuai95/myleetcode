#include<stdio.h>
#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
const int N = 10;


void mergeSort(vector<int> &nums, int l, int r)
{
	if (l >= r) return;
	
	int mid = l + (r - l) / 2;
	mergeSort(nums, l, mid);
	mergeSort(nums, mid + 1, r);

	vector<int> res;
	int i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (nums[i]<nums[j]) res.push_back(nums[i++]);
		else res.push_back(nums[j++]);
	}
	while (i<=mid) res.push_back(nums[i++]);
	while (j<=r) res.push_back(nums[j++]);
	for (int i = 0; i<res.size(); ++i)
	{
		nums[l+i] = res[i];
	}
}

void bubbleSort(vector<int> &nums)
{
	for(int i=0;i<nums.size()-1;++i)
	{
		for(int j=0;j<nums.size()-1-i;++j)
		{
			if(nums[j]>nums[j+1])
				swap(nums[j],nums[j+1]);
		}
	}
}

void insertsort(vector<int> &nums)
{
	for(int i=0;i<nums.size();++i)
	{
		int v=nums[i];
		int j=i-1;
		while(j>=0&&nums[j]>v)
		{
			nums[j+1]=nums[j];
			j--;
		}
		nums[j+1]=v;
	}
}//插入排序

void selectSort(vector<int>& nums)
{
	int min=0;
	int n=nums.size();
	for(int i=0;i<n-1;++i)
	{	
		min=i;
		for(int j=i+1;j<n;++j)
		{
			if(nums[j]<nums[min])
				min=j;
		}
		swap(nums[i],nums[min]);	
	}	
}//选择排序
int main()
{
	vector<int> nums;
	vector<int> num1;
	srand(time(0));
	for (int i = 0; i<N; ++i)
	{
		int a = rand() % 100;
		nums.push_back(a);
	}
	cout << "排序前：";
	for (int i = 0; i<nums.size(); ++i)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	mergeSort(nums, 0, nums.size() - 1);
	cout << "归并排序后：";
	for (int i = 0; i<nums.size(); ++i)
	{
		cout << nums[i] << " ";
	}
	cout << endl;


	for (int i = 0; i<N; ++i)
	{
		int a = rand() % 100;
		num1.push_back(a);
	}
	cout << "选择排序前：";
	for (int i = 0; i<num1.size(); ++i)
	{
		cout << num1[i] << " ";
	}
	cout << endl;

	selectSort(num1);
	cout << "选择排序后：";
	for (int i = 0; i<num1.size(); ++i)
	{
		cout << num1[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}