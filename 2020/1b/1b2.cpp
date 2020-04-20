#include <bits/stdc++.h>

using namespace std;

long find( long low, long high, int x, bool horiz )
{
    string res;
    //  low is maybe OUT, high is IN
    while (low<high-1)
    {
        auto mid = (low+high)/2;
        if (horiz)
            cout << mid << " " << x << "\n";
        else
            cout << x << " " << mid << "\n";
        cin >> res;
        if (horiz)
            cerr << mid << " " << x << " -> " << res << "\n";
        else
            cerr << x << " " << mid << " -> " << res << "\n";
        if (res=="HIT")
            high = mid;
        if (res=="MISS")
            low = mid;
    }
    return high;
}

const long BIG = 1000000000;

int main()
{
    long T;
    long R;
    cin >> T;

    cin >> R;
    cin >> R;

    cerr << "Radius" << R << "\n";

    int i =0;

    int delta = BIG-R;

    for (long casen=1;casen<=T;casen++)
    {
        // cerr << "CASE #" << casen << "\n";
        cerr << "\n\n\n\n\n";
        int x = find( -BIG, -BIG+delta*2+1, 0, true );
        int y = find( -BIG, -BIG+delta*2+1, 0, false );

        cerr << "RES1 = " << x << " " << y << "\n";

        // x = find( -BIG, -BIG+delta*2+1, y+R, true );
        // y = find( -BIG, -BIG+delta*2+1, x+R, false );

        cerr << "RES2 = " << x << " " << y << "\n";

        for (int dx=-1;dx!=1;dx++)
            for (int dy=-1;dy!=1;dy++)
            {
                cout << x+R+dx << " " << y+R+dy << "\n";
                cerr << x+R+dx << " " << y+R+dy << "\n";
                string res;

                cin >> res;
                cerr << res << "\n";
                if (res=="CENTER")
                    goto next;
            }

        next:
            ;
    }
}
