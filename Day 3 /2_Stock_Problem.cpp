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
    stack<int> st;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty())
        {
            int l = st.top();
            int o = v[l];
            if (o <= v[i])
            {
                st.pop();
            }
            else
            {
                break;
            }
        }
        if (st.empty())
        {
            a[i] = i + 1;
        }
        else
        {
            a[i] = i - st.top();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
