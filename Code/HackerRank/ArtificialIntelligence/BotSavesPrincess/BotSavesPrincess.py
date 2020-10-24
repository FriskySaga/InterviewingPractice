"""HackerRank (Easy): Bot Saves Princess

Artificial Intelligence
"""

def displayPathtoPrincess(n, grid):
  print(n, grid)

if __name__ == "__main__":
  m = int(input())
  grid = [] 
  for i in range(0, m): 
      grid.append(input().strip())

  displayPathtoPrincess(m, grid)

