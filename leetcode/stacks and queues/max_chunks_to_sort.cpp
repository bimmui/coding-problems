class Solution
{
public:
    // this works bc the sum of (arr[i] - i) equals 0 where ever we can make
    // a chunk since the elements in that part all have a number that can be cancelled out
    int maxChunksToSorted(vector<int> &arr)
    {

        // arr = permutation of integers 0 to n-1
        int n = arr.size();
        int i = 0, sum = 0, chunks = 0;

        while (i < n)
        {
            // substracting array and its index at every index
            sum += (arr[i] - i);
            if (sum == 0)
            {
                chunks++;
            }
            i++;
        }

        return chunks;
    }
};