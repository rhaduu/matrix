#include <iostream>

//in order to write less, I defined the for's I'll use the most in a very short form;
#define fori3 for(i=0; i<3; i++)
#define forj3 for(j=0; j<3; j++)

// i and  j are global variables because I am going to use them in different functions;
int i, j;

//functions prototypes;
int construct(int m[100][100]);
void matrix(int m[100][100]);
int determinant (int m[100][100]);

int main(){
    int m[100][100], deter;

    std::cout << "For this matrix: \n";
    construct(m);
    matrix(m);

    std::cout <<"The determinant is: \n";

    deter = determinant(m);

    std::cout<< "\t"<< deter<<"\n";


    return 0;
}

//this function is contructing the matrix by herself;
int construct (int m[100][100]){
    srand(time(NULL));

    fori3{
        m[i][i] = 1;
    }
    fori3{
        forj3{
            if (i<j)
                m[i][j]= (rand()%6)+1;
            else if (i>j)
                m[i][j] = (rand()%6)+1;
        }
    }
}

//this function is displaying the matrix in a readable form;
void matrix (int m[100][100]){
    fori3{
        forj3{
            std::cout <<"\t"<< m[i][j]<< "\t";
        }
        std::cout<< "\n";
    }
}

//this function is calculating and returning to the main function the determinant of the matrix;
int determinant(int m[100][100]){
    int p_dp, p_t1p, p_t2p;
    int p_ds, p_t1s, p_t2s;
    int rez;

    p_dp = m[0][0]*m[1][1]*m[2][2];
    p_t1p = m[0][2]*m[1][0]*m[2][1];
    p_t2p = m[0][1]*m[2][0]*m[1][2];

    p_ds = m[0][2]* m[1][1]* m[2][0];
    p_t1s = m[0][0]* m[2][1] * m[1][2];
    p_t2s = m[0][1]* m[1][0] * m[2][2];

    rez = p_dp + p_t1p+ p_t2p - (p_ds+p_t1s+p_t2s);

    return rez;
}