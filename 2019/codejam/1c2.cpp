#include <math.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

// ofstream flog;

bool is_prefix( const string &p, const string &s )
{
    // flog << "PREFIX [" << p << "] [" << s << "] ";
    for (int i=0;i!=p.size();i++)
        if (s.size()<i || p[i]!=s[i])
        {
            // flog << "-> NO\n";
            return false;
        }
    // flog << "-> YES\n";
    return true;
}

int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // flog.open( "log.txt" );

	int T,F;
	cin >> T >> F;

    // flog << "T = " << T << "\n" << flush;
    // flog << "F = " << F << "\n" << flush;
	for (int casen=1;casen<=T;casen++)
	{

        vector<string> guesses;
        guesses.resize( 119 );
        string res;

        int count = 0;

        for (int pos=0;pos!=5;pos++)
        {
            vector<int> n;
            n.resize(5);

            for (auto c:res)
            {
                n[c-'A'] = 1000;
            }

            //  We do this rounds questions on valid guesses
            for (int i=0;i!=119;i++)
            {
                // flog << i << ": ";
                if (is_prefix( res, guesses[i]))
                {
                    count++;
                    cout << i*5+pos+1 << "\n" << flush;
                    // flog << "Q = " << i*5+pos << "\n" << flush;
                    string s;
                    cin >> s;
                    // flog << "A = " << s << "\n" << flush;
                    if (s=="N")
                        exit(1);
                    guesses[i] += s[0];
                    n[s[0]-'A']++;
                }
            }
            // flog << "STATS = ";
            // for (int i=0;i!=5;i++)
            //     flog << (char)('A'+i) << "=" << n[i] << " ";
            // flog << "\n";
            char c = (min_element( begin(n), end(n) ) - begin(n))+'A';
            res += c;
            // flog << "PARTIAL = " << res << "\n" << flush;
        }
        cout << res << "\n" << flush;
        // flog << "RES = [" << res << "]\n" << flush;
        std::string response;
        cin >> response;
        // flog << "VERDICT = " << response << "\n" << flush;
        if (response=="N")
            exit(1);
        // flog << "COUNT = " << count << "\n";
	}
	
	return 0;
}
