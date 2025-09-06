package main

const INF = 1e9

func ShortestDistance(matrix [][]int) [][]int {
	n := len(matrix)

	// Convert -1 to INF for processing
	dist := make([][]int, n)
	for i := range n {
		dist[i] = make([]int, n)
		for j := range n {
			if matrix[i][j] == -1 && i != j {
				dist[i][j] = INF
			} else {
				dist[i][j] = matrix[i][j]
			}
		}
	}

	for k := range n {
		for i := range n {
			for j := range n {
				if dist[i][k] < INF && dist[k][j] < INF && dist[i][j] > dist[i][k]+dist[k][j] {
					dist[i][j] = dist[i][k] + dist[k][j]
				}
			}
		}
	}

	for i := range n {
		if dist[i][i] < 0 {
			return nil /* Negative cycle detected */
		}
	}

	// Convert INF back to -1
	for i := range n {
		for j := range n {
			if dist[i][j] == INF {
				dist[i][j] = -1
			}
		}
	}

	return dist
}

func main() {
	matrix := [][]int{
		{0, 3, -1, -1},
		{-1, 0, 1, 2},
		{-1, -1, 0, 4},
		{-1, -1, -1, 0},
	}

	shortest_dist := ShortestDistance(matrix)

	for _, row := range shortest_dist {
		for _, val := range row {
			if val == -1 {
				print("INF ")
			} else {
				print(val, " ")
			}
		}
		println()
	}
}
