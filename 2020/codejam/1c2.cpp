#include <bits/stdc++.h>

using namespace std;

int T;
int N;


int main()
{
    int T;
    cin >> T;

    for (int casen=1;casen<=T;casen++)
    {
		cout << "Case #" << casen << ": ";

        string s;
        cin >> s;

        int d =0;

        for (auto c:s)
        {
            int n = c-'0';
            while (n>d)
            {
                cout << "(";
                d++;
            }
            while (n<d)
            {
                cout << ")";
                d--;
            }
            cout << c;
        }

        while (0<d)
        {
            cout << ")";
            d--;
        }

		cout << "\n";
    }
}
