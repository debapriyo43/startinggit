

// Input :
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output :
// -8 0 -6 -6
// Explanation :ls
l
    // First negative integer for each window of size k
    // {-8, 2} = -8
    // {2, 3} = 0 (does not contain a negative integer)
    // {3, -6} = -6
    // {-6, 10} = -6
    vector<long long>
    printFirstNegativeInteger(long long int A[],
                              long long int N, long long int K)
{

    deque<long long> dq;
    vector<long long> ans;
    // check for the first k window
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
        ans.push_back(0);
    // check for the remaining window
    for (int i = K; i < N; i++)
    {
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }
        if (A[i] < 0)
            dq.push_back(i);
        if (dq.size() > 0)
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
    }
    return ans;
}