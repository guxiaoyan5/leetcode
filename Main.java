import  java.lang.Math;

class Solution {
    public int solution(int A[], int B[], int N) {
        int[] C = new int[N];
        for (int i = 0; i < N; i++) {
            int x = Math.max(A[i], B[i]);
            if (x > 0 && x <= N) {
                C[x - 1] = x;
            }
        }
        for (int i = 0; i < N; i++) {
            if (C[i] != i + 1) {
                return i + 1;
            }
        }
        return N + 1;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] A = {1, 2, 4, 3};
        int[] B = {1, 3, 2, 3};
        System.out.println(solution.solution(A,B,4));
    }
}
