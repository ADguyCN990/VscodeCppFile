#include <bits/stdc++.h>

using namespace std;

int tf(int n)
{
    if (n > 0)
    {
        n -= 10;
    }
    else
    {
        n += 10;
    }
    return n;
}

vector<int> preprocess(vector<int> c, int t)
{
    int count = 0;
    while (t > 0)
    {
        if (t & 1 == 1)
        {
            c[count] = tf(c[count]);
        }

        count++;
        t >>= 1;
    }
    return c;
}

int solve1(int in1, int in2)
{

    int t;
    t = 1;
    while (t--)
    {
        vector<char> a(4), b(4);
        vector<int> c(4);
        // int in;
        // cin >> in;
        for (auto &i : a)
        {
            i = in1 % 10;
            in1 /= 10;
        }
        reverse(a.begin(), a.end());
        // cin >> in;
        for (auto &i : b)
        {
            i = in2 % 10;
            in2 /= 10;
        }
        reverse(b.begin(), b.end());
        for (int i = 0; i < 4; i++)
        {
            c[i] = b[i] - a[i];
        }
        int global_min = -1;
        for (int i = 0; i <= 0b1111; i++)
        {
            vector<int> tmp = preprocess(c, i);
            int _max = abs(tmp[0]);
            int _sum = 0;
            for (int j = 1; j < 4; j++)
            {
                if (tmp[j] * tmp[j - 1] > 0)
                {
                    if (_max > abs(tmp[j]))
                    {
                        _sum += _max - abs(tmp[j]);
                        _max = abs(tmp[j]);
                    }
                    _max = max(_max, abs(tmp[j]));
                }
                else
                {
                    _sum += _max;
                    _max = abs(tmp[j]);
                }
            }
            _sum += _max;
            if (global_min == -1)
            {
                global_min = _sum;
            }
            global_min = min(global_min, _sum);
        }
        reverse(c.begin(), c.end());

        for (int i = 0; i <= 0b1111; i++)
        {
            vector<int> tmp = preprocess(c, i);
            int _max = abs(tmp[0]);
            int _sum = 0;
            for (int j = 1; j < 4; j++)
            {
                if (tmp[j] * tmp[j - 1] > 0)
                {
                    if (_max > abs(tmp[j]))
                    {
                        _sum += _max - abs(tmp[j]);
                        _max = abs(tmp[j]);
                    }
                    _max = max(_max, abs(tmp[j]));
                }
                else
                {
                    _sum += _max;
                    _max = abs(tmp[j]);
                }
            }
            _sum += _max;
            if (global_min == -1)
            {
                global_min = _sum;
            }
            global_min = min(global_min, _sum);
        }
        return global_min;
    }
    return 0;
}

char aa[5], bb[5];
int a[5], b[5], c[5];

bool check()
{
    if (c[1] * c[2] <= 0 && c[2] * c[3] <= 0 && c[3] * c[4] <= 0)
    {
        return false;
    }
    return true;
}

int solve(vector<int> v)
{
    int ans = 0;
    for (int i = 1; i <= 4; ++i)
    {
        a[i] = v[i];
    }
    for (int i = 5; i <= 8; ++i)
    {
        b[i - 4] = v[i];
    }
    for (int i = 1; i <= 4; ++i)
    {
        int up = (b[i] - a[i] + 10) % 10, down = abs(a[i] - b[i] + 10) % 10;
        if (up > down)
        {
            c[i] = -down;
        }
        else
            c[i] = up;
    }
    while (check())
    {
        for (int i = 1; i <= 4; ++i)
        {
            int j = i, sumc = c[i], num = 20;
            while (c[j] * sumc > 0 && j <= 4)
            {
                j++;
                sumc = c[j - 1];
            }
            if (j == i)
                continue;
            for (int k = i; k < j; ++k)
            {
                num = min(num, abs(c[k]));
            }
            if (c[i] < 0)
                num = -num;
            // geng xin lian xv qv jian
            for (int k = i; k < j; ++k)
            {
                c[k] -= num;
            }
            // xiang liang bian yan shen
            for (int k = i - 1; k >= 1; k--)
            {
                int cur = c[k] - num;
                if ((10 - abs(cur)) <= abs(c[k]))
                {
                    c[k] = (c[k] < 0 ? 1 : -1) * (10 - abs(cur));
                }
                else
                    break;
            }
            for (int k = j; k <= 4; ++k)
            {
                int cur = c[k] - num;
                if ((10 - abs(cur) <= abs(c[k])))
                {
                    c[k] = (c[k] < 0 ? 1 : -1) * (10 - abs(cur));
                }
                else
                    break;
            }
            ans += abs(num);
            i = j - 1;
        }
    }
    for (int i = 1; i <= 4; ++i)
    {
        int c1 = (10 - abs(c[i]));
        if (abs(c[i] > c1))
            c[i] = c1;
    }
    for (int i = 1; i <= 4; ++i)
    {
        ans += abs(c[i]);
    }
    // cout << ans << endl;
    return ans;
}

int main(void)
{
    int t;
    // cin >> t;
    t  = 1;
    while (t--)
    {
        int in1, in2;
        // cin >> in1 >> in2;
        in1 = 3232, in2 = 0;
        vector<int> v;
        v.push_back(0);
        v.push_back(in1 / 1000);
        v.push_back((in1 / 100) % 10);
        v.push_back((in1 / 10) % 10);
        v.push_back(in1 % 10);
        v.push_back(in2 / 1000);
        v.push_back((in2 / 100) % 10);
        v.push_back((in2 / 10) % 10);
        v.push_back(in2 % 10);
        int ss0 = solve(v);
        int ss1 = solve1(in1, in2);
        cout << min(ss0, ss1) << endl;
    }
    return 0;
}

// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;

//     for (int i1 = 0; i1 <= 9; i1++)
//     {
//         for (int i2 = 0; i2 <= 9; ++i2)
//         {
//             for (int i3 = 0; i3 <= 9; ++i3)
//             {
//                 for (int i4 = 0; i4 <= 9; ++i4)
//                 {
//                     for (int i5 = 0; i5 <= 9; ++i5)
//                     {
//                         for (int i6 = 0; i6 <= 9; ++i6)
//                         {
//                             for (int i7 = 0; i7 <= 9; ++i7)
//                             {
//                                 for (int i8 = 0; i8 <= 9; ++i8)
//                                 {
//                                     vector<int> v;
//                                     v.push_back(0);
//                                     v.push_back(i1);
//                                     v.push_back(i2);
//                                     v.push_back(i3);
//                                     v.push_back(i4);
//                                     v.push_back(i5);
//                                     v.push_back(i6);
//                                     v.push_back(i7);
//                                     v.push_back(i8);
//                                     int ss0 = solve(v);
//                                     int ss1 = solve1(1000 * i1 + 100 * i2 + 10 * i3 + i4, 1000 * i5 + 100 * i6 + 10 * i7 + i8);
//                                     if (ss0 != ss1)
//                                     {
//                                         cout << "!!!" << 1000 * i1 + 100 * i2 + 10 * i3 + i4 << "   " << 1000 * i5 + 100 * i6 + 10 * i7 + i8 << endl;
//                                         cout << ss0 << " " << ss1 << endl;
//                                     }
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return 0;
// }