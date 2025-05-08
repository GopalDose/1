public class MatAdd {
    public List<List<Integer>> addE(List<List<Integer>> mat1, List<List<Integer>> mat2){
        Integer row = mat1.size();
        Integer col = mat1[0].size();
        List<List<Integer>> res = new List<List<Integer>>();
        
        for (Integer i = 0 ; i < row; i++){
            List<Integer> rows = new List<Integer>();
            for(Integer j = 0; j < col; j++){
                rows.add(mat1[i][j] + mat2[i][j]);
            }
            res.add(rows);
        }
        return res;
    }
    
    public static void main(){
        List<List<Integer>> matrixA = new List<List<Integer>>{
            new List<Integer>{1, 2, 3},
            new List<Integer>{4, 5, 6}
        };
            
        List<List<Integer>> MatrixB = new List<List<Integer>>{
            new List<Integer> {7, 8 ,9},
            new List<Integer>{1, 1, 1}
        };
        MatAdd n = new MatAdd();
        List<List<Integer>> result = n.addE(matrixA, matrixB);
        
         for (List<Integer> row : result) {
            System.debug(row);
        }
    }
}