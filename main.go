package main

func minDistance(word1 string, word2 string) int {
	n := len(word1)
	m := len(word2)
	if n*m == 0 {
		return n + m
	}
	dp := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]int, m)
		dp[i][0] = i
	}
	for i := 0; i < m+1; i++ {
		dp[0][i] = i
	}
	for i := 1; i < n+1; i++ {
		for j := 1; j < m+1; j++ {
			left := dp[i-1][j] + 1
			down := dp[i][j-1] + 1
			left_down := dp[i-1][j-1]
			if word2[j] != word1[i] {
				left_down += 1
			}
			dp[i][j] = Min(left, Min(down, left_down))
		}
	}
	return dp[n][m]
}
func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
