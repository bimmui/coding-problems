class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // i prob couldve used an stl set instead of all of this
        vector<int> bootleg_htable(1000, 10000);
        vector<int> results;
        for (int i = 0; i < nums1.size(); i++)
        {
            bootleg_htable[nums1[i]] = nums1[i];
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (bootleg_htable[nums2[i]] != 10000 and bootleg_htable[nums2[i]] == nums2[i])
            {
                results.push_back(nums2[i]);
                bootleg_htable[nums2[i]] = 10000;
            }
        }

        return results;
    }
};