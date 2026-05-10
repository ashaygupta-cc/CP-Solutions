class Solution {
public:
    # define ll long long
    vector<double> internalAngles(vector<int>& sides) {

      int a = sides[0];
      int b = sides[1];
      int c = sides[2];

      if(!(a+b > c && a+c > b && b+c > a)) return {};

      vector<double>An;

     An.push_back(((acos(double(a*a+b*b-c*c)/double(2*a*b)))*180.0)/M_PI);
     An.push_back(((acos(double(c*c+b*b-a*a)/double(2*b*c)))*180.0)/M_PI);
     An.push_back(((acos(double(a*a+c*c-b*b)/double(2*a*c)))*180.0)/M_PI);
        
     sort(An.begin(),An.end());
     return An;
    }
};