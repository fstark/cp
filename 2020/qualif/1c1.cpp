#include <bits/stdc++.h>

using namespace std;

int N;
static array<bool,100> presence;
bool dup;

void clean()
{
    for (int i=0;i!=N;i++)
        presence[i] = false;
    dup = false;
}

void add( int n )
{
    if (presence[n-1])
        dup = true;
    presence[n-1] = true;
}

int main()
{
    int T;
    cin >> T;

    for (int casen=1;casen<=T;casen++)
    {
        cin >> N;

		cout << "Case #" << casen << ": ";

        array<array<int,100>,100> a;

        for (int r=0;r!=N;r++)
            for (int c=0;c!=N;c++)
                cin >> a[r][c];
        
        int s = 0;
        for (int i=0;i!=N;i++)
            s += a[i][i];
        
        int rt = 0;
        int ct = 0;

        for (int r=0;r!=N;r++)
        {
            clean();

            for (int c=0;c!=N;c++)
            {
                add( a[r][c] );
            }
            rt += dup;
        }

        for (int c=0;c!=N;c++)
        {
            clean();

            for (int r=0;r!=N;r++)
            {
                add( a[r][c] );
            }
            ct += dup;
        }

		cout << s << " " << rt << " " << ct << "\n";
    }
}
