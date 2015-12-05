//Mergesort / Tri fusion

//complexité temporelle pour  entrée de taille n: n log n
//Source code de l'implémentation du tri fusion(merge sort) utilisant un tableau par ordre croissant

#include <stdio.h>
#include "mergesort.h"

int main()
{
   
    int merge[MAX],i,n;

    printf("Nombre d'éléments: ");
    scanf("%d",&n);

    printf("Les éléments à trier: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&merge[i]);
    }

    partition(merge,0,n-1);

    printf("Les éléments après le tri: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",merge[i]);
    }

   return 0;
}

void partition(int tab[],int low,int high) //partition des éléments
{ 

    int mid;

    if(low<high)
    {
        mid=(low+high)/2; // on trouve le milieu
        partition(tab,low,mid); // partition low à mid
        partition(tab,mid+1,high); // partition mid+1 à high
        mergeSort(tab,low,mid,high); 
    }
}

void mergeSort(int tab[],int low,int mid,int high)
{

    int j; // init de j à 0
    int tmp[MAX];

    int l=low;
    int i=low;
    int m=mid+1;

    while((l<=mid)&&(m<=high))//tant que l'extrémité la plus basse est inférieure au 'milieu'
    {					  	  // et que l'extrémité supérieure est supérieure à mid+1 
        if(tab[l]<=tab[m])
        {
           tmp[i]=tab[l];
           l++;
        }

        else
        {
           tmp[i]=tab[m];
           m++;
        }

        i++;
    }

    if(l>mid)
    {
        for(j=m;j<=high;j++)
        {
           tmp[i]=tab[j];
           i++;
        }
    }

    else
    {
        for(j=l;j<=mid;j++)
        {
            tmp[i]=tab[j];
            i++;
        }
    }
   
    for(j=low;j<=high;j++)
    {
        tab[j]=tmp[j];
    }
}