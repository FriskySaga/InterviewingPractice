"""HackerRank (Easy): Find The Point

Mathematics
"""

#
# Complete the findPoint function below.
#
def findPoint(px:int, py:int, qx:int, qy:int) -> (int,int):
  """Find the point reflection.

  :param px: First point's x value
  :param py: First point's y value
  :param qx: Second point's x value
  :param qy: Second point's y value
  :return: (x,y) for point reflection of point p across point q

  A point reflection, or inversion, of point p across point q
  is a 180 degree rotation of point p around point q.

  Example: Suppose r is the point reflection of p across q.
        r
      q
    p

  In the figure, p:(0,0), q:(1,1), r:(2,2)
  """
  return 2*qx - px, 2*qy - py

if __name__ == '__main__':
  assert findPoint(0,0,1,1) == (2,2)
  assert findPoint(1,1,2,2) == (3,3)

