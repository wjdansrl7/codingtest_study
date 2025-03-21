import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        Arrays.sort(people);
        
        int j = 0;
        for(int i = people.length - 1; i >= j; i--) {
            if(people[i] + people[j] <= limit) {
                j++;
            }
            answer++;
        }
        return answer;
    }
}