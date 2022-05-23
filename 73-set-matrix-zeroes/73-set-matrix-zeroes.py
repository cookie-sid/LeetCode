class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        n = len(matrix)
        m = len(matrix[0])
        hor = False 
        vert = False
        for x in range(n):
            if(matrix[x][0] == 0):
                vert = True
        
        for y in range(m):
            if(matrix[0][y] == 0):
                hor = True
                
        for x in range(1,n):
            for y in range(1,m):
                if(matrix[x][y] == 0):
                    matrix[x][0] = 0
                    matrix[0][y] = 0
        
        for x in range(1,n):
            if(matrix[x][0] == 0):
                for y in range(m):
                    matrix[x][y] = 0
                    
        for y in range(1,m):
            if(matrix[0][y] == 0):
                for x in range(n):
                    matrix[x][y] = 0
        
        if hor:
            for y in range(m):
                matrix[0][y] = 0
                
        if vert:
            for x in range(n):
                matrix[x][0] = 0
        