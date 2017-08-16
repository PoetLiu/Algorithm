void insert(int *nums, int *m, int new)
{
    int i = 0, tmp = labs(nums[i]-new); 
    for (i = 0; i < *m; i++) {
        if (labs(nums[i] - new) <= tmp) 
            tmp = labs(nums[i] - new);
        else
            break;
    }
    tmp = i;
    
    for (i = *m; i > tmp; i--) 
        nums[i] = nums[i-1];
    nums[tmp]   = new;
    (*m)++;
}

void merge(int* nums1, int m, int* nums2, int n) {
    int i = 0, total = m; 
    for (i = 0; i < n; i++)
        insert(nums1, &total, nums2[i]);
    return;   
}
