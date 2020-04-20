#include <bits/stdc++.h>

using namespace std;

int T;
int N;


int main()
{
    int T;

//    freopen("1c3.in", "r", stdin);

    cin >> T;

    for (int casen=1;casen<=T;casen++)
    {
		cout << "Case #" << casen << ": ";

        cin >> N;

        vector<tuple<int,int,int>> tasks;

        for (int i=0;i!=N;i++)
        {
            int f,t;
            cin >> f;
            cin >> t;
            tasks.push_back( { f, t, i });
        }

        sort( begin(tasks), end(tasks) );

        string r(N,' ');

        int c = 0;
        int j = 0;
        for (auto t:tasks)
        {
            if (c<=get<0>(t))
            {
                c = get<1>(t);
                r[get<2>(t)] = 'C';
            }
            else if (j<=get<0>(t))
            {
                j = get<1>(t);
                r[get<2>(t)] = 'J';
            }
            else
            {
                r = "IMPOSSIBLE";
                break;
            }
        }

		cout << r << "\n";
    }
}
