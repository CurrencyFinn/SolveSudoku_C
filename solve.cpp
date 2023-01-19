#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

// 0 => no entry

// TAKS combination with horizontal solving vector towards the frame aka doing a hor_solve for solving vector and transposition for the vertical solving vector then making that function a class with solving, tranposing, transforming
// !!!universal solving frame!!!
// new way of solving instead of a vector that decreases in size an array with size 9 that has values in it, deleting value if the zero amount is not equal to 8, problem now is that the vector size changes and therefore some weird changes occur. Maybe later on move back to vectors.


//int checkArray[9] = {1,2,3,4,5,6,7,8,9};
int frame[9][9] = { {4,8,1,7,6,9,3,5,0}, {5,6,0,3,2,4,0,7,0}, {3,0,0,0,5,0,6,0,0}, {0,9,7,1,0,0,5,4,0}, {0,8,5,0,0,6,1,0,0}, {2,1,0,5,4,0,0,8,6}, {0,7,6,2,0,5,9,3,4}, {9,5,3,0,4,0,0,0,0}, {0,2,0,0,3,0,0,6,5} };
int horFrame[9][9];
int verFrame[9][9];
//int outputFrame[9][9];
int checkArray[9] = {1,2,3,4,5,6,7,8,9};
vector<vector<vector<int>>> tempFrame(9, vector<vector<int> > (9, vector<int>(9)));
vector<vector<vector<int>>> solveFrame(9, vector<vector<int> > (9, vector<int>(9)));
int intCount =0;
int quitLoop =0;
// internal block 

void intSolveSetup(int inputMatrix[9][9])
{
    for (int i=0; i<solveFrame.size(); i++) {
        for(int j = 0; j != solveFrame[i].size(); j++)
        {   
            if (inputMatrix[i][j] != 0) {
                //outputFrame[i][j] = inputMatrix[i][j]; // only shows filled in entries
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
        for (int k=0; k<9; k++) 
        {
            if(frame[i][k] ==0) {
                tempVec.clear();
                for (int j=0; j<9; j++) {
                    if (inputMatrix[i][j] != 0) {
                        tempVec.push_back(inputMatrix[i][j]);
                    }
                    // this function could perhaps be moved outside the k function
                }
                //every single position on the frame // tempVec !=8 so it doesnt have to solve horizontal and vertical because its already has the solution by internal solving
                if (tempVec.size() != 8) {
                    vector<int> PositionVec;
                    if(i<3) { // change later to < 3
                        if(k<3) {
                            for(int p=0;p<9;p++) {
                                tempVec.push_back(horFrame[0][p]);
                                tempVec.push_back(verFrame[k+3*i][p]);
                            }
                        }
                        if(k>2 && k<6) {
                            for(int p=0;p<9;p++) {
                                tempVec.push_back(horFrame[1][p]);
                                tempVec.push_back(verFrame[(k-3)+3*i][p]);
                            }
                        }
                        if (k>5) {
                            for(int p=0;p<9;p++) {
                                tempVec.push_back(horFrame[2][p]);
                                tempVec.push_back(verFrame[(k-6)+3*i][p]);
                            }
                        }
                    }
                    if(i>2 && i<6) {
                        if(k<3) {
                            for(int p=0;p<9;p++) {
                                tempVec.push_back(horFrame[3][p]);
                                tempVec.push_back(verFrame[k+3*(i-3)][p]);
                            }
                        }
                        if(k>2 && k<6) {
                            for(int p=0;p<9;p++) {
                                tempVec.push_back(horFrame[4][p]);
                                tempVec.push_back(verFrame[(k-3)+3*(i-3)][p]);
                            }
                        }
                        if (k>5) {
                            for(int p=0;p<9;p++) {
                                tempVec.push_back(horFrame[5][p]);
                                tempVec.push_back(verFrame[(k-6)+3*(i-3)][p]);
                            }
                        }
                    }
                    if(i>5) {
                        if(k<3) {
                            for(int p=0;p<9;p++) {
                                tempVec.push_back(horFrame[6][p]);
                                tempVec.push_back(verFrame[k+3*(i-6)][p]);
                            }
                        }
                        if(k>2 && k<6) {
                            for(int p=0;p<9;p++) {
                                tempVec.push_back(horFrame[7][p]);
                                tempVec.push_back(verFrame[(k-3)+3*(i-6)][p]);
                            }
                        }
                        if (k>5) {
                            for(int p=0;p<9;p++) {
                                tempVec.push_back(horFrame[8][p]);
                                tempVec.push_back(verFrame[(k-6)+3*(i-6)][p]);
                            }
                        }

                        // add positional values for row and column values as input i and k! where i is outside array and k is inside array.
                        // For 3 every steps, horizontal increases by 1, while inside these 3 steps vertical increases 1 step
                    }
                }
                sort(tempVec.begin(), tempVec.end()); // v 
                tempVec.erase(unique(tempVec.begin(),tempVec.end()), tempVec.end()); // have to test if this speeds up the n^2 loop size 
                if (tempVec[0] == 0) {
                    tempVec.erase(tempVec.begin());
                }

                // for(int i=0;i<tempVec.size();i++) {
                //     cout<<tempVec[i]<<' ';
                // }
                // cout<<endl; // visualize 

                if (solveFrame[i][k][0] != 0) {
                    for (int l=0; l<tempVec.size(); l++) {
                        vector<int>::iterator it = find(solveFrame[i][k].begin(), solveFrame[i][k].end(), tempVec[l]); 
                        if (it != solveFrame[i][k].end()) {
                            solveFrame[i][k].erase(it);
                        } 
                    }
                    if (solveFrame[i][k].size() == 1) {
                        frame[i][k] = solveFrame[i][k][0];
                        solveFrame[i][k][0] = 0;
                    }
                    if(quitLoop ==3) { // remove this later now for testing
                            vector<int> uniqueTempVec;
                            // for_each(solveFrame[i][k].begin(), solveFrame[i][k].end(), [&] (int n) {
                            //     uniqueTempVec.push_back(n);
                            // });
                            //cout<<solveFrame[i][k].size();
                            //for(int l=0;l<solveFrame[i][k].size();l++) {
                            //uniqueTempVec.insert(solveFrame[i][k].begin(), solveFrame[i][k].end(), solveFrame[i][k][l]);
                            uniqueTempVec.insert(uniqueTempVec.end(), solveFrame[i][k].begin(), solveFrame[i][k].end());
                            //}
                            // vector<int>::iterator it;
                            // it = unique(uniqueTempVec.begin(), uniqueTempVec.end());  
                            // cout <<  "\t" << *it;
                            for(int z=0;z<uniqueTempVec.size();z++) {
                                cout<<uniqueTempVec[z]<< ' ';
                            }
                            cout<<endl;
                    }
                } 
            }
            else {
                intCount++; // the amount of open spots to be solved in THE PREVIOUS FRAME
            }
        }
        tempVec.clear();
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
    horSolve(frame, horFrame);
    transpose(horFrame, verFrame);
    // initialize solving system
    intSolveSetup(frame);

    // internal solving
    
    while(intCount<81) {
        intCount=0;
        intSolve(frame);
        quitLoop++;
        if(quitLoop ==4) {
            intCount=81;
            cout<<"quit loop with max loops"<<endl;
            cout<<endl;
        }
    }

    
    visualiseVec3D(solveFrame);
    visualise(frame);

    return 0;
}