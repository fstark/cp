#include <bits/stdc++.h>

using namespace std;

int N;

void dump( std::array<std::array<int,50>,50> &a, int delta = 0 )
{
    for (int r=0;r!=N;r++)
    {
        for (int c=0;c!=N;c++)
            cout << a[r][c]+delta << " ";
        cout << "\n";
    }
}

void swap_row( std::array<std::array<int,50>,50> &a, int r0, int r1 )
{
    for (int i=0;i!=N;i++)
        swap( a[r0][i], a[r1][i] );
}

void swap_col( std::array<std::array<int,50>,50> &a, int c0, int c1 )
{
    for (int i=0;i!=N;i++)
        swap( a[i][c0], a[i][c1] );
}

bool build( std::array<std::array<int,50>,50> &a, int pos, int sum, int max )
{
    cerr << "  POS=" << pos << " SUM=" << sum << " MAX=" << max << "\n";

    if (pos==N)
        return sum==0;  //  won if sum is zero

    while (1)
    {
        //  move the max on top

        cerr << "    LOOK FOR " << max << "\n";
        for (int r=pos;r!=N;r++)
            for (int c=pos;c!=N;c++)
                if (a[r][c]==max)
                {
                    swap_row( a, pos, r );
                    swap_col( a, pos, c );
                    cerr << "FOUND\n";
                    // dump( a );
                    goto end;
                }

        goto next;

end:
        if (build(a,pos+1,sum-max,min(sum-max,max)))
            return true;

next:
        max--;

        // cerr << max << "\n";

        if (max<sum/(N-pos))
            break;
    }

    return false;
}

int main()
{
    int T;

    freopen("1c5.in", "r", stdin);

    cin >> T;

    for (int casen=1;casen<=T;casen++)
    {
		cout << "Case #" << casen << ": ";

        cin >> N;
        int trace;
        cin >> trace;

        trace -= N;

        cerr << "N= " << N << " TRACE= " << trace << "\n";

        std::array<std::array<int,50>,50> a;

        for (int i=0;i!=N;i++)
            for (int j=0;j!=N;j++)
                a[i][j] = (i-j+N)%N;

        // dump( a );

        if (!build( a, 0, trace, min(trace,N-1) ))
            cout << "IMPOSSIBLE\n";
        else
        {
            cout << "POSSIBLE\n";
            dump( a, 1 );
        }
    }
}
