//

//  main.cpp

//  Project D (retry 2)

//

//  Created by Anson Thai on 17/4/20.

//  Copyright © 2020 Anson Thai. All rights reserved.

//





using namespace std;

#include <vector>

#include <iostream>

#include <map>











int main(int argc, const char * argv[]) {

    

    

    //input

    int n;

    

    cin >> n;

    

    int array [n];

    char cArray [n];

    

    cin >> cArray;

    

    for (int i=0;i<n;i++) {

        array[i] = (int) cArray[i] -48;

    }

    

 

    

    

    //second method

    /*

    

    map<int, int> my_map;

    

    int total = 0;

    

    for (int i1=0;i1<n-2;i1++) {

        

        // if number at index is not found

        if (my_map.find(array[i1]) == my_map.end() ) {

            my_map[array[i1]] = 1;

            

            map<int, int> my_map2;

            

            for (int i2=i1+1;i2<n-1;i2++) {

                if (my_map2.find(array[i2]) == my_map2.end() ) {

                    my_map2[array[i2]] = 1;

                    map<int, int> my_map3;

                    

                    for (int i3=i2+1;i3<n;i3++) {

                        if (my_map3.find(array[i3]) == my_map3.end() ) {

                            my_map3[array[i3]] = 1;

                            total = total+1;

                            

                        }

                            

                            

                    }

                    

                    

                    

                    

                }

            }

            

            

        }

    }

    

    cout << total << endl;

    

    

    */

    

    

    

    

    

    

    

    

    int num_array [10] = {0,0,0,0,0,0,0,0,0,0};

    

    int unique_after_index[n];

    

    int index_array_first[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    int index_array_second[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    

    

    

    int unique_counter = 0;

    

    for (int i = n-1;i>=0;i--) {

        if (num_array[array[i]] == 0) {

            unique_after_index[i] = unique_counter;

            unique_counter ++;

            num_array[array[i]] += 1;

            

        } else {

            unique_after_index[i] = unique_counter;

            num_array[array[i]] += 1;

        }

        

        

        

    }

    

    int num_array2 [10] = {0,0,0,0,0,0,0,0,0,0};

 

    

    

    

    

    for (int i=0; i<n; i++) {

        if (num_array2[array[i]] == 0) {

            index_array_first[array[i]] = i;

        }

        

        if (num_array2[array[i]] == 1) {

            index_array_second[array[i]] = i;

        }

        

        num_array2[array[i]] += 1;

    }

    

    

    int first_index_unique_second_indexes[10][10] = {0};

    

    for (int i=0;i<10;i++) {

        for (int j=index_array_first[i]+1;j<n;j++) {

            if (first_index_unique_second_indexes[i][array[j]] == 0) {

                first_index_unique_second_indexes[i][array[j]] = j;

            }

        }

    }

    int result = 0;

    

    for (int i=0;i<10;i++) {

        

        for (int j=0;j<10;j++) {

            

            if (index_array_first[i]>=0 and first_index_unique_second_indexes[i][j]>0) {

                

                if ((index_array_first[i] < n-2) and (index_array_first[j] < n-1)) {

                    

                    result += unique_after_index[first_index_unique_second_indexes[i][j]];

                }

                

            }

        }

    

    }

    

    

    cout << result << "\n";

    

    

    

    

    

    

    return 0;

}
