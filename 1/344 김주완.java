class Solution {
    public void reverseString(char[] s) {
        char tmp;
        int len = s.length;
        for (int i=0; i<len/2; i++) {
            tmp = s[i];
            s[i] = s[len - 1 - i];
            s[len - 1 - i] = tmp;
        }
    }
}
