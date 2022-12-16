#include <iostream>
#include <algorithm>

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
            transpose_frame[j][i] = hor_frame[i][j];
      }
    }

    return;

}



int main()

{   
    hor_solve();
    ver_solve();
    for (int i=0; i<9; i++) {
        std::cout << ver_frame[0][i] << std::endl; 
    }

    return 0;
}