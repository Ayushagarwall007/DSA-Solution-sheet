// Solve a given equation and return the value of 'x' in the form of a string "x=#value". The equation contains only '+', '-' operation, the variable 'x' and its coefficient. You should return "No solution" if there is no solution for the equation, or "Infinite solutions" if there are infinite solutions for the equation.

// If there is exactly one solution for the equation, we ensure that the value of 'x' is an integer.

 

// Example 1:

// Input: equation = "x+5-3+x=6+x-2"
// Output: "x=2"
// Example 2:

// Input: equation = "x=x"
// Output: "Infinite solutions"
// Example 3:

// Input: equation = "2x=x"
// Output: "x=0"
 

// Constraints:

// 3 <= equation.length <= 1000
// equation has exactly one '='.
// equation consists of integers with an absolute value in the range [0, 100] without any leading zeros, and the variable 'x'.




class Solution {
    
    private:
    int num(int i,int end, string eq)
    {
        char ch = '+';
        int left=0;
        while(i<end)
        {
            int x=0;
            while(i<end and isdigit(eq[i]))
            {
                x=x*10+(eq[i]-'0');
                i++;
            }
            if(i < end && eq[i] == 'x'){
                i++;
                continue;
            }
           left = left + (ch == '-' ? -x : + x);
            ch = eq[i];
            i++;
        }
        return left;
    }
    
    int xNum(int i, int start, string eq){
        int xVal = 0;
        while(i >= start){
            if(eq[i] == 'x'){
                i--;
                char ch = '+';
                int x = 0;
                int y = 1;
                while(i >= start && isdigit(eq[i])){
                    x = x + (eq[i]-'0')*y;
                    y *= 10;
                    i--;
                }
                if(y == 1) x = 1;
                if(i >= start) ch = eq[i];
                xVal = xVal + (ch == '-' ? -x : + x);
            }
            i--;
        }
        return xVal;
    }
    
    
public:
    string solveEquation(string eq) {
        int n=eq.size();
        int mid=0;
        while(eq[mid]!= '=')mid++;
        
        // before the = 
        int left=num(0,mid,eq);
        int xLeft=xNum(mid-1,0,eq);
        
        //After the =
        int right = num(mid+1, n, eq);
        int xRight = xNum(n-1, mid+1, eq);
        
        
                cout<<left<<" "<<right<<endl;
        cout<<xLeft<<" "<<xRight;
        
        if(xLeft==xRight and left== right)
            return "Infinite solutions";
        else if(xLeft==xRight)
        {
            return "No solution";
        }
  else if(xLeft > xRight){
            int x = xLeft-xRight;
            string str = "x=" + to_string((right-left)/x);
            return str;
        }
        else{
            int x = xRight-xLeft;
            string str = "x=" + to_string((left-right)/x);
            return str;
        }
        
    }
};
