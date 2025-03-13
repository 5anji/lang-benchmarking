package main

import "container/list"

func bfs(graph map[int][]int, start int) {
    visited := make(map[int]bool)
    queue := list.New()
    queue.PushBack(start)
    visited[start] = true

    for queue.Len() > 0 {
        elem := queue.Remove(queue.Front()).(int)
        for _, neighbor := range graph[elem] {
            if !visited[neighbor] {
                visited[neighbor] = true
                queue.PushBack(neighbor)
            }
        }
    }
}

func buildGraph(edges [][2]int, nodes int) map[int][]int {
    graph := make(map[int][]int)
    for _, e := range edges {
        u, v := e[0], e[1]
        graph[u] = append(graph[u], v)
        graph[v] = append(graph[v], u)
    }
    return graph
}

func main() {
    graphs := [][][2]int{
        {{0,1}, {0,2}, {1,3}, {2,4}, {4,5}},                             // 5 edges
        {{0,1}, {0,2}, {1,3}, {2,4}, {4,5}, {1,2}, {3,5}},               // 7 edges
        {{0,1}, {0,2}, {1,3}, {2,4}, {4,5}, {1,2}, {3,5}, {3,4}, {0,5}}, // 9 edges
    }

    for _, edgeList := range graphs {
        graph := buildGraph(edgeList, 6)
        bfs(graph, 0)
    }
}
