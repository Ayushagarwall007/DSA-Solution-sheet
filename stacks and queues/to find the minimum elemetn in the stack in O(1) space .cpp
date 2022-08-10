https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?topList=love-babbar-dsa-sheet-problems

// Problem Statement
// Sample Input 1:
// 6
// 1 13
// 1 47
// 5
// 4
// 2
// 3
// Sample Output 1:
// 13
// false
// 47
// 13
// Explanation Of Input 1:
// Here we have six queries in total.

// Query 1: Integer 1 represents the push function. Hence we push element ‘13’ onto the stack.

// Query 2: Integer 1 represents the push function. Hence we push element ‘47’ onto the stack.

// Query 3: Integer 5 represents the getMin function. Hence we print the minimum element present in the stack that is 13.

// Query 4: Integer 4 represents the isEmpty function. Hence here, we print false because the stack is not empty.

// Query 5: Integer 2 represents the pop function. The stack contains element ‘47’ at the top. We remove/pop ‘47’ from the stack and print ‘47’ on the new line.

// Query 6: Integer 3 represents the top function. Because we have element ‘13’ at the top of the stack, we print ‘13’ on the new line.




#include<stack>
#include<limits.h>
class SpecialStack {
    // Define the data members.
	stack<int> s;
    int mini = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else
        {
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }   
            else
            {
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty())
            return -1;
        
        return mini;
    }  
};
