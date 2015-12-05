#ifndef MERGESORT_H
#define MERGESORT_H
#include <stdio.h>
#define MAX 50

void mergeSort(int tab[],int low,int mid,int high);
void partition(int tab[],int low,int high);//trouve le "milieu" de la liste d'éléments

#endif