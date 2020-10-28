#include <stdio.h>
#include <math.h>

int main()
{
    int MAX; 
    printf("Taille de la matrice : ");
    scanf("%d",&MAX); 

    typedef double TM[MAX][MAX];
    TM A;
    TM G;


    printf("les elements de la matrice\n");
    for(int i=0;i<MAX;i++)
	for (int j=0;j<MAX;j++)
	{
    	    //scanf("%lf",&A[i][j]);
    	    A[i][j]=1.0d/(i+j+1); //matrice de Hilbert
	}

    for(int k=0;k<MAX;k++)
    {
        G[k][k] = A[k][k];
        for(int i=0;i<k;i++)
            G[k][k] = G[k][k] - G[k][i]*G[k][i];
        G[k][k] = sqrt(G[k][k]); 
        for(int i=k+1;i<MAX;i++)
        {
            G[i][k] = A[i][k];
            for(int j=0;j<k;j++)
                G[i][k] = G[i][k] - G[i][j] * G[k][j];
            G[i][k] = G[i][k] / G[k][k];
        }
    }

    printf("A =\n");
    for(int i=0;i<MAX;i++)
    {
	for (int j=0;j<MAX;j++)
    	    printf("%.10lf ",A[i][j]);
	printf("\n");
    }

    printf("G =\n");
    for(int i=0;i<MAX;i++)
    {
	for (int j=0;j<MAX;j++)
    	    printf("%.10lf ",G[i][j]);
	printf("\n");
    }

}
