#include<iostream>
using namespace std;
void Need(int p, int r, int need[100][100], int maxm[100][100], int allot[100][100])
{
    for (int i = 0 ; i < p ; i++)
        for (int j = 0 ; j < r ; j++)
            need[i][j] = maxm[i][j] - allot[i][j];
}
bool safe(int p, int r, int avail[], int maxm[][100], int allot[][100])
{
    int need[100][100];
    Need(p, r, need, maxm, allot);

    bool finish[100] = {0};

    int safeSeq[100];

    int work[100];
    for (int i = 0; i < r ; i++)
        work[i] = avail[i];
    int count = 0;
    while (count < p)
    {

        bool found = false;
        for (int c = 0; c <p; c++)
        {
            if (finish[c] == 0)
            {
                int j;
                for (j = 0; j < r; j++)
                    if (need[c][j] > work[j])
                        break;
                if (j == r)
                {
                    for (int k = 0 ; k < r ; k++)
                        work[k] += allot[c][k];

                    safeSeq[count++] = c;

                    finish[c] = 1;

                    found = true;
                }
            }
        }
        if (found == false)
        {
            cout << "He thong o trang thai chua an toan!!" << endl;
            return false;
        }
    }
    cout << "He thong co chuoi an toan la: ";
    for (int i = 0; i < p ; i++)
        cout << safeSeq[i] << " ";
    return true;
}
int main()
{
    int p, r;
    cin >> p >> r;
    int allot[100][100];
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            cin >> allot [i] [j] ;
        }
    }
    int maxm[100][100];
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            cin >> maxm[i][j];
        }
    }
    int avail[100];
    for (int i = 0; i < r; i++) {
        cin >> avail[i];
    }
    safe(p, r, avail, maxm, allot);
    return 0;
}