#include <bits/stdc++.h>

using namespace std;

int T;
int B;

array<bool,100> bits;
int query_left;
int p;

bool query( int p )
{
    // cerr << "WILL Q\n";
    query_left--;
    cout << p+1 << "\n";
    bool res;
    cin >> res;
    // cerr << "READ FROM " << p << " => " << res << "\n";
    return res;
}

void query_and_store( int p )
{
    bits[p] = query( p );
}

void dual_query_and_store( int p )
{
    query_and_store( p );
    query_and_store( B-1-p );
}

void dump_result()
{
    // cerr << "DUMP!\n";
    for (int i=0;i!=B;i++)
        cout << bits[i];
    cout << "\n";
    string r;
    cin >> r;
    if (r[0]!='Y')
    {
        // cerr << "FAILED!\n";
        exit(1);
    }
}

array<bool,100> flip( array<bool,100> in )
{
    array<bool,100> res;
    for (int i=0;i!=100;i++)
        res[i] = !in[i];
    return res;
}

array<bool,100> reverse( array<bool,100> in )
{
    array<bool,100> res;
    for (int i=0;i!=100;i++)
        res[i] = in[B-1-i];
    return res;
}

array<bool,100> change( bool fflip, bool freverse )
{
    array<bool,100> res = bits;
    if (fflip)
        res = flip(res);
    if (freverse)
        res = reverse(res);
    return res;
}

int main()
{

    cin >> T;
    cin >> B;

    // cerr << "READ " << T << "\n";
    // cerr << "READ " << B << "\n";

    for (int casen=1;casen<=T;casen++)
    {
        // cerr << "CASE # " << casen << "\n";

        p =0;
        query_left = 10;
        while (p!=B/2)
        {
            if (query_left)
            {
                dual_query_and_store( p++ );
            }

            if (p==B/2)
                break;

            if (!query_left)
            {
                auto first = query(0);

                vector<array<bool,100>> s;
                auto r = change( false, false );
                if (r[0]==first)
                    s.push_back( r );
                r = change( false, true );
                if (r[0]==first)
                    s.push_back( r );
                r = change( true, false );
                if (r[0]==first)
                    s.push_back( r );
                r = change( true, true );
                if (r[0]==first)
                    s.push_back( r );
                assert( s.size()==2 );

                //  Scan to find a different bit
                int i;
                for (i=0;i!=p;i++)
                    if (s[0][i]!=s[1][i])
                    {
                        if (query(i)==s[0][i])
                            bits = s[0];
                        else
                            bits = s[1];
                        break;
                    }
                if (i==p)
                {
                    // assert( s[0]==s[1] );
                    bits = s[0];
                    query(0);
                }
                query_left = 8;
            }
        }

        dump_result();
    }
}
