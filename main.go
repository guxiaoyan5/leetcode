package main

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

func copyRandomList(head *Node) *Node {
	temp:= head
	var m map[int]*Node
	for temp!=nil{
		m[temp.Val] = &Node{Val: temp.Val}
		temp = temp.Next
	}
	
}
