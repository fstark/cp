#include <math.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

bool wins( char c0, char c1 )
{
    if (c1=='R')
        return c0=='P';
    if (c1=='P')
        return c0=='S';
    if (c1=='S')
        return c0=='R';
    return false;
}

int main(int argc, const char * argv[])
{
	
	int T;
	cin >> T;
	for (int casen=1;casen<=T;casen++)
	{
        int A;
		cout << "Case #" << casen << ": ";
		
		cin >> A;
		
		vector<string> v;
        for (int i=0;i!=A;i++)
        {
            string s;
            cin >> s;
            v.push_back( s );
        }

        string res = "";

        bool won = false;
        bool lost = false;

        for (int i=0;i!=500;i++)
        {
            int r = 0;
            int p = 0;
            int s = 0;

            char c;
            for (int j=0;j!=v.size();j++)
            {
                c = v[j][i%v[j].size()];
                if (c=='R') r++;
                if (c=='P') p++;
                if (c=='S') s++;
            }

            // cerr << r << "/" << p << "/" << s << "\n";

            if (r && p && s)
            {
                break;
            }

                //  WON
            if (r && !p && !s)
            {
                res += 'P';
                won = true;
                break;
            }

            if (!r && p && !s)
            {
                res += 'S';
                won = true;
                break;
            }

            if (!r && !p && s)
            {
                res += 'R';
                won = true;
                break;
            }

                //  CONTINUE
            if (r && p && !s) { c = 'P'; res += c; }
            if (!r && p && s) { c = 'S'; res += c; }
            if (r && !p && s) { c = 'R'; res += c; }

            vector<string> w;
            for (int j=0;j!=v.size();j++)
            {
                auto c2 = v[j][i%v[j].size()];
                if (!wins(c,c2))
                {
                    w.push_back( v[j] );
                }
            }
            v = w;
        }

        if (!won)
            res = "IMPOSSIBLE";

		cout << res << "\n";
	}
	
	return 0;
}
