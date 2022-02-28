#include "iostream"
#include "ctime"
using namespace std;


char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int row, col;

bool CheckBot(int n)
{
    int r,c;

    if(n <= 3)
    {    r = 0; c = n-1;}

    else if(n > 3 && n <= 6)
    { r = 1; c = n - 4;}

    else
    { r = 2; c = n-7;}

    if(board[r][c] == 'X' || board[r][c] == 'O' || n>9)
    {
        return false;
    }

    return true;
}

char checkBoard(char c)
{
    if(int(c) >= 48 && int(c) <= 58)
        return ' ';
    
    else
        return c;
}

void drawBoard()
{
    cout<<checkBoard(board[0][0])<<" | "<<checkBoard(board[0][1])<<" | "<<checkBoard(board[0][2])<<endl;
    cout<<"---------"<<endl;

    cout<<checkBoard(board[1][0])<<" | "<<checkBoard(board[1][1])<<" | "<<checkBoard(board[1][2])<<endl;
    cout<<"---------"<<endl;

    cout<<checkBoard(board[2][0])<<" | "<<checkBoard(board[2][1])<<" | "<<checkBoard(board[2][2])<<endl;
}

void Setvalue(int n, char var)
{
L4:
    if(n <= 3)
    {    row = 0; col = n-1;}

    else if(n > 3 && n <= 6)
    { row = 1; col = n - 4;}

    else
    { row = 2; col = n-7;}

    if(board[row][col] == 'X' || board[row][col] == 'O' || n>9)
    {
        cout<<"\nInvalid Input Please Re-enter : ";
        cin>>n;
        cout<<"\n";
        goto L4;
    }

    board[row][col] = var;

}

bool checkWin(char marker)
{
    bool flag = 0;

    //first Digonal
    int i = 2;
    int j = 2;
    while(i >= 0 && j>= 0)
    {
        if(board[i][j] != marker)
        {
            flag = 1;
            break;
        }
        i--;
        j--;
    }

    //Second digonal
    if(flag == 1)
    {
        i = 2;
        j = 0;
        while (i >= 0 && j <= 2)
        {
            if(board[i][j] != marker)
            {
                flag = 1;
                goto L3;
            }
            i --;
            j ++;
        }
        flag = 0;
    }
L3:
    //horizontal
    if(flag == 1)
    {
        i = row;
        j = 0;
        while (j<=2)
        {
            if(board[i][j] != marker)
            {
                flag = 1;
                goto L2;
            }
            j++;
        }
        flag = 0;
    }
L2:
    //vertical
    if(flag == 1)
    {
        i = 2;
        j = col;
        while (i>=0)
        {
            if(board[i][j] != marker)
            {
                flag = 1;
                goto L1;
            }
            i--;
        }
        flag = 0;
    }
L1:
    if(flag  == 0)
        return true;

    else  
        return false;
}

void SwapPlayer(int *player, char *c)
{
    if(*player == 1)
    {
        *player = 2;
        *c = 'O';
    }
    
    else
    {
        *player = 1; 
        *c = 'X';
    }
}

void PlaywithFriend()
{
    int player_current = 1;
    char curr_marker = 'X';

    int position;

    for(int i=0; i<9; i++)
    {
        cout<<"Player "<<player_current<<" Enter the Positon: ";
        cin>>position;

        Setvalue(position, curr_marker);
        drawBoard();

        if(i>3)
        {
            if(checkWin(curr_marker))
            {
                cout<<"Player "<<player_current<<" Have won "<<endl;
                return;
            }
        }

        SwapPlayer(&player_current, &curr_marker);
    }

    cout<<"Nobody Won it's a Tie ";
}

void PlaywithBot()
{
    int player_current = 1;
    char curr_marker = 'X';

    int position;

    for(int i=0; i<9; i++)
    {
        if(player_current == 2)
        {
            cout<<"Computer has chosen : ";

            srand(time(NULL));
            int random ;

            do
            {
                random = (rand() % (10 -1 +1) + 1);

            }while( CheckBot(random) == false);

            cout<<random<<endl;

            Setvalue(random, curr_marker);
            drawBoard();
        }

        else
        {
            cout<<"Player "<<player_current<<" Enter the Positon: ";
            cin>>position;

            Setvalue(position, curr_marker);
            drawBoard();
        }

        if(i>3)
        {
            if(checkWin(curr_marker))
            {
                cout<<"\nPlayer "<<player_current<<" Have won Congratulations"<<endl;
                return;
            }
        }

        SwapPlayer(&player_current, &curr_marker);
    }

    cout<<"Nobody Won it's a Tie ";
}


int main()
{
    int option;

    cout<<"Welcome to this Console based Tic Tac Toe Game"<<endl;

    cout<<(board[0][0])<<" | "<<(board[0][1])<<" | "<<(board[0][2])<<endl;
    cout<<"---------"<<endl;

    cout<<(board[1][0])<<" | "<<(board[1][1])<<" | "<<(board[1][2])<<endl;
    cout<<"---------"<<endl;

    cout<<(board[2][0])<<" | "<<(board[2][1])<<" | "<<(board[2][2])<<endl;

    cout<<"\nGiven are the Position to be Inputed\n"<<endl;

    cout<<"Press 1 to Play with Friend \nPress 2 to Play against the Noob Bot"<<endl;
    cin>>option;
    cout<<endl;

    if(option == 1)
    {    PlaywithFriend();}

    else
    {cout<<"You are playing against the Bot\n";    PlaywithBot();}

    return 0;
}