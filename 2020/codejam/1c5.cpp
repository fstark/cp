#include <bits/stdc++.h>

using namespace std;

int N;


typedef std::array<std::array<int,50>,50> mat;

void dump( mat m, int delta = 0 )
{
    for (int r=0;r!=N;r++)
    {
        for (int c=0;c!=N;c++)
            cout << m[r][c]+delta << " ";
        cout << "\n";
    }
}

bool can_do( int n, int &a, int &b, int &c )
{
    if (n==0)
    {
        a = 0;
        b = N-1;
        c = 0;
        return true;
    }

    for (a=1;a!=N-1;a++)
        for (b=1;b!=N;b++)
            for (c=1;c!=N;c++)
                if (b!=c && a*b+c==n)
                {
                    return true;
                }
    return false;
}

std::array<std::array<int,50>,50> make()
{
    std::array<std::array<int,50>,50> res;
    for (int r=0;r!=N;r++)
        for (int c=0;c!=N;c++)
            res[r][c] = (c-r+N)%N;

    return res;
}

std::array<std::array<int,50>,50> make_2e()
{
    auto res = make();

    for (int r=1;r<N;r+=2)
        swap( res[r][0], res[r][2] );

    swap( res[0][0], res[0][1] );
    swap( res[1][0], res[1][1] );

    return res;
}

std::array<std::array<int,50>,50> make_2o()
{
    auto res = make();

    swap( res[0][0], res[0][1] );

    swap( res[1][0], res[1][1] );
    swap( res[1][1], res[1][2] );

    swap( res[2][0], res[2][1] );
    swap( res[3][1], res[3][2] );

    for (int r=4;r<N;r+=2)
        swap( res[r][0], res[r][2] );

    return res;
}

std::array<std::array<int,50>,50> make_2()
{
    if ((N%2)==0)
        return make_2e();
    return make_2o();
}

void mswap( mat &m, int v0, int v1 )
{
    // cout << "SWAP " << v0 << "<->" << v1 << "\n";
    for (int r=0;r!=N;r++)
        for (int c=0;c!=N;c++)
        {
            auto v = m[r][c];
            if (v==v0)
                m[r][c] = v1;
            if (v==v1)
                m[r][c] = v0;
        }
}

void mmove( mat &m, int a )
{
        rotate( begin(m), begin(m)+1, begin(m)+a+1 );

//    for (int r=0;r!=N;r++)
//        rotate( begin(m[r]), begin(m[r])+a, begin(m[r])+a+1 );
}

void mswap( mat &m )
{
    for (int r=0;r!=N;r++)
        for (int c=0;c!=N;c++)
        {
            m[r][c] = N-1-m[r][c];
        }
}

mat build( int a, int b, int c )
{
    mat res = make();

    mswap( res, res[0][a], c );
    mswap( res, res[0][N-1], b );

    mmove( res, a );

    return res;
}


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
    if (presence[n])
        dup = true;
    presence[n] = true;
}

bool check( mat &m, int t )
{
    int s = 0;
    for (int i=0;i!=N;i++)
        s += m[i][i];
    
    if (s!=t)
    {
        std::cerr << "FAIL!\n";
        exit(1);
        return false;
    }

    for (int r=0;r!=N;r++)
    {
        clean();

        for (int c=0;c!=N;c++)
        {
            add( m[r][c] );
        }
        if (dup)
        {
            std::cerr << "FAIL 2!\n";
            exit(1);
            return false;
        }
    }

    for (int c=0;c!=N;c++)
    {
        clean();

        for (int r=0;r!=N;r++)
        {
            add( m[r][c] );
        }
        if (dup)
        {
            std::cerr << "FAIL 3!\n";
            exit(1);
            return false;
        }
    }

    return true;
}

void solve( int n )
{
    int oldn = n;
    int a, b, c;

    bool sw = false;
    mat res;
    if (n>N*(N-1)/2)
    {
        n = N*N-N-n;
        sw = true;
    }

    if (N==4 && n==6)
    {
        res = {
                {
                    { 3, 0, 1, 2 },
                    { 0, 3, 2, 1 },
                    { 1, 2, 0, 3 },
                    { 2, 1, 3, 0 }
                }
            };
    }
    else if (n==2 && N>3)
    {
        res = make_2();
    }
    else if (can_do(n,a,b,c))
    {
        res = build( a, b, c );

        // cout << "A=" << a << " B=" << b << " C=" << c << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
        // cerr << "N=" << N << " t=" << oldn << "\n";
        return;
    }
    if (sw)
    {
        mswap( res );
    }
    cout << "POSSIBLE\n";

    // cout << oldn << "\n";
    dump( res, 1 );
    // check( res, oldn );
}

int main()
{
    int T;

    // freopen("1c5.in", "r", stdin);

    cin >> T;
    // cerr << T << "\n";

    for (int casen=1;casen<=T;casen++)
    {
		cout << "Case #" << casen << ": ";

        cin >> N;
        int trace;
        cin >> trace;

        trace -= N;

        // cerr << "N= " << N << " TRACE= " << trace << "\n";

        solve( trace );
    }
}

int main3()
{
    for (N=4;N!=5;N++)
        for (int t=0;t!=N*N-N;t++)
            solve( t );
}

int main4()
{
    N = 5;
    dump( build( 2, 2, 4 ), 0 );
}
