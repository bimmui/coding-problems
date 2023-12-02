class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 1;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[curr] != nums[i])
            {
                nums[curr + 1] = nums[i];
                curr++;
                count++;
            }
        }

        return count;
    }
};