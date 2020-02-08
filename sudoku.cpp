#include<iostream>

using namespace std;

int s[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

void printsudoku()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
        	cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
}

int unassigned(int *row, int *col)
{
    int num = 0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            
            if(s[i][j] == 0)
            {
                
                *row = i;
                *col = j;
                num = 1;
                return num;
            }
        }
    }
    return num;
}

int isSafe(int n, int r, int c)
{
    
    for(int i=0;i<9;i++)
    {
        if(s[r][i] == n)
            return 0;
    }

    for(int i=0;i<9;i++)
    {
        if(s[i][c] == n)
            return 0;
    }
    int rowstart = (r/3)*3;
    int colstart = (c/3)*3;
    for(int i=rowstart;i<rowstart+3;i++)
    {
        for(int j=colstart;j<colstart+3;j++)
        {
            if(s[i][j]==n)
                return 0;
        }
    }
    return 1;
}
int solvesudoku()
{
    int row;
    int col;
    if(unassigned(&row, &col) == 0)
        return 1;
    
    for(int i=1;i<=9;i++)
    {
        if(isSafe(i, row, col))
        {
            s[row][col] = i;
            
            if(solvesudoku())
                return 1;
            s[row][col]=0;
        }
    }
    return 0;
}
int main()
{
    if (solvesudoku())
        printsudoku();
    else
        printf("No solution\n");
    return 0;
}