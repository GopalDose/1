public class ArraySum{
    public List<Integer> sumArr(List<Integer> arr1, List<Integer> arr2){
        Integer s = arr1.size();
        List<Integer> ans = new List<Integer>();
        for(Integer i = 0; i < s; i++){
            ans.add(arr1[i] + arr2[i]);
        }
        return ans;
    }
    
    public static void main(){
        List<Integer> a = new List<Integer>{1, 2, 3, 4};
        List<Integer> b = new List<Integer>{1, 2, 3, 4};
            
        ArraySum cl = new ArraySum();
        System.debug(cl.sumArr(a, b));
    }
}