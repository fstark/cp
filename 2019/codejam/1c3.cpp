#include <math.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void TLE( bool f )
{
    if (!f)
        for (;;)
            ;
}

class game
{
    char s[15][15];

public:
    int sx,sy;

    game( int sx, int sy )
    {
        this->sx = sx;
        this->sy = sy;
    }

    void set( int x, int y, char c ) { s[x][y] = c; }
    char get( int x, int y ) const { return s[x][y]; }

    bool is_in( int x, int y) const { return x>=0 && y>=0 && x<sx && y<sy; }

    bool is_free( int x, int y ) const { return s[x][y] == '.'; }
    bool is_dead( int x, int y ) const { return s[x][y] == '#'; }

    int play( int x, int y, int dx, int dy, int &total )
    {
        while (is_in(x,y))
        {
            if (is_dead(x,y))
                return false;
            if (!is_free(x,y))
                return true;
            s[x][y] = '*';
            x += dx;
            y += dy;
            total++;
        }

        return true;
    }

    bool play_h( int x, int y, int &total )
    {
        total = 0;
        if (!is_free(x,y))
            return false;
        bool res = play( x, y, 1, 0, total );
        if (is_in(x-1,y) && is_dead(x-1,y))
            return false;
        return res;
    }

    bool play_v( int x, int y, int &total )
    {
        total = 0;
        if (!is_free(x,y))
            return false;
        bool res = play( x, y, 0, 1, total );
        if (is_in(x,y-1) && is_dead(x,y-1))
            return false;
        return res;
    }

    void dump() const
    {
        cerr << "C=" << sx << " R=" << sy << "\n";
        for (int y=0;y!=sy;y++)
        {
            for (int x=0;x!=sx;x++)
                cerr << s[x][y];
            cerr << "\n";
        }
    }

    string to_str( bool turn ) const
    {
        string res;
        if (turn)
            res += 't';
        for (int y=0;y!=sy;y++)
            for (int x=0;x!=sx;x++)
            {
                TLE( s[x][y]=='.' || s[x][y]=='#' || s[x][y]=='*' );
                res += s[x][y];
            }
        return res;
    }
};

bool hack = false;
std::map<string,bool> m;

void store( const game &g, bool turn, bool res )
{
    if (!hack)
        m[g.to_str(turn)] = res;
}

bool i_can_win( const game &g, bool myturn )
{
    auto k = g.to_str(myturn);
    auto r = m.find(k);

    if (r!=m.end() && r->first==k)
    {
        return r->second;
    }

    g.dump();

    if (myturn)
    {
        for (int y=0;y!=g.sy;y++)
            for (int x=0;x<g.sx;x++)
                if (g.is_free(x,y))
                {
                    int total;
                    game g2 = g;
                    if (g2.play_h( x, y, total ))
                    { 
                        if (i_can_win(g2,false))
                        {
                            store( g, myturn, true );
                            // if (found) TLE( cached==true );
                            return true;
                        }
                    }
                    x += total;
                }
        for (int x=0;x!=g.sx;x++)
            for (int y=0;y<g.sy;y++)
                if (g.is_free(x,y))
                {
                    int total;
                    game g2 = g;
                    if (g2.play_v( x, y, total ))
                    { 
                        if (i_can_win(g2,false))
                        {
                            store( g, myturn, true );
                            // if (found) TLE( cached==true );
                            return true;
                        }
                    }
                    y += total;
                }
        store( g, myturn, false );
        // if (found) TLE( cached==false );
        return false;
    }

    for (int y=0;y!=g.sy;y++)
        for (int x=0;x<g.sx;x++)
            if (g.is_free(x,y))
            {
                    int total;
                game g2 = g;
                if (g2.play_h( x, y, total ))
                { 
                    if (!i_can_win(g2,true))
                    {
                        store( g, myturn, false );
                        // if (found) TLE( cached==false );
                        return false;
                    }
                }
                x += total;
            }
    for (int x=0;x!=g.sx;x++)
        for (int y=0;y<g.sy;y++)
            if (g.is_free(x,y))
            {
                    int total;
                game g2 = g;
                if (g2.play_v( x, y, total ))
                { 
                    if (!i_can_win(g2,true))
                    {
                        store( g, myturn, false );
                        // if (found) TLE( cached==false );
                        return false;
                    }
                }
                y += total;
            }

    store( g, myturn, true );
    // if (found) TLE( cached==true );
    return true;
}

int top( const game &g )
{
    int count = 0;

    for (int y=0;y!=g.sy;y++)
        for (int x=0;x<g.sx;x++)
            if (g.is_free(x,y))
            {
                int total;
                game g2 = g;
                if (g2.play_h( x, y, total ))
                { 
                    if (i_can_win(g2,false))
                    {
                        // cerr << "WIN # " << total << " at H(" << x << "," << y << ")\n";
                        // g2.dump();
                        // g.dump();
                        count += total;
                    }
                }
                x += total;
            }
    for (int x=0;x!=g.sx;x++)
        for (int y=0;y<g.sy;y++)
            if (g.is_free(x,y))
            {
                int total;
                game g2 = g;
                if (g2.play_v( x, y, total ))
                { 
                    if (i_can_win(g2, false))
                    {
                        // cerr << "WIN # " << total << " at H(" << x << "," << y << ")\n";
                        // g2.dump();
                        // g.dump();
                        count += total;
                    }
                }
                y += total;
            }

    return count;
}

void check_one( const game &g )
{
    m = std::map<string,bool>{};
    auto r0 = top( g );
    hack = true;
    auto r1 = top( g );
    if (r0!=r1)
    {
        // cerr << r0 << " vs " << r1 << "\n";
        // g.dump();
        // cerr << "\n";
    }
}

void check_all( int r, int c )
{
    int n = r*c;
    int nn = (1<<n);
    for (int i=0;i!=nn;i++)
    {
        int j = i;
        game g(c,r);
        for (int y=0;y!=r;y++)
            for (int x=0;x!=c;x++)
            {
                g.set( x, y, j&1?'.':'#' );
                j >>= 1;
            }
        check_one( g );
    }
}

int R,C;

void check()
{
    for (int r=0;r!=5;r++)
        for (int c=0;c!=5;c++)
            check_all( r, c );
}

int main(int argc, const char * argv[])
{
    // check();
    // cerr << "DONE\n";

	int T;
	cin >> T;
	for (int casen=1;casen<=T;casen++)
	{
        m = std::map<string,bool>{};

		cout << "Case #" << casen << ": ";
		
		cin >> R >> C;
		
        // cerr << "ROWS=" << R << " COLS=" << C << "\n";

        game g( C, R );
        for (int y=0;y!=R;y++)
        {
            string s;
            cin >> s;
            for (int x=0;x!=C;x++)
                g.set( x, y, s[x] );
        }

        // g.dump();
        // cerr << "\n";

        int n = top(g);

        // cerr << "# = " << n << "\n";

		cout << n << "\n";
	}
	
	return 0;
}
