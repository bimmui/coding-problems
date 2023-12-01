class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> results;
        int currNum = 1;
        int index = 0;
        while (currNum <= n && index < target.size())
        {
            int num = target[index];
            if (num == currNum)
            {
                results.push_back("Push");
                currNum++;
                index++;
            }
            else
            {
                results.push_back("Push");
                results.push_back("Pop");
                currNum++;
            }
        }
        return results;
    }
};