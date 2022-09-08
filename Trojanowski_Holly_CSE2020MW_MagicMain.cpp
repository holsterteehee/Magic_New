#include <iostream>
#include "Trojanowski_Holly_CSE2020MW_Magic.h"

using namespace std;

int main()
{
    int n;
    int msum;
    int magic_sum;
    
    cout << "Size of Magic Square [odd]: ";
    cin >> n;
    cout << endl << endl;
    vector<vector<int> > magicSQ = magic(n);
    print_magic(magicSQ);

    if (test_magic(magicSQ, magic_sum))
    {
        cout << endl;
        cout << "Magic Square Test passes -- the magic sum is ";
        cout << magic_sum << endl;
    }
    else
    {
        cout << endl;
        cout << "Magic Square Test fails" << endl;
    }

return 0;

}
