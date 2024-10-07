class Solution {
    public String removeConsecutiveCharacter(String S) {
        // Convert the input string to a character array
        char[] arr = S.toCharArray();
        
        // Initialize an empty string to build the result
        String str = "";
        
        // Add the first character to the result string
        if (S.length() > 0) {
            str = str + arr[0];
        }

        // Iterate through the string starting from the second character
        for (int i = 0; i < S.length() - 1; i++) {
            // Check if the current character is different from the next character
            if (S.charAt(i + 1) != S.charAt(i)) {
                // Add the next character to the result string if it's different
                str = str + S.charAt(i + 1);
            }
        }
        
        // Return the result string with consecutive characters removed
        return str;
    }
}
