#include<stdio.h>
#include<string.h>
int main()
{
    char n;
    char grid[5][5] = {{' ', ' ', 'I', 'X', ' '},{' ', 'X', ' ', ' ', ' '},{'I', ' ', 'X', 'X', ' '},{' ', ' ', ' ', 'I', 'X'},{' ', 'X', ' ', ' ', 'P'}};
    
       
        for(int i = 0;i < 5;i++)
        {
            printf("+__+__+__+__+__+\n|");
            for(int j = 0;j < 5;j++)
            {
                printf("%2c|",grid[i][j]);
            }
            printf("\n");
        }
        printf("+__+__+__+__+__+\n");
        int i = 4;
        int j = 4;
        while(n != 'Q')
        {  
        fflush(stdin);
        printf("\nEnter move (W: up, S: down, A: left, D: right, Q: quit) : ");
        scanf("%2c",&n);
        fflush;
            if(n == 'W')
            {  
                
                i--;
                if(grid[i][j] != 'X' && i >= 0)
                    {  
                        if(grid[i][j] == 'I')
                        printf("\n👍ITEM COLLECTED👍\n");
                        grid[i+1][j] = ' ';
                        grid[i][j] = 'P';
                        
                    }
                else {printf("\n😉INVALID MOVE !😉\n"); i++;}     
            }
            else if (n == 'A')
            {
                
                j--;
                if(grid[i][j] != 'X'&& j >= 0)
                    {
                        if(grid[i][j] == 'I')
                        printf("\n👍ITEM COLLECTED👍\n");
                        grid[i][j+1] = ' ';
                        grid[i][j] = 'P';

                    }
                else {printf("\n😉INVALID MOVE !😉\n"); j++;} 
            }
            else if (n == 'S')
            {
                
                i++;
                if(grid[i][j] != 'X' && i <= 4)
                    {
                        if(grid[i][j] == 'I')
                        printf("\n👍ITEM COLLECTED👍\n");
                        grid[i-1][j] = ' ';
                        grid[i][j] = 'P';
                    }
                else {printf("\n😉INVALID MOVE !😉\n"); i--;} 
            }
            else if (n == 'D')
            {
                j++;
                if(grid[i][j] != 'X'&& j <= 4)
                    {
                        if(grid[i][j] == 'I')
                        printf("\n👍ITEM COLLECTED👍\n");
                        grid[i][j-1] = ' ';
                        grid[i][j] = 'P';
                    }
                else {printf("\n😉INVALID MOVE !😉\n"); j--;} 
            }
            else if(n != 'W' && n != 'A' && n != 'S' && n != 'D' && n != 'Q') 
            printf("\n😉INVALID KEY😉\n");
            else if (n == 'Q')
            {
                printf("\nTHANKS FOR PLAYING THE GAME\n\n😊----SOOFIYAN IMRAN------😊\n\n\n");
            }
            
            
            for(int i = 0;i < 5;i++)
            {
                printf("\n+__+__+__+__+__+\n|");
                for(int j = 0;j < 5;j++)
                {
                    printf("%2c|",grid[i][j]);
                }
                printf("\n");
            }
            printf("+__+__+__+__+__+\n");
        } 
              
}
