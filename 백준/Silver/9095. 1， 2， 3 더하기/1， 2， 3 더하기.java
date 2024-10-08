import java.io.*;
public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < T; tc++) {
            int n = Integer.parseInt(br.readLine());
            int[] dp = new int[20];

            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;

            if(n > 3) for (int i = 4; i < n + 1; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            sb.append(dp[n]).append('\n');
        }
        System.out.println(sb);
    }
}