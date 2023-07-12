#include <iostream>
#include <fstream>
#include <graphics.h>
#include <winbgim.h>
#include<mmsystem.h>
#include<stdlib.h>
#include<iomanip>
#include<dos.h>
#include<stdio.h>
#define NRL 618
#define NRC 618
#define LG 618
using namespace std;

ifstream fin("matrici.in");
ifstream ffin("vectori.in");

ofstream fout("matrici.out");
ofstream ffout("vectori.out");

float scalar, d = 1;
int nr_dep_stg, nr_dep_dr, putere;
bool engleza = false;

struct matrice {
    float elem[NRL][NRC];
    int linii;
    int coloane;
};

struct vectori {
    float elem[LG];
    int lungime;
};

matrice A;
matrice B;
matrice C;
matrice At;

vectori X;
vectori Y;
