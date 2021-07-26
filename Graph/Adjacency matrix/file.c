//C code
#include <stdio.h>
#include <stdlib.h>
void r_file(FILE *fp,int n,int graph[n][n])
{

// ex.txt must exist in the same directory

//oherwise it is requir to mention the absolute path

 if (fp == NULL) { 

 printf("\nError to open the file\n");
exit (1);
 }
fscanf(fp,"%d",&n); //fscanf function read a data (in

//from file pointed by the pointer fp
int i,j;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
 fscanf(fp,"%d",&graph[i][j]); //read a graph from file
}
}
}

int main () {
    int graph[10][10];int n;
      FILE *fp; //create a pointer to a file
      fp= fopen ("Ex.txt", "r"); //open a file in read mode,
    r_file(fp,n,graph);
int i,j;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("%3d",graph[i][j]); //read a graph from file
}
printf("\n");
}
fclose (fp); //to close the file
printf("\n%d",n);
return 0;

}
 