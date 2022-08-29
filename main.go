package main

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func computeArea(ax1 int, ay1 int, ax2 int, ay2 int, bx1 int, by1 int, bx2 int, by2 int) int {
	area1 := (ax2 - ax1) * (ay2 - ay1)
	area2 := (bx2 - bx1) * (by2 - by1)
	cx1 := Max(ax1, bx1)
	cx2 := Min(ax2, bx2)
	cy1 := Max(ay1, by1)
	cy2 := Min(ay2, by2)
	width := cx2 - cx1
	height := cy2 - cy1
	area3 := Max(width, 0) * Max(height, 0)
	return area1 + area2 - area3
}
