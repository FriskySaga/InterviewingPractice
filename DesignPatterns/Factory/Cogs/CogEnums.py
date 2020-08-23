# Python imports
from enum import Enum

class CogType(Enum):
  BOSSBOT = 1
  CASHBOT = 2
  LAWBOT  = 3
  SELLBOT = 4

class SellbotCogType(Enum):
  COLD_CALLER      = 1
  TELEMARKETER     = 2
  NAME_DROPPER     = 3
  GLAD_HANDER      = 4
  MOVER_AND_SHAKER = 5
  TWO_FACE         = 6
  THE_MINGLER      = 7
  MR_HOLLYWOOD     = 8

