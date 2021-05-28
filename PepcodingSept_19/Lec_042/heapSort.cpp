#include <iostream>
#include <vector>

using namespace std;
int compareTo(vector<int> &arr, int child, int par, bool isMax)
{
    if (isMax)
    {
        return arr[child] - arr[par];
    }
    else
    {
        return arr[par] - arr[child];
    }
}
void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void downHeapify(vector<int> &arr, int idx, int lidx, bool isMax)
{
    int maxidx = idx;
    int lchild = 2 * idx + 1;
    int rchild = 2 * idx + 2;

    if (lchild <= lidx && compareTo(arr, lchild, maxidx, isMax) > 0)
    {
        // cout<<"hi";
        maxidx = lchild;
    }
    if (rchild <= lidx && compareTo(arr, rchild, maxidx, isMax) > 0)
    {
        // cout<<"bye";
        maxidx = rchild;
    }
    if (maxidx != idx)
    {
        swap(arr, maxidx, idx);
        downHeapify(arr, maxidx, lidx, isMax);
    }
}
int main(int args, char **argv)
{
    vector<int> arr = {7, 20, 10, 15, 16, 8, 30};
    // vector<int> arr = {10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13};
    int n = arr.size() - 1;
    bool isMax = false;
    for (int i = n; i >= 0; i--)
    {
        downHeapify(arr, i, n, isMax);
    }
    for (int i = 0; i <= n; i++)
    {
        swap(arr[0], arr[n - i]);
        downHeapify(arr, 0, n - i - 1, isMax);
    }
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}