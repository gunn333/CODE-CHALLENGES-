class Solution{
    static boolean match(String wild, String pattern)
    {
        int wildIndex = 0;
        int patternIndex = 0;
        int wildStar = -1;
        int patternStar = -1;

        while (patternIndex < pattern.length()) {
            if (wildIndex < wild.length() && (wild.charAt(wildIndex) == pattern.charAt(patternIndex) || wild.charAt(wildIndex) == '?')) {
                wildIndex++;
                patternIndex++;
            } else if (wildIndex < wild.length() && wild.charAt(wildIndex) == '*') {
                wildStar = wildIndex;
                patternStar = patternIndex;
                wildIndex++;
            } else if (wildStar != -1) {
                wildIndex = wildStar + 1;
                patternIndex = patternStar + 1;
                patternStar++;
            } else {
                return false;
            }
        }

        while (wildIndex < wild.length() && wild.charAt(wildIndex) == '*') {
            wildIndex++;
        }

        return wildIndex == wild.length();
    }
}
