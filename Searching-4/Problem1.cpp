// Deepthi loves cruises. She is going to visit the Caribbean on a Cruise.
//So, she thought of providing everyone who is traveling with her with lunch as well.
//Each food item is denoted by an integer ID. A lunch box contains exactly A food items
//She has a list of food items with her denoted by an integer array B.
//She asked you to tell her the maximum number of lunchboxes she can prepare.

// Note:
// A lunch box can contain multiple same kinds of food items but the content of each lunch box should be the same.
// Example Input
// Input 1:
// A = 3, B = [1, 2, 3, 2, 6, 1, 3]
// Input 2:
// A = 4, B = [1, 3, 1, 3, 10, 3, 6, 6, 13]
// Example Output
// Output 1:
// 2
// Output 2:
// 1
// Example Explanation
// Explanation 1:
// She can choose the content to be [1, 2, 3] and prepare 2 luchboxes
// Explanation 2:
// She can choose the content to be [1, 3, 3, 3]

#include<bits/stdc++.h>
using namespace std;

bool isPossible(unordered_map<int, int> &freq, int A, int targetBoxes){
    //we basically divide each item into each lunch box by dividing their frequency by lunches we need to make
    
    //edge case
    //cant divide with zero
    if(targetBoxes==0){
        return true;
    }
    
    long long totalFoodItemsPerBox = 0;
    
    for(auto it: freq){
        int xFoodPerBox = it.second/targetBoxes;
        totalFoodItemsPerBox+=xFoodPerBox;
    }
    
    return totalFoodItemsPerBox >= A;
}

int solve(vector<int> &arr, int A, int n){
    unordered_map<int, int> freq;
    int maxi = 0;
    for(auto it: arr){
        freq[it]++;
        maxi = max(maxi, freq[it]);
    }

    int low = 0;
    int high = maxi;

    int res = 0;

    while(low<=high){
        int mid = (low+high)/2;

        if(isPossible(freq, A, mid)){
            res = mid;
            low = mid+1;   //max boxes nikaalne h
        }else{
            high = mid-1;
        }
    }
    return res;
}

int main(){
    vector<int>arr = {1, 3, 1, 3, 10, 3, 6, 6, 13};
    int A = 4;

    cout << solve(arr, A, arr.size()) << endl;
    return 0;
}