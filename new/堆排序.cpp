void adjust(vector<int>&nums,int index,int size){
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int maxindex = index;
	if(left<size&&nums[left]>nums[maxindex])
		maxindex = left;
	if(right<size&&nums[right]>nums[maxindex])
		maxindex = right;
	if(maxindex!=index){
		swap(nums[maxindex],nums[index]);
		adjust(nums,maxindex,size);
	}
}

void heapSort(vector<int> nums){
	int size = nums.size();
	for(int i=size/2-1;i>=0;i--)
		adjust(nums,i,size);
	for(int i=size-1;i>=1;i--){
		swap(nums[0],nums[i]);
		adjust(nums,0,i);
	}
}
