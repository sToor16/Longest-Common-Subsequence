#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

/*
 * Some parts of the code were directly copied from open source website such as cplusplusrefrence.com
 * Reference to code will be provided directly above the code throughout the program
 */

/*
 * The c++ version used was 11
 * CLion IDE was used to write the code
 * To make the code work simple open this project and press run button
 * IF any compiliation error occur, please let me know
 * ID-1001564975
 * email-shubhpreetsingh.toor@mavs.uta.edu
 */

/*
 * Clock time reference from
 * http://www.cplusplus.com/reference/ctime/clock/
 * the following clock time method returns clock time when called and this will be displayed
 */

int frequency_of_primes (int n) {
    int i,j;
    int freq=n-1;
    for (i=2; i<=n; ++i) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
    return freq;
}

/*
 * subSequence method is declared
 * This methid will be used for second method i.e lsis method
 * This method will take the combinedSequence array(Combination of two indices)
 * This method will return a vector
 * Returning vector will be a longest increaasing subsequence of the combined indeices array array
 * refernce to the code : https://www.geeksforgeeks.org/longest-increasing-subsequence/
 * reference to the code: https://www.geeksforgeeks.org/longest-common-increasing-subsequence-lcs-lis/
 */

std::vector<int> subSequence(int combinedSequence[], int length)  {
    int lis[length];

    for (int i= 0; i < length; i++) {
        int max = -1;
        for (int j = 0; j < i; j++) {
            // check if previous elements > current element
            if (combinedSequence[i] > combinedSequence[j]) {
                // update the max from the previous entries
                if (max == -1 || max < lis[j] + 1) {
                    max = 1 + lis[j];
                }
            }
        }
        if (max== -1) {
            max = 1;
        }
        lis[i] = max;
    }

    int result = 0;
    int index = 0;

    for (int i = 0; i < length; i++) {
        if (result < lis[i]) {
            result = lis[i];
            index = i;
        }
    }

    std::vector<int> resultSequence;
    resultSequence.push_back(combinedSequence[index]);

    int res = result - 1;
    for (int i = index-1; i >= 0; i--) {
        if(lis[i]==res){
            resultSequence.push_back(combinedSequence[i]);
            res--;
        }
    }

    return(resultSequence);
}

/*
 * lcs methood is declared
 * This method will be used for findind lcs of inputted arrays
 * This is the first method of the lab
 * This will also print the lcs matrix
 * This method will also print the length and actual sequence of lcs
 * Reference:(Method will be highly similar to) https://www.geeksforgeeks.org/longest-common-subsequence/
 *
 */
void lcs(int *fS, int *sS, int m, int n) {

    int costMatrix[m+1][n+1];

    for (int i=0; i<=m; i++) {

        for (int j=0; j<=n; j++) {

            if (i == 0 || j == 0) {
                costMatrix[i][j] = 0;
            }

            else if (fS[i-1] == sS[j-1]) {
                costMatrix[i][j] = costMatrix[i - 1][j - 1] + 1;
            }

            else {
                costMatrix[i][j] = fmax(costMatrix[i - 1][j], costMatrix[i][j - 1]);
            }
        }
    }
    std::cout << std::endl;
    std::cout << "Length of LCS is : ";
    std::cout << costMatrix[m][n];
    std::cout << std::endl;

    std::cout << std::endl;
    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            std::cout << costMatrix[i][j];
            std::cout << "   ";
        }
        std::cout << std::endl;
    }

    int i=m;
    int j=n;

    int index = costMatrix[m][n];

    // Create a character array to store the lcs string
    int lcs[index+1];
    lcs[index] = '\0';

    while (i > 0 && j > 0)
    {
        if (fS[i-1] == sS[j-1])
        {
            lcs[index-1] = fS[i-1];
            i--; j--; index--;
        }
        else if (costMatrix[i-1][j] > costMatrix[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    std::cout << std::endl;
    std::cout << "Longest Common Subsequence is: ";
    for (int i=0; i<costMatrix[m][n]; i++) {
        std::cout << lcs[i];
        if (i < costMatrix[m][n] -1) {
            std::cout << ",";
        }
    }
    std::cout << std::endl;
}

/*
 * Main method of the program
 */

int main() {

    int m, n;
    clock_t t1,t2;
    int f;


    /*
     * The following two for loops will run until user enters the length
     * The length accepted will be less than 25000
     * If length less than 1 or greater tha 25000 is given user will have to reenter length
     */
    for (; ;) {
        std::cout<<"Enter length of sequence one: ";
        std::cin >> m;
        if (m < 25000 && m > 0) {
            break;
        }
        std::cout  << "Enter valid length larger than 0 and shorter then 25000: ";
    }
    for (; ;) {
        std::cout<<"Enter lenght of sequence two: ";
        std::cin >> n;
        if (n < 25000 && n > 0) {
            break;
        }
        std::cout  << "Enter valid ength larger than 0 and shorter then 25000: ";
    }

    /*
     * Declaring the two sequence
     * The following two for loops will be used to enter each integer one by one
     * These loops will also verify that range of integer user can enter will be betwenn 0 and 255
     * After entering the sequences a -1 will be displayed
     */

    int firstSequence[m];
    int secondSequence[n];

    for (int i=0; i < m; i++) {
        std::cout << "Enter first sequence " << i+1;
        std::cout << ": ";
        std::cin >> firstSequence[i];
        for(;;) {
            if ( firstSequence[i] > 0 && firstSequence[i] < 255) {
                break;
            }
            std::cout << "Entered number out of range (should be between 0 and 255), Again ";
            std::cout << "enter first sequence " << i+1;
            std::cout << ": ";
            std::cin >> firstSequence[i];
        }
        //firstSequence[i] = 1;
    }
    std::cout << "-1" << std::endl;

    for (int i=0; i < n; i++) {
        std::cout << "Enter second sequence: " << i+1;
        std::cout << ": ";
        std::cin >> secondSequence[i];
        for(;;) {
            if ( secondSequence[i] > 0 && secondSequence[i] < 255) {
                break;
            }
            std::cout << "Entered number out of range (should be between 0 and 255), Again ";
            std::cout << "enter second sequence " << i+1;
            std::cout << ": ";
            std::cin >> secondSequence[i];
        }
        //secondSequence[i] = 2;

    }
    std::cout << "-1" << std::endl;

    t1 = clock(); // starting the clock of 1st method
    lcs(firstSequence, secondSequence, m,n);  // calling the lcs method
    t1 = clock() - t1;   // ending the clock for 1st method
    float time = (float) t1 / CLOCKS_PER_SEC;


    /*
     * For the second method (lsis) a unordered map will be used
     * The unordered map will have single integer values as keys and vector of values for indices
     */
    std::unordered_map< int, std::vector<int> > keyAndIndices;
    std::cout << std::endl << "now from lsis method" << std::endl;


    t2 = clock(); // starting the clock of 2nd method

    /*
     * This for loop will scan the map and if and index or element is not entered via this loop it wll be entered
     * Reference from: http://www.cplusplus.com/reference/unordered_map/unordered_map/find/
     * https://stackoverflow.com/questions/4395050/finding-value-in-unordered-map
     * https://www.geeksforgeeks.org/unordered_map-in-stl-and-its-applications/
     */
    for(int i=n-1;i>=0;i--) {
        std::vector<int> indicesVector;

        auto itr1 = keyAndIndices.find(secondSequence[i]);
        if (itr1 != std::end(keyAndIndices)) {
            auto& v = itr1->second;
            for (auto z : v) {

                indicesVector.push_back(z);
            }
            keyAndIndices.erase (itr1);
        }
        indicesVector.push_back(i);
        keyAndIndices.insert(make_pair(secondSequence[i],indicesVector));
    }

    /*
     * The following for loop will display the map
     * http://www.cplusplus.com/forum/beginner/161248/
     */

    {
        for( const auto& pair : keyAndIndices )
        {
            std::cout << "key: " << pair.first << "  value: [  " ;
            for( int d : pair.second ) std::cout << d << "  " ;
            std::cout << "]\n" ;
        }
    }

    /*
     * initializing an vector that will store the combined sequence values
     * This vector will compare the key values from map and then add the indices for that matched key into the vector
     * Reference from: http://www.cplusplus.com/forum/beginner/161248/
     */

    std::vector<int> combinedSequenceTemp;

    for(int i=0;i<m;i++) {

        auto itr2 = keyAndIndices.find(firstSequence[i]);
        if (itr2 != std::end(keyAndIndices)) {
            auto& v = itr2->second;
            for (auto z : v) {
                combinedSequenceTemp.push_back(z);
            }
        }
    }

    std::cout << std::endl << "Combined Sequence(from indices): ";
    int combinedSequence[combinedSequenceTemp.size()];
    std::copy(combinedSequenceTemp.begin(), combinedSequenceTemp.end(), combinedSequence);
    int length = sizeof(combinedSequence)/sizeof(combinedSequence[0]);
    for (int i=0;i<length;i++) {
        std::cout << combinedSequence[i];
    }

    int combinedSequenceSize = sizeof(combinedSequence)/ sizeof(combinedSequence[0]);
    if (combinedSequenceSize != 0) {


        std::vector<int> sLIS = subSequence(combinedSequence, length);


        std::cout << std::endl << "Longest Strictly Increasing Subsequence: ";
        std::reverse(sLIS.begin(), sLIS.end());

        std::vector<int> lcsFinal;

        for (std::vector<int>::const_iterator i = sLIS.begin(); i != sLIS.end(); ++i) {
            std::cout << *i << ' ';
            lcsFinal.push_back(secondSequence[*i]);
        }

        std::cout << std::endl << "Longest Common Subsequence; ";
        for (std::vector<int>::const_iterator i = lcsFinal.begin(); i != lcsFinal.end(); ++i) {
            std::cout << *i << ' ';
        }
        std::cout << std::endl << "Length of LCS is : " << lcsFinal.size() << std::endl;
        t2 = clock() - t2;


        std::cout << std::endl;
        printf("For LSIS method: %d clicks and time is: (%f seconds).\n", t1, ((float) t1) / CLOCKS_PER_SEC);
        printf("For LCS method: %d clicks and time is: (%f seconds).\n", t2, ((float) t2) / CLOCKS_PER_SEC);
    } else {
        std::cout << std::endl << "Longest Strictly Increasing Subsequence: ";
        std::cout << std::endl << "Longest Common Subsequence; ";
        std::cout << std::endl << "Length of LSIS is : ";
        std::cout << std::endl;
        printf("For LCS method: %d clicks and time is: (%f seconds).\n", t1, ((float) t1) / CLOCKS_PER_SEC);
        printf("For LCS method: %d clicks and time is: (%f seconds).\n", t2, ((float) t2) / CLOCKS_PER_SEC);
    }

}