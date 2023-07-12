#pragma once
#include "Libraries.h"

//Grafica matrici: Iosub George + Berea Manuela
void citire_matrici(); //Iosub George
void adunare_matrici(); //Iosub George
void scadere_matrici(); //Iosub George
void inmultire_matrici(); //Iosub George
void inmultire_matrice_cu_scalar(); //Iosub George
void impartire_matrice_cu_scalar(); //Iosub George
void transpusa(); //Iosub George
void inversa(); //Berea Manuela
void ridicare_la_putere(); //Berea Manuela
void diagonala_principala(); //Iosub George
void diagonala_secundara(); //Iosub George

//Grafica vectori: Iosub George + Berea Manuela
void citire_vectori(); //Berea Manuela
void suma_elem_din_vector(); //Berea Manuela
void prod_elem_din_vector(); //Berea Manuela
void inmultire_vector_cu_scalar(); //Berea Manuela
void impartire_vector_cu_scalar(); //Berea Manuela
void sortare_crescatoare(); //Berea Manuela
void sortare_descrescatoare(); //Berea Manuela
void permutare_stanga(); //Berea Manuela
void permutare_dreapta(); //Berea Manuela
void inversare_vector(); //Berea Manuela

void ecran_matrici(); //Iosub George
void ecran_vectori(); //Berea Manuela
void ecran_operatii(); //Iosub George + Berea Manuela
void optiuni(); //Berea Manuela + Iosub George
void interfata(); //Iosub George + Berea Manuela
void BibMat();


void citire_matrici() {
    fin >> A.linii >> A.coloane >> B.linii >> B.coloane;

    for (int i = 1; i <= A.linii; i++) {
        for (int j = 1; j <= A.coloane; j++) {
            fin >> A.elem[i][j];
        }
    }
    for (int i = 1; i <= B.linii; i++) {
        for (int j = 1; j <= B.coloane; j++) {
            fin >> B.elem[i][j];
        }
    }
    fin >> scalar;
    fin >> putere;
}


void citire_vectori() {
    ffin >> X.lungime;

    for (int i = 1; i <= X.lungime; i++) {
        ffin >> X.elem[i];
    }

    ffin >> scalar;
    ffin >> nr_dep_stg >> nr_dep_dr;
}

// Operatii matrici:

void adunare_matrici() {
    int k = A.linii * 45;
    int l = A.coloane * 45;
    matrice C;

    setbkcolor(9);
    setcolor(0);
    settextstyle(9, 0, 1);

    if (engleza == false) {
        bgiout << "Numar de linii matrice 1:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Numar de coloane matrice 1:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);

        bgiout << "Numar de linii matrice 2:" << ' ' << B.linii;
        outstreamxy(900, 230);
        delay(200);
        bgiout << "Numar de coloane matrice 2:" << ' ' << B.coloane;
        outstreamxy(900, 250);
        delay(200);
    }
    else {
        bgiout << "Number of lines matrix 1:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Number of columns matrix 1:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);

        bgiout << "Number of lines matrix 2:" << ' ' << B.linii;
        outstreamxy(900, 230);
        delay(200);
        bgiout << "Number of columns matrix 2:" << ' ' << B.coloane;
        outstreamxy(900, 250);
        delay(200);
    }

    if (A.linii != B.linii || A.coloane != B.coloane) {
        setcolor(0);
        settextstyle(1, 0, 3);
        setbkcolor(9);
        if (engleza == false) {
            fout << "Adunarea nu este posibila!\n";
            outtextxy(500, 400, "Adunarea nu este posibila!");
        }
        else {
            fout << "Sum is not possible!\n";
            outtextxy(500, 400, "Sum is not possible!!");
        }
    }
    else {
        C.linii = A.linii;
        C.coloane = A.coloane;
        for (int a = 1; a <= A.linii; a++) {
            for (int b = 1; b <= A.coloane; b++) {
                C.elem[a][b] = A.elem[a][b] + B.elem[a][b];
            }
        }

        if (engleza == false) {
            fout << "Adunare matrici:\n";
        }
        else {
            fout << "Sum of the matrices:\n";
        }
        for (int a = 1; a <= A.linii; a++) {
            for (int b = 1; b <= A.coloane; b++) {
                fout << C.elem[a][b] << ' ';
            }
            fout << '\n';
        }
        fout << '\n';

        if (A.coloane > 3) {
            for (int j = 250 + 90; j < 250 + l + 90; j += 45) {
                for (int i = 450 + 45; i < 450 + k + 45; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << A.elem[(j - 250) / 45 - 1][(i - 450) / 45];
                    outstreamxy(i + 3, j + 8);
                    delay(250);
                }
            }

            line(450 + k + 45 + k / 2 - 60, 250 + 90 + l / 2, 450 + k + 45 + k / 2 - 40, 250 + 90 + l / 2);
            line(450 + k + 45 + k / 2 - 50, 250 + l / 2 + 90 - 10, 450 + k + 45 + k / 2 - 50, 250 + l / 2 + 90 + 10); // Semnul +

            for (int j = 250 + 90; j < 250 + l + 90; j += 45) {
                for (int i = 450 + 2 * k + 45 - 70; i < 450 + 3 * k + 45 - 70; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << B.elem[(j - 250) / 45 - 1][(i - 450 + 70 - 2 * k) / 45];
                    outstreamxy(i + 3, j + 8);
                    delay(250);
                }
            }

            line(450 + 3 * k + 45 + k / 2 - 115, 250 + 90 + l / 2 - 6, 450 + 3 * k + 45 + k / 2 - 85, 250 + 90 + l / 2 - 6);
            line(450 + 3 * k + 45 + k / 2 - 115, 250 + 90 + l / 2 + 6, 450 + 3 * k + 45 + k / 2 - 85, 250 + 90 + l / 2 + 6);  // Semnul =

            for (int j = 250 + 90; j < 250 + l + 90; j += 45) {
                for (int i = 450 + 4 * k + 45 - 120; i < 450 + 5 * k + 45 - 120; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << C.elem[(j - 250) / 45 - 1][(i - 450 + 120 - 4 * k) / 45];
                    outstreamxy(i + 3, j + 8);
                    delay(250);
                }
            }
        }
        else {
            for (int j = 250 + 90; j < 250 + l + 90; j += 45) {
                for (int i = 450 + 45; i < 450 + k + 45; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << A.elem[(j - 250) / 45 - 1][(i - 450) / 45];
                    outstreamxy(i + 3, j + 8);
                    delay(250);
                }
            }

            line(450 + k + 45 + k / 2 - 10, 250 + 90 + l / 2, 450 + k + 45 + k / 2 + 10, 250 + 90 + l / 2);
            line(450 + k + 45 + k / 2, 250 + l / 2 + 90 - 10, 450 + k + 45 + k / 2, 250 + l / 2 + 90 + 10); // Semnul +

            for (int j = 250 + 90; j < 250 + l + 90; j += 45) {
                for (int i = 450 + 2 * k + 45; i < 450 + 3 * k + 45; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << B.elem[(j - 250) / 45 - 1][(i - 450 - 2 * k) / 45];
                    outstreamxy(i + 3, j + 8);
                    delay(250);
                }
            }

            line(450 + 3 * k + 45 + k / 2 - 15, 250 + 90 + l / 2 - 6, 450 + 3 * k + 45 + k / 2 + 15, 250 + 90 + l / 2 - 6);
            line(450 + 3 * k + 45 + k / 2 - 15, 250 + 90 + l / 2 + 6, 450 + 3 * k + 45 + k / 2 + 15, 250 + 90 + l / 2 + 6);  // Semnul =

            for (int j = 250 + 90; j < 250 + l + 90; j += 45) {
                for (int i = 450 + 4 * k + 45; i < 450 + 5 * k + 45; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << C.elem[(j - 250) / 45 - 1][(i - 450 - 4 * k) / 45];
                    outstreamxy(i + 3, j + 8);
                    delay(250);
                }
            }
        }
    }
}


void scadere_matrici() {
    int k = A.linii * 45;
    int l = A.coloane * 45;
    matrice C;

    setbkcolor(9);
    setcolor(0);
    settextstyle(9, 0, 1);

    if (engleza == false) {
        bgiout << "Numar de linii matrice 1:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Numar de coloane matrice 1:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);

        bgiout << "Numar de linii matrice 2:" << ' ' << B.linii;
        outstreamxy(900, 230);
        delay(200);
        bgiout << "Numar de coloane matrice 2:" << ' ' << B.coloane;
        outstreamxy(900, 250);
        delay(200);
    }
    else {
        bgiout << "Number of lines matrix 1:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Number of columns matrix 1:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);

        bgiout << "Number of lines matrix 2:" << ' ' << B.linii;
        outstreamxy(900, 230);
        delay(200);
        bgiout << "Number of columns matrix 2:" << ' ' << B.coloane;
        outstreamxy(900, 250);
        delay(200);
    }

    if (A.linii != B.linii || A.coloane != B.coloane) {
        setcolor(0);
        settextstyle(1, 0, 3);
        setbkcolor(9);
        if (engleza == false) {
            fout << "Scaderea nu este posibila!\n";
            outtextxy(500, 400, "Scaderea nu este posibila!");
        }
        else {
            fout << "Subtraction is not possible!\n";
            outtextxy(500, 400, "Subtraction is not possible!");
        }
    }
    else {
        C.linii = A.linii;
        C.coloane = A.coloane;
        for (int a = 1; a <= A.linii; a++) {
            for (int b = 1; b <= A.coloane; b++) {
                C.elem[a][b] = A.elem[a][b] - B.elem[a][b];
            }
        }

        if (engleza == false) {
            fout << "Scadere matrici:\n";
        }
        else {
            fout << "Subtraction of the matrices:\n";
        }
        for (int a = 1; a <= A.linii; a++) {
            for (int b = 1; b <= A.coloane; b++) {
                fout << C.elem[a][b] << ' ';
            }
            fout << '\n';
        }
        fout << '\n';

        if (A.coloane > 3) {
            for (int j = 250 + 90; j < 250 + l + 90; j += 45) {
                for (int i = 450 + 45; i < 450 + k + 45; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << A.elem[(j - 250) / 45 - 1][(i - 450) / 45];
                    outstreamxy(i + 3, j + 8);
                    delay(250);
                }
            }

            line(450 + k + 45 + k / 2 - 60, 250 + 90 + l / 2, 450 + k + 45 + k / 2 - 40, 250 + 90 + l / 2);

            for (int j = 250 + 90; j < 250 + l + 90; j += 45) {
                for (int i = 450 + 2 * k + 45 - 70; i < 450 + 3 * k + 45 - 70; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << B.elem[(j - 250) / 45 - 1][(i - 450 + 70 - 2 * k) / 45];
                    outstreamxy(i + 3, j + 8);
                    delay(250);
                }
            }

            line(450 + 3 * k + 45 + k / 2 - 115, 250 + 90 + l / 2 - 6, 450 + 3 * k + 45 + k / 2 - 85, 250 + 90 + l / 2 - 6);
            line(450 + 3 * k + 45 + k / 2 - 115, 250 + 90 + l / 2 + 6, 450 + 3 * k + 45 + k / 2 - 85, 250 + 90 + l / 2 + 6);  // Semnul =

            for (int j = 250 + 90; j < 250 + l + 90; j += 45) {
                for (int i = 450 + 4 * k + 45 - 120; i < 450 + 5 * k + 45 - 120; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << C.elem[(j - 250) / 45 - 1][(i - 450 + 120 - 4 * k) / 45];
                    outstreamxy(i + 3, j + 8);
                    delay(250);
                }
            }
        }
        else {
            for (int j = 250 + 90; j < 250 + l + 90; j += 45) {
                for (int i = 450 + 45; i < 450 + k + 45; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << A.elem[(j - 250) / 45 - 1][(i - 450) / 45];
                    outstreamxy(i + 3, j + 8);
                    delay(250);
                }
            }

            line(450 + k + 45 + k / 2 - 10, 250 + 90 + l / 2, 450 + k + 45 + k / 2 + 10, 250 + 90 + l / 2);

            for (int j = 250 + 90; j < 250 + l + 90; j += 45) {
                for (int i = 450 + 2 * k + 45; i < 450 + 3 * k + 45; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << B.elem[(j - 250) / 45 - 1][(i - 450 - 2 * k) / 45];
                    outstreamxy(i + 3, j + 8);
                    delay(250);
                }
            }

            line(450 + 3 * k + 45 + k / 2 - 15, 250 + 90 + l / 2 - 6, 450 + 3 * k + 45 + k / 2 + 15, 250 + 90 + l / 2 - 6);
            line(450 + 3 * k + 45 + k / 2 - 15, 250 + 90 + l / 2 + 6, 450 + 3 * k + 45 + k / 2 + 15, 250 + 90 + l / 2 + 6);  // Semnul =

            for (int j = 250 + 90; j < 250 + l + 90; j += 45) {
                for (int i = 450 + 4 * k + 45; i < 450 + 5 * k + 45; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << C.elem[(j - 250) / 45 - 1][(i - 450 - 4 * k) / 45];
                    outstreamxy(i + 3, j + 8);
                    delay(250);
                }
            }
        }
    }
}


void inmultire_matrici() {
    setbkcolor(9);
    setcolor(0);
    settextstyle(9, 0, 1);
    matrice Put;

    if (engleza == false) {
        bgiout << "Numar de linii matrice 1:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Numar de coloane matrice 1:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);

        bgiout << "Numar de linii matrice 2:" << ' ' << B.linii;
        outstreamxy(900, 230);
        delay(200);
        bgiout << "Numar de coloane matrice 2:" << ' ' << B.coloane;
        outstreamxy(900, 250);
        delay(200);
    }
    else {
        bgiout << "Number of lines matrix 1:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Number of columns matrix 1:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);

        bgiout << "Number of lines matrix 2:" << ' ' << B.linii;
        outstreamxy(900, 230);
        delay(200);
        bgiout << "Number of columns matrix 2:" << ' ' << B.coloane;
        outstreamxy(900, 250);
        delay(200);
    }

    int l1 = A.linii * 45;
    int k1 = A.coloane * 45;
    int l2 = B.linii * 45;
    int k2 = B.coloane * 45;

    //Inmultimea este posibila daca numarul de coloane de la prima matrice este egal cu numarul de linii de la a doua martice
    if (A.coloane != B.linii) {
        setcolor(0);
        settextstyle(1, 0, 3);
        setbkcolor(9);
        if (engleza == false) {
            fout << "Inmultirea nu este posibila!\n";
            outtextxy(500, 400, "Inmultirea nu este posibila!");
        }
        else {
            fout << "Multiplication is not possible!\n";
            outtextxy(500, 400, "Multiplication is not possible!");
        }
    }
    else {
        Put.linii = A.linii;
        Put.coloane = B.coloane;
        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= B.coloane; j++) {
                for (int k = 1; k <= A.coloane; k++) {
                    Put.elem[i][j] += A.elem[i][k] * B.elem[k][j];
                }
            }
        }

        if (engleza == false) {
            fout << "Inmultire matrici:\n";
        }
        else {
            fout << "Multiplication of the matrices:\n";
        }
        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= B.coloane; j++) {
                fout << Put.elem[i][j] << ' ';
            }
            fout << '\n';
        }
        fout << '\n';

        if (B.coloane + 2 <= A.coloane) {
            for (int j = 250 + 90; j < 250 + l1 + 90; j += 45) {
                for (int i = 450 + 45; i < 450 + k1 + 45; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << A.elem[(j - 250) / 45 - 1][(i - 450) / 45];
                    outstreamxy(i + 8, j + 8);
                    delay(250);
                }
            }

            line(550 + k2 + 45 + k2 / 2 - 10, 250 + l1 / 2 + 90 - 10, 550 + k2 + 45 + k2 / 2 + 10, 250 + l1 / 2 + 90 + 10);
            line(550 + k2 + 45 + k2 / 2 - 10, 250 + l1 / 2 + 90 + 10, 550 + k2 + 45 + k2 / 2 + 10, 250 + l1 / 2 + 90 - 10);// Semnul X
            delay(300);

            for (int j = 250 + 90; j < 250 + l2 + 90; j += 45) {
                for (int i = 550 + 2 * k2 + 45; i < 550 + 3 * k2 + 45; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << B.elem[(j - 250) / 45 - 1][(i - 550 - 2 * k2) / 45];
                    outstreamxy(i + 8, j + 8);
                    delay(250);
                }
            }

            line(550 + 3 * k2 + 45 + k2 / 2 - 15, 250 + 90 + l1 / 2 - 6, 550 + 3 * k2 + 45 + k2 / 2 + 15, 250 + 90 + l1 / 2 - 6);
            line(550 + 3 * k2 + 45 + k2 / 2 - 15, 250 + 90 + l1 / 2 + 6, 550 + 3 * k2 + 45 + k2 / 2 + 15, 250 + 90 + l1 / 2 + 6);  // Semnul =
            delay(300);

            for (int j = 250 + 90; j < 250 + l1 + 90; j += 45) {
                for (int i = 550 + 4 * k2 + 45; i < 550 + 5 * k2 + 45; i += 45) {
                    rectangle(i, j, i + 45, j + 45);
                    bgiout << fixed << setprecision(0) << Put.elem[(j - 250) / 45 - 1][(i - 550 - 4 * k2) / 45];
                    outstreamxy(i + 3, j + 8);
                    delay(250);
                }
            }
        }
        else {
            if (A.coloane < 4 || B.coloane < 4) {
                for (int j = 250 + 90; j < 250 + l1 + 90; j += 45) {
                    for (int i = 450 + 45; i < 450 + k1 + 45; i += 45) {
                        rectangle(i, j, i + 45, j + 45);
                        bgiout << fixed << setprecision(0) << A.elem[(j - 250) / 45 - 1][(i - 450) / 45];
                        outstreamxy(i + 8, j + 8);
                        delay(250);
                    }
                }

                line(450 + k2 + 45 + k2 / 2 - 10, 250 + l1 / 2 + 90 - 10, 450 + k2 + 45 + k2 / 2 + 10, 250 + l1 / 2 + 90 + 10);
                line(450 + k2 + 45 + k2 / 2 - 10, 250 + l1 / 2 + 90 + 10, 450 + k2 + 45 + k2 / 2 + 10, 250 + l1 / 2 + 90 - 10);// Semnul X
                delay(300);

                for (int j = 250 + 90; j < 250 + l2 + 90; j += 45) {
                    for (int i = 450 + 2 * k2 + 45; i < 450 + 3 * k2 + 45; i += 45) {
                        rectangle(i, j, i + 45, j + 45);
                        bgiout << fixed << setprecision(0) << B.elem[(j - 250) / 45 - 1][(i - 450 - 2 * k2) / 45];
                        outstreamxy(i + 8, j + 8);
                        delay(250);
                    }
                }

                line(450 + 3 * k2 + 45 + k2 / 2 - 15, 250 + 90 + l1 / 2 - 6, 450 + 3 * k2 + 45 + k2 / 2 + 15, 250 + 90 + l1 / 2 - 6);
                line(450 + 3 * k2 + 45 + k2 / 2 - 15, 250 + 90 + l1 / 2 + 6, 450 + 3 * k2 + 45 + k2 / 2 + 15, 250 + 90 + l1 / 2 + 6);  // Semnul =
                delay(300);

                for (int j = 250 + 90; j < 250 + l1 + 90; j += 45) {
                    for (int i = 450 + 4 * k2 + 45; i < 450 + 5 * k2 + 45; i += 45) {
                        rectangle(i, j, i + 45, j + 45);
                        bgiout << fixed << setprecision(0) << Put.elem[(j - 250) / 45 - 1][(i - 450 - 4 * k2) / 45];
                        outstreamxy(i + 3, j + 8);
                        delay(250);
                    }
                }
            }
            else {
                for (int j = 250 + 90; j < 250 + l1 + 90; j += 45) {
                    for (int i = 450 + 45; i < 450 + k1 + 45; i += 45) {
                        rectangle(i, j, i + 45, j + 45);
                        bgiout << fixed << setprecision(0) << A.elem[(j - 250) / 45 - 1][(i - 450) / 45];
                        outstreamxy(i + 8, j + 8);
                        delay(250);
                    }
                }

                line(450 + k2 + 45 + k2 / 2 - 90, 250 + l1 / 2 + 90 - 10, 450 + k2 + 45 + k2 / 2 - 70, 250 + l1 / 2 + 90 + 10);
                line(450 + k2 + 45 + k2 / 2 - 90, 250 + l1 / 2 + 90 + 10, 450 + k2 + 45 + k2 / 2 - 70, 250 + l1 / 2 + 90 - 10);// Semnul X
                delay(300);

                for (int j = 250 + 90; j < 250 + l2 + 90; j += 45) {
                    for (int i = 450 + 2 * k2 + 45 - 120; i < 450 + 3 * k2 + 45 - 120; i += 45) {
                        rectangle(i, j, i + 45, j + 45);
                        bgiout << fixed << setprecision(0) << B.elem[(j - 250) / 45 - 1][(i - 450 + 120 - 2 * k2) / 45];
                        outstreamxy(i + 8, j + 8);
                        delay(250);
                    }
                }

                line(450 + 3 * k2 + 45 + k2 / 2 - 135, 250 + 90 + l1 / 2 - 6, 450 + 3 * k2 + 45 + k2 / 2 - 115, 250 + 90 + l1 / 2 - 6);
                line(450 + 3 * k2 + 45 + k2 / 2 - 135, 250 + 90 + l1 / 2 + 6, 450 + 3 * k2 + 45 + k2 / 2 - 115, 250 + 90 + l1 / 2 + 6);  // Semnul =
                delay(300);

                for (int j = 250 + 90; j < 250 + l1 + 90; j += 45) {
                    for (int i = 450 + 4 * k2 + 45 - 160; i < 450 + 5 * k2 + 45 - 160; i += 45) {
                        rectangle(i, j, i + 45, j + 45);
                        bgiout << fixed << setprecision(0) << Put.elem[(j - 250) / 45 - 1][(i - 450 + 160 - 4 * k2) / 45];
                        outstreamxy(i + 3, j + 8);
                        delay(250);
                    }
                }
            }
        }
    }
}


void inmultire_matrice_cu_scalar() {
    C.linii = A.linii;
    C.coloane = A.coloane;
    matrice C;

    for (int i = 1; i <= A.linii; i++) {
        for (int j = 1; j <= A.coloane; j++) {
            C.elem[i][j] = A.elem[i][j] * scalar;
        }
    }

    if (engleza == false) {
        fout << "Inmultire matrice cu scalarul " << scalar << ":\n";
    }
    else {
        fout << "Multiplication of the matrix with the scalar " << scalar << ":\n";
    }
    for (int i = 1; i <= A.linii; i++) {
        for (int j = 1; j <= A.coloane; j++) {
            fout << C.elem[i][j] << ' ';
        }
        fout << '\n';
    }
    fout << '\n';

    setcolor(0);
    int k = A.coloane * 60;
    int l = A.linii * 60;

    setbkcolor(9);
    setcolor(0);
    settextstyle(9, 0, 1);

    if (engleza == false) {
        bgiout << "Numar de linii:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Numar de coloane:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);
    }
    else {
        bgiout << "Number of lines:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Number of columns:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);
    }

    for (int j = 200 + 120; j < 200 + l + 120; j += 60) {
        for (int i = 450 + 60; i < 450 + k + 60; i += 60) {
            rectangle(i, j, i + 60, j + 60);
            bgiout << setprecision(0) << fixed << A.elem[(j - 200) / 60 - 1][(i - 450) / 60];
            outstreamxy(i + 8, j + 15);
            delay(250);
        }
    }

    line(450 + k + 50 + k / 2 - 25, 250 + l / 2 + 80 - 10, 450 + k + 50 + k / 2, 250 + l / 2 + 80 + 10);
    line(450 + k + 50 + k / 2 - 25, 250 + l / 2 + 80 + 10, 450 + k + 50 + k / 2, 250 + l / 2 + 80 - 10);
    delay(300);

    rectangle(450 + k + 23 + k / 2 + 35 + 3, 250 + 80 + l / 2 - 30, 450 + k + 35 + k / 2 + 83, 250 + 80 + l / 2 + 30);
    delay(300);

    bgiout << scalar;
    outstreamxy(523 + k + k / 2 + 12, 250 + 80 + l / 2 - 6);
    delay(300);

    line(450 + 2 * k + 65, 250 + 80 + l / 2 - 6, 105 + 450 + 2 * k + 50 - 70, 250 + 80 + l / 2 - 6);
    line(450 + 2 * k + 65, 250 + 80 + l / 2 + 6, 105 + 450 + 2 * k + 50 - 70, 250 + 80 + l / 2 + 6); //=
    delay(300);

    for (int j = 200 + 120; j < 200 + l + 120; j += 60) {
        for (int i = 450 + 2 * k + 60 + 40; i < 450 + 3 * k + 60 + 40; i += 60) {
            rectangle(i, j, i + 60, j + 60);
            bgiout << setprecision(0) << fixed << C.elem[(j - 200) / 60 - 1][(i - 450 - 40 - 2 * k) / 60];
            outstreamxy(i + 8, j + 8);
            delay(250);
        }
    }
}


void impartire_matrice_cu_scalar() {
    setbkcolor(9);
    setcolor(0);
    settextstyle(9, 0, 1);

    if (engleza == false) {
        bgiout << "Numar de linii:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Numar de coloane:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);
    }
    else {
        bgiout << "Number of lines:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Number of columns:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);
    }

    if (scalar == 0) {
        setcolor(0);
        settextstyle(1, 0, 3);
        setbkcolor(9);
        if (engleza == false) {
            fout << "Impartirea la 0 nu este posibila!\n";
            outtextxy(500, 400, "Impartirea la 0 nu este posibila!");
        }
        else {
            fout << "Division by 0 is not possible!\n";
            outtextxy(500, 400, "Division by 0 is not possible!");
        }
    }
    else {
        matrice C;
        C.linii = A.linii;
        C.coloane = A.coloane;

        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                C.elem[i][j] = A.elem[i][j] / scalar;
            }
        }

        if (engleza == false) {
            fout << "Impartire matrice cu scalarul " << scalar << ":\n";
        }
        else {
            fout << "Dividing matrix by scalar " << scalar << ":\n";
        }
        for (int a = 1; a <= C.linii; a++) {
            for (int b = 1; b <= C.coloane; b++) {
                fout << C.elem[a][b] << ' ';
            }
            fout << '\n';
        }
        fout << '\n';

        setcolor(0);
        int k = A.coloane * 60;
        int l = A.linii * 60;

        for (int j = 200 + 120; j < 200 + l + 120; j += 60) {
            for (int i = 450 + 60; i < 450 + k + 60; i += 60) {
                rectangle(i, j, i + 60, j + 60);
                bgiout << setprecision(0) << fixed << A.elem[(j - 200) / 60 - 1][(i - 450) / 60];
                outstreamxy(i + 8, j + 15);
                delay(250);
            }
        }

        line(450 + k + 50 + k / 2 - 25, 250 + l / 2 + 80 - 10, 450 + k + 50 + k / 2, 250 + l / 2 + 80 + 10);
        delay(300);

        rectangle(450 + k + 23 + k / 2 + 35 + 3, 250 + 80 + l / 2 - 30, 450 + k + 35 + k / 2 + 83, 250 + 80 + l / 2 + 30);
        delay(300);

        bgiout << scalar;
        outstreamxy(523 + k + k / 2 + 12, 250 + 80 + l / 2 - 6);
        delay(300);

        line(105 + 450 + 2 * k + 50 - 95, 250 + 80 + l / 2 - 6, 105 + 450 + 2 * k + 50 - 75, 250 + 80 + l / 2 - 6);
        line(105 + 450 + 2 * k + 50 - 95, 250 + 80 + l / 2 + 6, 105 + 450 + 2 * k + 50 - 75, 250 + 80 + l / 2 + 6); //=
        delay(300);

        for (int j = 200 + 120; j < 200 + l + 120; j += 60) {
            for (int i = 450 + 2 * k + 60 + 40; i < 450 + 3 * k + 60 + 40; i += 60) {
                rectangle(i, j, i + 60, j + 60);
                bgiout << setprecision(2) << fixed << C.elem[(j - 200) / 60 - 1][(i - 450 - 40 - 2 * k) / 60];
                outstreamxy(i + 8, j + 8);
                delay(250);
            }
        }
    }
}


void transpusa() {
    matrice At;
    At.linii = A.coloane;
    At.coloane = A.linii;

    setbkcolor(9);
    setcolor(0);
    settextstyle(9, 0, 1);

    if (engleza == false) {
        bgiout << "Numar de linii:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Numar de coloane:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);
    }
    else {
        bgiout << "Number of lines:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Number of columns:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);
    }

    for (int j = 1; j <= A.coloane; j++) {
        for (int i = 1; i <= A.linii; i++) {
            At.elem[j][i] = A.elem[i][j];
        }
    }

    if (engleza == false) {
        fout << "Transpusa matricei:\n";
    }
    else {
        fout << "Transpose of the matrix:\n";
    }
    for (int j = 1; j <= A.coloane; j++) {
        for (int i = 1; i <= A.linii; i++) {
            fout << At.elem[j][i] << ' ';
        }
        fout << '\n';
    }
    fout << '\n';

    setcolor(0);
    int k = A.coloane * 60;
    int l = A.linii * 60;

    if (A.linii + 2 <= A.coloane) {
        for (int j = 200 + 120; j < 200 + l + 120; j += 60) {
            for (int i = 450 + 60; i < 450 + k + 60; i += 60) {
                rectangle(i, j, i + 60, j + 60);
                bgiout << fixed << setprecision(0) << A.elem[(j - 200) / 60 - 1][(i - 450) / 60];
                outstreamxy(i + 8, j + 15);
                delay(250);
            }
        }

        rectangle(500 + k + 60 + 15, 250 + 20, 500 + k + 60 + 40, 250 + 45);
        bgiout << "T";
        outstreamxy(575 + k + 5.5, 270 + 3.5);
        delay(300);

        line(500 + k + 60 + k / 2 - 15, 200 + 120 + l / 2 - 6, 500 + k + 60 + k / 2 + 15, 200 + 120 + l / 2 - 6);
        line(500 + k + 60 + k / 2 - 15, 200 + 120 + l / 2 + 6, 500 + k + 60 + k / 2 + 15, 200 + 120 + l / 2 + 6);
        delay(300);

        if (k <= l) {
            for (int j = 200 + 120; j < 200 + k + 120; j += 60) {
                for (int i = 650 + 2 * l + 60; i < 650 + 3 * l + 60; i += 60) {
                    rectangle(i, j, i + 60, j + 60);
                    bgiout << fixed << setprecision(0) << At.elem[(j - 200) / 60 - 1][(i - 650 - 2 * l) / 60];
                    outstreamxy(i + 8, j + 15);
                    delay(250);
                }
            }
        }
        else {
            for (int j = 200 + 120; j < 200 + k + 120; j += 60) {
                for (int i = 650 + 2 * l + 60 + 40; i < 650 + 3 * l + 60 + 40; i += 60) {
                    rectangle(i, j, i + 60, j + 60);
                    bgiout << fixed << setprecision(0) << At.elem[(j - 200) / 60 - 1][(i - 650 - 2 * l - 40) / 60];
                    outstreamxy(i + 8, j + 15);
                    delay(250);
                }
            }
        }
    }
    else {
        for (int j = 200 + 120; j < 200 + l + 120; j += 60) {
            for (int i = 450 + 60; i < 450 + k + 60; i += 60) {
                rectangle(i, j, i + 60, j + 60);
                bgiout << fixed << setprecision(0) << A.elem[(j - 200) / 60 - 1][(i - 450) / 60];
                outstreamxy(i + 8, j + 15);
                delay(250);
            }
        }

        rectangle(450 + k + 60 + 15, 250 + 20, 450 + k + 60 + 40, 250 + 45);
        bgiout << "T";
        outstreamxy(525 + k + 5.5, 270 + 3.5);
        delay(300);

        line(450 + k + 60 + k / 2 - 15, 200 + 120 + l / 2 - 6, 450 + k + 60 + k / 2 + 15, 200 + 120 + l / 2 - 6);
        line(450 + k + 60 + k / 2 - 15, 200 + 120 + l / 2 + 6, 450 + k + 60 + k / 2 + 15, 200 + 120 + l / 2 + 6);
        delay(300);

        if (k <= l) {
            for (int j = 200 + 120; j < 200 + k + 120; j += 60) {
                for (int i = 450 + 2 * l + 60; i < 450 + 3 * l + 60; i += 60) {
                    rectangle(i, j, i + 60, j + 60);
                    bgiout << fixed << setprecision(0) << At.elem[(j - 200) / 60 - 1][(i - 450 - 2 * l) / 60];
                    outstreamxy(i + 8, j + 15);
                    delay(250);
                }
            }
        }
        else {
            for (int j = 200 + 120; j < 200 + k + 120; j += 60) {
                for (int i = 450 + 2 * l + 60 + 40; i < 450 + 3 * l + 60 + 40; i += 60) {
                    rectangle(i, j, i + 60, j + 60);
                    bgiout << fixed << setprecision(0) << At.elem[(j - 200) / 60 - 1][(i - 450 - 2 * l - 40) / 60];
                    outstreamxy(i + 8, j + 15);
                    delay(250);
                }
            }
        }
    }
}


void ridicare_la_putere() {
    setbkcolor(9);
    setcolor(0);
    settextstyle(9, 0, 1);
    matrice Ap;

    if (engleza == false) {
        bgiout << "Numar de linii:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Numar de coloane:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);
    }
    else {
        bgiout << "Number of lines:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Number of columns:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);
    }

    if (A.linii != A.coloane) {
        setcolor(0);
        settextstyle(1, 0, 3);
        setbkcolor(9);
        if (engleza == false) {
            fout << "Ridicarea la putere nu este posibila!\n\n";
            outtextxy(500, 400, "Ridicarea la putere nu este posibila!");
        }
        else {
            fout << "Raising to power is not possible!\n\n";
            outtextxy(500, 400, "Raising to power is not possible!");
        }
    }
    else {
        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                Ap.elem[i][j] = (i == j);
            }
        }

        for (int q = 0; q < putere; q++) {
            for (int i = 1; i <= A.linii; i++) {
                for (int j = 1; j <= A.coloane; j++) {
                    C.elem[i][j] = 0;
                    for (int k = 1; k <= A.coloane; k++) {
                        C.elem[i][j] = C.elem[i][j] + Ap.elem[i][k] * A.elem[k][j];
                    }
                }
            }
            for (int i = 1; i <= A.linii; i++) {
                for (int j = 1; j <= A.coloane; j++) {
                    Ap.elem[i][j] = C.elem[i][j];
                }
            }
        }

        if (engleza == false) {
            fout << "Matricea ridicata la puterea " << putere << ":\n";
        }
        else {
            fout << "Matrix raised to the power " << putere << ":\n";
        }
        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                fout << Ap.elem[i][j] << ' ';
            }
            fout << '\n';
        }
        fout << '\n';

        int k = A.linii * 60;
        int l = A.coloane * 60;
        setbkcolor(9);
        setcolor(0);
        settextstyle(9, 0, 1);

        for (int j = 250 + 60; j < 250 + l + 60; j += 60) {
            for (int i = 450 + 60; i < 450 + k + 60; i += 60) {
                rectangle(i, j, i + 60, j + 60);
                bgiout << fixed << setprecision(0) << A.elem[(j - 250) / 60][(i - 450) / 60];
                outstreamxy(i + 16, j + 16);
                delay(250);
            }
        }

        rectangle(450 + k + 50 + 15, 250 + 20, 450 + k + 50 + 45, 250 + 50);
        bgiout << putere;
        outstreamxy(515 + k + 5.5, 270 + 5.5);
        delay(300);

        line(450 + k + 50 + k / 2 - 15, 250 + 60 + l / 2 - 6, 450 + k + 50 + k / 2 + 15, 250 + 60 + l / 2 - 6);
        line(450 + k + 50 + k / 2 - 15, 250 + 60 + l / 2 + 6, 450 + k + 50 + k / 2 + 15, 250 + 60 + l / 2 + 6);
        delay(300);

        for (int j = 250 + 60; j < 250 + l + 60; j += 60) {
            for (int i = 450 + 2 * k + 60; i < 450 + 3 * k + 60; i += 60) {
                rectangle(i, j, i + 60, j + 60);
                bgiout << fixed << setprecision(0) << Ap.elem[(j - 250) / 60][(i - 450 - (2 * k)) / 60];
                outstreamxy(i + 4, j + 16);
                delay(250);
            }
        }
    }
}


void inversa() {
    int k = A.linii * 60;
    int l = A.coloane * 60;
    matrice Aux = A;

    setbkcolor(9);
    setcolor(0);
    settextstyle(9, 0, 1);

    if (engleza == false) {
        bgiout << "Numar de linii:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Numar de coloane:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);
    }
    else {
        bgiout << "Number of lines:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Number of columns:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);

    }

    if (A.linii != A.coloane) {
        setcolor(0);
        settextstyle(1, 0, 3);
        setbkcolor(9);
        if (engleza == false) {
            fout << "Nu se poate calcula matricea inversa!\n\n";
            outtextxy(500, 400, "Nu se poate calcula matricea inversa!");
        }
        else {
            fout << "Inverse of the matrix can't be calculated!\n\n";
            outtextxy(500, 400, "Inverse of the matrix can't be calculated!");
        }
    }
    else {
        for (int i = 1; i <= Aux.linii; i++) {
            for (int j = Aux.linii + 1; j <= 2 * Aux.linii; j++) {
                if (i == (j - Aux.linii)) {
                    Aux.elem[i][j] = 1;
                }
                else {
                    Aux.elem[i][j] = 0;
                }
            }
        }

        for (int i = 1; (i <= Aux.linii) && (d != 0); i++) {
            for (int j = i; (j <= Aux.linii) && (Aux.elem[j][i] == 0); j++) {
                if (j > Aux.linii) {
                    d = 0;
                }
                else if (j > i) {
                    for (int z = 1; z <= 2 * Aux.linii; z++) {
                        Aux.elem[i][z] += Aux.elem[j][z];
                    }
                }
            }
            if (Aux.elem[i][i] != 1) {
                for (int z = 2 * Aux.linii; z >= 1; z--) {
                    Aux.elem[i][z] /= Aux.elem[i][i];
                }
            }
            for (int j = 1; j <= Aux.linii; j++) {
                if (j != i) {
                    for (int z = 2 * Aux.linii; z >= i; z--) {
                        Aux.elem[j][z] -= Aux.elem[j][i] * Aux.elem[i][z];
                    }
                }
            }
        }

        if (d == 0) {
            setcolor(0);
            settextstyle(1, 0, 3);
            setbkcolor(9);
            if (engleza == false) {
                fout << "Matricea nu este inversabila!\n\n";
                outtextxy(500, 400, "Matricea nu este inversabila!");
            }
            else {
                fout << "Matrix is not invertible!\n\n";
                outtextxy(500, 400, "Matrix is not invertible!");
            }
        }
        else {
            if (engleza == false) {
                fout << "Matricea inversa:\n";
            }
            else {
                fout << "Inverse of the matrix:\n";
            }
            for (int i = 1; i <= A.linii; i++) {
                for (int j = 1; j <= A.linii; j++) {
                    fout << fixed << setprecision(2) << Aux.elem[i][A.linii + j] << " ";
                }
                fout << '\n';
            }
            fout << '\n';

            setbkcolor(9);
            setcolor(0);
            settextstyle(9, 0, 1);

            for (int j = 250 + 60; j < 250 + l + 60; j += 60) {
                for (int i = 450 + 60; i < 450 + k + 60; i += 60) {
                    rectangle(i, j, i + 60, j + 60);
                    bgiout << fixed << setprecision(0) << A.elem[(j - 250) / 60][(i - 450) / 60];
                    outstreamxy(i + 16, j + 16);
                    delay(250);
                }
            }

            rectangle(450 + k + 50 + 15, 250 + 20, 450 + k + 50 + 45, 250 + 50);
            bgiout << "-1";
            outstreamxy(515 + k + 5.5, 270 + 5.5);
            delay(300);

            line(450 + k + 50 + k / 2 - 15, 250 + 60 + l / 2 - 6, 450 + k + 50 + k / 2 + 15, 250 + 60 + l / 2 - 6);
            line(450 + k + 50 + k / 2 - 15, 250 + 60 + l / 2 + 6, 450 + k + 50 + k / 2 + 15, 250 + 60 + l / 2 + 6);
            delay(300);

            for (int j = 250 + 60; j < 250 + l + 60; j += 60) {
                for (int i = 450 + 2 * k + 60; i < 450 + 3 * k + 60; i += 60) {
                    rectangle(i, j, i + 60, j + 60);
                    bgiout << setprecision(2) << fixed << Aux.elem[(j - 250) / 60][(k + i - 450 - (2 * k)) / 60];
                    outstreamxy(i + 4, j + 16);
                    delay(250);
                }
            }
        }
    }
}


void diagonala_principala() {
    int k = A.linii * 45;
    int l = A.coloane * 45;

    setbkcolor(9);
    setcolor(0);
    settextstyle(9, 0, 1);

    if (engleza == false) {
        bgiout << "Numar de linii:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Numar de coloane:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);
    }
    else {
        bgiout << "Number of lines:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Number of columns:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);

    }

    if (A.linii != A.coloane) {
        setcolor(0);
        settextstyle(1, 0, 3);
        setbkcolor(9);
        if (engleza == false) {
            fout << "Nu se pot efectua operatii!\n\n";
            bgiout << "Nu se pot efectua operatii!\n";
        }
        else {
            fout << "No operations can be performed!\n\n";
            bgiout << "No operations can be performed!\n";
        }
        outstreamxy(500, 400);
    }
    else {
        long long sdiag = 0, ssub = 0, sdeas = 0;
        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                if (i == j) {
                    sdiag += A.elem[i][j];
                }
            }
        }

        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                if (i > j) {
                    ssub += A.elem[i][j];
                }
            }
        }

        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                if (i < j) {
                    sdeas += A.elem[i][j];
                }
            }
        }

        long long pdiag = 1, psub = 1, pdeas = 1;
        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                if (i == j) {
                    pdiag *= A.elem[i][j];
                }
            }
        }

        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                if (i > j) {
                    psub *= A.elem[i][j];
                }
            }
        }

        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                if (i < j) {
                    pdeas *= A.elem[i][j];
                }
            }
        }

        for (int j = 180 + 90 + 10; j < 180 + l + 90 + 10; j += 45) {
            for (int i = 450 + 45; i < 450 + k + 45; i += 45) {
                setcolor(0);
                rectangle(i, j, i + 45, j + 45);

                if ((j - 180) / 45 - 1 == (i - 450) / 45) {
                    setbkcolor(1);
                    setcolor(15);
                    bgiout << setprecision(0) << fixed << A.elem[(j - 180 - 10) / 45 - 1][(i - 450) / 45];
                    outstreamxy(i + 8, j + 8);
                    delay(250);
                }
                else if ((j - 180) / 45 - 1 > (i - 450) / 45) {
                    setbkcolor(4);
                    setcolor(15);
                    bgiout << setprecision(0) << fixed << A.elem[(j - 180 - 10) / 45 - 1][(i - 450) / 45];
                    outstreamxy(i + 8, j + 8);
                    delay(250);
                }
                else {
                    setbkcolor(3);
                    setcolor(15);
                    bgiout << setprecision(0) << fixed << A.elem[(j - 180 - 10) / 45 - 1][(i - 450) / 45];
                    outstreamxy(i + 8, j + 8);
                    delay(250);
                }
            }
        }

        if (engleza == false) {
            fout << "Suma elementelor de pe diagonala principala este" << ' ' << sdiag << ".\n";
            fout << "Suma elementelor de deasupra diagonalei principale este" << ' ' << sdeas << ".\n";
            fout << "Suma elementelor de sub diagonala principala este" << ' ' << ssub << ".\n";
            fout << "Produsul elementelor de pe diagonala principala este" << ' ' << pdiag << ".\n";
            fout << "Produsul elementelor de deasupra diagonalei principale este" << ' ' << pdeas << ".\n";
            fout << "Produsul elementelor de sub diagonala principala este" << ' ' << psub << ".\n";
            fout << '\n';

            setbkcolor(1);
            bgiout << "Suma elementelor de pe diagonala principala este" << ' ' << sdiag << ".";
            outstreamxy(485, 480);
            delay(200);

            setbkcolor(3);
            bgiout << "Suma elementelor de deasupra diagonalei principale este" << ' ' << sdeas << ".";
            outstreamxy(485, 500);
            delay(200);

            setbkcolor(4);
            bgiout << "Suma elementelor de sub diagonala principala este" << ' ' << ssub << ".";
            outstreamxy(485, 520);
            delay(200);

            setbkcolor(1);
            bgiout << "Produsul elementelor de pe diagonala principala este" << ' ' << pdiag << ".";
            outstreamxy(485, 540);
            delay(200);

            setbkcolor(3);
            bgiout << "Produsul elementelor de deasupra diagonalei principale este" << ' ' << pdeas << ".";
            outstreamxy(485, 560);
            delay(200);

            setbkcolor(4);
            bgiout << "Produsul elementelor de sub diagonala principala este" << ' ' << psub << ".";
            outstreamxy(485, 580);
            delay(200);
        }
        else {
            fout << "Sum of the elements on the main diagonal is" << ' ' << sdiag << ".\n";
            fout << "Sum of the elements above the main diagonal is" << ' ' << sdeas << ".\n";
            fout << "Sum of the elements below the main diagonal is" << ' ' << ssub << ".\n";
            fout << "Product of the elements on the main diagonal is" << ' ' << pdiag << ".\n";
            fout << "Product of the elements above the main diagonal is" << ' ' << pdeas << ".\n";
            fout << "Product of the elements below the main diagonal is" << ' ' << psub << ".\n";
            fout << '\n';

            setbkcolor(1);
            bgiout << "Sum of the elements on the main diagonal is" << ' ' << sdiag << ".";
            outstreamxy(485, 480);
            delay(200);

            setbkcolor(3);
            bgiout << "Sum of the elements above the main diagonal is" << ' ' << sdeas << ".";
            outstreamxy(485, 500);
            delay(200);

            setbkcolor(4);
            bgiout << "Sum of the elements below the main diagonal is" << ' ' << ssub << ".";
            outstreamxy(485, 520);
            delay(200);

            setbkcolor(1);
            bgiout << "Product of the elements on the main diagonal is" << ' ' << pdiag << ".";
            outstreamxy(485, 540);
            delay(200);

            setbkcolor(3);
            bgiout << "Product of the elements above the main diagonal is" << ' ' << pdeas << ".";
            outstreamxy(485, 560);
            delay(200);

            setbkcolor(4);
            bgiout << "Product of the elements below the main diagonal is" << ' ' << psub << ".";
            outstreamxy(485, 580);
            delay(200);
        }
    }
}


void diagonala_secundara() {
    int k = A.linii * 45;
    int l = A.coloane * 45;

    setbkcolor(9);
    setcolor(0);
    settextstyle(9, 0, 1);

    if (engleza == false) {
        bgiout << "Numar de linii:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Numar de coloane:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);
    }
    else {
        bgiout << "Number of lines:" << ' ' << A.linii;
        outstreamxy(450, 230);
        delay(200);
        bgiout << "Number of columns:" << ' ' << A.coloane;
        outstreamxy(450, 250);
        delay(200);
    }

    if (A.linii != A.coloane) {
        setcolor(0);
        settextstyle(1, 0, 3);
        setbkcolor(9);
        if (engleza == false) {
            fout << "Nu se pot efectua operatii!\n\n";
            bgiout << "Nu se pot efectua operatii!\n";
        }
        else {
            fout << "No operations can be performed!\n\n";
            bgiout << "No operations can be performed!\n";
        }
        outstreamxy(500, 400);
    }
    else {
        long long sumdiag = 0, sumdeas = 0, sumsub = 0;
        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                if (i + j == A.linii + 1) {
                    sumdiag += A.elem[i][j];
                }
            }
        }

        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                if (i + j > A.linii + 1) {
                    sumsub += A.elem[i][j];
                }
            }
        }

        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                if (i + j < A.linii + 1) {
                    sumdeas += A.elem[i][j];
                }
            }
        }

        long long proddiag = 1, prodsub = 1, proddeas = 1;
        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                if (i + j == A.linii + 1) {
                    proddiag *= A.elem[i][j];
                }
            }
        }

        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                if (i + j > A.linii + 1) {
                    prodsub *= A.elem[i][j];
                }
            }
        }

        for (int i = 1; i <= A.linii; i++) {
            for (int j = 1; j <= A.coloane; j++) {
                if (i + j < A.linii + 1) {
                    proddeas *= A.elem[i][j];
                }
            }
        }

        for (int j = 180 + 90 + 10; j < 180 + l + 90 + 10; j += 45) {
            for (int i = 450 + 45; i < 450 + k + 45; i += 45) {
                setcolor(0);
                rectangle(i, j, i + 45, j + 45);

                if ((j - 180) / 45 - 1 + (i - 450) / 45 == 1 + A.linii) {
                    setbkcolor(1);
                    setcolor(15);
                    bgiout << setprecision(0) << fixed << A.elem[(j - 180 - 10) / 45 - 1][(i - 450) / 45];
                    outstreamxy(i + 8, j + 8);
                    delay(250);
                }
                else if ((j - 180) / 45 - 1 + (i - 450) / 45 > A.linii + 1) {
                    setbkcolor(4);
                    setcolor(15);
                    bgiout << setprecision(0) << fixed << A.elem[(j - 180 - 10) / 45 - 1][(i - 450) / 45];
                    outstreamxy(i + 8, j + 8);
                    delay(250);
                }
                else {
                    setbkcolor(3);
                    setcolor(15);
                    bgiout << setprecision(0) << fixed << A.elem[(j - 180 - 10) / 45 - 1][(i - 450) / 45];
                    outstreamxy(i + 8, j + 8);
                    delay(250);
                }
            }
        }

        if (engleza == false) {
            fout << "Suma elementelor de pe diagonala secundara este" << ' ' << sumdiag << ".\n";
            fout << "Suma elementelor de deasupra diagonalei secundare este" << ' ' << sumdeas << ".\n";
            fout << "Suma elementelor de sub diagonala secundara  este" << ' ' << sumsub << ".\n";
            fout << "Produsul elementelor de pe diagonala secundara  este" << ' ' << proddiag << ".\n";
            fout << "Produsul elementelor de deasupra diagonalei secundare este" << ' ' << proddeas << ".\n";
            fout << "Produsul elementelor de sub diagonala secundara  este" << ' ' << prodsub << ".\n";
            fout << '\n';

            setbkcolor(1);
            bgiout << "Suma elementelor de pe diagonala secundara este" << ' ' << sumdiag << ".";
            outstreamxy(485, 480);
            delay(200);

            setbkcolor(3);
            bgiout << "Suma elementelor de deasupra diagonalei secundare este" << ' ' << sumdeas << ".";
            outstreamxy(485, 500);
            delay(200);

            setbkcolor(4);
            bgiout << "Suma elementelor de sub diagonala secundara  este" << ' ' << sumsub << ".";
            outstreamxy(485, 520);
            delay(200);

            setbkcolor(1);
            bgiout << "Produsul elementelor de pe diagonala secundara  este" << ' ' << proddiag << ".";
            outstreamxy(485, 540);
            delay(200);

            setbkcolor(3);
            bgiout << "Produsul elementelor de deasupra diagonalei secundare este" << ' ' << proddeas << ".";
            outstreamxy(485, 560);
            delay(200);

            setbkcolor(4);
            bgiout << "Produsul elementelor de sub diagonala secundara  este" << ' ' << prodsub << ".";
            outstreamxy(485, 580);
            delay(200);
        }
        else {
            fout << "Sum of the elements on the second diagonal is" << ' ' << sumdiag << ".\n";
            fout << "Sum of the elements above the second diagonal is" << ' ' << sumdeas << ".\n";
            fout << "Sum of the elements below the second diagonal is" << ' ' << sumsub << ".\n";
            fout << "Product of the elements on the second diagonal is" << ' ' << proddiag << ".\n";
            fout << "Product of the elements above the second diagonal is" << ' ' << proddeas << ".\n";
            fout << "Product of the elements below the second diagonal is" << ' ' << prodsub << ".\n";
            fout << '\n';

            setbkcolor(1);
            bgiout << "Sum of the elements on the second diagonal is" << ' ' << sumdiag << ".";
            outstreamxy(485, 480);
            delay(200);

            setbkcolor(3);
            bgiout << "Sum of the elements above the second diagonal is" << ' ' << sumdeas << ".";
            outstreamxy(485, 500);
            delay(200);

            setbkcolor(4);
            bgiout << "Sum of the elements below the second diagonal is" << ' ' << sumsub << ".";
            outstreamxy(485, 520);
            delay(200);

            setbkcolor(1);
            bgiout << "Product of the elements on the second diagonal is" << ' ' << proddiag << ".";
            outstreamxy(485, 540);
            delay(200);

            setbkcolor(3);
            bgiout << "Product of the elements above the second diagonal is" << ' ' << proddeas << ".";
            outstreamxy(485, 560);
            delay(200);

            setbkcolor(4);
            bgiout << "Product of the elements below the second diagonal is" << ' ' << prodsub << ".";
            outstreamxy(485, 580);
            delay(200);
        }
    }
}


void ecran_matrici() {
    readimagefile("Fundal.jpg", 0, 0, 1530, 1000);
    if (engleza == false) {
        readimagefile("Adunare.jpg", 50, 250, 220, 350);
        readimagefile("Scadere.jpg", 50, 360, 220, 460);
        readimagefile("Inmultire.jpg", 50, 470, 220, 570);
        readimagefile("Inmultirecuscalar.jpg", 50, 580, 220, 680);
        readimagefile("Impartirecuscalar.jpg", 50, 690, 220, 790);
        readimagefile("Transpusa.jpg", 230, 250, 400, 350);
        readimagefile("Inversa.jpg", 230, 360, 400, 460);
        readimagefile("Putere.jpg", 230, 470, 400, 570);
        readimagefile("diagprinc.jpg", 230, 580, 400, 680);
        readimagefile("diagsec.jpg", 230, 690, 400, 790);
        readimagefile("Sterge.jpg", 630, 670, 880, 770);
        readimagefile("Inapoi.jpg", 900, 670, 1150, 770);
    }
    else {
        readimagefile("Sum.jpg", 50, 250, 220, 350);
        readimagefile("Subtraction.jpg", 50, 360, 220, 460);
        readimagefile("Multiplication.jpg", 50, 470, 220, 570);
        readimagefile("Scalar_multiplication.jpg", 50, 580, 220, 680);
        readimagefile("Scalar_division.jpg", 50, 690, 220, 790);
        readimagefile("Transpose.jpg", 230, 250, 400, 350);
        readimagefile("Inverse.jpg", 230, 360, 400, 460);
        readimagefile("Raise_to_power.jpg", 230, 470, 400, 570);
        readimagefile("Main_diagonal.jpg", 230, 580, 400, 680);
        readimagefile("Second_diagonal.jpg", 230, 690, 400, 790);
        readimagefile("Undo.jpg", 630, 670, 880, 770);
        readimagefile("Back.jpg", 900, 670, 1150, 770);
    }

jump:
    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false, buton4 = false, buton5 = false, buton6 = false, buton7 = false, buton8 = false, buton9 = false, buton10 = false, buton11 = false, buton12 = false;
    int x, y;
    do {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();

            if (x >= 50 && x <= 220 && y >= 250 && y <= 350) {
                gata = true;
                buton1 = true;
            }
            else if (x >= 50 && x <= 220 && y >= 360 && y <= 460) {
                gata = true;
                buton2 = true;
            }
            else if (x >= 50 && x <= 220 && y >= 470 && y <= 570) {
                gata = true;
                buton3 = true;
            }
            else if (x >= 50 && x <= 220 && y >= 580 && y <= 680) {
                gata = true;
                buton4 = true;
            }
            else if (x >= 50 && x <= 220 && y >= 690 && y <= 790) {
                gata = true;
                buton5 = true;
            }
            else if (x >= 230 && x <= 400 && y >= 250 && y <= 350) {
                gata = true;
                buton6 = true;
            }
            else if (x >= 230 && x <= 400 && y >= 360 && y <= 460) {
                gata = true;
                buton7 = true;
            }
            else if (x >= 230 && x <= 400 && y >= 470 && y <= 570) {
                gata = true;
                buton8 = true;
            }
            else if (x >= 230 && x <= 400 && y >= 580 && y <= 680) {
                gata = true;
                buton9 = true;
            }
            else if (x >= 230 && x <= 400 && y >= 690 && y <= 790) {
                gata = true;
                buton10 = true;
            }
            else if (x >= 630 && x <= 880 && y >= 670 && y <= 770) {
                gata = true;
                buton11 = true;
            }
            else if (x >= 900 && x <= 1150 && y >= 670 && y <= 770) {
                gata = true;
                buton12 = true;
            }
        }
    } while (!gata);

    if (buton1 == true) {
        adunare_matrici();
        goto jump;
    }
    else if (buton2 == true) {
        scadere_matrici();
        goto jump;
    }
    else if (buton3 == true) {
        inmultire_matrici();
        goto jump;
    }
    else if (buton4 == true) {
        inmultire_matrice_cu_scalar();
        goto jump;
    }
    else if (buton5 == true) {
        impartire_matrice_cu_scalar();
        goto jump;
    }
    else if (buton6 == true) {
        transpusa();
        goto jump;
    }
    else if (buton7 == true) {
        inversa();
        goto jump;
    }
    else if (buton8 == true) {
        ridicare_la_putere();
        goto jump;
    }
    else if (buton9 == true) {
        diagonala_principala();
        goto jump;
    }
    else if (buton10 == true) {
        diagonala_secundara();
        goto jump;
    }
    else if (buton11 == true) {
        ecran_matrici();
        goto jump;
    }
    else if (buton12 == true) {
        ecran_operatii();
        goto jump;
    }
}

// Operatii Vectori:

void suma_elem_din_vector() {
    int s = 0;
    for (int i = 1; i <= X.lungime; i++) {
        s = s + X.elem[i];
    }

    setcolor(0);
    setbkcolor(9);
    settextstyle(9, 0, 2);

    int z;
    int i = 450;
    int j = 250;
    int aux = X.lungime / 20;
    int aux2 = X.lungime % 20;

    if (engleza == false) {
        bgiout << "Numarul de elemente din vector este:" << ' ' << X.lungime;
    }
    else {
        bgiout << "The number of elements in the vector is:" << ' ' << X.lungime;
    }
    outstreamxy(450, 250);

    for (z = 1; z <= aux; z++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, j + z * 50, i + 50, j + z * 50 + 50);
            bgiout << setprecision(0) << fixed << X.elem[(i - 450) / 50 + 1 + (z - 1) * 20];
            outstreamxy(i + 7, j + z * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, j + z * 50, i + (y - 1) * 50 + 50, j + z * 50 + 50);
        bgiout << setprecision(0) << fixed << X.elem[(z - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, j + z * 50 + 16);
        delay(200);
    }

    if (engleza == false) {
        ffout << "Suma elementelor din vector este: " << s << "\n\n";
        bgiout << "Suma elementelor din vector este:" << ' ' << s;
    }
    else {
        ffout << "The sum of the elements in the vector is: " << s << "\n\n";
        bgiout << "The sum of the elements in the vector is: " << ' ' << s;
    }
    outstreamxy(450, j + z * 50 + 120);
}


void prod_elem_din_vector() {
    long long p = 1;
    for (int i = 1; i <= X.lungime; i++) {
        p = p * X.elem[i];
    }

    setcolor(0);
    setbkcolor(9);
    settextstyle(9, 0, 2);

    int z;
    int i = 450;
    int j = 250;
    int aux = X.lungime / 20;
    int aux2 = X.lungime % 20;

    if (engleza == false) {
        bgiout << "Numarul de elemente din vector este:" << ' ' << X.lungime;
    }
    else {
        bgiout << "The number of elements in the vector is:" << ' ' << X.lungime;
    }
    outstreamxy(450, 250);

    for (z = 1; z <= aux; z++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, j + z * 50, i + 50, j + z * 50 + 50);
            bgiout << setprecision(0) << fixed << X.elem[(i - 450) / 50 + 1 + (z - 1) * 20];
            outstreamxy(i + 7, j + z * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, j + z * 50, i + (y - 1) * 50 + 50, j + z * 50 + 50);
        bgiout << setprecision(0) << fixed << X.elem[(z - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, j + z * 50 + 16);
        delay(200);
    }

    if (engleza == false) {
        ffout << "Produsul elementelor din vector este: " << p << "\n\n";
        bgiout << "Produsul elementelor din vector este:" << ' ' << p;
    }
    else {
        ffout << "The product of the elements in the vector is: " << p << "\n\n";
        bgiout << "The product of the elements in the vector is: " << ' ' << p;
    }
    outstreamxy(450, j + z * 50 + 120);
}


void inmultire_vector_cu_scalar() {
    vectori Y;
    Y.lungime = X.lungime;
    for (int i = 1; i <= Y.lungime; i++) {
        Y.elem[i] = X.elem[i] * scalar;
    }

    if (engleza == false) {
        ffout << "Inmultirea vectorului cu scalarul " << scalar << ":\n";
    }
    else {
        ffout << "Vector multiplication with the scalar " << scalar << ":\n";
    }
    for (int i = 1; i <= Y.lungime; i++) {
        ffout << Y.elem[i] << ' ';
    }
    ffout << "\n\n";

    setcolor(0);
    setbkcolor(9);
    settextstyle(9, 0, 2);

    int z, ze;
    int i = 450;
    int j = 250;
    int aux = X.lungime / 20;
    int aux2 = X.lungime % 20;

    if (engleza == false) {
        bgiout << "Numarul de elemente din vector este:" << ' ' << X.lungime;
    }
    else {
        bgiout << "The number of elements in the vector is:" << ' ' << X.lungime;
    }
    outstreamxy(450, 250);

    for (z = 1; z <= aux; z++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, j + z * 50, i + 50, j + z * 50 + 50);
            bgiout << setprecision(0) << fixed << X.elem[(i - 450) / 50 + 1 + (z - 1) * 20];
            outstreamxy(i + 7, j + z * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, j + z * 50, i + (y - 1) * 50 + 50, j + z * 50 + 50);
        bgiout << setprecision(0) << fixed << X.elem[(z - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, j + z * 50 + 16);
        delay(200);
    }

    line(800, j + z * 50 + 80, 825, j + z * 50 + 105);
    line(800, j + z * 50 + 105, 825, j + z * 50 + 80);
    delay(200);

    rectangle(840, j + z * 50 + 70, 890, j + z * 50 + 120);
    bgiout << scalar;
    outstreamxy(855, j + z * 50 + 87);
    delay(200);

    line(900, j + z * 50 + 88, 930, j + z * 50 + 88);
    line(900, j + z * 50 + 103, 930, j + z * 50 + 103);
    delay(200);

    int aux3 = j + z * 50 + 100;
    for (ze = 1; ze <= aux; ze++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, aux3 + ze * 50, i + 50, aux3 + ze * 50 + 50);
            bgiout << setprecision(0) << fixed << Y.elem[(i - 450) / 50 + 1 + (ze - 1) * 20];
            outstreamxy(i + 7, aux3 + ze * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, aux3 + ze * 50, i + (y - 1) * 50 + 50, aux3 + ze * 50 + 50);
        bgiout << setprecision(0) << fixed << Y.elem[(ze - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, aux3 + ze * 50 + 16);
        delay(200);
    }
}


void impartire_vector_cu_scalar() {
    vectori Y;
    Y.lungime = X.lungime;
    for (int i = 1; i <= Y.lungime; i++) {
        Y.elem[i] = X.elem[i] / scalar;
    }

    if (engleza == false) {
        ffout << "Impartirea vectorului cu scalarul " << scalar << ":\n";
    }
    else {
        ffout << "Dividing the vector by scalar " << scalar << ":\n";
    }
    for (int i = 1; i <= Y.lungime; i++) {
        ffout << Y.elem[i] << ' ';
    }
    ffout << "\n\n";

    setcolor(0);
    setbkcolor(9);
    settextstyle(9, 0, 2);

    int z, ze;
    int i = 450;
    int j = 250;
    int aux = X.lungime / 20;
    int aux2 = X.lungime % 20;

    if (engleza == false) {
        bgiout << "Numarul de elemente din vector este:" << ' ' << X.lungime;
    }
    else {
        bgiout << "The number of elements in the vector is:" << ' ' << X.lungime;
    }
    outstreamxy(450, 250);

    for (z = 1; z <= aux; z++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, j + z * 50, i + 50, j + z * 50 + 50);
            bgiout << setprecision(0) << fixed << X.elem[(i - 450) / 50 + 1 + (z - 1) * 20];
            outstreamxy(i + 7, j + z * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, j + z * 50, i + (y - 1) * 50 + 50, j + z * 50 + 50);
        bgiout << setprecision(0) << fixed << X.elem[(z - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, j + z * 50 + 16);
        delay(200);
    }

    line(800, j + z * 50 + 80, 825, j + z * 50 + 105);
    delay(200);

    rectangle(840, j + z * 50 + 70, 890, j + z * 50 + 120);
    bgiout << scalar;
    outstreamxy(855, j + z * 50 + 87);
    delay(200);

    line(900, j + z * 50 + 88, 930, j + z * 50 + 88);
    line(900, j + z * 50 + 103, 930, j + z * 50 + 103);
    delay(200);
    settextstyle(9, 0, 1);

    if (scalar == 0) {
        setcolor(0);
        settextstyle(1, 0, 3);
        setbkcolor(9);
        if (engleza == false) {
            fout << "Impartirea la 0 nu este posibila!\n";
            outtextxy(450, 500, "Impartirea la 0 nu este posibila!");
        }
        else {
            fout << "Division by 0 is not possible!\n";
            outtextxy(450, 500, "Division by 0 is not possible!");
        }
    }
    else {
        int aux3 = j + z * 50 + 100;
        for (ze = 1; ze <= aux; ze++) {
            for (int i = 450; i < 1450; i += 50) {
                rectangle(i, aux3 + ze * 50, i + 50, aux3 + ze * 50 + 50);
                bgiout << setprecision(2) << fixed << Y.elem[(i - 450) / 50 + 1 + (ze - 1) * 20];
                outstreamxy(i + 3, aux3 + ze * 50 + 16);
                delay(200);
            }
        }

        for (int y = 1; y <= aux2; y++) {
            rectangle(i + (y - 1) * 50, aux3 + ze * 50, i + (y - 1) * 50 + 50, aux3 + ze * 50 + 50);
            bgiout << setprecision(2) << fixed << Y.elem[(ze - 1) * 20 + y];
            outstreamxy(i + (y - 1) * 50 + 3, aux3 + ze * 50 + 16);
            delay(200);
        }
    }
}


void sortare_crescatoare() {
    vectori Y;
    Y.lungime = X.lungime;

    for (int i = 1; i <= Y.lungime; i++) {
        Y.elem[i] = X.elem[i];
    }

    bool sorted = false;
    while (sorted == false) {
        sorted = true;
        for (int i = 1; i < Y.lungime; i++) {
            if (Y.elem[i] > Y.elem[i + 1]) {
                int aux = Y.elem[i];
                Y.elem[i] = Y.elem[i + 1];
                Y.elem[i + 1] = aux;
                sorted = false;
            }
        }
    }

    setcolor(0);
    setbkcolor(9);
    settextstyle(9, 0, 2);

    int z, ze;
    int i = 450;
    int j = 250;
    int aux = X.lungime / 20;
    int aux2 = X.lungime % 20;

    if (engleza == false) {
        bgiout << "Numarul de elemente din vector este:" << ' ' << X.lungime;
    }
    else {
        bgiout << "The number of elements in the vector is:" << ' ' << X.lungime;
    }
    outstreamxy(450, 250);
    delay(200);

    for (z = 1; z <= aux; z++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, j + z * 50, i + 50, j + z * 50 + 50);
            bgiout << setprecision(0) << fixed << X.elem[(i - 450) / 50 + 1 + (z - 1) * 20];
            outstreamxy(i + 7, j + z * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, j + z * 50, i + (y - 1) * 50 + 50, j + z * 50 + 50);
        bgiout << setprecision(0) << fixed << X.elem[(z - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, j + z * 50 + 16);
        delay(200);
    }

    int aux3 = j + z * 50 + 100;
    delay(200);

    if (engleza == false) {
        bgiout << "Vectorul sortat crescator este:";
        ffout << "Vectorul sortat crescator este:\n";
    }
    else {
        bgiout << "The ascending sorted vector is:";
        ffout << "The ascending sorted vector is:\n";
    }
    for (int i = 1; i <= Y.lungime; i++) {
        ffout << Y.elem[i] << ' ';
    }
    ffout << "\n\n";
    outstreamxy(450, aux3 + 20);
    delay(200);

    for (ze = 1; ze <= aux; ze++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, aux3 + ze * 50, i + 50, aux3 + ze * 50 + 50);
            bgiout << setprecision(0) << fixed << Y.elem[(i - 450) / 50 + 1 + (ze - 1) * 20];
            outstreamxy(i + 7, aux3 + ze * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, aux3 + ze * 50, i + (y - 1) * 50 + 50, aux3 + ze * 50 + 50);
        bgiout << setprecision(0) << fixed << Y.elem[(ze - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, aux3 + ze * 50 + 16);
        delay(200);
    }
}


void sortare_descrescatoare() {
    vectori Y;
    Y.lungime = X.lungime;

    for (int i = 1; i <= Y.lungime; i++) {
        Y.elem[i] = X.elem[i];
    }

    bool sorted = false;
    while (sorted == false) {
        sorted = true;
        for (int i = 1; i <= Y.lungime - 1; i++) {
            if (Y.elem[i] < Y.elem[i + 1]) {
                int aux = Y.elem[i];
                Y.elem[i] = Y.elem[i + 1];
                Y.elem[i + 1] = aux;
                sorted = false;
            }
        }
    }

    setcolor(0);
    setbkcolor(9);
    settextstyle(9, 0, 2);

    int z, ze;
    int i = 450;
    int j = 250;
    int aux = X.lungime / 20;
    int aux2 = X.lungime % 20;

    if (engleza == false) {
        bgiout << "Numarul de elemente din vector este:" << ' ' << X.lungime;
    }
    else {
        bgiout << "The number of elements in the vector is:" << ' ' << X.lungime;
    }
    outstreamxy(450, 250);
    delay(200);

    for (z = 1; z <= aux; z++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, j + z * 50, i + 50, j + z * 50 + 50);
            bgiout << setprecision(0) << fixed << X.elem[(i - 450) / 50 + 1 + (z - 1) * 20];
            outstreamxy(i + 7, j + z * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, j + z * 50, i + (y - 1) * 50 + 50, j + z * 50 + 50);
        bgiout << setprecision(0) << fixed << X.elem[(z - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, j + z * 50 + 16);
        delay(200);
    }

    int aux3 = j + z * 50 + 100;
    delay(200);

    if (engleza == false) {
        bgiout << "Vectorul sortat descrescator este:";
        ffout << "Vectorul sortat descrescator este:\n";
    }
    else {
        bgiout << "The descending sorted vector is:";
        ffout << "The descending sorted vector is:\n";
    }
    for (int i = 1; i <= Y.lungime; i++) {
        ffout << Y.elem[i] << ' ';
    }
    ffout << "\n\n";
    outstreamxy(450, aux3 + 20);
    delay(200);

    for (ze = 1; ze <= aux; ze++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, aux3 + ze * 50, i + 50, aux3 + ze * 50 + 50);
            bgiout << setprecision(0) << fixed << Y.elem[(i - 450) / 50 + 1 + (ze - 1) * 20];
            outstreamxy(i + 7, aux3 + ze * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, aux3 + ze * 50, i + (y - 1) * 50 + 50, aux3 + ze * 50 + 50);
        bgiout << setprecision(0) << fixed << Y.elem[(ze - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, aux3 + ze * 50 + 16);
        delay(200);
    }
}


void permutare_stanga() {
    vectori Y;
    Y.lungime = X.lungime;
    int nr_dep_stg_aux = nr_dep_stg;

    for (int i = 1; i <= Y.lungime; i++) {
        Y.elem[i] = X.elem[i];
    }

    while (nr_dep_stg != 0) {
        int save = Y.elem[1];
        for (int i = 1; i <= Y.lungime - 1; i++) {
            Y.elem[i] = Y.elem[i + 1];
        }
        Y.elem[Y.lungime] = save;
        nr_dep_stg--;
    }

    setcolor(0);
    setbkcolor(9);
    settextstyle(9, 0, 2);

    int z, ze;
    int i = 450;
    int j = 250;
    int aux = X.lungime / 20;
    int aux2 = X.lungime % 20;

    if (engleza == false) {
        bgiout << "Numarul de elemente din vector este:" << ' ' << X.lungime;
    }
    else {
        bgiout << "The number of elements in the vector is:" << ' ' << X.lungime;
    }
    outstreamxy(450, 250);
    delay(200);

    for (z = 1; z <= aux; z++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, j + z * 50, i + 50, j + z * 50 + 50);
            bgiout << setprecision(0) << fixed << X.elem[(i - 450) / 50 + 1 + (z - 1) * 20];
            outstreamxy(i + 7, j + z * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, j + z * 50, i + (y - 1) * 50 + 50, j + z * 50 + 50);
        bgiout << setprecision(0) << fixed << X.elem[(z - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, j + z * 50 + 16);
        delay(200);
    }

    int aux3 = j + z * 50 + 100;
    delay(200);

    if (engleza == false) {
        bgiout << "Vectorul permutat la stanga de " << nr_dep_stg_aux << " ori este:";
        ffout << "Vectorul permutat la stanga de " << nr_dep_stg_aux << " ori este:\n";
    }
    else {
        bgiout << "The vector after " << nr_dep_stg_aux << " permutations to left is:";
        ffout << "The vector after " << nr_dep_stg_aux << " permutations to left is:\n";
    }
    for (int i = 1; i <= Y.lungime; i++) {
        ffout << Y.elem[i] << ' ';
    }
    ffout << "\n\n";
    outstreamxy(450, aux3 + 20);
    delay(200);

    for (ze = 1; ze <= aux; ze++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, aux3 + ze * 50, i + 50, aux3 + ze * 50 + 50);
            bgiout << setprecision(0) << fixed << Y.elem[(i - 450) / 50 + 1 + (ze - 1) * 20];
            outstreamxy(i + 7, aux3 + ze * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, aux3 + ze * 50, i + (y - 1) * 50 + 50, aux3 + ze * 50 + 50);
        bgiout << setprecision(0) << fixed << Y.elem[(ze - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, aux3 + ze * 50 + 16);
        delay(200);
    }
}


void permutare_dreapta() {
    vectori Y;
    Y.lungime = X.lungime;
    int nr_dep_dr_aux = nr_dep_dr;

    for (int i = 1; i <= Y.lungime; i++) {
        Y.elem[i] = X.elem[i];
    }

    while (nr_dep_dr != 0) {
        int save = Y.elem[Y.lungime];
        for (int i = Y.lungime; i >= 2; i--) {
            Y.elem[i] = Y.elem[i - 1];
        }
        Y.elem[1] = save;
        nr_dep_dr--;
    }

    setcolor(0);
    setbkcolor(9);
    settextstyle(9, 0, 2);

    int z, ze;
    int i = 450;
    int j = 250;
    int aux = X.lungime / 20;
    int aux2 = X.lungime % 20;

    if (engleza == false) {
        bgiout << "Numarul de elemente din vector este:" << ' ' << X.lungime;
    }
    else {
        bgiout << "The number of elements in the vector is:" << ' ' << X.lungime;
    }
    outstreamxy(450, 250);
    delay(200);

    for (z = 1; z <= aux; z++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, j + z * 50, i + 50, j + z * 50 + 50);
            bgiout << setprecision(0) << fixed << X.elem[(i - 450) / 50 + 1 + (z - 1) * 20];
            outstreamxy(i + 7, j + z * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, j + z * 50, i + (y - 1) * 50 + 50, j + z * 50 + 50);
        bgiout << setprecision(0) << fixed << X.elem[(z - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, j + z * 50 + 16);
        delay(200);
    }

    int aux3 = j + z * 50 + 100;
    delay(200);

    if (engleza == false) {
        bgiout << "Vectorul permutat la dreapta de " << nr_dep_dr_aux << " ori este:";
        ffout << "Vectorul permutat la dreapta de " << nr_dep_dr_aux << " ori este:\n";
    }
    else {
        bgiout << "The vector after " << nr_dep_dr_aux << " permutations to right is:";
        ffout << "The vector after " << nr_dep_dr_aux << " permutations to right is:\n";
    }
    for (int i = 1; i <= Y.lungime; i++) {
        ffout << Y.elem[i] << ' ';
    }
    ffout << "\n\n";
    outstreamxy(450, aux3 + 20);
    delay(200);

    for (ze = 1; ze <= aux; ze++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, aux3 + ze * 50, i + 50, aux3 + ze * 50 + 50);
            bgiout << setprecision(0) << fixed << Y.elem[(i - 450) / 50 + 1 + (ze - 1) * 20];
            outstreamxy(i + 7, aux3 + ze * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, aux3 + ze * 50, i + (y - 1) * 50 + 50, aux3 + ze * 50 + 50);
        bgiout << setprecision(0) << fixed << Y.elem[(ze - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, aux3 + ze * 50 + 16);
        delay(200);
    }
}


void inversare_vector() {
    vectori Y;
    Y.lungime = X.lungime;

    for (int i = 1; i <= Y.lungime; i++) {
        Y.elem[i] = X.elem[i];
    }

    for (int i = 1; i <= Y.lungime / 2; i++) {
        int aux = Y.elem[i];
        Y.elem[i] = Y.elem[Y.lungime - i + 1];
        Y.elem[Y.lungime - i + 1] = aux;
    }

    setcolor(0);
    setbkcolor(9);
    settextstyle(9, 0, 2);

    int z, ze;
    int i = 450;
    int j = 250;
    int aux = X.lungime / 20;
    int aux2 = X.lungime % 20;

    if (engleza == false) {
        bgiout << "Numarul de elemente din vector este:" << ' ' << X.lungime;
    }
    else {
        bgiout << "The number of elements in the vector is:" << ' ' << X.lungime;
    }
    outstreamxy(450, 250);
    delay(200);

    for (z = 1; z <= aux; z++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, j + z * 50, i + 50, j + z * 50 + 50);
            bgiout << setprecision(0) << fixed << X.elem[(i - 450) / 50 + 1 + (z - 1) * 20];
            outstreamxy(i + 7, j + z * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, j + z * 50, i + (y - 1) * 50 + 50, j + z * 50 + 50);
        bgiout << setprecision(0) << fixed << X.elem[(z - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, j + z * 50 + 16);
        delay(200);
    }

    int aux3 = j + z * 50 + 100;
    delay(200);

    if (engleza == false) {
        bgiout << "Vectorul inversat este:";
        ffout << "Vectorul inversat este: \n";
    }
    else {
        bgiout << "The inverted vector is:";
        ffout << "The inverted vector is: \n";
    }
    for (int i = 1; i <= Y.lungime; i++) {
        ffout << Y.elem[i] << ' ';
    }
    ffout << "\n\n";
    outstreamxy(450, aux3 + 20);
    delay(200);

    for (ze = 1; ze <= aux; ze++) {
        for (int i = 450; i < 1450; i += 50) {
            rectangle(i, aux3 + ze * 50, i + 50, aux3 + ze * 50 + 50);
            bgiout << setprecision(0) << fixed << Y.elem[(i - 450) / 50 + 1 + (ze - 1) * 20];
            outstreamxy(i + 7, aux3 + ze * 50 + 16);
            delay(200);
        }
    }

    for (int y = 1; y <= aux2; y++) {
        rectangle(i + (y - 1) * 50, aux3 + ze * 50, i + (y - 1) * 50 + 50, aux3 + ze * 50 + 50);
        bgiout << setprecision(0) << fixed << Y.elem[(ze - 1) * 20 + y];
        outstreamxy(i + (y - 1) * 50 + 7, aux3 + ze * 50 + 16);
        delay(200);
    }
}



void ecran_vectori() {
    readimagefile("Fundal.jpg", 0, 0, 1530, 1000);
    if (engleza == false) {
        readimagefile("SumaElem.jpg", 50, 250, 220, 350);
        readimagefile("ProdusElem.jpg", 50, 360, 220, 460);
        readimagefile("Inmultirecuscalar.jpg", 50, 470, 220, 570);
        readimagefile("Impartirecuscalar.jpg", 50, 580, 220, 680);
        readimagefile("SortareCrescatoare.jpg", 230, 250, 400, 350);
        readimagefile("SortareDescrescatoare.jpg", 230, 360, 400, 460);
        readimagefile("PermutareStg.jpg", 230, 470, 400, 570);
        readimagefile("PermutareDr.jpg", 230, 580, 400, 680);
        readimagefile("Inversare.jpg", 50, 690, 220, 790);
        readimagefile("Sterge.jpg", 630, 670, 880, 770);
        readimagefile("Inapoi.jpg", 900, 670, 1150, 770);
    }
    else {
        readimagefile("Sum.jpg", 50, 250, 220, 350);
        readimagefile("Product.jpg", 50, 360, 220, 460);
        readimagefile("Scalar_multiplication.jpg", 50, 470, 220, 570);
        readimagefile("Scalar_division.jpg", 50, 580, 220, 680);
        readimagefile("Ascending_sort.jpg", 230, 250, 400, 350);
        readimagefile("Descending_sort.jpg", 230, 360, 400, 460);
        readimagefile("Right_permutation.jpg", 230, 470, 400, 570);
        readimagefile("Left_permutation.jpg", 230, 580, 400, 680);
        readimagefile("Reverse.jpg", 50, 690, 220, 790);
        readimagefile("Undo.jpg", 630, 670, 880, 770);
        readimagefile("Back.jpg", 900, 670, 1150, 770);
    }

jump:
    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false, buton4 = false, buton5 = false, buton6 = false, buton7 = false, buton8 = false, buton9 = false, buton10 = false, buton11 = false;
    int x, y;
    do {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();

            if (x >= 50 && x <= 220 && y >= 250 && y <= 350) {
                gata = true;
                buton1 = true;
            }
            else if (x >= 50 && x <= 220 && y >= 360 && y <= 460) {
                gata = true;
                buton2 = true;
            }
            else if (x >= 50 && x <= 220 && y >= 470 && y <= 570) {
                gata = true;
                buton3 = true;
            }
            else if (x >= 50 && x <= 220 && y >= 580 && y <= 680) {
                gata = true;
                buton4 = true;
            }
            else if (x >= 230 && x <= 400 && y >= 250 && y <= 350) {
                gata = true;
                buton5 = true;
            }
            else if (x >= 230 && x <= 400 && y >= 360 && y <= 460) {
                gata = true;
                buton6 = true;
            }
            else if (x >= 230 && x <= 400 && y >= 470 && y <= 570) {
                gata = true;
                buton7 = true;
            }
            else if (x >= 230 && y >= 580 && x <= 400 && y <= 680) {
                gata = true;
                buton8 = true;
            }
            else if (x >= 50 && y >= 690 && x <= 220 && y <= 790) {
                gata = true;
                buton9 = true;
            }
            else if (x >= 630 && y >= 670 && x <= 880 && y <= 770) {
                gata = true;
                buton10 = true;
            }
            else if (x >= 900 && x <= 1150 && y >= 670 && y <= 770) {
                gata = true;
                buton11 = true;
            }
        }
    } while (!gata);

    if (buton1 == true) {
        suma_elem_din_vector();
        goto jump;
    }
    else if (buton2 == true) {
        prod_elem_din_vector();
        goto jump;
    }
    else if (buton3 == true) {
        inmultire_vector_cu_scalar();
        goto jump;
    }
    else if (buton4 == true) {
        impartire_vector_cu_scalar();
        goto jump;
    }
    else if (buton5 == true) {
        sortare_crescatoare();
        goto jump;
    }
    else if (buton6 == true) {
        sortare_descrescatoare();
        goto jump;
    }
    else if (buton7 == true) {
        permutare_stanga();
        goto jump;
    }
    else if (buton8 == true) {
        permutare_dreapta();
        goto jump;
    }
    else if (buton9 == true) {
        inversare_vector();
        goto jump;
    }
    else if (buton10 == true) {
        ecran_vectori();
        goto jump;
    }
    else if (buton11 == true) {
        ecran_operatii();
        goto jump;
    }
}


void ecran_operatii() {
    readimagefile("Fundal.jpg", 0, 0, 1530, 1000);
    if (engleza == false) {
        readimagefile("Matrici.jpg", 620, 300, 900, 400);
        readimagefile("Vectori.jpg", 620, 440, 900, 540);
        readimagefile("Inapoi.jpg", 1180, 670, 1430, 770);
    }
    else {
        readimagefile("Matrices.jpg", 620, 300, 900, 400);
        readimagefile("Vectors.jpg", 620, 440, 900, 540);
        readimagefile("Back.jpg", 1180, 670, 1430, 770);
    }

    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false;
    int x, y;

    do {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if (x >= 620 && x <= 900 && y >= 300 && y <= 400) {
                gata = true;
                buton1 = true;
            }
            else if (x >= 620 && x <= 900 && y >= 440 && y <= 540) {
                gata = true;
                buton2 = true;
            }
            else if (x >= 1180 && x <= 1430 && y >= 670 && y <= 770) {
                gata = true;
                buton3 = true;
            }
        }
    } while (!gata);

    if (buton1 == true) {
        citire_matrici();
        ecran_matrici();
    }
    else if (buton2 == true) {
        citire_vectori();
        ecran_vectori();
    }
    else if (buton3 == true) {
        interfata();
    }
}


void optiuni() {
    if (engleza == false) {
        readimagefile("Optiunibk.jpg", 0, 0, 1530, 1000);
        readimagefile("Inapoi.jpg", 1180, 670, 1430, 770);
    }
    else {
        readimagefile("Optionsbk.jpg", 0, 0, 1530, 1000);
        readimagefile("Back.jpg", 1180, 670, 1430, 770);
    }
    readimagefile("Romania.jpg", 700, 510, 800, 590);
    readimagefile("Uk.jpg", 880, 510, 980, 590);
    setcolor(0);
    rectangle(750, 320, 830, 400);
    rectangle(1070, 320, 1150, 400);

jump:
    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false, buton4 = false, buton5 = false;
    int x, y;

    do {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();

            if (x >= 765 && x <= 815 && y >= 335 && y <= 385) {
                gata = true;
                buton1 = true;
            }

            if (x >= 1085 && x <= 1135 && y >= 335 && y <= 385) {
                gata = true;
                buton2 = true;
            }

            if (x >= 700 && x <= 800 && y >= 510 && y <= 590) {
                gata = true;
                buton3 = true;
            }

            if (x >= 880 && x <= 980 && y >= 510 && y <= 590) {
                gata = true;
                buton4 = true;
            }

            if (x >= 1180 && x <= 1430 && y >= 670 && y <= 770) {
                gata = true;
                buton5 = true;
            }
        }
    } while (!gata);

    if (buton1 == true) {
        PlaySound(TEXT("melodie-joc.wav"), NULL, SND_ASYNC | SND_LOOP); //porneste muzica
        readimagefile("sunet.jpg", 1082, 333, 1138, 388);
        setlinestyle(0, 2, 2);
        line(765, 335, 815, 385);
        line(815, 335, 765, 385);
        goto jump;
    }
    else if (buton2 == true) {
        PlaySound(NULL, 0, 0); // opreste muzica
        readimagefile("sunet.jpg", 755, 333, 825, 388);
        setlinestyle(0, 2, 2);
        line(1085, 335, 1135, 385);
        line(1135, 335, 1085, 385);
        goto jump;
    }
    else if (buton3 == true) {
        engleza = false;
        optiuni();
        goto jump;
    }
    else if (buton4 == true) {
        engleza = true;
        optiuni();
        goto jump;
    }
    else if (buton5 == true) {
        interfata();
        goto jump;
    }
}


void interfata() {
    readimagefile("Fundal.jpg", 0, 0, 1530, 1000);
    if (engleza == false) {
        readimagefile("Incepe.jpg", 610, 270, 915, 370);
        readimagefile("Optiuni.jpg", 610, 400, 915, 500);
        readimagefile("Iesire.jpg", 610, 530, 915, 630);
    }
    else {
        readimagefile("Start.jpg", 610, 270, 915, 370);
        readimagefile("Options.jpg", 610, 400, 915, 500);
        readimagefile("Exit.jpg", 610, 530, 915, 630);
    }

    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false;
    int x, y;

    do {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();

            if (x >= 610 && x <= 915 && y >= 270 && y <= 370) {
                gata = true;
                buton1 = true;
            }
            else if (x >= 610 && x <= 915 && y >= 400 && y <= 500) {
                gata = true;
                buton2 = true;
            }
            else if (x >= 610 && x <= 915 && y >= 530 && y <= 630) {
                gata = true;
                buton3 = true;
            }
        }
    } while (!gata); cleardevice();

    if (buton1 == true) {
        ecran_operatii();
    }
    else if (buton2 == true) {
        optiuni();
    }
    else if (buton3 == true) {
        closegraph();
    }
}

void BibMat() {
    initwindow(1530, 1000);
    interfata();
    getch();
    closegraph();
}
