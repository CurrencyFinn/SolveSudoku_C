#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

// 0 => no entry

// TAKS combination with horizontal solving vector towards the frame aka doing a hor_solve for solving vector and transposition for the vertical solving vector then making that function a class with solving, tranposing, transforming
// !!!universal solving frame!!!


//int checkArray[9] = {1,2,3,4,5,6,7,8,9};
int frame[9][9] = { {4,8,1,7,6,9,3,5,0}, {5,6,0,3,2,4,0,7,0}, {3,0,0,1,5,0,6,0,0}, {0,9,7,1,0,0,5,4,0}, {0,8,5,0,0,6,1,0,0}, {2,1,0,5,4,0,0,8,6}, {0,7,6,2,0,5,9,3,4}, {9,5,3,0,4,0,0,0,0}, {0,2,0,0,3,0,0,6,5} };
vector<vector<int>> vecFrame = { {4,8,1,7,6,9,3,5,0}, {5,6,0,3,2,4,0,7,0}, {3,0,0,0,5,0,6,0,0}, {0,9,7,1,0,0,5,4,0}, {0,8,5,0,0,6,1,0,0}, {2,1,0,5,4,0,0,8,6}, {0,7,6,2,0,5,9,3,4}, {9,5,3,0,4,0,0,0,0}, {0,2,0,0,3,0,0,6,5} };
int horFrame[9][9];
vector<vector<int>> horVector (9, vector<int>(9));
int verFrame[9][9];
vector<vector<int>> verVector (9, vector<int>(9));

int checkArray[9] = {1,2,3,4,5,6,7,8,9};

vector<vector<vector<int>>> solveFrame(9, vector<vector<int> > (9, vector<int>(9)));
int intCount =0;

// internal block 



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

void intSolveSetupVector(vector<vector<int>>& inputVector)
{
    for (int i=0; i<solveFrame.size(); i++) {
        for(int j = 0; j != solveFrame[i].size(); j++)
        {   
            if (inputVector[i][j] != 0) {
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
                else {
                    intCount++;
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


void intSolveVector(vector<vector<int>>& inputVector)
{
    for (int i =0; i<9; i++)
    {
        vector<int> tempVec;
        for (int j=0; j<9; j++) {
            tempVec.push_back(inputVector[i][j]);
        }
        for (int k=0; k<9; k++)
        if (solveFrame[i][k][0] != 0) {
            for (int l=0; l<9; l++) {
                vector<int>::iterator it = find(solveFrame[i][k].begin(), solveFrame[i][k].end(), tempVec[l]); 
                if (it != solveFrame[i][k].end()) {
                    solveFrame[i][k].erase(it);
                }
                else {
                    intCount++;
                }
                if (solveFrame[i][k].size() == 1) {
                    inputVector[i][k] = solveFrame[i][k][0];
                    solveFrame[i][k][0] = 0;
                }
            }
        }
    }
    return;
}



// horizonatal rows

void horSolve(int inputMatrix[9][9], int outputMatrix[9][9])
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

void vecHorSolve(vector<vector<int>>& inputVector, vector<vector<int>>& outputVector)
{
    int acount = 0;
    int bcount = 0;
    int ccount = 0;
    for(int i = 0; i<inputVector.size(); i++)
    {
        if(i < 3) // first row block
        {
            for(int b = 0; b != inputVector[i].size(); b++) {          
                if(b <3) // first segment row
                {
                    if (acount >8) {
                        acount = 0;
                    }
                    outputVector[0][acount] = inputVector[i][b];
                    acount++;
                }
                else if (b>2 && b<6) // second segment row
                {
                    if (bcount >8) {
                        bcount = 0;
                    }
                    outputVector[1][bcount] = inputVector[i][b];
                    bcount++;
                } 
                else // third segment row
                {
                    if (ccount > 8) {
                        ccount = 0;
                    }
                    outputVector[2][ccount] =  inputVector[i][b];
                    ccount++;
                }
            }
        }  
        else if (i>2 && i<6) // second row block
        {
            for(int b = 0; b!= inputVector[i].size(); b++) {
                if(b <3) // first segment row
                {
                    if (acount >8) {
                        acount = 0;
                    }
                    outputVector[3][acount] = inputVector[i][b];
                    acount++;
                }
                else if (b>2 && b<6) // second segment row
                {
                    if (bcount >8) {
                        bcount = 0;
                    }
                    outputVector[4][bcount] = inputVector[i][b];
                    bcount++;
                } 
                else // third segment row
                {
                    if (ccount > 8) {
                        ccount = 0;
                    }
                    outputVector[5][ccount] = inputVector[i][b];
                    ccount++;
                }
            }
        } 
        else // third row block
        {
            for(int b = 0; b!= inputVector[i].size(); b++) {
                if(b <3) // first segment row
                {
                    if (acount >8) {
                        acount = 0;
                    }
                    outputVector[6][acount] = inputVector[i][b];
                    acount++;
                }
                else if (b>2 && b<6) // second segment row
                {
                    if (bcount >8) {
                        bcount = 0;
                    }
                    outputVector[7][bcount] = inputVector[i][b];
                    bcount++;
                } 
                else // third segment row
                {
                    if (ccount > 8) {
                        ccount = 0;
                    }
                    outputVector[8][ccount] = inputVector[i][b];
                    ccount++;
                }
            }
        }
    }
    return;
}

void vecHorSolve3D(vector<vector<vector<int>>>& inputVector, vector<vector<vector<int>>>& outputVector)
{
    int acount = 0;
    int bcount = 0;
    int ccount = 0;
    for(int i = 0; i<inputVector.size(); i++)
    {
        if(i < 3) // first row block
        {
            for(int b = 0; b != inputVector[i].size(); b++) {          
                if(b <3) // first segment row
                {
                    if (acount >8) {
                        acount = 0;
                    }
                    outputVector[0][acount] = inputVector[i][b];
                    acount++;
                }
                else if (b>2 && b<6) // second segment row
                {
                    if (bcount >8) {
                        bcount = 0;
                    }
                    outputVector[1][bcount] = inputVector[i][b];
                    bcount++;
                } 
                else // third segment row
                {
                    if (ccount > 8) {
                        ccount = 0;
                    }
                    outputVector[2][ccount] =  inputVector[i][b];
                    ccount++;
                }
            }
        }  
        else if (i>2 && i<6) // second row block
        {
            for(int b = 0; b!= inputVector[i].size(); b++) {
                if(b <3) // first segment row
                {
                    if (acount >8) {
                        acount = 0;
                    }
                    outputVector[3][acount] = inputVector[i][b];
                    acount++;
                }
                else if (b>2 && b<6) // second segment row
                {
                    if (bcount >8) {
                        bcount = 0;
                    }
                    outputVector[4][bcount] = inputVector[i][b];
                    bcount++;
                } 
                else // third segment row
                {
                    if (ccount > 8) {
                        ccount = 0;
                    }
                    outputVector[5][ccount] = inputVector[i][b];
                    ccount++;
                }
            }
        } 
        else // third row block
        {
            for(int b = 0; b!= inputVector[i].size(); b++) {
                if(b <3) // first segment row
                {
                    if (acount >8) {
                        acount = 0;
                    }
                    outputVector[6][acount] = inputVector[i][b];
                    acount++;
                }
                else if (b>2 && b<6) // second segment row
                {
                    if (bcount >8) {
                        bcount = 0;
                    }
                    outputVector[7][bcount] = inputVector[i][b];
                    bcount++;
                } 
                else // third segment row
                {
                    if (ccount > 8) {
                        ccount = 0;
                    }
                    outputVector[8][ccount] = inputVector[i][b];
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

void transposeVector2D(vector<vector<int>>& inputVector, vector<vector<int>>& outputVector) {
     for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            outputVector[j][i] = inputVector[i][j];
      }
    }
}

void transposeVector3D(vector<vector<vector<int>>>& inputVector, vector<vector<vector<int>>>& outputVector) {
     for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            outputVector[j][i] = inputVector[i][j];
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


void visualiseVec2D(vector<vector<int>>& vec) {
    for (int i=0; i<vec.size(); i++) {
        for(int j=0; j != vec[i].size(); j++){
            cout << vec[i][j];
         }
         cout << ' ';
    }
    cout << endl;
    return;
}


void visualiseVec3D(vector<vector<vector<int>>>& vec) {
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

void writeOutfile(int inputMatrix[9][9]) {
  ofstream outFile ("output.txt");
  if (outFile.is_open())
  {
    for(int i = 0; i < 9; i++){
        for(int j=0; j<9; j++) {
            outFile << inputMatrix[i][j] << " " ;
            if (j==2) {
                outFile << "  ";
            }
            if (j==5) {
                outFile << "  ";
            }
            if (j==8) {
                outFile << "  ";
            }
        }
        outFile << "\n";
        if (i==2) {
            outFile << "\n";
        }
        if (i==5) {
            outFile << "\n";
        }
    }
    outFile.close();
  }
  else cout << "Unable to open file";
  return;

}

int main()
{   
                                // ## setup
                                // while(int_count !=27) {

                                // }
                                //horSolve(frame, horFrame);
                                //transpose(hor_frame, verFrame);
                                //intSolveSetup(horFrame);
                                // # vector
                                // vecHorSolve(vecFrame, horVector);
                                // transposeVector2D(horVector, verVector);
                                // intSolveSetupVector(vecFrame);


                                // ## initial frame:
                                //visualise(horFrame);

                                // # vector
                                // visualiseVec2D(horVector);


                                // ## solving + visualising
                                //intSolve(horFrame);
                                //visualiseVec(solveFrame);

                                // # vector
                                // vecHorSolve3D(solveFrame, solveFrame);
                                // intSolveVector(horVector);

                                // ## finial frame:
                                //visualise(horFrame);
                                //hor_solve(frame, horFrame);

                                // # vector
                                // visualiseVec2D(horVector);

                                //writeOutfile(horFrame);

                                // solving

    // setup
    visualiseVec2D(vecFrame);
    cout << ' ' << endl;

    vecHorSolve(vecFrame, horVector);
    transposeVector2D(horVector, verVector);

    // initialize solving system

    intSolveSetupVector(vecFrame);
    // internal solving
    

    while(intCount < 900) {
        intSolveVector(vecFrame);

        // horizontal solving

        vecHorSolve3D(solveFrame, solveFrame);
        intSolveVector(horVector);

        // vertical solving

        transposeVector3D(solveFrame, solveFrame);
        intSolveVector(verVector);

        // return to normal state

        transposeVector3D(solveFrame, solveFrame);
        vecHorSolve3D(solveFrame, solveFrame);

        visualiseVec3D(solveFrame);
    }

    // visualise result

    intSolveSetupVector(vecFrame);

    cout << ' ' << endl;
    visualiseVec2D(vecFrame);


    return 0;
}