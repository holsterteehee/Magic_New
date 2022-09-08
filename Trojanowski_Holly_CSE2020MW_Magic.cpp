#include "Trojanowski_Holly_CSE2020MW_Magic.h"

using namespace std;

pair<int, int> next_rc(vector<vector<int> > mag, int r, int c)
{
    int r1 = r;
    int c1 = c;
    pair<int, int> nextrc;
    int n = mag.size();

    if (r1 == n - 1 && c1 == n - 1)
    {
        // (r, c) is the lower right corner, we are moving one square
        nextrc.first = r1 - 1;
        nextrc.second = c1;
        
        return nextrc;
    }

    r1 = r1 + 1;
    c1 = c1 + 1; //next row and col

    if (r1 < n && c1 <n)
    {
        if(mag[r1] [c1] == 0)
        {
            nextrc.first = r1;
            nextrc.second = c1;

            return nextrc;
        }

        else
        {
            r1 = r1 - 2;
            c1 = c1 - 1;
            nextrc = wrap(r1, c1, n);
            
            return nextrc;
        }
        
    }

    else
    {
        nextrc = wrap(r1, c1, n);

        return nextrc;
    }
}

pair<int, int> wrap(int r, int c, int n)
{
    pair<int, int> rc;

    if (r >= n)
    {
        rc.first = 0;
        rc.second = c;

        return rc;
    }

    if (r < 0)
    {
        rc.first = n - 1;
        rc.second = c;

        return rc;
    }

    if (c >= n)
    {
        rc.first = r;
        rc.second = 0;

        return rc;
    }
    if (c < 0)
    {
        rc.first = r;
        rc.second = n - 1;

        return rc;
    }

    rc.first = r;
    rc.second = c;

    return rc;
}

vector<vector<int> > magic(int n)
{
    if (n % 2 == 0) 
    {
        cout << "Error: expected odd n, got " << n << "..." << endl;
        return vector<vector<int>>();
    } 
    else 
    {
        vector<vector<int>> mag;
        for (int i = 0; i < n; i++) 
        {
            vector<int> row;
            for (int j = 0; j < n; j++)
                row.push_back(0);
            mag.push_back(row);
        }
        return mag;
    }
    
}

void print_magic(const vector<vector<int> >& mag)
{
    cout << endl;
    for (int i = 0; i < mag.size(); i++)
    {
        for (int j = 0; j < mag.size(); j++)
            if (mag[i] [j] == 0)
                cout << left << setw(6) << "~" << " ";
            else
                cout << left << setw(6) << mag[i] [j] << " ";
        cout << endl;
    }
    cout << endl;

    return;
}

int row_sum(int i, const vector<vector<int>> &mag)
{
    int dim = mag[0].size();
    int sum = 0;
    for (int j = 0; j < dim; j++)
        sum += mag[i][j];
    return sum;
}

int col_sum(int j, const vector<vector<int>> &mag)
{
    int dim = mag[0].size();
    int sum = 0;
    for (int i = 0; i < dim; i++)
        sum += mag[i][j];
    return sum;
}

int diag1_sum(const vector<vector<int>> &mag)
{
    int dim = mag[0].size();
    int sum = 0;
    for (int i = dim - 1, j = 0; j < dim; i--, j++)
        sum += mag[i][j];
    return sum;
}

int diag2_sum(const vector<vector<int>> &mag)
{
    int dim = mag[0].size();
    int sum = 0;
    for (int i = dim - 1, j = 0; j < dim; i--, j++)
        sum += mag[i][j];
    return sum;
}
bool test_magic(const vector<vector<int>> & mag, int & msum)
{
    int dim = mag[0].size();
    int rsum = row_sum(0, mag);

    for (int i = 1; i < dim; i++)
        if (row_sum(i, mag) != rsum)
            return false;
    for (int i = 0; i < dim; i++)
        if (col_sum(i, mag) != rsum)
            return false;
    if (diag1_sum(mag) != rsum || diag2_sum(mag) != rsum)
        return false;

    msum = rsum;
    return true;
}

