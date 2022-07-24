// You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner
// is at the last row and column.

// You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid 
//   (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

// Return an array of coordinates representing the positions of the grid in the order you visited them
// Input: rows = 5, cols = 6, rStart = 1, cStart = 4
// Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],
//          [3,0],[2,0],[1,0],[0,0]]



class Solution
{
    public:
    vector<vector<int>>spiralMatrixIII(int rows,int cols,int rStart ,int cStart)
    {
        vector<vector<int>>ans;
        //visited node array 
        // iss array mai hum visited element kaa record track kaarenge
        vector<vector<bool>>isvisited(rows,vector<bool>(cols,false));
        int top=rStart,down=(rStart<(rows-1))?rStart+1:rStart,left=cStart,right=(cStart<(cols-1))?cStart+1:cStart;
        int direction =0;//initially mai clockwise ke liye right move hii hotaaa hai
        // 0 means right move
        //1 means down move 
        // 2 means left move
        // 3 means up move
        ans.push_back({rStart,cStart});
        isvisited[rStart][cStart]=true;
        while(ans.size()<rows*cols)
        {
            // phle move mai right move kaaroo ie forward move
            if(direction ==0)
            {
                for(int i=left+1;i<=right;i++)
                {
                    if(!isvisited[top][i])
                    {
                        ans.push_back({top,i});
                        isvisited[top][i]=true;
                    }
                }
            }
            
            // aab neeche move kaaro ie downward move
        else if( direction == 1 ){
            
            for( int i = top+1 ; i <= down ; ++i ){
                
                if( !isvisited[i][right] ){
                    
                    ans.push_back({ i , right }) ;
                    
                    isvisited[i][right] = true ;
                }
            }
            //  aab boundry set kaaro upaar or left ke liye ek step upaar jao or ek step left ki taraf jaoo
           if( top > 0 ){
            	top -= 1 ;
            }
            if( left > 0 ){
            	left -= 1 ;
            }
        }
        
        // aab left move kaaro ie backward move
        
        else if( direction == 2 ){
            
            for( int i = right-1 ; i >= left ; --i ){
                
                if( !isvisited[down][i] ){
                    
                    ans.push_back({ down , i }) ;
                    
                    isvisited[down][i] = true ;
                }
            }
            // aab boundry set kaaro right ke liye ek step right jao 
            if( right < (cols-1)){
            	right += 1 ;
            }
        }
        
        // upaar jaooo ie upward move
        
        else if( direction == 3 ){
            
            for( int i = down-1 ; i >= top ; --i ){
                
                if( !isvisited[i][left] ){
                    
                    ans.push_back({ i, left }) ;
                    
                    isvisited[i][left] = true ;
                }
            }
            //// aab boundry set kaaro down ke liye ek step neeche jao 
            if( down < (rows-1)){
            	down += 1;
            }
        }
        
        
        direction =  (direction+1)%4 ;
       
    } 
    
    return ans ;
    
}
};
