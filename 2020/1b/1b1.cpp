#include <bits/stdc++.h>

using namespace std;

bool cango( long x, long y, long steps )
{
    if (x==0 && y==0)
        return steps==0;
    x = abs(x);
    y = abs(y);
    if (((x^y)&1)==0)
        return false;
    auto d = x+y;
    return d<(1ul<<steps);
}

string dir( long &x, long &y, long steps )
{
    long d = 1<<steps;
    if (cango(x-d,y,steps))
    {
        x -= d;
        return "E";
    }
    if (cango(x+d,y,steps))
    {
        x += d;
        return "W";
    }
    if (cango(x,y-d,steps))
    {
        y -= d;
        return "N";
    }
    if (cango(x,y+d,steps))
    {
        y += d;
        return "S";
    }

    assert( false );
}

string soluce( long x, long y )
{
    for (long steps=0;steps!=80;steps++)
        if (cango(x,y,steps))
        {
            string s;
            while (steps--)
                s.insert( 0, dir( x,y, steps ) );
            return s;
        }
    return "IMPOSSIBLE";
}

long main2()
{
    for (long y=-10;y!=10;y++)
    {
        for (long x=-10;x!=10;x++)
            cout << cango( x, y, 1 );
        cout << "\n";
    }
}

int main()
{
    long T;
    long X;
    long Y;
    cin >> T;

    for (long casen=1;casen<=T;casen++)
    {
        cin >> X;
        cin >> Y;

		cout << "Case #" << casen << ": ";

cout << X << "\n";

		cout << soluce( X, Y ) << "\n";
    }
}
