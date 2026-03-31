class Solution {
    public boolean isPalindrome(String s) {
       boolean isPal = true;
       String input = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();

       int low = 0;
       int high = input.length() - 1;
      
       while(low < high) 
       {
          if(input.charAt(low)== input.charAt(high))
          {
            isPal = true;

          }
          else
          {
            isPal = false;
            break;
          }

          low++;
          high--;
       }

       return isPal;
    }
}
