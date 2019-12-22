#include<stdio.h>
#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
const int N = 10;

void adjust(vector<int>& nums,int p,int s)
{
    while(2*p+1<s)
    {
        int c1=2*p+1;
        int c2=2*p+2;
        int c=(c2<s&&nums[c2]>nums[c1])?c2:c1;
        if(nums[c]>nums[p]) swap(nums[c],nums[p]);
        else break;
        p=c;
    }
}
void heapSort(vector<int>& nums)
{
    for(int i=nums.size()/2;i>=0;--i)
    {
        adjust(nums,i,nums.size());
    }
    for(int i=nums.size()-1;i>0;--i)
    {
        swap(nums[0],nums[i]);
        adjust(nums,0,i);
    }
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
	heapSort(nums);
	cout << "ÅÅÐòºó£º";
	for (int i = 0; i<nums.size(); ++i)
	{
		cout  << nums[i] << " ";
	}
	system("pause");
	return 0;
}