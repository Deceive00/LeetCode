class Solution {
    public String shortestPalindrome(String s) {
        String reversed = new StringBuilder(s).reverse().toString();
        int n = s.length();
        
        for(int i = 0 ; i < n; i++ ){
            if(s.startsWith(reversed.substring(i))){
                return reversed.substring(0, i) + s;
            }
        }
        return reversed + s;
    }
}