import java.util.*;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        // List to hold grouped anagrams
        List<List<String>> anagramGroups = new ArrayList<>();
        
        // Array to track visited strings
        boolean[] visited = new boolean[strs.length];
        
        // Array to hold sorted strings
        String[] sortedStrs = new String[strs.length];
        
        // Sort each string and store its sorted version
        for (int i = 0; i < strs.length; i++) {
            sortedStrs[i] = sortString(strs[i]);
        }
        
        // Group anagrams based on their sorted strings
        for (int i = 0; i < sortedStrs.length; i++) {
            if (!visited[i]) {
                visited[i] = true; // Mark this string as visited
                List<String> group = new ArrayList<>();
                group.add(strs[i]); // Add the original string to the group
                
                // Check for other anagrams
                for (int j = i + 1; j < sortedStrs.length; j++) {
                    if (sortedStrs[i].equals(sortedStrs[j])) {
                        visited[j] = true; // Mark as visited
                        group.add(strs[j]); // Add the anagram to the group
                    }
                }
                
                // Add the group to the final list
                anagramGroups.add(group);
            }
        }
        
        return anagramGroups;
    }

    // Helper method to sort the characters of a string
    private String sortString(String str) {
        char[] chars = str.toCharArray();
        Arrays.sort(chars); // Sort characters
        return new String(chars); // Return the sorted string
    }
}
