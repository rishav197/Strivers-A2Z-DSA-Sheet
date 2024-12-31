
#include <cmath>

class Solution {
  public:
    double switchCase(int choice, vector<double> &arr) {
        double area;
        
        // when choice is 1
        if(choice==1){
            double r = arr[0];
            area = M_PI*pow(r, 2);
        }
        else{ //when choice is 2
            double l = arr[0];
            double b = arr[1];
            area = l*b;   
        }
        
        return area;
    }
};