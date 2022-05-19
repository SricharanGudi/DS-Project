#include<stdio.h>                           // header file 
#include<math.h>
int board[20],count;    
int main()                                  //main function
{
int n,i,j;
void queen(int row,int n);
printf("\n Enter number of Queens:");
scanf("%d",&n);                             //input from the user
queen(1,n);
return 0;
}
void print(int n)                           //function for printing the solution
{
int i,j;                                    
printf("\n\nSolution %d:\n\n",++count);
for(i=1;i<=n;++i)
  printf("\t%d",i);
for(i=1;i<=n;++i)
{
  printf("\n\n%d",i);
  for(j=1;j<=n;++j)                      //for n*n board
  {
   if(board[i]==j)
    printf("\tQ");                      //queen at i,j position
   else
    printf("\t-");                      //empty slot
  }
}
}
/*function to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
int i;
for(i=1;i<=row-1;++i)
{
  if(board[i]==column)                         //checking column and digonal conflicts
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
}
return 1;                                        //no conflicts
}
void queen(int row,int n)                      //function to check for proper positioning of queen
{
 int column;
 for(column=1;column<=n;++column)
 {
    if(place(row,column))
   {
     board[row]=column;                     //no conflicts so place queen
     if(row==n)                              //dead end
     print(n);                              //printing the board configuration
     else                                   //try queen with next position
     queen(row+1,n);
    }
 }
}