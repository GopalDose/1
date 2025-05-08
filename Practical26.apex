public class MatMult {

    // Method to multiply two matrices
    public static List<List<Integer>> multiply(List<List<Integer>> mat1, List<List<Integer>> mat2) {
        Integer rows1 = mat1.size();
        Integer cols1 = mat1[0].size();
        Integer rows2 = mat2.size();
        Integer cols2 = mat2[0].size();

        // Check if multiplication is possible
        if (cols1 != rows2) {
            System.debug('Matrix multiplication not possible: Columns of first matrix must equal rows of second matrix.');
            return new List<List<Integer>>();
        }

        // Initialize result matrix with zeros
        List<List<Integer>> result = new List<List<Integer>>();
        for (Integer i = 0; i < rows1; i++) {
            List<Integer> row = new List<Integer>();
            for (Integer j = 0; j < cols2; j++) {
                row.add(0);
            }
            result.add(row);
        }

        // Perform multiplication
        for (Integer i = 0; i < rows1; i++) {
            for (Integer j = 0; j < cols2; j++) {
                for (Integer k = 0; k < cols1; k++) {
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

        return result;
    }

    // Utility method to print a matrix
    public static void printMatrix(List<List<Integer>> matrix, String label) {
        System.debug(label);
        for (List<Integer> row : matrix) {
            System.debug(row);
        }
    }

    // Test method to demonstrate matrix multiplication
    public static void main() {
        List<List<Integer>> mat1 = new List<List<Integer>>{
            new List<Integer>{1, 2},
            new List<Integer>{3, 4}
        };

        List<List<Integer>> mat2 = new List<List<Integer>>{
            new List<Integer>{5, 6},
            new List<Integer>{7, 8}
        };

        List<List<Integer>> result = multiply(mat1, mat2);

        printMatrix(mat1, 'Matrix A:');
        printMatrix(mat2, 'Matrix B:');
        printMatrix(result, 'Matrix A * B:');
    }
}
