# Python imports
import logging

# Project imports
from Cogs.CogEnums import SellbotCogType
from Cogs.SellbotCogTypes.ColdCaller import ColdCaller
from Cogs.SellbotCogTypes.Telemarketer import Telemarketer

def makeCog(cogType):
  """Create a Sellbot cog.
  :param cogType: The type of cog to make
  :type cogType: BossbotCogType, CashbotCogType, LawbotCogType, or SellbotCogType
  """
  # Create Sellbot cogs
  if isinstance(cogType, SellbotCogType):

    if cogType == SellbotCogType.COLD_CALLER:
      return ColdCaller()
    
    elif cogType == SellbotCogType.TELEMARKETER:
      return Telemarketer()
    
    else:
      logging.error(f'{cogType} is unsupported')
      return NotImplemented
  
  # Bossbot/Cashbot/Lawbot cogs are unsupported
  else:
    logging.error(f'{cogType} is unsupported')
    return NotImplemented

