#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> a(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (st.size() != 0 && st.top() >= v[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            a[i] = -1;
        }
        else
        {
            a[i] = st.top();
        }
        st.push(v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}