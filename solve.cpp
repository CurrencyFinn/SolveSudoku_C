#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 0 => no entry

//int checkArray[9] = {1,2,3,4,5,6,7,8,9};
int frame[9][9] = { {1,5,3,4,7,6,2,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9}, {0,0,3,4,0,0,0,8,9} };
int hor_frame[9][9];
int ver_frame[9][9];


// internal block 

void int_solve(int inputMatrix[9][9])
{   
    std::vector<int> checkArray{1,2,3,4,5,6,7,8,9};
    // initialize array...

    // delete element at index 2
    checkArray.erase(checkArray.begin() + 2);

    
    int int_count =0;
    for(int i = 0; i<9; i++)
    {
        std::cout << inputMatrix[0][i] << std::endl;
        
        bool exists = std::find(checkArray, checkArray+9, inputMatrix[0][i]) != checkArray+9;
        
        if(exists) {
            auto arrayEnd = std::remove_if(checkArray, checkArray+9, inputMatrix[0][i]);
            // remove value from temp list, the remaining value is it is 8 add it, otherwise restore it 
            int_count++;
        }
        
    }
        for (int i=0; i<9; i++) {
            std::cout << checkArray[i] << std::endl;
        }
        if (int_count ==8) { //  1 element missing, find value that is non existing and fill in matrix for every input matrix [vert, hor, int]
            
        } 
        else 
        {
            // restore list to the new list and loop to another list
        }
  
    return;
}

// horizonatal rows

void hor_solve(int inputMatrix[9][9], int outputMatrix[9][9])
{
    int acount = 0;
    int bcount = 0;
    int ccount = 0;
    for(int i = 0; i<9; i++)
    {
        if(i < 3) // first row block

        {

            for(int b = 0; b<9; b++) {
                
                if(b <3) // first segment row
                {
                    if (acount >8) {
                        acount = 0;
                    }
                    outputMatrix[0][acount] = inputMatrix[i][b];
                    acount++;

                }
                else if (b>2 && b<6) // second segment row
                {
                    if (bcount >8) {
                        bcount = 0;
                    }
                    outputMatrix[1][bcount] = inputMatrix[i][b];
                    bcount++;

                } 
                else // third segment row
                {
                    if (ccount > 8) {
                        ccount = 0;
                    }
                    outputMatrix[2][ccount] = inputMatrix[i][b];
                    ccount++;

                }
            }
        }
        
        else if (i>2 && i<6) // second row block
            
        {
            for(int b = 0; b<9; b++) {
                
                if(b <3) // first segment row
                {
                    if (acount >8) {
                        acount = 0;
                    }
                    outputMatrix[3][acount] = inputMatrix[i][b];
                    acount++;

                }
                else if (b>2 && b<6) // second segment row
                {
                    if (bcount >8) {
                        bcount = 0;
                    }
                    outputMatrix[4][bcount] = inputMatrix[i][b];
                    bcount++;

                } 
                else // third segment row
                {
                    if (ccount > 8) {
                        ccount = 0;
                    }
                    outputMatrix[5][ccount] = inputMatrix[i][b];
                    ccount++;

                }
            }
        } 

        else // third row block
        {
            for(int b = 0; b<9; b++) {
                
                if(b <3) // first segment row
                {
                    if (acount >8) {
                        acount = 0;
                    }
                    outputMatrix[6][acount] = inputMatrix[i][b];
                    acount++;

                }
                else if (b>2 && b<6) // second segment row
                {
                    if (bcount >8) {
                        bcount = 0;
                    }
                    outputMatrix[7][bcount] = inputMatrix[i][b];
                    bcount++;

                } 
                else // third segment row
                {
                    if (ccount > 8) {
                        ccount = 0;
                    }
                    outputMatrix[8][ccount] = inputMatrix[i][b];
                    ccount++;

                }
            }
        }

    }



    return;
}

// vertical columns
// void ver_solve() // O(N^2)

// {

//     for (int i = 0; i<9; i+=3) {

//         for(int b=0; b<9; b+=3)
        
//         {

//             std::cout << frame[i][b] << ' ';
//             if (b==6) { // second vert row
//                 b=-2;
//             }

//             if (b==7) { // third vert row
//                 b=-1;
//             }
//         }

//         std::cout << ' ' << std::endl;

        
//         if (i==6) { // interchange 3*3 outside matrix so it creates horizontal arrangement of the vertical
//             i=-2;
//         }

//         if (i==7) {
//             i=-1;
//         }
//     }
//     return;

// }

void transpose(int inputMatrix[9][9], int outputMatrix[9][9]) { // O(N)
     for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            outputMatrix[j][i] = inputMatrix[i][j];
      }
    }
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
    //setup
    // hor_solve(frame, hor_frame);
    // visualise(hor_frame);
    // std::cout << ' ' << endl; 
    // transpose(hor_frame, ver_frame);
    // visualise(ver_frame);

    int_solve(frame);

    return 0;
}