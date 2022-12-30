#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 0 => no entry

// TAKS # after solving the vector gets deleted unwanted

//int checkArray[9] = {1,2,3,4,5,6,7,8,9};
int frame[9][9] = { {4,8,1,7,6,9,3,5,0}, {5,6,0,3,2,4,0,7,0}, {3,0,0,1,5,0,6,0,0}, {0,9,7,1,0,0,5,4,0}, {0,8,5,0,0,6,1,0,0}, {2,1,0,5,4,0,0,8,6}, {0,7,6,2,0,5,9,3,4}, {9,5,3,0,4,0,0,0,0}, {0,2,0,0,3,0,0,6,5} };
int hor_frame[9][9];
int ver_frame[9][9];
int checkArray[9] = {1,2,3,4,5,6,7,8,9};
vector<vector<vector<int>>> solveFrame(9, vector<vector<int> > (9, vector<int>(9)));


// internal block 

void int_solve(int inputMatrix[9][9])
{   
    
    for (int i=0; i<9; i++) {

        vector<int> checkVector{1,2,3,4,5,6,7,8,9};
    
        int int_count =0;
        for(int j = 0; j<9; j++)
        {   
            vector<int>::iterator it = find(checkVector.begin(), checkVector.end(), inputMatrix[i][j]); 

            if (it != checkVector.end()) {
                checkVector.erase(it);
            } else {
                int_count++;
            }
        } 
        if (int_count ==1) { // there is one [0]
            for (int k=0; k<9; k++) {
                if (inputMatrix[i][k] == 0) {
                    inputMatrix[i][k] = checkVector[0];
                }
            }
        }
    }

    return;
}

void intSolveSetup(int inputMatrix[9][9])
{
    for (int i=0; i<solveFrame.size(); i++) {
        for(int j = 0; j != solveFrame[i].size(); j++)
        {   
            if (inputMatrix[i][j] != 0) {
                solveFrame[i][j].resize(1);
                solveFrame[i][j][0] = 0;
            }
            else {

                    for (int k = 0; k != solveFrame[i][j].size(); k++)
                    {   
                        solveFrame[i][j][k] = checkArray[k];
                    }
                
            }
         }
    }
    return;
}

void intSolve(int inputMatrix[9][9])
{
    for (int i =0; i<9; i++)
    {
        vector<int> tempVec;
        for (int j=0; j<9; j++) {
            tempVec.push_back(inputMatrix[i][j]);
        }
        for (int k=0; k<9; k++)
        if (solveFrame[i][k][0] != 0) {
            for (int l=0; l<9; l++) {
                vector<int>::iterator it = find(solveFrame[i][k].begin(), solveFrame[i][k].end(), tempVec[l]); 
                if (it != solveFrame[i][k].end()) {
                    solveFrame[i][k].erase(it);
                }
                if (solveFrame[i][k].size() == 1) {
                    inputMatrix[i][k] = solveFrame[i][k][0];
                    solveFrame[i][k][0] = 0;
                }
            }
        }
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

void transpose(int inputMatrix[9][9], int outputMatrix[9][9]) {
     for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            outputMatrix[j][i] = inputMatrix[i][j];
      }
    }
}

void visualise(int matrix[9][9]) {
    for (int i=0; i<9; i++) {
        for(int j=0; j<9; j++){
            cout << matrix[i][j] << ' '; 
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void visualiseVec(vector<vector<vector<int>>>& vec) {
    for (int i=0; i<vec.size(); i++) {
        for(int j=0; j != vec[i].size(); j++){
            for (int k = 0; k != vec[i][j].size(); k++)
                {   
                    cout << vec[i][j][k];
                }
                cout << ' ';
         }
         cout << endl;
    }
    cout << endl;
    return;
}

int main()
{   
    // ## setup
    hor_solve(frame, hor_frame);
    transpose(hor_frame, ver_frame);
    intSolveSetup(frame);


    // ## initial frame:
    visualise(frame);


    // ## solving + visualising
    intSolve(frame);
    //visualiseVec(solveFrame);


    // ## finial frame:
    visualise(frame);

    return 0;
}