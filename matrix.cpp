#include <iostream>
#define fori3 for(i=0; i<3; i++)
#define forj3 for(j=0; j<3; j++)

//using namespace std;
int i, j;

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

void matrix (int m[100][100]){
    fori3{
        forj3{
            std::cout <<"\t"<< m[i][j]<< "\t";
        }
        std::cout<< "\n";
    }
}

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