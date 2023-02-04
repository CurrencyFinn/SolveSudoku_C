#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// 0 => no entry
//int frame[9][9] = { {0,1,0,8,0,0,0,0,3}, {5,6,0,0,0,0,0,0,0}, {0,0,0,6,7,5,0,0,0}, {4,0,0,0,0,0,3,0,0}, {9,0,5,8,0,0,0,0,0}, {0,0,8,0,1,0,0,0,6}, {9,0,2,0,3,7,0,0,6}, {7,5,0,0,0,4,0,8,0}, {0,0,0,2,0,0,5,9,0} }; 
//int frame[9][9] = { {5,3,0,6,0,0,0,9,8}, {0,7,0,1,9,5,0,0,0}, {0,0,0,0,0,0,0,6,0}, {8,0,0,4,0,0,7,0,0}, {0,6,0,8,0,3,0,2,0}, {0,0,3,0,0,1,0,0,6}, {0,6,0,0,0,0,0,0,0}, {0,0,0,4,1,9,0,8,0}, {2,8,0,0,0,5,0,7,9} }; // wikipedia sudoku
//int frame[9][9] = { {4,8,1,7,6,9,3,5,0}, {5,6,0,3,2,4,0,7,0}, {3,0,0,0,5,0,6,0,0}, {0,9,7,1,0,0,5,4,0}, {0,8,5,0,0,6,1,0,0}, {2,1,0,5,4,0,0,8,6}, {0,7,6,2,0,5,9,3,4}, {9,5,3,0,4,0,0,0,0}, {0,2,0,0,3,0,0,6,5} }; //filled in png
int importMatrix[9][9];
int outputMatrix[9][9];
int horFrame[9][9];
int verFrame[9][9];
int checkArray[9] = {1,2,3,4,5,6,7,8,9};
vector<vector<vector<int>>> solveFrame(9, vector<vector<int> > (9, vector<int>(9)));
int intCount =0;
int intCountInternal =0;
int quitLoop =0;
int partialFrameChecker = 0;

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
        for (int k=0; k<9; k++) 
        {
            if(inputMatrix[i][k] ==0) {
                tempVec.clear();
                for (int j=0; j<9; j++) {
                    if (inputMatrix[i][j] != 0) {
                        tempVec.push_back(inputMatrix[i][j]);
                    }
                }
                if (tempVec.size() != 8) { // tempVec !=8 sono need to solve horizontal and vertical
                    vector<int> PositionVec;
                    if(i<3) {
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
                    }
                }
                sort(tempVec.begin(), tempVec.end()); // below
                tempVec.erase(unique(tempVec.begin(),tempVec.end()), tempVec.end()); 
                if (tempVec[0] == 0) {
                    tempVec.erase(tempVec.begin());
                }
                // for(int i=0;i<tempVec.size();i++) {
                //     cout<<tempVec[i]<<' ';
                // }
                // cout<<endl; // visualize solving
                if (solveFrame[i][k][0] != 0) {
                    for (int l=0; l<tempVec.size(); l++) {
                        vector<int>::iterator it = find(solveFrame[i][k].begin(), solveFrame[i][k].end(), tempVec[l]); 
                        if (it != solveFrame[i][k].end()) {
                            solveFrame[i][k].erase(it);
                            intCountInternal++;
                        } 
                    }
                    if (solveFrame[i][k].size() == 1) {
                        inputMatrix[i][k] = solveFrame[i][k][0];
                        solveFrame[i][k][0] = 0;
                    }
                } 
            }
            else {
                intCount++; // the amount of open spots to be solved in THE PREVIOUS FRAME can be improved to be moved somewhere else
            }
        }
        tempVec.clear();
        
        if(intCountInternal==0) { // remove this later now for testing // between >13 something goes wrong
            vector<int> uniqueTempVec;
            // create all possible values in an vector 
            for (int k=0; k<solveFrame[i].size();k++) 
            {
                for(int z=0; z<solveFrame[i][k].size();z++) {
                    if(solveFrame[i][k].size()!=1){
                        uniqueTempVec.push_back(solveFrame[i][k][z]);
                    }
                }
            }
            sort(uniqueTempVec.begin(), uniqueTempVec.end()); 
            // for(int z=0;z<uniqueTempVec.size();z++) {
            //     cout<<uniqueTempVec[z]<< ' ';
            // }
            // cout<<endl; //visualize
            if(uniqueTempVec.size() >1){ // !0 or >2
                if (uniqueTempVec[0] != uniqueTempVec[1])
                    for (int k=0; k<9; k++) 
                    {
                        vector<int>::iterator it = find(solveFrame[i][k].begin(), solveFrame[i][k].end(), uniqueTempVec[0]); 
                        if (it != solveFrame[i][k].end()) {
                            for(int l=0;l<9;l++) {
                                if(inputMatrix[i][l] == uniqueTempVec[0]) {
                                    solveFrame[i][k].erase(it);
                                    partialFrameChecker++;
                                }
                            }
                            if (partialFrameChecker== 0){ 
                                solveFrame[i][k].resize(1);
                                solveFrame[i][k][0] = 0;
                                inputMatrix[i][k]= uniqueTempVec[0];
                            } else {
                                partialFrameChecker =0;
                            }
                        } 
                    }
                // Adjecent cell check
                for (int p = 1; p < uniqueTempVec.size()- 1; p++)
                    if (uniqueTempVec[p] != uniqueTempVec[p + 1] && uniqueTempVec[p] != uniqueTempVec[p - 1])
                        for (int k=0; k<9; k++) 
                        {
                            vector<int>::iterator it = find(solveFrame[i][k].begin(), solveFrame[i][k].end(), uniqueTempVec[p]); 
                            if (it != solveFrame[i][k].end()) {
                                for(int l=0;l<9;l++) {
                                    if(inputMatrix[i][l] == uniqueTempVec[p]) {
                                        solveFrame[i][k].erase(it);
                                        partialFrameChecker++;
                                    }
                                }
                                if (partialFrameChecker== 0){ 
                                solveFrame[i][k].resize(1);
                                solveFrame[i][k][0] = 0;
                                inputMatrix[i][k]= uniqueTempVec[p];
                                } else {
                                    partialFrameChecker=0;
                                }
                            } 
                        }
                // Check for the last element
                if (uniqueTempVec[uniqueTempVec.size() - 2] != uniqueTempVec[uniqueTempVec.size() - 1])
                    for (int k=0; k<9; k++) 
                    {
                        vector<int>::iterator it = find(solveFrame[i][k].begin(), solveFrame[i][k].end(), uniqueTempVec[uniqueTempVec.size() - 1]); 
                        if (it != solveFrame[i][k].end()) {
                            for(int l=0;l<9;l++) {
                                if(inputMatrix[i][l] == uniqueTempVec[uniqueTempVec.size() - 1]) {
                                    solveFrame[i][k].erase(it);
                                    partialFrameChecker++;
                                }
                            }
                            if (partialFrameChecker== 0){ 
                                solveFrame[i][k].resize(1);
                                solveFrame[i][k][0] = 0;
                                inputMatrix[i][k]= uniqueTempVec[uniqueTempVec.size() - 1];
                            } else {
                                partialFrameChecker=0;
                            }
                            
                        } 
                    }
            }
        }
        intCountInternal =0;
    }
    return;
}
void horSolve(int inputMatrix[9][9], int outputMatrix[9][9]) // horizonatal rows
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
void writeOutfile(int inputMatrix[9][9]) { // change , to ; for excel read // must be the horizontal frame
  ofstream outFile ("resources\\output.csv");
  if (outFile.is_open())
  {
    for(int i = 0; i < 9; i++){
        for(int j=0; j<9; j++) { // every line has 9 characters
            
            outFile << inputMatrix[i][j] <<",";
            if (j==2) {
                outFile << ",";
            }
            if (j==5) {
                outFile << ",";
            }
        }
        outFile << "\n";
        if(i==2) {
            outFile<<"\n";
        }
        if(i==5) {
            outFile<<"\n";
        }
    }
    outFile.close();
  }
  else cerr << "error: file open failed."<<endl;
  return;
}
void readImportfile(string ImportFile) {
    ifstream ReadableFile;
    ReadableFile.open("resources\\"+ImportFile);
    if (!ReadableFile.is_open()) {
        cerr << "error: file open failed " << ImportFile << ".\n";
        return;
    }
    string line;
    vector<vector<int>> writeVector;
    int val;       
    int outerIndex =0;
    int innerIndex =0;
    while (getline(ReadableFile,line))
    {    
        stringstream ss(line);
        while(ss >> val){ 
            if(innerIndex >8) {
                outerIndex++;
                innerIndex = 0;
            }
            importMatrix[outerIndex][innerIndex] = val;
            innerIndex++;
            if(ss.peek() == ',') ss.ignore();
            if(ss.peek() == ',') {
                ss.ignore();
            }
        }      
    }
    horSolve(importMatrix, outputMatrix); //outputMatrix is frame.
    ReadableFile.close();
    return;
}
int main()
{   
    string impFile;
    cout<<"Name import file: ";
    cin>> impFile;
    auto start = high_resolution_clock::now();
    readImportfile(impFile);
    horSolve(outputMatrix, horFrame);
    transpose(horFrame, verFrame);
    intSolveSetup(outputMatrix);  // initialize solving system
    while(intCount<81) { // internal solving
        intCount=0;
        intSolve(outputMatrix);
        horSolve(outputMatrix, horFrame);
        transpose(horFrame, verFrame);
        quitLoop++;
        if(quitLoop ==100) { // max loops that will be ran.
            intCount=81;
            cout<<"quit loop with max loops"<<endl;
            cout<<endl;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"After " << quitLoop<< " procedures sudoku was solved in: "<<duration.count()<< "ms" <<endl;
    //visualiseVec3D(solveFrame); // should be all 0 for debug.
    visualise(outputMatrix);
    writeOutfile(horFrame);
    return 0;
}