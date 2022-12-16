#include <iostream>
#include <algorithm>
using namespace std;
// 0 => no entry

const int checkArray[9] = {1,2,3,4,5,6,7,8,9};
int frame[9][9] = { {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9} };
int transpose_frame [9][9];
int hor_frame[9][9];
int ver_frame[9][9];
int acount = 0;
int bcount = 0;
int ccount = 0;
// internal block 

void int_solve()
{
    for(int i = 0; i<9; i++)
    {
        std::cout << frame[0][i] << std::endl;
        
        bool exists = std::find(checkArray, checkArray + 9, frame[0][i]) != checkArray + 9;

        if(exists) {
            std::cout << "Element found" << std::endl;
        }
        
    }
  
    
    return;
}

// horizonatal rows

void hor_solve()
{
   
    for(int i = 0; i<9; i++)
    {
        if(i <3) // first row block

        {

            for(int b = 0; b<9; b++) {
                
                if(b <3) // first segment row
                {
                    if (acount >9) {
                        acount = 0;
                    }
                    hor_frame[0][acount] = frame[i][b];
                    acount++;

                }
                else if (b>2 && b<6) // second segment row
                {
                    if (bcount >9) {
                        bcount = 0;
                    }
                    hor_frame[1][bcount] = frame[i][b];
                    bcount++;

                } 
                else // third segment row
                {
                    if (ccount > 9) {
                        ccount = 0;
                    }
                    hor_frame[2][ccount] = frame[i][b];
                    ccount++;

                }
            }
        }
        
        else if (i<6) // second row block
            
        {
            
            for(int b = 0; b<9; b++) {
                
                if(b <3) // first segment row
                {
                    if (acount >9) {
                        acount = 0;
                    }
                    hor_frame[3][acount] = frame[i][b];
                    acount++;

                }
                else if (b>2 && b<6) // second segment row
                {
                    if (bcount >9) {
                        bcount = 0;
                    }
                    hor_frame[4][bcount] = frame[i][b];
                    bcount++;

                } 
                else // third segment row
                {
                    if (ccount > 9) {
                        ccount = 0;
                    }
                    hor_frame[5][ccount] = frame[i][b];
                    ccount++;

                }
            }
        } 

        else // third row block
        {
            for(int b = 0; b<9; b++) {
                
                if(b <3) // first segment row
                {
                    if (acount >9) {
                        acount = 0;
                    }
                    hor_frame[6][acount] = frame[i][b];
                    acount++;

                }
                else if (b>2 && b<6) // second segment row
                {
                    if (bcount >9) {
                        bcount = 0;
                    }
                    hor_frame[7][bcount] = frame[i][b];
                    bcount++;

                } 
                else // third segment row
                {
                    if (ccount > 9) {
                        ccount = 0;
                    }
                    hor_frame[8][ccount] = frame[i][b];
                    ccount++;

                }
            }
        }

    }

    return;
}

// vertical columns

void ver_solve()

{
    acount = 0;
    bcount = 0;
    ccount = 0;

    // tranpose of frame => same technique as hor_solve

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            transpose_frame[j][i] = frame[i][j];
      }
    }
     for(int i = 0; i<9; i++)
    {
        if(i <3) // first row block

        {
            for(int b = 0; b<9; b++) {
                
                if(b <3) // first vert row
                {
                    //std::cout << transpose_frame[0][b] << std::endl; 
                }

                else if (b>2 && b<6) // second vert row
                {
                    //std::cout << transpose_frame[1][b] << std::endl; 
                }
                else // thirds vert row
                {
                    //std::cout << transpose_frame[2][b] << std::endl; 
                }

            }
        }

        else if (i<6) // second row block
        
        { 
                
            for(int b = 0; b<9; b++) {
                
                if(b <3) // fourth vert row
                {
                    //std::cout << transpose_frame[3][b] << std::endl; 
                }

                else if (b>2 && b<6) // fifth vert row
                {
                    //std::cout << transpose_frame[4][b] << std::endl; 
                }
                else // sixth vert row
                {
                    //std::cout << transpose_frame[5][b] << std::endl; 
                }

            }
        }

        else 
        
        {
            for(int b = 0; b<9; b++) {
                if(b <3) //  seventh row
                {
                    //std::cout << transpose_frame[6][b] << std::endl; 
                }

                else if (b>2 && b<6) // eight vert row
                {
                    //std::cout << transpose_frame[7][b] << std::endl; 
                }
                else // nineth vert row
                {
                    //std::cout << transpose_frame[8][b] << std::endl; 
                }

            }
        }
    }
    return;

}

void visualise(int matrix[9][9]) {

    for (int i=0; i<9; i++) {
        for(int j=0; j<9; j++){
            std::cout << matrix[i][j] << ' '; 
        }
        std::cout << std::endl;
    
    }

    return;
}

int main()

{   
    hor_solve();
    ver_solve();
    visualise(frame);
    std::cout << ' ' << std::endl; 
    visualise(transpose_frame);
    
    // twop option 

    // # tranpose indivual frame [9] => count first row of i=0, i=3 firt row, i=6 first row leads to the vertical row. Now same holder for then the other rows. O
    // # not tranpose make a script that indidually selectes ofset numbers so vertical row is selecected. 

    return 0;
}